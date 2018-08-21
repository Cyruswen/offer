#include <iostream>
#include <iostream>
using namespace std;
//剑指offer面试题1
#if 0
class mystring
{
public:
    mystring(char* m_pData = NULL);
    mystring(const mystring& str);
    ~mystring(void);

    //方案一
    //  mystring& operator=(const mystring& s)
    //  {
    //      if (this == &s)
    //      {
    //          return *this;
    //      }
    //      if (m_pData)
    //      {
    //          delete[] m_pData;
    //          m_pData = NULL;
    //      }
    //      m_pData = new char[strlen(s.m_pData) + 1];
    //      strcpy(m_pData, s.m_pData);
    //      return *this;
    //  }

    //方案二
    //  mystring& operator=(const mystring& s)
    //  {
    //      if (this != &s)
    //      {
    //          mystring tmpstring(s.m_pData);
    //          char* tmpstr = tmpstring.m_pData;
    //          tmpstring.m_pData = m_pData;
    //          m_pData = tmpstr;
    //      }
    //      return *this;
    //  }
private:
    char* m_pData;
};
#endif

//面试题2 实现单例模式(singleton)
class Singleton
{
public:
private:
    Singleton();
    Singleton(const Singleton& sg);

};
