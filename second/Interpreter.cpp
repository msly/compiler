#include "stdafx.h"
#include "Interpreter.h"
#include "Token.h"

using namespace std;

Interpreter::Interpreter(Lexer le)
    : lexer(le)
    , current_token(Token::TYPE::END, 0)
{
    // get current_token
    current_token = lexer.get_next_token();
}


Interpreter::~Interpreter()
{
}

/************************************************************************/
/* Parser / Interpreter code                                            */
/************************************************************************/

void Interpreter::eat(Token::TYPE type)
{
    if (current_token.type == type) {
        current_token = lexer.get_next_token();
    } else {
        cout << "eat error" << endl;
    }
}

int Interpreter::factor() {
    Token token = current_token;

    if (token.type == Token::TYPE::INTEGER) {
        eat(Token::TYPE::INTEGER);
        return token.value;
    } else if (token.type == Token::TYPE::LPAREN) {
        eat(Token::TYPE::LPAREN);

        int ret = expr();

        eat(Token::TYPE::RPAREN);
        return ret;
    } 
    cout << "factor error" << endl;
    return 0;
}

int Interpreter::term() {

    int result = factor();

    while (current_token.type == Token::TYPE::MUL
        || current_token.type == Token::TYPE::DIV) {

        Token token = current_token;
        if (token.type == Token::TYPE::MUL) {
            eat(Token::TYPE::MUL);
            result = result * factor();
        } else if (token.type == Token::TYPE::DIV) {
            eat(Token::TYPE::DIV);
            result = result / factor();
        }
    }

    return result;
}

/*
expr:term((PLUS|MINUS)term)*
term:factor((MUL|DIV)factor)*
factor:INTEGER
*/
int Interpreter::expr() {

    int result = term();

    while (current_token.type == Token::TYPE::PLUS
        || current_token.type == Token::TYPE::MINUS) {

        Token op = current_token;
        if (op.type == Token::TYPE::PLUS) {
            eat(Token::TYPE::PLUS);
            result = result + term();
        } else if (op.type == Token::TYPE::MINUS) {
            eat(Token::TYPE::MINUS);
            result = result - term();
        }
    }

    return result;
}
