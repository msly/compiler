#include "stdafx.h"
#include "Token.h"

using namespace std;


Token::Token(TYPE type, int value) : type(type), value(value)
{
       
}


Token::~Token()
{
}

std::string Token::toString()
{
    std::string typeName[] = { "INTEGER", "PLUS", "END" };
    return "TOKEN(" + typeName[static_cast<int>(this->type)] + ", " + to_string(this->value) + ")";
}
