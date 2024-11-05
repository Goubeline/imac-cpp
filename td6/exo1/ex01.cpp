#include <iostream>
#include <vector>

#include "exo01.hpp"

void display(Position submarine)
{
    std::cout << "Position du sous marin : (" << submarine.x << ", " << submarine.y << ')' << std::endl;
}

void moveSubmarine(Position& submarine, Move move)
{
    switch (move.direction)
    {
    case Up:
        submarine.y += move.distance;
        break;
    case Down:
        submarine.y -= move.distance;
        break;
    case Forward:
        submarine.x += move.distance;
        break;
    default:
        submarine.x -= move.distance;
        break;
    }
}

int main()
{
        Position submarine;
    std::vector<Move> moves = {
        {Direction::Forward, 10},
        {Direction::Down, 5},
        {Direction::Backward, 3},
        {Direction::Up, 2},
        {Direction::Forward, 5},
        {Direction::Down, 1},
        {Direction::Backward, 2},
        {Direction::Forward, 3},
        {Direction::Down, 1},
        {Direction::Up, 3},
        {Direction::Forward, 1},
        {Direction::Down, 5},
        {Direction::Backward, 2},
        {Direction::Forward, 6}
    };

    for (Move move : moves)
    {
        moveSubmarine(submarine, move);
        display(submarine);
    }
    return 0;
}
