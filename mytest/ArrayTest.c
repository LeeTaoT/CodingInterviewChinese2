#include <stdio.h>


void test8()
{
    int numbers[] = { 1, 2, 3, 4 , 5};
    int length = sizeof(numbers)/ sizeof(int);
    for(int i = 0 ; i < length ; ++i)
    {
        printf( " number[numbers[%d]] = %d\n" ,  i, numbers[numbers[i]]);
    }
}

/*测试用例*/

int main()
{
   test8();
 
 /*
 **number[numbers[0]] = 2
 **number[numbers[1]] = 3
 **number[numbers[2]] = 4
 **number[numbers[3]] = 5
 **number[numbers[4]] = 0
 **/
}
