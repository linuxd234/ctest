#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int **array = NULL;
    printf("input the number n:\n");
    scanf("%d", &n);

    //定义动态数组
    array = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(sizeof(int) * n);
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
    int num = 1; //1-n
    for (int i = 1; i <= n; i++)
    {
        int increment = 2 * i - 1; //对角线镜像元素增量
        for (int j = 0; j < i; j++)
        {
            array[i - j - 1][n - j - 1] = num + increment; //先给镜像赋值
            array[n - j - 1][i - j - 1] = num++;           //最后一行时会覆盖前条
            increment = increment - 2;
            //printf("yyy---");
        }
        num = num + i;
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