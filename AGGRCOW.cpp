/* user :saurabh3240
    contest : 101 Hack Jun 2015
    problem:  A
    platform :hackerrank
    date: 22-06-2015
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
#define limit 10000005
 
 
int main()
{	
	int t;
	gi(t);
	while(t--)
	{
		int n,k;
		gi(n);
		gi(k);
		int arr[n];
		rep(i,n)
			gi(arr[i]);
		sort(arr,arr+n);
	
		{
			// do a  binary search 
			int st = 0;
			int end = arr[n-1];
			int mid;
			while(st<end)
			{	mid = (st+end)/2;
				//pis(mid);pis(st);pin(end);
				int temp = arr[0];
				int count=1;
				for(int i=1;i<n;i++)
				{
					if(arr[i]-temp>=mid)
					{
						count++;
						temp = arr[i];	
 
					}		
				}
			///	pin(count);			
				if(count>=k)
				{
					st = mid+1;
				}
				else
				{
					end = mid;
				}		
			}
		//	pis(mid);pis(st);pin(end);
			
			pin(st-1);
			
		}	
	
	}             
}