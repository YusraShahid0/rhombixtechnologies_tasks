#include "Grid.hpp"

void Grid::make(RenderWindow &window){

    for (int row=0; row<rows; row++){
        for (int col=0; col<columns; col++){
            Color color = Cells[row][col] ? Color{0,255, 50, 255} : Color{55, 55, 55, 255};
            RectangleShape cell;
            cell.setSize(Vector2f(cellSize, cellSize));
            cell.setFillColor(color);
            cell.setOutlineThickness(2);
            cell.setOutlineColor(Color{100, 100, 100, 255});
            cell.setPosition(Vector2f(row*cellSize + 2, col*cellSize + 2));
            window.draw(cell);
        }
    }
}

void Grid::setCellValue(int row, int col, int value){
    if ((row>=0) && (row<rows) && (col>=0) && (col<columns)){
        Cells[row][col] = value;
    }
}

int Grid::getCellValue(int row, int col)
{
    return Cells[row][col];
}

void Grid::randomLive(){
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < columns; col++){
            int randomNum = rand() % 6;
            Cells[row][col] = (randomNum == 1) ? 1 : 0;
        }
    }
}

int Grid::getRows()
{
    return rows;;
}

int Grid::getColumns()
{
    return columns;
}

void Grid::clear() {
    for (auto& row : Cells) {
        fill(row.begin(), row.end(), 0);
    }
}