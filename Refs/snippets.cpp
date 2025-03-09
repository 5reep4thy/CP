#define ll long long 
#include <bits/stdc++.h>
using namespace std;

/////// Segment tree
template<typename T>
class seg_tree {
  public:
    size_t n;
    vector<T> arr;
    seg_tree(size_t sz) {
      size_t needed = 1;
      while (needed <= sz) {
        needed *= 2;
      }
      n = needed;
      arr.resize(2 * n + 1);
    };
    T range_sum(size_t l, size_t r) {
      T ret{0};
      l += n + 1, r += n + 1;
      while (l < r) {
        debug(l, r);
        if (l % 2 == 0) {
          ret += arr[l];
          l += 1;
        }
        if (r % 2 == 1) {
          ret += arr[r];
          r -= 1;
        }
        l = (l + 1) / 2;
        r = (r + 1) / 2;
      }
      if (l == r) {
        ret += arr[l];
      }
      return ret;
    }
    void update_num(size_t ind, T x) {
      ind = n + ind + 1;
      while (ind > 1) {
        arr[ind] += x;
        ind = (ind + 1) / 2;
      }
    }
};

/////// fenwick
template<typename T>
struct fenwick {
  vector<T> bit;
  int n;
  fenwick(vector<T> &x) {
    this -> n = x.size() + 1;
    this -> bit.resize(n, 0);
    for (int i = 0; i < n - 1; i++) {
      add(i, x[i]);
    }
  }
  void add(int idx, T delta) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += delta;
  }
  int sum(int idx) {
    T ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
          ret += bit[idx];
      return ret;
  }

  T sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

///////////////  mod inv
const ll mod = 1e9 + 7;
ll binpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b % 2) {
      ans *= a;
      ans %= mod;
    }
    a = a * a;
    a %= mod;
    b = b >> 1;
    b %= mod;
  }
  return ans;
}
ll mod_inv(ll a) {
  return binpow(a, mod - 2);
}

//////////////////////// factorial

const ll mod = 1e9 + 7;
ll binpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b % 2) {
      ans *= a;
      ans %= mod;
    }
    a = a * a;
    a %= mod;
    b = b >> 1;
    b %= mod;
  }
  return ans;
}
ll mod_inv(ll a) {
  return binpow(a, mod - 2);
}
vector<ll> factorial(ll n) {
  vector<ll> fact(n);
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i < n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  return fact;
}

vector<ll> factorial_inv(ll n) {
  vector<ll> fact_inv(n);
  fact_inv[0] = 1;
  fact_inv[1] = 1;
  for (int i = 2; i < n; i++) {
    fact_inv[i] = fact_inv[i - 1] * mod_inv(i);
    fact_inv[i] %= mod;
  }
  return fact_inv;
}
const ll mxN = 1e9 + 7;
vector<ll> fact(mxN), fact_inv(mxN);

///////////////// Extended euclidean
// x is mod inv of a ( mod b ), if a and b are co-prime
template<typename T>
void extendedEuclidean(T a, T& x, T b, T& y) {

  T x1, y1;
  if (b == 0) {
    x = 1;
    y = 1;
    return;
  }
  extendedEuclidean(b, x1, (a % b), y1);
  x = y1;
  y = x1 - (a / b) * y1;

}

///////////// dijkstra
template <class T>
vector<T> dijkstra(T src, const vector<vector<pair<T, T>>>& edges) {
  struct comp {
    // strict weak ordering should be present
    bool operator()(const pair<T, T>& a, const pair<T, T>& b) const {
      return a.first < b.first || (!(b.first < a.first) && a.second < b.second);
    }
  };
  uint32_t n = edges.size();
  vector<T> d(n, std::numeric_limits<T>::max() - 1);
  vector<T> p(n, -1);
  d[src] = 0;
  set<pair<T, T>, comp> pq;
  pq.insert({0, src});
  while (!pq.empty()) {
    pair<T, T> tp = *pq.begin();
    pq.erase(pq.begin());
    for (const pair<T, T>& ed: edges[tp.second]) {
      if (d[tp.second] + ed.second <= d[ed.first]) {
        pq.erase({d[ed.first], ed.first});
        d[ed.first] = d[tp.second] + ed.second;
        p[ed.first] = tp.second;
        pq.insert({d[ed.first], ed.first});
      }
    }
  }
  return d;
};