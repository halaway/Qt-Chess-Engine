#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>


class Board
{
public:
    // Define the BoardPiece struct inside the Piece class
    struct BoardPiece
    {
        bool is_opponent = false;
        std::string p_name;
        bool is_empty = false;
    };

//private:
    // Chess Board Vector
    //std::vector< std::vector<BoardPiece> > board;

public:

    std::vector< std::vector<BoardPiece> > board;
    // Default constructor Create Board
    Board();

    //Printing Board
    void Print();

    //Position Piece const Board& board,
    bool Position_Piece(std::pair<int, int> start, std::pair<int,int> end);

    bool OpponentPosition(std::pair<int,int> start,std::pair<int,int> end );



    // Can Piece Move to Position : Switches Based on Type
    friend bool Allowed_Move(const Board& board, std::pair<int, int> start, std::pair<int ,int> end);

    // Can Pawn Move to end Location
    friend bool Can_Pawn_Move(const Board& board, std::pair<int, int> start, std::pair<int, int> end);

    // Can King Move to end Location
    friend bool Can_King_Move(const Board& board, std::pair<int, int> start, std::pair<int, int> end);

    // Can Queen Move to end Location
    friend bool Can_Queen_Move(const Board& board, std::pair<int, int> start, std::pair<int, int> end);

    // Can Knight Move to end Location
    friend bool Can_Knight_Move(const Board& board, std::pair<int, int> start, std::pair<int, int> end);

    // Can Rook Move to end Location
    friend bool Can_Rook_Move(const Board& board, std::pair<int, int> start, std::pair<int, int> end);

    // Can Bishop Move to end Location
    friend bool Can_Bishop_Move(const Board& board, std::pair<int, int> start, std::pair<int, int> end);

};



/*
 * First: Handle Piece Rules
 * Second: Handle Piece Moves
 * Third: Handle Ending
 *
 */


#endif // BOARD_H
