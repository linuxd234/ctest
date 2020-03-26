#include <stdio.h>
/**
 * 输入一个整形数组，统计该数组内0-9数字的个数
*/
int count[10] = {0}; //全部初化为零
int main()
{
    int input[64] = {0}; //必须初始化，变量不初始化内容随机
    int charSum(int);
    printf("请输入int数组，以0结束以enter、空格、tab作为分隔。\n");
    //printf("�������飡\n");
    int num;
    int i = 0;
    scanf("%d", &num);
    while (num != 0)
    {
        input[i] = num;
        scanf("%d", &num);
        i++;
    }
    printf("\n--------------------------------------------\n");
    int j = 0;
    while (input[j] != 0)
    {
        int temp = input[j];
        while (temp != 0)
        {
            int c = temp % 10; //获得末尾数
            charSum(c);
            temp = temp / 10; //截取前一位
        }
        j++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (count[i] != 0)
        {
            printf("%d:%d;\n", i, count[i]);
        }
    }

    return 0;
}

int charSum(int c) //传入分解后的一位0-9数字，进行统计
{
    switch (c)
    {
    case 0:
        count[0]++;
        break;

    case 1:
        count[1]++;
        break;
    case 2:
        count[2]++;
        break;
    case 3:
        count[3]++;
        break;
    case 4:
        count[4]++;
        break;
    case 5:
        count[5]++;
        break;
    case 6:
        count[6]++;
        break;
    case 7:
        count[7]++;
        break;
    case 8:
        count[8]++;
        break;
    case 9:
        count[9]++;
        break;
    }
    return 0;
}