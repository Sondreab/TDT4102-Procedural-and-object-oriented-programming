#include "Minesweeper.h"
#include "utilities.h"

Minesweeper::Minesweeper(int width, int height, int mines) 
	:width(width), height(height), mines(mines), gameOver(false)
{
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	gameBoard = new Tile* [height];
	for (int i = 0; i < height; i++)
	{
		gameBoard[i] = new Tile[width];
		for (int j = 0; j < width; j++)
		{
			gameBoard[i][j].mine = false;
			gameBoard[i][j].open = false;
			gameBoard[i][j].flagged = false;
		}
	}
	int minesPlaced = 0;
	while (minesPlaced < mines)
	{
		int row = modernRandomWithLimits(0, height - 1, generator);
		int col = modernRandomWithLimits(0, width - 1, generator);
		if (!gameBoard[row][col].mine)
		{
		gameBoard[row][col].mine = true;
		minesPlaced++;
		}
	}
}

Minesweeper::~Minesweeper() {
	for (int i = 0; i < height; i++)
	{
		delete[] this->gameBoard[i];
	}
	delete[] this->gameBoard;
	this->gameBoard = nullptr;
}

bool Minesweeper::isGameOver() const {
    return gameOver;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    return gameBoard[row][col].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return gameBoard[row][col].mine;
}

bool Minesweeper::isFlagTile(int row, int col) const
{
	return gameBoard[row][col].flagged;
}

void Minesweeper::setFlagTile(int row, int col) const
{
	if (!gameBoard[row][col].open)
	{
		if (isFlagTile(row, col))
		{
			gameBoard[row][col].flagged = false;
		}
		else
		{
			gameBoard[row][col].flagged = true;
		}
	}
}

void Minesweeper::openTile(int row, int col) {
	if (isFlagTile(row, col)) { return; }
		gameBoard[row][col].open = true;
	if (gameBoard[row][col].mine)
	{
		gameOver = true;
	}
	
	if (!numAdjacentMines(row, col))
	{
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int j = col - 1; j <= col + 1; j++)
			{
				if ((i >= 0 && i <= height - 1) && (j >= 0 && j <= width - 1))
				{
					if (!gameBoard[i][j].open && !gameBoard[i][j].flagged)
					{
					openTile(i, j);
					}
				}
			}
		}
	}
}

int Minesweeper::numAdjacentMines(int row, int col) const {
	int numMines = 0;
	for (int i = row - 1; i <= row + 1; i++)
	{
		for (int j = col - 1; j <= col + 1; j++)
		{
			if ((i >= 0 && i <= height - 1) && (j >= 0 && j <= width - 1))
			{
				if (gameBoard[i][j].mine)
				{
					numMines++;
				}
			}
		}
	}
    return numMines;
}
