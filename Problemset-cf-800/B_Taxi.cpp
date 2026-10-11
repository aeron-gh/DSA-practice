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
  if (mp[1] >= mp[3]) {
    mp[1] -= mp[3];
  } else {
    mp[1] = 0;
  }

  if (mp[2] % 2 == 0) {
    mp[4] += mp[2] / 2;
    mp[2] = 0;
  } else {
    mp[4] += (mp[2] / 2);
    mp[2] = 1;
  }

  if (mp[1] != 0 and mp[2] != 0) {
    mp[1]--;
    mp[1]--;
    mp[2]--;
    mp[4]++;
  }

  for (auto &a : mp) {
    if (a.second < 0) {
      a.second = 0;
    }
  }
  mp[1] = (mp[1] + 3) / 4;
  int cnt = 0;
  for (auto a : mp) {
    cnt += a.second;
  }

  cout << cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
