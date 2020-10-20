#!/bin/bash

# file mailusers.sh
# brief Script to take list of emails, create users and passwords from them
#   and to distribute account info to appropriate emails
# author rory.beebout
# assignment Project - Scripting 2
# date 10/20/2020

if [[ $EUID -ne 0 ]]; then
  echo "Must Run as Root" >&2
  exit 1
fi

#check if CSI230 is a group, or create
while [ "$1" != "" ];
do
  f=$1
  if [[ -f "${f}" ]];then
    #Core Loop
    while IFS="" read -r h || [ -n "$h" ]
    do
      user=$(echo "$h" | cut -d "@" -f 1)
    #create password
      pass=$(openssl rand -base64 32)
      echo ${pass}
    #check if User exits/create user and add to group

    #chage command for password reset

    #email the lad
      echo ${user}
    done < $f
  else
    echo "${f} does not exist"
    exit 1
  fi
  shift
done
