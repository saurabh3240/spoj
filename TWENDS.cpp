#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
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
int dp[1002][1002];
int n;
int arr[1002];
int ans =0;

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
int call(int l,int r)
{
    int t = n-r+l;
    if(l>r)
        return 0;
    if(l==r)
    {
        dp[l][r]=-arr[l];
        return dp[l][r];
    }
    if(dp[l][r]!=-1)
        return dp[l][r];
    else
    {   if(t%2==1)
        {
            if(arr[l]>=arr[r])
            {
                dp[l][r] = -arr[l]+call(l+1,r);
            }
            else
            {
                dp[l][r] = -arr[r]+call(l,r-1);
            }
            return dp[l][r];
        }
        else
        {
            int x = max(arr[l]+call(l+1,r),arr[r]+call(l,r-1));
            dp[l][r]=x;
                return x;

        }
    }
}
int main()
{
    rep(i,1002)
    {
        rep(j,1002)
            dp[i][j]=-1;
    }
    gi(n);
    rep(i,n)
        gi(arr[i]);
    cout<<call(0,n-1)<<endl;;
}
