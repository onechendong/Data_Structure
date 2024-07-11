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

link insert_node (link root, int val){
    
    if(root==NULL){
        return creat_node(val);
    }
    else{
        if(root->num>val){
            root->left= insert_node(root->left, val);
        }
        else if(root->num<val){
            root->right= insert_node(root->right, val);
        }
        return root;
    }
}

//中序
void inorder(link ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%2d ", ptr->num);
        inorder(ptr->right);
    }
}

//前序
void preorder(link ptr){
    if(ptr!=NULL){
        printf("%2d ", ptr->num);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

//後續
void postorder(link ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%2d ", ptr->num);
    }
}

int main(){

    int array[]={7, 4, 1, 5, 16, 8, 11, 12, 15, 9, 2};
    link ptr=NULL;
    size_t s=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<s;i++){
        ptr=insert_node(ptr, array[i]);  //遞迴
    }

    printf("中序: \n");
    inorder(ptr);
    printf("\n\n");
    printf("前序: \n");
    preorder(ptr);
    printf("\n\n");
    printf("後序: \n");
    postorder(ptr);
    
    system("pause");

    return 0;
}