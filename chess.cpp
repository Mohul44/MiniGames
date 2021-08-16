#include <iostream>
#include <cstdlib>
#include<typeinfo>
using namespace std;
class Piece;
class Board;
#define N 8

class Spot{
    public:
    int x;
    int y;
    Piece * onSpotPiece;

    Spot(){
        x = -1;
        y = -1;
        onSpotPiece = NULL;
    }

    Spot(int a,int b, Piece * p)
    {
        x = a;
        y = b;
        onSpotPiece = p;
    }

};


int main(){  
   //testPiece();
 //  PlayGame();
    return 0;
}