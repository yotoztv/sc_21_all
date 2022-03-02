#Docker OS & update

FROM debian:buster
RUN apt-get update && apt-get upgrade -y

#Server installation

RUN apt-get install -y wget
RUN apt-get install -y vim
RUN apt-get install -y curl
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server
RUN apt-get install -y php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap

#Certificate

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/ft_serv.key -out /etc/ssl/certs/ft_serv.crt -subj "/C=RU/ST=Moscow/L=Moscow/O=21 School/OU=dlucio/CN=fts"

#Server setup $ config

WORKDIR /var/www
COPY srcs/ .
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz
RUN tar -xvzf phpMyAdmin-5.0.4-all-languages.tar.gz
RUN rm -rf phpMyAdmin-5.0.4-all-languages.tar.gz
RUN rm -rf latest.tar.gz
RUN mv phpMyAdmin-5.0.4-all-languages wordpress/phpMyAdmin
RUN chmod +x *.sh
RUN mv ft_serv.conf /etc/nginx/sites-available/default

#Init

EXPOSE 80 443
CMD ["bash", "ft_server_init.sh"]
