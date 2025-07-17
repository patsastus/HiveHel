#!/bin/bash
shopt -s expand_aliases
alias ccc='cc -Wall -Wextra -Werror'
ccc -g bonus.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c -o bns -D BUFFER_SIZE=42
ccc -g mandatory.c ../get_next_line.c ../get_next_line_utils.c -o mand -D BUFFER_SIZE=1         


