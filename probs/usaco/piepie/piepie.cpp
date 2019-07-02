/**
ID: albert.28
LANG: C++14
PROB: piepie
**/

/// Time:

#include <bits/stdc++.h>

/**
Mod operations in O(lg n)
Source: Benjamin Qi, https://github.com/bqi343/USACO/blob/master/Implementations/11%20-20(4)/Operators/modOp.cpp?fbclid=IwAR0m2afS-1xVg9kgeF8q8EJIeP9TP3Lct8dYb_hPJuI5gqHP1Utp5EkiOQ8
**/

using namespace std;

#define MAXN 100005
#define MOD 1000000007

#define FOR(g,i,n) for(int i = g; i < n; i++)
#define FORD(g,i,n) for(int i = g; i >= n; i--)

#define apple() ios_base::sync_with_stdio(0)
#define hentai() cin.tie(); cout.tie()

#define mp make_pair
#define pb push_back
#define	ll long long
// #define int ll
#define INF (1e9*1)+5
#define LL_INF (1e18*1)+5
#define bitinc(s) (s&-s)
#define endl '\n'

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
#define f first
#define s second
typedef vector<pii> vii;
typedef set<pii> sii;
typedef map<pii, pii> mii;

void fileio(char* in, char* out)
{
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}

namespace modOp
{
    int ad(int a, int b, int mod = MOD) { return (a+b)%mod; }
    int sub(int a, int b, int mod = MOD) { return (a-b+mod)%mod; }
    int mul(int a, int b, int mod = MOD) { return (ll)a*b%mod; }

    int AD(int& a, int b, int mod = MOD) { return a = ad(a,b,mod); }
    int SUB(int& a, int b, int mod = MOD) { return a = sub(a,b,mod); }
    int MUL(int& a, int b, int mod = MOD) { return a = mul(a,b,mod); }

    int po (int b, int p, int mod = MOD) { return !p?1:mul(po(mul(b,b,mod),p/2,mod),p&1?b:1,mod); }
    int inv (int b, int mod = MOD) { return po(b,mod-2,mod); }

    int invGeneral(int a, int b) { // 0 < a < b, gcd(a,b) = 1
        if (a == 0) return b == 1 ? 0 : -1;
        int x = invGeneral(b%a,a);
        return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
    }
}

using namespace modOp;

int n, d, a[2*MAXN], b[2*MAXN], dist[2*MAXN];

struct ja
{
	bool operator()(int p, int q) const
	{
		return b[p] < b[q];
	}
};

struct jb
{
	bool operator()(int p, int q) const
	{
		return a[p] < a[q];
	}
};

multiset<int, ja> A;
multiset<int, jb> B;

queue<int> q;

int main()
{
	fileio("piepie.in", "piepie.out");
	cin >> n >> d;
	FOR(0, i, 2*n)
	{
		int x, y;
		cin >> x >> y;
		a[i] = -x;
		b[i] = -y;
		dist[i] = -1;
	}
	FOR(0, i, n)
	{
		if(b[i] == 0)
		{
			dist[i] = 1;
			q.push(i);
		} else A.insert(i);
		if(a[n+i] == 0)
		{
			dist[n+i] = 1;
			q.push(n+i);
		} else B.insert(n+i);
	}
	// cout << q.size() << endl;
	multiset<int, ja>::iterator rb1;
	multiset<int, jb>::iterator rb2;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		// cout << f << endl;
		if(f >= n) while(true) // currently on Elsie's pie and trying to give to Bessie
		{
			rb1 = A.lower_bound(f);
			// cout << *rb1 << " A" << endl;
			if(rb1 == A.end() || b[*rb1] > b[f]+d) break;
			dist[*rb1] = dist[f]+1;
			q.push(*rb1);
			A.erase(rb1);
		} else while(true) // currently on Bessie's pie and trying to give to Elsie
		{
			rb2 = B.lower_bound(f);
			// cout << *rb2 << " B" << endl;
			if(rb2 == B.end() || a[*rb2] > a[f]+d) break;
			dist[*rb2] = dist[f]+1;
			q.push(*rb2);
			B.erase(rb2);
		}
	}
	for(int i = 0; i < n; i++) cout << dist[i] << endl;
}
