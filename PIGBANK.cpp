/* user :saurabh3240
	contest : spoj
	problem: PIGBANK
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <string.h>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
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
#define pln(x) printf("%d\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
#define fs first
#define sc second
#define pb push_back
#define ll long long
#define MOD  1000000000

ll C[100006];
ll wt[100006];
ll K[100006];

ll knapSack(int W, ll wt[], ll val[], int n)
{
   int i, w;

   // Build table K[][] in bottom up manner
   // cout<<"hello"<<endl;
   // cout<<W<<endl;

   for(w=0;w<=W;w++)
    K[w]=MOD;
   for (i = 0; i <= n; i++)
   {
  //   cout<<"i= "<<i<<endl;
       for (w = 0; w <= W; w++)
       {
    //     cout<<"w= "<<w<<endl;

           if (wt[i-1] == w)
           {
             K[w] = min(val[i-1],  K[w]);
           }
           else if (wt[i-1] < w)
              K[w] = min(K[w-wt[i-1]]+val[i-1],  K[w]);
          // cout<<K[w]<<" ";

       }
       // cout<<endl;
   }
   return K[W];
}

int main()
{	int t;
	gi(t);
  while(t--)
  {
    ll E,F;
    gl(E);gl(F);
    ll W = F-E;
    int n;
    gi(n);
    ll wt[n];
    ll v[n];
    rep(i,n)
    {
      gl(v[i]);
      gl(wt[i]);
    }
    ll ans = knapSack(W, wt, v, n);
    if(ans==MOD && W!=0)
    {
      cout<<"This is impossible."<<endl;
    }
    else if(W==0)
    {
      cout<<"The minimum amount of money in the piggy-bank is "<<0<<"."<<endl;
    }
    else
    {
      cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;
    }

  }
}
