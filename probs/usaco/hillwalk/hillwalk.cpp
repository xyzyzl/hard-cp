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
#define MOD (1e9*1)+7
#define MOD2 998244353
#define INF (1e9*1)+5

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> iii;
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

int n;
struct pt
{
	int x1, y1, x2, y2, i;
	bool operator<(pt other) const
	{
		if(x2 < other.x2)
		{
			return (ll)(y2-other.y1)*(other.x2-other.x1) < (ll)(other.y2-other.y1)*(x2-other.x1);
		} else
		{
			return (ll)(y2-y1)*(other.x2-x1) < (ll)(other.y2-y1)*(x2-x1);
		}
		
	}
};
vector<pt> segs;
viii ev;

void solve()
{
	cin >> n;
	segs.resize(n);
	FOR(i, n)
	{
		segs[i].i=i;
		cin >> segs[i].x1 >> segs[i].y1 >> segs[i].x2 >> segs[i].y2;
		ev.pb(mp(mp(segs[i].x1, segs[i].y1), i));
		ev.pb(mp(mp(segs[i].x2, segs[i].y2), i));
	}
	int ci = 0;
	int ans = 1;
	set<pt> s0;
	sort(ev.begin(), ev.end());
	for(iii x : ev)
	{
		int id = x.s;
		if(segs[id].x1 == x.f.f) s0.insert(segs[id]);
		else
		{
			if(id != ci) s0.erase(segs[id]);
			else
			{
				auto it = s0.find(segs[id]);
				if(it == s0.begin()) break; // we have no more
				// otherwise we still have some other element
				--it;
				ci = it->i;
				ans++;
				s0.erase(s0.find(segs[id]));
			}
		}
	}
	cout << ans << endl;
}

signed main()
{
	fileio("hillwalk");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}
