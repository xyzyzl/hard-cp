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

int main()
{
    int t = 1;
    cin >> t; // uncomment if it's multitest
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        viii v(5+n);
        FOBIR(i, n)
        {
            int t,l,h;
            cin >> t >> l >> h;
            v[i] = mp(t, mp(l,h));
        }
        v[0] = mp(0, mp(m, m));
        ll lo = m;
        ll hi = m;
        bool oops = 0;
        int pre = 0;
        FOBIR(i, n)
        {
            int k = v[i].f;
            // cout << k << endl;
            if(lo - k + pre <= v[i].s.s && hi + k - pre >= v[i].s.f)
            {
                lo = max(lo-k+pre, (ll)v[i].s.f);
                hi = min(hi+k-pre, (ll)v[i].s.s);
                pre = k;
            } else
            {
                oops = 1;
                break;
            }
            
        }
        if(oops) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
}