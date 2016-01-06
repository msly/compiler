#include "stdafx.h"
#include "Token.h"
#include "Interpreter.h"

using namespace std;

int main(){

    while (true) {
        cout << "input:";

        string str;
        getline(cin, str); // 会有空格之类的,用这个获取输入

        Interpreter interpreter = Interpreter(str);
        cout << "result:" << interpreter.expr() << endl;
    }
    


    getchar();
    return 0;
}