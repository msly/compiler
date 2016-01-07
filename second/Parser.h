#pragma once

#include "Token.h"
#include "Lexer.h"
#include "BinOp.h"

class Parser
{
public:
    Parser(Lexer lexer);
    ~Parser();

public:
    BinOp_ptr expr();
    void eat(Token::TYPE tpye);
    BinOp_ptr term();
    BinOp_ptr factor();

private:
    Token current_token;

    Lexer lexer;
};

