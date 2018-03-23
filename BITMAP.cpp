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
#define MOD 1000000007
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
#define pb push_back
using namespace std;


int n,m;
int dp[200][202];
string s[182];

int main()
{
    int t;
    gi(t);
    while(t--)
    {
        gi(n);
        gi(m);
        rep(i,n+2)
        {
            rep(j,m+2)
            {
                dp[i][j]=MOD;
            }
        }
        rep(i,n)
        {
            cin>>s[i];
        }
        queue<pair<int,int  > > q;
        rep(i,n)
        {
            rep(j,m)
            {
                if(s[i][j]=='1')
                {

                    q.push(make_pair(i+1,j+1));
                }
            }
        }
        int l = 0;
        while(1)
        {
            std::queue<pair<int,int> > qnew;
        //    cout<<q.size()<<" qsize "<<endl;
            while(q.size()>0)
            {
                pair<int,int> pp = q.front();
                q.pop();
                int x = pp.fs;
                int y = pp.sc;
                if(y<1|| y>m ||x<1 ||x>n)
                    continue;
            //    cout<<x<<" "<<y<<endl;
                if(dp[x][y]==MOD)
                {
                    dp[x][y]=min(l,dp[x][y]);

                    if(x+1 <= n && dp[x+1][y]==MOD)
                        qnew.push(make_pair(x+1,y));
                    if(y+1<=m && dp[x][y+1]==MOD)
                        qnew.push(make_pair(x,y+1));
                    if(x-1>=1 && dp[x-1][y]==MOD)
                        qnew.push(make_pair(x-1,y));
                    if(y-1>=1 && dp[x][y-1]==MOD)
                        qnew.push(make_pair(x,y-1));
                }
            }
            q = qnew;
            l++;
            if(q.size()==0)
                break;
        }
        rep(i,n)
        {
            rep(j,m)
                pis(dp[i+1][j+1]);
            pnl();
        }

    }
}
