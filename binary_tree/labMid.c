#include<stdio.h>
#include<stdlib.h>


struct node{
    int roll;
    float cgpa;
    float total;
    float mathnum;
    float socionum;
    float engnum;
    struct node *left;
    struct node *right;
};
struct node *create(struct node *root,int roll,float cgpa,float total,float mathnum,float socionum,float engnum)
{
        if(root==NULL)
        {
            struct node *newnode;
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->roll=roll;
            newnode->cgpa=cgpa;
            newnode->total=total;
            newnode->mathnum=mathnum;
            newnode->socionum=socionum;
            newnode->engnum=engnum;
            newnode->left=NULL;
            newnode->right=NULL;
            return newnode;
        }
    
    if(cgpa < root->cgpa)
    {
       root->left=create(root->left,roll,cgpa,total,mathnum,socionum,engnum);
    }
    else if(cgpa > root->cgpa)
    {
       root->right=create(root->right,roll,cgpa,total,mathnum,socionum,engnum);
    }
    else if(cgpa==root->cgpa)
    {
              if(total < root->total)
                {
                root->left=create(root->left,roll,cgpa,total,mathnum,socionum,engnum);
                }
                else if(total>root->total)
                {
                root->right=create(root->right,roll,cgpa,total,mathnum,socionum,engnum);
                }
                 else if(total==root->total)
                {
                                             if(mathnum < root->mathnum)
                                                {
                                                root->left=create(root->left,roll,cgpa,total,mathnum,socionum,engnum);
                                                }
                                                else if(mathnum>root->mathnum)
                                                {
                                                root->right=create(root->right,roll,cgpa,total,mathnum,socionum,engnum);
                                                }
                                                 else if(mathnum==root->mathnum)
                                                {
                                                            
                                                            if(socionum < root->socionum)
                                                                {
                                                                root->left=create(root->left,roll,cgpa,total,mathnum,socionum,engnum);
                                                                }
                                                                 else if(socionum>root->socionum)
                                                                {
                                                                root->right=create(root->right,roll,cgpa,total,mathnum,socionum,engnum);
                                                                }
                                                                 else if(socionum==root->socionum)
                                                                {
                                                                                   
                                                                            if(engnum < root->engnum)
                                                                                {
                                                                                root->left=create(root->left,roll,cgpa,total,mathnum,socionum,engnum);
                                                                                }
                                                                                else if(engnum>root->engnum)
                                                                                {
                                                                                root->right=create(root->right,roll,cgpa,total,mathnum,socionum,engnum);
                                                                                }
                                                                                else if(engnum==root->engnum)
                                                                                {
                                                                                                  
                                             if(roll < root->roll)
                                                {
                                                root->left=create(root->left,roll,cgpa,total,mathnum,socionum,engnum);
                                                }
                                                else if(roll>root->roll)
                                                {
                                                root->right=create(root->right,roll,cgpa,total,mathnum,socionum,engnum);
                                                }
                
                                             }
                                 }
                                                    
                         }
                    
                }
    }
    return root;

} 

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \n",root->roll);
        inorder(root->right);
    }
}




int main()
{
    FILE *file=fopen("input.txt","r");
    struct node *root;
    root=0;
    for(int i=0;i<10;i++)
    {
        int r;
        float c,m,s,e;
        float t=0;
        fscanf(file,"%d %f %f %f %f",&r,&c,&m,&s,&e);
        t=m+s+e;
        root=create(root,r,c,t,m,s,e);
    }
    inorder(root);
}