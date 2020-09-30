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
    printf("%f--%f--%f\n",.12,12.,.0);//.12、21.都是合法小数，单独一个.不行
    printf("###################1\n");
    void show(int);
    void (*pf)();
    pf=show;
    //*pf(11);必须加括号
    pf(12);//ok
    (*pf)(12);//ok
    printf("###################2\n");
    double a=12.345;
    printf("double is :%2f\n",a);//缺省小数精度只有域宽会如何--撑破域宽
    printf("###################3\n");
    char *s={"aaaaaa"};//这种写法也对
    printf("%s\n",s);
    printf("###################4\n");
    float f;
    printf("in put a float:");//测试输入域宽
    //scanf("%3.3f",&f);得到的结果全零
    scanf("%3f",&f);//只会控制整数，小数部分全零（只截取整数部分小数当作下一个输入）
    printf("float is:%f\n",f);
    printf("###################5\n");
    int _int;
    float ust$;
    ust$=10;//合法
    int aa,*pp=&aa;//合法
    int *ip;
    //scanf("%d",ip);//不合法
    //printf("%d\n next:",*ip);
    scanf("%d",pp);
    printf("%f,%d\n",ust$,aa);//上一步的小数会移到aa里
    printf("###################6\n");
    return 0;
}
void show(int a){
    printf("%d\n",a);
}
