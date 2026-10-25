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
  vector<pair<int, int>> vec;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a % k != 0) {
      vec.push_back({a % k, i});
    } else {
      vec.push_back({k, i});
    }
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < vec.size(); i++) {
    mp[vec[i].first].push_back(vec[i].second);
  }
  vector<int> ans;
  for (auto a : mp) {
    sort(a.second.begin(), a.second.end());
    reverse(a.second.begin(), a.second.end());

    for (int i = 0; i < a.second.size(); i++) {
      ans.push_back(a.second[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
