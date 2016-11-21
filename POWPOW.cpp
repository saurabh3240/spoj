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
#define MOD2 1000000006
#define MOD3 1000000005

#define limit 200005
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
    return test; 
}
ll arr[200005];
int main()
{	
	ll p =2;
	ll q= 500000003;
	ll invp = mod_pow(p,q-2,q);
	int t;
	gi(t);
	arr[0]=1;
	forup(i,1,limit)
		arr[i]= (arr[i-1]*i)%q;
		
	while(t--)
	{
		ll a,b,n;
		gl(a);
		gl(b);
		gl(n);
		ll zz = arr[n]*arr[n];
		zz%=q;
		ll temp = mod_pow(zz,q-2,q);
		ll exp = arr[2*n]*temp;
		exp%=q;
		exp= (exp*p*invp)%MOD2;
		
		ll xx = mod_pow(exp,b,MOD2);
		ll ans = mod_pow(a,xx,MOD);	
		pln(ans);
	}
}  



