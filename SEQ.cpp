
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
#define MOD 1000000000
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
vector<vector<ll> > multiply(vector<vector<ll> > A , vector<vector<ll>> B)
{
    int k = A.size();
    vector<std::vector<ll> >C;
    rep(a,k)
    {
        std::vector<ll> v;
        rep(b,k)
        {
            ll x=0ll;
            rep(c,k)
            {
                x+=(A[a][c]*B[c][b])%MOD;
                x%=MOD;
            }
            v.pb(x);
        }
        C.pb(v);
    }
    return C;

}
vector<vector<ll>>  powerf(vector<vector<ll>> F, ll n,vector<ll> c)
{
    int  k = F.size();

     vector<std::vector<ll> > M;
     rep(i,k)
     {   std::vector<ll> v;
           rep(j,k)
           {
               v.pb(0ll);
           }
           M.pb(v);
    }
    rep(i,k)
       M[0][i]=c[i]%MOD;

    forup(i,1,k)
       M[i][i-1]=1ll;

    if( n == 0 || n == 1)
        return M;

    F=powerf(F, n/2,c);
    F=multiply(F, F);
    if (n%2 != 0)
        F=multiply(F, M);
    return F;
}

ll solve(vector<ll> b, vector<ll> c,int n)
{
int k = c.size();
 vector<std::vector<ll> > F1,F2;

 rep(i,k)
{   std::vector<ll> v;
    rep(j,k)
    {
        v.pb(0);
    }
    F1.pb(v);
}
 rep(i,k)
    F1[0][i]=c[i]%MOD;

 forup(i,1,k)
    F1[i][i-1]=1ll;

  F2 = powerf(F1,n,c);

  // rep(i,k)
  // {
  //     rep(j,k)
  //       pls(F2[i][j]);
  //    pnl();
  // }
 ll ans =0;
 rep(i,k)
 {
     // pls(F2[0][i]);
     // pln(b[k-i-1]);
     ans += F2[0][i]*b[k-i-1];
     ans%=MOD;
 }
 return ans;

}
int main()
{
    int t;
    gi(t);
    while(t--)
    {
        int k;
        gi(k);
        ll x;
        std::vector<ll> c,b;
        rep(i,k)
        {
            gl(x);
            b.pb(x);
        }
        rep(i,k)
        {
            gl(x);
            c.pb(x);
        }
        int n;
        gi(n);
        if(n<=k)
            pln(b[n-1]);
        else
        {
            ll ans = solve(b,c,n-k);
            pln(ans%MOD);
        }
        //cout<<"END OF CASE"<<endl;
    }
}
