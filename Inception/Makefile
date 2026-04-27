composeFile := srcs/docker-compose.yml

all: up

up:
	docker compose -f $(composeFile) up -d --build

down:
	docker compose -f $(composeFile) down

status:
	docker ps

healthCheck:
	docker inspect --format='{{.State.Health.Status}}' mariadb

fclean:
	-docker stop $$(docker ps -qa) 2>/dev/null || true
	-docker rm $$(docker ps -qa) 2>/dev/null || true
	-docker rmi -f $$(docker images -qa) 2>/dev/null || true
	-docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	-docker network rm $$(docker network ls -q) 2>/dev/null || true
	-docker system prune -a --volumes -f

re: fclean all

.PHONY: all up down status healthCheck fclean re
