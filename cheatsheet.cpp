// ============================================================================
//  CP CHEATSHEET (C++17)
//  Ctrl+F the tags like [DSU], [SEGTREE], [DIJKSTRA] to jump around.
//  Everything is independent. Copy only what you need.
//  Compile: g++ -std=c++17 -O2 -Wall -Wextra -fsanitize=address,undefined x.cpp
// ============================================================================
//
//  KEYNOTES
//  --------
//  Constraint -> complexity (about 1e8 simple ops per second)
//    n <= 10        : O(n!)          permutations, brute force
//    n <= 20        : O(2^n * n)     bitmask DP, meet in the middle
//    n <= 500       : O(n^3)         Floyd-Warshall, interval DP
//    n <= 5000      : O(n^2)         simple 2D DP
//    n <= 1e5..2e5  : O(n log n)     sort, segtree, BIT, Dijkstra, binary
//    search n <= 1e6..1e7  : O(n)           sieve, two pointers, prefix sums n
//    <= 1e18      : O(log n) or O(sqrt n)   math, binary exponentiation
//
//  Common traps
//    - int overflow: use long long when a product can pass 2e9. (ll)a * b, not
//    (ll)(a * b)
//    - Mod arithmetic: (a - b + MOD) % MOD, never leave negatives
//    - Reset global arrays between test cases
//    - endl flushes (slow). Use '\n'
//    - Don't use unordered_map on Codeforces without a custom hash (anti-hash
//    tests)
//    - Off-by-one: decide half-open [l, r) or closed [l, r] once and stick to
//    it
//    - 1-indexed vs 0-indexed: write it on top of the page when you start
//    - Deep recursion (1e5+ depth) can crash on some judges, go iterative
//    - Comparators must be strict: use <, never <=, or sort() can crash
//    - Dijkstra fails on negative edges
//
//  Problem-solving checklist
//    1. Read constraints first, they hint at the intended complexity
//    2. Solve small cases by hand, find the pattern
//    3. Write a brute force, then a stress test against your fast solution
//    4. Think: sort? binary search on answer? greedy? DP? graph? prefix sums?
//    5. Check edge cases: n = 1, all equal, already sorted, max values
// ============================================================================

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ---------------------------------------------------------------- [TEMPLATE]
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const ll MOD = 1e9 + 7; // or 998244353
const ll INF = 1e18;    // safe: INF + INF still fits in ll
const int INF32 = 1e9;
const int dx4[] = {1, -1, 0, 0}, dy4[] = {0, 0, 1, -1}; // grid moves

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Debug print (only active when compiled with -DLOCAL)
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

// ======================================================================
//  1. MATH / NUMBER THEORY
// ======================================================================

// [MODPOW] binary exponentiation, O(log e)
ll power(ll b, ll e, ll m = MOD) {
  ll r = 1;
  b %= m;
  while (e > 0) {
    if (e & 1)
      r = r * b % m;
    b = b * b % m;
    e >>= 1;
  }
  return r;
}

// [MODINV] inverse when m is prime (Fermat)
ll modinv(ll a, ll m = MOD) { return power(a, m - 2, m); }

// [EXTGCD] a*x + b*y = gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll g = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
// inverse for any modulus (needs gcd(a, m) == 1), returns -1 otherwise
ll modinv_any(ll a, ll m) {
  ll x, y;
  if (extgcd(a, m, x, y) != 1)
    return -1;
  return (x % m + m) % m;
}
// gcd / lcm: std::gcd(a, b), std::lcm(a, b) from <numeric>. lcm = a / gcd * b
// (divide first)

// [SIEVE] smallest prime factor, linear sieve O(n)
vector<int> spf, primes;
void sieve(int n) {
  spf.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (!spf[i]) {
      spf[i] = i;
      primes.pb(i);
    }
    for (int p : primes) {
      if (p > spf[i] || (ll)i * p > n)
        break;
      spf[i * p] = p;
    }
  }
}
// factorize using spf, O(log x). Call sieve(maxN) first
vector<pair<int, int>> factorize(int x) {
  vector<pair<int, int>> f;
  while (x > 1) {
    int p = spf[x], c = 0;
    while (x % p == 0)
      x /= p, c++;
    f.pb({p, c});
  }
  return f;
}

