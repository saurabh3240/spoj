/* user :saurabh3240
    contest : spoj practicee
    problem:  POUR1
    platform :spoj
    date: 28-02-2017
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

int readint()
    {
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ret = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ret = ret * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ret;
   }


unsigned long long mod_pow(unsigned long long num, unsigned long long pow, unsigned long long mod)
{
    unsigned long long test;
    unsigned long long n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}

ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;
		a = b;
		b = r;
	}
	return a;
}
map<pair<int,int>,int > mp;
int a,b,c;
int bfs(int x,int y)
{
	queue<vector<int> > q;
	vector<int> v;
	v.pb(x);
	v.pb(y);
	v.pb(0);
	q.push(v);
	mp[make_pair(0,0)]=1;
	while(q.size())
	{	
		vector<int> v = q.front();
		int i  = v[0];
		int j = v[1];
		int k = v[2];
		//cout<<i<<" "<<j<<" "<<k<<endl;
		if(i==c||j==c)
			return k;
		else
		{	// push in queue
			q.pop();

			pair<int,int> p = make_pair(v[0],v[1]);
			{
				mp[p]=1;
				//empty first vessel
				if(i!=0)
				{
					vector<int> temp;
					i = 0;
					temp.pb(i);
					temp.pb(j);
					temp.pb(k+1);
					pair<int,int> pp(i,j);
					if(!mp[pp])
					{
						q.push(temp);
					}
					mp[pp]=1;
				}
				i  = v[0];
				j = v[1];
				k = v[2];
				// empty second vessel
				if(j!=0)
				{
					vector<int> temp;
					j = 0;
					temp.pb(i);
					temp.pb(j);
					temp.pb(k+1);
					pair<int,int> pp(i,j);
					if(!mp[pp])
					{
						q.push(temp);
					}
					mp[pp]=1;

				}
				// fill first vessel
				i  = v[0];
				j = v[1];
				k = v[2];
				
				if(i!=a)
				{
					vector<int> temp;
					i = a;
					temp.pb(i);
					temp.pb(j);
					temp.pb(k+1);
					pair<int,int> pp(i,j);
					if(!mp[pp])
					{
						q.push(temp);
					}
					mp[pp]=1;
				}
				// fill second vessel
				i  = v[0];
				j = v[1];
				k = v[2];
				
				if(j!=b)
				{
					vector<int> temp;
					j = b;
					temp.pb(i);
					temp.pb(j);
					temp.pb(k+1);
					pair<int,int> pp(i,j);
					if(!mp[pp])
					{
						q.push(temp);
					}
					mp[pp]=1;	
				}
				i  = v[0];
				j = v[1];
				k = v[2];
					
				// porting from i to j
					
				//	from i to j
				{
				
					vector<int> temp;
					int tt = j;
					j = min(j+i,b);
					tt = j-tt;
					i = i-tt;
					temp.pb(i);
					temp.pb(j);
					temp.pb(k+1);
					pair<int,int> pp(i,j);
					if(!mp[pp])
					{
						q.push(temp);
					}
					mp[pp]=1;

				}
				i  = v[0];
				j = v[1];
				k = v[2];

				//	from j to i
				{
				
					vector<int> temp;
					int tt = i;
					i = min(i+j,a);
					tt = i-tt;
					j = j-tt;
					temp.pb(i);
					temp.pb(j);
					temp.pb(k+1);
					pair<int,int> pp(i,j);
					if(!mp[pp])
					{
						q.push(temp);
					}
					mp[pp]=1;

				}
				i  = v[0];
				j = v[1];
				k = v[2];
			
			}
		}
	}
	return -1;

}
int main()
{
	int t;
	gi(t);
	while(t--)
	{
		gi(a);
		gi(b);
		gi(c);
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(c>a&&c>b)
		{
			pin(-1);
		}
		else
		{
			mp.clear();
			int x = bfs(0,0);
			pin(x);	
		}
	}
	
}
