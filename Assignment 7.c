#include<stdio.h>
void main() {
    int x,y,n;
    printf("Enter the size of the traingle:");
    scanf("%d",&n);


    for(x=1;x<=n;x++) {
        for(y=1;y<=x;y++) {
            printf("*");
        }


        printf("\n");
    }
    for(x=1;x<n;x++) {
        for(y=n;y>x;y--) {
            printf("*");
        }


        printf("\n");
    }




getchar();
}