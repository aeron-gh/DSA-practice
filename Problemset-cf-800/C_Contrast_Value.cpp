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
  int n;
  cin >> n;
  int ar[n];
  for (int &a : ar) {
    cin >> a;
  }
  bool f = true;
  for (int i = 0; i < n - 1; i++) {
    if (ar[i] != ar[i + 1]) {
      f = false;
    }
  }
  if (f) {
    cout << 1 << endl;
    return;
  }
  vector<int> arr;
  for (int i = 0; i < n - 1; i++) {
    if (ar[i] == ar[i + 1]) {

    } else {
      arr.push_back(ar[i]);
      // arr.push_back(ar[i + 1]);
      // i++;
    }
  }
  arr.push_back(ar[n - 1]);
  int ans = 0;
  n = arr.size();
  for (int i = 1; i < n - 1; i++) {
    if (arr[i - 1] < arr[i] and arr[i + 1] < arr[i]) {
      ans++;
    } else if (arr[i - 1] > arr[i] and arr[i + 1] > arr[i]) {
      ans++;
    }
  }

  if (ans == 0) {
    cout << 2 << endl;
    return;
  }
  cout << ans + 2 << endl;
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
