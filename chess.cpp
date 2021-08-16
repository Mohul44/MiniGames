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

class Piece{
    public:
    bool isWhite;
    bool isAlive;
    bool isKing;
    Piece()
    {
        isWhite = true;
        isAlive = true;
        isKing = false;
    }

    Piece(bool white)
    {
        isWhite = white;
        isAlive = true;
    }

     Piece(bool white, bool king)
    {
        isWhite = white;
        isAlive = true;
        isKing = king;
    }

    void getKilled(){
        isAlive = false;    
    }

    virtual bool canMove(Board & board, Spot * start, Spot * end) = 0;
};

class Knight: public Piece{
    public:
    Knight(bool white){
        isWhite = white;
     }
    bool canMove(Board & board, Spot * start, Spot * end){
        if(end->onSpotPiece!=NULL && start->onSpotPiece->isWhite==end->onSpotPiece->isWhite)return false;
        int diff_x = abs(start->x-end->x);
        int diff_y = abs(start->y-end->y);
        if(diff_x * diff_y==2){
            return true;
        }
        return false;
    }
};

class Bishop: public Piece{
    public:
    Bishop(bool white){
        isWhite = white;
     }
    bool canMove(Board & board, Spot * start, Spot * end){
         if(end->onSpotPiece!=NULL && start->onSpotPiece->isWhite==end->onSpotPiece->isWhite)return false;
        int diff_x = abs(start->x-end->x);
        int diff_y = abs(start->y-end->y);
        if(diff_x == diff_y){
            return true;
        }
        return false;
    }
};

class King: public Piece{
    public:
    King(bool white){
        isWhite = white;
        isKing = true;
     }
    bool canMove(Board & board, Spot * start, Spot * end){
         if(end->onSpotPiece!=NULL && start->onSpotPiece->isWhite==end->onSpotPiece->isWhite)return false;
        int diff_x = abs(start->x-end->x);
        int diff_y = abs(start->y-end->y);
        if(diff_x == diff_y && diff_x==1){
            return true;
        }
        return false;
    }
};

class Pawn: public Piece{
    public:
     Pawn(bool white){
        isWhite = white;
     }
       bool canMove(Board & board, Spot * start, Spot * end){
         if(end->onSpotPiece!=NULL && start->onSpotPiece->isWhite==end->onSpotPiece->isWhite)return false;
        int diff_x = abs(start->x-end->x);
        int diff_y = abs(start->y-end->y);
        if(diff_y==0 && diff_x==1){
            return true;
        }
        return false;
    }
};

class Rook: public Piece{
    public:
    Rook(bool white){
        isWhite = white;
     }
    bool canMove(Board & board, Spot * start, Spot * end){
         if(end->onSpotPiece!=NULL && start->onSpotPiece->isWhite==end->onSpotPiece->isWhite)return false;
        int diff_x = abs(start->x-end->x);
        int diff_y = abs(start->y-end->y);
        if((diff_x == 0 && diff_y>0) || (diff_y == 0 && diff_x>0)){
            return true;
        }
        return false;
    }
};


class Queen: public Piece{
    public:
    Queen(bool white){
        isWhite = white;
     }
      bool canMove(Board & board, Spot * start, Spot * end){
         if(end->onSpotPiece!=NULL && start->onSpotPiece->isWhite==end->onSpotPiece->isWhite)return false;
        int diff_x = abs(start->x-end->x);
        int diff_y = abs(start->y-end->y);
        if((diff_x == 0 && diff_y>0) || (diff_y == 0 && diff_x>0) || diff_x == diff_y){
            return true;
        }
        return false;
    }
};

int main(){  
   //testPiece();
 //  PlayGame();
    return 0;
}