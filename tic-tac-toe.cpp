#include<bits/stdc++.h>
using namespace std;

#define player1 1
#define player2 2
#define m 3
#define n 3
#define fr(i,n) for(int i=0;i<n;i++)

bool isWin(vector<vector<int>> & matrix){
    fr(i,m){
        if(matrix[i][0]!=0 && matrix[i][0] == matrix[i][1] && matrix[i][2] == matrix[i][1])return true;
    }
    fr(i,n){
        if(matrix[0][i]!=0 && matrix[0][i] == matrix[1][i] && matrix[2][i] == matrix[1][i])return true;
    }
    if(matrix[0][0]!=0 && matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])return true;
    if(matrix[0][2]!=0 && matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])return true;
    return false;
}

bool isFull(vector<vector<int>> matrix){
    for(auto x : matrix){
        for(auto y : x){
            if(y==0)return false;
        }
    }
    return true;
}

void display(vector<vector<int>> & matrix){
    for(auto x : matrix){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void playGame(vector<vector<int>> & matrix, int turn){
    
    while(isWin(matrix)==false && isFull(matrix)==false){
        display(matrix);
        cout<<"player "<<turn<<" turns"<<endl;
        int x = 0;
        int y = 0;
         cout<<"enter row between 0 -2"<<endl;
              cin>>x;
            cout<<"enter col between 0 -2"<<endl;
            cin>>y;
        while(x<0 || y<0 || x>=3 || y>=3 || matrix[x][y]!=0){
            cout<<"Wrong input enter again check if matrix is not filled"<<endl;
            cout<<"player"<<"  "<<turn<<"enter again"<<endl;
            cout<<"enter row between 0 -2"<<endl;
              cin>>x;
            cout<<"enter col between 0 -2"<<endl;
            cin>>y;
        }
        cout<<"here"<<endl;
        matrix[x][y] = turn;
        if(isWin(matrix)){
            cout<<endl<<endl;
         if(turn==1)cout<<"player 1 wins";
         else cout<<"player 2 wins";
         return ; 
        }
        if(turn==1)turn=2;
        else if(turn==2)turn = 1;
    }
    
}