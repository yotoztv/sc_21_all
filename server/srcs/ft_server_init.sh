#!/bin/bash

bash sql.sh
service php7.3-fpm start && service nginx start
bash wordpress.sh
bash
