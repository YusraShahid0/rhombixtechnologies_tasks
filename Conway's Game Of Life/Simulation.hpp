#pragma once
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Grid.hpp"

using namespace std;
using namespace sf;

class Simulation
{
private:
    Grid grid;
    Grid tempGrid;

public:
    // parameterized constructor
    Simulation(int width, int height, int cellSize) : 
    grid(width, height, cellSize), tempGrid(width, height, cellSize) {}

    //drawing the simulation on the window
    void make(RenderWindow &window);

    //setting the value of a cell
    void SetValue(int row, int col, int value);

    int GetValue(int row, int col);

    // counting the neighbors around a cell
    int NeighborCount(int row, int col);

    // updating the value of a cell based on Game of Life's conditions
    void update(int row, int col);

    // running the simulation
    void run(RenderWindow &window);
};

#endif