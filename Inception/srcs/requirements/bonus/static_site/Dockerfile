FROM alpine:3.22

ARG STATIC_PORT

RUN apk add --no-cache busybox-extras

COPY index.html /var/www/index.html

EXPOSE ${STATIC_PORT}

ENTRYPOINT ["sh", "-c", "httpd -f -p ${STATIC_PORT} -h /var/www"]
