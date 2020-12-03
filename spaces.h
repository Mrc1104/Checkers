/***
 * File: spaces.h
 * Brief: space class, stores the states of the squares on a checker board
 * 
 * Author: Ryan Conaway
 * Email: mc321015@ohio.edu
 * 
 * Last Modified: 11/24/2020 
 */
#ifndef SPACES_H
#define SPACES_H


namespace main_savitch_14
{

class spaces // board states
{

    public:

    //simple state checks
    bool is_empty()const; // is the square occupied
    bool is_red()const; // is the square red
    bool is_black()const; // is the square black
    bool is_piece_white()const; // is the piece on the square white
    bool is_piece_red()const; // is the piece on the square red
    bool is_piece_king()const;

    // change state -- piece
    void make_piece_white(); // makes the piece white
    void make_piece_red(); // makes the piece red
    void make_piece_king();


    // change state -- color
    void make_black(); // make the square black
    void make_red(); // make the square red

    // change state -- emptiness
    void make_empty(); // makes the square empty
    void make_not_empty(); // makes the square not empty


    private:
    bool empty = true; // is the square empty
    bool red = false; // is the piece/space red
    bool black = false; // is the space black
    bool piece_red = false; // is the piece white
    bool piece_white = false; // if true, piece is white
    bool piece_king = false; // no kings at start


};





} // namespace main_savitch_14






#endif