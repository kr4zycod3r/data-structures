//
//  main.c
//  quicksort
//
//  Created by piyush goel on 12/21/12.
//  Copyright (c) 2012 piyush goel. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int top=0;
int num[1000000],lower1=0,upper1=0;;
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

 struct node *push(int lower,int upper,struct node *root)
{
    struct node *temp;
    int i=1;
    for (i=1;i>=0; i--)
    {
       
      temp=getnode();
      if (top==0)
      {
        root=temp;
        temp->link=NULL;
        temp->node=lower;
        top+=1;
      }
      else
      {
        if (i==1)
        temp->node=lower;
        else
        temp->node=upper;
        
        temp->link=root;
        root=temp;
        top+=1;
      }
    }
   return root;
};
 struct node *pop(struct node *root)
{
    int i=1;
    for (i=1; i>=0;i--)
    {
     if (top>=1)
     {
         if(i==1)
          upper1=root->node;
         else
             lower1=root->node;
        root=root->link;
        top-=1;
     }
     else
      return NULL;
     
    }
    return root;
};

int reduction(int lower,int upper)
{
    int i=0,j=0,loc=lower;
    //printf("\nin");
    if (lower==upper)
    {
        return -1;
    }
    
    while(1)
    {
        
        j=upper;
        for (; j!=lower;j--)
        {
            if(num[lower]>=num[j])
             {
                 i=num[lower];
                 num[lower]=num[j];
                 num[j]=i;
                 loc=j;
                 upper=j;
                 goto next;
             }
            
        }
        if (j==lower)
        {
            return loc;
        }
        
    next:
        j=lower;
        for (;upper!=j;j++)
        {
            if(num[j]>=num[upper])
            {
                i=num[j];
                num[j]=num[upper];
                num[upper]=i;
                loc=j;
                lower=j;
                goto nexter;
            }
            
        }
    nexter:
        if (upper==j)
        {
            return loc;
        }

        
        
    }

};
int main(int argc, const char * argv[])
{

    struct node *root=NULL;
    int i=0,t=0,loc=0;
   
   // printf("enter the nos.\n");
    take(&t);
    for (i=0; i<=t-1; i++)
    {
        take(&num[i]);
    }
    upper1=i-1;
    
    do
    {
              loc=reduction(lower1,upper1);
        if (loc<=upper1-2&&loc>=lower1+2)
        {
            root=push(lower1,loc-1,root);
            root=push(loc+1,upper1,root);
            i=1;
        }
        else if ((loc==lower1||loc-1==lower1)&&loc<=upper1-2)
        {
            root=push(loc+1,upper1,root);
            i=1;
        }
        else if (loc>=lower1+2&&(loc+1==upper1||loc==upper1))
        {
            root=push(lower1,loc-1,root);
            i=1;
        }
        else
        {   i=0;
            root=pop(root);
            loc=reduction(lower1,upper1);
            if (loc<=upper1-2&&loc>=lower1+2)
            {
                root=push(lower1,loc-1,root);
                root=push(loc+1,upper1,root);
                i=1;
            }
            else if ((loc==lower1||loc-1==lower1)&&loc<=upper1-2)
            {
                root=push(loc+1,upper1,root);
                i=1;
            }
            else if (loc>=lower1+2&&(loc+1==upper1||loc==upper1))
            {
                root=push(lower1,loc-1,root);
                i=1;
            }

           // printf("\nme%d\n",loc);
        }
        root=pop(root);
        
        
        
        
    }while (root!=NULL||i!=0);
    
    
    for (i=0; i<=t-1; i++)
    {
        printf("\n%d",num[i]);
    }
    
        return 0;
}

