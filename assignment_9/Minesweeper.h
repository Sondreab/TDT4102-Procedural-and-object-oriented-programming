#pragma once

class Minesweeper {
private:

	struct Tile {
		bool open;
		bool mine;
		bool flagged;
	};

	int width;
	int height;
	int mines;
	bool gameOver;
	Tile **gameBoard;

public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

	bool isFlagTile(int row, int col) const;
	void setFlagTile(int row, int col) const;
	
    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};
