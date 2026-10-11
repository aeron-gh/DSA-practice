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
  vector<pair<int, int>> ar(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ar[i].first = a;
    ar[i].second = i;
  }
  sort(ar.begin(), ar.end());
  if (ar[0].first != ar[1].first) {
    cout << ar[0].second + 1 << endl;
  } else {
    cout << ar[n - 1].second + 1 << endl;
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
