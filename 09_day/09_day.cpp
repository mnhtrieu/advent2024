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
  string str;

  vector<ll> v;
  getline(in, str);

  ll num = 0;
  F(str.size()) {
    ll x = str[i] - '0';
    if (i % 2 == 0) { FF(x) v.PB(num); num++;}
    else FF(x) v.PB(-1);
  }

  ll last = v.size()-1;
  FOR(start, 0, v.size()) {
    ll end = 0;
    if (v[start] != -1) continue;
    while(end < (ll)v.size() && v[start+end] == -1) end++;
    if (start+end >= (ll)v.size()) break;
    FF(end) {
      while (v[last-j] == -1) last--;
      if (last-j < start+end) break;
      swap(v[start+j], v[last-j]);
    }
    start += end; 
    last -= end;
  }

  unsigned long long res = 0;
  for(ll i = 0; v[i] != -1; ++ i) res += v[i]*i;
  cout << "Part 1: " << res << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<ll> v;
  unordered_map<ll,ll> cnts;
  getline(in, str);

  ll num = 0;
  F(str.size()) {
    ll x = str[i] - '0';
    if (i % 2 == 0) { FF(x) v.PB(num); cnts[num] = x; num++;}
    else FF(x) v.PB(-1);
  }

  set<ll> processed;
  // auto it = cnts.cbegin();
  // ll last = v.size()-1;
  // for(; it != cnts.cend(); ++ it) {

  //   ll start = 0;
  //   for(; start < v.size(); ++ start) {
  //     ll size = 0;
  //     if (v[start] != -1) continue;
  //     while(size < (ll)v.size() && v[start+size] == -1) size++;
  //     if (start+size >= (ll)v.size()) break;
  //     if (it->bb > size) break;
  //     start += size;
  //   }


  // }
  FOR(start, 0, v.size()) {
    ll size = 0;
    if (v[start] != -1) continue;
    while(size < (ll)v.size() && v[start+size] == -1) size++;
    if (start+size >= (ll)v.size()) break;
    F(v.size()) {
      if (v[i] == -1) cout << ".";
      else cout << v[i];
    }
    cout << endl;
    cout << "found " << size << " free space beginning at " << start << endl;

    auto found = cnts.cbegin();
    for(; found != cnts.cend(); ++ found) {
      if (processed.count(found->aa) || found->bb > size) continue;
      break;
    }

    if (found != cnts.end()) {
      cout << "found " << found->aa << endl;
      ll idx = v.size()-1;
      while (v[idx] != found->aa) idx --;
      if (idx < start) {
        start = 0;

        return;
      }
      FF(found->bb) swap(v[start+j], v[idx-j]);
      processed.insert(found->aa);
      start += found->bb-1;
    }
    else {
      found = cnts.cbegin();
      processed.insert(found->aa);
    }
    
    if (processed.size() == cnts.size()) break;
    
    cout << endl;
  }

  F(v.size()) {
    if (v[i] == -1) cout << ".";
    else cout << v[i];
  }
  cout << endl;

  cout << "Part 2: " << endl; // 6636608781232
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

// 6607511481908 LOW