#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

/// Draws three boxes
void THREEBOXES() {
    system("cls");
    char BOX[4]={'o', '1', '2', '3'};
    cout << "\t  WHICH BOX HAS THE CANDY?\n" << endl;
    cout << "\t+-----+   +-----+   +-----+\n"<<
            "\t|     |   |     |   |     |\n"<<
            "\t|     |   |     |   |     |\n"<<
            "\t|     |   |     |   |     |\n"<<
            "\t+-----+   +-----+   +-----+\n"<<
    "\t   "<<BOX[1]<<"         "<<BOX[2]<<"         "<<BOX[3]<< endl;
}

/// Rand function
int MACHINE_DECIDE() {
    srand ( time(NULL) );
    int Num[3] = {1,2,3};
    for(int i=0;i<1;i++) {
        int RandIndex = rand() % 4;
        return Num[RandIndex];
    }
}

void WIN_LOSE(int user, int machine) {
    if(user == machine) {
        cout << "\t  YOU GOT THE RIGHT BOX!\n" << endl;
        cout << "\t\t  *****\n";
    }
    else cout << "\t  YOU GOT THE WRONG BOX!\n" << endl;
}

void CHECKUSER(int user, int machine) {
    if(user!=1 && user !=2 && user !=3) cout << "\t\tINVALID CHOICE!" << endl;
    else {
        WIN_LOSE(user, machine);
        cout << "\t   THE CANDY'S IN BOX-" << machine << endl;
    }
}

/// Function to move the cursor on console
void SetCursorPosition(int x, int y) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x,y};
    SetConsoleCursorPosition(output, pos);
}

void MOVECANDY() {
    for(int i=0; i<10; i++) {
        char candy='X';
        SetCursorPosition(11,4);
        cout << candy;
        Sleep(90);
        SetCursorPosition(21,4);
        cout << candy;
        Sleep(90);
        SetCursorPosition(31,4);
        cout << candy;
        Sleep(90);

        for(int a=0; a<1; a++) {
            char space=' ';
            SetCursorPosition(11,4);
            cout << space;
            Sleep(90);
            SetCursorPosition(21,4);
            cout << space;
            Sleep(90);
            SetCursorPosition(31,4);
            cout << space;
            Sleep(90);
        }
    }
    cout << endl << endl << endl << endl;
}

void PRINTCANDY(int machine) {
    if(machine==1) {
        SetCursorPosition(11,4);
        cout << "X";
    }
    else if(machine==2) {
        SetCursorPosition(21,4);
        cout << "X";
    }
    else if(machine==3) {
        SetCursorPosition(31,4);
        cout << "X";
    }
    SetCursorPosition(0,11);
}


int main() {
    int user, machine;

    THREEBOXES();
    MOVECANDY();
    machine = MACHINE_DECIDE();

    cout << endl << "\tCHOOSE A BOX (1. 2. 3.) : "; cin  >> user; cout << endl;

    PRINTCANDY(machine);
    CHECKUSER(user, machine);

    return 0;
}

