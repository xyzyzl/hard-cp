// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(j, i, n) for (int i = j; i < n; i++)
#define FORD(i, n) for (int i = n - 1; i >= 0; i--)
#define F1R(i, n) for (int i = 1; i <= n; i++)
#define F1RD(i, n) for (int i = n; i >= 1; i--)
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
	int h, g;
	cin >> h >> g;
	int n = (1 << h) - 1, m = (1 << g) - 1;
	vii v(n);
	FOR(i, n)
	{
		cin >> v[i].f;
		v[i].s = i+1;
	}
	sort(v.begin(), v.end());
	vi vis(n+1);
	vi del(n+1);
	ll ans = 0ll;
	for(auto p : v)
	{
		int x = p.s;
		while(x > m || vis[x])
		{
			x /= 2;
		}
		if(!x) continue;
		if(vis[LEFT(x)] == vis[RIGHT(x)])
		{
			vis[x] = 1;
			ans += p.f;
			del[p.s] = 1;
		}
	}
	cout << ans << endl;
	F1RD(i, n)
	{
		if(!del[i]) cout << i << " ";
	}
	cout << endl;
}

int main()
{
	DUEHOANG;
	// fileio("d1c.in", "d1c.out");
	int t = 1;
	cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
