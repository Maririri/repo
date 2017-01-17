#include <string.h>
#include <string>
#include <iostream>

#include "MyString.h"

using namespace std;

namespace myStl
{
    MyString::MyString(const char* p)
    {
        m_pStr = new char[strlen(p)+1];
        strcpy(m_pStr,p);
    }

    MyString::MyString(const MyString & other)
    {
        m_pStr = new char[strlen(other.m_pStr)+1];
        strcpy(m_pStr,other.m_pStr);
    }

    MyString::MyString(MyString && other)  {
        m_pStr = other.m_pStr;
        other.m_pStr=nullptr;
    }

    MyString &MyString::operator=(const MyString & other)
    {
        if (this != &other)  {
            delete[] m_pStr;
            m_pStr = new char[strlen(other.m_pStr)+1];
            strcpy(m_pStr,other.m_pStr);
        }

        return *this;
    }

    MyString &MyString::operator=(MyString && other)
    {
        delete[] m_pStr;
        m_pStr = other.m_pStr;

        other.m_pStr=nullptr;
        return *this;
    }


    ostream& operator<< ( ostream& os, const MyString & s)
    {
        os << s.m_pStr;
        return os;
    }

    std::ostream& operator<< ( std::ostream& os, const MyCircle& c)
    {
        os << "Circle: x=" << c.x << " y=" << c.y <<" r="<<c.r<<endl;
        return os;
    }
}
