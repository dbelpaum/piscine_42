#!/bin/sh
ifconfig -a | grep ether | awk '$1=$1' | cut -c 7-
