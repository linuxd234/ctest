#include <stdio.h>
/**
 * 汉诺塔问题
*/
int main()
{
    void hanoi(int, int, int, int);
    int n = 0; //汉诺塔的层数
    printf("input hanoi counts:");
    scanf("%d", &n);
    hanoi(1, 3, 2, n); //将n个塔从1移到3

    return 0;
}

void hanoi(int star, int end, int use, int counts)
{ //把塔从star借助use移动到end
    if (counts > 0)
    {
        if (counts != 1)
        {
            hanoi(star, use, end, counts - 1); //将最后一层以上的塔借助第三个柱子（end）移动到第二个柱子上（use）
            printf("%d----->%d\n", star, end); //将最后一个塔移到目的地
            hanoi(use, end, star, counts - 1); //将第借用（use）的柱子上剩余的塔通过star移动到end
        }
        else //如果只有一个汉诺塔直接把它从star移动到end（递归终止）
        {
            printf("%d----->%d\n", star, end);
        }
    }
    else
    {
        printf("error in counts!\n");
    }
}
