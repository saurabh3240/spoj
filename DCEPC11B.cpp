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
 
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
 
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 1000006
long long mod_pow(ll num, ll pow, ll mod)
{
   ll test;
    ll n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
        	test = (test*n)%mod;
        n = (n*n)%mod;
    }
    return test; /* note this is potentially lossy */
}
int main()
{	int t;
	gi(t);
	while(t--)
	{	ll n, p;
		gl(n);	
		gl(p);
		if(p<=n)
			printf("0\n");
		else
		{	ll ans = p-1;
			for(int i=n+1;i<p;i++)
			{	ans*=mod_pow(i,p-2,p);
				ans%=p;
			}
			printf("%lld\n",ans);	
		}		
	}
}  



