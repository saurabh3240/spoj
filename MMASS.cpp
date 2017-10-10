/* user :saurabh3240
    contest : practice
    problem:  MMASS
    platform :SPOj
    date: 10-10-2017
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

//((CH)2(OH2H)(C(H))O)3    -1  26 19 13   16

ll mass(string s)
{
  stack<ll> st;

  rep(i,s.size())
  {
    if(s[i]=='(')
      st.push(-1);
    else if(s[i]=='C')
    {
      st.push(12);
    }
    else if(s[i]=='H')
    {
      st.push(1);
    }
    else if(s[i]=='O')
    {
      st.push(16);
    }
    else if(s[i]==')')
    { ll temp = 0;
      while(st.top()!=-1)
      {
          temp+=st.top();
          st.pop();
      }
      st.pop();
      st.push(temp);
    }
    else
    {
      ll x = st.top();
      st.pop();
      x*=(s[i]-'0');
      st.push(x);
    }
  }
  ll temp = 0;
    while(!st.empty())
    {
        temp+=st.top();
        st.pop();
    }

    return temp;
}

int main()
{

  string s;
  cin>>s;
  cout<<mass(s)<<endl;

}
