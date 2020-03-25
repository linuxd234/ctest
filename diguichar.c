#include <stdio.h>
#include "string.h"
/*
*递归镜像输出字符串，如输入abcdef-----输出abcdefedcba
*/
int tag = 0;
int main()
{
    int recursive(char *, int, int);
    int recursive2(char *, int, int);
    char array[100];
    printf("input a string with enter as the end:\n");
    //scanf("%s",array);
    gets(array);

    int len = getStringLen(array); //c标准库string.h中有类似函数strlen()
    //printf("%d",len);
    recursive(array, 0, len);
    printf("\n--------------------------------------\n");
    recursive2(array, 0, len);

    return 0;
}
int recursive(char *array, int star, int length)//采用标志位的方法
{
    if (star >= 0 && star < length)//在数组下标合法范围内
    {
        printf("%c", array[star]);//先打印
        if (star >= length - 1)//到达尾部折回去的标志
            tag = 1;
        if (tag == 0)//正向
        {
            recursive(array, star + 1, length);//入口1
        }
        else if (tag == 1)//反向-镜像
        {
            recursive(array, star - 1, length);//入口2
        }
    }
    return 0;
}

int recursive2(char *array, int star, int length)//另一种用数学方法
{
    if (star >= 0 && star <= 2 * (length - 1))//2倍长度
    {
        if (star <= length - 1)//在正向的范围内
            printf("%c", array[star]);
        else//在反向的范围内
            printf("%c", array[2 * (length - 1) - star]);

        recursive2(array, star + 1, length);//仅仅一个递归入口
    }
    return 0;
}