#pragma once

#include "Parser.h"


class Interpreter
{
public:
    Interpreter(Parser parser);
    ~Interpreter();

public:

    int interpret();

    int visit(BinOp_ptr tree);

private:
    Parser parser;
    
};

