// Write a program  to pass a structure as the parameter of the function by value.
#include<stdio.h>
#include<string.h>
typedef struct Students
{
    char name[30];
    int age ;
    int marks ;

}stu;
void show(stu S){
    printf("Name:%s\n",S.name);
    printf("Age:%d\n",S.age);
    printf("Marks:%d\n",S.marks);

}

int main(){
stu S1 ;
printf("Enter name:");
scanf("%s",&S1.name);
printf("Enter Age :");
scanf("%d",&S1.age);
printf("Enter Marks:");
scanf("%d",&S1.marks);
show(S1);



return 0 ;
}