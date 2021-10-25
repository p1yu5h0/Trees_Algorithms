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

vector<vector<int>> levelOrder(node* root) {
    /*
     * Algorithm:-
     * To store the level order traversal level wise we need a queue data structure and a 2d array
     * Each of the row of the 2d array contains the value of all the nodes in that level
     * Queue ds initially have the root in it
     * Now we start traversing over the queue and take out the front node first(initially the root node)
     * Now if left of that node exists we push that inside the queue and then if the right exists, we push that too inside the queue
     * After completing all the nodes of that level and putting their children inside the queue, we push all the parents on that level inside a vector
     * In the end of that level we push that level array (1D) inside our ans array (2D)
     * We do this process for all the nodes ie. till the queue finally become empty
     * In the end the answer 2D vector is the final level order or bfs traversal of the given tree
     * */
    vector<vector<int>> ans;
    if(root == nullptr){
        return ans;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        while(size--){
            node* temp = q.front();
            q.pop();
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    return 0;
}
