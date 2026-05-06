## Instructions
The project was tested running on a virtual machine running Debian 13.4 installed via [Debian netinst](https://www.debian.org/CD/netinst/), and choosing only system utilities and ssh-server. 

### Prerequisites
The following must be installed:
```
docker.io
docker-compose
```

### Environment variables
The project requires some environment variables to be set to build, but there are default values for everything set in the docker-compose files. If one wants to adjust any variable, the easiest way would be to copy the following example `.env` file into the `srcs/` folder, and make any adjustments you want:
```
MYSQL_USER=wp_user
MYSQL_DATABASE=wordpress_db
MYSQL_PORT=3306
WP_ADMIN=bestuser
WP_ADMIN_EMAIL="nraatika@student.hive.fi"
WP_USER=wp_user
WP_USER_EMAIL=wp_user@wishfulthinking.com
WP_URL="nraatika.42.fr"
WP_TITLE="Best ever blog"
WP_DB_HOST=mariadb
WP_PORT=9000
NGINX_PORT=443
REDIS_PORT=6379
FTP_USER=ftpuser
FTP_RANGE_START=21100
FTP_RANGE_END=21110
FTP_PATH=/var/www/wordpress/wp-content/uploads
ADMINER_PORT=9000
STATIC_PORT=3000
MONITOR_PORT=5000
```

### Secrets
In order for the project to run, passwords for the various users and services must be defined. You can run the following script to create the necessary files, with the default password `42`, and change the contents to whatever you please:
```
FILES=(ftp_user_pw.txt  mariadb_root_pw.txt  mariadb_user_pw.txt  wp_bestuser_pass.txt  wp_user_pass.txt)
mkdir -p ./secrets
for FILENAME in "${FILES[@]}"; do
  echo 42 > "./secrets/$FILENAME"
  chmod 600 "./secrets/$FILENAME"
done
```

### Running Inception
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

## Testing 
There are many ways to test that the services are running correctly, from a simple `make status` to see that everything claims to be up and running, to using the website and running `make logs` to see what went on in the background. 

To test a specific container, it can be good to open up a view of the logs with 
```
make logs s=<container_name>
``` 
in one terminal on the VM, and then interact with the website in a way that should activate the container. Most logs except `nginx` are quite sparse though, mostly containing some startup info, or any errors. Below are some example tests for each container.

### `nginx`
Access the website at the correct port (`-k` tells curl to ignore the self-signed certiicate warning, `-v` gives us the whole handshake sequence to see the certificate details):
```
curl -kv https://nraatika.42.fr:443
```

Accessing on the wrong port (should be quietly refused; `nginx` is not listening on that port):
```
curl -kv http://nraatika.42.fr:80
```

### `wordpress`
By default wordpress logs are quite silent, only showing errors. If the site works, it's silent after the setup entries. 

### `mariadb`
By default mariadb also doesn't log events, so you can't see things happening there. You can access the database directly from the VM terminal, by running
```
docker exec -it mariadb mariadb -u <username> -p
```
and log in as either `root` or whatever username is set in the .env for `$MYSQL_USER`, using the credentials set in the `secrets` folder. You then have full SQL access , here are some smaple commands:
```
SHOW DATABASES;
SELECT User, Host FROM mysql.user;
SHOW VARIABLES LIKE 'port';
```

### `redis`
`redis` logs are also quite empty when it's running , `Ready to accept connections tcp` is the sign that it's working correctly. To see the cache in action, you can instead use
```
docker exec -it redis redis-cli monitor
```
And then access the website, and you'll see redis doing a lot of work. You can also see it active in the admmin dashboard.

### `ftp`
The `ftp` server only has access to `/var/www/wordpress/wp-content/uploads` folder (or whatever is set in `.env` as `$FTP_PATH`), as a security measure; the ftp server exists to accept large file uploads, not for doing any editing of content. There's also password control.

A "realistic" test sequence:
- User uploads a file: `ftp -p nraatika.42.fr 21`
  - logs in with `ftpuser` and password set in the corresponding file
  - runs `put <image.jpg>` to upload an image
  - runs `quit` to exit
- Wordpress admin (`bestuser` by default) logs in to admin panel `https://nraatika.42.fr/wp-admin`
  - Posts -> Add post
  - add an image block, choose `insert from URL`
  - paste in `https://nraatika.42.fr/wp-content/uploads/image.jpg`
  - click `Publish` twice

A new post with the user-uploaded image now exists!

### `adminer`
- Browse to `https://nraatika.42.fr/adminer`
- set `mariadb` as the server, `$MYSQL_USER` as the user, and the corresponding password, and `wordpress_db`
- you now have a GUI to interact with the database, rather than the terminal based one from earlier

### `static_site`
- Browse to `https://nraatika.42.fr/static`

### `monitor`
- Browse to `https://nraatika.42.fr/monitor`
- you should see some usage stats on each running container
- you can run `docker exec -it mariadb mysql -u root -p -e "SELECT BENCHMARK(10000000, ENCODE('hello','goodbye'));"` in the VM terminal to see a temporary spike in `mariadb` usage, as an example. you will need the corresponding password for the `root` user of the db.
