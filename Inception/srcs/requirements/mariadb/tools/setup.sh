#!/bin/sh

mariadb-install-db --user=mysql --datadir=/var/lib/mysql

dbPass=$(cat /run/secrets/mariadb_user_pw)
rootPass=$(cat /run/secrets/mariadb_root_pw)

cat << EOF > /tmp/init.sql
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};

CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${dbPass}';
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${dbPass}';

GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'localhost';

ALTER USER 'root'@'localhost' IDENTIFIED BY '${rootPass}';

DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';

FLUSH PRIVILEGES;
EOF

exec mariadbd --user=mysql --init-file=/tmp/init.sql
