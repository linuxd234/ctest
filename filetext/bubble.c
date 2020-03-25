void sortInt(int *array,int nub){//asc
    for (int i = 0; i < nub-1; i++)//times
    {
        for (int j = 0; j < nub-i-1; j++)
        {
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        
    }
    
}