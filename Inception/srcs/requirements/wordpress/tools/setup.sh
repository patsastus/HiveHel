#!/bin/sh

dbPass=$(cat /run/secrets/mariadb_user_pw)
adminPass=$(cat /run/secrets/wp_admin_pw)
userPass=$(cat /run/secrets/wp_user_pw)

cd /var/www/wordpress

if [ ! -f latest.tar.gz ]; then
    echo "Downloading WordPress..."
    curl -L https://wordpress.org/latest.tar.gz | tar -xz -C /var/www/wordpress --strip-components=1
fi

if [ ! -f wp-config.php ]; then
    echo "Creating wp-config.php..."
    cat > /var/www/wordpress/wp-config.php <<EOL
<?php
define('DB_NAME', '${MYSQL_DATABASE}');
define('DB_USER', '${MYSQL_USER}');
define('DB_PASSWORD', '${dbPass}');
define('DB_HOST', '${WP_DB_HOST}:${MYSQL_PORT}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');
define('AUTH_KEY',         '$(head -c 64 /dev/urandom | base64)');
define('SECURE_AUTH_KEY',  '$(head -c 64 /dev/urandom | base64)');
define('LOGGED_IN_KEY',    '$(head -c 64 /dev/urandom | base64)');
define('NONCE_KEY',        '$(head -c 64 /dev/urandom | base64)');
define('AUTH_SALT',        '$(head -c 64 /dev/urandom | base64)');
define('SECURE_AUTH_SALT', '$(head -c 64 /dev/urandom | base64)');
define('LOGGED_IN_SALT',   '$(head -c 64 /dev/urandom | base64)');
define('NONCE_SALT',       '$(head -c 64 /dev/urandom | base64)');
\$table_prefix = 'wp_';
define('WP_DEBUG', ${WP_DEBUG});
if (!defined('ABSPATH')) define('ABSPATH', __DIR__ . '/');
require_once(ABSPATH . 'wp-settings.php');
EOL
fi

exec php-fpm83 -F
