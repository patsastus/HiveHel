composeFile := srcs/docker-compose.yml
bonusFile := srcs/docker-compose.bonus.yml
dataDir := /home/nraatika/data
s ?=

all: up

up:
	@mkdir -p $(dataDir)/mariadb $(dataDir)/wordpress
	docker compose -f $(composeFile) up -d --build

bonus: down
	docker compose -f $(composeFile) -f $(bonusFile) up -d --build

down:
	docker compose -f $(composeFile) -f $(bonusFile) down

status:
	docker compose -f $(composeFile) -f $(bonusFile) ps
	@echo ""

status-network:
	docker network ls
	@echo ""

status-volumes:
	docker volume ls
	@echo "---"
	docker volume inspect mariadb_data
	@echo "---"
	docker volume inspect wordpress_data
	@echo ""

logs:
ifeq ($s,)
	@services=$$(docker compose -f $(composeFile) -f $(bonusFile) config --services); \
    for svc in $$services; do \
    	echo "===== Logs for: $$svc ====="; \
    	docker compose -f $(composeFile) -f $(bonusFile) logs $$svc; \
    	echo ""; \
    done
else
	@echo "===== Logs for: $s =====";
	docker compose -f $(composeFile) -f $(bonusFile) logs $s -f;
endif

tls-check:


fclean: down
	-docker stop $$(docker ps -qa) 2>/dev/null || true
	-docker rm $$(docker ps -qa) 2>/dev/null || true
	-docker rmi -f $$(docker images -qa) 2>/dev/null || true
	-docker volume rm $$(docker volume ls -q) 2>/dev/null || true
	-docker network rm $$(docker network ls -q) 2>/dev/null || true
	-docker system prune -a --volumes -f
	sudo rm -rf $(dataDir)/wordpress/*
	sudo rm -rf $(dataDir)/mariadb/*

re: fclean all

.PHONY: all up down status status-network status-volumes logs tls-check fclean re
