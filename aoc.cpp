#include<bits/stdc++.h>
//#include<chrono>
#include<boost/algorithm/string.hpp>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
#define bsplit boost::algorithm::split 
#define rms(s, c) s.erase(remove(s.begin(), s.end(), c), s.end());
class node {
  public:
    string src;
    node* l;
    node* r;
    node(string s) {
      src = s;
      l = nullptr;
      r = nullptr;
    }
};
node* root;
map<string, node*> iscreated;

void parse_string(string&& s) {
  rms(s, ' ');
  rms(s, '(');
  rms(s, ')');
  vector<string> vals;
  bsplit(vals, s, boost::is_any_of("="));
  string src = std::move(vals[0]);

  bsplit(vals, vals[1], boost::is_any_of(","));;
  string lef = vals[0], rig = vals[1];
  node* cur, *left, *right;
  if (iscreated.count(src) == 0) {
    debug("new node", src);
    cur = new node(src);
    if (src == "AAA") {
      root = cur;
    }
    iscreated[src] = cur;
  }
  else {
    debug("old node", src);
    cur = iscreated[src];
  }
  if (iscreated.count(lef) == 0) {
    debug("new node", lef);
    left = new node(lef);
    iscreated[lef] = left;
  }
  else {
    debug("old node", lef);
    left = iscreated[lef];
  }
  if (iscreated.count(rig) == 0) {
    debug("new node", rig);
    right = new node(rig);
    iscreated[rig] = right;
  }
  else {
    debug("old node", rig);
    right = iscreated[rig];
  }
  /* debug(cur->src); */
  cur->l = left;
  cur->r = right;

}
void solve() {
  ifstream fptr;
  fptr.open("input.txt");
  int lno = 0;
  string dirs;
  while (fptr) {
    
    string s;
    getline(fptr, s);
    if (lno == 0) {
      dirs = s;
      lno++;
      continue;
    }
    if (s.size() > 0) {

      parse_string((string &&) s);
    }


    
  }
  bool found = 0;
  int ind = 0;
  int ans = 0;
  int sz = dirs.size();
  while (!found) {
    debug(root->src);
    if (root->src == "ZZZ") {
      found = 1;
      break;
    }
    if (dirs[ind % sz] == 'L') {
      root = root->l;
    }
    else
      root = root->r;
    ans++;
    ind++;
    debug(ind);
  }
  cout << ans << "\n";

}

int main() {
	//auto start = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test = 1;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	while(test--) 
		solve();
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//float seconds = (float) (duration.count()) / (float) 1e6;
 	//debug(seconds);

	return 0;
}
