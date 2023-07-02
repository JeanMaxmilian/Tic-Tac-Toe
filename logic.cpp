#include <iostream>
#include <cstdio>
#include "logic.h"

using namespace std;

string board[9]{" ", " ", " ", " ", " ", " ", " ", " ", " "};
string player1{},player2{},champion{};
int player{1};
int position{0};

namespace LGC{

    void introduction()
    {
        cout<<"Press [Enter] to begin: ";
        getchar(); //haults the screen  
        cout<<"\n";

        cout<<"\n";
        cout<<"***********\n";
        cout<<"Tic-Tac-Toe\n";
        cout<<"***********\n";

        cout<<"Enter player-1's name :";
        cin>>player1;
        cout<<endl;

        cout<<"Enter player-2's name :";
        cin>>player2;
        cout<<endl;

        cout<<"Player 1) X\n";
        cout<<"Player 2) O\n";

        cout<<"The 3x3 grid is shown below:\n\n";

        cout << "     |     |      \n";
        cout << "  1  |  2  |  3   \n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  4  |  5  |  6   \n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  7  |  8  |  9   \n";
        cout << "     |     |      \n\n";

    }

    bool isWinner()
    {

        bool winner = false;
        string symbol{};
        //for checking rows

        for(int i{};i<9;i+=3){
        
            if((board[i] == board[i+1]) && (board[i+1] == board[i+2]) && board[i] != " ")
            {
               winner = true;
               symbol = board[i];
            }         
        }

        //for checking columns

        for(int i{};i<3;i++){
        
            if((board[i] == board[i+3]) && (board[i+3] == board[i+6]) && board[i] != " ")
            {
               winner = true;
               symbol = board[i];
            }         
        }

        //for checking diagonal

        if((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " ")
        {
            winner = true;
            symbol = board[0];
        }       

        else if((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " ")
        {
            winner = true;
            symbol = board[2];
        }         
        

        if(winner){
            if(symbol == "x"){
                champion = player1;
            }
            else{
                champion = player2;
            }
        }


        return winner;
    }

    bool filled_up()
    {
        bool filled = true;
        
        for(int i = 0; i<9; i++)
        {
            if(board[i]==" ")
            {
                filled = false;
            }
        }
        
        return filled;
    }

    void draw()
    {
        cout<<  "     |     |      \n";
        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
        cout << "_____|_____|_____ \n";
        cout << "     |     |      \n";
        cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
        cout << "_____|_____|_____ \n";
        cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
        cout << "     |     |      \n";
        cout << "\n";

    }

    void set_position()
    {
        cout<<"Player "<<player<<"'s turn (Enter: 1-9) :";   //1-9 (Enter: (1-9))
        while(!(cin>>position))
        {
            cout<<"Please enter a valid number between (1-9)"<<endl;
            cin.clear();  //flushing the buffer
            cin.ignore();  
        }
        cout<<endl;
        
        while (board[position -1] != " "){
            cout<<"Oops, invalid position or that position is already filled\nTry again\n";
            cout << "Player " << player << "'s Turn (Enter 1-9) :";
            cin>>position;
            cout<<"\n";
        }

    }

    void update_board()
    {
    
        if (player % 2 == 1){
            board[position - 1] = "X";  
        }
        else
        {
            board[position - 1] = "O";
        }
    }

    void change_player() {
        if (player == 1){
            player++;
        }
        else{
            player--;
        }
    }

    void take_turn()
    {
        while(!isWinner() && !filled_up())  
        {
            //invoking the functions
            set_position();
            update_board();
            change_player();
            draw();
        }
    }

    

    void end_game()
    {
        if(isWinner())
        {   

            cout<<champion<<" is the winner!"<<endl;
            
        }
        
        else if(filled_up())
        {
            cout<<"There is a tie!"<<endl;
        }
    }


}