#include"student.h"

void stud_save(SLL *ptr)
{
    if(ptr==0)
    {
        printf("no records found\n");
        return;
    }

    FILE *fp=fopen("student.dat","w");

    while(ptr)
    {
        fprintf(fp,"%d %s %f\n",
                ptr->rollno,
                ptr->name,
                ptr->percentage);

        ptr=ptr->next;
    }

    fclose(fp);

    printf("data saved in file\n");
}

void loadfile(SLL **ptr)
{
    FILE *fp=fopen("student.dat","r");

    if(fp==0)
    {
        return;
    }

    SLL *new,*temp;

    while(1)
    {
        new=malloc(sizeof(SLL));

        if(new==0)
        {
            printf("memory allocation failed\n");
            fclose(fp);
            return;
        }

        if(fscanf(fp,"%d %s %f",
                  &new->rollno,
                  new->name,
                  &new->percentage)!=3)
        {
            free(new);
            break;
        }

        new->next=0;

        if(*ptr==0)
        {
            *ptr=new;
        }
        else
        {
            temp=*ptr;

            while(temp->next)
                temp=temp->next;

            temp->next=new;
        }
    }

    fclose(fp);
}

