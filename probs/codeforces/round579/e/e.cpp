#include <bits/stdc++.h>
 
using namespace std;

#define MAXN 201

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
#define x first
#define y second

int w[150005];
int main()
{
    int t=1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vi v(n);
        FOR(i, n)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int a = 0;
        FOR(i, n)
        {
            if(!(w[v[i]-1] || v[i] <= 1))
            {
                a++;
                w[v[i]-1]++;
            } else if(!w[v[i]])
            {
                a++;
                w[v[i]]++;
            } else if(!(w[v[i]+1] || v[i] > 150001))
            {
                a++;
                w[v[i]+1]++;
            }
        }
        cout << a << endl;
    }
}