// [FACTORIZE] trial division, O(sqrt n), no sieve needed
vector<pair<ll, int>> factorize_slow(ll n) {
  vector<pair<ll, int>> f;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p)
      continue;
    int c = 0;
    while (n % p == 0)
      n /= p, c++;
    f.pb({p, c});
  }
  if (n > 1)
    f.pb({n, 1});
  return f;
}
// all divisors, O(sqrt n)
vector<ll> divisors(ll n) {
  vector<ll> d;
  for (ll i = 1; i * i <= n; i++)
    if (n % i == 0) {
      d.pb(i);
      if (i != n / i)
        d.pb(n / i);
    }
  sort(all(d));
  return d;
}
// Euler totient, O(sqrt n)
ll phi(ll n) {
  ll r = n;
  for (ll p = 2; p * p <= n; p++)
    if (n % p == 0) {
      while (n % p == 0)
        n /= p;
      r -= r / p;
    }
  if (n > 1)
    r -= r / n;
  return r;
}

// [NCR] factorials + inverse factorials mod prime, O(n) build, O(1) query
struct Comb {
  vector<ll> f, inv;
  Comb(int n) : f(n + 1), inv(n + 1) {
    f[0] = 1;
    for (int i = 1; i <= n; i++)
      f[i] = f[i - 1] * i % MOD;
    inv[n] = power(f[n], MOD - 2);
    for (int i = n; i > 0; i--)
      inv[i - 1] = inv[i] * i % MOD;
  }
  ll C(int n, int r) {
    return (r < 0 || r > n) ? 0 : f[n] * inv[r] % MOD * inv[n - r] % MOD;
  }
  ll P(int n, int r) { return (r < 0 || r > n) ? 0 : f[n] * inv[n - r] % MOD; }
};

// [MATRIX] matrix exponentiation (fibonacci, linear recurrences), O(k^3 log e)
typedef vector<vector<ll>> Mat;
Mat matmul(const Mat &A, const Mat &B) {
  int n = sz(A), m = sz(B[0]), k = sz(B);
  Mat C(n, vector<ll>(m, 0));
  for (int i = 0; i < n; i++)
    for (int t = 0; t < k; t++) {
      if (!A[i][t])
        continue;
      for (int j = 0; j < m; j++)
        C[i][j] = (C[i][j] + A[i][t] * B[t][j]) % MOD;
    }
  return C;
}
Mat matpow(Mat A, ll e) {
  int n = sz(A);
  Mat R(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++)
    R[i][i] = 1;
  while (e > 0) {
    if (e & 1)
      R = matmul(R, A);
    A = matmul(A, A);
    e >>= 1;
  }
  return R;
}
// fib(n): matpow({{1,1},{1,0}}, n)[0][1]

// [MILLER-RABIN] deterministic for n < 3.3e24, so fine for all 64-bit
ll mulmod(ll a, ll b, ll m) { return (__int128)a * b % m; }
ll powmod(ll b, ll e, ll m) {
  ll r = 1;
  b %= m;
  while (e > 0) {
    if (e & 1)
      r = mulmod(r, b, m);
    b = mulmod(b, b, m);
    e >>= 1;
  }
  return r;
}
bool isPrime(ll n) {
  if (n < 2)
    return false;
  static const ll bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (ll p : bases)
    if (n % p == 0)
      return n == p;
  ll d = n - 1;
  int s = 0;
  while ((d & 1) == 0)
    d >>= 1, s++;
  for (ll a : bases) {
    ll x = powmod(a, d, n);
    if (x == 1 || x == n - 1)
      continue;
    bool comp = true;
    for (int r = 1; r < s; r++) {
      x = mulmod(x, x, n);
      if (x == n - 1) {
        comp = false;
        break;
      }
    }
    if (comp)
      return false;
  }
  return true;
}

// ======================================================================
//  2. ARRAYS, SEARCHING, PREFIX SUMS, TWO POINTERS
// ======================================================================

// [PREFIX] prefix sums. sum of a[l..r) = p[r] - p[l]
vector<ll> prefixSum(const vector<ll> &a) {
  vector<ll> p(sz(a) + 1, 0);
  for (int i = 0; i < sz(a); i++)
    p[i + 1] = p[i] + a[i];
  return p;
}
// [DIFF ARRAY] add v to a[l..r] in O(1): d[l] += v, d[r+1] -= v, then prefix
// sum d at the end

