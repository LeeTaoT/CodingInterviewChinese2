#ifndef ASSIGMENTOPERATOR_H
#define ASSIGMENTOPERATOR_H

#include <cstring>
#include <new>

class CMyString{

public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    /*自定义一个赋值运算符*/
    CMyString & operator=( const CMyString&);

private:
    char *m_pData; //指向字符串数组
};

/* 初级版本: 问题在于当new 分配失败后原对象也被销毁，无法保证异常安全
** 1. 入参应是常量引用
** 2. 返回类型为该类型的引用
** 3. 先释放源对象的内存空间，防止内存泄露
** 4. 应返回*this 
** 5. 考虑复制运算符两侧是否 为同一对象
*/
CMyString&  CMyString::operator=(const CMyString& str)
{

    /*先判断是否为同一对象*/
    if(this == &str)
    {
        return *this;
    }

    /*先释放原本指向的对象*/
    delete [] m_pData;

    m_pData = nullptr ;//删除之后将指针初始化空

    /*在堆上重新分配内存*/
   // m_pData = new string(*(str.m_pData)); x
   m_pData = new char[std::strlen(str.m_pData) + 1];

   std::strcpy(m_pData, str.m_pData);

   return *this;

}

/*
** 异常安全版
*/
CMyString&  CMyString::operator=(const CMyString& str)
{

    if (this == &str)
    {
        return *this;
    }
    //改变new的方式，如果分配失败，返回一个空指针 
    char *strTmp = new (std::nothrow) char[std::strlen(str.m_pData) + 1];

    if(nullptr != strTmp)
    {
        // 分配成功时才将原字符串释放
        delete [] m_pData;

        // 将指针指向分配的新内存
        m_pData = strTmp;

        // Tmp 指针不再需要，离开作用域时，被自动销毁,分配的内存区域由m_pData管理 ?
        strTmp = nullptr; 

        std::strcpy(m_pData, str.m_pData);
    }

    return *this;
    

}

/*
** 书中提供的正式版本,创建一个临时实例，将其交换
** 提供其配套的构造函数 与 析构函数
*/
CMyString&  CMyString::operator=(const CMyString& str)
{
   if ( this != &str)
   {
        CMyString strTmp(str);    // 调用构造函数进行内存分配

        /* 如下的写法是错误的，Tmp 使用str初始化，
        * strTmp在离开if作用域时会调用其析构函数从而错误的将str释放
        * m_pData指向的值也成为无效值       
        * *********************************
        * strTmp.m_pData = str.m_pData;
        * m_pData = strTmp.m_pData;
        * 
        */
      char *pTmp = strTmp.m_pData; // 保存构造函数分配的内存空间
      strTmp.m_pData = m_pData;  // 离开if时自动调用析构函数将内存销毁
      m_pData = pTmp; 

   }

   return *this; 

}


CMyString::CMyString(const CMyString& str)
{
    int length = std::strlen(str.m_pData);
    m_pData = new char[length + 1];
    std::strcpy(m_pData, str.m_pData);

}

CMyString::~CMyString()
{
    delete [] m_pData;
}

#endif
