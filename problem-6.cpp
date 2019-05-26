/*
 
 Question:
 
    This problem was asked by Google.
 
    A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
 
    Given the root to a binary tree, count the number of unival subtrees.
 
    For example, the following tree has 5 unival subtrees:
 
            0
           / \
          1   0
         / \
        1   0
       / \
      1   1
 
 */

#include <bits/stdc++.h>

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pl pair<ll,ll>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define in(a) for(auto k:a)
#define f(a,n) for(auto i=a;i<n;i++)
#define mem(a,val) memset(a,val,sizeof(a))
#define x first
#define y second

using namespace std;


class Node {
public:
    int value;
    Node *left,*right;
    
    Node(int value) {
        this->value = value;
        this->left = this->right = NULL;
    }
    
};

bool countUnivalUtil(Node *root,int &count) {
    
    if(root == NULL)
        return true;
    
    bool isLeftUnival = countUnivalUtil(root->left,count);
    bool isRightUnival = countUnivalUtil(root->right,count);
    
    if(!isLeftUnival or !isRightUnival)
        return false;
    
    if(root->left!=NULL and root->left->value!=root->value)
        return false;
    
    if(root->right!=NULL and root->right->value!=root->value)
        return false;
    
    count++;
    return true;
}


int countUnival(Node* root) {
    int count=0;
    
    countUnivalUtil(root,count);
    
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    // ll T;
    // cin>>T;
    //cin.ignore(); // must be there when using getline(cin, s)
    // while(T--)
    // {
    
    // }
    
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->left = new Node(1);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(1);
    root->right->right = new Node(0);
    
    int count = countUnival(root);
    cout<<count<<endl;
    
    return 0;
}
