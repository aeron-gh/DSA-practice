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
  vector<int> arr(26, 0);
  for (int i = 0; i < n; i++) {
    char a;
    cin >> a;
    arr[a - 'a']++;
  }
  vector<int> vec;
  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 != 0) {
      vec.push_back(arr[i]);
    }
  }

  int sz = vec.size();
  int cnt = sz - 1;
  // sort(vec.begin(), vec.end());
  // for (int i = 0; i < sz - 1; i++) {
  //   cnt += 1;
  // }
  if (k >= cnt) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
