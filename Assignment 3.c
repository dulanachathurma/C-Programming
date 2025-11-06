#include<stdio.h>
void main(){
int days,payment,Total,Bonus,Netsalary;
printf("Enter the number of work days: ");
scanf("%d",&days);
    printf("Enter the number of payments: ");
    scanf("%d",&payment);
if(days<=0){
printf("Invalid Number");
}

else if(payment<=0){
printf("Invalid amount");
}
else if(days>20){
Bonus=(days-20)*1500;
Total=(days*payment);
Netsalary=Total+Bonus;
printf("Total payment = %d",Total);
printf("\nBonus = %d",Bonus);
printf("\nNet salary = %d",Netsalary);

}
else{
Bonus=0;
    Total=(days*payment);
    Netsalary=Total+Bonus;
    printf("Total payment = %d",Total);
    printf("\nBonus = %d",Bonus);
    printf("\nNet salary = %d",Netsalary);
}
getchar();
}


