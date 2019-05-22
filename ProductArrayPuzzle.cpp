/* 
	
	Question : 

	This problem was asked by Uber.

	Given an array of integers, return a new array such that each element at index i 

	of the new array is the product of all the numbers in the original array except the one at i.

	For example, 

	if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. 

	If our input was [3, 2, 1], the expected output would be [2, 3, 6].

	Follow-up: what if you can't use division?

*/


/* 

	Approach : 

	Construct two arrays left and right each of size n.

	left[i] contains product of all the elements to the left of a[i] excluding a[i].

	Similarly, right[i] contains product of all the elements to the right of a[i] excluding a[i].

	To get the result, multiply corresponding elements in left and right 

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

// End of template

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	ll T;
	cin>>T;
	//cin.ignore(); // must be there when using getline(cin, s)
	while(T--)
	{ 
		ll n; cin>>n;
		ll a[n],left[n],right[n];
		
		f(0,n) cin>>a[i];           // input done

		left[0] = right[n-1] = 1;  // initialise first and last element of left and right to 1 respectively
		
		// constructing left array
		f(1,n) {
			left[i] = left[i-1]*a[i-1];
		}

		// constructing right array
		for(ll i=n-2;i>=0;i--) {
			right[i] = right[i+1]*a[i+1];
		}

		// printing the output
		f(0,n) {
			cout<<left[i]*right[i]<<" ";
		}
		cout<<std::endl;
	}
	return 0;
}