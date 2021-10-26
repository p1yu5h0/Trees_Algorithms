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

vector<int> preorderiterative(node* root){
    /*
     * Algorithm:-
     * This is an iterative way to approach this problem
     * We use a stack instead of recursion
     * First push the root node inside the stack
     * Now till the stack becomes empty we keep on iterating
     * Since it's a preorder traversal it's (root, left, right)
     * Which means the root is printed first then the left subtree then the right subtree
     * First pushback the root node (or the current node) inside the ans array and then,
     * But since the stack is LIFO type hence we need to push the right subtree (or node) first and then push the left subtree (or node)
     * Hence on stack iteration from top to bottom we got our left subtree printed first and the right subtree printed second
     * With this algo in the end we get the correct preorder traversal
     * */
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right!= nullptr){
            s.push(temp->right);
        }
        if(temp->left!= nullptr){
            s.push(temp->left);
        }
    }
    return ans;
}

vector<int> inorderiterative(node* root){
    /*
     * Algorithm:-
     * Inorder is LEFT ROOT RIGHT
     * In case of recursion we had first go to all the left (remember), then return and then take the root node and then try right for that node
     * In recursion we just used the auxiliary stack inside the memory but in this iterative case, we will use our own stack
     * Initially we have a root node and an empty stack
     * We put that node inside the stack
     * Now remove it and check if it has any left child or not
     * Now till we reach the nullptr, we push all the left child inside the stack
     * After reaching the null ptr we just take out that element from stack and print it
     * Now we move to the right child and if it's a null, then we come back and push out the top element of stack and print it
     * Then we move to the grandparent of nullptr right and go to the right
     * We do these steps until the whole tree is covered and stack become empty
     * */
    vector<int>inorder;
    if(root==nullptr){
        return inorder;
    }
    stack<node*>st;
    while(root or !st.empty())
    {
        if(root)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            root=st.top();
            st.pop();
            inorder.push_back(root->data);
            root=root->right;
        }
    }
    return inorder;
}

vector<int> postorderiterative2stacks(node* root){
    /*
     * Algorithm:-
     * Steps :
       1. Initial config : Take the root and put it in the 1st stack.
       2. Now, take the top from the 1st stack and put it into the 2nd stack
       3. After that, if the top in 2nd stack has left → add it in 1st stack.  And if the top in 2nd stack has right → add it in the 1st stack.
       4. Now again, take the top from the 1st stack and put it into the 2nd stack. Repeat step 2 & 3 until 1st stack is empty.
       5. Pop the element from the 2nd stack and print.
     * */
    vector<int> postorder;
    stack<node*> s1, s2;
    if(root == nullptr){
        return postorder;
    }
    s1.push(root);
    while(!s1.empty()){
        auto temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!= nullptr){
            s1.push(temp->left);
        }
        if(temp->right!= nullptr){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}

//vector<int> postorderiterative1stacks(node* root){
//    do this later
//}

int maxHeightdfs(node* root) {
    /*
     * Algorithm:-
     * Simple recursive solution can be used to find the depth of a binary tree
     * Here the base case is when we reach the nullptr and return zero
     * Else for every current root, we find the maximum of the sum of right root or the left root and add 1 to it everytime
     * */
    if(root==nullptr){
        return 0;
    }
    return max(maxHeightdfs(root->left),maxHeightdfs(root->right))+1;
}

int maxHeightbfs(node* root) {
    if(root == nullptr){
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        auto size = q.size();
        count++;
        while(size--){
            auto temp = q.front();
            q.pop();
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
    }
    return count;
}

int dfsisBalanced(node* root, bool& isBalanced) {
    if(!root || !isBalanced) //if unbalanced, return for saving time, no need to check the rest of nodes
        return 0;
    int l = dfsisBalanced(root->left, isBalanced), r = dfsisBalanced(root->right, isBalanced);
    if(abs(l-r) > 1)
        isBalanced = false;
    return max(l, r) + 1;
}

bool isBalanced(node* root) {
    /*
     * Algorithm:-
     * Here if we go and check all the nodes one by one recursively, the time complexity becomes O(n^2)
     * But if we use some height of binary tree algorithm we can find that it's a balanced tree or not
     * ie. at anypoint of recursion if(abs(lh - rh) > 1) then we return -1 which means false
     * else if the recursion completes we return true;
     * */
    bool isBalanced = true;
    dfsisBalanced(root, isBalanced);
    return isBalanced;
}

int height(node* root)
{
    if(!root)return 0;
    return max(height(root->left),height(root->right))+1;
}

int diameterOfBTnaive(node* root){
    /*
     * Algorithm:-
     * The naive way to solve this problem is to go to each node and calculate the left path height + right path height
     * And in the end return the largest height you can get after comparing each and every node
     * */
    if(!root)return 0;

    int root_height=height(root->left)+height(root->right);

    int left_root_height=diameterOfBTnaive(root->left);

    int right_root_height= diameterOfBTnaive(root->right);

    return max(root_height,max(left_root_height,right_root_height));
}

int depth(node *root, int& max_dm){
    if(root)
    {
        int lt=depth(root->left, max_dm);
        int rt=depth(root->right, max_dm);

        max_dm=max(max_dm,lt+rt);

        return 1+max(lt,rt);
    }
    return 0;
}

int diameterOfBinaryTreeOptimal(node* root) {
    /*
     * Algorithm:-
     * At every step when we are calculating depth at the same time we keep tack of max of lt+rt i.e (diameter)
     * */
    int max_dm = 0;
    depth(root, max_dm);
    return max_dm;
}

bool isSameTree(node* p, node* q) {
    /*
     * Algorithm:-
     * If the trees are same then their traversals must also be same
     * Lets check here with the help of preorder traversal
     * Traversal visits each of the similar nodes in the two binary trees simultaneously and check if the value is same or not
     * */
    if(p==nullptr or q==nullptr){
        return (p==q);
    }
    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);


    return 0;
}
