#!/bin/bash

bash autoindex.sh
service php7.3-fpm start
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';"
