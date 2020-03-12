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