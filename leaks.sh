#!/bin/bash

make
ARG=`ruby -e "puts (-50..0).to_a.shuffle.join(' ')"`; ./push_swap $ARG &
sleep 1
PID="$(ps | grep push_swap | head -n1 | awk '{print $1}')"
leaks $PID