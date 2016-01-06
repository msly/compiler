#pragma once

#include <cstdint>

class Token
{

public:
    enum class TYPE:std::int8_t
    {
        INTEGER = 0,
        PLUS = 1,
        MINUS = 2,
        MUL = 3,
        DIV = 4,
        END = 5
    };

    

public:
    Token(TYPE type, int value);
    ~Token();

public:
    std::string toString();

public:
    TYPE type;
    int value;
};