// [PREFIX2D] sum of rectangle (r1,c1)..(r2,c2) inclusive, 0-indexed
struct Pref2D {
  vector<vector<ll>> p;
  Pref2D(const vector<vector<ll>> &a) {
    int n = sz(a), m = sz(a[0]);
    p.assign(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        p[i + 1][j + 1] = a[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
  }
  ll query(int r1, int c1, int r2, int c2) {
    return p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
  }
};

// [BINSEARCH] smallest x in [lo, hi] where ok(x) is true. ok must be monotone
// (false ... false true ... true). If nothing is true you get hi, so check
// ok(hi) after.
template <class F> ll bsFirstTrue(ll lo, ll hi, F ok) {
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    if (ok(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}
// largest x where ok(x) is true (true ... true false ... false)
template <class F> ll bsLastTrue(ll lo, ll hi, F ok) {
  while (lo < hi) {
    ll mid = lo + (hi - lo + 1) / 2;
    if (ok(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}
// STL: lower_bound = first >= x, upper_bound = first > x (on sorted ranges)
// Binary search on doubles: loop 100 times instead of while (hi - lo > eps)

// [COMPRESS] coordinate compression, returns sorted unique values
vector<int> compress(vector<int> &a) {
  vector<int> v = a;
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  for (int &x : a)
    x = lower_bound(all(v), x) - v.begin();
  return v;
}

// [KADANE] max subarray sum
ll kadane(const vector<ll> &a) {
  ll best = a[0], cur = a[0];
  for (int i = 1; i < sz(a); i++) {
    cur = max(a[i], cur + a[i]);
    best = max(best, cur);
  }
  return best;
}

// [TWO POINTERS] pattern: longest window with sum <= S (all a[i] >= 0)
int longestWindow(const vector<ll> &a, ll S) {
  int best = 0;
  ll cur = 0;
  for (int l = 0, r = 0; r < sz(a); r++) {
    cur += a[r];
    while (cur > S && l <= r)
      cur -= a[l++];
    best = max(best, r - l + 1);
  }
  return best;
}

// [MONO STACK] next greater element index (or -1)
vector<int> nextGreater(const vector<int> &a) {
  int n = sz(a);
  vector<int> res(n, -1);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
      res[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  return res;
}

// [MONO DEQUE] sliding window maximum of size k
vector<int> slidingMax(const vector<int> &a, int k) {
  deque<int> dq;
  vector<int> res;
  for (int i = 0; i < sz(a); i++) {
    while (!dq.empty() && a[dq.back()] <= a[i])
      dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k)
      dq.pop_front();
    if (i >= k - 1)
      res.pb(a[dq.front()]);
  }
  return res;
}

// ======================================================================
//  3. DATA STRUCTURES
// ======================================================================

// [DSU] union find, near O(1) per op
struct DSU {
  vector<int> p, sz_;
  DSU(int n) : p(n), sz_(n, 1) { iota(all(p), 0); }
  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (sz_[a] < sz_[b])
      swap(a, b);
    p[b] = a;
    sz_[a] += sz_[b];
    return true;
  }
  bool same(int a, int b) { return find(a) == find(b); }
  int size(int x) { return sz_[find(x)]; }
};

// [BIT] Fenwick tree, point update + prefix/range sum, 0-indexed, O(log n)
struct BIT {
  int n;
  vector<ll> t;
  BIT(int n) : n(n), t(n + 1, 0) {}
  void add(int i, ll v) {
    for (i++; i <= n; i += i & -i)
      t[i] += v;
  }
  ll query(int i) {
    ll s = 0;
    for (i++; i > 0; i -= i & -i)
      s += t[i];
    return s;
  }                                                          // sum [0..i]
  ll query(int l, int r) { return query(r) - query(l - 1); } // sum [l..r]
};
// Counting inversions: go left to right, ans += (count of seen elements > a[i])
// using BIT on compressed values

// [SEGTREE] iterative segment tree, point update, range query on [l, r)
// Works for any associative op. Usage:
//   SegTree st(n, 0LL, [](ll a, ll b){ return a + b; });      // sum
//   SegTree st(n, (ll)INF, [](ll a, ll b){ return min(a, b); }); // min
template <class T, class F> struct SegTree {
  int n;
  vector<T> t;
  T id;
  F f;
  SegTree(int n, T id, F f) : n(n), t(2 * n, id), id(id), f(f) {}
  void build(const vector<T> &a) {
    for (int i = 0; i < n; i++)
      t[n + i] = a[i];
    for (int i = n - 1; i > 0; i--)
      t[i] = f(t[2 * i], t[2 * i + 1]);
  }
  void update(int i, T v) {
    for (t[i += n] = v; i > 1; i >>= 1)
      t[i >> 1] = f(t[i & ~1], t[i | 1]);
  }
  T query(int l, int r) {
    T resl = id, resr = id;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        resl = f(resl, t[l++]);
      if (r & 1)
        resr = f(t[--r], resr);
    }
    return f(resl, resr);
  }
};

// [LAZYSEG] recursive segment tree: range add + range sum, 0-indexed, inclusive
// [l, r]
struct LazySeg {
  int n;
  vector<ll> sum, lz;
  LazySeg(int n) : n(n), sum(4 * n, 0), lz(4 * n, 0) {}
  void app(int x, int l, int r, ll v) {
    sum[x] += v * (r - l + 1);
    lz[x] += v;
  }
  void push(int x, int l, int r) {
    if (!lz[x])
      return;
    int m = (l + r) / 2;
    app(2 * x, l, m, lz[x]);
    app(2 * x + 1, m + 1, r, lz[x]);
    lz[x] = 0;
  }
  void upd(int x, int l, int r, int ql, int qr, ll v) {
    if (qr < l || r < ql)
      return;
    if (ql <= l && r <= qr) {
      app(x, l, r, v);
      return;
    }
    push(x, l, r);
    int m = (l + r) / 2;
    upd(2 * x, l, m, ql, qr, v);
    upd(2 * x + 1, m + 1, r, ql, qr, v);
    sum[x] = sum[2 * x] + sum[2 * x + 1];
  }
  ll qry(int x, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return 0;
    if (ql <= l && r <= qr)
      return sum[x];
    push(x, l, r);
    int m = (l + r) / 2;
    return qry(2 * x, l, m, ql, qr) + qry(2 * x + 1, m + 1, r, ql, qr);
  }
  void update(int l, int r, ll v) { upd(1, 0, n - 1, l, r, v); }
  ll query(int l, int r) { return qry(1, 0, n - 1, l, r); }
};

// [SPARSE] sparse table, range MIN on static array, O(n log n) build, O(1)
// query, inclusive [l, r]
struct SparseTable {
  vector<vector<int>> t;
  SparseTable(const vector<int> &a) {
    int n = sz(a), K = 32 - __builtin_clz(n);
    t.assign(K, vector<int>(n));
    t[0] = a;
    for (int k = 1; k < K; k++)
      for (int i = 0; i + (1 << k) <= n; i++)
        t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
  }
  int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(t[k][l], t[k][r - (1 << k) + 1]);
  }
};

// [ORDERED SET] pbds: order statistics. For a multiset store pair(value,
// uniqueId)
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
// os.insert(x); os.erase(x);
// *os.find_by_order(k)  -> k-th smallest (0-indexed)
// os.order_of_key(x)    -> number of elements strictly less than x

// [TRIE] lowercase strings. insert / count words with a prefix / exact search
struct Trie {
  vector<array<int, 26>> nxt;
  vector<int> pass, fin;
  Trie() { newNode(); }
  int newNode() {
    nxt.emplace_back();
    nxt.back().fill(0);
    pass.pb(0);
    fin.pb(0);
    return sz(nxt) - 1;
  }
  void insert(const string &s) {
    int u = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (!nxt[u][c]) {
        int v = newNode();
        nxt[u][c] = v;
      }
      u = nxt[u][c];
      pass[u]++;
    }
    fin[u]++;
  }
  int prefixCount(const string &s) {
    int u = 0;
    for (char ch : s) {
      u = nxt[u][ch - 'a'];
      if (!u)
        return 0;
    }
    return pass[u];
  }
  bool contains(const string &s) {
    int u = 0;
    for (char ch : s) {
      u = nxt[u][ch - 'a'];
      if (!u)
        return false;
    }
    return fin[u] > 0;
  }
};
// Binary trie (max xor pair): same idea with 2 children per node, walk bits
// from 30 down to 0

// [CUSTOM HASH] for unordered_map / unordered_set, avoids anti-hash tests
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t R =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + R);
  }
};
// unordered_map<ll, int, custom_hash> mp;

