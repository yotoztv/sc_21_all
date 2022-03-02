FROM alpine:3.12.3

RUN apk update && apk upgrade

RUN apk add --no-cache mysql mysql-client openrc

COPY start_script.sh /
RUN chmod -R 755 /start_script.sh
COPY my_db.sql /
RUN chmod -R 755 /my_db.sql
COPY my.cnf /etc/mysql

EXPOSE 3306

ENTRYPOINT sh start_script.sh