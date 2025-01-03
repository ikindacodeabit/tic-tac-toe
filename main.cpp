#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<int> possible_moves = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

bool game_over(char game[3][3]){
    if ((game[0][0] == game[0][1] && game[0][1] == game[0][2]) && (game[0][0] == 'O' || game[0][0] == 'X'))  return true;
    else if ((game[1][0] == game[1][1] && game[1][1] == game[1][2]) && (game[1][0] == 'O' || game[1][0] == 'X'))  return true;
    else if ((game[2][0] == game[2][1] && game[2][1] == game[2][2]) && (game[2][0] == 'O' || game[2][0] == 'X'))  return true;
    else if ((game[0][0] == game[1][0] && game[1][0] == game[2][0]) && (game[0][0] == 'O' || game[0][0] == 'X'))  return true;
    else if ((game[0][1] == game[1][1] && game[1][1] == game[2][1]) && (game[0][1] == 'O' || game[0][1] == 'X'))  return true;
    else if ((game[0][2] == game[1][2] && game[1][2] == game[2][2]) && (game[0][2] == 'O' || game[0][2] == 'X'))  return true;
    else if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) && (game[0][0] == 'O' || game[0][0] == 'X'))  return true;
    else if ((game[0][2] == game[1][1] && game[1][1] == game[2][0]) && (game[1][1] == 'O' || game[1][1] == 'X'))  return true;
    else  return false;
};

int main(){
    char p1, p2, player;
    int move = 1, inp, n;
    char table[3][3];
    cout<<"Enter whether player 1 will play O or X ?\n";
    cin>>p1;
    p1 = (char)toupper(p1);
    p2 = (p1 == 'O')?'X':'O';
    cout<<"Player 1 is : "<<p1<<"\n";
    cout<<"Player 2 is : "<<p2<<"\n";
    for(int i =0; i<3; i++)
        for(int j = 0; j<3; j++)
            table[i][j] = ' ';
    while(true)
    {
        cout<<"Possible moves are : ";
        for(int i = 0; i < possible_moves.size(); i++)
            cout<<possible_moves[i]<<" ";
        cout<<"\n";
        cout<<"Enter your move: ";
        cin>>inp;
        cout<<"\n";
        if(move%2 == 0)
            player = p2;
        else 
            player = p1;
        if(inp == 1)
            table[0][0] = player;
        else if (inp == 2)
            table[0][1] = player;
        else if (inp == 3)
            table[0][2] = player;
        else if (inp == 4)
            table[1][0] = player;
        else if (inp == 5)
            table[1][1] = player;
        else if (inp == 6)
            table[1][2] = player;
        else if (inp == 7)
            table[2][0] = player;
        else if (inp == 8)
            table[2][1] = player;
        else if (inp == 9)
            table[2][2] = player;
        cout<<"  "<<table[0][0]<<"  |  "<<table[0][1]<<"  |  "<<table[0][2]<<"  \n";
        cout<<"------------------\n";
        cout<<"  "<<table[1][0]<<"  |  "<<table[1][1]<<"  |  "<<table[1][2]<<"  \n";
        cout<<"------------------\n";
        cout<<"  "<<table[2][0]<<"  |  "<<table[2][1]<<"  |  "<<table[2][2]<<"  \n";
        n = possible_moves.size();
        auto it = find(possible_moves.begin(), possible_moves.end(), inp);
        possible_moves.erase(it);
        move++;
        if(game_over(table)||(possible_moves.size() == 0))    break;
    }
    if(player == p1 && game_over(table))
        cout<<"Player 1 ("<<p1<<") has won !";
    else if (game_over(table))
        cout<<"Player 2 ("<<p2<<") has won !";
    else
        cout<<"The game is a draw";
    return 0;
}
