#include "Simulation.hpp"
#include <iostream>
using namespace std;

void Simulation::make(RenderWindow & window){
    grid.make(window);
}

void Simulation::SetValue(int row, int col, int value){
    grid.setCellValue(row, col, value);
}

int Simulation::GetValue(int row, int col)
{
    return grid.getCellValue(row, col);
}

int Simulation::NeighborCount(int row, int col){
    int neighbors = 0;
    int offsetPairs[8][2] = {{0,-1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}};
   
    for (int i=0; i<8; i++){
        int neighborRow = row + offsetPairs[i][0];
        int neighorCol = col + offsetPairs[i][1];

        if ((neighborRow >= 0) && (neighborRow < grid.getRows()) && 
        (neighorCol >= 0) && (neighorCol < grid.getColumns())){
            
            neighbors += grid.getCellValue(neighborRow, neighorCol);
        }
    }

    return neighbors;
}

void Simulation::update(int row, int col){
    int neighbors = NeighborCount(row, col);
    int value = grid.Cells[row][col];

    if ((neighbors < 2) || (neighbors > 3)){
        value = 0;
    }

    else if (neighbors == 3){
        value = 1;
    }

    tempGrid.setCellValue(row, col, value);
}

void Simulation::run(RenderWindow &window){
    int rows = grid.getRows();
    int cols = grid.getColumns();

    tempGrid.clear();
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            update(row, col);
        }
    }
    grid.Cells = tempGrid.Cells;
    make(window);
}