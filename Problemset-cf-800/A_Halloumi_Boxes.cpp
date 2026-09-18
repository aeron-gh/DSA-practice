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
  for (int &a : arr) {
    cin >> a;
  }

  if (k > 1) {
    cout << "YES" << endl;
  } else {
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
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
