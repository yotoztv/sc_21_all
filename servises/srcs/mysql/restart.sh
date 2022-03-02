kubectl delete svc mysql-service
kubectl delete deploy mysql-deployment
docker rmi -f my_sql
docker build -t my_sql srcs/mysql
kubectl apply -f srcs/mysql/mysql.yaml