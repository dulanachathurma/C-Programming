#include <stdio.h>
int main() {
    int rows, cols;
    int rowsum=0, colsum=0,Total=0;

    printf("Enter the size of the planting grid(Ex: 4*5):");
    scanf("%d*%d", &rows,&cols);
    printf("\n");


    int array[50][50];
    int i,j;

 for(i=0;i<rows;i++) {
     for(j=0;j<cols;j++) {
    printf("Enter the numbers of arrays in row %d column %d slot:",i+1,j+1);
         scanf("%d",&array[i][j]);
     }

 }
 printf("\n---------------------------------------\n\n");
         for( i=0;i<rows;i++) {
             rowsum=0;
         for( j=0;j<cols;j++) {
             printf("%4d\t",array[i][j]);
             rowsum+=array[i][j];
             Total+=array[i][j];
         }
       printf("(%d)\n",rowsum);

         }
    for( j=0;j<cols;j++) {
        colsum=0;
        for( i=0;i<rows;i++) {
            colsum+=array[i][j];
        }
        printf("( %d)\t",colsum);

    }

    printf("(%d)\n",Total);


    printf("\n\n---------------------------------------");


return 0;
}