#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = nullptr;
    }
};

void preorderrecursive(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data;
    preorderrecursive(root->left);
    preorderrecursive(root->right);
}

void inorderrecursive(node* root){
    if(root == nullptr){
        return;
    }
    inorderrecursive(root->left);
    cout<<root->data;
    inorderrecursive(root->right);
}

void postorderrecursive(node* root){
    if(root == nullptr){
        return;
    }
    postorderrecursive(root->left);
    postorderrecursive(root->right);
    cout<<root->data;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    return 0;
}
