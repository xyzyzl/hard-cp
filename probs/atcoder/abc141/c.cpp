#include <bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

int n, k, q;
int ans[100005];
int main() {
  cin >> n >> k >> q;
  for(int i = 0; i < q; i++) {
    int wadiya;
    cin >> wadiya;
    wadiya--;
    ans[wadiya]++;
  }
  for(int i = 0; i < n; i++) {
    cout << ((q-ans[i] < k) ? "Yes" : "No") << endl;
  }
}
