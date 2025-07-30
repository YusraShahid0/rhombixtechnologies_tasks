#pragma once
#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Grid
{
protected:
    const int rows;
    const int columns;
    const int cellSize;

public:
    vector<vector<int>> Cells;

    // default constructor
    Grid() : rows(0), columns(0), cellSize(0), Cells(0, vector<int>(0, 0)) {}

    // parameterized constructor
    Grid(int width, int height, int cellSize) : 
    rows(width / cellSize), columns(height / cellSize), cellSize(cellSize), Cells(rows, vector<int>(columns, 0))
    {
        randomLive();
    }

    // drawing the grid
    void make(RenderWindow &window);

    // setting a cell's value and color
    void setCellValue(int row, int col, int value);

    //getting a cell's value
    int getCellValue(int row, int col);

    // generating random live cells
    void randomLive();

    // getting number of rows
    int getRows();

    // getting number of columns
    int getColumns();

    // clear the grid
    void clear();
};

#endif