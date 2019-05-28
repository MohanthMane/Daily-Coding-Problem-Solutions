/*
 
 Question :
 
 This problem was asked by Twitter.
 
 Implement an autocomplete system. That is, given a query string s and a set of all possible query strings,
 
 return all strings in the set that have s as a prefix.
 
 For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
 
 Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
 
*/


// We're going to use a trie for easy accessing of strings.


#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> res;


class TrieNode {
    
public:
    
    TrieNode* child[26];
    bool end;
    
    TrieNode() {
        this->end = false;
        for (int i = 0; i < 26; i++) {
            this->child[i] = NULL;
        }
    }
    
};

void insert(TrieNode* root,string key) {
    TrieNode* it = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i]-'a';
        if(it->child[index]==NULL)
            it->child[index] = new TrieNode();
        
        it = it->child[index];
    }
    
    it->end = true;
}

bool search(TrieNode* root,string key) {
    TrieNode* it = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if(it->child[index] == NULL)
            return false;
        it = it->child[index];
    }
    return (it and it->end);
}

void autoCompleteUtil(struct TrieNode* root, char str[], int level)
{
    if (root->end)
    {
        str[level] = '\0';
        string s = str;
        res.push_back(s);
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            str[level] = i + 'a';
            autoCompleteUtil(root->child[i], str, level + 1);
        }
    }
}

void autoComplete(TrieNode* root,string query) {
    TrieNode* it = root;
    for (int i = 0; i < query.length(); i++) {
        int index = query[i] - 'a';
        if(it->child[index] == NULL)
            return;
        it = it->child[index];
    }
    char str[100];
    autoCompleteUtil(it,str,0);
}

int main() {
    ll n; cin>>n;
    cin.ignore();
    string a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    
    string query;
    cin>>query;
    // input done
    
    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; i++) {
        insert(root,a[i]);
    }
    // preprocessing done
    
    autoComplete(root,query); // logic starts here
    for(string s: res) {
        cout<< (query + s) << " ";
    }
    cout<<endl;
    return 0;
}

