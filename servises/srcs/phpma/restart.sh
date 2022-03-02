kubectl delete svc phpmyadmin-service
kubectl delete deploy phpmyadmin-deployment
docker build -t my_phpmyadmin srcs/phpma
kubectl apply -f srcs/phpma/php.yaml