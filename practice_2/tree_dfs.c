#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct TreeNode
{
    int num;
    struct TreeNode *right;
    struct TreeNode *left;
};

typedef struct TreeNode node;
typedef node *link;

link creat_node (int data){
    link newnode;
    newnode=(link)malloc(sizeof(node));
    newnode->num=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void DFS (link root){
    if(root==NULL){
        return;
    }

    printf("%d ", root->num);
    DFS(root->left);
    DFS(root->right);
}

int main(){
    link root=creat_node(1);
    root->left=creat_node(2);
    root->right=creat_node(3);
    root->left->left=creat_node(4);
    root->left->right=creat_node(5);
    root->right->left=creat_node(6);
    
    DFS(root);

    return 0;
}