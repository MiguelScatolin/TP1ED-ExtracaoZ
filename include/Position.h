#ifndef POSITION_H
#define POSITION_H

#include <string>

class Position
{
    public:
        Position() {}
        Position(int x, int y) : x(x), y(y) {}
        std::string ToString() { return "(" + std::to_string(x) + "," + std::to_string(y) + ")"; };

    private:
        int x;
        int y;

    friend class Map;
};

#endif