
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

int B,N;
int cost[101];
int fun[101];

int dp[501][101];



int main()
{


    while(1)
    {
        gi(B);
        gi(N);

        if(B==0&&N==0)
            break;

        rep(i,N)
        {
            gi(cost[i+1]);
            gi(fun[i+1]);
        }
        int mxans=0;
        int bug=0;
        rep(j,N+1)
        {
            rep(w,B+1)
            {
                if(w==0||j==0)
                    dp[w][j]=0;
                else if(cost[j]>w)
                    dp[w][j] = dp[w][j-1];
                else
                    dp[w][j] = max(dp[w][j-1],fun[j]+dp[w-cost[j]][j-1]);

                if(mxans<dp[w][j])
                {
                    mxans = dp[w][j];
                    bug =w;
                }
                else if(mxans==dp[w][j])
                {
                    bug = min(bug,w);
                }
            }

        }
        pis(bug);
        pin(mxans);
    }

}
