#pragma once

class Matrix {
private:
	unsigned int rows, columns;
	double *data;

public:
	Matrix();
	explicit Matrix(unsigned int nRows, unsigned int nColumns);
	Matrix(unsigned int nRows);
	~Matrix();
	Matrix(const Matrix & rhs);

	int index(unsigned int row, unsigned int column) const;
	void print();
	double get(unsigned int row, unsigned int col) const;
	void set(unsigned int row, unsigned int col, double value) const;
	int getHeight() const;
	int getWidth() const;
	bool isValid() const;

	Matrix operator =(Matrix rhs);
	Matrix& operator +=(Matrix &rhs);
	Matrix operator +(Matrix &rhs);
	Matrix& operator -=(Matrix &rhs);
	Matrix operator -(Matrix &rhs);
	//Matrix& operator *=(Matrix &rhs);
	//Matrix operator *(Matrix &rhs);
};

std::ostream& operator <<(std::ostream &os, const Matrix &data);
