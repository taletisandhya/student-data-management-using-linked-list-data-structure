#include"student.h"
int main()
{
SLL *headptr=NULL;
loadfile(&headptr);
char op;
while(1)
{
printf("******* STUDENT RECORD MENU *******\n");
printf("a/A : add new record\n");
printf("d/D : delete a record\n");
printf("s/S : show the list\n");
printf("m/M : modify a record\n");
printf("v/V : save records\n");
printf("e/E : exit\n");
printf("t/T : sort the list\n");
printf("l/L : delete all the records\n");
printf("r/R : reverse the list\n");

printf("Enter your choice\n");
scanf(" %c", &op);
switch(op)
{
case 'a':
case 'A':
         stud_add(&headptr);break;
case 's':
case 'S':
         stud_show(headptr);break;
case 'd':
case 'D':
         stud_del(&headptr);break;
case 'm':
case 'M':
         stud_mod(headptr);break;
case 'v':
case 'V':
         stud_save(headptr);break;
case 't':
case 'T':
         sort_record(headptr);break;
case 'l':
case 'L':
         deleteall(&headptr);break;
case 'r':
case 'R':
         reversenode(&headptr);break;
case 'e':
case 'E':
         if(exitprogram(&headptr))
         return 0;
default:printf("invalid choice\n");

break;
}
}
}

///////////////////////////////////////////////////////////////////

int exitprogram(SLL **ptr)
{
    char ch;
    SLL *del;

    printf("S/s : Save and exit\n");
    printf("E/e : Exit without saving\n");

    printf("Enter your choice\n");
    scanf(" %c",&ch);

    if(ch=='s' || ch=='S')
    {
        stud_save(*ptr);

        while(*ptr)
        {
            del=*ptr;
            *ptr=del->next;
            free(del);
        }

        return 1;
    }

    else if(ch=='e' || ch=='E')
    {
        while(*ptr)
        {
            del=*ptr;
            *ptr=del->next;
            free(del);
        }

        return 1;
    }

    else
    {
        printf("Invalid choice\n");
        return 0;
    }
}


//////////////////////////////////////////////////////////////////////////////

void sort_record(SLL *ptr)
{
    if(ptr==0)
    {
        printf("no records found\n");
        return;
    }

    char op;

    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");

    printf("enter your choice\n");
    scanf(" %c",&op);

    if(op=='n' || op=='N')
    {
        SLL *temp;
        int rollno;
        char name[50];
        float percentage;

        for(temp=ptr; temp->next!=0; temp=temp->next)
        {
            SLL *next=temp->next;

            while(next)
            {
                if(strcmp(temp->name,next->name)>0)
                {
                    rollno=temp->rollno;
                    temp->rollno=next->rollno;
                    next->rollno=rollno;

                    strcpy(name,temp->name);
                    strcpy(temp->name,next->name);
                    strcpy(next->name,name);

                    percentage=temp->percentage;
                    temp->percentage=next->percentage;
                    next->percentage=percentage;
                }

                next=next->next;
            }
        }

        printf("records sorted by name\n");
    }

    else if(op=='p' || op=='P')
    {
        SLL *temp;
        int rollno;
        char name[50];
        float percentage;

        for(temp=ptr; temp->next!=0; temp=temp->next)
        {
            SLL *next=temp->next;

            while(next)
            {
                if(temp->percentage < next->percentage)
                {
                    rollno=temp->rollno;
                    temp->rollno=next->rollno;
                    next->rollno=rollno;

                    strcpy(name,temp->name);
                    strcpy(temp->name,next->name);
                    strcpy(next->name,name);

                    percentage=temp->percentage;
                    temp->percentage=next->percentage;
                    next->percentage=percentage;
                }

                next=next->next;
            }
        }

        printf("records sorted by percentage\n");
    }

    else
    {
        printf("invalid choice\n");
    }
}
/////////////////////////////////////////////////////////////////////////////


void deleteall(SLL **ptr)
{
    SLL *del;

    if(*ptr==0)
    {
        printf("no records found\n");
        return;
    }

    while(*ptr)
    {
        del=*ptr;
        *ptr=del->next;
        free(del);
    }

    printf("all records deleted successfully\n");
}



////////////////////////////////////////////////////////////////////////////////////




void reversenode(SLL **ptr)
{
    SLL *prev=0;
    SLL *cur=*ptr;
    SLL *next;

    if(*ptr==0)
    {
        printf("no records found\n");
        return;
    }

    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }

    *ptr=prev;

    printf("list reversed successfully\n");
}

