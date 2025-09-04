
#include<stdio.h>

void sortArray(int arr[], int size){
    int temp;
for(int i=0;i<size-1;i++) {
    for(int j=0;j<size-1-i;j++) {
        if(arr[j]>arr[j+1]) {
            temp=arr[j];
            arr[j]=arr[j+1];
          arr[j+1]=temp;
        }

    }
}
}
int main(){
    int value;
    printf("\nHow many values are there:");
    scanf("%d",&value);
    int num[value];
    for(int i=0;i<value;i++){
        printf("Enter the number %d:\t",i+1);
        scanf("%d",&num[i]);
    }
    sortArray(num,value);
    printf("Values in ascending order:\n");
    for(int i=0;i<value;i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
    float median;
    if(value%2==0) {
        median=(num[value/2-1]+num[value/2])/2;
    }
        else {
            median=num[value/2];
        }




        printf("\n\nThe median is %.2f",median);



    return 0;
}