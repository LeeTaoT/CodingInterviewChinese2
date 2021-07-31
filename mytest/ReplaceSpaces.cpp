#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

//==================================使用cpp 自带的string 重写

string &ReplaceBlank(string& str)
{
    if ( str.empty() )
    {
        return str; 
    }
    /*先算出有多少空格*/
    int numberofBlank = 0;
    for(auto c : str)
    {
        if ( c == ' ')
        {
            numberofBlank++;
        }
    }

    auto newlength = str.size() + numberofBlank * 2;
    string::size_type originalsize = str.size();
     
    //重新分配str的大小
    try
    {
        /* code */
        str.resize(str.size() + numberofBlank * 2 , ' ');
    }
    catch(const bad_alloc& exc)
    {
        cout << "size is ok ,throw bad_alloc" << endl; 

    }
    catch(const length_error& exc)
    {
        cout << "oversize max_size length"<< endl;

    }

    int OrginalIndex = originalsize - 1 ;
    int NewIndex = str.size() -1;

   
    while((OrginalIndex >= 0 )&&( NewIndex > OrginalIndex ))  
    {
        if( ' ' == str[OrginalIndex] )
        {
            str[NewIndex--] = '0';
            str[NewIndex--] = '2';
            str[NewIndex--] = '%'; 
        }
        else
        {
            str[NewIndex--] = str[OrginalIndex--];
        }
        /* code */
    }
    
    return str;
}


int main()
{
    string str;
    cout << "please input a string to deal with :";
    if( getline(cin,str) )
    {
        cout << "Original size :" << str.size() << endl;
        (void)ReplaceBlank(str);
    }
    cout << "after replace blank : " << str << endl;
    cout << "New size : " << str.size() << endl;

    
}
