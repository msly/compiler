#include "stdafx.h"
#include "BinOp.h"

BinOp::BinOp(BinOp_ptr_ left, Token op, BinOp_ptr_ right)
    : left(left)
    , op(op)
    , right(right)
{

}


BinOp::~BinOp() {
}
