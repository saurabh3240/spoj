#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define limit 100005
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
#define gi(x) fastRead_int(x)
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
#define pb push_back
using namespace std;
inline void fastRead_int(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());

    if(c=='-') {
        neg = 1;
        c = getchar();
    }

    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
}
int arr[21][21];
ll  dp[21][1<<21];
int n;
ll solve(int x,int mask)
{
    // cout<<x<<" "<<mask<<endl;

    if(dp[x][mask]!=-1)
        return dp[x][mask];

    if(x<0)
        return 0;
    if(x==0)
    {
        rep(i,n)
        {
            if(mask&(1<<i))
            {
                return arr[i][0];
            }
        }
    }

    ll ans=0;
    rep(i,n)
    {
        if(arr[i][x]==1&&(mask&1<<i))
        {
            ans+=solve(x-1,mask^(1<<i));
        }
    }
    dp[x][mask]=ans;
    return ans;

}
int main()
{
    int t;
    gi(t);
    rep(i,t)
    {
        gi(n);
        rep(i,n)
            rep(j,n)
                gi(arr[i][j]);

        rep(i,n)
        {
            rep(j,1<<n)
                dp[i][j]=-1;
        }

        ll ans = solve(n-1,(1<<n)-1);
        pln(ans);
    }
}
