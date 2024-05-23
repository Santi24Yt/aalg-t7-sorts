#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void printv(vector<int> v, string s);
void printvi(vector<int> v, string s);
void printvn(vector<int> v, string s);
void printh(vector<int> v, string s);
void printb(vector<vector<int>> b);

vector<int> bsort(vector<int> a, int nb);

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  srand(time(NULL));

/* Valores mínimo y máximo para los números aleatorios */
  int lb = 100;
  int ub = 999;

  /* Cantidad de números a generar */
  int n = 30;

  vector<int> l(n);
  /* Generar un número aleatorio (en nuestro rango definido) y meterlo 3 veces al vector */
  for (int i = 0; i < n; i++)
  {
    int z = (rand() % (ub - lb + 1)) + lb;
    l[i] = z;
  }

  printv(l, "L");
  bsort(l, 9);

  cout << "\n\n---- 5 buckets\n";
  printv(l, "L");
  bsort(l, 5);
  
}

vector<int> bsort(vector<int> a, int nb)
{
  vector<vector<int>> buckets(nb);
  int m = *(max_element(a.begin(), a.end())) + 1;

  for (int i = 0; i < a.size(); i++)
  {
    int p = (a[i]*nb)/m;
    buckets[p].push_back(a[i]);
  }

  printb(buckets);

  for (int i = 0; i < buckets.size(); i++)
  {
    sort(buckets[i].begin(), buckets[i].end());
  }

  cout << "----ordenar----\n";
  printb(buckets);

  vector<int> r;
  for (auto b : buckets)
  {
    for (auto e : b)
    {
      r.push_back(e);
    }
  }

  printv(r, "R");

  return r;
}

void printv(vector<int> v, string s)
{
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
}

void printvi(vector<int> v, string s)
{
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << i << ":" << v[i];
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
}

void printvn(vector<int> v, string s)
{
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == 0)
    {
      cout << 'N';
    } else {
      cout << v[i];
    }
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
}

void printh(vector<int> v, string s)
{
  ios_base::fmtflags f(cout.flags());
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << "0x" << setfill('0') << setw(4) << hex << uppercase << v[i];
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
  cout.flags(f);
}

void printb(vector<vector<int>> b)
{
  for (int i = 0; i < b.size(); i++)
  {
    cout << "b" << i+1 << ": ";
    for (int j = 0; j < b[i].size(); j++)
    {
      cout << b[i][j];
      if (j + 1 != b[i].size())
      {
        cout << " -> ";
      }
    }
    cout << '\n';
  }
}

