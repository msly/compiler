#ifndef TOOLS_H_20120624
#define TOOLS_H_20120624

#pragma once

#include <string>
#include <vector>
#include <windows.h>

std::wstring AnsiToUnicode(const char* buf)
{
    int len = ::MultiByteToWideChar(CP_ACP, 0, buf, -1, NULL, 0);
    if (len == 0) return L"";

    std::vector<wchar_t> unicode(len);
    ::MultiByteToWideChar(CP_ACP, 0, buf, -1, &unicode[0], len);

    return &unicode[0];
}

std::string UnicodeToAnsi(const wchar_t* buf)
{
    int len = ::WideCharToMultiByte(CP_ACP, 0, buf, -1, NULL, 0, NULL, NULL);
    if (len == 0) return "";

    std::vector<char> utf8(len);
    ::WideCharToMultiByte(CP_ACP, 0, buf, -1, &utf8[0], len, NULL, NULL);

    return &utf8[0];
}

std::wstring Utf8ToUnicode(const char* buf)
{
    int len = ::MultiByteToWideChar(CP_UTF8, 0, buf, -1, NULL, 0);
    if (len == 0) return L"";

    std::vector<wchar_t> unicode(len);
    ::MultiByteToWideChar(CP_UTF8, 0, buf, -1, &unicode[0], len);

    return &unicode[0];
}

std::string UnicodeToUtf8(const wchar_t* buf)
{
    int len = ::WideCharToMultiByte(CP_UTF8, 0, buf, -1, NULL, 0, NULL, NULL);
    if (len == 0) return "";

    std::vector<char> utf8(len);
    ::WideCharToMultiByte(CP_UTF8, 0, buf, -1, &utf8[0], len, NULL, NULL);

    return &utf8[0];
}


typedef unsigned char BYTE;

inline BYTE toHex(const BYTE &x)
{
    return x > 9 ? x + 55: x + 48;
}

std::string urlEncoding( std::string &sIn )
{
    std::string sOut;
    for( std::string::size_type ix = 0; ix < sIn.size(); ix++ )
    {
        BYTE buf[4];
        memset( buf, 0, 4 );
        if( isalnum( (BYTE)sIn[ix] ) )
        {
            buf[0] = sIn[ix];
        }
        else if ( isspace( (BYTE)sIn[ix] ) )
        {
            buf[0] = '+';
        }
        else
        {
            buf[0] = '%';
            buf[1] = toHex( (BYTE)sIn[ix] >> 4 );
            buf[2] = toHex( (BYTE)sIn[ix] % 16);
        }
        sOut += (char *)buf;
    }
    return sOut;
}

#endif /*#ifndef TOOLS_H_20120624*/
