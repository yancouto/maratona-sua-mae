#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

struct City{
	ull qto;
	int d;
};


map<string, int> mpc, where;
map<string, ull> hm;
int ict, m, k;
City cc[50005];

struct Comp{
	bool operator()(int a, int b){
		if(cc[a].qto == cc[b].qto)
			return a < b;
		return cc[a].qto < cc[b].qto;
	}
}

set<int, Comp> st;

void add_city(char s[25]){
	int i;
	for(i = 0; s[i] != '\0'; i++);
	string ss = string(s, s + i);
	if(!mpc.count(ss)){
		st.insert(ict);
		mpc.insert(make_pair(ss, ict++));	
	}
}

void add_name(char s[25], ull f){
	int i;
	for(i = 0; s[i] != '\0'; i++);
	string ss = string(s, s + i);
	hm.insert(make_pair(ss, f));
}

void add_location(string s, int loc){
	if(!where.count(s)) where.insert(make_pair(s, loc));
	else where[s] = loc;
}

string give_str(char s[25]){
	int i;
	for(i = 0; s[i] != '\0'; i++);
	return string(s, s+i);
}

int main(){
	char name[25], city[25];
	int n, f, day; scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %s %lld", name, city, &f);
		add_city(city);
		cc[mpc[city]].qto += f;
		add_name(name, f);
		add_location(name, mpc[city]);
	}
	scanf("%d %d", &m, &k);
	bool win = true;
	int lday = 0;
	for(int i = 0; i < k; i++){
		scanf("%d %s %s", &day, name, city);
		string nme = give_str(name);
		string cty = give_str(city);
		add_city(city);
		set<int>::iterator it2, it = st.end();
		it--;
		City a, b;
		a = cc[*it];
		if(st.size() > 1){
			it2 = it; it2--;
			b = cc[*it2];
			if(a.qto == b.qto)
				win = false;
		}
		if(win){
			a.d += day - lday;
			lday = day;
		}
		int bef = where[nme];
		int	too = mpc[cty]; 	
		cc[bef].qto -= hm[nme];
		cc[too].qto += hm[nme];
	}
	return 0;
}

