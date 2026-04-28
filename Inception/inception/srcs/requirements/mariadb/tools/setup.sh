#!/bin/sh

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Database not found, initializing..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

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

FLUSH PRIVILEGES;
EOF
    exec mariadbd --user=mysql --datadir=/var/lib/mysql --init-file=/tmp/init.sql
else
    echo "Database already exists, starting it up..."
    exec mariadbd --user=mysql --datadir=/var/lib/mysql
fi
