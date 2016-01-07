#include "stdafx.h"
#include "Token.h"
#include "Interpreter.h"

using namespace std;

int main(){

    while (true) {
        cout << "input:";

        string str;
        getline(cin, str); // ���пո�֮���,�������ȡ����

        Parser parser(str);
        Interpreter interpreter(parser);
        cout << "result:" << interpreter.interpret() << endl;
    }

    getchar();
    return 0;
}