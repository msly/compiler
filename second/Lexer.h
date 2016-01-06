#pragma once

#include "Token.h"

class Lexer
{
public:
    Lexer(std::string text);
    ~Lexer();

public:
    Token get_next_token();
    void skip_space();
    void advance();
    int integer();

private:
    std::string input_text;

    char current_char;

    uint32_t pos;


};

