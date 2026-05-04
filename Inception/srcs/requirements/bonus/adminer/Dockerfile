FROM alpine:3.22

ARG ADMINER_PORT

RUN apk add --no-cache --no-cache \
    php83 \
    php83-fpm \
    php83-mysqli \
    php83-session \
    wget

RUN mkdir -p /var/www/adminer

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php -O /var/www/adminer/index.php

RUN sed -i "s/^listen = .*/listen = ${ADMINER_PORT}/g" /etc/php83/php-fpm.d/www.conf

WORKDIR /var/www/adminer

EXPOSE ${ADMINER_PORT}

ENTRYPOINT ["php-fpm83", "-F"]
