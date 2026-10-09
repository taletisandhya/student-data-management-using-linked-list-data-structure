#include"student.h"
void stud_del(SLL **ptr)
{
if(*ptr==0)
{
printf("no records found\n");
return;
}
char op;
printf("r/R:Enter rollno to delete\n");
printf("n/N:Enter name to delete\n");

printf("enter your choice\n");
scanf(" %c",&op);
if(op=='r' || op=='R')
{
int rollno;
printf("enter rollno to delete\n");
scanf("%d",&rollno);
SLL *del=*ptr,*prev;
while(del)
{
if(rollno==del->rollno)
{
if(del==*ptr)
*ptr=del->next;
else
prev->next=del->next;
free(del);
printf("record deleted successfully\n");
return;
}
prev=del;
del=del->next;
}
printf("rollno not found\n");
}

else if(op=='n' || op=='N')
{
char name[20];
int count=0;
printf("enter name to delete\n");
scanf("%s",name);
SLL *del=*ptr;
while(del)
{
if(strcmp(name,del->name)==0)
count++;

del=del->next;
}
if(count==0)
{
printf("name not found\n");
return;
}
if(count==1)
{
del=*ptr;
SLL *prev=0;
while(del)
{
if(strcmp(name,del->name)==0)
{
if(del==*ptr)
*ptr=del->next;
else
prev->next=del->next;
free(del);
printf("record deleted successfully\n");
return;
}
prev=del;
del=del->next;
}
}
//if multiple records having same name
printf("multiple records having same name\n");
del=*ptr;
while(del)
{
if(strcmp(name,del->name)==0)
printf("%d %s %f\n",del->rollno,del->name,del->percentage);
del=del->next;
}
int rollno;
printf("enter rollno to delete\n");
scanf("%d",&rollno);
del=*ptr;
SLL *prev=0;
while(del)
{
if(rollno==del->rollno)
{
if(del==*ptr)
*ptr=del->next;
else
prev->next=del->next;
free(del);
printf("record deleted successfully\n");
return;
}
prev=del;
del=del->next;
}
printf("rollno not found\n");
}
else
printf("invalid choice\n");
}

