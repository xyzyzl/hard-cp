// Time:
// Algorithms: 

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define MAXN 200005

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

int n, a[MAXN];
ll L, d[MAXN];
int dp[MAXN][20];
void read()
{
	DUEHOANG;
	cin >> n >> L;
	a[0] = 1;
	dp[0][0] = dp[200004][0] = 200004;
	F1R(i, n-1)
	{
		int par;
		ll dist;
		cin >> par >> dist;
		--par;
		d[i] = d[par] + dist;
		dp[i][0] = par;
		F1R(j, 18)
		{
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
		int x = i;
		FORD(j, 19)
		{
			if(d[i] - d[dp[x][j]] <= L)
			{
				// this is currently in range... try again
				// but with different x
				x = dp[x][j];
			}
		}
		// if(x == 0) cout << dp[x][0] << endl;
		// cerr << dp[x][0] << endl;
		a[i]++;
		a[dp[x][0]]--; // counteract psum-on-tree thing
	}

}

void solve()
{
	// cout << a[0] << endl;
	FORD(i, n)
	{
		// cout << dp[i][0] << endl;
		a[dp[i][0]] += a[i];
		// cout << a[dp[i][0]] << endl;
	}
	FOR(i, n)
	{
		cout << a[i] << endl;
	}
}

int main()
{
	fileio("runaway.in", "runaway.out");
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		read();
		solve();
	}
	
}
