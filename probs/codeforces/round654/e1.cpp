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

int n, p, a[MAXN];
void read()
{
	cin >> n >> p;
	FOR(i, n) cin >> a[i];
}

void solve()
{
	sort(a, a+n);
	int m = a[n-1];
	int n_good = 0;
	si all;
	FOR(q, 1+m)
	{
		int x = q;
		if(x > m || x < m+1-n) continue; // adds 0
		bool good = 1;
		int y = 0;
		FOR(i, n)
		{
			y = (upper_bound(a, a+n, x)) - a;
			y -= i;
			if(y <= 0) break;
			if(!(y%p))
			{
				good = 0; 
				break;
			}
			x++;
		}
		if(!y || !good) continue;
		all.insert(q);
	}
	cout << all.size() << endl;
	for(int q : all) cout << q << ' ';
	cout << endl;
}

int main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
