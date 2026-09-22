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

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> dp(n, 1);
  vector<int> par(n, -1);

  int ans = 1;
  int last = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        par[i] = j;
      }
    }

    if (dp[i] > ans) {
      ans = dp[i];
      last = i;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << par[i] << " ";
  }
  vector<int> res;

  while (last != -1) {
    res.push_back(arr[last]);
    last = par[last];
  }

  reverse(res.begin(), res.end());

  // cout << ans << endl;

  for (int x : res) {
    // cout << x << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}
