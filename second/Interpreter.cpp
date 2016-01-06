#include "stdafx.h"
#include "Interpreter.h"
#include "Token.h"

using namespace std;

Interpreter::Interpreter(std::string text) 
    : input_text(text)
    , pos(0)
    , current_token(Token::TYPE::END, 0)
{
}


Interpreter::~Interpreter()
{
}

void Interpreter::eat(Token::TYPE type)
{
    if (current_token.type == type) {
        current_token = get_next_token();
    } else {
        cout << "eat error" << endl;
    }
}

// ·µ»Ø½á¹û
int Interpreter::expr()
{
    current_token = get_next_token();

    Token left = current_token;
    eat(Token::TYPE::INTEGER);

    Token op = current_token;
    eat(Token::TYPE::PLUS);

    Token right = current_token;
    eat(Token::TYPE::INTEGER);

    if (op.value == '+') {
        return left.value + right.value;
    } else {
        return left.value - right.value;
    }
}

Token Interpreter::get_next_token()
{
    if (pos > input_text.length() - 1){
        return Token(Token::TYPE::END, 0);
    }

    char current_char = input_text[pos];

    while (isspace(current_char)) {
        ++pos;

        if (pos > input_text.length() - 1) {
            return Token(Token::TYPE::END, 0);
        }

        current_char = input_text[pos];
    }

    // digit
    int value = 0;
    while (isdigit(current_char)) {
        value = value * 10 + atoi(&current_char);

        ++pos;
        current_char = input_text[pos];
    }
    if (value != 0)
        return Token(Token::TYPE::INTEGER, value);

    
    // plus
    if (current_char == '+' || current_char == '-') {
        ++pos;
        return Token(Token::TYPE::PLUS, current_char);
    } 


    cout << "get_next_token error" << endl;
    return Token(Token::TYPE::END, 0);

}


