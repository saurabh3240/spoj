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
ll a[2][2],b[2][2],c[2][2];

void matrixmul(ll F[2][2],ll M[2][2])
{
		ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
	  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
	  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
	 ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
	 
	  F[0][0] = x%MOD;
	  F[0][1] = y%MOD;
	  F[1][0] = z%MOD;
	  F[1][1] = w%MOD;
}


long long mat_pow( ll pow)
{
    ll test[2][2] = {{1,1},{1,0}};
    ll n[2][2] = {{1,1},{1,0}};
    if(pow==0)
    	return 0;
    if(pow==1)
    	return 1;
	pow-=2;
    for(; pow; pow >>= 1)
    {
        if (pow & 1)
        	matrixmul(test,n);
        matrixmul(n,n);
    }
    return test[0][0]; /* note this is potentially lossy */
}
//// 0 1 2 3 4 5 6 7 
//// 0 1 1 2 3 5 8
bool p[10000004];
int dp[10000004];

int main()
{	int t;
	p[0]=1;
	p[1]=1;
	for(int i=2;i<10000004;i++)
	{
		if(p[i]==0)
		{
			for(int j = i+i;j<10000004;j+=i)
				p[j]=1;
			dp[i]= dp[i-1]+1;
	
		}
		else
			dp[i]=dp[i-1];
	}
	//cout<<"helo"<<endl;
	gi(t);
	while(t--)
	{	
		int n;
		gi(n);
		int mid = n/2;
		int ans = n-mid;
		//pin(ans);
		int z = dp[n]-dp[mid];
		//pin(z);
		ans = min(ans,z);
		pin(ans);
	}
}  



