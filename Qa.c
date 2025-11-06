#include <stdio.h>
struct student{
    char name[50];
    int number;
    float marks;
    char grade;
};
char getgrade(float marks) {
    if(marks>=75) {
     return 'A';
    }
    else if(marks>=65) {
        return 'B';
    }
    else if(marks>=55) {
        return 'C';
    }
    else if(marks>=45) {
        return 'D';
    }
    else{
        return 'F';
    }
}
int main(){
    FILE *in,*out;
struct student s;
in=fopen("Input.txt","r");
out=fopen("Output.txt","w");

if(in==NULL || out==NULL){
printf("Error\n");
}
    fprintf(out,"Results\n");
    fprintf(out,"-----------------\n");
while(fscanf(in,"%[^\n],%d,%f",s.name,&s.number,&s.marks)!=EOF){
    s.grade=getgrade(s.marks);
fprintf(out,"Name=%s\n",s.name);
fprintf(out,"Number=%d\n",s.number);
fprintf(out,"Grade=%c\n",s.grade);
fprintf(out,"-----------------\n");
}
fclose(in);
fclose(out);
printf("Done\n");
return 0;

}


