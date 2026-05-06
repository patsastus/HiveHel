composeFile := srcs/docker-compose.yml
bonusFile := srcs/docker-compose.bonus.yml
dataDir := /home/nraatika/data
secretDir := ./secrets
requiredFiles := ftp_user_pw.txt mariadb_root_pw.txt  mariadb_user_pw.txt  wp_bestuser_pass.txt  wp_user_pass.txt
s ?=

all: up

check_secrets:
	@echo "Checking for required secrets in $(secretDir)..."
	@for file in $(requiredFiles); do \
		if [ ! -s $(secretDir)/$$file ]; then \
		echo "Error: Missing secret file: $(secretDir)/$$file"; \
			echo "Please ensure all passwords exist in the secrets folder."; \
			exit 1; \
		fi; \
	done
	@echo "All secrets found. Proceeding..."
	@if [ ! -f srcs/.env ]; then \
	    echo "Warning: no .env file found in srcs/, using default values"; \
	fi;

up: check_secrets
	@mkdir -p $(dataDir)/mariadb $(dataDir)/wordpress
	docker compose -f $(composeFile) up -d --build

bonus: down
	docker compose -f $(composeFile) -f $(bonusFile) up -d --build

down:
	docker compose -f $(composeFile) -f $(bonusFile) down

status:
	docker compose -f $(composeFile) -f $(bonusFile) ps
	@echo ""

network:
	docker network ls
	@echo ""

volume:
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

.PHONY: all check_secrets up down status network volume logs fclean re
