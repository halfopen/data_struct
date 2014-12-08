@g++ -Wall -o main main.cc nprimes.cc nprimes.h
@main 50000
@echo (Answer: 5133)
@del /F main.exe

@pause
