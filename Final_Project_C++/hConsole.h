#pragma once
#include<windows.h>
#include<conio.h>
#include<stdio.h>

extern HANDLE hConsole;

enum ColorConsole {
    Blue = 3,
    Green = 2,
    Red = 4,
    White = 7
};

inline void SetBlue() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Blue);
}
inline void SetRed() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Red); 
}
inline void SetGreen() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Green); 
}
inline void SetWhite() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, White);
}