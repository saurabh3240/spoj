
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
vector<int> getBinVector(unsigned ll x)
{
	vector<int> v,vr;
	while(x)
	{
		v.pb(x&1);
		x>>=1;
	}
	int n = v.size();
	rep(i,n)
	{
		vr.pb(v[n-i-1]);
	}
	return vr;

}

ull ncr[70][70];
vector<int> dp[70];
int prime[70];

unsigned long long getcount(int size,int c)
{
	unsigned ll ans =0ull;
	rep(i,dp[c].size())
	{	
		int z = dp[c][i];
		if(z>size)
			break;
		if(z>0)
			ans+=ncr[size][z];
		//	cout<<ncr[size][z]<<" "<<"---"<<size<<" "<<z<<endl;;
	}
	//cout<<endl;
	return ans;
}
int main()
{	
	ncr[0][0]=1ull;
	ncr[1][0]=1ull;
	ncr[1][1]=1ull;
	
	for(int i=2;i<67;i++)
	{
		ncr[i][0]=1;		
		for(int j =1;j<=i;j++)
		{
			ncr[i][j] =ncr[i-1][j-1]+ncr[i-1][j];
	//		cout<<ncr[i][j]<<" ";
		}
	}
	
	prime[0]=1;
	prime[1]=1;
	for(int i=2;i<70;i++)
	{
		if(prime[i]==0)
		{
			for(int j =i+i;j<70;j+=i)
				prime[j]=1;
	
		}
	}
	
	
	for(int i=0;i<67;i++)
	{
		for(int j=0;i+j<67;j++)
		{
			if(!prime[i+j])
			{
				dp[i].pb(j);
			}
		}
	}
	
//	rep(i,34)
//	{
//		cout<<i<<" "<<__builtin_popcount(i)<<endl;
//	}
	int t;
	gi(t);
	while(t--)
	{
		unsigned ll l,r;
		scanf("%llu",&l);
		scanf("%llu",&r);
		l = l-1ull;
		vector<int> vl,vr;
		vl = getBinVector(l);
		vr = getBinVector(r);
		int count =0;
		int prev =0;
		int n = vl.size();
		unsigned ll ansl =0ull;
		for(int i=0;i<vl.size();i++)
		{
		 	if(vl[i]==1)
		 	{
				if(prev==0)
					ansl+=getcount(n-i,count);
				count++;
			}
			else
			{
				if(prev==1)
				{
					ansl-=getcount(n-i,count);
					
				}
			}	
			prev = vl[i];
		}
		
		//cout<<ansl<<endl;
		count =0;
		prev =0;
		n = vr.size();
		unsigned ll ansr =0ull;
		for(int i=0;i<vr.size();i++)
		{
		 	if(vr[i]==1)
		 	{
				if(prev==0)
					ansr+=getcount(n-i,count);
				count++;
			}
			else
			{
				if(prev==1)
				{
					ansr-=getcount(n-i,count);
					
				}
			}	
			prev = vr[i];
		}
		cout<<ansr-ansl<<endl;
	}
}

