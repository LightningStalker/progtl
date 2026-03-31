#!/bin/bash
# wa.sh - rinse away the sin of trailing whitespace <- Project Crew™ 2/23/2026
PROGNAME=$(basename ${0})
if test -n "${1}"
then
  if test -f "${1}"
  then
    echo ${PROGNAME}: Looking at file: ${1}
    NL=$(egrep -ch ' +$' ${1})
    echo ${PROGNAME}: Found ${NL} line\(s\) ending in whitespace.
    if test ${NL} -gt 0
    then
      echo ${PROGNAME}: Cleaning it up...
      sed -i -r 's/ +$//' ${1}
    else
      echo ${PROGNAME}: Nothing to do.
    fi
  else
    echo ${PROGNAME}: \'${1}\': File not found
  fi
else
  echo "${PROGNAME}: I can remove the trailing whitespace.  Name a file."
fi
