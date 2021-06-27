#include <cstdio>

#include <iostream>
using std::cin; 
using std::cout; 
using std::endl;

#include <map>
using std::map;

#include <string>
using std::string;

/*参照原理，自己写出的版本
** 
*/
bool duplicate(int numbers[], int length , int *duplication)
{
    /*输入有效性检查*/
    if( numbers == nullptr || length  <= 0)
        return false;
    
    int i = 0 ;
    while (  i < length)
    {
        /* 如果第i 个元素 不在第i 个位置上*/
        if(numbers[i] != i)
        {
            /*如果第i位置的元素,与 第number[i] 位置上的元素不相等*/
            if(numbers[i] != numbers[numbers[i]])
            {
                /*交换元素，将number[i]放在第number[i]的位置上*/
                int tmp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = tmp;
            }
            else
            {
                /*如果i位置上的元素与,第number[i]位置上的元素相等，找到了重复元素*/
                *duplication = numbers[i];
                return true;
            }
        }
        else
        {
            /* 第i 个元素处在第i个位置上,遍历下一个*/
            i++;

        }
    }
    return false;

}

bool duplicateContainer(int numbers[], int length, map<int,size_t> & duplication)
{
    /*输入有效性检查*/
    if( numbers == nullptr || length  <= 0)
        return false;
    
    int i = 0 ;
    while (  i < length)
    {
        /* 如果第i 个元素 不在第i 个位置上*/
        if(numbers[i] != i)
        {
            /*如果第i位置的元素,与 第number[i] 位置上的元素不相等*/
            if(numbers[i] != numbers[numbers[i]])
            {
                /*交换元素，将number[i]放在第number[i]的位置上*/
                int tmp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = tmp;
            }
            else
            {
                /*如果i位置上的元素与,第number[i]位置上的元素相等，找到了重复元素*/
                /*将重复元素放到关联容器中并计数,进行下一次循环*/
                ++duplication[numbers[i]];
                i++;
            }
        }
        else
        {
            /* 第i 个元素处在第i个位置上,遍历下一个*/
            i++;

        }
    }

    return true;

}


/* 参考版:
** 参数: numbers : 整数数组
**      length  : 数组长度
**      duplication : (输出) 数组中的一个重复数字
**
** 返回值 :
**          true     - 输入有效，并且数组中存在重复的数字
**          false    - 输入无效，或者数组中不存在重复的数字 
*/
bool duplacate2(int numbers[], int length, int * duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;
    
    for(int i = 0; i < length ; ++i)
    {
        while (numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }

            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
        
    }

    return false;

}


bool contains(int array[], int length, int number)
{
    for (int i = 0; i < length ; ++i)
    {
        if (array[i] == number)
        {
            return true;
        }
        
    }
    return false;
    
}




void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}




void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4};
    int duplications[] = { 1 };
    test( "Test1", numbers, sizeof(numbers)/sizeof(int), duplications,sizeof(duplications)/sizeof(int),true);

}
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4};
    int duplications[] = { 4 };
    test( "Test2", numbers, sizeof(numbers)/sizeof(int), duplications,sizeof(duplications)/sizeof(int),true);

}

void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}



void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4};
    int duplications[] = { -1 };
    test( "Test4", numbers, sizeof(numbers)/sizeof(int), duplications,sizeof(duplications)/sizeof(int),false);

}


void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4}; //? 为什么没有段错误
    int duplications[] = { -1 };
    test( "Test5", numbers, sizeof(numbers)/sizeof(int), duplications,sizeof(duplications)/sizeof(int),false);

}


void test6()
{
    int *numbers = nullptr; 
    int duplications[] = { -1 };
    test( "Test6", numbers,0, duplications,sizeof(duplications)/sizeof(int),false);

}
void PrintMapContainer(map<int, size_t> & mapContainer)
{

    if(true ==  mapContainer.empty())
    {
        cout << "no Duplication " << endl;
        return ;
    }
    for(const auto &Con : mapContainer)
    {
        cout << Con.first << " occurs " << (Con.second + 1) 
             << ( (Con.second  + 1 > 1) ? " times" : " time") << endl;
    }
}
void test7()
{
    int number1[] = { 2, 1, 3, 1, 4};
    int number2[] = { 2, 4, 3, 1, 4};
    int number3[] = { 2, 4, 2, 1, 4};
    int number4[] = { 2, 1, 3, 0, 4};
    int number5[] = { 2, 1, 3, 5, 4};
    int number6[] = { 2, 1, 3, 1, 4};
    map<int, size_t> MapDuplication;

    cout <<  "Test7 : "  <<  endl;

    cout <<  "number1 : " << endl;
    duplicateContainer(number1,sizeof(number1)/sizeof(int), MapDuplication);
    PrintMapContainer(MapDuplication) ;
    MapDuplication.clear();
    
    cout <<  "number2 : " << endl;
    duplicateContainer(number2,sizeof(number2)/sizeof(int), MapDuplication);
    PrintMapContainer(MapDuplication) ;
    MapDuplication.clear();

    cout <<  "number3 : " << endl;
    duplicateContainer(number3,sizeof(number3)/sizeof(int), MapDuplication);
    PrintMapContainer(MapDuplication) ;
    MapDuplication.clear();

    cout <<  "number4 : " << endl;
    duplicateContainer(number4,sizeof(number4)/sizeof(int), MapDuplication);
    PrintMapContainer(MapDuplication) ;
    MapDuplication.clear();

    cout <<  "number5 : " << endl;
    duplicateContainer(number5,sizeof(number5)/sizeof(int), MapDuplication);
    PrintMapContainer(MapDuplication) ;
    MapDuplication.clear();

    cout <<  "number6 : " << endl;
    duplicateContainer(number6,sizeof(number6)/sizeof(int), MapDuplication);
    PrintMapContainer(MapDuplication) ;
    MapDuplication.clear();


    

}

void test8()
{
    int numbers[] = { 1, 2, 3, 4};
    int length = sizeof(numbers)/ sizeof(int);
    for(int i = 0 ; i < length ; i++)
    {
        printf( " number[numbers[%d]] = %d\n" ,  i, numbers[numbers[i]]);
    }
}

/*测试用例*/

int main()
{
   // test1();
   // test2();
   // test3();
   // test4();
   // test5();
   // test6();
   // test7();
   test8();
}
