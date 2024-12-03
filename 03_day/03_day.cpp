#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define MOD ((ll)(1e9+7))

#define FILE "demo.in"
//#define FILE "input.in"

void part_1(const string & file);
void part_2(const string & file);
vector<ll> explode(string const & s, char delim);

void part_1(const string & file) {
  ifstream in(file);
  string str, tmp;

  ll res = 0;
  while(getline(in, tmp)) { str += tmp; }

  regex r("mul\\(([0-9]*),([0-9]*?)\\)");
  smatch m;
  string::const_iterator start( str.cbegin() );
  while(regex_search(start, str.cend(), m, r)) {
    res += stoll(m[1]) * stoll(m[2]);
    start = m.suffix().first;
  }
  cout << "Part 1: " << res << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str, tmp;
  ll res = 0;

  while(getline(in, tmp)) { str += tmp; }
  regex r("mul\\(([0-9]*?),([0-9]*?)\\)");
  smatch m;
  str = "do()" + str;
  string::const_iterator start(str.cbegin());
  while(regex_search(start, str.cend(), m, r)) {
    string tmp = str.substr(0, str.find(m.str(0), start - str.cbegin()));
    ll x = tmp.rfind("do()"), y = tmp.rfind("don't()");
    if (x > y) { res += stoll(m[1]) * stoll(m[2]); }
    start = m.suffix().first;
  }
  cout << "Part 2: " << res << endl;
}

vector<ll> explode(string const & s, char delim) {
    vector<ll> res;
    istringstream iss(s);

    for(string token; getline(iss, token, delim);)
      res.PB(stoi(token));

    return res;
}

int main(int argc, const char ** argv){
  ios::sync_with_stdio(0);cin.tie(0);
  
  string file = FILE;
  if (argc > 1) {
    file = argv[1];
  }

  part_1(file);
  part_2(file);
  return 0;
}