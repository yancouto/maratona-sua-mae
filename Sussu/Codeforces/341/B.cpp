
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n;

map<int,int> mrk1, mrk2;

set <int> s1, s2;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		mrk1[i - j]++;
		mrk2[i + j]++; 
		s1.insert(i-j);
		s2.insert(i+j);
	}
	ll res = 0;
	while(!s1.empty()){
		int v = *s1.begin();
		s1.erase(v);
		ll cnt = mrk1[v];
		res += ((cnt)*(cnt-1))/2;
	}
	while(!s2.empty()){
		int v = *s2.begin();
		s2.erase(v);
		ll cnt = mrk2[v];
		res += ((cnt)*(cnt-1))/2;
	}
	cout << res;
}
