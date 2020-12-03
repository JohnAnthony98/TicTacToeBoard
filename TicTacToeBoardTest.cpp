/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, boardStartsBlank)
{
  TicTacToeBoard game;
  bool empty = true;

  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      if(game.getPiece(i, j) != Blank){
        empty = false;
      }
    }
  }

	ASSERT_TRUE(empty);
}

TEST(TicTacToeBoardTest, xStartsGame)
{
  TicTacToeBoard game;
  game.placePiece(0, 0);
	ASSERT_TRUE(game.getPiece(0, 0) == X);
}

TEST(TicTacToeBoardTest, oGoesSecond)
{
  TicTacToeBoard game;
  game.placePiece(0, 0);
  game.placePiece(1, 0);
	ASSERT_TRUE(game.getPiece(1, 0) == O);
}

TEST(TicTacToeBoardTest, placeRowUnderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(-1, 0) == Invalid);
}

TEST(TicTacToeBoardTest, placeRowOverLimit)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(99, 0) == Invalid);
}

TEST(TicTacToeBoardTest, placeColumnUnderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(0, -1) == Invalid);
}

TEST(TicTacToeBoardTest, placeColumnOverLimit)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(0, 99) == Invalid);
}

TEST(TicTacToeBoardTest, placeRowUnderColOverZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(-1, 99) == Invalid);
}

TEST(TicTacToeBoardTest, placeRowOverColunderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(99, -1) == Invalid);
}

TEST(TicTacToeBoardTest, placeRowOverColOverZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(99, 99) == Invalid);
}

TEST(TicTacToeBoardTest, placeRowUnderColUnderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.placePiece(-1, -1) == Invalid);
}

TEST(TicTacToeBoardTest, getRowUnderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(-1, 0) == Invalid);
}

TEST(TicTacToeBoardTest, getRowOverLimit)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(99, 0) == Invalid);
}

TEST(TicTacToeBoardTest, getColumnUnderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(0, -1) == Invalid);
}

TEST(TicTacToeBoardTest, getColumnOverLimit)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(0, 99) == Invalid);
}

TEST(TicTacToeBoardTest, getRowUnderColOverZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(-1, 99) == Invalid);
}

TEST(TicTacToeBoardTest, getRowOverColunderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(99, -1) == Invalid);
}

TEST(TicTacToeBoardTest, getRowOverColOverZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(99, 99) == Invalid);
}

TEST(TicTacToeBoardTest, getRowUnderColUnderZero)
{
  TicTacToeBoard game;
	ASSERT_TRUE(game.getPiece(-1, -1) == Invalid);
}

TEST(TicTacToeBoardTest, placeOnNonBlankSpace)
{
  TicTacToeBoard game;
  game.placePiece(2, 1);
	ASSERT_TRUE(game.placePiece(2, 1) == Invalid);
}
