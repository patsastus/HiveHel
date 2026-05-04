FROM alpine:3.22

ARG MONITOR_PORT

RUN apk add --no-cache python3 py3-flask py3-docker-py

COPY ./tools/app.py /app.py

EXPOSE ${MONITOR_PORT}

ENTRYPOINT ["sh", "-c", "python3 /app.py --port ${MONITOR_PORT}"]
