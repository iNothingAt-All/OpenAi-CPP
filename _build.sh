#!/bin/bash

if [ ! -d "./bin" ]; 
    then mkdir ./bin
fi

g++ -I./include ./src/*.cpp -o ./bin/main -lcurl