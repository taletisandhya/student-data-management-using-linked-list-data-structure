#include"student.h"

void stud_mod(SLL *ptr)
{
    if(ptr==0)
    {
        printf("no records found\n");
        return;
    }

    char op;

    printf("Enter which record to search for modification\n");
    printf("r/R : Search by roll number\n");
    printf("n/N : Search by name\n");
    printf("p/P : Search by percentage\n");

    printf("enter your choice\n");
    scanf(" %c",&op);

    if(op=='r' || op=='R')
    {
        int rollno;

        printf("enter rollno to modify\n");
        scanf("%d",&rollno);

        SLL *del=ptr;

        while(del)
        {
            if(rollno==del->rollno)
            {
                printf("rollno=%d name=%s percentage=%.2f\n",
                       del->rollno,del->name,del->percentage);

                printf("enter new name\n");
                scanf("%s",del->name);

                printf("enter new percentage\n");
                scanf("%f",&del->percentage);

                printf("record modified successfully\n");
                return;
            }

            del=del->next;
        }

        printf("rollno not found\n");
    }

    else if(op=='n' || op=='N')
    {
        char name[20];
        int count=0;
        int rollno;

        printf("enter name to modify\n");
        scanf("%s",name);

        SLL *del=ptr;
 /* Count matching names */
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

        /* Only one matching record */
        if(count==1)
        {
            del=ptr;

            while(del)
            {
                if(strcmp(name,del->name)==0)
                {
                    printf("rollno=%d name=%s percentage=%.2f\n",
                           del->rollno,del->name,del->percentage);

                    printf("enter new name\n");
                    scanf("%s",del->name);

                    printf("enter new percentage\n");
                    scanf("%f",&del->percentage);

                    printf("record modified successfully\n");
                    return;
                }

                del=del->next;
            }
        }

  /* Multiple matching records */
        printf("multiple records found\n");

        del=ptr;

        while(del)
        {
            if(strcmp(name,del->name)==0)
            {
                printf("rollno=%d name=%s percentage=%.2f\n",
                       del->rollno,del->name,del->percentage);
            }

            del=del->next;
        }

        printf("enter rollno to modify\n");
        scanf("%d",&rollno);

        del=ptr;

        while(del)
        {
            if(rollno==del->rollno &&
               strcmp(name,del->name)==0)
            {
                printf("enter new name\n");
                scanf("%s",del->name);

                printf("enter new percentage\n");
                scanf("%f",&del->percentage);

                printf("record modified successfully\n");
                return;
            }

            del=del->next;
        }

        printf("record not found\n");
    }

    else if(op=='p' || op=='P')
    {
        float percentage;
        int count=0;
        int rollno;

        printf("enter percentage to modify\n");
        scanf("%f",&percentage);

        SLL *del=ptr;

        /* Count matching percentage */
        while(del)
        {
            if(del->percentage==percentage)
                count++;

            del=del->next;
        }

        if(count==0)
        {
            printf("percentage not found\n");
            return;
        }
  /* Only one matching record */
        if(count==1)
        {
            del=ptr;

            while(del)
            {
                if(del->percentage==percentage)
                {
                    printf("rollno=%d name=%s percentage=%.2f\n",
                           del->rollno,del->name,del->percentage);

                    printf("enter new name\n");
                    scanf("%s",del->name);

                    printf("enter new percentage\n");
                    scanf("%f",&del->percentage);

                    printf("record modified successfully\n");
                    return;
                }

                del=del->next;
            }
        }

        /* Multiple matching records */
        printf("multiple records found\n");

        del=ptr;

        while(del)
        {
            if(del->percentage==percentage)
            {
                printf("rollno=%d name=%s percentage=%.2f\n",
                       del->rollno,del->name,del->percentage);
            }

            del=del->next;
        }

        printf("enter rollno to modify\n");
        scanf("%d",&rollno);

        del=ptr;

        while(del)
        {
            if(rollno==del->rollno &&
               del->percentage==percentage)
            {
                printf("enter new name\n");
                scanf("%s",del->name);

                printf("enter new percentage\n");
                scanf("%f",&del->percentage);

                printf("record modified successfully\n");
                return;
            }

            del=del->next;
        }

        printf("record not found\n");
    }
else
    {
        printf("invalid choice\n");
    }
}

