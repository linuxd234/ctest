typedef struct sqIntStack20
{
    int stack20[20];
    int top;
} intStack20;

//初始化留给main程序完成
// int sqStackInit(intStack20 *sta){
//     *sta={{0},-1};
//     return 0;
// }

int traverse(intStack20 sta)
{
    while (sta.top != -1)
    {
        printf("%d  ", sta.stack20[sta.top--]);
    }
    return 0;
}

int traverseReverse(intStack20 sta)
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