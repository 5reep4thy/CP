/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: sreepat2
PROG: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>
using namespace std;
ofstream fout ("transform.out");
ifstream fin ("transform.in");
#ifdef _DEBUG
#include "local_helper.cpp"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long
#define int8_t int
// Rotate matrix of max size 10
void RotateMat(char (*x)[10][10], char (*y)[10][10], int8_t sz)  {
  assert(sz <= 10);
  for (int8_t i = 0; i < sz; i++)
    for (int8_t j = 0; j < sz; j++) {
      (*y)[sz - j - 1][i] = (*x)[i][j];
    }
}
// Reflect
int8_t (*ReflectMat(char (*x)[10][10], char (*y)[10][10], int8_t sz)) [10][10] {
  assert(sz <= 10);
  for (int8_t i = 0; i < sz; i++)
    for (int8_t j = 0; j < sz; j++) {
      (*y)[i][sz - j - 1] = (*x)[i][j];
    }
  return (int8_t(*)[10][10])y;
}
bool CheckSame(char (*x)[10][10],char (*y)[10][10], int8_t sz)  {
  assert(sz <= 10);
  for (int8_t i = 0; i < sz; i++)
    for (int8_t j = 0; j < sz; j++) {
      if ((*x)[i][j] != (*y)[i][j]) 
        return false;
    }
  return true;
}
void PrintMat(char (*y)[10][10], int8_t sz)  {
  assert(sz <= 10);
  for (int8_t i = 0; i < sz; i++) {
    for (int8_t j = 0; j < sz; j++) {
      fout << (*y)[i][j] ;
    }
    fout << "\n";
  }
}
void solve() {
  char mat[10][10];
  char mato[10][10];
  int8_t n;
  fin >> n;
  char (*tmpMat)[10][10] = (char(*)[10][10]) new char[10][10];
  char (*tmpMat2)[10][10] = (char(*)[10][10]) new char[10][10];
  for (auto i = 0; i < n; i++) 
    for (auto j = 0; j < n; j++) {
      fin >> mat[i][j];
      (*tmpMat)[i][j] = 'a';
    }
  for (auto i = 0; i < n; i++) 
    for (auto j = 0; j < n; j++)
      fin >> mato[i][j];
  RotateMat((char (*)[10][10])(&mat), (char (*)[10][10])tmpMat, n);      
  if (CheckSame(tmpMat, &mato, n)) {
    fout << 1 << "\n";
    return;
  }
  RotateMat((char (*)[10][10])(tmpMat), (char (*)[10][10])tmpMat2, n);      
  if (CheckSame(tmpMat2, &mato, n)) {
    fout << 2 << "\n";
    return;
  }
  RotateMat((char (*)[10][10])(tmpMat2), (char (*)[10][10])tmpMat, n);      
  if (CheckSame(tmpMat, &mato, n)) {
    fout << 3 << "\n";
    return;
  }
  ReflectMat((char (*)[10][10])(&mat), (char (*)[10][10])tmpMat, n);      
  if (CheckSame(tmpMat, &mato, n)) {
    fout << 4 << "\n";
    return;
  }
  RotateMat((char (*)[10][10])(tmpMat), (char (*)[10][10])tmpMat2, n);      
  if (CheckSame(tmpMat2, &mato, n)) {
    fout << 5 << "\n";
    return;
  }
  RotateMat((char (*)[10][10])(tmpMat2), (char (*)[10][10])tmpMat, n);      
  if (CheckSame(tmpMat, &mato, n)) {
    fout << 5 << "\n";
    return;
  }
  RotateMat((char (*)[10][10])(tmpMat), (char (*)[10][10])tmpMat2, n);      
  if (CheckSame(tmpMat2, &mato, n)) {
    fout << 5 << "\n";
    return;
  }
  if (CheckSame(&mat, &mato, n)) {
    fout << 6 << "\n";
    return;
  }
  fout << 7 << "\n";
  delete [] tmpMat;
  delete [] tmpMat2;


}
int main() {
  int tests = 1;
  /* fin >> tests; */
  while (tests--) solve();
  return 0;
}
