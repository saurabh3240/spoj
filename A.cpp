/* user :saurabh3240
    contest : practice
    problem:  PPATH
    platform :SPOj
    date: 13-01-2016
*/
 
#include <vector>
#include <list>
#include <map>
#include<unordered_map>
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
bool prime[1005];
int bfs(int x,int y)
{
	unordered_map<int,bool > vis;
	unordered_map<int,bool > level;

	queue<int> q;
	q.push(x);
	level[x]=0;
	vis[x]=true;
	
	if(x==y)
		return 0;
	else
	{
		while(!q.empty())
		{
			int p = q.front();
			q.pop();
			if(p==y&&vis[p]==true)
			{
				return level[p];
			}
			int z = p%10;
			// first digit
			for(int i=0;i<9;i++)
			{
				if(i!=z)
				{
					int n = p-z;
					n+=i;
					if(!vis[n]&&!prime[n])
					{
						cout<<"n1 "<<n<<endl;
						int g;
						cin>>g;
						q.push(n);
						vis[n]= true;
					}	
				}
			}
			z = p/10;
			z = z%10;
			// second digit
			for(int i=0;i<9;i++)
			{
				if(i!=z)
				{
					int n = p-z*10;
					n+=i*10;
					if(!vis[n]&&!prime[n])
					{
						cout<<"n2 "<<n<<endl;
						int g;
						cin>>g;

					
						q.push(n);
						vis[n]= true;

					}	
				}
			}

			z = p/100;
			z = z%10;
		// third digit
			for(int i=0;i<9;i++)
			{
				if(i!=z)
				{
					int n = p-z*100;
					n+=i*100;
					if(!vis[n]&&!prime[n])
					{

						cout<<"n3 "<<n<<endl;
						int g;
						cin>>g;

						q.push(n);
						vis[n]= true;

					}	
				}
			}
			
		
		
			z = p/1000;
			z = z%10;
			for(int i=0;i<9;i++)
			{
				if(i!=z)
				{
					int n = p-z*1000;
					n+=i*1000;
					if(!vis[n]&&!prime[n])
					{
						cout<<"n4 "<<n<<endl;
						int g;
						cin>>g;

						q.push(n);
						vis[n]= true;
					}	
				}
			}
			// fourh digit

					
			
			
		}
	
	}	
}

int  perform(int x,int y)
{
	if(x==y)
	{
		return 0;
	}
	else
	{
		return bfs(x,y);
	}
}

int main()
{
	prime[0]=true;
	prime[1]=true;
	for(int i=2;i<1005;i++)
	{
		if(prime[i]==false)
		{
			for(int j = i+i;j<1005;j+=i)
			{
				prime[j]= true;
			}
		}
	}
	int t;
	gi(t);
	while(t--)
	{
		int x,y;
		gi(x);
		gi(y);
		pin(perform(x,y));
		
	}
		
}

