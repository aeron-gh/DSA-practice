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
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }
  if (mp.size() == 1) {
    cout << "YES" << endl;
    return;
  }

  if (mp.size() > 2) {
    cout << "NO" << endl;
    return;

  } else {
    vector<int> mpp;
    for (auto a : mp) {
      mpp.push_back(a.second);
    }
    if (mpp[0] == mpp[1] or (mpp[0] + 1 == mpp[1]) or (mpp[0] == mpp[1] + 1)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