// ======================================================================
//  4. STRINGS
// ======================================================================

// [Z] z[i] = length of longest common prefix of s and s[i..]
vector<int> zfunc(const string &s) {
  int n = sz(s);
  vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i < r)
      z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] > r)
      l = i, r = i + z[i];
  }
  return z;
}

// [KMP] pi[i] = length of longest proper prefix of s[0..i] that is also a
// suffix
vector<int> prefixFunction(const string &s) {
  int n = sz(s);
  vector<int> pi(n, 0);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}
// Find pattern p in text t: pi = prefixFunction(p + '#' + t), match ends where
// pi[i] == sz(p) Smallest period of s: n - pi[n-1] (valid if it divides n)

// [HASH] polynomial rolling hash with 2 mods and random bases. get(l, r) for
// s[l..r)
struct StrHash {
  static constexpr ll M1 = 1000000007, M2 = 998244353;
  ll B1, B2;
  vector<ll> h1, h2, p1, p2;
  StrHash(const string &s) {
    B1 = 1000 + rng() % 100000;
    B2 = 1000 + rng() % 100000;
    int n = sz(s);
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
      h1[i + 1] = (h1[i] * B1 + s[i]) % M1;
      h2[i + 1] = (h2[i] * B2 + s[i]) % M2;
      p1[i + 1] = p1[i] * B1 % M1;
      p2[i + 1] = p2[i] * B2 % M2;
    }
  }
  pll get(int l, int r) {
    ll a = ((h1[r] - h1[l] * p1[r - l]) % M1 + M1) % M1;
    ll b = ((h2[r] - h2[l] * p2[r - l]) % M2 + M2) % M2;
    return {a, b};
  }
};

