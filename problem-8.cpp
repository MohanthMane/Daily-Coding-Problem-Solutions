/*
 
 Question:
 
 This problem was asked by Airbnb.
 
 Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
 
 Numbers can be 0 or negative.
 
 For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.
 
 [5, 1, 1, 5] should return 10, since we pick 5 and 5.
 
 Follow-up: Can you do this in O(N) time and constant space?
 
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

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll T;
    cin>>T;
    cin.ignore(); // must be there when using getline(cin, s)
    while(T--)
    {
        ll n; cin>>n;
        ll a[n];
        f(0,n) cin>>a[i];
        int include_i = a[0],exclude_i = 0;
        f(1,n) {
            int temp = max(include_i,exclude_i);
            include_i = exclude_i + a[i];
            exclude_i = temp;
        }
        cout<<max(include_i,exclude_i)<<std::endl;
    }
    return 0;
}

