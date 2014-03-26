//
//  main.c
//  polish notation
//
//  Created by piyush goel on 12/27/12.
//  Copyright (c) 2012 piyush goel. All rights reserved.
//
/*
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int count=1;
char option[3],operation[50];

struct stack *roots,*rear,*next;
struct node *returns1,*returns2;
struct stack
{
    struct node *item;
    struct stack *link,*back;
    
};
struct stack *getstack()
{
    
    return (struct stack*)malloc(sizeof(struct stack));
};
void push(struct node *add)
{
    struct stack *temp;
    temp=getstack();
    next=temp;
    if (count==1)
    {
        roots=temp;
        temp->back=NULL;
        temp->link=NULL;
    }
    else
    { temp->back=rear;
        rear->link=next;
        temp->link=NULL;
    }
    temp->item=add;
    rear=temp;
    count++;
    
};
void pop()
{
    struct stack *returns;
    int i=0;
    for(i=0;i<=1;i++)
    {
     returns=rear;
     count--;
     if (rear->back==NULL)
     {   rear=NULL;
        returns2=returns->item;
        
     }
     else if(rear!=NULL)
    {  rear=rear->back;
      if(i==0)
         returns1=returns->item;
     
     else
         returns2=returns->item;
     }
        
    }
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

int answer(struct node *leaf)
{   char a=leaf->node;
    int leftnode=0,rightnode=0;
    struct node *addl=NULL,*addr=NULL;
    addl=leaf->left;
    addr=leaf->right;
    printf("%c",a);
    if (48<=addl->node<=57&&48<=addr->node<=57)
    {
        leftnode=addl->node-48;
        rightnode=addr->node-48;
    }
    
    else if (48>=addl->node>=57&&48<=addr->node<=57)
    {
        rightnode=addr->node-48;
        leftnode=answer(addl);
        
    }
    
    else if(48<=addl->node<=57&&48>=addr->node>=57)
    {
        leftnode=addl->node-48;
        rightnode=answer(addr);
    }
    
    else
    {
        leftnode=answer(addl);
        rightnode=answer(addr);
    }
    
    switch (leaf->node)
    {
        case '+':
            return leftnode+rightnode;
            break;
        case '-':
            return leftnode-rightnode;
            break;
        case '*':
            return leftnode*rightnode;
            break;
        case '/':
            return leftnode/rightnode;
            break;
        case '^':
            return pow(leftnode,rightnode);
            break;
        default:
            break;
    }
    
    return 0;

};

int main(int argc, const char * argv[])
{
    int i=0,flag=0,flag_=0;
    char test;
    struct node *temp,*root;
  while (1)
  {
      printf("\nchoose....\n1.Type operation:\n a.prefix\n b.infix\n c.postfix\n2.convert to:\n a.prefix\n b.infix\n c.postfix\n3.print answer\n4.exit\n");
    
    scanf("%s",option);
    
    
    switch (option[0])
    {
        case '1':
            printf("\nType operation: ");
            scanf("%s",operation);
            if (option[1]=='c')
            {
                for (i=0; operation[i]!='\0'; i++)
                {
                    temp=getnode();
                    temp->node=operation[i];
                    temp->left=NULL;
                    temp->right=NULL;
                    
                    if (47>=operation[i]>=58)
                    {
                        pop();
                        temp->right=returns1;
                        temp->left=returns2;
                    }
                    push(temp);
                }
                root=temp;
                
            }
            

            
            else if (option[1]=='b')
            {
                for (i=0; operation[i]!='\0'; i++)
                {
                    
                    temp=getnode();
                    temp->node=operation[i];
                    temp->left=NULL;
                    temp->right=NULL;
                    test=operation[i];
                priority:
                    switch (test)
                    {
                        case ')'|'(':
                            flag=0;
                            break;
                            
                        case '*'|'/':
                            flag=2;
                            break;
    
                        case '^':
                            flag=3;
                            break;
    
                        default:
                            flag=1;
                            break;
                    }
               
                    if (47>=operation[i]>=58&&operation[i]!=')')
                        push(temp);
                    
                    else if (48<=operation[i]<=57)
                    {
                        test=operation[i+1];
                        goto priority;
                        flag_=flag;
                        test=operation[i-1];
                        goto priority;
                        
                        if (flag_<=flag)
                        {
                            pop();
                            returns1->left=returns2;
                            returns1->right=temp;
                            push(returns1);
                            if(operation[i+1]==')')
                                i++;
                        }
                    else
                      push(temp);
                    }
                
                }
                pop();
                root=returns1;
            }
            
            else if (option[1]=='a')
            {
               for (i=0; operation[i]!='\0'; i++)
               {
                   temp=getnode();
                   temp->node=operation[i];
                   if (47>=operation[i]>=58)
                       push(temp);
            else if (48<=operation[i]<=57&&operation[i+1]=='\0')
            {
                pop();
                returns2->left=returns1;
                returns2->right=temp;
                push(returns2);
            }
               
              else
              {
                  push(temp);
                  temp=getnode();
                  temp->node=operation[i+1];
                  pop();
                  returns2->left=returns1;
                  returns2->right=temp;
                  push(returns2);
                  i++;
              
              }
               }
                pop();
                root=returns1;
            }
            break;
            
            
            case '2':
            if (option[1]=='a')
              preorder(root);
            else if (option[2]=='b')
                inorder(root);
            else
                postorder(root);
            break;
                  
           case '3':
            printf("\n%d",answer(root));
             break;
            
           case '4':
            exit(4);
            
            
        default:
            break;
    }
    
  } return 0;
}

*/
/*
 if (option[1]=='c')
 {
 for (i=0; operation[i]!='\0'; i++)
 {
 temp=getnode();
 temp->node=operation[i];
 temp->left=NULL;
 temp->right=NULL;
 
 if (47>=operation[i]>=58)
 {
 pop();
 temp->right=returns1;
 temp->left=returns2;
 }
 push(temp);
 }
 root=temp;
 
 }

 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node * stack[15],* stack1[15];
int count=0,j=0,count1=0;
char operation[20];
void push(struct node *itemad)
{
    stack[count]=itemad;
    count+=1;
};
struct node * pop()
{
    count-=1;
    return stack[count];
};
struct node
{
    char item;
    struct node *left,*right;
};

struct node *getnode()
{
    
    return (struct node*)malloc(sizeof(struct node));
};
void preorder(struct node *leaf )
{
    if(leaf!=NULL)
        printf("\n%c",leaf->item);
    
    if(leaf->left!=NULL)
        preorder(leaf->left);
    
    if(leaf->right!=NULL)
        preorder(leaf->right);
    
};
int answer(struct node *leaf )
{
    int jawaab=0,leftint=0,rightint=0;
    
    if ((47<leaf->left->item&&leaf->left->item<=57)&&(47<leaf->right->item&&leaf->right->item<=57))
    {
        printf("%c%d",leaf->left->item,leaf->left->item);
        leftint=leaf->left->item-48;
        printf("leftint1=%d",leftint);
        rightint=leaf->right->item-48;
    }
    else if ((47<leaf->left->item&&leaf->left->item<=57)&&(leaf->right->item>57||leaf->right->item<=47))
    {
       leftint=leaf->left->item-48;
        rightint=answer(leaf->right);
    }
    else if ((47<leaf->right->item&&leaf->right->item<=57)&&(leaf->left->item>57||leaf->left->item<=47))
    {
        rightint=leaf->right->item-48;
        printf("rightint2=%d",rightint);
        leftint=answer(leaf->left);
        printf("leftint2=%d",leftint);
    }
    else if ((leaf->left->item>57||leaf->left->item<=47)&&(leaf->right->item>57||leaf->right->item<=47))
    {
        leftint=answer(leaf->left);
        rightint=answer(leaf->right);

    }
    
    switch (leaf->item)
    {
        case '+':
            return leftint+rightint;
            break;
        case '-':
            return leftint-rightint;
            break;
        case '*':
            return leftint*rightint;
            break;
        case '/':
            return leftint/rightint;
            break;
        case '^':
            return pow(leftint,rightint);
            break;
        default:
            break;
    }

    return jawaab;
  
};
int priority(char op)
{
    switch (op) {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            break;
    }
    return 0;

};
void push1(struct node *itemad)
{
    stack1[count1]=itemad;
    count1+=1;
};
struct node * pop1()
{
    count1-=1;
    return stack1[count1];
};
struct node *recur(int i)
{
    struct node *temp=NULL,*root=NULL,*pop1=NULL,*pop2=NULL;
   
    for (i=0;operation[i]!=')';i++)
    {
        temp=getnode();
        temp->item=operation[i];
        temp->left=NULL;
        temp->right=NULL;
        if (47<operation[i]&&operation[i]<=57)
        {
            push(temp);
            
        }
        else if ((47>=operation[i]||operation[i]>57)&&(operation[i]!='('&&operation[i]!=')'))
        {
            push(temp);
            p1=priority(operation[i]);
            if (47<operation[i+1]&&operation[i+1]<=57) {
                if ((47>=operation[i+2]||operation[i]>57)&&(operation[i+2]!='('&&operation[i]!=')'))
                {
                    p2=priority(operation[i+2]);
                    if (p1>=p2)
                    {
                        i+=1;
                        temp=getnode();
                        temp->item=operation[i];
                        temp->left=NULL;
                        temp->right=NULL;
                        pop1=pop();
                        pop2=pop();
                        pop1->left=pop2;
                        pop1->right=temp;
                    }
                    else
                    {
                        push(temp);
                        continue;
                    }
                }
                
                else if (operation[i+1]=='(')
                {
                    i+=2;
                    
                    
                    
                }
            }
        }
    }


}

int main()
{
    struct node *temp=NULL,*root=NULL,*pop1=NULL,*pop2=NULL;
    char option[3];
    int i=0,p1=0,p2=0;
    while (1)
    {
        printf("\nchoose....\n1.Type operation:\n a.prefix\n b.infix\n c.postfix\n2.convert to:\n a.prefix\n b.infix\n c.postfix\n3.print answer\n4.exit\n");
        
        scanf("%s",option);
    
        switch (option[0])
        {
           case '1':
                printf("Type operation: ");
                scanf("%s",operation);
                if (option[1]=='a')
                {
                    for(i=0;operation[i]!='\0';i++)
                    {
                        temp=getnode();
                        //printf("%d",i);
                        temp->item=operation[i];
                        temp->left=NULL;
                        temp->right=NULL;
                         if(i==0)
                             root=temp;
                        if (47>=operation[i]||operation[i]>57)
                        {
                           push(temp);
                        }
                        else if (47<operation[i]<=57)
                        {
                            if(operation[i+1]!='\0')
                            {
                                 push(temp);
                                 pop1=pop();
                                 pop2=pop();
                                 i+=1;
                                temp=getnode();
                                temp->left=NULL;
                                temp->right=NULL;
                                temp->item=operation[i];
                                pop2->left=pop1;
                                pop2->right=temp;
                                push(pop2);
                         if (47>=operation[i]||operation[i]>57)
                                    push(temp);
                                
                            }
                            else
                            {
                                pop1=pop();
                                pop2=pop();
                                printf("count=%d",count);
                                pop2->left=pop1;
                                pop2->right=temp;
                                push(pop2);

                            }
                        }
                    }
                    if (count==3)
                    {
                        pop1=pop();
                        pop2=pop();
                        stack[0]->left=pop2;
                        stack[0]->right=pop1;
                    }
                    
                }
                
                else if (option[1]=='b')
                {
                    for (i=0;operation[i]!='\0';i++)
                    {
                        temp=getnode();
                        temp->item=operation[i];
                        temp->left=NULL;
                        temp->right=NULL;
                        if (47<operation[i]&&operation[i]<=57)
                        {
                            push(temp);
                            
                        }
                        else if ((47>=operation[i]||operation[i]>57)&&(operation[i]!='('&&operation[i]!=')'))
                        {
                            push(temp);
                            p1=priority(operation[i]);
                            if (47<operation[i+1]&&operation[i+1]<=57)   {
                                  if ((47>=operation[i+2]||operation[i]>57)&&(operation[i+2]!='('&&operation[i]!=')'))
                                  {
                                      p2=priority(operation[i+2]);
                                      if (p1>=p2)
                                      {
                                          i+=1;
                                          temp=getnode();
                                          temp->item=operation[i];
                                          temp->left=NULL;
                                          temp->right=NULL;
                                          pop1=pop();
                                          pop2=pop();
                                          pop1->left=pop2;
                                          pop1->right=temp;
                                      }
                                      else
                                      {
                                          push(temp);
                                          continue;
                                      }
                                  }
                                }
                            else if (operation[i+1]=='(')
                                {
                                    i+=2;
                                    temp=recur(i);
                                    
                                    if ((47>=operation[i]||operation[i]>57)&&(operation[i]!='('&&operation[i]!=')'))
                                    {
                                      p2=priority(operation[i]);
                                        if (p1>=p2)
                                        {
                                            pop1=pop();
                                            pop2=pop();
                                            pop1->left=pop2;
                                            pop1->right=temp;
                                        }
                                        else
                                        {
                                          
                                        
                                        
                                        }
                                        
                                    
                                    }
                                    
                                }
                             
                        }
                    }
                
                }
                    break;
                case'2':
                if (option[1]=='a')
                {
                    printf("root2=%c",root->item);
                    preorder(root);
                }
                break;
            case '3':
                printf("%d",answer(root));
                break;
        }
    
    
    
    }
        





}







