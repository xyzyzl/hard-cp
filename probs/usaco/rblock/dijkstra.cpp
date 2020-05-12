// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 1000005

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

int n, m, wt[MAXN], par[MAXN];
vii adj[MAXN];

/// Set-based Dijkstra implementation.
void dijkstra(int src)
{
	fill(wt, wt + n, INF);
	fill(par, par + n, -1);

	set<pii> pq;
	pq.insert(mp(0, src));

	wt[src] = 0;

	int ct = 0;
	while (!pq.empty())
	{
		pii tp = *pq.begin();
		pq.erase(pq.begin());

		for (pii gu : adj[tp.s])
		{
			int w = gu.f;
			int ind = gu.s;
			if (wt[tp.s] + w < wt[ind])
			{
				pq.erase(mp(wt[ind], ind)); /// you can't efficiently erase with a priority queue
				/// and you're processing way too many indices
				wt[ind] = wt[tp.s] + w;
				par[ind] = tp.s;
				pq.insert(mp(wt[ind], ind));
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	FOR(i, m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adj[a].pb(mp(w, b));
		adj[b].pb(mp(w, a));
	}
	dijkstra(0);
	vi path;
	int ind = n-1;
	while(ind != -1)
	{
		path.pb(ind);
		ind = par[ind];
	}
	int old = wt[n-1];
	int best = wt[n-1];
	FOR(i, path.size()-1)
	{
		int best_i = -1;
		int best_j = -1;
		FOR(j, adj[path[i]].size())
		{
			if(adj[path[i]][j].s == path[i+1])
			{
				best_i = j;
				break;
			}
		}
		FOR(j, adj[path[i+1]].size())
		{
			if(adj[path[i+1]][j].s == path[i])
			{
				best_j = j;
				break;
			}
		}
		adj[path[i]][best_i].f *= 2;
		// cerr << adj[path[i]][best_i].f << endl;
		adj[path[i+1]][best_j].f *= 2;
		// cerr << adj[path[i+1]][best_j].f << endl;
		dijkstra(0);
		MAX(best, wt[n-1]);
		adj[path[i]][best_i].f /= 2;
		adj[path[i+1]][best_j].f /= 2;
	}
	cout << best-old << endl;
}

int main()
{
	DUEHOANG;
	fileio("rblock.in", "rblock.out");
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		solve();
	}
	
}