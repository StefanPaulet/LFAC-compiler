#!/bin/bash

flex compiler.l
mv lex.yy.c ./temps/scanner.c

bison --debug --verbose -d compiler.ypp -o compiler.cpp
mv compiler.cpp ./temps
mv compiler.hpp ./temps
mv compiler.output ./temps/parser_output

gcc -c ./temps/scanner.c -o ./temps/scanner.o
g++ -std=c++20 ./temps/scanner.o ./temps/compiler.cpp ./temps/main.cpp -o compiler