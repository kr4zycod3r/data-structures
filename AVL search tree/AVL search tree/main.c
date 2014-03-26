//
//  main.c
//  AVL search tree
//
//  Created by piyush goel on 3/28/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[20],j=0;
char rot[2],er;

struct node
{
    int item;
    struct node *left,*right;
};
struct node *root=NULL,*par=NULL;

struct node *getnode()
{
    
    return (struct node*)malloc(sizeof(struct node));
};
int depth(struct node *root)
{
   if(root==NULL)
       return 0;
    else
        return (depth(root->left)>depth(root->right)?depth(root->left):depth(root->right))+1;

};
int bf(struct node *root)
{
    return depth(root->left)-depth(root->right);
};
struct node *llrot(struct node *root)
{
    struct node *temp;
    temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root=temp;
    
    return root;
    
};

struct node *rrrot(struct node *root)
{
    struct node *temp;
    temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root=temp;
    return root;
    
};

struct node *lrrot(struct node *root)
{
    struct node *temp1,*temp2;
    if (er=='L')
    {
        printf("\nlrl");
        temp1=root->left;
        temp2=temp1->right;
        temp1->right=temp2->left;
        temp2->left=temp1;
        root->left=temp2->right;
        temp2->right=root;
        root=temp2;
        
    }
    else if (er=='R')
    {
        printf("\nlrr");
        temp1=root->left;
        temp2=temp1->right;
        temp1->right=temp2->right;
        temp2->right=temp1;
        root->left=temp2->left;
        temp2->left=root;
        root=temp2;
    
    }
    return root;
};
struct node *rlrot(struct node *root)
{
    struct node *temp1,*temp2;
    if (er=='L')
    {
       printf("\nlrl");
        temp1=root->right;
        temp2=temp1->left;
        temp1->left=temp2->left;
        temp2->left=temp1;
        root->right=temp2->right;
        temp2->right=root;
        root=temp2;
    }
    else if (er=='R')
    {
       printf("\nlrr");
        temp1=root->right;
        temp2=temp1->left;
        temp1->left=temp2->right;
        temp2->right=temp1;
        root->right=temp2->left;
        temp2->left=root;
        root=temp2;
    
    }
    return root;

};
void insert(struct node *temp,struct node *par)
{
    
    
    
    if (temp->item<par->item)
    {
        if(j==2)
        { er='L';
            j++;
            printf("\nL");
        }

        if(j<=1)
        { rot[j]='L';
          j++;
        }
                if (par->left==NULL)
            par->left=temp;
        
        
        else if (par->left!=NULL)
            insert(temp,par->left);
        
    }
    else if (temp->item>par->item)
    {
        if(j==2)
        {  er='R';
            j++;
            printf("\nR");
        }

        if(j<=1)
        { rot[j]='R';
          j++;
        }
                if (par->right==NULL)
            par->right=temp;
        
        
        else if (par->right!=NULL)
            insert(temp,par->right);
        
    }
   
    
    if (bf(root)<-1||bf(root)>1)
    {
        
        if (strcmp(rot,"LL")==0)
         root=llrot(root);
           
        
        else if (strcmp(rot,"RR")==0)
            root=rrrot(root);
            
        else if (strcmp(rot,"LR")==0)
             root=lrrot(root) ;
        else if (strcmp(rot, "RL")==0)
            root=rlrot(root);
    }
    
    
    
};
struct node *search(int item,struct node *suc)
{
    
    
    
    if (item<suc->item)
    {
        
        if (suc->left==NULL)
        {
            printf("\n Item not found");
            return NULL;
        }
        
        
        else if (suc->left!=NULL)
        {  par=suc;
            suc=search(item,suc->left);
        }
    }
    else if (item>suc->item)
    {
        
        if (suc->right==NULL)
        {
            printf("\n Item not found");
            return NULL;
        }
        else if (suc->right!=NULL)
        {   par=suc;
            suc=search(item,suc->right);
        }
        
    }
    
    else if (item==suc->item)
        printf("\n Item found");
    return suc;
    
    
};


void preorder(struct node *leaf )
{
    
    if(leaf!=NULL)
        printf("\n%d",leaf->item);
    
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
        printf("\n%d",leaf->item);
};
void inorder(struct node *leaf )
{
    if(leaf->left!=NULL)
        inorder(leaf->left);
    
    if(leaf!=NULL)
        printf("\n%d",leaf->item);
    
    if(leaf->right!=NULL)
        inorder(leaf->right);
    
    
};
struct node *r(int bal,struct node *root)
{
    struct node *temp,*temp1;
    if (bal==0||bal==1)
    {
        temp=root->left;
        root->left=temp->right;
        temp->right=root;
        root=temp;
    }
    else if(bal==-1)
    {
        temp=root->left;
        temp1=temp->left;
        temp->right=temp1->left;
        temp1->left=temp;
        root->left=temp1->right;
        temp1->right=root;
        root=temp;
    }
    return root;
};
struct node *l(int bal,struct node *root)
{
    struct node *temp,*temp1;
    if (bal==0||bal==1)
    {
        temp=root->right;
        root->right=temp->left;
        temp->left=root;
        root=temp;
    }
    else if(bal==-1)
    {
        temp=root->right;
        temp1=temp->left;
        temp->right=temp1->left;
        temp1->left=temp;
        root->right=temp1->right;
        temp1->right=root;
        root=temp;
    }
    return root;
};

struct node *delete(struct node *temp,struct node *root)
{
    if (temp->item<par->item)
       par->left=NULL;
    else if(temp->item>par->item)
        par->right=NULL;
    else
        root=NULL;
    
    if (bf(root)<-1||bf(root)>1)
    {
        if (temp->item<root->item)
           root=l(bf(root),root);
        else if (temp->item>root->item)
            root=r(bf(root),root);
    }
    
    return root;
    
};


int main(int argc, const char * argv[])
{
    
    char option[2];
    struct node *temp=NULL;
    int num=0,i=0;
start:
    printf("Enter Item\n");
    scanf("%d",&num);
    
    for (i=0;i<num;i++)
        scanf("%d",&arr[i]);
    
    for (i=0;i<num;i++)
    {
        
        temp=getnode();
        temp->item=arr[i];
        temp->left=NULL;
        temp->right=NULL;
        
        if(i==0)
            root=temp;
        
        j=0;
        insert(temp,root);
        
    }
    
    while (1)
    {
        printf("\n1.create a new tree\n2.preorder\n3.postorder\n4.inorder\n5.insert\n6.search\n7.bf\n8.delete\n9.exit\n");
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
                
            case '5':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                temp=getnode();
                temp->item=num;
                temp->left=NULL;
                temp->right=NULL;
                j=0;
                insert(temp,root);
                
                break;
                
            case '6':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                temp=search(num,root);
                break;
            case '7':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                temp=search(num,root);
                printf("\n%d",bf(temp));
                break;
            case '8':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                temp=search(num,root);
                root=delete(temp,root);
                break;
            case '9':
                exit(9);
                break;
                
                
        }
    
    
    }
}
