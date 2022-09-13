
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int gsize2;
int S = 0;
int D = 0;
int available = 0;

#include "Header.hpp"
using namespace std;

void LimpiarPantalla(char fill = ' ') {
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void drawSquare(int a, int b) {
    int size, full;

    if (available == 0) {
        cout << "Medidas del cuadrado: ";
        cin >> a;
        cout << "¿Cuadrado relleno?: " << endl << "0)No  1)si" << endl;
        cin >> b;
        size = a;
        full = b;
        LimpiarPantalla();
    }

    Figure* vector1[50];
    vector1[available] = new Square(size, full, 1);
    vector1[available]->figureSetter(size, full);
    vector1[available]->draw(1);
    available++;
}

void drawTriangle(int a, int b) {
    int size, full;

    if (available == 0) {
        cout << "Medidas del triangulo: ";
        cin >> a;
        cout << "El triangulo con relleno: " << endl << "0)No  1)Si" << endl;
        cin >> b;
        size = a;
        full = b;
        LimpiarPantalla();
    }

    Figure* vector2[50];
    vector2[available] = new Triangle(size, full, 2);
    vector2[available]->figureSetter(size, full);
    vector2[available]->draw(2);
    available++;
}

void Rectangulo(int a, int b, int c) {
    int size, full, size2;

    if (available == 0) {
        cout << "Tamaño del primer rectangulo: ";
        cin >> a;
        cout << "Tamaño del segundo rectangulo: ";
        cin >> b;
        cout << "Relleno en el rectangulo: " << endl << "0)No  1)si" << endl;
        cin >> c;
        size = a;
        full = c;
        size2 = b;
        gsize2 = b;
        LimpiarPantalla();
    }

    Figure* vector3[50];
    vector3[available] = new Rec(size, full, size2, 3);
    vector3[available]->figureSetter(size, full);
    vector3[available]->draw(3);
    available++;
}

void menu() {
    int op, size, full, size2;

    cout << "Cual figura quieres ver?: " << endl << "-------------------------" << endl;
    cout << "1.- Cuadrado" << endl << "2.- Triangulo" << endl << "3.- Rectangulo" << endl;
    cin >> op;

    while (op < 1 || op>3) {
        cout << "Opcion no valida" << endl;
        cin >> op;
    }

    switch (op) {
    case 1: {
        while (1) {
            drawSquare(size, full);
            MoverFigura();
            LimpiarPantalla();
        }
    }break;

    case 2: {
        while (1) {
            drawTriangle(size, full);
            MoverFigura();
            LimpiarPantalla();
        }
    }break;

    case 3: {
        while (1) {
            Rectangulo(size, full, size2);
            MoverFigura();
            LimpiarPantalla();
        }
    }break;
    }
}

void MoverFigura() {
    char moveOption;
    cin >> moveOption;
    cout << endl;

    if (moveOption == 'A' || moveOption == 'a') {
        if (D != 0) {
            D--;
        }
    }

    if (moveOption == 'W' || moveOption == 'w') {
        if (S != 0) {
            S--;
        }
    }

    if (moveOption == 'S' || moveOption == 's') {
        S++;
    }

    if (moveOption == 'D' || moveOption == 'd') {
        D++;
    }
}


int main() {
    menu();
}