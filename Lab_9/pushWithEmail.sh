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

# Send Email
emailname="rory.beebout@mymail.champlain.edu"
emailpasswd="Ehh, this is a secret"
rcpt="rory.beebout@mymail.champlain.edu"

curl --url 'smtp://smtp.gmail.com:587' --ssl \
      --mail-from $emailname \
      --mail-rcpt $rcpt \
      --user "$emailname:$emailpasswd" \
      -T <(echo -e "From: $emailname\nTo: $h\nSubject: Pushweb Notification\n\nHelloo\nweb content pushed to ${AWSHOST}")
