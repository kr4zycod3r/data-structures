//
//  main.c
//  binary tree
//
//  Created by piyush goel on 12/25/12.
//  Copyright (c) 2012 piyush goel. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int count=1;
struct queue *rootq,*rear,*next;
struct queue
{
    struct node *item;
    struct queue *link,*back;
  
};
struct queue *getqueue()
{
    
    return (struct queue*)malloc(sizeof(struct queue));
};
void push(struct node *add)
{
    struct queue *temp;
    temp=getqueue();
    next=temp;
    if (count==1)
    {
        rootq=temp;
        temp->back=NULL;
        
    }
    else
    { temp->back=rear;
      rear->link=next;
      
    }
        temp->item=add;
        rear=temp;
       count++;
    
};
struct node *pop()
{
    struct queue *returns;
    returns=rootq;
    count--;
    if (rootq->link==NULL)
    {   rootq=NULL;
        return returns->item;
   
    }
    else
    rootq=rootq->link;
    return returns->item;
};
struct node
{
    char node;
    struct node *left,*right;
};

struct node *getnode()
{
    
    return (struct node*)malloc(sizeof(struct node));
};
void preorder(struct node *leaf )
{
    if(leaf!=NULL)
    printf("\n%c",leaf->node);
    
    if(leaf->left!=NULL)
    preorder(leaf->left);
    
    if(leaf->right!=NULL)
    preorder(leaf->right);
    
};
void postorder(struct node *leaf )
{
    if(leaf->left!=NULL)
    postorder(leaf->left);
    
    if(leaf->right!=NULL)
    postorder(leaf->right);
    
    if(leaf!=NULL)
        printf("\n%c",leaf->node);
};
void inorder(struct node *leaf )
{
    if(leaf->left!=NULL)
   inorder(leaf->left);
   
    if(leaf!=NULL)
        printf("\n%c",leaf->node);
    
    if(leaf->right!=NULL)
     inorder(leaf->right);
    
    
};

int main(int argc, const char * argv[])
{
    struct node *temp,*root,*par;

    int depth=1,i=0;
    char option[2],item[2];
start:
    printf("create a binary tree...");
    depth=1;temp=NULL,root=NULL,par=NULL,count=1;
    do {
        printf("\ndepth=%d-",depth);
        if (depth==1)
        {
            printf("\nEnter root item ");
            scanf("%s",item);
            temp=getnode();
            temp->node=item[0];
            root=temp;
            push(temp);depth=2;
            printf("\ndepth=%d-",depth);
        }
       
        for (i=1; i<=pow(2,depth-2); i++)
        {
                par=pop();
                printf("\nleft child of %c ",par->node);
                scanf("%s",item);
                if (item[0]=='x')
                  par->left=NULL;
                else
                {
                  temp=getnode();
                  temp->node=item[0];
                  par->left=temp;
                  temp->left=NULL;
                  temp->right=NULL;
                  push(temp);
                }
                printf("\nright child of %c ",par->node);
                scanf("%s",item);
                if (item[0]=='x')
                  par->right=NULL;
                else
                {
                  temp=getnode();
                  temp->node=item[0];
                  par->right=temp;
                  temp->left=NULL;
                  temp->right=NULL;
                  push(temp);
                }

       }
        depth++;
        printf("\nWanna enter another item?(y/n) ");
        scanf("%s",option);
    } while (option[0]=='y');
    
    
    while (1)
    {
        printf("\n1.create a new tree\n2.preorder\n3.postorder\n4.inorder\n5.exit\n");
        scanf("%s",option);
        switch (option[0])
        {
            case '1':
                goto start;
                break;
                
            case '2':
                preorder(root);
                break;
            
            case '3':
                postorder(root);
                break;

            case '4':
                inorder(root);
                break;
    
            default:exit(5);
                break;
        }
    }
    
    
    
    
    return 0;
}

