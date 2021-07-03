#include <iostream>

int gatDuplication(const int * numbers, int length)
{
    if((numbers == nullptr) || length <= 0 )
        return -1;

    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        /* code */
        int middle = ((end - start) >> 1)  + start;
        int cout = countRange(numbers, length, start , middle);
        if(end == start)
        {
            if(cout > 1)
            {
                return start;
            }
            else
            {
                break;
            }
        }
        if(cout > (middle - start + 1))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
    
    
}
int countRange(const int * numbers, int length, int start , int end)
{
    if(numbers == nullptr)
        return 0;

    int count = 0;
    for (int i = 0; i < length ; i++)
    {
        if(numbers[i] >= start && numbers[i] <= end)
        {
            ++count;
        }
    }
    return count;
    
}