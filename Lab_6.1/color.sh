#!/bin/bash

# file color.sh
# brief String checking with a case statement
# author rory.beebout
# assignment Lab 6.1
# date 10/12/2020

##### Constants
red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[0;35m'
default='\033[0m'

read -p "What is your favorite color (red, green, blue, yellow, or magenta)? " color
color=${color^^}

case "$color" in
  RED) selected_color=$red
      ;;
  GREEN) selected_color=$green
      ;;
  YELLOW) selected_color=$yellow
      ;;
  BLUE) selected_color=$blue
      ;;
  MAGENTA) selected_color=$magenta
      ;;
  ''|*) echo "Invalid Color, friend!"
      echo "Exiting..."
      exit 22;
      ;;
esac
echo -e "${selected_color}Your selected color is ${color}${default}"
