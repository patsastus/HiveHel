FROM alpine:3.22

RUN apk update && apk add --no-cache \
    nginx \
    openssl \
    gettext

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -noenc -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FI/ST=Uusimaa/L=Helsinki/O=Hive Helsinki/OU=Hive Helsinki/CN=nraatika.42.fr/UID=nraatika"

RUN mkdir -p /var/run/nginx

COPY ./conf/nginx.conf.template /etc/nginx/nginx.conf.template
COPY ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh

ENTRYPOINT ["sh", "/tmp/setup.sh"]
