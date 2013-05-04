#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

std::string g_strScript;

bool ReadFile()
{
    std::ifstream fin(".\\custom script2.txt");
    if (!fin.good())
        return false;

    std::ostringstream os;
    os << fin.rdbuf();
    g_strScript = os.str();
    return true;
}

// 关键字 write read if else is less_than goto set mod add writeln
// 符号 ：“
// 变量
// 注释 "//"
void Analysis()
{
    if (g_strScript.empty())
    {
        std::cout << "script is empty" << std::endl;
        return;
    }

    std::string strTemp = ""; // 存放临时字符串
    for (size_t i=0; i<g_strScript.size(); ++i)
    {
        if (   (g_strScript[i] >= 'a' && g_strScript[i] <= 'z') 
            || (g_strScript[i] >= 'A' && g_strScript[i] <= 'Z') ) // 字母
        {
            strTemp.push_back(g_strScript[i]);
            std::cout << "字母：" << g_strScript[i] << std::endl;
        }
        else if (g_strScript[i] == ' ') // 空格
        {
            if (strTemp == "write")
            {
                std::cout << &g_strScript[i++] << std::endl;
                int nNum;
                std::cin >> nNum;
                std::cout << nNum << std::endl;
                return ;
            }
            std::cout << "空格：" << g_strScript[i] << std::endl;
        }
        else if (g_strScript[i] == '"') // 引号
        {
            std::cout << "引号：" << g_strScript[i] << std::endl;
        }
        else
        {
            std::cout << "未知：" << (int)g_strScript[i] << std::endl;
        }
    }


}

void AnalysisCalc()
{
    while (true)
    {
        cout << "请输入:" << endl;
        string strCalc;
        getline(cin, strCalc);
        //cin >> strCalc;

        int nLeft = 0, nRight = 0, nResult = 0;   
        enum OP{NUL,ADD,SUB,MUL,DIV};
        OP op = NUL;
        bool bLeft = false;
        for (int i=0; i<strCalc.size(); ++i)
        {
            cout << strCalc[i] << endl;
            if (strCalc[i] >= '0' && strCalc[i] <= '9')
            {
                if (!bLeft)
                {
                    nLeft = nLeft * 10 + strCalc[i] - '0';
                }
                else
                {
                    nRight = nRight * 10 + strCalc[i] - '0';
                }
            }
            else if (strCalc[i] == '+')
            {
                bLeft = true;
                op = ADD;
            }
            else if (strCalc[i] == '-')
            {
                bLeft = true;
                op = SUB;
            }
            else if (strCalc[i] == '*')
            {
                bLeft = true;
                op = MUL;
            }
            else if (strCalc[i] == '/')
            {
                bLeft = true;
                op = DIV;
            }
            else if (strCalc[i] == ' ')
            {
                cout << "空格" << endl;
            }
        }

        if (op == NUL)
        {
            cerr << "OP 为 NUL" << endl;
            return ;
        }
        else
        {
            if (op == ADD)
                nResult = nLeft + nRight;
            else if (op == SUB)
                nResult = nLeft - nRight;
            else if (op == MUL)
                nResult = nLeft * nRight;
            else if (op == DIV)
            {
                if (nRight == 0)
                    cerr << "nRight不能为0" << endl;
                else
                    nResult = nLeft / nRight;
            }
            cout << "你输入的为: " << strCalc << "=" << nResult << endl;
        }
    }
    
}


int main(int argc, char* argv[])
{
    //if (!ReadFile())
    //{
    //    std::cout << "read file failure" << std::endl;
    //    return EXIT_FAILURE;
    //}

    //Analysis();

    AnalysisCalc();

    return 0;
}