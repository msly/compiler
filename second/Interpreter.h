#pragma once

#include "Token.h"
#include "Lexer.h"

class Interpreter
{
public:
    Interpreter(Lexer lexer);
    ~Interpreter();

public:
    int expr();
    void eat(Token::TYPE tpye);
    int term();
    int factor();

    

private:
    Token current_token;

    Lexer lexer;
    
};

