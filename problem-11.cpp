/*
 
 Question:
 
 This problem was asked by Amazon.
 
 Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
 
 For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
 
 */

#include<bits/stdc++.h>

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

// RECURSIVE WAY
int solve(string s,int start,int end,int k) {
    if(end - start == 1) {
        return 1;
    } else {
        unordered_map<char,int> m;
        f(start,end+1) {
            m[s[i]]++;
        }
        int map_size = m.size();
        m.clear();
        if(map_size<=k) {
            return end-start+1;
        } else {
            return max(solve(s,start+1,end,k),
                       solve(s,start,end-1,k));
        }
    }
}

// USING HASHMAP (EFFICIENT)
void func(string s,int k) {
    unordered_map<char,int> m;
    f(0,s.length()) m[s[i]]++;
    int unique = m.size();
    int res = 0;
    int i = 0,j = s.length()-1;
    if(unique<=k) {
        cout<<j-i+1<<endl;
        return;
    } else {
        unordered_map<char,int> window_map;
        int start,end;
        start = end = 0;
        while(start<s.length() and end<s.length()) {
            // cout<<"{DEBUG INFO} : ADDING "<<s[end]<<endl;
            window_map[s[end]]++;
            if(window_map.size()>k) {
                res = max(res,end-start);
                while(start<s.length() and window_map.size()>k) {
                    window_map[s[start]]--;
                    if(window_map[s[start]]==0) {
                        window_map.erase(s[start]);
                    }
                    start++;
                }
            }
            end++;
        }
        cout<<res<<endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll T;
    cin>>T;
    cin.ignore(); // must be there when using getline(cin, s)
    while(T--)
    {
        string s; cin>>s;
        int k; cin>>k;
        cout<<solve(s,0,s.length()-1,k)<<endl;
        func(s,k);
    }
    return 0;
}

