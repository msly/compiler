#pragma once

#include <cstdint>

class Token
{

public:
    enum class TYPE:std::int8_t
    {
        INTEGER = 0,
        PLUS = 1,
        END = 2
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

