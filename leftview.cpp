#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left, *right;
    
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
} ;

void leftview(Node* root, int level, int* maxlevel){
    if(!root) return;
    
    if(level > *maxlevel){
        cout<<root->val<<"\t\t";
        *maxlevel = level;
    }
    
    leftview(root->left, level+1, maxlevel);
    leftview(root->right, level+1, maxlevel);
    
    return;
}


int main()
{
    Node* root = new Node(12); 
    root->left = new Node(10); 
    root->right = new Node(30); 
    root->right->left = new Node(25); 
    root->right->right = new Node(40); 
    
    
    int maxlevel = 0;
    leftview(root, 1, &maxlevel);
    
    
    
    
   return 0;
}