#!/bin/bash

if [ -z "$1" ]
then
  g++ -std=c++11 -g -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -O2 main.cpp -o main
else
  g++ -std=c++11 -g -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -O2 $1 -o main
fi
