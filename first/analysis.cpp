#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


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


int main(int argc, char* argv[])
{
    if (!ReadFile())
    {
        std::cout << "read file failure" << std::endl;
        return EXIT_FAILURE;
    }

    Analysis();

    return 0;
}