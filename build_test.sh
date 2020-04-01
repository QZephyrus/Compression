#!/bin/bash

g++ Compression.cpp test.cpp -I/usr/include/python2.7 -lpython2.7 -otest -lboost_date_time -Wall 