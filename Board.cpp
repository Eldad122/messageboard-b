#include "Board.hpp"
#include <iostream>
/*
    Board.cpp.
    Author: Eldad digdeker
*/
using namespace std;

namespace ariel {
 void Board::post(uint row, uint col, Direction direction, string message) 
 {
     bool check=true;// true is horizontal
        uint len=message.length();
        if(direction==Direction::Horizontal){ // update end rows and cols
            this->end_row = max(this->end_row, row);
            this->end_col = max(this->end_col, col+len);
        }
        else{
            check=false;
            this->end_row = max(this->end_row, row+len);
            this->end_col = max(this->end_col, col);
        }
        // update start rows and cols
        this->start_col = min(this->start_col, col);
        this->start_row = min(this->start_row, row);
        if(!check){
        for(ulong i=0 ;i<len;i++){
            this->board[row][col].c = message[i];
            row++;
        }
        }
        else
        {
            for(ulong i=0 ;i<len;i++){ // write the message
            this->board[row][col].c = message[i];
            col++;
        }
        }
    }

    string Board::read(uint row, uint col, Direction direction, uint length){
        string board;
        bool check=true;
        if(direction == Direction:: Vertical)
        {
            check=false;
        }
        // get the meassge according direction
        if(check)
        {
            for(uint i=0; i<length; i++){
            board += this->board[row][col].c;
            col++;
        }
        }
        else
        {
        for(uint i=0; i<length; i++){
        board += this->board[row][col].c;
        row++;
        }
        }
        return board;
    }
    
    void Board::show() {
        //draw the board
        for (uint i = this->start_row; i < this->end_row; i++) {
            for (uint j = this->start_col; j < this->end_col; j++) {
                cout << this->board[i][j].c;
            }
            cout << "\n";
        }
    }
}