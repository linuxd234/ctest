#include <stdio.h>
#include "stack.c"

intStack20 stack = {{0}, -1}; //init
int main()
{
    int routeSum(int, int);
    int star, end;

    printf("input start and end with \'-\' to split:\n");
    scanf("%d-%d", &star, &end);
    printf("the route total:%d", routeSum(star, end));
    return 0;
}

int routeSum(int star, int end)
{
    //printf("%d  ", star);
    push(&stack, star);
    if (star + 1 != end && star + 2 != end) //非直连
    {
        int a = routeSum(star + 1, end);
        pop(&stack);
        int b = routeSum(star + 2, end);
        pop(&stack);
        return a + b;
    }
    else if (star + 1 == end) //直连&递归终止case1
    {
        //printf("%d\n", end);
        push(&stack, end); //push、pop一对操作
        traverseReverse(stack);
        pop(&stack);
        printf("\n");
        return 1;
    }
    else //直连&递归终止case2，包含两条路径
    {
        //printf("%d\n", end);
        push(&stack, end);
        traverseReverse(stack);
        pop(&stack);
        printf("\n");
        int a = routeSum(star + 1, end);
        pop(&stack);
        return 1 + a;
    }

    // else//第二种思路
    // {
    //     printf("%d  %d\n",star+1,end);
    //     printf("%d\n",end);
    //     return 2;
    // }
}