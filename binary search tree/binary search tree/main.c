//
//  main.c
//  binary search tree
//
//  Created by piyush goel on 3/26/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int arr[20];

struct node
{
    int item;
    struct node *left,*right;
};
struct node *temp=NULL,*root=NULL,*par=NULL;

struct node *getnode()
{
    
    return (struct node*)malloc(sizeof(struct node));
};
void insert(struct node *temp,struct node *par)
{
   
    
    
        if (temp->item<par->item)
        {
            
            if (par->left==NULL)
              par->left=temp;
            
            
            else if (par->left!=NULL)
                insert(temp,par->left);
               
        }
        else if (temp->item>par->item)
        {
             
            if (par->right==NULL)
             par->right=temp;
            
            
            else if (par->right!=NULL)
                insert(temp,par->right);
            
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

struct node *delete(int item,struct node *suc)
{
    
    struct node *repar=NULL,*insuc=NULL;
    suc=search(item,suc);
    repar=par;

    if (suc->right==NULL&&suc->left==NULL)
    {
        if (par->left==suc)
            par->left=NULL;
        else
            par->right=NULL;
        
    }
    
    else if((suc->right==NULL&&suc->left!=NULL)||(suc->right!=NULL&&suc->left==NULL))
    {
        if (suc->right==NULL&&suc->left!=NULL)
        {
            if (par->left==suc)
                par->left=suc->left;
            else if (par->right==suc)
                par->right=suc->left;
        }
        
        else if (suc->right!=NULL&&suc->left==NULL)
        {
            if (par->left==suc)
                par->left=suc->right;
            else if (par->right==suc)
                par->right=suc->right;
        }
    }
    
    else if (suc->right!=NULL&&suc->left!=NULL)
    {
        insuc=suc->right;
        while (insuc->left!=NULL)
              insuc=insuc->left;
        insuc=delete(insuc->item,suc);
        insuc->left=suc->left;
        insuc->right=suc->right;
        
        if (repar->left==suc)
            repar->left=insuc;
        else if (repar->right==suc)
            par->right=insuc;
    
    }
    
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



int main(int argc, const char * argv[])
{

    char option[2];
    
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
    
        
         insert(temp,root);
        
     }
       
    while (1)
    {
        printf("\n1.create a new tree\n2.preorder\n3.postorder\n4.inorder\n5.insert\n6.search\n7.delete\n8.exit\n");
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
                temp=delete(num,root);
                break;
                
            default:exit(8);
                break;
        }
    }

    
    return 0;
}

