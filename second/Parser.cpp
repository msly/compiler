#include "stdafx.h"
#include "Parser.h"

using namespace std;

Parser::Parser(Lexer le)
    : lexer(le)
    , current_token(Token::TYPE::END, 0) 
{
    // get current_token
    current_token = lexer.get_next_token();
}


Parser::~Parser() {
}

/************************************************************************/
/* Parser / Interpreter code                                            */
/************************************************************************/

void Parser::eat(Token::TYPE type) {
    if (current_token.type == type) {
        current_token = lexer.get_next_token();
    } else {
        cout << "eat error" << endl;
    }
}

BinOp_ptr Parser::factor() {
    Token token = current_token;

    if (token.type == Token::TYPE::INTEGER) {
        eat(Token::TYPE::INTEGER);
        return make_shared<BinOp>(nullptr, token, nullptr);
    } else if (token.type == Token::TYPE::LPAREN) {
        eat(Token::TYPE::LPAREN);

        BinOp_ptr ret = expr();

        eat(Token::TYPE::RPAREN);
        return ret;
    }
    cout << "factor error" << endl;
    return 0;
}

BinOp_ptr Parser::term() {

    BinOp_ptr result = factor();

    while (current_token.type == Token::TYPE::MUL
        || current_token.type == Token::TYPE::DIV) {

        Token op = current_token;
        if (op.type == Token::TYPE::MUL) {
            eat(Token::TYPE::MUL);
        } else if (op.type == Token::TYPE::DIV) {
            eat(Token::TYPE::DIV);
        }

        result = make_shared<BinOp>(result, op, term());
    }

    return result;
}

BinOp_ptr Parser::expr() {

    BinOp_ptr result = term();

    while (current_token.type == Token::TYPE::PLUS
        || current_token.type == Token::TYPE::MINUS) {

        Token op = current_token;
        if (op.type == Token::TYPE::PLUS) {
            eat(Token::TYPE::PLUS);
        } else if (op.type == Token::TYPE::MINUS) {
            eat(Token::TYPE::MINUS);
        }

        result = make_shared<BinOp>(result, op, term());
    }

    return result;
}
