// header.pp

// Guard to avoid double inclusions
#ifndef __HEADER_INCLUDED__
#define __HEADER_INCLUDED__

/*
    Invariants:
    f.a. i,j, 0 <= matrix[i][j] <= 2
    0 <= lastMove <= 6, except at the start lastMove = -1
    player = 0,1
    f.a. i, 0<= setSteine[i] <= 6

    Example:
    [0][0] [0][1] [0][2] [0][3] [0][4] [0][5] [0][6]
    [1][0]
    .
    [6][0] .      .      .       .     .      [6][6]
*/
struct spielfeld{
    int matrix [7][7];  //matrix [y][x] | y <- Zeile | x <- Spalte
    int lastMove;       // 
    int player;         //
    int setSteine [7];  //Speichert oberste Steinposition in jeder Spalte
};

/*  Preconditions: none 
    Postconditions: returns struct spielfeld sp as followed:
    sp.matrix is initialized all with 0
    sp.lastMove = -1
    sp.player is set to 0
    sp.setSteine is set to 6*/
spielfeld createSpielfeld();

// Prints spielefeld sp in console.
void printSpielfeld(spielfeld sp);

//Prints which players turn it is
void printPlayersTurn(int player);

/*  Preconditions: correct spielfeld sp
    Postconditions:
    return false: wenn kein Stein mehr reinpasst, nichts passiert
    return true:    
        Setzt Stein in Spalte "spalte"
        updated sp.lastMove
        wechselt sp.player*/
bool setStein(spielfeld *spP, int spalte);

/*  
    checks for winner 
*/
bool checkGewinner(spielfeld sp);

/*  Preconditions: correct spielfeld sp
    Postconditions:
    returns a number between 0 and 6
*/
int aiPlayer(spielfeld sp);

/* 
    Main routine of the game
*/
void gameRoutine(spielfeld *spP);

#endif  