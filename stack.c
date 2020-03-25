/*
*顺序栈工具文件
 */
typedef struct sqIntStack20
{
    int stack20[20];
    int top;
} intStack20;

//初始化留给main程序完成，结构体变量在定义后无法整体赋值（只有在初始化时可以）
// int sqStackInit(intStack20 *sta){
//     *sta={{0},-1};
//     return 0;
// }

int traverse(intStack20 sta) //遍历方法
{
    while (sta.top != -1)
    {
        printf("%d  ", sta.stack20[sta.top--]);
    }
    return 0;
}

int traverseReverse(intStack20 sta) //逆序遍历栈方法
{
    for (int i = 0; i <= sta.top; i++)
    {
        printf("%d  ", sta.stack20[i]);
    }
    return 0;
}

int pop(intStack20 *sta)
{
    int re = sta->stack20[sta->top--];
    return re;
}

int push(intStack20 *sta, int in)
{
    sta->stack20[++sta->top] = in;
    return 0;
}