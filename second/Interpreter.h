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

    void skip_space();

    void advance();

    int integer();

private:

    std::string input_text;

    Token current_token;
    char current_char;

    uint32_t pos;
};

