/***
 * File: Checkers.h
 * Brief: child class of game.h, it stores the board
 * 
 * Author: Ryan Conaway
 * Email: mc321015@ohio.edu
 * 
 * Last Modified: 11/24/2020 
 */


#ifndef CHECKERS_H
#define CHECKERS_H

#include <string>
#include "game.h"
#include "spaces.h"


namespace main_savitch_14{

class Checkers : public game
{
    public:
    Checkers(); // defualt constructor

    // overridden functions
    void display_status()const; // displays the board
    bool is_legal(const std::string& move) const; // checks to see if move is legal
    void restart(); // restarts the board
    std::string get_user_move( ) const;

    //mutators
    void make_move(const std::string& move); // makes the move
    void make_single_move(const std::string& move); // helper function for make_move();
    bool single_move(const std::string& move, int call)const; // helper function for is_legal()
    bool multiple_moves(const std::string& move)const; // helper function for is_legal()
    bool white_move(int x1, int y1, int x2, int y2, int call)const; // helper function for is_legal()
    bool red_move(int x1, int y1, int x2, int y2, int call)const; // helper function for is_legal()
    bool is_white_jump_possible(int x1, int y1, int x2, int y2)const;
    bool is_red_jump_possible(int x1, int y1, int x2, int y2)const;






    //     // Return a pointer to a copy of myself: PHASE 3
    	game* clone( ) const;
    //     // Compute all the moves that the next player can make: PHASE 3
    	void compute_moves(std::queue<std::string>& moves) const {}
    // 	// Evaluate a board position: PHASE 3
	// // NOTE: positive values are good for the computer.
    	int evaluate( ) const;
    // 	// Return true if the current game is finished: PHASE 2
    bool is_game_over( ) const;
    who winning( ) const;





    private:
    spaces board[8][8]; // [rows][columns]
    char piece = '0'; // choice of piece
    char king = 'K'; // king choice



};
}



#endif