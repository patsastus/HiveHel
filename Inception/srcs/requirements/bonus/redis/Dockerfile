FROM alpine:3.22

RUN apk add --no-cache redis

ENTRYPOINT ["redis-server", "--protected-mode", "no", "--bind", "0.0.0.0"]
