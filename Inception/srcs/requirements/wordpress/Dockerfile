FROM alpine:3.22

RUN apk update && apk add --no-cache\
    php83 \
    php83-fpm \
    php83-mysqli \
    php83-iconv \
    php83-mbstring \
    curl;

RUN sed -i "s/listen = 127.0.0.1:9000/listen = ${WP_PORT}/g" /etc/php83/php-fpm.d/www.conf

RUN mkdir -p /var/www/wordpress && chown -R nobody:nobody /var/www/wordpress

COPY ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh
WORKDIR /var/www/wordpress

EXPOSE ${WP_PORT}

ENTRYPOINT ["sh", "/tmp/setup.sh"]
