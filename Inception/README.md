*This project has been created as part of the 42 curriculum by nraatika.*

# Inception

## 1 Description
### 1.1 Summary
This project is about creating a network of Docker containers that work together via Docker Compose. My read is that it's an intro to creating a cloud-ready project: when you've containerized each element, they can be deployed to a remote server somewhere, and you don't need physical access to the hardware. We're working inside a virtual machine rather than a remote server, but the concept remains the same.

In the mandatory part of the project, we're building a simple web server split into three containers: 
 - a container running `nginx`, a reverse proxy that's accessible to the outside network, that talks to
 - a second container running `php-fpm` that serves a standard Wordpress blog, which in turn talks to 
 - a third container running `mariadb`, a MYSQL database server.

In the bonus part, we add a list of prescribed additional services to the mix, each in their own container: 
- `redis`, a database cache sitting between Wordpress and the database
- an `ftp` server, to facilitate uploading larger files to the website
- `adminer`, a visual interface for interacting with the database
- a simple `static` website

And finally, one additional service that we're free to choose. I chose to implement a small monitoring service dashboard as a Python Flask web server. It reports some stats on all of the Docker containers running on that host, by interfacing with the Docker API running on `/var/run/docker.sock`

### 1.2 Docker containers
Docker is the backbone of this project. It's a service that collects a number of useful Linux kernel functionalities to create what are essentially lightweight, isolated instances of Linux (**containers**) that are sandboxed from the "parent" Linux and each other. The main elements are various *namespace* isolations Docker does:
- **PID**: The main process of each container is PID 1 (in the container namespace), but something else entirely in the "parent" system.
- **Mount-point**: The container filesystem namespace has it's own root directory, `/`, but that can correspond to wherever we choose in the "parent" filesystem namespace, like `/home/nraatika/`. The container has dummy/virtual versions of a few hardware aspects that are "files" on Linux: `/dev/null`, `dev/random`,`/dev/tty`. To make data persist between container runs, you need Docker volumes or bind mounts.
- **Network (NET)**: the container namespace has it's own network stack, down to physical layer cards like `eth0`. Not connected to the global network namespace unless specified.
- **UNIX Timesharing System (UTS)**: isolates `hostname` and domain name: the container hinks it has a name that's different from the name the underlying OS has in the global namespace.
- **Inter-Process Communication (IPC)**: Processes running in the container can't access memory shared with anything outside the container. The only access a container has to outside processes is via the network.
- **User (USER)**: user and group IDs are container-specific; an `admin` in one container doesn't share rights with an `admin` in another one. Also means something running as `root` in a container doesn't have global `root` rights.

With these isolations, you can create these lightweight Linux instances that share the parent kernel, but can work independently and only have the minimal packages installed to perform the tasks they need to do. This means you can easily run multiple containers on normal hardware, where running full virtual machines for every service would be impossible. 

