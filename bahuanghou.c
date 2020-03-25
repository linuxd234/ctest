#include <stdio.h>
/*
*求序列关键：固定一列扫描该列所有可能行，找到一符合行时递归求下一个皇后的位置
*递归终止条件是列到达9，此时输出序列
*回溯时机在调用递归后，把当前列的行位置清空，继续for扫描下一可能满足条件的行
*回溯后对行check仅受之前列信息-皇后位置的影响，从后向前搜索全部可能
*check逻辑简单
*/
int location[8] = {0};
//int isUsed[8][8] = {0};
int total = 0;
int main()
{
    int getQueue(int);

    getQueue(0);//调用求八皇后的方法
    printf("total:%d", total);

    return 0;
}

int getQueue(int lie)
{
    int check(int, int);//声明check函数
    if (lie <= 7)//递归进行
    {
        for (int hang = 0; hang < 8; hang++) //hang，固定了列扫描行
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
    else //递归结束条件，已到达不存在的第九列
    {
        for (int i = 0; i < 8; i++)//打印序列
        {
            printf("%d  ", location[i]);
        }
        total++;//总数+1
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