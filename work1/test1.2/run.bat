@g++ -Wall -o main.exe main.cc llist.cc listset.cc
@type input.txt | main.exe
@del /F main.exe
@pause
