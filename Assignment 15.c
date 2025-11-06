#include <stdio.h>
#include <string.h>
#define SIZE 5
struct Staff{
int staff_id;
char name[50];
 int days;
float salary;
};
float calculate_salary(int days) {
    float basic = days *2500;
    if (days> 25 ){
        int extra_days = days -25;
        float bonus = extra_days* 2500* 0.10;
        return basic + bonus;
    }
   return  basic;
    }
int main(){
struct Staff employees[SIZE];
int i, j;
for (i = 0; i < SIZE; i++) {
    employees[i].staff_id = 101 + i;
    printf("Enter employee %d's name:" , i + 1);
    scanf("%s", &employees[i].name);
    printf("Enter worked days of %s: ", employees[i].name);
    scanf("%d", &employees[i].days);
    employees[i].salary = calculate_salary(employees[i].days);
}
struct Staff temp;
for (i = 0; i < SIZE -1; i++) {
    for ( j = 0; j < SIZE- i -1; j++ ) {
        if (employees[j].salary < employees[j + 1].salary){
            temp = employees[j];
        employees[j] = employees[j + 1];
        employees[j + 1] = temp;
    }
}
}

printf("\n%10s %15s %10s %10s\n","Staff ID"," Name"," Days", "Salary");
printf("-----------------------------------------\n");
for (i = 0; i < SIZE; i++){
    printf("%-10d %-15s %-10d %-10.2f\n",employees[i].staff_id, employees[i].name, employees[i].days, employees[i].salary);

    }
int search_id;
printf("\nenter staff ID to search:" );
scanf("%d", &search_id);
int found = 0;
for (i = 0; i < SIZE; i++) {
    if (employees[i].staff_id == search_id){
        printf("\nEmployee found: \n");
    printf("Staff ID : %d\n", employees[i].staff_id);
    printf("Name: %s\n", employees[i].name);
    printf("Days: %d\n", employees[i].days);
    printf("Salary: %.2f\n", employees[i].salary);
    found = 1;
    break;
}
}
if (!found){
    printf("No employee found with Staff ID %d\n", search_id);
}
return 0;
}

