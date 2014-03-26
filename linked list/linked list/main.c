//
//  main.c
//  linked list
//
//  Created by piyush goel on 12/19/12.
//  Copyright (c) 2012 piyush goel. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int a=1,b=0;
struct node *par;
struct node
{
     char node;
    struct node *link;
};

struct node *getnode()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    return temp;
};

struct node *searchitem(struct node *root)
{
    struct node *position;
    char item[2];b=1;
    printf("\nEnter item ");
    scanf("%s",item);
    position=root;
    while (position!=NULL)
    {
        
        if (position->node==item[0])
        {
            break;
        }b++;
        par=position;
        position=position->link;
    }
    if (position==root)
    {
        par=NULL;
        return position;
    }
    printf("\n");
    return position;
};


struct node *createnew()
{
     a=2;
    char option[2],item[2];
    struct node *temp,*old,*root;
    printf("Create a new linked list....\n");
    printf("Item1 ");
    scanf("%s",item);
    temp=getnode();
    root=temp;
    fflush(stdin);
    
    do
    {
    
        old=temp;
        temp->node=item[0];
        printf("\nWanna enter another item?(y/n) ");
        scanf("%s",option);
        if (option[0]=='y')
        {
            
            
            fflush(stdin);
            printf("\nItem%d ",a++);
            scanf("%s",item);
            temp=getnode();
            old->link=temp;
        }
    } while (option[0]=='y');
    temp->link=NULL;a-=1;
    return root;
};

void printlist(struct node *root)
{
  struct node *next;
    a=1;
    next=root;
    while (next!=NULL)
    {
        printf("\nItem%d %c",a++,next->node);
        
        next=next->link;
    }
    a-=1;printf("\n");
};

struct node *deleteitem(struct node *root)
{
    struct node *position;
    
    
    position=searchitem(root);
    if (position==NULL) {
        printf("\nItem not found");
    }
    else if(par==NULL)
    {
        root=root->link;
        printf("\nItem successfully deleted");
    }
    else
    {
        par->link=position->link;
        printf("\nItem successfully deleted");
    }
    printf("\n");
    return root;
};

struct node *insertitem(struct node *root)
{
    struct node *next,*temp;
    char item[2];
    int place=0,b=1;
    printf("\nEnter item to be inserted ");
    scanf("%s",item);
    printf("\nEnter position ");
    scanf("%d",&place);
    
    if (place>a+1)
    {
        printf("\nSorry item cannot be inserted");
    }
    
    else if (place==1)
    {
        temp=getnode();
        temp->node=item[0];
        temp->link=root;
        root=temp;
        
        printf("\nItem successfully inserted\n");
       
    }
    else 
    {
        next=root;
        par=next;
        temp=getnode();
        temp->node=item[0];
        while (b!=place)
        {
            b++;
          par=next;
            next=next->link;
        }
        par->link=temp;
        temp->link=next;
        printf("\nItem successfully inserted\n");
        return root;
    }
    
     return root;

};

int main(int argc, const char * argv[])
{
    int option=0;
   // char;*/
    struct node *root,*position;
    
  while (1)
  {
        
    
    printf("select from list...\n1.create new list\n2.print list\n3.delete item\n4.insert item\n5.search item\n6.Exit\n");
    scanf("%d",&option);
    switch (option) {
        case 1:
            root=createnew();
            break;
            
        case 2:
            printlist(root);
            break;
         
        case 3:
           root=deleteitem(root);
            break;
            
        case 4:
           root=insertitem(root);
            break;
            
        case 5:
           position=searchitem(root);
            if (position!=NULL)
            {
                printf("\nItem found at %d place",b);
            }
            else printf("\nItem not found");
            break;
     
       case 6:
            exit(6);
        default:
            break;
    }
    
  }
    
    return 0;
}

