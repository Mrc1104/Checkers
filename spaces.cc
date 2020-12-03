/***
 * File: spaces.cc
 * Brief: implementation of spaces.h
 * 
 * Author: Ryan Conaway
 * Email: mc321015@ohio.edu
 * 
 * Last Modified: 11/24/2020 
 */

#include "spaces.h"



namespace main_savitch_14
{
//function definitions

//checks to see if square is empty
bool spaces::is_empty()const{
    return empty;
}

// checks to see if square is red
bool spaces::is_red()const{
    return red;
}
//checks to see if square is black
bool spaces::is_black()const{
    return black;
}

// checks to see if piece is white
bool spaces::is_piece_white()const{
    return piece_white;
}

//checks to see if piece is red
bool spaces::is_piece_red()const{
    return piece_red;
}
// checks to see if piece is a king
bool spaces::is_piece_king()const
{
    return piece_king;
}

// make a piece a king
void spaces::make_piece_king()
{
    piece_king = true;
}
// make square red
void spaces::make_red(){
    red = true;
    black = false;
}

// make swaure black
void spaces::make_black(){
    red = false;
    black = true;
}

// make square empty
void spaces::make_empty(){
    empty = true;
    piece_red = false;
    piece_red = false;
    piece_king = 0;
}

// make square not empty
void spaces::make_not_empty(){
    empty = false;
}

// make piece white
void spaces::make_piece_white(){
    piece_white = true;
    piece_red = false;
}

//make piece red
void spaces::make_piece_red(){
    piece_white = false;
    piece_red = true;
}



}