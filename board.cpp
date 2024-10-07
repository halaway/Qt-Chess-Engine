#include "board.h"
#include <utility>
#include <iostream>
#include <string>
#include <vector>

// Enumeration representing the codes for different chess piece types.
enum string_code
{
    pawn,
    king,
    queen,
    rook,
    bishop,
    knight
};

// Converts string representation of a chess piece type to its corresponding code.
string_code switch_piece(std::string const &inString)
{
    if (inString == "pawn")
        return pawn;
    if (inString == "king")
        return king;
    if (inString == "queen")
        return queen;
    if (inString == "rook")
        return rook;
    if (inString == "bishop")
        return bishop;
    if (inString == "knight")
        return knight;

    else
        return pawn;
}

// Creating Board Environment & Board Functions
Board::Board()
{

    // INITIAL CHESS BOARD
    std::vector<std::vector<BoardPiece>> init_board(8, std::vector<BoardPiece>(8));

    // Initialize the first and last rows - rooks, knights, bishops
    std::string backRank[] = {"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"};
    for (int i = 0; i < 8; ++i)
    {

        init_board[0][i] = {true, backRank[i], false};  // Black pieces lie on the lower ranks
        init_board[7][i] = {false, backRank[i], false}; // White pieces lie on the higher ranks
    }

    // Initializing the second and seventh rows of pawns
    for (int i = 0; i < 8; ++i)
    {

        init_board[1][i] = {true, "pawn", false};  // Black pawns
        init_board[6][i] = {false, "pawn", false}; // White pawns
    }

    // Initializing empty squares
    for (int row = 2; row < 6; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            init_board[row][col] = {false, "-", true};
        }
    }

    // Assiging board
    board = init_board;
}

// TEST PRINT
void Board::Print()
{

    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            std::cout << board[i][j].p_name << " ";
        }
        std::cout << " " << std::endl;
    }
    std::cout << "" << std::endl;
}

// Checking Valid Board Position & Re Assigning value
bool Board::Position_Piece(std::pair<int, int> start, std::pair<int, int> end)
{

    if (Allowed_Move(*this, start, end))
    {
        board[end.first][end.second] = board[start.first][start.second];

        board[start.first][start.second] = BoardPiece{true, "-", true};

        return true;
    }
    return false;
}

// Determing if opponents move is valid given start and end position
bool Board::OpponentPosition(std::pair<int, int> start, std::pair<int, int> end)
{

    if (Allowed_Move(*this, start, end))
    {
        return true;
    }
    return false;
}

// Outer Function to switch based on piece
bool Allowed_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{

    int s_xpos = start.first;
    int s_ypos = start.second;

    std::string current_piece = board.board[s_xpos][s_ypos].p_name;

    switch (switch_piece(current_piece))
    {
    case pawn:
        return Can_Pawn_Move(board, start, end);

    case king:
        return Can_King_Move(board, start, end);

    case queen:
        return Can_Queen_Move(board, start, end);

    case bishop:
        return Can_Bishop_Move(board, start, end);

    case knight:
        return Can_Knight_Move(board, start, end);

    case rook:
        return Can_Rook_Move(board, start, end);
    }

    return true;
}

// Can Pawn Move to end Location
bool Can_Pawn_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{
    int s_xpos = start.first;
    int s_ypos = start.second;

    int e_xpos = end.first;
    int e_ypos = end.second;

    // Determining the direction of movement is an opponent's piece
    int direction = board.board[s_xpos][s_ypos].is_opponent ? 1 : -1;

    // Move one square forward if the destination is empty
    if (e_xpos == s_xpos + direction && s_ypos == e_ypos && board.board[e_xpos][e_ypos].is_empty)
    {
        return true;
    }

    // Move two squares forward from the initial position
    if (s_xpos == (board.board[s_xpos][s_ypos].is_opponent ? 1 : 6) && e_xpos == s_xpos + 2 * direction && s_ypos == e_ypos && board.board[e_xpos][e_ypos].is_empty && board.board[s_xpos + direction][s_ypos].is_empty)
    {
        return true;
    }

    // Capture diagonally if empty or opponents piece
    if (e_xpos == s_xpos + direction && (e_ypos == s_ypos - 1 || e_ypos == s_ypos + 1) &&
        (!board.board[e_xpos][e_ypos].is_empty && board.board[e_xpos][e_ypos].is_opponent))
    {
        return true;
    }

    return false;
}

