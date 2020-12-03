#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    turn = O;
    return turn;
  }
  else if(turn == O){
    turn = X;
    return turn;
  }
  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //check for out of bounds
  if(row < 0 || row >= BOARDSIZE || column < 0 || column >= BOARDSIZE){
    return Invalid;
  }
  //check to make sure place is empty
  if(board[row][column] != Blank){
    return Invalid;
  }
  Piece placed = turn;
  board[row][column] = placed;
  toggleTurn();
  return placed;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < 0 || row >= BOARDSIZE || column < 0 || column >= BOARDSIZE){
    return Invalid;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  //8 Unique Win Conditions per Player
  //1. 3 on top row
  if(board[0][0] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][0];
    if(board[1][0] == checkingPiece && board[2][0] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //2. 3 on middle row
  if(board[0][1] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][1];
    if(board[1][1] == checkingPiece && board[2][1] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //3. 3 on bottom row
  if(board[0][2] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][2];
    if(board[1][2] == checkingPiece && board[2][2] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //4. 3 on left Column
  if(board[0][0] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][1];
    if(board[0][1] == checkingPiece && board[0][2] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //5. 3 on middle Column
  if(board[1][0] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][1];
    if(board[1][1] == checkingPiece && board[1][2] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //6. 3 on right Column
  if(board[2][0] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][1];
    if(board[2][1] == checkingPiece && board[2][2] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //7. 3 on left Diagonal
  if(board[0][0] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][1];
    if(board[1][1] == checkingPiece && board[2][2] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //8. 3 on Right Diagonal
  if(board[2][0] != empty){
    //get piece on first spot
    Piece checkingPiece = board[0][1];
    if(board[1][1] == checkingPiece && board[0][2] == checkingPiece){
      //three in a row
      return checkingPiece;
    }
  }
  //at this point, there is no winner
  bool full = true;
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      if(board[i][j] == Blank){
        full = false;
      }
    }
  }
  if(full){
    return Blank;
  }
  return Invalid;
}
