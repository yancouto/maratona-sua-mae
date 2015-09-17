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

City cc[50005];

struct Comp{
	bool operator()(int a, int b){
		if(cc[a].qto == cc[b].qto)
			return a < b;
		return cc[a].qto > cc[b].qto;
	}
};

int ict, m, k;
map<string, int> mpc, where; //mpc = mapeia cada cidade a um indice, where = mapeia cada bilionario para a cidade em que se encontra
map<string, ull> hm; //Qto cada bilionario possui
set<int, Comp> st;

void add_city(char s[25]){
	int i;
	string ss = string(s);
	if(!mpc.count(ss)){
		st.insert(ict);
		cc[ict].d = 0;
		cc[ict].name = ss;
		cc[ict].qto = 0;
		mpc.insert(make_pair(ss, ict++));	
	}
}

void add_name(char s[25], ull f){
	int i;
	string ss = string(s);
	hm.insert(make_pair(ss, f));
}

void add_location(string s, int loc){
	if(!where.count(s)) where.insert(make_pair(s, loc));
	else where[s] = loc;
}

int main(){
	char name[25], city[25];
	int n, day; scanf("%d", &n);
	ull f;
	for(int i = 0; i < n; i++){
		scanf("%s %s %lld", name, city, &f);
		add_city(city);
		cc[mpc[city]].qto += f;
		add_name(name, f);
		add_location(string(name), mpc[city]);
	}
	scanf("%d %d", &m, &k);
	int lday = 0;
	for(int i = 0; i < k; i++){
		scanf("%d %s %s", &day, name, city);
		string nme = string(name);
		string cty = string(city);
		add_city(city);
		set<int>::iterator it, it2;
		it = st.begin();
		bool win = true;
		if(st.size() > 1){
			it2 = it; it2++;
			if(cc[*it].qto == cc[*it2].qto)
				win = false;
		}
		if(win) cc[*it].d += day - lday;
		lday = day;
		int bef = where[nme]; //Onde o bilionario desse evento estava
		int	too = mpc[cty]; //Para onde o bilionario desse evento vai
		st.erase(st.find(bef));
		st.erase(st.find(too));
		cc[bef].qto -= hm[nme]; //Atualiza as fortunas da cidade de onde saiu e da cidade pra onde vai
		cc[too].qto += hm[nme];
		where[nme] = too; 
		st.insert(bef);
		st.insert(too);
	}
	set<int>::iterator it, it2;
	it = st.begin();
	if(st.size() > 1){
		it2 = it; it2++;
		if(cc[*it].qto != cc[*it2].qto)	cc[*it].d += m - lday;
	}
	else cc[*it].d += m-lday;
	for(map<string, int>::iterator it = mpc.begin(); it != mpc.end(); ++it){
		City x = cc[it->snd];
		//printf("Cidade %s e %s com %d dias\n", (it->fst).c_str(), x.name.c_str(), x.d);
		if(x.d)	printf("%s %d\n", (it->fst).c_str(), x.d); 
	}
	return 0;
}

