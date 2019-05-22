/* 
	
	Question : 

	This problem was recently asked by Google.

	Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

	For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

	Bonus: Can you do this in one pass?

*/


/* 

	Approach : 
	
	We'll do it in one pass by using hash table

	For every a[i] chech whether x - a[i] exists in hash table

	If Yes, break the loop

	insert a[i] otherwise

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

int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	ll T;
	cin>>T;
	//cin.ignore(); // must be there when using getline(cin, s)
	while(T--)
	{ 
		ll n,x; cin>>n>>x;
		ll a[n];
		f(0,n) cin>>a[i];
		unordered_set<ll> s;
		bool found = false;
		f(0,n) {
			ll diff = x - a[i];
			if(diff>0 and s.find(diff)!=s.end()) {
				found = true;
				break;
			}
			s.insert(a[i]);
		}
		if(found)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}