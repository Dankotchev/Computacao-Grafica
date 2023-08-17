#!/bin/bash
g++ -Wall -Iinclude -g main.cpp include/*.cpp -o main.exe -lGL -lglfw && ./main.exe