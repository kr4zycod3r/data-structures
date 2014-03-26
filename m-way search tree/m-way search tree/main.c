//
//  main.c
//  m-way search tree
//
//  Created by piyush goel on 3/30/13.
//  Copyright (c) 2013 piyush goel. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int m=5,key=0;
struct node
{
    int key[4],pk,pp;
    struct node *a[5];
    
};
struct node *root=NULL;
struct node *getnode()
{
    return (struct node *)malloc(sizeof(struct node));

};
void insert(int item,struct node *par)
{
    int t=0,i=0;
    struct node *temp;
    if (item<par->key[0]&&par->pk<m-1)
    {
        par->pk+=1;
        printf("\nenter");
        for (i=0;i<par->pk ;i++)
        {
            t=par->key[i];
            par->key[i]=item;
            item=t;
        }
    }
    else
    {
        for (i=0;item>par->key[i]&&i<par->pk;)
            i++;
              if(i<m)
        {
            
            if (par->a[i]!=NULL)
               insert(item,par->a[i]);
            else
            {
                temp=getnode();
                temp->key[0]=item;
                temp->pk=1;
                temp->pp=0;
                temp->a[0]=NULL;
                temp->a[1]=NULL;
                temp->a[2]=NULL;
                temp->a[3]=NULL;
                temp->a[4]=NULL;
                par->a[i]=temp;
                par->pp+=1;
                printf("\nenter");

            }
            
        
        }
        else
            printf("\n cannot be inserted");
    
    }


};
struct node *search(int item,struct node *par)
{
    int i=0;
    for (i=0;item>par->key[i]&&i<par->pk;)
        i++;
    if (item==par->key[i])
    {
        key=i;
        return par;
    }
    else if((item<par->key[i]||item>par->key[i])&&par->a[i]!=NULL)
        return search(item,par->a[i]);
    
    else
        return NULL;
};
struct node *delete(int item,struct node *par)
{
    int j=0;
    struct node *temp;
    par=search(item,par);
    if(par==NULL)
        return NULL;
    else
    {
        if (par->a[key]==NULL&&par->a[key+1]==NULL)
        {
            
            par->pk--;
            if (par->pk==0)
               par=NULL;
            
            else
            {
              for (j=key;j<=par->pk&&key<m-1;j++)
                   par->key[j]=par->key[j+1];
            }
            
        }
        else if (par->a[key]!=NULL&&par->a[key+1]==NULL)
        {
        
            temp=par->a[key];
            par->key[key]=temp->key[temp->pk-1];
            if(temp->pk==1)
                par->a[key]=NULL;
            else
            return delete(temp->key[temp->pk-1],root);
        
        }
        
        else if (par->a[key]==NULL&&par->a[key+1]!=NULL)
        {
            temp=par->a[key+1];
            par->key[key]=temp->key[0];
            if(temp->pk==1)
                par->a[key+1]=NULL;
            else
            return delete(temp->key[0],root);
        }
        
        else if (par->a[key]!=NULL&&par->a[key+1]!=NULL)
        {
            
            temp=par->a[key];
            par->key[key]=temp->key[temp->pk-1];
            if(temp->pk==1)
                par->a[key+1]=NULL;
            else
            return delete(temp->key[temp->pk-1],root);
            
        }
        
    
    
    
    }

    return par;
};

int main(int argc, const char * argv[])
{
    char option[2];
    struct node *temp=NULL;
    int num=0,i=0,arr[50];

start:
    printf("Enter Item\n");
    scanf("%d",&num);
    
    for (i=0;i<num;i++)
        scanf("%d",&arr[i]);
    
    for (i=0;i<num;i++)
    {
        
        if (i==0)
        {
            temp=getnode();
            temp->key[0]=arr[i];
            temp->pk=1;
            temp->pp=0;
            temp->a[0]=NULL;
            temp->a[1]=NULL;
            temp->a[2]=NULL;
            temp->a[3]=NULL;
            temp->a[4]=NULL;
            root=temp;
            
        }
        
        else
            insert(arr[i],root);
    }

    while (1)
    {
        printf("\n1.create a new tree\n2.insert\n3.search\n4.delete\n5.exit\n");
        scanf("%s",option);
        switch (option[0])
        {
            case '1':
                goto start;
                break;
                
            case '2':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                insert(num,root);
                break;
                
            case '3':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                temp=search(num,root);
                if(temp==NULL)
                    printf("\nItem not found");
                else
                    printf("\nItem found");
                break;
                
            case '4':
                printf("\nEnter Item: ");
                scanf("%d",&num);
                temp=delete(num,root);
                if(temp==NULL)
                    printf("\nItem not found");
                else
                    printf("\nItem deleted");
                break;
                
            
            case '5':
                exit(5);
                break;
                
        }
    }
    
    return 0;
}

