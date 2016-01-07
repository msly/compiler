#pragma once

#include "AST.h"
#include "Token.h"



class BinOp : public AST
{
public:
    typedef std::shared_ptr<BinOp> BinOp_ptr_;
    BinOp(BinOp_ptr_ left, Token op, BinOp_ptr_ right);
    ~BinOp();

public:
    BinOp_ptr_ left;
    Token op;
    BinOp_ptr_ right;
};

typedef BinOp::BinOp_ptr_ BinOp_ptr;


