#include "stdafx.h"
#include "Interpreter.h"
#include "Token.h"

using namespace std;

Interpreter::Interpreter(std::string text) 
    : input_text(text)
    , pos(0)
    , current_token(Token::TYPE::END, 0)
{
    current_char = input_text[pos];
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
    if (op.type == Token::TYPE::PLUS)
        eat(Token::TYPE::PLUS);
    else
        eat(Token::TYPE::MINUS);

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
    while (current_char != '\0') {

        if (isspace(current_char))
            skip_space();

        if (isdigit(current_char)) {
            return Token(Token::TYPE::INTEGER, integer());
        }

        // plus
        if (current_char == '+') {
            advance();
            return Token(Token::TYPE::PLUS, '+');
        }

        // minus
        if (current_char == '-') {
            advance();
            return Token(Token::TYPE::MINUS, '-');
        }

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

    return Token(Token::TYPE::END, 0);

}

void Interpreter::skip_space() {
    while (current_char != '\0' && isspace(current_char))
        advance();
}

void Interpreter::advance() {

    ++pos;

    if (pos > input_text.length() - 1) {
        current_char = '\0';
    } else {
        current_char = input_text[pos];
    }
    
}

int Interpreter::integer() {
    string str;
    while (current_char != '\0' && isdigit(current_char)) {
        str.push_back(current_char);
        advance();
    }

    return stoi(str);
}


