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
  int n, k;
  cin >> n >> k;
  vector<int> ar(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  int ans = 0;
  int pre = 0;

  sort(ar.begin(), ar.end());
  for (int i = 2; i <= n; i++) {
    if ((ar[i] - ar[i - 1]) <= k) {
    } else {
      ans = max((i - 1) - pre, ans);
      pre = i - 1;
    }
  }

  ans = max(n - pre, ans);

  cout << n - ans << endl;
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
