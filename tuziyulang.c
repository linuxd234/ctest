#include <stdio.h>
typedef struct dongkou
{
    int dong;
    int isVisited;
    struct dongkou *next;
} dongNode;

int main()
{
    int testSecure(int *, int, int, dongNode *);
    int n, m;
    dongNode *p;                       //洞口节点指针
    dongNode dongList = {-1, 0, NULL}; //headNode
    p = &dongList;

    printf("输入总共有几�?洞口n:");
    //printf("�����붴����n:"); //gb2312
    scanf("%d", &n);
    printf("输入狼隔几个洞口进入m:");
    //printf("������ÿ��������m:"); //gb2312
    scanf("%d", &m);
    int t1[3] = {1, 2, 3};
    int t2[3] = {0, 1, 2};
    int t3[3] = {1, 3, 5};

    for (int i = 0; i < n; i++)
    {
        dongNode *dongnode = (dongNode *)malloc(sizeof(dongNode));
        dongnode->dong = i;
        dongnode->isVisited = 0;
        p->next = dongnode;
        p = p->next;
    }                    //生成洞口链表
    p->next = &dongList; //循环链表

    testSecure(t1, 3, m, &dongList);
    testSecure(t2, 3, m, &dongList);
    testSecure(t3, 3, m, &dongList);
    return 0;
}

int testSecure(int *testArray, int arraylen, int jiange, dongNode *dongList)
{
    for (int i = 0; i < arraylen; i++)
    {
        dongNode *tempNode = dongList; //临时指针指向洞口列表的头节点
        while (!tempNode->isVisited)
        {
            tempNode->isVisited = 1;
            if (testArray[i] == tempNode->dong)
            {
                printf("存在安全洞口！");
                //printf("���ڰ�ȫ���ڣ�\n");//gb2312
                return 1;
            }
            for (int j = 0; j < jiange; j++) //每m个访问一次
            {
                tempNode = tempNode->next;
            }
        }
    }
    printf("不存在安全洞口！");
    //printf("�����ڰ�ȫ���ڣ�\n");//gb2312
    return 0;
}