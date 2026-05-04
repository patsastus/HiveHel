#!/bin/sh

openssl req -x509 -noenc -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FI/ST=Uusimaa/L=Helsinki/O=Hive Helsinki/OU=Hive Helsinki/CN=${WP_URL}/UID=nraatika"

envsubst '${NGINX_PORT} ${WP_URL} ${WP_PORT}' < /etc/nginx/nginx.conf.template > /etc/nginx/nginx.conf

if [ -f /etc/nginx/templates/adminer.conf.template ]; then
    echo "Adminer template found. Generating bonus config..."
    mkdir -p /etc/nginx/http.d/bonus
    envsubst '${ADMINER_PORT}' < /etc/nginx/templates/adminer.conf.template > /etc/nginx/http.d/bonus/adminer.conf
fi

if [ -f /etc/nginx/templates/static_site.conf.template ]; then
    echo "Static site template found. Generating bonus config..."
    mkdir -p /etc/nginx/http.d/bonus
    envsubst '${STATIC_PORT}' < /etc/nginx/templates/static_site.conf.template > /etc/nginx/http.d/bonus/static_site.conf
fi

if [ -f /etc/nginx/templates/monitor.conf.template ]; then
    echo "Monitor template found. Generating bonus config..."
    mkdir -p /etc/nginx/http.d/bonus
    envsubst '${MONITOR_PORT}' < /etc/nginx/templates/monitor.conf.template > /etc/nginx/http.d/bonus/monitor.conf
fi

exec nginx -g "daemon off;"
