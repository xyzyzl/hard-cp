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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define ll long long
#define MOD ((1e9*1)+7)
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

typedef set<ll> sl;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> lll;
typedef vector<pll> vll;
typedef vector<lll> vlll;
typedef priority_queue<ll> pql;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dl;
typedef map<ll, ll> mll;

// ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> osii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osll;
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

void solve()
{
	int n; cin >> n;
	vll a(n);
	FOR(i, n)
	{
		cin >> a[i].s >> a[i].f;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int l = 0, r = n-1;
	ll ct = 0;
	ll ans = 0;
	int j = n-1;
	FOR(i, n)
	{
		while(j > i && a[j].f <= ct)
		{
			ans += a[j].s;
			ct += a[j].s;
			--j;
		}
		if(i == j+1) break;
		while(j > i && ct + a[i].s >= a[j].f)
		{
			if(ct >= a[i].f) 
				ans += max(a[j].f-ct, 0ll);
			else 
				ans += max(a[j].f-ct, 0ll)*2;
			a[i].s -= max(a[j].f - ct, 0ll);
			ct = max(a[j].f, ct);
			ans += a[j].s;
			ct += a[j].s;
			--j;
		}
		if(a[i].f <= ct + a[i].s)
		{
			ans += max(a[i].f-ct, 0ll)*2 + min(ct+a[i].s-a[i].f, a[i].s);
			ct += a[i].s;
		} else 
		{
			ans += a[i].s*2;
			ct += a[i].s;
		}
	}
	cout << ans << endl;
}

signed main()
{
	// fileio("");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
