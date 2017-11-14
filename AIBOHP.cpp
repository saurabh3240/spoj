/* user :saurabh3240
    contest : codechef march long
    problem:  STRPALIN
    platform :Codechef
    date: 06-03-2016
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
#define limit 1000006
int prime[limit];

int solve(string s)
{
    string r = s;
    reverse(r.begin(),r.end());
    int n = s.size();
    int dp[n+1][n+1];
    rep(i,n)
    {
        dp[i][0]=dp[0][i]=0;
    }

    forup(i,1,n+1)
    {
        forup(j,1,n+1)
        {
            if(s[i-1]==r[j-1])
            {
                dp[i][j]=  dp[i-1][j-1]+1;
            }
            else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][n];
}
int main()
{
    int t;
    string s;
    gi(t);
    while(t--)
    {
        cin>>s;
        cout<<solve(s)<<endl;;
    }


}
