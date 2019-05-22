/*

    Question :

    This problem was asked by Stripe.

    Given an array of integers, find the first missing positive integer in linear time and constant space. 

    In other words, find the lowest positive integer that does not exist in the array. 

    The array can contain duplicates and negative numbers as well.

    For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

    You can modify the input array in-place.
     
*/


/*
    Approach :

    As we have to find the smallest positive integer excluding zero, 

    we'll store the element a[i] at (i-1)th position i.e; swap a[i] with a[a[i]-1]

    We don't perform swap operation when a[i]<=0 and a[i]>=n

    Finally, the first index i where i+1!=a[i] gives us the solution i.e; i+1

    If we reach end of the array and yet to find a solution then the answer is n+1
 
*/


/*
 
 Time complexity : O(n)
 Space complexity : O(1)
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

ll solve(ll A[],ll n) {
    
    for (int i = 0; i < n; i++) {
        while (A[i] != i + 1) {
            if (A[i] <= 0 || A[i] >= n)
                break;
            
            if(A[i]==A[A[i]-1])
                break;
            
            int temp = A[i];
            A[i] = A[temp - 1];
            A[temp - 1] = temp;
        }
    }
    
    for (int i = 0; i < n; i++){
        if (A[i] != i + 1){
            return i + 1;
        }
    }
    
    return n+1;
    
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll T;
    cin>>T;
    //cin.ignore(); // must be there when using getline(cin, s)
    while(T--)
    {
        ll n; cin>>n;
        ll A[n];
        cout<<solve(A,n)<<endl;
    }
    return 0;
}
