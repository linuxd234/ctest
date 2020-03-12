#include <stdio.h>
#include "string.h"
int tag = 0;
int main()
{
    int recuresive(char *, int, int);
    int recuresive2(char *, int, int);
    char array[100];
    printf("input a string with enter as the end:\n");
    //scanf("%s",array);
    gets(array);

    int len = getStringLen(array); //c标准库string.h中有类似函数strlen()
    //printf("%d",len);
    recuresive(array, 0, len);
    printf("\n--------------------------------------\n");
    recuresive2(array, 0, len);

    return 0;
}
int recuresive(char *array, int star, int length)
{
    if (star >= 0 && star < length)
    {
        printf("%c", array[star]);
        if (star >= length - 1)
            tag = 1;
        if (tag == 0)
        {
            recuresive(array, star + 1, length);
        }
        else if (tag == 1)
        {
            recuresive(array, star - 1, length);
        }
    }
    return 0;
}

int recuresive2(char *array, int star, int length)//另一种用数学方法
{
    if (star >= 0 && star <= 2 * (length - 1))
    {
        if (star <= length - 1)
            printf("%c", array[star]);
        else
            printf("%c", array[2 * (length - 1) - star]);

        recuresive2(array, star + 1, length);
    }
    return 0;
}