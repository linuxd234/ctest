#include <stdio.h>
/**
 * 狼进兔子洞问题
 * 总共有n个洞口，狼逆时针每m个一进洞：如n=6 m=2 123456洞口中2、4、6是安全的
 * 输入测试数组，判断数组中是否存在安全洞口
*/
typedef struct dongkou
{
    int dong;      //洞口名称
    int isVisited; //是否访问过，为了在查找安全洞口过程中结束不必要的循环
    struct dongkou *next;
} dongNode; //洞口节点

int main()
{
    int testSecure(int *, int, int, dongNode *);
    int n, m;
    dongNode *p;                       //洞口节点指针
    dongNode dongList = {-1, 0, NULL}; //headNode
    p = &dongList;

    printf("输入总共有几个洞口n:");
    //printf("�����붴����n:"); //gb2312
    scanf("%d", &n);
    printf("输入狼隔几个洞口进入m:");
    //printf("������ÿ��������m:"); //gb2312
    scanf("%d", &m);

    //以下为测试用例
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
    }                    //根据输入的n来生成洞口链表，并初始化
    p->next = &dongList; //循环链表

    testSecure(t1, 3, m, &dongList);
    testSecure(t2, 3, m, &dongList);
    testSecure(t3, 3, m, &dongList);
    return 0;
}

int testSecure(int *testArray, int arraylen, int jiange, dongNode *dongList)
{ //传入的测试数组、长度、间隔（m）、洞口链表
    for (int i = 0; i < arraylen; i++)
    {
        dongNode *tempNode = dongList; //临时指针指向洞口列表的头节点
        while (!tempNode->isVisited)
        {
            tempNode->isVisited = 1;            //没有访问的设置为访问过
            if (testArray[i] == tempNode->dong) //测试数组中有能与安全洞口匹配的
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