#include<stdio.h>
#include<stdbool.h>
 int factorCount (int n){
int count=0,x;

for (x=1;x<=n;x++){
    if(n%x==0){
        count++;
}
}
       return count;
        }

        int main(){
        int n;
        printf("Enter a number: ");
        scanf ("%d", &n);
        printf ("Number of factors:%d", factorCount(n));

     return 0;
}
