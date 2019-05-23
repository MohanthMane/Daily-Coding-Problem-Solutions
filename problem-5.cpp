/*
 
 Question:
 
 This problem was asked by Facebook.
 
 Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
 
 count the number of ways it can be decoded.
 
 For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
 
 You can assume that the messages are decodable. For example, '001' is not allowed.
 
*/

/*
 
 Approach:
 
 This can be solved using recursion. But, time complexity is exponential.
 
 This code can be solved in linear time using dynamic programming
 
*/

/*
 
 Time complexity : O(n)
 Space complexity : O(n)
 
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

int func(string s,int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        if (s[i-1] > '0')
        dp[i] = dp[i-1];
        
        if (s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7'))
        dp[i] += dp[i-2];
    }
    return dp[n];
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll T;
    cin>>T;
    //cin.ignore(); // must be there when using getline(cin, s)
    while(T--)
    {
        string s; cin>>s;
        // cout<<s.length()<<endl;
        cout<<func(s,s.length())<<endl;
    }
    return 0;
}
