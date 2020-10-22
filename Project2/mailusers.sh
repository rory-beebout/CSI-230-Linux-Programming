#!/bin/bash

# file mailusers.sh
# brief Script to take list of emails, create users and passwords from them
#   and to distribute account info to appropriate emails
# author rory.beebout
# assignment Project - Scripting 2
# date 10/20/2020

#check if root
if [[ $EUID -ne 0 ]]; then
  echo "Must Run as Root" >&2
  exit 1
fi

#check if CSI230 is a group, or create
if [ $(getent group CSI230) ]; then
  echo "CSI230 exists..."
else
  echo "CSI230 does not exist... Creating it."
  groupadd CSI230
fi

#acquire email login for the future
echo "Sign in to Email to send from - Must be Gmail"
read -p 'Email Address: ' emailname
read -sp 'Password: ' emailpasswd
echo "\n"

while [ "$1" != "" ];
do
  f=$1
  if [[ -f "${f}" ]];then
    #Core Loop
    while IFS="" read -r h || [ -n "$h" ]
    do
      #get username
      user=$(echo "$h" | cut -d "@" -f 1)
      #create password
      pass=$(openssl rand -base64 32)
      #check if User exits/create user
      if id "${user}" &>/dev/null; then
        echo 'user found...Overwriting Password'
        echo "$user:$pass" | chpasswd
      else
        echo 'user not found...Creating'
        useradd -m ${user}
        echo "$user:$pass" | chpasswd
      fi
      #add user to group
      usermod -a -G CSI230 $user
      #require password change on login
      passwd --expire $user
      #email the lad
      curl --url 'smtp://smtp.gmail.com:587' --ssl \
      --mail-from $emailname \
      --mail-rcpt $h \
      --user "$emailname:$emailpasswd" \
      -T <(echo -e "From: $emailname\nTo: $h\nSubject: Project 2 Account Initialization\n\nHello\nYour account is made. \nUsername: ${user}\npassword: ${pass}")
    done < $f
  else
    echo "${f} does not exist"
    exit 1
  fi
  shift
done
