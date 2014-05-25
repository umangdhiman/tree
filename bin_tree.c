#include <stdio.h>
#include<stdlib.h>
#define SIZE 10
struct stack_a{
   int arr[SIZE];
   int tos;
};
int stack_NOT_empty(struct stack_a *st){
   if(st->tos==-1)
       return 0;
   else
       return 1;
}
struct treenode{
   struct treenode *left;
   int info;
   struct treenode *right;
};
void push_stack(struct stack_a *st,struct treenode **x){
   st->tos++;
   st->arr[st->tos]=*x;
}
int pop_stack(struct stack_a *st){
   int x;
   x=st->arr[st->tos];
   st->tos--;
   return x;
}
void insert_node(struct treenode **tp,int x){
   struct treenode *p,*r,*s;
   p=(struct treenode **)malloc(sizeof(struct treenode *));
   p->info=x;
   p->left=NULL;
   p->right=NULL;
   if(*tp==NULL){
       *tp=p;
   }
   else{
       r=s=*tp;
       while(r!=NULL){
           s=r;
           if(x>r->info){
               r=r->right;
           }
           else{
               r=r->left;
           }
       }
       if(x>s->info){
           s->right=p;
       }
       else{
           s->left=p;
       }
   }
}
void delete_treenode(struct treenode **tp,int a){
   struct treenode *r,*s,*t,*x,*y,*z;
   r=s=*tp;
   while(r!=NULL&&r->info!=a){
       s=r;
       if(a>r->info){
           r=r->right;
       }
       else{
           r=r->left;
       }
   }
   if(r==NULL){
       printf("Item not found\n");
   }
   else if(r->left==NULL&&r->right==NULL){
       if(r==s){
           *tp=NULL;
       }
       else{
           if(s->info>r->info){
               s->left=NULL;
           }
           else{
               s->right=NULL;
           }
       }
   }
   else if(r->left!=NULL&&r->right==NULL||r->right!=NULL&&r->left==NULL){
       if(s==r){
           if(r->left!=NULL)
               *tp=r->left;
           else
               *tp=r->right;
       }
       else{
           if(r->left!=NULL){
               t=r->left;
               if(r==s->left){
                   s->left=t;
               }
               else{
                   s->right=t;
               }
           }
           else{
               t=r->right;
               if(r==s->left){
                   s->left=t;
               }
               else{
                   s->right=t;
               }
           }
       }
   }
   else{
       x=y=z=r->right;
       while(z!=NULL){
           x=y;
           y=z;
           z=z->left;
       }
       if(x!=y){
           x->left=y->right;
           y->left=r->left;
           y->right=r->right;
       }
       if(x==y){
           if(a>s->info){
               s->right=y;
           }
           else{
               s->left=y;
           }
           y->left=r->left;
       }
       if(r==s){
           *tp=y;
       }
       if(s!=r){
           if(r==s->left){
               s->left=y;
           }
           else{
               s->right=y;
           }
       }
   }
}
void in_traverse(struct treenode *tp){
   if(tp!=NULL){
       in_traverse(tp->left);
       printf("%d\n",tp->info);
       in_traverse(tp->right);
   }
}
void pre_traverse(struct treenode *tp){
   if(tp!=NULL){
       printf("%d\n",tp->info);
       pre_traverse(tp->left);
       pre_traverse(tp->right);
   }
}
void post_traverse(struct treenode *tp){
   if(tp!=NULL){
       post_traverse(tp->left);
       post_traverse(tp->right);
       printf("%d\n",tp->info);
   }
}
int main()
{
   struct stack_a s;
   int choice,ele;
   struct treenode *tree=NULL;
   s.tos=-1;
   while(1){
       printf("Enter 1 to insert\n,2 to delete\n,3 to traverse inorder\n,4 preorder\n,5 postorder\n,6 to exit\n");
       scanf("%d",&choice);
       switch(choice){
       case 1:
           printf("Enter an element to insert\n");
           scanf("%d",&ele);
           insert_node(&tree,ele);
           break;
       case 2:
           printf("Enter a no. to delete\n");
           scanf("%d",&ele);
           delete_treenode(&tree,ele);
           break;
       case 3:
           in_traverse(tree);
           break;
       case 4:
           pre_traverse(tree);
           break;
       case 5:
           post_traverse(tree);
           break;
       case 6:
           exit(0);
       }
   }
   return 0;
}

