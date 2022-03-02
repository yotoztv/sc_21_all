kubectl delete svc wp-service
kubectl delete deploy wp-deployment
docker build -t my_wordpress srcs/wp/
kubectl apply -f srcs/wp/wp.yaml