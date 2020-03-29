#include<stdio.h>
/**
 * 模板以及遇到的一些小问题证明
*/
int main()
{
    printf("%d\n",0%5);
    char c[2]={'a','b'};
    char *p;
    p=c;
    printf("%d---%d\n",sizeof(c),sizeof(char));//c是含有两个字符的数组大小为2
    printf("%d---%d\n",sizeof(p),sizeof(*p));//p是指针大小为8c
    printf("%f--%f--%f",.12,12.,.0);//.12、21.都是合法小数，单独一个.不行
    return 0;
}
