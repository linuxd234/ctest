#include <stdio.h>
#include <stdlib.h>
#include "bubble.c"
int main()
{
    void sortInt(int *, int);
    int tempArr[1024] = {0};
    int count = 0;
    FILE *fp=fopen("F:\\ctest\\filetext\\number.txt","r+");
    //FILE *fp = fopen("number.txt", "r+");//r+会覆盖最后一个数据，a+不会具体体现本例上是多输出一个空行
    if (fp == NULL)
    {
        printf("open error!\n");
        exit(0);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d\n", &tempArr[count]);
            //int nub;
            // fscanf(fp,"%d",&nub);//\r\n
            // printf("%d\n",nub);
            count++;
        }
        sortInt(tempArr, count);

        for (int i = 0; i < count; i++)
        {
            fprintf(fp, "%d\n", tempArr[i]);
            printf("%d  ", tempArr[i]);
        }

        fclose(fp);
    }
    return 0;
}