#!/bin/bash
minikube start --vm-driver=virtualbox

eval $(minikube docker-env)
minikube addons enable metallb

kubectl apply -f srcs/metallb.yaml

docker build -t my_nginx srcs/nginx/
docker build -t my_sql srcs/mysql/
docker build -t my_phpmyadmin srcs/phpma/
docker build -t my_wordpress srcs/wp/
docker build -t my_ftps srcs/ftps/
docker build -t my_influxdb srcs/influx/
docker build -t my_grafana srcs/grafana

kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/phpma/php.yaml
kubectl apply -f srcs/wp/wp.yaml
kubectl apply -f srcs/ftps/ftps.yaml
kubectl apply -f srcs/influxdb/influxdb.yaml
kubectl apply -f srcs/grafana/grafana.yaml

minikube dashboard

sh srcs/influx/restart.sh