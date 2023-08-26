g++ -c main.cpp -o main.o

g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

rm main.o
./main

rm main