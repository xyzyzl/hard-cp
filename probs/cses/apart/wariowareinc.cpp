#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 200005
 
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORD(i, n) for(int i = n-1; i >= 0; i--)
#define FOBIR(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define DUEHOANG ios_base::sync_with_stdio(0); cin.tie(); cout.tie()
 
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef deque<int> di;
typedef map<int, int> mii;
#define f first
#define s second
 
int n, m, k;
vi a1;
multiset<int> a2;
int main()
{
	DUEHOANG;
	cin >> n >> m >> k;
	a1.resize(n);
	FOR(i, n)
		cin >> a1[i];
	FOR(i, m)
	{
		int a;
		cin >> a;
		a2.insert(a);
	}
	sort(a1.begin(), a1.end());
	int c=0;
	FOR(i, n)
	{
		auto a = a2.lower_bound(a1[i]-k);
		if(a != a2.end() && (*a <= (a1[i] + k)))
		{
			c++;
			a2.erase(a);
		}
	}
	cout << c << endl;
}