# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 17:12:35 by prodrigo          #+#    #+#              #
#    Updated: 2021/01/06 16:33:26 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM 	debian:buster

ENV 	AUTOINDEX on

RUN 	apt-get update && apt-get install -y \
		nginx \
		mariadb-server \
		php-fpm php-mysql php-mbstring \
		wget \
		&& rm -rf /var/lib/apt/lists/*
# Default page is located on /var/www/html
RUN		echo "daemon off;" >> /etc/nginx/nginx.conf && \
		rm var/www/html/index.nginx-debian.html
COPY	srcs/nginx/*.conf /tmp/

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
		tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
		mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin && \
		rm -rf phpMyAdmin-5.0.2-english.tar.gz
COPY	srcs/phpmyadmin/config.inc.php /var/www/html/phpmyadmin

RUN		wget https://wordpress.org/latest.tar.gz && \
		tar -xzvf latest.tar.gz && \
		mv wordpress /var/www/html/ && \
		rm -rf latest.tar.gz
COPY	srcs/wordpress/wp-config.php /var/www/html/wordpress

EXPOSE 	80 443

