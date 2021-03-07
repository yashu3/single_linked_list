#include <stdio.h>
#include <stdlib.h>
struct node
 {
 int info;
 struct node *next;
 };

int count(struct node* start);
struct node* create_list(struct node* start);
struct node* add_at_beg(struct node* start,int data);
struct node* add_at_end(struct node* start,int data);
void display(struct node* start );
struct node* search(struct node* start,int data);
struct node* add_aft_node(struct node* start, int data);
struct node* add_bef_node(struct node* start, int data);
struct node* add_at_pos(struct node* start,int data);
struct node* del(struct node* start, int data);
struct node* reverse(struct node* start);
struct  node* sorting(struct node* start);


int main()
{
    int choice,data,loc,val,val1,n,i;
    struct node *start;
    while(1)
    {
        printf("1. create list \n");
        printf("2. display \n");
        printf("3. count \n ");
        printf("4. search \n ");
        printf("5. add to empty list \add at beginning \n");
        printf("6. add at end  \n");
        printf("7. add after node \n ");
        printf("8. add before node \n ");
        printf("9. add at position \n ");
        printf("10. Delete \n ");
        printf("11. Reverse \n ");
        printf("12. Sorting  \n ");
        printf("13. Quit \n \n ");
        printf("Enter your choice ...\n ");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1: start=create_list(start);

            break;
        case 2: display(start );
            break;
        case 3:
        count( start);
            break;
        case 4: printf("enter you want to search = ");
                scanf("%d",&n);
                loc=search(start,n);
                printf("element found at pos = %d \n",loc);
            break;
        case 5:
            printf("Enter your elements");
            scanf("%d",&data);
            start=add_at_beg(start,data);
            break;
        case 6:
            printf("Enter your elements");
            scanf("%d",&data);
            start=add_at_end(start,data);
            break;
        case 7:
             printf("Enter data you want to add  = \n");
               scanf("%d",&val);
               start=add_aft_node(start,val);
            break;
        case 8:
           printf("Enter data you want to add  = \n");
               scanf("%d",&val1);
               start=add_bef_node(start,val1);
            break;
        case 9:
           printf("Enter data you want to add at position  = \n");
               scanf("%d",&data);
               start=add_at_pos(start,data);

            break;
        case 10:
        printf("Enter data you want to delete = \n");
               scanf("%d",&data);
               start=del(start,data);

            break;
        case 11:
       start= reverse(start);
            break;
        case 12:
            n=count(start);
            for(i=1;i<n;i++)
            start=sorting(start);
            break;

        case 13:
            exit(1) ;
            break;

        default:
            printf("Please enter correct choice");

    }    }


    return 0;

}


struct node* create_list(struct node* start)
{
    int i,n,data;
    printf("Enter no. of nodes");
    scanf("%d",&n);
    if(n==0){
        return start;
    }
    start=NULL;
    printf("Please Enter Data");
    scanf("%d",&data);
  start=add_at_beg(start,data);
  for(int i=2;i<=n;i++)
  {
      printf("Please Enter Data");
      scanf("%d",&data);
      start=add_at_end(start,data);
   }
  return start;

}
struct node* add_at_beg(struct node* start,int data)
{
  struct node* tmp;
  tmp= (struct node* ) malloc(sizeof(struct node));
  tmp->info=data;
  tmp->next=start;
  start=tmp;
  return start;
};
struct node* add_at_end(struct node *start, int data)
{
  struct node *tmp,*p;
  tmp= (struct node *)malloc(sizeof(struct node));
  tmp->info=data;
  p=start;
  while(p->next!=NULL)
  {

  p=p->next;}
  p->next=tmp;
  tmp->next=NULL;
  return start;
}
void display(struct node* start)
{
    struct node *p;
    p=start;
    printf("list is \n");
    while(p!=NULL)
    {
    printf("%d \n",p->info);
    p=p->next;
    }
    printf("\n\n\n");
    }

struct node *search(struct node* start , int data)
{
    struct node* p;
    p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->info==data)
        {
            return(pos);
        }
    p=p->next;
    pos++;
    }
}
int count(struct node* start)
{
    struct node* p;
    p=start;
    int cnt=0;
    while(p!=NULL)
 {  p=p->next;
    cnt++;
}
printf("No. Of elements = %d\n",cnt);
  return(cnt);
  }

struct node* add_aft_node(struct node* start, int data)
{
struct node *p,*tmp;
int pos,n;
p=start;
printf("Enter node afetr which you want to add  = \n");
scanf("%d",&n);

pos=search(start,n);
for(int i=1;i<=pos;i++)
{
if(i==pos)
{
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;

tmp->next=p->next;
p->next=tmp;
}
p=p->next;
}
return(start);
}

struct node* add_bef_node(struct node* start, int data)
{
struct node *p,*tmp;
int pos,n;
p=start;
printf("Enter node before which you want to add  = \n");
scanf("%d",&n);

pos=search(start,n);
for(int i=1;i<pos;i++)
{
if(i==pos-1)
{
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;

tmp->next=p->next;
p->next=tmp;
}
p=p->next;
}
return(start);
}


struct node* add_at_pos(struct node* start,int data)

{

struct node *p,*tmp;
int pos,n;
p=start;
printf("Enter position at which you want to add element  = \n");
scanf("%d",&pos);
tmp=(struct node*)malloc(sizeof(struct node));
tmp->info=data;
if(pos==1)
           {
            start=add_at_beg(start,data);
       return (start);     }

for(int i=1;i<=pos;i++)
{
if(i==pos)
{

tmp->next=p->next;
p->next=tmp;

}
else{
printf("There are less then %d elements \n",pos);
}
p=p->next;

}
return(start);
}

struct node* del(struct node* start, int data)
{
struct node* p,*tmp;
int item,i,pos;
pos=search(start,data);
p=start;

if (start==NULL)
  {
   printf("List has no elements");
   return(start);
   }
if (start->info==data)
  {
  tmp=start;
  start=start->next;
  free(tmp);
  return start;
   }
p=start;
for(i=1;i<pos;i++)
{
if(i==pos-1)
{
tmp=p->next;
p->next=tmp->next;
free(tmp);
return(start);
}
p=p->next;
}
}

struct node* reverse(struct node *start)
{

    struct node *prevNode, *curNode;

    if(start != NULL)
    {
        prevNode = start;
        curNode = start->next;
        start = start->next;

        prevNode->next = NULL; // Make first node as last node

        while(start != NULL)
        {
            start = start->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = start;
        }

        start = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
        return (start);
    }
}


struct  node* sorting(struct node* start)
{
struct node *p,*tmp,*ptr;
int a,n,i;
p=start;
tmp=p;
p=p->next;
while(p!=NULL)
{
if(tmp->info<p->info)
{ a=tmp->info;
tmp->info=p->info;
p->info=a;
}
else
{
p=p->next;
tmp=tmp->next;}
}
return (start);
}
