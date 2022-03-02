kubectl delete svc grafana-service
kubectl delete deploy grafana-deployment
docker build -t my_grafana srcs/grafana
kubectl apply -f srcs/grafana/grafana.yaml