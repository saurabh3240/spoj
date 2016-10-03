/* user :saurabh3240
    contest : VISA
    problem:  
    platform :HCAKERRANK
    date: 23-11-2015
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
#include<unordered_map>
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
#define INF 1000000000
#define ull unsigned long long
using namespace std;
ull mod_pow(ull num, ull pow, ull mod)
{
    ull test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
//while((getchar())!='\n'); //buffer clear
ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;a = b; b = r;
	}
	return a;
}

char haystack[1005];
ll hashed[1005];
ll prime =31;
ll power[1005];

int main()
{	
	int t;
	gi(t);
	power[0]=1;
	for(int i=1;i<1005;i++)
		power[i] = (power[i-1]*prime)%MOD;
		
	while(t--)
	{
		haystack[0]='a';
		scanf("%s",(haystack+1));
		int n = strlen(haystack)-1;
		hashed[0]='a';
		for(int i=1;i<=n;i++)
			hashed[i]= (hashed[i-1]+(haystack[i]*power[i])%MOD)%MOD;
		
		
		map<ll,int> mp;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n-i;j++)
			{
//				cout<<j<<" "<<j+i<<endl;
				ll temp = (hashed[j+i]-hashed[j]+MOD)%MOD;
				temp*=power[n-j-i];
				temp%=MOD;
				mp[temp]++;			
			}	
		}	
	
		pin(mp.size());
	}
}

