#!/bin/bash

# file push.sh
# brief used to push apache content to a rmeove server using rsync
# author rory.beebout
# Lab 9, Scheduled Tasks
# date 11/2/2020
# credits All except email written by Prof Paden, shown in lab video

#Constants
AWSHOST="ec2-54-209-232-64.compute-1.amazonaws.com"
AWSUSER="push-web"
LOCALDIR="web-content"

#Change to working directory
cd /root/cron-lab

# Rsync
rsync -e "ssh -i keys/push-web" -vraO --no-perms --delete --chmod=660 --chown=push-web:www-data "${LOCALDIR}/" "${AWSUSER}@${AWSHOST}":
# Write an entry to syslog
logger -t $0 "web content pushed to ${AWSHOST}"
