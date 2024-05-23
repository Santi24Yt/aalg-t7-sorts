#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void printv(vector<int> v, string s);
void printvi(vector<int> v, string s);
void printvn(vector<int> v, string s);
void printh(vector<int> v, string s);

vector<int> csort(vector<int> a, int b, int d);

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  srand(time(NULL));

  vector<int> l = {0x3C1A, 0x7E21, 0x0087, 0x374D, 0x001C, 0x04EA, 0x1964, 0xA98F, 0x02B4, 0x0527, 0x01BC, 0x5432, 0x078C, 0x6ADB, 0x027D, 0x4FBC, 0x0B72, 0xEDAD, 0x00AF, 0xC85A, 0x1111, 0x985E, 0xD503, 0xE527, 0x0FAB, 0xAEAE, 0x09FC};

  vector<int> o = l;

  /* LSD */
  for (int i = 0; i < 4; i++)
  {
    o = csort(o, 0x10, i);
    printh(o, "OH");
    printv(o, "O");
  }

}

vector<int> csort(vector<int> a, int b, int d)
{
  int n = a.size();

  vector<int> c(b);

  for (int e : a)
  {
    int digito = (e / (int)pow(b, d)) % b;
    c[digito]++;
  }

  for (int i = 1; i < c.size(); i++)
  {
    c[i] = c[i] + c[i-1];
  }

  vector<int> r(n);

  for (int i = n-1; i >= 0; i--)
  {
    int digito = (a[i] / (int)pow(b, d)) % b;
    r[c[digito] - 1] = a[i];
    c[digito]--;
  }

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

