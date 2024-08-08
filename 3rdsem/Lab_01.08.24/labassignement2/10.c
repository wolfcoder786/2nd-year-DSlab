/*Wap to create a structure Employee which has three data-members emp.id,name, and doj
where doj is an object of the structure Date(nested structure).*/
#include<stdio.h>
#include<string.h>
typedef struct Date
{
    int day ;
    int month ;
    int year ;

}Date;
typedef struct Employee
{
    int id ;
    char name[30];
    Date doj;
}emp ;
void display(emp e){
    printf("Employee_id:%d\n",e.id);
    printf("Name:%s\n",e.name);
    printf("Date_of_joining:%d/%d/%d\n",e.doj.day,e.doj.month,e.doj.year);

}


int main(){
    emp e1;
    printf("Enter Employee ID: ");
    scanf("%d", &e1.id);
    printf("Enter Name: ");
    scanf("%s", &e1.name);
    printf("Enter Date of Joining (dd mm yyyy): ");
    scanf("%d %d %d", &e1.doj.day, &e1.doj.month, &e1.doj.year);
    display(e1);
    

return 0 ;
}