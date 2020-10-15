#!/bin/bash

# file converter.sh
# brief Uses -options to convert file from upper to lower or vice versa 
# author rory.beebout
# assignment lab 6.2
# date 10/15/2020

usage()
{
  echo "$0 usage: [-f input filed] [-c U(upper) or L(lower)"
  exit 1
}

while getopts ":f:c:" options;
do
  case "${options}" in
    f)
      f=${OPTARG}
      if [[ -f "${f}" ]];then
        echo "${f} exists"
      else
       usage
      fi
      ;;
    c)
      c=${OPTARG}
      if [[ ${c} == "U" || ${c} == "L" ]]; then
        echo "${f} - ${c}"
      else
        usage
      fi
      ;;
    *)
      usage
      ;;
  esac
done

while read line
do
  if [ ${c} == "U" ]; then
    echo $line | tr [:lower:] [:upper:]
  else
    echo $line | tr [:upper:] [:lower:]
  fi
done < $f

exit 0
