//
//  main.c
//  stacks through linked list
//
//  Created by piyush goel on 12/20/12.
//  Copyright (c) 2012 piyush goel. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int top=0;
struct node
{
    char node;
    struct node *link;
};

struct node *getnode()
{
   
    return (struct node*)malloc(sizeof(struct node));
};

struct node *push(struct node *root)
{
    char item[2];
    struct node *temp;
    temp=getnode();
    printf("\nEnter item ");
    scanf("%s",item);
    fflush(stdin);
    if (top==0)
    {
        root=temp;
        temp->link=NULL;
        temp->node=item[0];
        top+=1;
    }
    else
    {
        temp->node=item[0];
        temp->link=root;
        root=temp;
        top+=1;
    };
    printf("\nItem pushed\n");
    return root;
};
struct node *pop(struct node *root)
{
    if (top>=1)
    {
        printf("\n%c\n",root->node);
        root=root->link;
        top-=1;
    }
    else
    {
        printf("\nERROR209:STACK UNDERFLOW\n");
    }
    return root;
};
 
int main(int argc, const char * argv[])
{

    struct node *root=NULL;
    int option[1];
    
    while (1)
    {
        printf("select from the list\n1.Push\n2.Pop\n3.exit\n");
        scanf("%d",&option[0]);
        switch (option[0])
        {
            case 1:
             root=push(root);
                break;
                
            case 2:
             root=pop(root);
                break;
                
            case 3:
                exit(3);
                break;
            default:
                break;
        }
    }
    return 0;
}

