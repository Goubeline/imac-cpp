#pragma once

struct Position
{
    int x = 0;
    int y = 0;
};

enum Direction{
    Up,
    Down,
    Forward,
    Backward
};

struct Move
{
    enum Direction direction;
    unsigned int distance;
};