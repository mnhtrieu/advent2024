#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
#define FOR(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define F(n) FOR(i, 0, n)
#define FF(n) FOR(j, 0, n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a, b) (fabs(a - b) <= (fabs(a + b) * EPS))
#define MOD ((ll)(1e9 + 7))

#define FILE "demo.in"
// #define FILE "input.in"

void part_1(const string &file);
void part_2(const string &file);
vector<ll> explode(string const &s, char delim);

int sgn(ll val)
{
  return (0 < val) - (val < 0);
}

void part_1(const string &file)
{
  ifstream in(file);
  string str;

  ll safe = 0;
  while (getline(in, str))
  {
    vector<ll> x = explode(str, ' ');
    ll s = sgn(x[0] - x[1]);
    bool success = true;
    F(x.size() - 1)
    {
      ll y = x[i] - x[i + 1];
      if (abs(y) >= 1 && abs(y) <= 3 && sgn(y) == s)
        continue;
      success = false;
      break;
    }
    if (success)
      safe++;
  }

  cout << "Part 1: " << safe << endl;
}

void part_2(const string &file)
{
  ifstream in(file);
  string str;

  ll safe = 0;
  while (getline(in, str))
  {
    vector<ll> x = explode(str, ' ');
    
    ll s = sgn(x[0] - x[1]);
    bool success = true;
    F(x.size() - 1) {
      ll y = x[i] - x[i + 1];
      if (abs(y) >= 1 && abs(y) <= 3 && sgn(y) == s) continue;
      success = false;
      break;
    }
    
    if (success) safe++;
    else {
      ll skip = 0;
      while (skip < (ll)x.size()) {
        vector<ll> y = x;
        success = true;
        y.erase(y.begin() + skip);
        ll s2 = sgn(y[0] - y[1]);
        F(y.size() - 1) {
          ll val = y[i] - y[i + 1];
          if (abs(val) >= 1 && abs(val) <= 3 && sgn(val) == s2) continue;
          success = false;
          break;
        }
        if (success) { safe++; break; }
        skip++;
      }
    }
  }

  cout << "Part 2: " << safe << endl;
}

vector<ll> explode(string const &s, char delim)
{
  vector<ll> res;
  istringstream iss(s);

  for (string token; getline(iss, token, delim);)
    res.PB(stoi(token));

  return res;
}

int main(int argc, const char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string file = FILE;
  if (argc > 1)
  {
    file = argv[1];
  }

  part_1(file);
  part_2(file);
  return 0;
}
