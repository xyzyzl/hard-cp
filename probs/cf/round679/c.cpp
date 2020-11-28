#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // pbds
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#pragma GCC optimize("O3")

using namespace __gnu_pbds;
using namespace std;

#define MAXN 200005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define endl '\n'
#define DUEHOANG                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL);                \
	cout.tie(NULL)

#define fileio(in, out)      \
	freopen(in, "r", stdin); \
	freopen(out, "w", stdout);

#define ll long long
#define int ll
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

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
// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
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

int a[6], b[MAXN];
pii dp[MAXN][6][6];
int n;
void solve()
{
	FOR(i, 6) cin >> a[i];
	sort(a, a+6);
	cin >> n;
	FOR(i, n) cin >> b[i];
	sort(b, b+n);
	FOR(i, n) FOR(j, 6) FOR(k, 6) dp[i][j][k] = mp(0, 1e15);
	FOR(i, 6) FOR(j, i+1) dp[0][i][j] = mp(b[0]-a[i], b[0]-a[i]);
	F1R(i, n-1) 
	{
		FOR(j, 6) FOR(k, j+1)
		{
			vii v;
			FOR(l, k+1) v.pb(mp(min(dp[i-1][k][l].f, b[i]-a[j]), max(dp[i-1][k][l].s, b[i]-a[j])));
			int mn = LLONG_MAX;
			int ind = 0;
			FOR(l, k+1) 
			{
				int m = v[l].s-v[l].f;
				if(m < mn)
				{
					ind = l;
				}
				MIN(mn, m);
			}
			dp[i][j][k] = mp(min(dp[i-1][k][ind].f, b[i]-a[j]), max(dp[i-1][k][ind].s, b[i]-a[j]));
		}
	}
	int df = INT_MAX;
	FOR(i, 6) FOR(j, 6) 
	{
		df = min(df, dp[n-1][i][j].s - dp[n-1][i][j].f);
	}
	cout << df << endl;
}

signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