// [MANACHER] d1[i] = number of odd palindromes centered at i,
// d2[i] = number of even palindromes centered between i-1 and i. O(n)
void manacher(const string &s, vector<int> &d1, vector<int> &d2) {
  int n = sz(s);
  d1.assign(n, 0);
  d2.assign(n, 0);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
      k++;
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
      k++;
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }
}

// ======================================================================
//  5. GRAPHS
// ======================================================================
typedef vector<vector<int>> Graph;            // unweighted adjacency list
typedef vector<vector<pair<int, ll>>> WGraph; // (to, weight)
struct Edge {
  int u, v;
  ll w;
};

// [BFS] shortest path in unweighted graph, d = -1 if unreachable
vector<int> bfs(const Graph &g, int s) {
  vector<int> d(sz(g), -1);
  queue<int> q;
  d[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u])
      if (d[v] < 0) {
        d[v] = d[u] + 1;
        q.push(v);
      }
  }
  return d;
}

// [DFS] recursive. Connected components count
void dfs(const Graph &g, int u, vector<char> &vis) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v])
      dfs(g, v, vis);
}
int components(const Graph &g) {
  vector<char> vis(sz(g), 0);
  int c = 0;
  for (int i = 0; i < sz(g); i++)
    if (!vis[i]) {
      dfs(g, i, vis);
      c++;
    }
  return c;
}
// Grid BFS/DFS: loop d in 0..3, nx = x + dx4[d], ny = y + dy4[d], bounds check,
// then visit

// [0-1 BFS] edges with weight 0 or 1, O(V + E)
vector<int> bfs01(const vector<vector<pair<int, int>>> &g, int s) {
  vector<int> d(sz(g), INF32);
  deque<int> dq;
  d[s] = 0;
  dq.push_back(s);
  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();
    for (auto [v, w] : g[u])
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        if (w == 0)
          dq.push_front(v);
        else
          dq.push_back(v);
      }
  }
  return d;
}

// [DIJKSTRA] non-negative weights, O((V + E) log V). par[] gives the path (walk
// back from target)
vector<ll> dijkstra(const WGraph &g, int s, vector<int> *par = nullptr) {
  vector<ll> d(sz(g), INF);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  d[s] = 0;
  pq.push({0, s});
  if (par)
    par->assign(sz(g), -1);
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();
    if (du > d[u])
      continue;
    for (auto [v, w] : g[u])
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        if (par)
          (*par)[v] = u;
        pq.push({d[v], v});
      }
  }
  return d;
}

// [BELLMAN-FORD] handles negative edges, O(VE). Returns true if a negative
// cycle is reachable from s
bool bellmanFord(int n, int s, const vector<Edge> &es, vector<ll> &d) {
  d.assign(n, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    bool changed = false;
    for (auto &e : es)
      if (d[e.u] < INF && d[e.u] + e.w < d[e.v]) {
        d[e.v] = d[e.u] + e.w;
        changed = true;
      }
    if (!changed)
      return false;
    if (i == n - 1)
      return true;
  }
  return false;
}

// [FLOYD] all pairs shortest paths, O(n^3). d[i][i] = 0, missing edges = INF
void floyd(vector<vector<ll>> &d) {
  int n = sz(d);
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (d[i][k] < INF && d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

// [TOPO] Kahn's algorithm. If sz(result) < n there is a cycle
vector<int> topoSort(const Graph &g) {
  int n = sz(g);
  vector<int> indeg(n, 0), order;
  for (int u = 0; u < n; u++)
    for (int v : g[u])
      indeg[v]++;
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (!indeg[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.pb(u);
    for (int v : g[u])
      if (--indeg[v] == 0)
        q.push(v);
  }
  return order;
}

// [KRUSKAL] MST weight (needs DSU above). Returns -1 if graph is disconnected
ll kruskal(int n, vector<Edge> es) {
  sort(all(es), [](const Edge &a, const Edge &b) { return a.w < b.w; });
  DSU d(n);
  ll tot = 0;
  int used = 0;
  for (auto &e : es)
    if (d.unite(e.u, e.v)) {
      tot += e.w;
      used++;
    }
  return used == n - 1 ? tot : -1;
}

// [BIPARTITE] 2-coloring with BFS. color is filled with 0/1, returns false if
// odd cycle
bool bipartite(const Graph &g, vector<int> &color) {
  int n = sz(g);
  color.assign(n, -1);
  for (int s = 0; s < n; s++) {
    if (color[s] != -1)
      continue;
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ 1;
          q.push(v);
        } else if (color[v] == color[u])
          return false;
      }
    }
  }
  return true;
}

