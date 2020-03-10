/*求全排列
 *2020/3/9
 *linuxd234
*/
#include<stdio.h>
int main(){
    int swap(char *,char *);
    int pailie(int,int,char *);
    char a[]={'1','2','3','4'};
    pailie(0,4,a);
    return 0;
}

int swap(char *fir,char *sec){
        char temp=*fir;
        *fir=*sec;
        *sec=temp;
        return 0;
    }

int pailie(int star,int len,char *array){
    for( int i=star;i<len;i++){
        if(star!=i){
            swap(&array[star],&array[i]);
            if(star!=len-1){
                pailie(star+1,len,array);
            }else
            {
                printf("%s\n",array);
            }
            swap(&array[star],&array[i]);
        }else
        {
            if(star!=len-1){
                pailie(star+1,len,array);
            }else
            {
                printf("%s\n",array);
            }
        }
        
    }
    return 0;
}
