
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
vector<int> edges[2005];
int visited[2005];
int dist[2005];

int n,m;
int flag=0;
void dfs(int u)
{
//    cout<<"u "<<u+1<<endl;
    visited[u]=1;
    rep(j,edges[u].size())
    {
        int v = edges[u][j];
        if(!visited[v])
        {
            dist[v] = dist[u]+1;
            dfs(v);
        }
        else  //visisted
        {

            int xx = abs(dist[v]-dist[u]-1);
            // pis(xx);
            // pis(v+1);
            // pin(u+1);
            if(xx%2==1)
            {
                flag=1;
                return;
            }
        }
    }
}
void solve()
{
    rep(i,n)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
        if(flag)
            return;
    }
}
int main()
{
    int t;
    gi(t);
    rep(i,t)
    {
    //    int n,m;
        rep(j,2005)
        {    edges[j].clear();
            visited[j]=0;
            dist[j]=0;
        }
        gi(n);
        gi(m);
        flag=0;
        rep(j,m)
        {
            int u,v;
            gi(u);
            gi(v);
            u--;
            v--;
            edges[u].pb(v);
            edges[v].pb(u);
        }
        solve();
        if(flag)
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n",i+1);

        }
        else
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n",i+1);
        }
    }

}
