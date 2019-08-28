#include <bits/stdc++.h>
 
#pragma GCC optimize ("O3")

using namespace std;

#define MAXN 100005

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define x first
#define y second

int n, a[MAXN];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	DUEHOANG;
	cin >> n;
	FOR(i, n) cin >> a[i];
	sort(a, a+n);
	int mn = INT_MAX;
	FOR(i, n)
	{
		int j = (upper_bound(a, a+n, a[i]*2) - a);
		// cout << j << endl;
		mn = min(i+(n-j), mn);
	}
	cout << mn << endl;
}