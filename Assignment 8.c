#include <stdio.h>
int main(){
int i,minrange,maxrange;


int code[5];
int price[5];

for(i=0;i<5;i++){
printf("\nEnter the Item code:");
scanf("%d",&code[i]);

printf("Enter the price:");
scanf("%d",&price[i]);
}
printf("\nItem code\t\tPrice");
printf("\n-------------------\n");
for(i=0;i<5;i++){
printf("%d\t \t%d\n",code[i],price[i]);
}
printf("\nEnter a price range to find items (ex: 150-250): ");
scanf("%d-%d",&minrange,&maxrange);
printf("\nSerch Results\n");
    printf("\nItem code\t\tPrice");
    printf("\n-------------------\n");
for(i=0;i<5;i++){
if(price[i]>=minrange && price[i]<=maxrange){
printf("%d\t \t%d\n",code[i],price[i]);
}
}
if(price[i]<minrange && price[i]>maxrange){
printf("Not Found");
}
return 0;
}
