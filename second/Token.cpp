#include "stdafx.h"
#include "Token.h"

using namespace std;


Token::Token(TYPE type/* = Token::TYPE::END*/, int value/* = 0*/) 
    : type(type)
    , value(value)
{
       
}


Token::~Token()
{
}

std::string Token::toString()
{
    std::string typeName[] = { "INTEGER", "PLUS", "MINUS", "MUL", "DIV", "LPAREN", "RPAREN", "END" };
    return "TOKEN(" + typeName[static_cast<int>(this->type)] + ", " + to_string(this->value) + ")";
}
