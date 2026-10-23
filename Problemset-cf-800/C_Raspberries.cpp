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
  int arr[n];
  int ans = INT_MAX;
  int foo = 0;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0) {
      foo++;
    }
    if (arr[i] % k != 0) {
      ans = min(k - arr[i] % k, ans);
    } else {
      ans = 0;
    }
  }
  if (k == 4) {
    if (foo >= 2) {
      ans = 0;
    } else if (foo == 1) {
      ans = min(ans, 1);
    } else if (foo == 0) {
      ans = min(ans, 2);
    }
  }
  cout << ans << endl;
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
