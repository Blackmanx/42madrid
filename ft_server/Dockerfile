# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 17:12:35 by prodrigo          #+#    #+#              #
#    Updated: 2021/03/22 16:39:57 by prodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM 	debian:buster

ENV 	AUTOINDEX on

RUN 	apt-get update && apt-get install -y \
		wget \
		nginx \
		mariadb-server \
		php-fpm php-mysql php-mbstring php-xml \
		&& rm -rf /var/lib/apt/lists/*
# Web files are located in /var/www/html
RUN		rm var/www/html/index.nginx-debian.html
COPY	srcs/nginx/*.conf /tmp/

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz && \
		tar -xzvf phpMyAdmin-5.1.0-english.tar.gz && \
		mv phpMyAdmin-5.1.0-english/ /var/www/html/phpmyadmin && \
		rm -rf phpMyAdmin-5.1.0-english.tar.gz
COPY	srcs/phpmyadmin/config.inc.php /var/www/html/phpmyadmin

RUN		wget https://wordpress.org/latest.tar.gz && \
		tar -xzvf latest.tar.gz && \
		mv wordpress /var/www/html/ && \
		rm -rf latest.tar.gz
COPY	srcs/wordpress/wp-config.php /var/www/html/wordpress

RUN		mkdir ~/mkcert && cd ~/mkcert && \
		wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.3/mkcert-v1.4.3-linux-amd64 && \
		mv mkcert-v1.4.3-linux-amd64 mkcert && chmod +x mkcert && \
		./mkcert -install && ./mkcert localhost

RUN		chown -R www-data:www-data /var/www/html/*

COPY srcs/*.sh ./

EXPOSE 	80 443

CMD bash script.sh && tail -f /dev/null