// [BRIDGES / CUT VERTICES] undirected graph, handles multi-edges. Call addEdge
// then run() Afterwards bridge[edgeId] and cut[vertex] are filled
struct LowLink {
  int n, timer = 0, m = 0;
  vector<vector<pair<int, int>>> g; // (to, edge id)
  vector<int> tin, low;
  vector<char> bridge, cut;
  LowLink(int n) : n(n), g(n), tin(n, -1), low(n, 0), cut(n, 0) {}
  void addEdge(int u, int v) {
    g[u].pb({v, m});
    g[v].pb({u, m});
    m++;
  }
  void dfs(int u, int pe) {
    tin[u] = low[u] = timer++;
    int children = 0;
    for (auto [v, id] : g[u]) {
      if (id == pe)
        continue;
      if (tin[v] != -1)
        low[u] = min(low[u], tin[v]);
      else {
        dfs(v, id);
        low[u] = min(low[u], low[v]);
        children++;
        if (low[v] > tin[u])
          bridge[id] = 1;
        if (pe != -1 && low[v] >= tin[u])
          cut[u] = 1;
      }
    }
    if (pe == -1 && children > 1)
      cut[u] = 1;
  }
  void run() {
    bridge.assign(m, 0);
    for (int i = 0; i < n; i++)
      if (tin[i] == -1)
        dfs(i, -1);
  }
};

// [SCC] Kosaraju. comp[v] = component id, ids are in topological order of the
// condensation DAG
struct SCC {
  int n;
  vector<vector<int>> g, rg;
  vector<int> comp, order;
  vector<char> vis;
  SCC(int n) : n(n), g(n), rg(n), comp(n, -1), vis(n, 0) {}
  void addEdge(int u, int v) {
    g[u].pb(v);
    rg[v].pb(u);
  }
  void dfs1(int u) {
    vis[u] = 1;
    for (int v : g[u])
      if (!vis[v])
        dfs1(v);
    order.pb(u);
  }
  void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : rg[u])
      if (comp[v] < 0)
        dfs2(v, c);
  }
  int run() {
    for (int i = 0; i < n; i++)
      if (!vis[i])
        dfs1(i);
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
      if (comp[order[i]] < 0)
        dfs2(order[i], c++);
    return c; // number of components
  }
};

// [LCA] binary lifting on a tree, O(n log n) build, O(log n) query
struct LCA {
  int n, LOG;
  vector<vector<int>> up;
  vector<int> depth;
  LCA(const Graph &g, int root = 0) : n(sz(g)) {
    LOG = 1;
    while ((1 << LOG) < n)
      LOG++;
    up.assign(LOG, vector<int>(n, root));
    depth.assign(n, 0);
    vector<char> seen(n, 0);
    queue<int> q;
    q.push(root);
    seen[root] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u])
        if (!seen[v]) {
          seen[v] = 1;
          depth[v] = depth[u] + 1;
          up[0][v] = u;
          q.push(v);
        }
    }
    for (int k = 1; k < LOG; k++)
      for (int v = 0; v < n; v++)
        up[k][v] = up[k - 1][up[k - 1][v]];
  }
  int kth(int a, int k) { // k-th ancestor
    for (int i = 0; i < LOG; i++)
      if (k >> i & 1)
        a = up[i][a];
    return a;
  }
  int lca(int a, int b) {
    if (depth[a] < depth[b])
      swap(a, b);
    a = kth(a, depth[a] - depth[b]);
    if (a == b)
      return a;
    for (int k = LOG - 1; k >= 0; k--)
      if (up[k][a] != up[k][b]) {
        a = up[k][a];
        b = up[k][b];
      }
    return up[0][a];
  }
  int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
};

// [TREE DIAMETER] two BFS. Returns {endpointA, endpointB, length in edges}
array<int, 3> treeDiameter(const Graph &g) {
  auto d0 = bfs(g, 0);
  int a = max_element(all(d0)) - d0.begin();
  auto d1 = bfs(g, a);
  int b = max_element(all(d1)) - d1.begin();
  return {a, b, d1[b]};
}

// [EULER TOUR] tin/tout + subtree size. Subtree of u = nodes with tin in
// [tin[u], tout[u])
struct EulerTour {
  vector<int> tin, tout, sub;
  int timer = 0;
  EulerTour(const Graph &g, int root = 0)
      : tin(sz(g)), tout(sz(g)), sub(sz(g), 1) {
    go(g, root, -1);
  }
  void go(const Graph &g, int u, int p) {
    tin[u] = timer++;
    for (int v : g[u])
      if (v != p) {
        go(g, v, u);
        sub[u] += sub[v];
      }
    tout[u] = timer;
  }
};

