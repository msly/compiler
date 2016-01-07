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
        LPAREN = 5,
        RPAREN = 6,
        END = 7
    };

    

public:
    Token(TYPE type = Token::TYPE::END, int value = 0);
    ~Token();

public:
    std::string toString();

public:
    TYPE type;
    int value;
};

