kubectl delete svc nginx-service
kubectl delete deploy nginx-deployment
docker build -t my_nginx srcs/nginx
kubectl apply -f srcs/nginx/nginx.yaml