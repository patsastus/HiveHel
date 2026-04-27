FROM alpine:3.22

RUN apk update && apk add mariadb mariadb-client

RUN sed -i 's/skip-networking/#skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

COPY tools/setup.sh /tmp/setup.sh

RUN chmod +x /tmp/setup.sh

EXPOSE ${MARIADB_PORT}

ENTRYPOINT ["sh", "/tmp/setup.sh"]
