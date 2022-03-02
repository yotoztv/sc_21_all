#!bun/bash

service mysql start
mysql -e "CREATE DATABASE wordpress"
mysql -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -e "GRANT ALL ON *.* TO 'admin'@'localhost' IDENTIFIED BY 'admin' WITH GRANT OPTION;"
mysql -e "FLUSH PRIVILEGES"
