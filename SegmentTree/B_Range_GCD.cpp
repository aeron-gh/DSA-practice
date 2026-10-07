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

struct Node {
  int g;
  //   int val;
  //   int mn = INT_MAX;
  //   int mx = INT_MIN;
};

Node operator+(Node a, Node b) {
  Node ans;
  ans.g = gcd(a.g, b.g);
  return ans;
}

template <typename T> struct SegTree {
  T *tree;
  const int n;
  const T identity;

private:
#define mid ((tL + tR) >> 1)
#define lcId ((tId << 1) + 1)
#define rcId lcId + 1
#define leftChild lcId, tL, tM
#define rightChild rcId, tM + 1, tR

  void update(int tId, int tL, int tR, int idx, T val) {
    if (tL == tR) {
      tree[tId] = val;
      return;
    }

    int tM = mid;

    if (idx <= mid)
      update(leftChild, idx, val);
    else
      update(rightChild, idx, val);

    tree[tId] = tree[lcId] + tree[rcId];
  }

  T query(int tId, int tL, int tR, int l, int r) {
    if (l > tR or r < tL)
      return identity;
    if (l <= tL and tR <= r)
      return tree[tId];
    int tM = mid;
    return query(leftChild, l, r) + query(rightChild, l, r);
  }

#undef mid
#undef lcId
#undef rcId
#undef leftChild
#undef rightChild
public:
  SegTree(int n, T identity) : n(n), identity(identity) {
    tree = new T[4 * n];
    for (int i = 0; i < 4 * n; ++i) {
      tree[i] = identity;
    }
  }

  void update(int idx, T val) { update(0, 0, n - 1, idx, val); }

  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

void solve() {

  int n, m;
  cin >> n >> m;
  int a[n];
  for (auto &i : a)
    cin >> i;

  SegTree<Node> st(n, Node());

  for (int i = 0; i < n; i++) {
    st.update(i, Node({a[i]}));
  }

  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, val;
      cin >> i >> val;
      i--;
      st.update(i, Node({val}));

    } else {
      int l, r;
      cin >> l >> r;
      r--;
      l--;
      cout << st.query(l, r).g << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
