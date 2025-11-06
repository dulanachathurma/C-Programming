#include <stdio.h>
void main(){
int n,x,c;
printf("Enter a number: ");
scanf("%d",&n);
x=1;
c=0;
if(n<0){
printf("\nPlease enter a positive number");
}

else if(n>0){
    printf("Factors ");
while(x<=n){
if(n%x==0){
    printf("%d ",x);
    c++;
}
x++;
}
printf("\nFactors count:%d",c);
if(c>2){
printf("\n\nComposite number");
}
    else if(n==0 || n==1){
        printf("\n\nNeither prime or composite number");
    }
else{
printf("\n\nPrime number");
}
}

getchar();
}
