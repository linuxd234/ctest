/**
 * 求字符串长，有类似的库函数<string.h>--strlen()不包含'\0'
*/
int getStringLen(char *array){
    char *c=array;
    int len=0;
    while (*c!='\0')
    {
        len++;
        c=c+1;
    }
    return len;
}