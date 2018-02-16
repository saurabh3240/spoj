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
int N, Q;

// Variables, that hold current "state" of computation
int current_answer;

unordered_map<int,int> cnt;

// Array to store answers (because the order we achieve them is messed up)
int answers[200002];
int BLOCK_SIZE;
int arr[30003];

// We will represent each query as three numbers: L, R, idx. Idx is
// the position (in original order) of this query.
pair< pair<int, int>, int> queries[200002];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// When adding a number, we first nullify it's effect on current
// answer, then update cnt array, then account for it's effect again.
inline void add(int x)
{
    cnt[x]++;
    if(cnt[x]==1)
        current_answer++;
}

// Removing is much like adding.
inline void remove(int x)
{
    if(cnt[x]==1)
        current_answer--;
    cnt[x]--;
}

int main()
{
    cin.sync_with_stdio(false);
    cin >> N ;
    BLOCK_SIZE = static_cast<int>(sqrt(N));

    // Read input array
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    // Read input queries, which are 0-indexed. Store each query's
    // original position. We will use it when printing answer.
    cin>>Q;

    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    // Sort queries using Mo's special comparator we defined.
    sort(queries, queries + Q, mo_cmp);

    // Set up current segment [mo_left, mo_right].
    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < Q; i++) {
        // [left, right] is what query we must answer now.
        int left = queries[i].first.first;
        int right = queries[i].first.second;

        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right > right) {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(arr[mo_left]);
        }

        // Store the answer into required position.
        answers[queries[i].second] = current_answer;
    }

    // We output answers *after* we process all queries.
    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}
