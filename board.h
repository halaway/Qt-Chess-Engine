#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Class Board Representing the ChessBoard along with the rules for allowing 
 * valid chess captures, moves, and checks. 
 * 
 */
class Board
{
public:
    /**
     * @brief Define the BoardPiece struct inside the Piece class
     * 
     */
    struct BoardPiece
    {
        bool is_opponent = false;
        std::string p_name;
        bool is_empty = false;
    };

public:
    std::vector<std::vector<BoardPiece>> board; // Board represented as a 2D vector of type BoardPiece

    Board(); // Default constructor Create Board

    void Print(); // Printing Board for Debug

    /**
     * @brief Positions a Piece within Board object given start and end position 
     * 
     * @param start Pair consisting of row, column coordinates 
     * @param end Pair consisting of row, column coordinates 
     * @return true 
     * @return false 
     */
    bool Position_Piece(std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief Determines valid move for an opponent's position given start and end position
     * 
     * @param start 
     * @param end 
     * @return true 
     * @return false 
     */
    bool OpponentPosition(std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief Determines whether a piece can move from the start position to the end position
     * while delegating to more specific functions depending on the piece type.
     * 
     * @param board 
     * @param start 
     * @param end 
     * @return true 
     * @return false 
     */
    friend bool Allowed_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief Determines whether a Pawn can move from the start position to the end position
     */
    friend bool Can_Pawn_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief  Determines whether a King can move from the start position to the end position
     */
    friend bool Can_King_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);

    // Can Queen Move to end Location

    /**
     * @brief Determines whether a Queen can move from the start position to the end position
     */
    friend bool Can_Queen_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief Determines whether a Knight can move from the start position to the end position
     * 
     */
    friend bool Can_Knight_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief Determines whether a Rook can move from the start position to the end position
     */
    friend bool Can_Rook_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);

    /**
     * @brief Determines whether a Bishop can move from the start position to the end position
     */
    friend bool Can_Bishop_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end);
};

/*
 * First: Handle Piece Rules
 * Second: Handle Piece Moves
 * Third: Handle Ending
 *
 */

#endif // BOARD_H
