#include <random>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class ttt_game {
    public: 
        char pos[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        void show_game_state();
        void comp_move();
        bool is_game_over();
        char user, computer, winner = ' ';
        vector<int> possible_moves = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
        void show_possible_moves();
        void user_move(int move);
        int move_number = 0;
};

void ttt_game::show_game_state(){
    
        cout<<"  "<<pos[0]<<"  |  "<<pos[1]<<"  |  "<<pos[2]<<"  \n";
        cout<<"------------------\n";
        cout<<"  "<<pos[3]<<"  |  "<<pos[4]<<"  |  "<<pos[5]<<"  \n";
        cout<<"------------------\n";
        cout<<"  "<<pos[6]<<"  |  "<<pos[7]<<"  |  "<<pos[8]<<"  \n";
}

void ttt_game::user_move(int move){
    move_number++;
    pos[move-1] = user;
    auto it = find(possible_moves.begin(), possible_moves.end(), move);
    possible_moves.erase(it);
}

void ttt_game::comp_move(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, possible_moves.size());
    move_number++;
    int turn;
    int randomValue = distrib(gen);
    randomValue--;  
    turn = possible_moves[randomValue];
    pos[turn-1] = computer;
    auto it = find(possible_moves.begin(), possible_moves.end(), turn);
    possible_moves.erase(it);

}

bool ttt_game::is_game_over(){
    if(pos[0] == pos[1] && pos[1] == pos[2] && (pos[0] != ' '))
    {
        winner = pos[0];
        return true;
    }
    else if(pos[3] == pos[4] && pos[4] == pos[5] && (pos[3] != ' '))
    {
        winner = pos[3];
        return true;
    }
    else if(pos[6] == pos[7] && pos[7] == pos[8] && (pos[6] != ' '))
    {
        winner = pos[6];
        return true;
    }
    else if(pos[0] == pos[3] && pos[3] == pos[6] && (pos[0] != ' '))
    {
        winner = pos[0];
        return true;
    }
    else if(pos[1] == pos[4] && pos[4] == pos[7] && (pos[1] != ' '))
    {
        winner = pos[1];
        return true;
    }
    else if(pos[2] == pos[5] && pos[5] == pos[8] && (pos[2] != ' '))
    {
        winner = pos[2];
        return true;
    }
    else if(pos[0] == pos[4] && pos[4] == pos[8] && (pos[0] != ' '))
    {
        winner = pos[0];
        return true;
    }
    else if(pos[2] == pos[4] && pos[4] == pos[6] && (pos[2] != ' '))
    {
        winner = pos[2];
        return true;
    }
    else 
        return false;
}

void ttt_game::show_possible_moves(){
    for(int i = 0; i < possible_moves.size(); i++)
        cout<<possible_moves[i]<<" ";
    cout<<"\n";
}

int main()
{
    ttt_game game;
    int choice, move;
    char usr, comp;
    cout<<"Do you want to play first or second?\n";
    cin>>choice;
    cout<<"Do you want to play X or O ?\n";
    cin>>usr;
    comp = (usr == 'X') ? 'O' : 'X';
    game.user = usr;
    game.computer = comp;
    while (!(game.is_game_over()))
    { 
        if(choice == 1){
            cout<<"Possible moves are : ";
            game.show_possible_moves();
            cout<<"Enter your move\n";
            cin>>move;
            game.user_move(move);
            game.show_game_state();
            if(game.is_game_over() || game.move_number == 9)
                break;
            game.comp_move();
            game.show_game_state();
        }
        else
        {
            game.comp_move();
            game.show_game_state();
            if(game.is_game_over() || game.move_number == 9)
                break;
            if(game.is_game_over())
                break;
            cout<<"Possible moves are : ";
            game.show_possible_moves();
            cout<<"Enter your move\n";
            cin>>move;
            game.user_move(move);
            game.show_game_state();
        }
    }
    if(game.is_game_over()){
        if(game.winner == usr)
            cout<<"You have won !";
        else 
            cout<<"The computer has won !";
     }
    else 
        cout<<"It is a draw !";
    return 0;
}
