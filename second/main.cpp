#include "stdafx.h"
#include "Token.h"
#include "Interpreter.h"

using namespace std;

int main(){

    while (true) {
        cout << "input:";

        string str;
        getline(cin, str); // 会有空格之类的,用这个获取输入

        Parser parser(str);
        Interpreter interpreter(parser);
        cout << "result:" << interpreter.interpret() << endl;
    }

    getchar();
    return 0;
}