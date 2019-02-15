#!/bin/bash

##################### COLOR #############################

NC="\033[0m"
RED="\033[0;31m"
LRED="\033[1;31m"
LBLUE="\033[3;34m"
GREEN="\033[0;32m"
LGREEN="\033[0;32m"
ORANGE="\033[0;33m"
YELLOW="\033[1;33m"

########################################################

title() 
{
  termwidth="$(tput cols)"
  padding="$(printf '%0.1s' ={1..500})"
  printf $RED'%*.*s %s %*.*s\n' 0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"$NC
}

center() 
{
  termwidth="$(tput cols)"
  padding="$(printf '%0.1s' ={1..500})"
  printf $LBLUE'%*.*s %s %*.*s\n' 0 "$(((termwidth-2-${#1})/2))" "$padding" "$1" 0 "$(((termwidth-1-${#1})/2))" "$padding"$NC
}



clear
title "FAILS CHECKER"
echo -e $LBLUE"\nPress enter to continue...\n"
read
########### CHECK NORM ############
center "Norm test:"
norminette -R CheckForbiddenSourceHeader */*.c
echo -e $GREEN"\nTest completed!"$NC
########### CHECK PRINTF ############
center "Check printf press ENTER ..."
read
ret="$(cat */*.c 2>/dev/null | grep "printf" | wc -l | tr -d " ")"
if [ $ret -ne 0 ]
then
	echo -e $ORANGE"NUMBER OF PRINTF: $ret" $RED"FAILED ❌ "$NC
	cat */*.c | grep "printf"
else
	echo -e $GREEN"\n\n[OK] ✅  "$NC
fi
############ CHECK INCLUDE ###############
center "Check #INCLUDE press ENTER ..."
read
ret="$(cat */*.c 2>/dev/null | grep "stdio.h" | wc -l | tr -d " ")"
if [ $ret -ne 0 ]
then
	echo -e $ORANGE"stdio.h:"$RED" $ret" $RED"FAILED ❌ "$NC
	cat */*.c | grep "stdio.h"
else
	echo -e $GREEN"\nInvalid include: 0 [OK] ✅  "$NC
fi
########### A.OUT CHECKER ############
center "Check A.OUT press ENTER ..."
read
ret="$(ls -R 2>/dev/null | grep "a.out" | wc -l | tr -d " ")"
if [ $ret -ne 0 ]
then
	echo -e $ORANGE"NUMBER OF A.OUT:"$RED" $ret\n"$NC
	echo -e $ORANGE"Do you want delete it? y/n"$NC
	read answer
	if [ "$answer" = "y" ] || [ "$answer" = "Y" ]
	then
		rm */a.out
		echo -e $GREEN"all a.out has been delete."$NC
	fi
else
	echo -e $GREEN"\na.out: 0 [OK] ✅  "$NC
fi
############ CHECK INCLUDE ###############
center "Check MALLOC PROTECT press ENTER ..."
read
echo -e $NC
ret="$(cat */*.c 2>/dev/null | grep "malloc" | wc -l | tr -d " ")"
if [ $ret -ne 0 ]
then
	cat */*.c | grep "= malloc"
fi
center "END"
read
