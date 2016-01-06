#include "stdafx.h"
#include "Lexer.h"

using namespace std;


Lexer::Lexer(string text) 
    : input_text(text)
    , pos(0) 
{
    current_char = input_text[pos];
}


Lexer::~Lexer() {
}

/************************************************************************/
/* Lexer code                                                           */
/************************************************************************/
Token Lexer::get_next_token() {
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

void Lexer::skip_space() {
    while (current_char != '\0' && isspace(current_char))
        advance();
}

void Lexer::advance() {

    ++pos;

    if (pos > input_text.length() - 1) {
        current_char = '\0';
    } else {
        current_char = input_text[pos];
    }

}

int Lexer::integer() {
    string str;
    while (current_char != '\0' && isdigit(current_char)) {
        str.push_back(current_char);
        advance();
    }

    return stoi(str);
}
