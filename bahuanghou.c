#include <stdio.h>
int location[8] = {0};
//int isUsed[8][8] = {0};
int total = 0;
int main()
{
    int getQueue(int);

    getQueue(0);
    printf("total:%d", total);

    return 0;
}

int getQueue(int lie)
{
    int check(int, int);
    if (lie <= 7)
    {
        for (int hang = 0; hang < 8; hang++) //hang
        {
            if (check(hang, lie))
            {
                //isUsed[hang][lie] = 1;
                //扫描方向从低下标到高下标所以不用check是否已使用过
                //肯定都没使用过，只有能不能使用的区别
                location[lie] = hang;
                getQueue(lie + 1); //递归
                //isUsed[hang][lie] = 0;
                location[lie] = 0; //回溯复原
            }
        }
    }
    else //递归结束条件lie=8
    {
        for (int i = 0; i < 8; i++)
        {
            printf("%d  ", location[i]);
        }
        total++;
        printf("\n");
    }
    return 0;
}

int check(int hang, int lie) //因为是列序依次进行的，一定不同列。只检测行、对角线。
{
    for (int i = 0; i < lie; i++)
    {
        if ((hang == location[i]) || (location[i] - i == hang - lie) || (i + location[i] == lie + hang))
            return 0;
    }

    return 1;
}