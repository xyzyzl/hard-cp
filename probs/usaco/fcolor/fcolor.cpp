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

int n, m, p[MAXN], sz[MAXN];
vi adj[MAXN];
vi groups;
qi q;
int find_set(int i)
{
    return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j)
{
    int x = find_set(i);
    int y = find_set(j);
    if (x == y)
        return false;
    p[x] = p[y] = x;
    sz[x] += sz[y];
    adj[x].insert(adj[x].end(), adj[y].begin(), adj[y].end());
    adj[y].clear();
    if(adj[x].size() >= 2) q.push(x);
    return true;
}

void init()
{
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < n; i++) sz[i] = 1;
}

void read()
{
	// cerr << "y" << endl;
	cin >> n >> m;
	// cerr << "ye" << endl;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
	}
	init();
	// cerr << "yes" << endl;
}

void solve()
{
	// add all of the elements admired by > 2 cows into the list
	// qi adm;
	FOR(i, n)
	{
		if(adj[i].size() >= 2) q.push(i);
	}
	while(q.size())
	{
		int x = q.front();
		// cerr << x << endl;
		if(adj[x].size() <= 1)
		{
			q.pop();
			continue;
		}
		int a = adj[x].back();
		adj[x].pop_back();
		int b = adj[x].back();
		if(p[a] == p[b]) continue;
		// merge the nodes
		union_set(a, b);
	}
	vi sets(n);
	FOR(i, n) sets[i] = find_set(i);
	vi vis(n), val(n);
	int ct = 0;
	vi ans(n);
	FOR(i, n)
	{
		if(vis[sets[i]])
		{
			ans[i] = val[sets[i]];
		} else 
		{
			val[sets[i]] = ++ct;
			ans[i] = val[sets[i]];
			vis[sets[i]] = 1;
		}
	}
	FOR(i, n) cout << ans[i] << endl;
}

int main()
{
	fileio("fcolor.in", "fcolor.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		// cerr << "huh" << endl;
		read();
		solve();
	}
	
}