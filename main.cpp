
#include <iostream>
#include <stdio.h>
#include "header.hpp"

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

// Prints spielfeld sp with one line extra above
void printSpielfeld(spielfeld sp){
    std::cout << "\n";
    for(int y = 0; y < 7;++y) {
        for(int x = 0; x < 7; ++x){
            printf("%d", sp.matrix[y][x]);
        }
        std::cout << "\n";
    }
}

//Prints which players turn it is
void printPlayersTurn(int player){
    printf("Next turn player %d\n", player);
}

/*Setzt Stein in Spalte "spalte", updated sp.lastMove, und wechselt sp.player
gibt false: wenn kein Stein mehr reinpasst
gibt true: wenn Stein erfolgreich gesetzt wurde*/
bool setStein(spielfeld *spP, int spalte){ 
    if((*spP).setSteine[spalte] == 0){
        return false;
    }
    else {
        (*spP).matrix[(*spP).setSteine[spalte]][spalte] = (*spP).player + 1;
        (*spP).player = ((*spP).player + 1)%2;
        (*spP).lastMove = spalte;
        //setSteine verringern
        return true;
    }
}

void gameRoutine(spielfeld *spP){
    do {
        // 1. Print Game field
        printSpielfeld(*spP);
        // 2. Print which players turn it is
        printPlayersTurn((*spP).player);
        // 3. Set new position
        setStein(spP, 0);
        // 4. Check for Winner
    } while(/*!checkGewinner(*spP)*/1);
}

int main()
{
    // Create spielfeld
    spielfeld sp = createSpielfeld();  
    // Start Game Routine
    gameRoutine(&sp);
}