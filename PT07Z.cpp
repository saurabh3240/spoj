/* user :saurabh3240
    contest : 101 Hack Jun 2015
    problem:  A
    platform :hackerrank
    date: 22-06-2015
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

int n;
vector<int> edges[10001];
bool visited[10001];
int dist[10001];
int current_dist =0;
int maxans =0;
int dfs(int u)
{
    visited[u]=true;
    dist[u]=current_dist;
    vector<int> vv;
    rep(i,edges[u].size())
    {
        int v =edges[u][i];
        current_dist++;
        if(!visited[v])
        {
            int x = dfs(v);
            vv.pb(x);
        }
        current_dist--;
    }
    int mx =-1;
    int vsize = vv.size();
    sort(vv.begin(),vv.end());
    if(vv.size()==0)
    {
        return dist[u];
    }
    if(vv.size()==1)
    {
        maxans = max(maxans,vv[0]-dist[u]);
        return vv[0];
    }
    else
    {
        //top 2
        maxans = max(maxans,vv[vsize-1]+vv[vsize-2]-2*dist[u]);
        return vv[vsize-1];
    }
}

int main()
{   gi(n);
    rep(i,n-1)
    {
        int x,y;
        gi(x);
        gi(y);
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dfs(1);
    // cout<<"hello"<<endl;
    // rep(j,n)
    // {
    //     pin(dist[j+1]);
    // }
pin(maxans);
}
