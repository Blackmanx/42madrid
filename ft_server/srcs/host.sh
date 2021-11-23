#!/bin/bash

docker cp ft_server:/root/.local/share/mkcert/rootCA.pem /home/blackman/.local/share/mkcert

/home/blackman/mkcert/mkcert -install
