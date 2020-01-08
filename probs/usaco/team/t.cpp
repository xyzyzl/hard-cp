// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1005
#define MAXK 15

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOBIR(i, n) for (int i = 1; i <= n; i++)
#define FOBIRD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)

#define fileio(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout);

#define ll long long
#define INF (1e9*1)+5
#define MOD (ll)((1e9*1)+9)

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
typedef vector<iii> viii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second

#define LEFT(x) 2 * x
#define RIGHT(x) 2 * x + 1

#define bitinc(x) x&-x

const int MAX(int &a, int b)
{
    return a = max(a, b); 
}
const int MIN(int &a, int b)
{
    return a = min(a, b); 
}

int n, m, k, a[MAXN], b[MAXN];
ll dp[MAXN][MAXN], ar[MAXN][MAXN];
int main()
{
    DUEHOANG;
    fileio("team.in", "team.out");
    int t = 1;
    // cin >> t; // uncomment if it's multitest
    while(t--)
    {
        cin >> n >> m >> k;
        FOR(i, n) cin >> a[i];
        FOR(i, m) cin >> b[i];
        sort(a, a+n);
        sort(b, b+m);
        FOR(i, n+1) FOR(j, m+1)
        {
            dp[i][j] = 1; // state 0
        }
        FOR(x, k)
        {
            memset(ar, 0, sizeof(ar));
            FOR(i, n) FOR(j, m)
            {
                if(a[i] > b[j]) ar[i+1][j+1] += dp[i][j];
            }
            FOR(i, n+1) FOR(j, m+1)
            {
                dp[i][j] = ar[i][j];
            }
            FOR(i, n+1) FOR(j, m+1)
            {
                // note that every group that consists of things before i, j from the previous iteration can be used in the current
                // set, we should reflect that in the current
                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
                if(i && j) dp[i][j] -= dp[i-1][j-1];

                dp[i][j] = (dp[i][j] % MOD + MOD) % MOD; // ensure modulo 100000007
            }
        }
        cout << dp[n][m] % MOD << endl;
    }
}