/* user :saurabh3240
    contest : codechef march long
    problem:  STRPALIN
    platform :Codechef
    date: 06-03-2016
*/
 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
 
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
 
#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0
 
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)
 
#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
 
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000006
int prime[limit];
ll ans[limit];



int main()
{
	int t;
	gi(t);
	while(t--)
	{
		int n;
		gi(n);
		int arr[n];

		rep(i,n)
		{
			gi(arr[i]);

		}
		if(n==1)
		{
			pin(-1);	
		}
		else
		{
			int i   = n-1;
			while(i>0)
			{
				if(arr[i]>arr[i-1])
				{
					break;
				}
				i--;
				
			}	
			if(i==0)
			{
				pin(-1);
			}
			else
			{

				int ind = i-1;
				vector<int> v;

					int j = n-1;
				int ind2,z;
				for(;j>=i;j--)
				{
					if(arr[j]>arr[ind])
					{
						z = arr[j];
						ind2 = j;
						break;
					}
	
				}
				v.pb(arr[ind]);
				for(;i<n;i++)
				{
					if(ind2!=i)
						v.pb(arr[i]);
				}		
				sort(v.begin(),v.end());
				rep(i,ind)
				{
					printf("%d",arr[i]);		
				}
				printf("%d",z);
				rep(i,v.size())
				{
					printf("%d",v[i]);
				}
					printf("\n");
			}
		}

	}
}
