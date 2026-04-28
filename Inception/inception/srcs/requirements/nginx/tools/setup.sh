#!/bin/sh

openssl req -x509 -noenc -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FI/ST=Uusimaa/L=Helsinki/O=Hive Helsinki/OU=Hive Helsinki/CN=${WP_URL}/UID=nraatika"

envsubst '${NGINX_PORT} ${WP_URL} ${WP_PORT}' < /etc/nginx/nginx.conf.template > /etc/nginx/nginx.conf

exec nginx -g "daemon off;"
