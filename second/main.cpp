#include "stdafx.h"
#include "Token.h"
#include "Interpreter.h"

using namespace std;

int main(){

    while (true) {
        cout << "input:";

        string str;
        getline(cin, str); // ���пո�֮���,�������ȡ����

        Interpreter interpreter = Interpreter(str);
        cout << "result:" << interpreter.expr() << endl;
    }
    


    getchar();
    return 0;
}