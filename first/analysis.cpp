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

// �ؼ��� write read if else is less_than goto set mod add writeln
// ���� ����
// ����
// ע�� "//"
void Analysis()
{
    if (g_strScript.empty())
    {
        std::cout << "script is empty" << std::endl;
        return;
    }

    std::string strTemp = ""; // �����ʱ�ַ���
    for (size_t i=0; i<g_strScript.size(); ++i)
    {
        if (   (g_strScript[i] >= 'a' && g_strScript[i] <= 'z') 
            || (g_strScript[i] >= 'A' && g_strScript[i] <= 'Z') ) // ��ĸ
        {
            strTemp.push_back(g_strScript[i]);
            std::cout << "��ĸ��" << g_strScript[i] << std::endl;
        }
        else if (g_strScript[i] == ' ') // �ո�
        {
            if (strTemp == "write")
            {
                std::cout << &g_strScript[i++] << std::endl;
                int nNum;
                std::cin >> nNum;
                std::cout << nNum << std::endl;
                return ;
            }
            std::cout << "�ո�" << g_strScript[i] << std::endl;
        }
        else if (g_strScript[i] == '"') // ����
        {
            std::cout << "���ţ�" << g_strScript[i] << std::endl;
        }
        else
        {
            std::cout << "δ֪��" << (int)g_strScript[i] << std::endl;
        }
    }


}

void AnalysisCalc()
{
    while (true)
    {
        cout << "������:" << endl;
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
                cout << "�ո�" << endl;
            }
        }

        if (op == NUL)
        {
            cerr << "OP Ϊ NUL" << endl;
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
                    cerr << "nRight����Ϊ0" << endl;
                else
                    nResult = nLeft / nRight;
            }
            cout << "�������Ϊ: " << strCalc << "=" << nResult << endl;
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