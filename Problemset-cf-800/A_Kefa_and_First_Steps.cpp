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
  if (n == 1) {
    cout << n;
    return;
  }
  int arr[n];
  for (auto &a : arr) {
    cin >> a;
  }
  int foo = 1;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] <= arr[i + 1]) {
      foo++;
    } else {
      foo = 1;
    }
    ans = max(foo, ans);
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
