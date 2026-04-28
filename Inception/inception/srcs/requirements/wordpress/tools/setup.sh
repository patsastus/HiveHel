#!/bin/sh

dbPass=$(cat /run/secrets/mariadb_user_pw)
adminPass=$(cat /run/secrets/wp_admin_pw)
userPass=$(cat /run/secrets/wp_user_pw)

cd /var/www/wordpress

if [ ! -f wp-config.php ]; then
    echo "Downloading WordPress..."
    curl -L https://wordpress.org/latest.tar.gz | tar -xz -C /var/www/wordpress --strip-components=1
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

    echo "Creating install script..."
    installScript="install.php"
    cat << EOF > $installScript
<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);
\$_SERVER['HTTP_HOST'] = getenv('WP_URL');
\$_SERVER['SERVER_NAME'] = getenv('WP_URL');
\$_SERVER['REQUEST_METHOD'] = 'GET';
function wp_mail() {
    return true;
}
define('WP_INSTALLING', true);
require_once('wp-load.php');
require_once('wp-admin/includes/upgrade.php');
require_once('wp-includes/user.php');

\$siteUrl = 'https://' . getenv('WP_URL');

wp_install(
    getenv('WP_TITLE'),
    getenv('WP_ADMIN'),
    getenv('WP_ADMIN_EMAIL'),
    1,
    '',
    '${adminPass}'
);

update_option('siteurl', \$siteUrl);
update_option('home', \$siteUrl);

\$userId = wp_create_user(
    getenv('WP_USER'),
    '${userPass}',
    getenv('WP_USER_EMAIL')
);
\$newUser = new WP_User(\$userId);
\$newUser->set_role('author');
?>
EOF
    echo "Running install script..."
    php83 $installScript
    rm $installScript
fi

chown -R nobody:nobody /var/www/wordpress

exec php-fpm83 -F
