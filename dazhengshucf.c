#include <stdio.h>
#include <math.h>
/*
*简单实现大整数乘法
*2020/9/30 create by linuxd
*/
int dataNum(long long d)
{
    // 返回一个整数有几位
    int i = 0;
    while (d)
    {
        i++;
        d = d / 10;
    }
    return i;
}

long long dazhengshucfa(long long x, long long y)
{
    //输出两个乘数x、y
    int dataNum(long long);
    int x_num = dataNum(x);
    int y_num = dataNum(y);
    //获取x，y的数字位数

    int n = (x_num > y_num ? x_num : y_num);
    //当x，y位数不同时以大的为准（按大的划分）
    // printf("%d\n",n);
    if (n == 1 || n == 0) //递归终止条件
    {
        return x * y;
    }
    else
    {
        long long a = x / (long long)pow(10, n / 2);
        long long b = x % (long long)pow(10, n / 2);
        //用10的n/2次方划分x为a、b两部分
        long long c = y / (long long)pow(10, n / 2);
        long long d = y % (long long)pow(10, n / 2);
        //用10的n/2次方划分y为c、d两部分
        long long ac = dazhengshucfa(a, c);
        long long bd = dazhengshucfa(b, d);

        long long s = ac * (long long)pow(10, (n / 2) * 2) +
                      (dazhengshucfa(a - b, d - c) + ac + bd) * (long long)pow(10, n / 2) + bd;
        // 将n除2再乘以2是为了防止类似n=3，n/2=1是按1位进行划分的（除以10划分），最后ac要乘的是10的(n / 2) * 2=2次方而不是n=3次方
        return s;
    }
}

int main()
{
    //case 1：
    long long x1 = 1234, y1 = 5678;
    long long x2 = 1212, y2 = 1199;
    //case 2：
    long long x3 = 1212111, y3 = 1199;
    long long x4 = 121122, y4 = 111999;
    //case 3：
    long long x5 = 1, y5 = 111999;
    long long x6 = 0, y6 = 111999;
    //  long long x7 = 121, y7 = 111;
    //  long long x8 = 210, y8 = 999;
    //  long long x9 = -89, y9 = 888;

    long long z1 = dazhengshucfa(x1, y1);
    long long z2 = dazhengshucfa(x2, y2);
    long long z3 = dazhengshucfa(x3, y3);
    long long z4 = dazhengshucfa(x4, y4);
    long long z5 = dazhengshucfa(x5, y5);
    long long z6 = dazhengshucfa(x6, y6);
    // long long z7 = dazhengshucfa(x7, y7);
    // long long z8 = dazhengshucfa(x8, y8);
    // long long z9 = dazhengshucfa(x9, y9);
    printf("case 1:######################################\n");
    printf("z1:%lld\n", z1);
    printf("z2:%lld\n", z2);
    printf("case 2:######################################\n");
    printf("z3:%lld\n", z3);
    printf("z4:%lld\n", z4);
    printf("case 3:######################################\n");
    printf("z5:%lld\n", z5);
    printf("z6:%lld\n", z6);
    // printf("z7:%lld\n", z7);
    // printf("z8:%lld\n", z8);
    // printf("z9:%lld\n", z9);
    printf("######################################\n");
    printf("size of long long :%d\n", sizeof(long long));
    printf("size of long :%d\n", sizeof(long));

    return 0;
}