// [DINIC] max flow, O(V^2 E) worst case, very fast in practice. Bipartite
// matching = flow with unit caps
struct Dinic {
  struct E {
    int to;
    ll cap;
  };
  vector<E> es;
  vector<vector<int>> g;
  vector<int> level, it;
  Dinic(int n) : g(n), level(n), it(n) {}
  void addEdge(int u, int v, ll c) {
    g[u].pb(sz(es));
    es.pb({v, c});
    g[v].pb(sz(es));
    es.pb({u, 0});
  }
  bool bfs(int s, int t) {
    fill(all(level), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int id : g[u])
        if (es[id].cap > 0 && level[es[id].to] < 0) {
          level[es[id].to] = level[u] + 1;
          q.push(es[id].to);
        }
    }
    return level[t] >= 0;
  }
  ll dfs(int u, int t, ll f) {
    if (u == t)
      return f;
    for (int &i = it[u]; i < sz(g[u]); i++) {
      int id = g[u][i], v = es[id].to;
      if (es[id].cap > 0 && level[v] == level[u] + 1) {
        ll got = dfs(v, t, min(f, es[id].cap));
        if (got > 0) {
          es[id].cap -= got;
          es[id ^ 1].cap += got;
          return got;
        }
      }
    }
    return 0;
  }
  ll maxflow(int s, int t) {
    ll flow = 0;
    while (bfs(s, t)) {
      fill(all(it), 0);
      while (ll f = dfs(s, t, INF))
        flow += f;
    }
    return flow;
  }
};

// ======================================================================
//  6. DYNAMIC PROGRAMMING
// ======================================================================
// Recipe: define state -> write transition -> set base cases -> pick order ->
// optimize

// [KNAPSACK] 0/1: iterate capacity DOWNWARDS. Unbounded: iterate UPWARDS
ll knapsack01(const vector<int> &w, const vector<ll> &v, int W) {
  vector<ll> dp(W + 1, 0);
  for (int i = 0; i < sz(w); i++)
    for (int c = W; c >= w[i]; c--)
      dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
  return dp[W];
}
ll knapsackUnbounded(const vector<int> &w, const vector<ll> &v, int W) {
  vector<ll> dp(W + 1, 0);
  for (int i = 0; i < sz(w); i++)
    for (int c = w[i]; c <= W; c++)
      dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
  return dp[W];
}

// [COIN CHANGE] min coins (-1 if impossible) and number of ways (order does not
// matter)
int minCoins(const vector<int> &coins, int target) {
  vector<int> dp(target + 1, INF32);
  dp[0] = 0;
  for (int x = 1; x <= target; x++)
    for (int c : coins)
      if (c <= x && dp[x - c] != INF32)
        dp[x] = min(dp[x], dp[x - c] + 1);
  return dp[target] == INF32 ? -1 : dp[target];
}
ll countWays(const vector<int> &coins, int target) {
  vector<ll> dp(target + 1, 0);
  dp[0] = 1;
  for (int c : coins)
    for (int x = c; x <= target; x++)
      dp[x] = (dp[x] + dp[x - c]) % MOD;
  return dp[target];
}

// [LIS] O(n log n), strictly increasing. For non-decreasing use upper_bound
int lis(const vector<int> &a) {
  vector<int> t;
  for (int x : a) {
    auto it = lower_bound(all(t), x);
    if (it == t.end())
      t.pb(x);
    else
      *it = x;
  }
  return sz(t);
}

// [LCS] longest common subsequence, O(nm)
int lcs(const string &a, const string &b) {
  int n = sz(a), m = sz(b);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1
                                      : max(dp[i - 1][j], dp[i][j - 1]);
  return dp[n][m];
}

// [EDIT DISTANCE] Levenshtein, O(nm)
int editDistance(const string &a, const string &b) {
  int n = sz(a), m = sz(b);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++)
    dp[i][0] = i;
  for (int j = 0; j <= m; j++)
    dp[0][j] = j;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                      dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
  return dp[n][m];
}

// [BITMASK DP] TSP: shortest tour visiting all n <= ~20 nodes, start/end at 0.
// O(2^n n^2)
ll tsp(const vector<vector<ll>> &dist) {
  int n = sz(dist), full = (1 << n) - 1;
  vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
  dp[1][0] = 0;
  for (int mask = 1; mask <= full; mask++)
    for (int last = 0; last < n; last++) {
      if (dp[mask][last] >= INF)
        continue;
      for (int nx = 0; nx < n; nx++) {
        if (mask >> nx & 1)
          continue;
        ll &cur = dp[mask | 1 << nx][nx];
        cur = min(cur, dp[mask][last] + dist[last][nx]);
      }
    }
  ll best = INF;
  for (int last = 0; last < n; last++)
    best = min(best, dp[full][last] + dist[last][0]);
  return best;
}
// Submask enumeration (total O(3^n) over all masks):
//   for (int sub = mask; sub; sub = (sub - 1) & mask) { ... }   // add the
//   empty set separately

