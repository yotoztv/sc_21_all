#!/bin/bash

title="dlucio aka Victor"
user="admin"
pswd="admin"
mail="dlucio@student.21-school.ru"
curl -d "weblog_title=$title&user_name=$user&admin_password=$pswd&admin_password2=$pswd&admin_email=$mail" -k https://localhost/wp-admin/install.php?step=2
