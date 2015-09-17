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
	string name;
	ull qto;
	int d;
};

struct Evento{
	string who;
	int too;
	Evento() {}
	Evento(string who, int too) : who(who), too(too) {};
};

City cc[70005];

struct Comp{
	bool operator()(int a, int b){
		if(cc[a].qto == cc[b].qto)
			return a > b;
		return cc[a].qto > cc[b].qto;
	}
};

int ict, m, k;
map<string, int> mpc;
map<string, pair<ull, int> > bil;
set<int, Comp> st;

int add_city(char s[25]){
	int i;
	string ss = string(s);
	if(!mpc.count(ss)){
		cc[ict].d = 0;
		cc[ict].name = ss;
		cc[ict].qto = 0;
		mpc.insert(make_pair(ss, ict++));	
		return ict-1; 
	}
	int ret = mpc[ss];
	st.erase(ret);
	return ret;
}

void add_bil(char s[25], ull f, int where){
	int i;
	string ss = string(s);
	bil.insert(make_pair(ss, make_pair(f, where)));
}

vector<Evento> ev[70005];

int calc_winner(){
	set<int> :: iterator it, it2;
	it = st.begin();
	if(st.size() == 1) return *it;
	it2 = it; it2++;
	if(cc[*it].qto == cc[*it2].qto) return -1;
	return *it;
}

int main(){
	char name[25], city[25];
	int n, day; scanf("%d", &n);
	ull f;
	for(int i = 0; i < n; i++){
		scanf("%s %s %lld", name, city, &f);
		int ind = add_city(city);
		cc[ind].qto += f;
		st.insert(ind);
		add_bil(name, f, ind);
	}
	scanf("%d %d", &m, &k);
	for(int i = 0; i < k; i++){
		scanf("%d %s %s", &day, name, city);
		int ind = add_city(city);
		st.insert(ind);
		ev[day].pb(Evento(name, ind)); 		
	}
	int lwinner = calc_winner();
	for(int i = 1; i <= m; i++){
		if(lwinner != -1) cc[lwinner].d++;
		if(ev[i].empty()) continue;
		for(int k = 0; k < ev[i].size(); k++){
			map<string, pair<ull, int> > :: iterator it = bil.find(ev[i][k].who);
			pair<ull, int> info = it->snd;
			int bef = info.snd, too = ev[i][k].too;
			if(bef == too) continue;
			st.erase(bef); cc[bef].qto -= info.fst; st.insert(bef);
			st.erase(too); cc[too].qto += info.fst; st.insert(too);
			(it->snd).snd = too;	
		}
		lwinner = calc_winner();
	}
	for(map<string, int>::iterator it = mpc.begin(); it != mpc.end(); ++it)
		if(cc[it->snd].d) printf("%s %d\n", (it->fst).c_str(), cc[it->snd].d);
	return 0;
}

