#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left, *right;
    
    Node(int a) : val(a){
        left = NULL;
        right = NULL;
    }
};

void Morris(Node* root){
    if(!root) return;
    
    Node* curr = root, *pre;
    
    while(curr){
        if(!curr->left){
            cout<<curr->val<<"\t";
            curr = curr->right;
            continue;
        }
        
        pre = curr->left;
        
        while(pre && pre->right && pre->right!=curr){
            pre = pre->right;
        }
        
        if(pre->right == curr){
            pre->right = NULL;
            cout<<curr->val<<"\t";
            curr = curr->right;
            continue;
        }
        
        else{
            pre->right = curr;
            curr = curr->left;
        }
        
    }
}

int main(){
    Node* a = new Node(5);
    
    a->left = new Node(2);
    a->right = new Node(10);
    a->left->left = new Node(1);
    a->left->right = new Node(3);
    a->right->left = new Node(8);
    a->right->right = new Node(12);
     a->right->right->right = new Node(17);
    
    Morris(a);
}