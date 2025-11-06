#include <stdio.h>
int main() {
char name[5][50];
   int age[5];
    int i;


    for(i=0;i<5;i++) {

        printf("Enter the name:");
            scanf("%s",&name[i]);
            printf("Enter the age:");
            scanf("%d",&age[i]);
            printf("\n");
        }
        printf("\n");

    printf("\nName\t\t\t\tAge\n");
    printf("\n---------------------------------------\n\n");
    for( i=0;i<5;i++) {
        printf("%-20s %d years\n", name[i], age[i]);
        }
    int maxage = age[0],minage= age[0];
    int maxindex=0 ,minindex=0;

    for(i=1;i<5;i++) {
        if(maxage<age[i]) {
            maxage=age[i];
            maxindex=i;

        }
        else if(minage>age[i]) {
            minage=age[i];
            minindex=i;
        }
    }
    printf("\nOldest person:%s (%dyears)\n",name[maxindex],maxage);
    printf("\nYoungest person:%s (%dyears)\n",name[minindex],minage);

    return 0;
}
