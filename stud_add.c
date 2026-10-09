#include "student.h"
void stud_add(SLL **ptr)
{
SLL *new;
new=malloc(sizeof(SLL));
if(new==NULL)
{
printf("memory allocation failed\n");
return;
}
int roll=1;
SLL *temp;
while(1)
{
temp=*ptr;
while(temp!=NULL)
{
if(temp->rollno==roll)
{
roll++;
break;
}
temp=temp->next;
}
if(temp==NULL)
break;
}
new->rollno=roll;
printf("enter name and percentage\n");
scanf("%s%f",new->name,&new->percentage);
new->next=NULL;
if(*ptr==NULL)
*ptr=new;
else
{
temp=*ptr;
while(temp->next!=NULL)
temp=temp->next;
temp->next=new;
}
printf("record added successfully\n");
}

