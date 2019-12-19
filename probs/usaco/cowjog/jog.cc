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

typedef set<int> si;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> iii;
typedef vector<pii> vii;
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
    a = max(a, b); 
}
const int MIN(int &a, int b)
{
    a = min(a, b); 
}

int n;
ll t;
vector<ll> x;

int main()
{
    fileio("cowjog.in", "cowjog.out");
    cin >> n >> t;
    FOR(i, n)
    {
        ll pos, spd;
        cin >> pos >> spd;
        ll m = (-(pos + t*spd));
        if(x.empty() || m >= *x.rbegin())
        {
            x.pb(m);
        } else 
        {
            *upper_bound(x.begin(), x.end(), m) = m;
        }
    }
    cout << x.size() << endl;
}