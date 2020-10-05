#!/bin/bash

# file project1.sh
# brief 1st script, to hopefully create a webpage filled with sys info
# author rory.beebout
# assignment Project - Scripting 1
# date 10/5/2020
# brief Writes Basic HTML for webpage, general format, constants,
# and "Here" script from linuxcommand.org "Writing Shell Scripts"

##### Constants

TITLE="System Information for $HOSTNAME"
RIGHT_NOW="$(date +"%x %r %Z")"
TIME_STAMP="Updated on $RIGHT_NOW by $USER"

##### Functions

# brief Return basic distribution info
get_linux_kernal_info()
{
  uname -a
}

# brief Return free command output in human readable format
get_physical_swap_memory()
{
  free -h
}

# brief Return disk space command output in human readable format
get_disk_space()
{
  df -h
}

# brief Return users who have active shell prompts(logged-in)
# and use groups command for each one to get user and groups they belong to
get_loggedin_users()
{
  #A very clever one-liner from Charles Duffy on stackoverflow at
  #stackoverflow.com/questions/11426529/reading-output-of-a-command-into-an-array-in-bash
  IFS=$'\n' read -r -d '' -a users_array < <( who | cut -d: -f1 && printf '\0')
  for i in "${users_array[@]}"
  do
    groups $i
  done
}

# brief Return primary IP addr
get_ip_address()
{
  hostname -I
}

# brief Return time since last system start
get_system_uptime()
{
  uptime
}

# brief List tons and tons of system specs
get_system_info()
{
  lshw -html
}

##### Main - Compiles all systems info into an html format
if [[ $EUID -ne 0 ]]; then
  echo "Must Run as Root" >&2
  exit 1
fi

cat <<- _EOF_
  <html>
  <head>
      <title>$TITLE</title>
  </head>

  <body>
      <h1>$TITLE</h1>
      <p>$TIME_STAMP</p>
      <h3>Basic Info</h3>
      <pre>$(get_linux_kernal_info)</pre>
      <h3>Free Memory</h3>
      <pre>$(get_physical_swap_memory)</pre>
      <h3>Disk Info</h3>
      <pre>$(get_disk_space)</pre>
      <h3>Shell Users</h3>
      <pre>$(get_loggedin_users)</pre>
      <h3>Network Info</h3>
      <pre>$(get_ip_address)</pre>
      <h3>System Uptime</h3>
     <pre> $(get_system_uptime)</pre>
      <h1>Lots of Info</h1>
     <pre>$(get_system_info)</pre>
  </body>
  </html>
_EOF_