// [SOS DP] f[mask] = sum of g[sub] over all submasks of mask, O(2^B * B)
void sosSubsets(vector<ll> &f, int B) {
  for (int b = 0; b < B; b++)
    for (int m = 0; m < (1 << B); m++)
      if (m >> b & 1)
        f[m] += f[m ^ (1 << b)];
}

// [DIGIT DP] count x in [0, N] with digit sum == S (S < 200, N < 1e19). Change
// the state for other problems
namespace DigitDP {
string d;
ll memo[20][200][2];
int S;
ll go(int pos, int sum, int tight) {
  if (sum > S)
    return 0;
  if (pos == sz(d))
    return sum == S;
  ll &r = memo[pos][sum][tight];
  if (r != -1)
    return r;
  r = 0;
  int lim = tight ? d[pos] - '0' : 9;
  for (int x = 0; x <= lim; x++)
    r += go(pos + 1, sum + x, tight && x == lim);
  return r;
}
ll count(ll N, int s) {
  d = to_string(N);
  S = s;
  memset(memo, -1, sizeof memo);
  return go(0, 0, 1);
}
} // namespace DigitDP

// [TREE DP] example: max weight independent set on a tree (no two adjacent
// nodes picked) dp[u][0] = best in subtree of u if u is NOT picked, dp[u][1] =
// if u IS picked
void treeDP(const Graph &g, const vector<ll> &w, int u, int p,
            vector<array<ll, 2>> &dp) {
  dp[u][0] = 0;
  dp[u][1] = w[u];
  for (int v : g[u]) {
    if (v == p)
      continue;
    treeDP(g, w, v, u, dp);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}
// Other DP families to know: interval DP (dp[l][r]), DP on DAG,
// probability/expected value DP, DP with bitsets, divide and conquer DP, convex
// hull trick

// ======================================================================
//  7. BITS
// ======================================================================
// x & -x                    lowest set bit
// x & (x - 1)               remove lowest set bit
// x >> i & 1                check bit i
// x | (1 << i)              set bit i,    x & ~(1 << i)  clear bit i,    x ^ (1
// << i)  toggle
// __builtin_popcount(x)     number of set bits (use popcountll for long long)
// __builtin_clz(x)          leading zeros (x != 0),  __builtin_ctz(x) trailing
// zeros 31 - __builtin_clz(x)     floor(log2 x) Power of two check        x > 0
// && (x & (x - 1)) == 0 Always use 1LL << i when i can reach 31 or more

// ======================================================================
//  8. GEOMETRY (basic)
// ======================================================================
typedef pair<ll, ll> P;
ll cross(P o, P a, P b) {
  return (a.first - o.first) * (b.second - o.second) -
         (a.second - o.second) * (b.first - o.first);
}
// cross > 0: left turn (counter-clockwise), < 0: right turn, == 0: collinear

// [CONVEX HULL] Andrew's monotone chain, O(n log n). Returns hull in
// counter-clockwise order
vector<P> convexHull(vector<P> p) {
  sort(all(p));
  p.erase(unique(all(p)), p.end());
  int n = sz(p);
  if (n < 3)
    return p;
  vector<P> h(2 * n);
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(h[k - 2], h[k - 1], p[i]) <= 0)
      k--;
    h[k++] = p[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(h[k - 2], h[k - 1], p[i]) <= 0)
      k--;
    h[k++] = p[i];
  }
  h.resize(k - 1);
  return h;
}

// ======================================================================
//  9. STL QUICK REFERENCE
// ======================================================================
// sort(all(v)); reverse(all(v)); unique(all(v)) after sorting; iota(all(v), 0)
// next_permutation(all(v))  (start from sorted)      max_element / min_element
// accumulate(all(v), 0LL)   (0LL, not 0, or it sums in int)
// nth_element(v.begin(), v.begin() + k, v.end())     k-th smallest in O(n)
// set / map: O(log n).  unordered_*: O(1) average, can be hacked
// priority_queue is a max-heap. Min-heap: priority_queue<T, vector<T>,
// greater<T>> multiset erase: s.erase(s.find(x)) removes ONE copy, s.erase(x)
// removes ALL copies string: s.substr(pos, len), s.find(t) returns string::npos
// if missing Random: uniform_int_distribution<int>(l, r)(rng) shuffle(all(v),
// rng)

// ======================================================================
//  CONTEST SKELETON (put this at the bottom of your file)
// ======================================================================
void solve() {
  // read input, solve, print
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  // cin >> T;
  while (T--)
    solve();
  return 0;
}
