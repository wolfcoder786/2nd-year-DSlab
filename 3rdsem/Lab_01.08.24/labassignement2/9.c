/* Write a program to create a structure student with data-members name,age and marks,use 
the function getdetail()to accept the values from the user and return the structure through 
function*/
#include<stdio.h>
struct details
{
    char name[30];
    int age ;
    int marks;
};
struct details getdetail(){
    struct details d ;
    printf("Enter name:");
    scanf("%s",d.name);
    printf("Enter age :");
    scanf("%d",&d.age);
    printf("Enter marks:");
    scanf("%d",&d.marks);
    return d ;

}

int main(){
printf("Enter the details of the student:\n");
struct details d ;
d = getdetail();
printf("Name:%s\n",d.name);
printf("Age:%d\n",d.age);
printf("Marks:%d\n",d.marks);
return 0 ;
}