#include "stdafx.h"
#include "Interpreter.h"

using namespace std;

Interpreter::Interpreter(Parser parser)
    : parser(parser)
{
}

Interpreter::~Interpreter()
{
}

int Interpreter::interpret() {
    BinOp_ptr tree = parser.expr();
    return visit(tree);
}

int Interpreter::visit(BinOp_ptr tree) {
    if (tree->op.type == Token::TYPE::PLUS) {

        return visit(tree->left) + visit(tree->right);

    } else if (tree->op.type == Token::TYPE::MINUS) {

        return visit(tree->left) - visit(tree->right);

    } else if (tree->op.type == Token::TYPE::MUL) {

        return visit(tree->left) * visit(tree->right);

    } else if (tree->op.type == Token::TYPE::DIV) {

        return visit(tree->left) / visit(tree->right);

    } else if (tree->op.type == Token::TYPE::INTEGER) {

        return tree->op.value;

    }
    cout << "error visit" << endl;
    return 0;
}

