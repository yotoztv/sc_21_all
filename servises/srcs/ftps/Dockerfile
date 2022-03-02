FROM alpine:3.12.3

RUN apk update && apk upgrade

RUN apk add openssl vsftpd
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/ssl/certs/selfsigned_ssl.crt \
	-keyout /etc/ssl/private/selfsigned_ssl.key \
    -subj "/C=RU/ST=Moscow/L=Moscow/O=School21/CN=dlucio"

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
RUN chmod -R 777 /etc/vsftpd/vsftpd.conf

RUN mkdir -p /var/log/ftp
RUN touch /var/log/ftp/xferlog
EXPOSE 21 10090
RUN echo "root:0000" | chpasswd
ENTRYPOINT vsftpd /etc/vsftpd/vsftpd.conf