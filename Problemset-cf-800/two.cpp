#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<int> fa(101, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    fa[a]++;
  }

  int cnt = 0;
  while (cnt != n) {
    for (int i = 100; i >= 0; i--) {
      if (fa[i] != 0) {
        cout << i << " ";
        fa[i]--;
        cnt++;
      }
    }
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
