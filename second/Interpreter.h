#pragma once

#include "Token.h"

class Interpreter
{
public:
    Interpreter(std::string text);
    ~Interpreter();

public:
    int expr();

    void eat(Token::TYPE tpye);

    Token get_next_token();

private:

    std::string input_text;

    Token current_token;

    uint32_t pos;
};

