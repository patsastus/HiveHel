composeFile := srcs/docker-compose.yml
dataDir := /home/nraatika/data

all: up

up:
	docker compose -f $(composeFile) up -d --build

down:
	docker compose -f $(composeFile) down -v

status:
	docker compose -f $(composeFile) ps
	@echo "---"
	docker network ls
	@echo "---"
	docker volume ls
	@echo "---"
	docker volume inspect mariadb_data
	@echo "---"
	docker volume inspect wordpress_data


logs:
	@services=$$(docker compose -f $(composeFile) config --services); \
		for svc in $$services; do \
			echo "===== Logs for: $$svc ====="; \
			docker compose -f $(composeFile) logs $$svc; \
			echo ""; \
		done

healthCheck:
	docker inspect --format='{{.State.Health.Status}}' mariadb

fclean: down
	-docker stop $$(docker ps -qa) 2>/dev/null || true
	-docker rm $$(docker ps -qa) 2>/dev/null || true
	-docker rmi -f $$(docker images -qa) 2>/dev/null || true
	-docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	-docker network rm $$(docker network ls -q) 2>/dev/null || true
	-docker system prune -a --volumes -f
	@sudo rm -rf $(dataDir)/wordpress/*
	@sudo rm -rf $(dataDir)/mariadb/*

re: fclean all

.PHONY: all up down status healthCheck fclean re
