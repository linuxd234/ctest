#include <stdio.h>
/**求全排列
 *思路1：接近人手算思路的，递归+for（star，len，栈）+栈（存已查路径）
 *思路2：基于交换的：1.对首位与后边依次交换（第一次不交换即第一次进入for）2.后位（star+1）重复1的工作 
 *3.直到没有可交换时返回 4.返回后要把递归之前交换的换回来
 *如1234---1243---1324---1342--1432--1423....
*/
int main()
{
    int swap(char *, char *);
    int pailie(int, int, char *);
    char a[] = {'1', '2', '3', '4'};
    pailie(0, 4, a);
    return 0;
}

int swap(char *fir, char *sec)
{ //此处的交换是实参交换
    char temp = *fir;
    *fir = *sec;
    *sec = temp;
    return 0;
}

int pailie(int star, int len, char *array)
{ //当前位置，总长，排列序列
    for (int i = star; i < len; i++)
    { //当前位置与后位依次交换
        if (star != i)
        {                                  //第一次与自己不交换（第二次以后的for才能进入）
            swap(&array[star], &array[i]); //与star+1、+2.....+len-1元素进行交换
            pailie(star + 1, len, array);  //后续元素重复本过程，递归
            swap(&array[star], &array[i]); //换回来，回溯
        }
        else //第一次的for进入，第一次与自己不交换
        {
            if (star != len - 1)
            { //不到最后
                pailie(star + 1, len, array);
            }
            else //到最后输出序列，递归终止与star==len-1即无可与交换的后续
            {
                printf("%s\n", array);
                //对于star==末尾（len-1）的一定只有一次进入for的机会，并且此时正应该输出本次排好序的队列
            }
        }
    }
    return 0;
}
