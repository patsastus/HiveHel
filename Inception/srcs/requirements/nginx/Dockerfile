FROM alpine:3.22

RUN apk add --no-cache nginx openssl gettext

RUN mkdir -p /etc/nginx/ssl
RUN mkdir -p /var/run/nginx

COPY ./conf/nginx.conf.template /etc/nginx/nginx.conf.template
COPY ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh

ENTRYPOINT ["sh", "/tmp/setup.sh"]
