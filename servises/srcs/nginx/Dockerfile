# OS
FROM alpine:3.7

#It's me!)
LABEL maintainer="dlucio <dlucio@gmail.com>"

# upgrade package and install necessary
RUN apk update && apk upgrade
RUN mkdir -p /run/openrc && touch /run/openrc/softlevel
RUN apk add bash nginx --no-cache openssl openssh sudo supervisor openrc
RUN mkdir -p /var/run/sshd

# copy files
RUN mkdir -p /run/nginx
COPY nginx.conf /etc/nginx/conf.d/default.conf
COPY index.html /var/www/site/
COPY supervisord.conf /etc/supervisord.conf

# make ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/ssl/certs/selfsigned_ssl.crt \
	-keyout /etc/ssl/private/selfsigned_ssl.key \
	-subj "/C=RU/ST=Moscow/L=Moscow/O=School21/CN=dlucio"

#make ssh
RUN adduser -D mwinter && echo "mwinter:0000" | chpasswd && ssh-keygen -A

# open ports
EXPOSE 80 443 22
CMD supervisord -c /etc/supervisord.conf