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
  int arr[n];
  for (int &a : arr) {
    cin >> a;
  }

  vector<int> can(n + 1, INT_MAX);
  vector<int> par(n, -1);
  vector<int> idx(n + 1, -1);
  can[0] = INT_MIN;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int a = arr[i];
    auto it = lower_bound(can.begin(), can.end(), a);
    int pos = it - can.begin();
    *it = a;
    idx[pos] = i;
    if (pos > 1) {
      par[i] = idx[pos - 1];
    }
    ans = max(ans, pos);
  }
  int j = idx[ans];
  vector<int> v;
  while (j != -1) {
    v.push_back(arr[j]);
    j = par[j];
  }

  reverse(v.begin(), v.end());
  cout << ans << endl;

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
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
