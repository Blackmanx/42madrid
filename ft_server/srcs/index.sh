#!/bin/bash
if [ "$AUTOINDEX" = "off" ] ;
then cp /tmp/off.conf /etc/nginx/sites-available/default ;
else cp /tmp/on.conf /etc/nginx/sites-available/default ; fi
if (( $(ps -ef | grep -v grep | grep nginx | wc -l) > 0 ))
then service nginx reload
fi
exit 0