// Can the Rook Move to end Location
bool Can_Rook_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{
    int s_xpos = start.first;
    int s_ypos = start.second;

    int e_xpos = end.first;
    int e_ypos = end.second;

    // Check if the move is either horizontal or vertical
    if (s_xpos != e_xpos && s_ypos != e_ypos)
    {
        return false; // Rook cannot move diagonally
    }

    // Check horizontal movement
    if (s_xpos == e_xpos)
    {
        // Moving in the same row
        int start_col = std::min(s_ypos, e_ypos);
        int end_col = std::max(s_ypos, e_ypos);
        for (int col = start_col + 1; col < end_col; ++col)
        {
            if (!board.board[s_xpos][col].is_empty)
            {
                return false; // Path is blocked
            }
        }
        // Check if the destination contains an opponent's piece
        if (!board.board[e_xpos][e_ypos].is_empty && board.board[e_xpos][e_ypos].is_opponent)
        {
            return true; // Can capture opponent's piece
        }
        // Check if destination is empty
        if (board.board[e_xpos][e_ypos].is_empty)
        {
            return true; // Move is valid and destination is empty
        }
    }
    // Check vertical movement
    else if (s_ypos == e_ypos)
    {
        // Moving in the same column
        int start_row = std::min(s_xpos, e_xpos);
        int end_row = std::max(s_xpos, e_xpos);
        for (int row = start_row + 1; row < end_row; ++row)
        {
            if (!board.board[row][s_ypos].is_empty)
            {
                return false; // Path is blocked
            }
        }
        // Check if the destination contains an opponent's piece
        if (!board.board[e_xpos][e_ypos].is_empty && board.board[e_xpos][e_ypos].is_opponent)
        {
            return true; // Can capture opponent's piece
        }
        // Check if destination is empty
        if (board.board[e_xpos][e_ypos].is_empty)
        {
            return true; // Move is valid and destination is empty
        }
    }

    // If none of the conditions are met, the move is invalid
    return false;
}

// Can the Knight move end Location
bool Can_Knight_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{

    // Setting positions
    int s_xpos = start.first;
    int s_ypos = start.second;

    int e_xpos = end.first;
    int e_ypos = end.second;

    // Calculating absolute differences coordinates
    int dx = std::abs(e_xpos - s_xpos);
    int dy = std::abs(e_ypos - s_ypos);

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
    {

        if (board.board[e_xpos][e_ypos].is_empty || board.board[e_xpos][e_ypos].is_opponent)
        {
            return true;
        }
    }

    return false;
}

// Can Bishop Move to end Location
bool Can_Bishop_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{
    int s_xpos = start.first;
    int s_ypos = start.second;

    int e_xpos = end.first;
    int e_ypos = end.second;

    // Calculating differences in positions
    int dx = std::abs(e_xpos - s_xpos);
    int dy = std::abs(e_ypos - s_ypos);

    if (dx != dy)
    {
        return false;
    }

    // Determining direction of movement
    int x_direction = (e_xpos > s_xpos) ? 1 : -1;
    int y_direction = (e_ypos > s_ypos) ? 1 : -1;

    // Check all intermediate squares
    int x = s_xpos + x_direction;
    int y = s_ypos + y_direction;

    while (x != e_xpos && y != e_ypos)
    {
        if (!board.board[x][y].is_empty)
        {
            return false;
        }
        x += x_direction;
        y += y_direction;
    }

    return board.board[e_xpos][e_ypos].is_empty || board.board[e_xpos][e_ypos].is_opponent;
}

// Can Queen Move to end Location
bool Can_Queen_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{

    // Combination of Rook & Bishop Function
    return (Can_Rook_Move(board, start, end) || Can_Bishop_Move(board, start, end));
}

// Can King Move to end Location
bool Can_King_Move(const Board &board, std::pair<int, int> start, std::pair<int, int> end)
{

    if (std::abs(start.first - end.first) > 1 || std::abs(start.second - end.second) > 1)
    {
        return false;
    }

    // TODO: Determine if king can take

    if (!board.board[end.first][end.second].is_empty && !board.board[end.first][end.second].is_opponent)
    {
        return false;
    }

    return true;
}

