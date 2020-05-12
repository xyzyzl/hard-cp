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

vi find_subset(int l, int u, vi w)
{
	int n = w.size();
	vii nw(n);
	FOR(i, n)
	{
		nw[i] = mp(w[i], i);
	}
	sort(nw.begin(), nw.end());
	// you need indices so you kinda can't do this!
	// sort(w.begin(), w.end());
	int i = 0, j = 0;
	ll rsm = 0;
	vi ans;
	while(i < n)
	{
		while(i < n && rsm < (ll)l)
		{
			rsm += (ll)nw[i].f;
			i++;
		}
		while(j < i && rsm > (ll)u)
		{
			rsm -= (ll)nw[j].f;
			j++;
		}
		if((ll)l <= rsm && rsm <= (ll)u)
		{
			// this is good
			for(int k = j; k < i; k++) ans.pb(nw[k].s);
			break;
		}
	}
	// are you supposed to put the subset in inc order too or smth
	// whatever
	sort(ans.begin(), ans.end());
	return ans;
}
signed main()
{
	DUEHOANG;
	int t = 1;
	// cin >> t; // uncomment if it's multitest
	while(t--)
	{
		vi v;
		v = find_subset(15, 17, { 6,8,8,7 });
		for(int x : v) cout << x << " ";
		cout << endl;
		
		v = find_subset(14, 15, { 5,5,6,6 });
		for(int x : v) cout << x << " ";
		cout << endl;
		
		v = find_subset(10, 20, { 15,16,17,18 });
		for(int x : v) cout << x << " ";
		cout << endl;
		
	}
	
}
