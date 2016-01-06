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

/************************************************************************/
/* Parser / Interpreter code                                            */
/************************************************************************/

void Interpreter::eat(Token::TYPE type)
{
    if (current_token.type == type) {
        current_token = get_next_token();
    } else {
        cout << "eat error" << endl;
    }
}

int Interpreter::factor() {
    Token token = current_token;
    eat(Token::TYPE::INTEGER);
    return token.value;
}

int Interpreter::expr() {

    current_token = get_next_token();

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

int Interpreter::term() {

    Token token = current_token;
    eat(Token::TYPE::INTEGER);
    return token.value;
}

// int Interpreter::expr()
// {
//     current_token = get_next_token();
// 
//     int result = term();
// 
//     while (current_token.type == Token::TYPE::PLUS 
//         || current_token.type == Token::TYPE::MINUS) {
// 
//         Token op = current_token;
//         if (op.type == Token::TYPE::PLUS) {
//             eat(Token::TYPE::PLUS);
//             result = result + term();
//         } else if (op.type == Token::TYPE::MINUS) {
//             eat(Token::TYPE::MINUS);
//             result = result - term();
//         }
//     }
// 
//     return result;
// }

/************************************************************************/
/* Lexer code                                                           */
/************************************************************************/
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

        // minus
        if (current_char == '*') {
            advance();
            return Token(Token::TYPE::MUL, '*');
        }

        // minus
        if (current_char == '/') {
            advance();
            return Token(Token::TYPE::DIV, '/');
        }

    }

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





