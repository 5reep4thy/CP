/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("milk2.out");
ifstream fin ("milk2.in");
#ifdef _DEBUG
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long

struct Point {
  int x, y;
};
void solve() {
  int n;
  fin >> n;
  vector<Point> a(n);
  map<int, vector<int>> points;
  map<int, vector<int>> pointe;
  set<int> pts;
  for (int i = 0; i < n; i++) {
    fin >> a[i].x >> a[i].y;
    pts.insert(a[i].x);
    pts.insert(a[i].y);
    points[a[i].x].push_back(i);
    pointe[a[i].y].push_back(i);
  }
  sort(a.begin(), a.end(), [] (Point p, Point q) {
    if (p.x < q.x)
    return 1;
    if (p.x == q.x && p.y < q.y)
    return 1;
    return 0;
  });
  set<int> curpts;
  bool updateVal = true;
  int nothingTaken = 0;
  int somethingTaken = 0;
  int start = 0, end = 0;
  int prevPt = *pts.begin();
  for (auto pt: pts) {
    for (auto po: pointe[pt]) {
      curpts.erase(po);
    }
    for (auto po: points[pt]) {
      curpts.insert(po);
    }
    if (updateVal) {
      start = pt, end = pt;
      nothingTaken = max(nothingTaken, pt - prevPt);
      debug(nothingTaken, pt);
      updateVal = false;
    }
    if (curpts.size() == 0) {
        debug(pt, "End");
      prevPt = pt;
      updateVal = 1;
      end = pt;
      somethingTaken = max(somethingTaken, end - start);
    }
    else {
      end = pt;
      somethingTaken = max(somethingTaken, end - start);
      debug(pt, "Not end");
      debug(end, start);
    }
  }
  fout << somethingTaken << " " << nothingTaken << "\n";

}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
