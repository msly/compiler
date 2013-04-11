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

// ¹Ø¼ü×Ö write read if else is less_than goto set mod add writeln
// ·ûºÅ £º¡°
// ±äÁ¿
// ×¢ÊÍ "//"
void Analysis()
{
    if (g_strScript.empty())
    {
        std::cout << "script is empty" << std::endl;
        return;
    }

    std::string strTemp = ""; // ´æ·ÅÁÙÊ±×Ö·û´®
    for (size_t i=0; i<g_strScript.size(); ++i)
    {
        if (   (g_strScript[i] >= 'a' && g_strScript[i] <= 'z') 
            || (g_strScript[i] >= 'A' && g_strScript[i] <= 'Z') ) // ×ÖÄ¸
        {
            strTemp.push_back(g_strScript[i]);
            std::cout << "×ÖÄ¸£º" << g_strScript[i] << std::endl;
        }
        else if (g_strScript[i] == ' ') // ¿Õ¸ñ
        {
            if (strTemp == "write")
            {
                
            }
            std::cout << "¿Õ¸ñ£º" << g_strScript[i] << std::endl;
        }
        else if (g_strScript[i] == '"') // ÒýºÅ
        {
            std::cout << "ÒýºÅ£º" << g_strScript[i] << std::endl;
        }
        else
        {
            std::cout << "Î´Öª£º" << (int)g_strScript[i] << std::endl;
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