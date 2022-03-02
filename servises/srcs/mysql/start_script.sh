#!/bin/bash

rc default
/etc/init.d/mariadb setup
rc-service mariadb start
echo "CREATE DATABASE my_db" | mysql && \
echo "GRANT ALL PRIVILEGES ON my_db.* TO 'root'@'%' IDENTIFIED BY 'root' WITH GRANT OPTION" | mysql && \
echo "FLUSH PRIVILEGES;" | mysql
mysql -uroot my_db < my_db.sql
rc-service mariadb stop
exec mysqld_safe