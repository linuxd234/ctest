#include <stdio.h>
#include <stdlib.h>
/**
 * 螺旋输出矩阵，如 n=4时
 * 16   10  5   2
 * 9    15  11  6
 * 4    8   14  12
 * 1    3   7   13
*/
int main()
{
    int n;
    int **array = NULL; //指向指针的指针，可以用来引用二维数组，但意义有区别
    printf("input the number n:\n");
    scanf("%d", &n);

    //定义动态数组
    array = (int **)calloc(n, sizeof(int *)); //申请元素为n个一维指针数组
    for (int i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(sizeof(int) * n); //为一维指针素组元素申请空间
    }
    //动态数组初始化
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = 0;
        }
    }

    //主体
    int num = 1;                 //1-n
    for (int i = 1; i <= n; i++) //总共要进行的回数
    {
        int increment = 2 * i - 1;  //对角线镜像元素增量
        for (int j = 0; j < i; j++) //每回要赋值的元素个数，第一次1对第二次2对
        {
            array[i - j - 1][n - j - 1] = num + increment; //先给镜像赋值
            array[n - j - 1][i - j - 1] = num++;           //最后一行时会覆盖前条
            increment = increment - 2;                     //镜像增量变化5-3-2-1....
            //有种固定镜像增量的方法即变动镜像下标：主（i，i-1）-->镜像（n-i，n-i+1）外层每次for的increment固定
        }
        num = num + i; //1...3...7
    }
    //打印
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    //free
    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}