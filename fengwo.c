#include <stdio.h>
#include "stack.c"
/*
*蜜蜂趴窝问题，求出总可能数与路径，蜜蜂只能向右爬行即路径只能有小向大
*采用递归，与某地正向相邻的只有n+1、n+2，先找到去相邻的路线，再递归地求相邻再去它相邻的路线
*递归终止条件是n+1/n+2是目的地
*利用栈记录路径，最后到目的地时逆序遍历栈
*访问节点开始就入栈，出栈时机两种：1.递归结束前在末尾出栈（弹出当前路点）2.递归返回后紧跟着出栈（弹出下一个路点）
*/
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
    push(&stack, star);//将本次路径入栈
    if (star + 1 != end && star + 2 != end) //非直连
    {
        int a = routeSum(star + 1, end);//n+1点去目标的路数目
        pop(&stack);//将下次（star+1）路径出栈，此时栈顶为本次路点
        int b = routeSum(star + 2, end);//n+2点去目标的路数目
        pop(&stack);
        return a + b;
    }
    else if (star + 1 == end) //直连&递归终止case1：紧挨着如1-2、4-5
    {
        //printf("%d\n", end);
        push(&stack, end); //push、pop一对操作
        traverseReverse(stack);//逆序遍历栈
        pop(&stack);//弹出的是end，并非本节点，因此递归返回后还要再弹一次--->27行
        printf("\n");
        return 1;
    }
    else //直连&递归终止case2，包含两条路径：隔着一个数如1-3（123、13）、4-6（456、46）
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