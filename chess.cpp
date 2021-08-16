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

class Board{
    public:
    Spot * boxes[N][N];
    Board()
    {
        for(int i=0;i<8;i++){
            boxes[1][i] = new Spot(1,i,new Pawn(true));
            boxes[6][i] = new Spot(6,i,new Pawn(false));
        }

        boxes[0][0] = new Spot(0,1,new Rook(true));
        boxes[0][7] = new Spot(0,7,new Rook(true));
        boxes[0][1] = new Spot(0,2,new Knight(true));
        boxes[0][6] = new Spot(0,6,new Knight(true));
        boxes[0][2] = new Spot(0,3,new Bishop(true));
        boxes[0][5] = new Spot(0,5,new Bishop(true));

        boxes[0][3] = new Spot(0,3,new Queen(true));
        boxes[0][4] = new Spot(0,4,new King(true));

        boxes[7][0] = new Spot(7,1,new Rook(false));
        boxes[7][7] = new Spot(7,7,new Rook(false));
        boxes[7][1] = new Spot(7,2,new Knight(false));
        boxes[7][6] = new Spot(7,6,new Knight(false));
        boxes[7][2] = new Spot(7,3,new Bishop(false));
        boxes[7][5] = new Spot(7,5,new Bishop(false));

        boxes[7][4] = new Spot(7,4,new Queen(false));
        boxes[7][3] = new Spot(7,3,new King(false));

        for(int i=2;i<6;i++){
            for(int j=0;j<8;j++){
                boxes[i][j] = new Spot(i,j,NULL);
            }
        }
    }    

};

class Player{
    public:
    bool isWhite;
   Player(bool white){
        isWhite = white;
    }
};

void display(Board & brd){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(brd.boxes[i][j]->onSpotPiece!=NULL){
            cout<<typeid(*(brd.boxes[i][j]->onSpotPiece)).name();
            brd.boxes[i][j]->onSpotPiece->isWhite ? cout<<"P1"<<"     " : cout<<"P2"<<"     ";
            }
            else{
                cout<<"   .       ";
            }
        }
        cout<<endl;
    }
}
void testPiece(){
    Board b;
    King rk(true);
    Spot * start = new Spot(0,0,&rk);
    Spot * end = new Spot(1,1,NULL);
    cout<<rk.canMove(b,start,end)<<rk.isWhite<<rk.isAlive<<rk.isKing;
}

void PlayGame(){
    Board brd;
    int turn = 1;
    bool isWhiteTurn = true;
    while(true){

        // Get valid start box
        display(brd);
        cout<<"Player "<<turn<<" turn"<<endl;
        cout<<"Select starting box"<<endl;
        int a=-1,b=-1;
        Spot * start = NULL;
         while(start== NULL || start->onSpotPiece==NULL || start->onSpotPiece->isAlive==false || start->onSpotPiece->isWhite!=isWhiteTurn){
            cout<<"Please select a valid starting move!"<<endl;
            a = -1;
            b = -1;
            while(a<0 || b<0 || a>7 || b>7){
                cout<<"Select valid box"<<endl;
                cin>>a>>b;
            }
            start = brd.boxes[a][b];
        }

        // Get valid end vox
        a = -1;
        b = -1;
        Spot * end = NULL;
        while(end==NULL || (start->onSpotPiece->canMove(brd,start,end)==false)){
            a = -1;
            b = -1;
            end = NULL;
            while(a<0 || b<0 || a>7 || b>7){
            cout<<"Select valid ending box"<<endl;
            cin>>a>>b;
            }
            end = brd.boxes[a][b];
        }

        // Check if killed or if king killed

        Piece * killed = end->onSpotPiece;
        if(killed!=NULL){
            killed->isAlive = false;
            if(killed->isKing==true){
                cout<<"Player "<<turn<<" wins"<<endl<<endl;
                return;
            }
        }

        // Endbox is start Piece and start Piece is NULL
        end->onSpotPiece = start->onSpotPiece;
        start->onSpotPiece = NULL;   
        if(turn==1)turn = 2;
        else turn = 1;
        isWhiteTurn = !isWhiteTurn;
    }
    cout<<"Game Over"<<endl;
    return ;
}

int main(){  
   //testPiece();
   PlayGame();
    return 0;
}
