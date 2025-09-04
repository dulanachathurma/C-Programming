#include<stdio.h>
void main(){
int a,b,c,d,e,f;
printf("------Salary Calculator------\n\n\n");
printf("Enter the number of worked days : ");
scanf("%d",&a);
printf("Enter the daily payment : ");
scanf("%d",&b);
c=a*b;
d=c*25/100;
e=c*8/100;
f=c+d-e;
printf("\n\nTotal payment: %d",c);
printf("\nBonus: %d",d);
printf("\nETF: %d",e);
printf("\nNet Salary: %d",f);
getchar();
}