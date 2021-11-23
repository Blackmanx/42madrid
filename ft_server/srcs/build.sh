#!/bin/bash

read -r -p "Do you need to build or clean? (B/C)" input

case $input in
[bB])
	read -r -p "Do you want autoindex? (Y/N)" yn
	case $yn in
        [Yy]* ) 	echo "Building" ;
	docker build -t ft_server .
	docker run -t -d --name ft_server -p 80:80 -p 443:443 ft_server
	docker exec -it ft_server bash;;
        [Nn]* ) docker build -t ft_server .
	docker run -t -d --env AUTOINDEX=off --name ft_server -p 80:80 -p 443:443 ft_server
	docker exec -it ft_server bash;;
        * ) echo "Please answer yes or no.";;
    esac
	;;
[cC])
	docker stop ft_server
	docker rm $(docker ps -qa)
	docker system prune -a --force
	;;
		*)
	echo "Invalid input"
	exit 1
	;;
esac
