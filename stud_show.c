#include"student.h"
void stud_show(SLL *ptr)
{
if(ptr==0)
{
printf("no records found\n");
return;
}
printf("------------------------------------------\n");
printf("Rollno Name      Percentage\n");
printf("-------------------------------------------\n");
while(ptr)
{
printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
printf("----------------------------------------------\n");
}

