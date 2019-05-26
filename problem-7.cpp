/*
 
 Question:
 
 This problem was asked by Apple.
 
 Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
 
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
// #define f(a,n) for(auto i=a;i<n;i++)
#define mem(a,val) memset(a,val,sizeof(a))
#define x first
#define y second

using namespace std;

void func() {
    cout<<"Hi there!!!\n";
}

void job_scheduler(function<void(void)> f,int n) {
    std::this_thread::sleep_for(chrono::milliseconds(n*1000));
    f();
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
    
    
    int n; cin>>n;
    function<void(void)> f = func;
    job_scheduler(f,n);
    
    return 0;
}
