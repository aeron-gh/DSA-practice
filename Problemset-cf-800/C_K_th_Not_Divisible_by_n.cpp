#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
  int n, k;
  cin >> n >> k;
  int i = 0;
  int j = k + 1;
  int tar = -1;
  while (i <= j) {
    int mid = (i + j) / 2;
    if (n + ((n - 1) * mid) > k) {
      j = mid - 1;
    } else {
      i = mid + 1;
      tar = mid;
    }
  }
  //   cout << tar << endl;
  cout << tar + 1 + k << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
