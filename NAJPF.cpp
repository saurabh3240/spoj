/* user :saurabh3240
    problem:  NAJPF
    date: 04-03-2016
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
#define limit 1000006


char haystack[1000006];
ll hashed[1000006];
ll prime   = 71l;
ll power[ 1000006];

char needle[1000006];
ll hashed_needle;

bool OK(int i)
{
	int j = 0;
	int m = strlen(needle);
	while(j<m)
	{
		if(needle[j]!=haystack[i])
		{
				return false;
		}
		j++;
		i++;
	}
	if(j==m)
		return true; 
	else
		return false;
}
int main()
{	
	int t;
	gi(t);
	
	power[0]=1;
	for(int i=1;i<1000006;i++)
		power[i] = (power[i-1]*prime)%MOD;

	
	while(t--)
	{
		scanf("%s",haystack);
		scanf("%s",needle);
		
		int n = strlen(haystack);
		rep(i,n)
		{
			haystack[i]=haystack[i]-'a';
		}
		hashed[0]=haystack[0]; 
		
		for(int i=1;i<n;i++)
			hashed[i]=(hashed[i-1]+(power[i]*haystack[i])%MOD )%MOD;
		
		int m = strlen(needle);
		rep(i,m)
			needle[i]=needle[i]-'a';
	
		hashed_needle = needle[0];
		
		for(int i=1;i<m;i++)
			hashed_needle=(hashed_needle+(power[i]*needle[i])%MOD )%MOD;
		
		vector<int> ans;
		for(int i=m-1;i<n;i++)
		{	if(i==m-1)
			{	ll comp_hashed = hashed[i];
				if(comp_hashed==hashed_needle)
				{	int x =i-m+1;
					if(OK(x))
						ans.pb(x+1); 			
				}
			}
			else
			{
				ll comp_hashed = (hashed[i]-hashed[i-m]+2*MOD)%MOD;
				ll temp_hashed = (hashed_needle*power[i-m+1])%MOD;	
				if(comp_hashed ==temp_hashed)
				{
					int x =i-m+1;
					if(OK(x))
					{
						ans.pb(x+1);
					} 	
					
				}
			}
			
		}
		if(ans.size()==0)
		{
			printf("Not Found\n\n");
		}
		else
		{
			pin(ans.size());
			rep(j,ans.size())
			{
				pis(ans[j]);	
			}	
			printf("\n\n");
		}
		
	
	}
		
}



