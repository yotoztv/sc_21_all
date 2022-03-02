kubectl delete svc influxdb-service
kubectl delete deploy influxdb-deployment
docker build -t my_influxdb srcs/influxdb/
kubectl apply -f srcs/influxdb/influxdb.yaml