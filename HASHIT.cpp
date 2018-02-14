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
int tot=0;
int table[101];
string table2[101];
int hashed(string s)
{   ll h=0;
    rep(i,s.size())
    {
        h +=s[i]*(i+1);
        h%=101;
    }
    h *=19;
    h %=101;
    return h;
}
int rehash(string s)
{
    int k = hashed(s);
    forup(i,1,20)
    {
        int z = k+i*i+23*i;
        z%=101;
        if(table[z]==-1)
            return z;
    }
    return -1;
}
map<string,int> mp2;

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
        int n;
        cin>>n;
        rep(i,101)
        {
            table[i]=-1;
            table2[i]="@@";
        }
        tot  =0;
        string str;
        rep(i,n)
        {
            cin>>str;
            if(str[0]=='A')
            {
                str  =  str.substr(4);
                // cout<<str<<endl;
                int dup =0;
                rep(i,101)
                {
                    if(str.compare(table2[i])==0)
                    {
                        dup =1;
                        break;
                    }
                }
                if(dup)
                    continue;
                int k = hashed(str);
                //pin(k);
                if(mp2[str]==1)
                    continue;
                if(table[k]==-1) // add
                {
                    table[k]=1;
                    table2[k]=str;
                    tot++;
                //    cout<<"Add1"<<endl;
                }
                else // rehash
                {
                    int k2 = rehash(str);
                 //  cout<<"rehash"<<k2<<endl;

                    if(k2!=-1)
                    {
                        table[k2]=1;
                        table2[k2]=str;
                        tot++;
                    //    cout<<"ADED"<<endl;

                    }
                }
            }
            else
            {
                str  =  str.substr(4);
                // cout<<str<<endl;
                int k2 = hashed(str);

            //    cout<<"delete ";
                //pin(k2);
                if(table[k2]==1 && str.compare(table2[k2])==0) //delete it
                {
                    table[k2]=-1;
                    tot--;
                    table2[k2]="@@";

            //        cout<<"hua"<<endl;
                }
                else
                {
                    forup(i,1,20)
                    {
                        int z = k2+i*i+23*i;
                        z%=101;
                        if(table[z]==1&& str.compare(table2[z])==0 )
                        {
                            table[z]=-1;
                            tot--;
                            table2[z]="@@";
                //            cout<<"hua2"<<endl;
                            break;
                        }
                    }

                }
            }

        }
        cout<<tot<<endl;
        rep(i,101)
        {
            if(table[i]==1)
                cout<<i<<":"<<table2[i]<<endl;
        }
	}
	return 0;
}
