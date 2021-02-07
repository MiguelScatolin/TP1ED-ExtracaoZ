#ifndef POSITION_H
#define POSITION_H

class Position
{
    public:
        Position() {}
        Position(int x, int y) : x(x), y(y) {}

    private:
        int x;
        int y;

    friend class Robot;
};

#endif