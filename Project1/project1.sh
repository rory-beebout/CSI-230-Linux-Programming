#!/bin/bash

# file project1.sh
# brief 1st script, to hopefully create a webpage filled with sys info
# author rory.beebout
# assignment Project - Scripting 1
# date 10/5/2020
# brief Writes Basic HTML for webpage, from linuxcommand.org "Writing Shell Scripts"
##### Constants

TITLE="System Information for $HOSTNAME"
RIGHT_NOW="$(date +"%x %r %Z")"
TIME_STAMP="Updated on $RIGHT_NOW by $USER"

##### Functions

# brief Exits if the user running is not the root user.
check_root()
{
  if [[ $EUID -ne 0 ]]; then
    echo "Must Run as Root" >&2
    exit 1
  fi
}
get_linux_kernal_info()
{
  uname -a
}


get_physical_swap_memory()
{
  free -h
}


get_disk_space()
{
  df -h
}


get_loggedin_users()
{
  IFS=$'\n' read -r -d '' -a users_array < <( who | cut -d: -f1 && printf '\0')
  for i in "${users_array[@]}"
  do
    groups $i
  done
#  while IFS=: read -r user pass desc home shell; do
#    echo "$user is in '\n'"
#    "groups $user"
#  done < /etc/passwd
}


get_IP_address()
{
  hostname -I
}


get_system_uptime()
{
  uptime
}


get_system_info()
{
  lshw -html
}
##### Main - Compiles all systems info into an html format,
# will need to direct into a file eventually.

cat <<- _EOF_
  <html>
  <head>
      <title>$TITLE</title>
  </head>

  <body>
      <h1>$TITLE</h1>
      <p>$TIME_STAMP</p>
      $(check_root)
      $(get_system_uptime)
      $(get_IP_address)
      $(get_loggedin_users)
      $(get_disk_space)
      $(get_physical_swap_memory)
      $(get_linux_kernal_info)
      $(get_system_info)
  </body>
  </html>
_EOF_