In practice, to make a Docker container, you create a *Dockerfile*, that first specifies what base image you're starting from (for this project I'm always starting from `alpine:3.22`, a lightweight Linux distribution; there are ready-made images for any number of services available on [Dockerhub](https://hub.docker.com/) if you don't want to or need to create your own from scratch). And then whatever commands you need to run to make your service function: installing packages from a package manager, compiling something, moving files from the parent filesystem into the container filesystem, and finally a command that runs as PID 1 in the created container.

### 1.3 Docker Compose
Containment is all fine and good, but we do want containers to be able to communicate with each other. That is where Docker Compose comes in: it handles setting up a number of Docker containers that can work together in predefined ways. You write down some specifications into a **YAML**-file (that stands for **Y**AML **A**in't **M**arkup **L**anguage) usually called `docker-compose.yml`, to specify which *services* to spin up (i.e. `mariadb`, `nginx` and `wordpress`), where the necessary files are located, whether one container depends on another, what networks and volumes your containers will be working with and what environment variables and secrets they require (more on all of these concepts below). You then call `docker compose -f docker-compose.yml up` to spin up all the containers at once (or in order, if there are certain dependencies specified).

### 1.4 Container dependencies
You can set up dependencies between containers in the docker-compose file:
- `depends_on: <necessary>` will cause Docker compose to order the creation of containers so `necessary` is created before the container with this specification
- `depends on: <necessary>: condition: service_healthy` will cause Docker compose to wait until the `necessary` container reports status `healthy`, before trying to start the container with this this specification. This requires that `necessary` defines a `health_check` function, but is very useful if one container requires that another service be up and running, not just that the other container exists. For this project, wordpress requires the database to be functional to work correctly, so `mariadb` has a `health_check`, and wordress will wait until it's ok before being started.

### 1.5 Secrets and environment variables
When you're setting up a Docker container (or multiple ones), you often want to pass in some variables that guide the installation of packages and setup of services. There are two main ways to do this: *environment variables* (typically specified by key=value pairs, or a full .env file containing a list of such) and *secrets*. 

**Environment variables** are relatively simple: you define them in the docker-compose file, and they're available as environment variables in whatever the container runs. They're also fully available to anyone with access to the Docker container (or anyone running `docker inspect <container_name>` on the host), and as such should only contain non-critical information: usernames, port numbers, hostnames etc. 

**Secrets** are things that you don't want to leak: passwords, API keys, and any other sensitive data. the docker-compse file needs to know where they exist on the host, but they're passed into the containers to a specific path in the containers filesystem that only exists in RAM (`/run/secrets/`). They're also not visible via `inspect`.

### 1.6 Networking
You can specify what networks each container has access to: I create one called `inception` shared by all containers, as that's required by the subjects. By default, Docker also has the `host`, `bridge` and `null` networks available. The `host` network is as it sounds: it's whatever access the host machine has. As to the `inception` network, it is only available to the Docker containers that are using it, unless we specify some `port: <internal>:<external>` to expose a certain port of the `inception` network to the outside. Different containers can communicate over a network they share using the container names as addresses: if the `wordpress` container wants to send a message to the `mariadb` container on port `3306`, it simply addresses `mariadb:3306` (so long as they both have `network: inception` specified in the docker-compose file, or any other shared network)

### 1.7 Persistent data storage
Most data in a container is ephemeral: it disappears once the container is spun down. If we want to have data that persists between reboots, we need some persisten storage. There are two ways to achieve this in Docker: *bind mounts* and *Docker volumes*

**Bind mounts** are simply points of the host filesystem mounted inside the container filesystem. It's a useful way to give access to a file to multiple containers: I use bind mounts in the bonus part to add separate routes to the `nginx` container: it looks in a certain folder for additional `.conf` files, if it sees them, it adds them to the available routes. And the docker compose file mounts those files from the host filesystem into the `nginx` one.
Example of a bind mount in a docker-compose: 
```
services:
  service_name:
    volumes: 
      - ./<host_path>:<container_path>
```

**Docker volumes**
Instead of simply naming a path on the host system, you can instead simply give the volume a name, and let Docker assign a place in it's internal filesystem for it. It has the advantage over a bind mount that the user is unlikely to accidentally mess with it, but at the same time, that means it's harder to make changes from ouside the container. Using volumes over bind mounts has the advantage that it puts it in Dockers reporting system, so you can get information on it by using `docker volumes ls`. You can still also bind the volume to a specific path on the host system by specifying a bind driver for the volume in the docker-compose file, giving you the best of both options. Example of a volume 
```
services:
  service_name:
    volumes: 
      - <volume_name>:<container_path>
...
volumes:
  volume_name:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: <host_path>
```
## 2 Instructions
The project was tested running on a virtual machine running Debian 13.4 installed via [Debian netinst](https://www.debian.org/CD/netinst/), and choosing only system utilities and ssh-server. 

### 2.1 Prerequisites
The following must be installed:
```
docker.io
docker-compose
```

### 2.2 Environment variables
The project requires some environment variables to be set to build, but there are default values for everything set in the docker-compose files. If one wants to adjust any variable, the easiest way would be to copy the following example `.env` file into the `srcs/` folder, and make any adjustments you want:
> ```
> MYSQL_DATABASE=wordpress_db
> MYSQL_USER=wp_user
> MYSQL_PORT=3306
> WP_ADMIN=bestuser
> WP_ADMIN_EMAIL="nraatika@student.hive.fi"
> WP_USER=wp_user
> WP_USER_EMAIL=wp_user@wishfulthinking.com
> WP_URL="nraatika.42.fr"
> WP_TITLE="Best ever blog"
> WP_DB_HOST=mariadb
> WP_PORT=9000
> NGINX_PORT=443
> REDIS_PORT=6379
> FTP_USER=ftpuser
> FTP_RANGE_START=21100
> FTP_RANGE_END=21110
> FTP_PATH=/var/www/wordpress/wp-content/uploads
> ADMINER_PORT=9000
> STATIC_PORT=3000
> MONITOR_PORT=5000
> ```

### 2.3 Secrets
In order for the project to run, passwords for the various users and services must be defined. You can run the following script to create the necessary files, with the default password `42`, and change the contents to whatever you please:
```
FILES=(ftp_user_pw.txt  mariadb_root_pw.txt  mariadb_user_pw.txt  wp_bestuser_pass.txt  wp_user_pass.txt)
mkdir -p ./secrets
for FILENAME in "${FILES[@]}"; do
  echo 42 > "./secrets/$FILENAME"
  chmod 600 "./secrets/$FILENAME"
done
```

### 2.4 Running Inception
Running inception is handled via the `make` command:
- `make` or `make up` will spin up the mandatory version of the project
- `make bonus` will spin up the bonus version of the project
- `make down` will take down all running containers
- `make status` will print the status of running containers
- `make network` will print status of the docker compose networks
- `make volume` will print information regarding existing Docker volumes
- `make logs` will print the logs of all services
- `make logs s=<service>` will open an updating view of the logs of the specified service, ctrl-c to escape
- `make fclean` will remove all containers, networks and volumes, **including clearing the bound data folders**, so this destroys data persistence.
- `make re` wipes everything and starts from scratch

## 3 Resources
### 3.1 References
- [Docker compose official documentation](https://docs.docker.com/compose/)
- [Offical Wordpress Docker image guide](https://hub.docker.com/hardened-images/catalog/dhi/wordpress/guides)

### 3.2 AI usage
I used AI in varied ways during this project, including:
- helping refine the project structure at the start
- troublsehooting and error message explanation
- as a learning tool to refine my understanding of concepts (*eg* what exactly does `depends_on:` in the docker-compose file do? )
- writing the scripts used to set up Wordpress
-
