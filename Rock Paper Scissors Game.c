#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
 int userchoice,compchoice;

srand(time(0));

printf("Rock Paper Scissor Game\n ");
printf("1=Rock,2=Paper,3=Scissor\n ");
 printf("Enter your choice: ");
 scanf("%d",&userchoice);

if(userchoice <1 || userchoice >3){
printf("Invalid Choice\n");
return 0;
}
compchoice = (rand() % 3) + 1;

printf("You chose:%d\n ",userchoice);
printf("Computer chose:%d\n ",compchoice);

if(compchoice == userchoice){
printf("Try again\n ");
}
else if((userchoice ==1 && compchoice==2)||(userchoice ==2 && compchoice==3)||(userchoice ==3 && compchoice==1)){
printf("You win!\n ");
}
else{
printf("Computer Win\n ");
}
return 0;
}



