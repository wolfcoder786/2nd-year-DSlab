//Passing structure to function
#include<stdio.h>
struct Employee
{
    char name;
    int Employee_id;
};
struct Employee get_data(struct Employee e1){
    printf("Enter the details of the employee");
    printf("Enter name :");
    scanf("%s",&e1.name);
    printf("Enter id:");
    scanf("%d",&e1.Employee_id);
    return e1  ;

}
int main(){
    struct Employee e1;
    get_data(e1);
    printf("The details are :",e1);
    
    
return 0 ;
}