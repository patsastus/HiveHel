FROM alpine:3.22

ARG WP_PORT

ARG INSTALL_REDIS=false

RUN apk add --no-cache\
    php83 \
    php83-fpm \
    php83-mysqli \
    php83-iconv \
    php83-mbstring \
    php83-openssl \
    php83-curl \
    php83-session \
    php83-ctype \
    php83-tokenizer \
    php83-dom \
    php83-xml \
    php83-simplexml \
    curl \
    mariadb-client

RUN echo "Building WordPress with INSTALL_REDIS=${INSTALL_REDIS}"

RUN if [ "${INSTALL_REDIS}" == "true" ]; then \
        apk add --no-cache php83-phar php83-pecl-redis; \
        curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar; \
        chmod +x wp-cli.phar; \
        mv wp-cli.phar /usr/local/bin/wp; \
    fi

RUN sed -i "s/listen = 127.0.0.1:9000/listen = ${WP_PORT}/g" /etc/php83/php-fpm.d/www.conf

RUN mkdir -p /var/www/wordpress && chown -R nobody:nobody /var/www/wordpress

COPY ./tools/setup.sh /tmp/setup.sh
RUN chmod +x /tmp/setup.sh
WORKDIR /var/www/wordpress

EXPOSE ${WP_PORT}

ENTRYPOINT ["sh", "/tmp/setup.sh"]
