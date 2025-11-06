#include <stdio.h>
void main(){
int month, date;
printf("Enter the number of month and days: ");
scanf("%d %d", &month, &date);
if(month >= 1 && month <= 12) {
   printf("valid month");
}
else{
   printf(" \nInvalid month");
}
 if(month == 2)
   {
   if(date>=1 && date <= 28){
      printf("  \nvalid date");
   }
   else{
      printf(" \nInvalid date");
   }
}
   else if(month ==1 ||month ==3  ||month ==5 ||month ==7 ||month ==8 ||month ==10 ||month ==12)
      {
      if(date>=1 && date <= 31){
         printf(" \nvalid date");
      }
      else{
         printf(" \nInvalid date");
      }
      }
      else if(month ==4 ||month ==6 ||month ==9 ||month ==11 ) {
         if(date>=1 && date <= 30){
            printf(" \nvalid date");
         }
         else{
            printf(" \nInvalid date");
         }
      }
getchar();
}