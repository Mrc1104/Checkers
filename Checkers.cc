/***
 * File: Checkers.cc
 * Brief: implementation of checkers.h
 * 
 * Author: Ryan Conaway
 * Email: mc321015@ohio.edu
 * 
 * Last Modified: 11/24/2020 
 */
#include <iostream>
#include <vector>
#include "checkers.h"
#include "spaces.h"
#include "game.h"
#include "colors.h"
namespace main_savitch_14{


// constrctor
Checkers::Checkers()
{
    restart();
}

//displays the board
void Checkers::display_status()const
{
    for(int y = 0; y< 8; ++y){
        std::cout << B_BLUE << BOLD << y+1 << RESET;
        for(int x = 0 ; x <  8; ++x ){
            if(board[y][x].is_red()){
                std::cout << B_RED << "   " << RESET;
            }
            else{
                std::cout << B_BLACK;
                if(board[y][x].is_empty()){
                    std::cout << "   " << RESET;
                }
                else{
                    if(board[y][x].is_piece_red()){
                        if(board[y][x].is_piece_king()){
                            std::cout << " " << RED << king << " " << RESET;
                        }
                        else{
                            std::cout << " " << RED << piece << " " << RESET;
                        }
                    }
                    else{
                        if(board[y][x].is_piece_king()){
                            std::cout << " " << WHITE << king << " " << RESET;
                        }
                        else{
                            std::cout << " " << WHITE << piece << " " << RESET;
                        }
                    }
                }

            }
        } // x loop
        std::cout << std::endl;
    } // y loop
    std::cout << B_BLUE << "  A  B  C  D  E  F  G  H  " << RESET << std::endl;
    // std::cout << B_BLUE << "  0  1  2  3  4  5  6  7  " << RESET << std::endl;
    // std::cout << "Enter in the form A6B5 (A6 -> B5)" << std::endl;

}




// restarts the board
void Checkers::restart(){
    game::restart();
    for(int y = 0; y < 8; ++y){
        for(int x = 0 ; x < 8; ++x ){

            // make board colors

            if( (y % 2) == 0){
                if( (x % 2) == 0){
                    board[y][x].make_red();
                }
                else{
                    board[y][x].make_black();
                }
            }
            else{
                if( (x % 2) == 0){
                    board[y][x].make_black();
                }
                else{
                    board[y][x].make_red();
                }
            }

            
            
            // add pieces
            if( y <=2){
                if(board[y][x].is_black()){
                    board[y][x].make_not_empty();
                    board[y][x].make_piece_red();
                }
                else{
                    board[y][x].make_empty();
                }
            }
            else if( y > 4){
                if(board[y][x].is_black()){
                    board[y][x].make_not_empty();
                    board[y][x].make_piece_white();
                }
                else{
                    board[y][x].make_empty();
                }
            }
            else{
                board[y][x].make_empty();
            }

        } // x loop
    } // y loop

}



// updates the board to reflect the move
 void Checkers::make_move(const std::string& move){
    // cout << "MAKING MOVE!" << std::endl;
    // std::cout << move <<std::endl;
    
    if(move.size() == 4){
        make_single_move(move);
    }
    else{ // multiple moves
        for(int i = 0; i < move.size()-2; i+=2 ){ //move1, move2, move3,..., moveN have 2 parts, move1 -> move2, move2->move3,...,move(N-1)->moveN
             // std::cout << i << " " << move.at(i) << std::endl; 
            std::string moveN = move.substr(i,i+4); // std::cout << moveN << endl;
            make_single_move(moveN);
        }

    }
    // updates move counter
    game::make_move(move);
}


// makes an individual component of a move
void Checkers::make_single_move(const std::string& move){
        int x1 = toupper(move.at(0)) - 65;   // centers it on 0 | x-direction
        int y1 = int(move.at(1)) - 49;  // this returns the exact int value | y-direction
        int x2 = toupper(move.at(2)) - 65;  // std::cout << x2 << std::endl;  // returns the exact int value | x-direction
        int y2 = move.at(3) - 49 ; // centers it on 0 | y-direction
        if(next_mover() == HUMAN){ // move is human / white
            board[y2][x2].make_not_empty();
            board[y2][x2].make_piece_white();
            if(board[y1][x1].is_piece_king()){
                board[y2][x2].make_piece_king();
            }
            if(y2 == 0){
                board[y2][x2].make_piece_king();
            }
            if(y2 == y1-2){ // gotta remove the jumped piece
                int y3 = y1-1; 
                int x3;
                if(x2 == x1+2){ // board geometry for jumped piece
                    x3 = x1+1;
                }
                else{
                    x3 = x1-1;
                }
                board[y3][x3].make_empty();
            }
            if(y2 == y1+2){ // gotta remove the jumped piece
                int y3 = y1+1; 
                int x3;
                if(x2 == x1+2){ // board geometry for jumped piece
                    x3 = x1+1;
                }
                else{
                    x3 = x1-1;
                }
                board[y3][x3].make_empty();
            }
           

        }
        else{ // move is computer (red)
            board[y2][x2].make_not_empty();
            board[y2][x2].make_piece_red();
            if(board[y1][x1].is_piece_king()){
                board[y2][x2].make_piece_king();
            }
            if(y2 == 7){
                board[y2][x2].make_piece_king();
            }
            if(y2 == y1+2){ // gotta remove the jumped piece
                int y3 = y1+1; 
                int x3;
                if(x2 == x1+2){ // board geometry for jumped piece
                    x3 = x1+1;
                }
                else{
                    x3 = x1-1;
                }
                board[y3][x3].make_empty();
            }
            if(y2 == y1+2){ // gotta remove the jumped piece
                int y3 = y1+1; 
                int x3;
                if(x2 == x1+2){ // board geometry for jumped piece
                    x3 = x1+1;
                }
                else{
                    x3 = x1-1;
                }
                board[y3][x3].make_empty();
            }
        }

        board[y1][x1].make_empty();

}




//checks to see if a move is legal
bool Checkers::is_legal(const std::string& move)const
{
    bool flag = true;
    if(move.size() % 2 != 0){ // odd number moves impossible
        return false; 
    }
    else if(move.size() < 3){ // answers less than 3 digits wrong are impossible
        return false;
    }
    else if(move.size() == 4){ // single move
        flag = single_move(move,0);
        return flag;
    }
    else{ // multiple jumps
        flag = multiple_moves(move);
        return flag;
    }

}

// checks to see if individual move is legal
bool Checkers::single_move(const std::string& move, int call) const // helper function for is_legal()
{
    bool flag = true;
    int x1 = toupper(move.at(0)) - 65;   // centers it on 0 | x-direction
    int y1 = int(move.at(1)) - 49;  // this returns the exact int value | y-direction
    int x2 = toupper(move.at(2)) - 65;  // std::cout << x2 << std::endl;  // returns the exact int value | x-direction
    int y2 = move.at(3) - 49 ; // centers it on 0 | y-direction


    if(next_mover() == HUMAN) // white pieces;
    {
        flag = white_move(x1,y1,x2,y2, call);
    }
    else{
        flag = red_move(x1,y1,x2,y2, call);
    }

    return flag;
}

// checks to see if move is legal for a white piece
bool Checkers::white_move(int x1, int y1, int x2, int y2, int call)const // white_move
{ 
    if(!board[y1][x1].is_piece_king()){
        //normal checks
        if(x2 != x1+1 && x2 != x1-1 && x2 != x1+2 && x2 != x1-2){
            return false;
        }
        if(x2 == x1+2 || x2 == x1-2){
            if((y2 != y1+2) && (y2 != y1-2) ){
                return false;
            }
        }
        if(y2 == y1+2 || y2 == y1-2){
            if((x2 != x1+2) && (x2 != y1-2) ){
                return false;
            }
        }
        if( (y1 >= 0 && y1 < 8 ) && (x1 >= 0 && x1 < 8) ){
            if((y2 < 0 ||  y2 > 8 ) || (x2 < 0 || x2 > 8)){
                return false;
            }
            if(board[y1][x1].is_empty() && call == 0){
                return false;
            }
            else{ // board is not empty
                if( ( y2 != y1-1) && (y2 != y1-2)){ // moving 'up' the board
                    return false;
                }
                else{ 
                    if(  (x2 != x1+1) && (x2 != x1-1) && (x2 != x1+2) && (x2 != x1-2) ){ // moving left or right
                        return false;
                    }
                    else{
                        if( x1 > x2 ){ 
                            if(!board[y1-1][x1-1].is_empty( ) ){
                                if(board[y1-1][x1-1].is_piece_white()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                        }
                        else{ // x1 < x2
                            if(!board[y1-1][x1+1].is_empty( ) ){
                                if(board[y1-1][x1+1].is_piece_white()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                        }
                    }
                }
                if(y2 < 0 || y2 > 8){ // make sure we dont run off the board
                    return false;
                }
                else if(x2 < 0 || x2 > 8){ // make sure we dont run off the board
                    return false;
                }
            }
        }
        else{
            return false;
        }
    }

    else{ // piece is a king

        //normal checks
        if(x2 != x1+1 && x2 != x1-1 && x2 != x1+2 && x2 != x1-2 ){
            return false;
        }
        if(x2 == x1+2 || x2 == x1-2){
            if((y2 != y1+2) && (y2 != y1-2) ){
                return false;
            }
        }
        if(y2 == y1+2 || y2 == y1-2){
            if((x2 != x1+2) && (x2 != y1-2) ){
                return false;
            }
        }
        if( (y1 >= 0 && y1 < 8 ) && (x1 >= 0 && x1 < 8) ){
            if((y2 < 0 ||  y2 > 8 ) || (x2 < 0 || x2 > 8)){
                return false;
            }
            if(board[y1][x1].is_empty() && call == 0){
                return false;
            }
            else{ // board is not empty
                if( (y2 != y1-1) && (y2 != y1+1) &&  (y2 != y1-2) && (y2 != y1+2 ) ){ // moving 'up' or 'down' the board
                    return false;
                    }
                else{ 
                    if(  (x2 != x1+1) && (x2 != x1-1) && (x2 != x1+2) && (x2 != x1-2)){ // moving left or right
                        return false;
                        }
                    else{
                        if( x1 > x2 ){ 
                            if(!board[y1-1][x1-1].is_empty( ) ){
                                if(board[y1-1][x1-1].is_piece_white()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                            if(!board[y1+1][x1-1].is_empty( ) ){
                                if(board[y1+1][x1-1].is_piece_white()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }


                        }
                        else{ // x1 < x2
                            if(!board[y1-1][x1+1].is_empty( ) ){
                                if(board[y1-1][x1-1].is_piece_white()){
                                   return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                            if(!board[y1+1][x1+1].is_empty( ) ){
                                if(board[y1+1][x1-1].is_piece_white()){
                                   return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                        }
                    }
                    if(y2 < 0 || y2 > 8){ // make sure we dont run off the board
                        return false;
                    }
                    else if(x2 < 0 || x2 > 8){ // make sure we dont run off the board
                        return false;
                    }
                }
            }
        }
        
        else{
            return false;
        }
    }
    bool final_flag = is_white_jump_possible(x1,y1, x2,y2 );
    if(!final_flag){
        return false;
    }
    return true;
}


// checks to see if a move is legal for a red piece
bool Checkers::red_move(int x1, int y1, int x2, int y2, int call)const
{
    if(!board[y1][x1].is_piece_king()){

        // normal checks
        if(x2 != x1+1 && x2 != x1-1 && x2 != x1+2 && x2 != x1-2 ){
            return false;
        }
        if(x2 == x1+2 || x2 == x1-2){
            if((y2 != y1+2) && (y2 != y1-2) ){
                return false;
            }
        }
          if(y2 == y1+2 || y2 == y1-2){
            if((x2 != x1+2) && (x2 != y1-2) ){
                return false;
            }
        }
        if( (y1 >= 0 && y1 < 8 ) && (x1 >= 0 && x1 < 8) ){
            if((y2 < 0 ||  y2 > 8 ) || (x2 < 0 || x2 > 8)){
                return false;
            }
            if(board[y1][x1].is_empty() && call == 0){
                return false;
            }
            else{ // board is not emtpy
                if((y2 != y1+1) && (y2 != y1+2)){ // moving 'up' the board
                    return false;
                    }
                else{ 
                    if(  (x2 != x1+1) && (x2 != x1-1) && (x2 != x1+2) && (x2 != x1-2)){ // moving left or right
                        return false;
                    }
                    else{
                        if( x1 > x2 ){ 
                            if(!board[y1+1][x1-1].is_empty( ) ){
                                if(board[y1+1][x1-1].is_piece_red()){
                                    return false;
                                }      
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }            
                            }
                        }
                        else{ // x1 < x2
                            if(!board[y1+1][x1+1].is_empty( ) ){
                                if(board[y1+1][x1+1].is_piece_red()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                        }
                    }
                    
                    if(y2 < 0 || y2 > 8){ // make sure we dont run off the board
                        return false;
                    }
                    else if(x2 < 0 || x2 > 8){ // make sure we dont run off the board
                        return false;
                    }
                }
            }
        }
        else{
            return false;
        }
    }


    else{ // piece is a king

        //normal checks
        if(x2 != x1+1 && x2 != x1-1 && x2 != x1+2 && x2 != x1-2 ){
            return false;
        }
        if(x2 == x1+2 || x2 == x1-2){
            if((y2 != y1+2) && (y2 != y1-2) ){
                return false;
            }
        }
        if(y2 == y1+2 || y2 == y1-2){
            if((x2 != x1+2) && (x2 != y1-2) ){
                return false;
            }
        }
        if( (y1 >= 0 && y1 < 8 ) && (x1 >= 0 && x1 < 8) ){
            if((y2 < 0 ||  y2 > 8 ) || (x2 < 0 || x2 > 8)){
                return false;
            }
            if(board[y1][x1].is_empty() && call == 0){
                return false;
            }
            else{ // the spot is not empty and you can actually jump
                if( (y2 != y1+1) && (y2 != y1-1) && (y2 != y1+2) && (y2 != y1-2)){ // moving 'up'nor 'down' the board
                    return false;
                }
                else{ 
                    if(  (x2 != x1+1) && (x2 != x1-1) && (x2 != x1+2) && (x2 != x1-2)){ // moving left or right
                        return false;
                    }
                    else{
                        if( x1 > x2 ){ 
                            if(!board[y1+1][x1-1].is_empty( ) ){
                                if(board[y1+1][x1-1].is_piece_red()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                            if(!board[y1-1][x1-1].is_empty( ) ){
                                if(board[y1-1][x1-1].is_piece_red()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                        }
                        else{ // x1 < x2
                            if(!board[y1+1][x1+1].is_empty( ) ){
                                if(board[y1+1][x1+1].is_piece_red()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                            if(!board[y1-1][x1+1].is_empty( ) ){
                                if(board[y1-1][x1+1].is_piece_red()){
                                    return false;
                                }
                                else if(!board[y2][x2].is_empty()){
                                    return false;
                                }
                            }
                        }
                    }
                }
                if(y2 < 0 || y2 > 8){ // make sure we dont run off the board
                        return false;
                    }
                else if(x2 < 0 || x2 > 8){ // make sure we dont run off the board
                    return false;
                    }
            }
        }
        else{
            return false;
        }

    }
    bool final_flag = is_red_jump_possible(x1,y1, x2,y2 );
    if(!final_flag){
        return false;
    }
    return true;
}

// parse complicated moves into individual 'single' moves
bool Checkers::multiple_moves(const std::string& move)const
{
    bool flag = true;

    for(int i = 0; i < move.size()-2; i+=2 ){ //move1, move2, move3,..., moveN have 2 parts, move1 -> move2, move2->move3,...,move(N-1)->moveN
        // std::cout << i << " " << move.at(i) << std::endl; 
        std::string moveN = move.substr(i,i+4); // std::cout << moveN << endl;
        flag = single_move(moveN, i);
        if(flag == false){ // want to stop as soon as one error is found
            return flag;
        }

    }
    return flag;
}

// returns who is winning
game::who Checkers::winning( )const
{
    int eval = evaluate();
    if(eval > 0){
        return COMPUTER;
    }
    else if(eval < 0){
        return HUMAN;
    }
    else if(eval == 0){
        return NEUTRAL;
    }
}

// evaluates the board. Kings are worth double compared to a normal piece
int Checkers::evaluate( ) const 
{
        int eval = 0; //postive eval favors red; negative eval favors white. 
		for (int y = 0; y < 8; ++y){
			for (int x = 0; x < 8; ++x)
			{   
                if(!board[y][x].is_empty()){ // piece is red
                    if(board[y][x].is_red()){
                        if(board[y][x].is_piece_king()){
                            eval+=2;
                        }
                        else{
                            eval+=1;
                        }
                    }
                    else{ // piece is white
                        if(board[y][x].is_piece_king()){
                            eval-=2;
                        }
                        else{
                            eval-=1;
                        }
                    }
                }
			}
        }
        return eval;
    };

// checks to see if game is over
bool Checkers::is_game_over( ) const {
    bool redLeft = false;
	bool whiteleft = false;
	for (int y = 0; y < 8; ++y){
		for (int x = 0; x < 8; ++x)
		{
			if (board[y][x].is_piece_red()){
                redLeft = true;
            } 
			if (board[y][x].is_piece_white()){
                whiteleft = 1;
            } 
		}
    }
	if ( ( redLeft == 0 ) || ( whiteleft == 0) ){ // no pieces in play, game is over
        return true;
    } 
    else{ // still pieces in play
		return false;
	}
}

// clones the game
game* Checkers::clone( )const
{
    return new Checkers(*this);
}


bool Checkers::is_white_jump_possible( int x1, int y1, int x2, int y2 )const
{
    struct xymove{
        int x1, y1, x2, y2;
    };
    bool flag = true; // generic return flag
    bool possible_jump = false; // flag for if a jump is possible
    vector<xymove> jumps;
    int size = jumps.size();
    for(int y = 2; y < 6; ++y ){
        for(int x = 2; x < 6; ++x){
            if( /*!board[y][x].is_empty() &&*/ board[y][x].is_piece_white()){
                if( (board[y+1][x+1].is_piece_red() && board[y+2][x+2].is_empty() ) ){ // jump is possible
                    possible_jump = true;
                    jumps.push_back({x1 = x, y1 = y,x2 = x+2, y2 = y+2 });
                }
                if((board[y+1][x-1].is_piece_red() && board[y+2][x-2].is_empty() ) ){ // jump is possible
                    possible_jump = true;
                    jumps.push_back({x1 = x, y1 = y, x2 = x-2, y2 = y+2 });
                }
                if(board[y][x].is_piece_king()){ // piece can move backwards
                    if( (board[y-1][x+1].is_piece_red() && board[y-2][x+2].is_empty() ) ){ // jump is possible
                        possible_jump = true;
                        jumps.push_back({x1 = x, y1 = y,x2 = x+2, y2 = y-2 });
                    }
                    if( (board[y-1][x-1].is_piece_red() && board[y-2][x-2].is_empty() ) ){ // jump is possible
                        possible_jump = true;
                        jumps.push_back({x1 = x, y1 = y,x2 = x-2, y2 = y-2 });
                    }
                }
            }
        } // x-loop
    } // y-loop
    if(possible_jump){
        for(int i = 0; i < jumps.size(); ++i ){
            if(x1 == jumps[i].x1 &&  y1 == jumps[i].y1 && x2 == jumps[i].x2 && y2 == jumps[i].y2){
                flag = true;
                return flag; 
            }
            else{
                std::cout << "\nPossible Jumps: ";
                for(int i = 0; i < jumps.size(); ++i ){
                    std::cout << jumps[i].y1 + 49;
                    std::cout << jumps[i].x1 + 65;
                    std::cout << jumps[i].y2 + 49;
                    std::cout << jumps[i].x2 + 65;
                    std::cout << " ";
                }
                std::cout << std::endl;
                flag = false;
                return flag;
            }
        }
    }

    return flag;
}



bool Checkers::is_red_jump_possible( int x1, int y1, int x2, int y2 )const
{
    struct xymove{
        int x1, y1, x2, y2;
    };
    bool flag = true; // generic return flag
    bool possible_jump = false; // flag for if a jump is possible
    vector<xymove> jumps;
    int size =  jumps.size();
    for(int y = 2; y < 6; ++y ){
        for(int x = 2; x < 6; ++x){
            if( /*!board[y][x].is_empty() &&*/ board[y][x].is_piece_white()){
                if( (board[y-1][x+1].is_piece_red() && board[y-2][x+2].is_empty() ) ){ // jump is possible
                    possible_jump = true;
                    jumps.push_back({x1 = x, y1 = y,x2 = x+2, y2 = y-2 });
                }
                if((board[y-1][x-1].is_piece_red() && board[y-2][x-2].is_empty() ) ){ // jump is possible
                    possible_jump = true;
                    jumps.push_back({x1 = x, y1 = y, x2 = x-2, y2 = y-2 });
                }
                if(board[y][x].is_piece_king()){ // piece can move forewards
                    if( (board[y+1][x+1].is_piece_red() && board[y+2][x+2].is_empty() ) ){ // jump is possible
                        possible_jump = true;
                        jumps.push_back({x1 = x, y1 = y,x2 = x+2, y2 = y+2 });
                    }
                    if( (board[y+1][x-1].is_piece_red() && board[y+2][x-2].is_empty() ) ){ // jump is possible
                        possible_jump = true;
                        jumps.push_back({x1 = x, y1 = y,x2 = x-2, y2 = y+2 });
                    }
                }
            }
        } // x-loop
    } // y-loop
    if(possible_jump){
        for(int i = 0; i < jumps.size(); ++i ){
            if(x1 == jumps[i].x1 &&  y1 == jumps[i].y1 && x2 == jumps[i].x2 && y2 == jumps[i].y2){
                flag = true;
                return flag; 
            }
            else{
                std::cout << "\nPossible Jumps: ";
                for(int i = 0; i < jumps.size(); ++i ){
                    std::cout << jumps[i].y1 + 49;
                    std::cout << jumps[i].x1 + 65;
                    std::cout << jumps[i].y2 + 49;
                    std::cout << jumps[i].x2 + 65;
                    std::cout << " ";
                }
                std::cout << std::endl;
                flag = false;
                return flag;
            }
        }
    }

    return flag;
}



std::string Checkers::get_user_move( ) const
{
	string answer;
    if(next_mover() == HUMAN){
        display_message("White To Move");
    }
    else{
        display_message("Red To Move:");
    }
	display_message("(Ex A6B5)\nYour move, please: ");
	getline(cin, answer);
	return answer;
}

} // namespace namespace main_savitch_14