FROM alpine:3.22

ARG REDIS_PORT

RUN apk add --no-cache redis

EXPOSE ${REDIS_PORT}

ENTRYPOINT ["sh", "-c", "redis-server --protected-mode no --bind 0.0.0.0 --port ${REDIS_PORT}"]
