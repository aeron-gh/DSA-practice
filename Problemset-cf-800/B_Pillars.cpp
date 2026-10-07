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

  for (int &x : arr) {
    cin >> x;
  }
  int idx = -1;
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (mx < arr[i]) {
      mx = arr[i];
      idx = i;
    }
  }

  for (int i = 1; i <= idx; i++) {
    if (arr[i] <= arr[i - 1]) {
      cout << "no";
      return;
    }
  }

  for (int i = idx + 1; i < n; i++) {
    if (arr[i] >= arr[i - 1]) {
      cout << "no";
      return;
    }
  }

  cout << "yes";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  //   cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
