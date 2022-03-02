kubectl delete svc ftps-service
kubectl delete deploy ftps-deployment
docker build -t my_ftps srcs/ftps/
kubectl apply -f srcs/ftps/ftps.yaml