# Compiler-Construction-Lab-Tasks

Task #03: Install flex and bison.


Instruction for flex & bison in Debian Linux (Ubuntu/Linux Mint)

PRE-REQUISITE

(A) Install flex from terminal: sudo apt-get install flex
(B) Install bison from terminal: sudo apt-get install bison
(C) If you dont have gcc installed, you can get it using sudo apt-get install gcc

+ +++++++++++++++++++++	+
+ PROCESSING	+
+ +++++++++++++++++++++ +

(1) Process the .lex file with flex
————————————-
flex filename.lex
>> lex.yy.c will be created

(2) Process .y file with bison
————————————-
bison -yd filename.y
>> Two files: y.tab.c and y.tab.h will be created

(3) Compile all files with gcc
————————————-
gcc -Wall y.tab.c y.tab.h -ly lex.yy.c -lfl -o myexecutable
>> myexecutable is your desired executable file, run in in the terminal using command: ./myexecutable


