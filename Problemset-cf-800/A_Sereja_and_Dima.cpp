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
  for (auto &a : arr)
    cin >> a;

  int i = 0;
  int j = n - 1;
  int foo = 0;
  int bar = 0;
  int no = 1;
  while (i <= j) {
    if (arr[i] < arr[j]) {
      if (no % 2 == 0) {
        foo += arr[j];
      } else {
        bar += arr[j];
      }
      j--;
    } else {
      if (no % 2 == 0) {
        foo += arr[i];
      } else {
        bar += arr[i];
      }
      i++;
    }
    no++;
  }
  cout << bar << " " << foo;
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
