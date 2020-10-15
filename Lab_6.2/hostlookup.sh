#!/bin/bash

# file hostlookup.sh
# brief Script to take hosts file and look them up
# author rory.beebout
# assignment Lab 6.2
# date 10/15/2020

while [ "$1" != "" ];
do
  case "$1" in
    *)
      f=$1
      if [[ -f "${f}" ]];then
        while IFS="" read -r h || [ -n "$h" ]
        do
          out=$(host -W1 -t A $h)
          if [ $? -eq 0 ];then
            ip=$(echo $out | cut -d " " -f 4)
            echo ${h},$ip
          else
            echo "${h},not found"
          fi
        done < $f
      else
        echo "${f} does not exist"
        exit 1
      fi
      ;;
  esac
  shift
done
