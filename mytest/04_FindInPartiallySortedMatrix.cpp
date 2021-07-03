
/**
 * 面试题4: 二维数组中查找
 * 
 */
 
#include <cstdio>
#include <iostream>
using std::cout ; using std::cin; using std::endl;

/**
 * 自己编写: 二分法查找: 错误
 * 比如如下数组数字10一定找不到
 * 
 */
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
/
bool Find(int matrix[][4] , int rows, int colums, int number)
{
    //检查入参有效性

    if( (matrix == nullptr) || (rows <= 0) || (colums <= 0))
        return  false;

    //因为数组向右，向下依次增大，最小值在矩阵的左上方,最大值在矩阵右下方
    if( number <  matrix[0][0] || number > matrix[rows -1 ] [colums -1])
        return  false;

    //对应colums
    int iLeftPos    =  0;
    int iRightPos   =  colums -1;

    // 对应row
    int iTopPos     =  0;
    int iButtomPos  =  rows - 1;  
    int bColumStart = true;
    int bRowsStart  = true ;


    /*以右上角的值作为比较起点，使用二分法进行查找*/
    while ( ( true == bColumStart ) || 
            ( true == bRowsStart )  )
    {
        /* code */
        if((number < matrix[iTopPos][iRightPos]) && 
           (true == bColumStart ))
        {
            if((number == matrix[iTopPos][iLeftPos]) || number == matrix[iTopPos][iRightPos])
            {
                return true;
            }

            int middle = (iLeftPos + iRightPos) >> 1;
            if( number < matrix[iTopPos][middle] )
            {
                iRightPos = middle;
            }
            else if(number > matrix[iTopPos][middle])
            {
                if( iLeftPos == middle)
                {
                    if(false == bRowsStart )
                    {
                        if(number == matrix[iTopPos + 1][middle])
                        {
                            return true;
                        }
                    }
                    bColumStart = false;  // 列二分已经结束
                }
                iLeftPos  = middle;
            }
            else
            {
                return true;
            }
        }
        else if( (number > matrix[iTopPos][iRightPos]) &&
                 ( true == bRowsStart ))
        {
            if(number == matrix[iTopPos][iRightPos] || number == matrix[iButtomPos][iRightPos])
            {
                return true;
            }
            int middle = (iTopPos + iButtomPos) >> 1;
            if ( number > matrix[middle][iRightPos])
            {
                /* code */
                if(iTopPos == middle )
                {
                    //以
                    if( false == bColumStart)
                    {
                        if( number == matrix[middle + 1][iRightPos] ||
                            number == matrix[middle + 1][iRightPos - 1])
                        {
                            return true;
                        }
                    }
                    bRowsStart = false;     // 行二分结束
                }
                iTopPos = middle;
            }
            else if(number < matrix[middle][iRightPos])
            {
                iButtomPos = middle;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if( (true == bRowsStart )&& (true == bRowsStart))
            {
                return true;
            }    
            else
            {
                return false;
            }
                
        } 
    }

    return false;

}



void Test()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int number = 0;
    cout << "Please input a number need to find : "  << endl;
    if(cin >> number)
    {
       cout << "start find " << number << endl;
       cout << ((true == Find(matrix , 4 , 4 , number)) ? "find number": "can't find" )
            << endl;
    }
    
}
int main()
{
    Test() ;
    return 0;
}