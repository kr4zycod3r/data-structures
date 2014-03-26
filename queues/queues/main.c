//
//  main.c
//  queues
//
//  Created by piyush goel on 12/24/12.
//  Copyright (c) 2012 piyush goel. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
void take(int *a)
{
    register char c=0;
    
    while (c<33) {
        c=getchar_unlocked();
    }
    
    
    *a=0;
    while (c>47)
    {
        *a=*a*10+c-48;
        c=getchar_unlocked();
    }
    
};

struct node
{
    int node;
    struct node *link;
};

struct node *getnode()
{
    
    return (struct node*)malloc(sizeof(struct node));
};

void printlist(struct node *root)
{
    int i=1;
    while (root!=NULL)
    {
        printf("\nItem%d %d",i,root->node);
        root=root->link;
    }

};
struct node *insert(struct node *rear)
{
    int item;
    struct node *temp;
    printf("\nEnter item to be inserted ");
    scanf("%d",&item);
    temp=getnode();
    rear->link=temp;
    rear=temp;
    temp->link=NULL;
    temp->node=item;
    printf("\nItem successfully inserted...");

    return rear;
};


int main(int argc, const char * argv[])
{

    struct node *temp,*root,*rear,*old=NULL;
    int i=1,item=0;
    char option[2];
    printf("create a queue....");
    
create:
    do {
        printf("\nItem%d ",i);
        take(&item);
        temp=getnode();
        temp->node=item;
        if (i==1)
            root=temp;
        else
            old->link=temp;
        i++;
        rear=temp;
        old=temp;
        temp->link=NULL;
        printf("\nwanna enter more?(y/n) ");
        scanf("%s",option);
        
    } while (option[0]=='y');
    
    while (1)
    {
        printf("\n1.create a new queue\n2.printlist\n3.insert item\n4.Exit\n");
        scanf("%s",option);
        switch (option[0])
        {
            case '1':
                goto create;
                break;
                
            case '2':
                printlist(root);
                break;
                
            case '3':
             rear=insert(rear);
                break;

                
            default:exit(4);
                break;
        }
        
    }
    
    return 0;
}

