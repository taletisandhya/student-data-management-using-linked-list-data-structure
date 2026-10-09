#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
int rollno;
char name[50];
float percentage;
struct student *next;
}SLL;


extern void stud_add(SLL **);
extern void stud_del(SLL **);
extern void stud_show(SLL *);
extern void stud_mod(SLL *);
extern void stud_save(SLL *);
extern void loadfile(SLL **);
extern int exitprogram(SLL **);
extern void sort_record(SLL *);
extern void deleteall(SLL **);
extern void reversenode(SLL **);

