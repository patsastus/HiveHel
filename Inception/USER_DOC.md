# Stack
## Mandatory
The mandatory parts of the project are defined in `srcs/docker-compose.yml`. There are 3 services running:
- `nginx` that runs the nginx reverse proxy, has a port open to the outside network, and routes traffic to the wordpress container as needed. It also has access to the `wordpress_data` volume, to serve certain non-dynamic files directly (like `.css` files).
- `wordpress` runs the `php-fpm` server, to serve dynamic PHP pages. It has access to the volume `wordpress_data` that contains the presistent files associated with the wordpress blog, and a network connection to `mariadb`.
- `mariadb` runs a mariadb MYSQL server, used to handle posts made on the blog. It has access to a volume named `mariadb_data`. It has a network connection to `wordpress`

## Bonus
For the bonus part, 5 additional services are added, each running in a container of the same name:
- `redis`, running `redis-server`, a database cache, is added to the mix, and registered with the `wordpress` container, so it functions as a proper cache.
- `ftp`, running a `vsftpd` server, to facilitate uploading large files to the `wordpress_data` volume.
- `adminer`, running `php-fpm`, serving a graphical user interface for interacting with the database in the `mariadb` container.
- `static_site`, a simple static html website served by the `busybox` server.
- `monitor`, a dynamic website providing a dashboard of all the containers running on the host. The server is Python Flask, with the data provided by the Docker API accessed via `/var/run/docker.sock`

# Running and testing the project
The project is designed to be interacted with via the `make` command. Ensure that you've followed the prerequisites of adding the necessary password files set out in `README.md`, and then run:
- `make` or `make up` to spin up the mandatory version of the project
- `make bonus` to spin up the bonus version of the project
- `make down` to take down all running containers
- `make status` to print the status of running containers
- `make logs` to print the logs of all services
- `make logs s=<service>` to open an updating view of the logs of the specified service, ctrl-c to escape
- `make fclean` to remove all containers, networks and volumes, **including clearing the bound data folders**, so this destroys data persistence.
- `make re` to wipe everything and start from scratch

## Accessing the website
By default, the site is located at `https://nraatika.42.fr`, while the admin panel is at `https://nraatika.42.fr/wp-admin`. Since I have a headless VM set up, you can't access it via a graphical browser inside the VM. But there are options:
- `ssh` into the VM, and use 
  - `curl -kv https://nraatika.42.fr:443` will show that *a* page is being served, and a TLS1.3 certificate is being used
  - `w3m https://nraatika.42.fr` w3m is a text-based browser, you can navigate with keys and follow a link with enter to check basic functionality of the site. `q` to exit.
- I've set up the VM with a local access network, so we can access it from any browser running on cluster machines with the correct IP, or with the hostname if using `chrome` started from the command line, where I've manually mapped the hostname to the IP.

## Credentials
Below is a table of the different users for services defined in the docker-compose and/or the .env file, and which file in the secrets folder provides the corresponding password
| **username** | `wp_user` | `bestuser` | `wp_user` | `root` | `ftpuser`|
| --- | --- | --- | --- | --- | --- 
| **service** | `wordpress` | `wordpress` | `mariadb` | `mariadb` | `ftp` |
| **password_file** |  `wp_user_pass.txt`   | `wp_bestuser_pass.txt`    |  `mariadb_user_pw.txt`   | `mariadb_root_pw.txt`    | `ftp_user_pw.txt` |

## Testing 
There are many ways to test that the services are running correctly, from a simple `make status` to see that everything claims to be up and running, to using the website and running `make logs` to see what went on in the background. 

To test a specific container, it can be good to open up a view of the logs with 
```
make logs s=<container_name>
``` 
in one terminal on the VM, and then interact with the website in a way that should activate the container. Most logs except `nginx` are quite sparse though, mostly containing some startup info, or any errors.
