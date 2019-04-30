
#include <iostream>
#include <stdio.h>

struct spielfeld{
    int matrix [7][7];  //matrix [y][x] | x <- Zeile | y <- Spalte
    int lastMove;       // 
    int player;         //
    int setSteine [7];  //Speichert oberste Steinposition in jeder Spalte
};

// Kreiert das Spielfeld, initialisiert player und setSteine, lässt lastMove auf -1
spielfeld createSpielfeld(){
    spielfeld sp;
    for(int y = 0; y < 7;++y) {
        for(int x = 0; x < 7; ++x){
            sp.matrix [y][x] = 0;
        }
        sp.setSteine[y] = 6;
    }
    sp.player = 0;
    sp.lastMove = -1;
    return sp;
}

// Printed das Spielfeld
void printSpielfeld(spielfeld sp){
    std::cout << "\n";
    for(int y = 0; y < 7;++y) {
        for(int x = 0; x < 7; ++x){
            printf("%d", sp.matrix[y][x]);
        }
        std::cout << "\n";
    }
}

//Setzt Stein in Spalte "spalte", updated sp.lastMove, und wechselt sp.player
bool setStein(spielfeld *spP, int spalte){ 
    if((*spP).setSteine[spalte] == 0){
        return false;
    }
    else {
        (*spP).matrix[(*spP).setSteine[spalte]][spalte] = (*spP).player + 1;
        (*spP).player = ((*spP).player + 1)%2;
        (*spP).lastMove = spalte;
        return true;
    }
}

int main()
{
    spielfeld sp = createSpielfeld();
    printSpielfeld(sp);
    setStein(&sp, 1);
    printSpielfeld(sp);
}