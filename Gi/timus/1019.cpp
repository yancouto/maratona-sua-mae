#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
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

struct Evento{
	int cor, pty;
	Evento(){}
	Evento(int cor, int pty) : cor(cor), pty(pty) {}
	bool operator < (const Evento &e) const { return pty > e.pty; } 
};

pair<int, Evento> ev[10010];
set<Evento> st;

int main(){
	int k; scanf("%d", &k);
	int iev = 0;
	ev[iev++] = make_pair(0, Evento(0, 1));
	ev[iev++] = make_pair(1000000000, Evento(0, -1));

	for(int i = 2; i < k+2; i++){
		int a, b; char c;
		scanf("%d %d %c", &a, &b, &c);
		ev[iev++] = make_pair(a, Evento((c == 'b'), i));
		ev[iev++] = make_pair(b, Evento((c == 'b'), -i));
	}

	sort(ev, ev+iev);
	st.insert(Evento(0, 1));
	int lwhite = 0, ini = 0, fim = -1;

	for(int i = 1; i < iev; i++){
		bool bwhite = true;
		if((st.begin()->cor) != 0) bwhite = false;
		int hm = ev[i].fst - lwhite;			
		if(ev[i].snd.pty < 0) 
			st.erase(Evento(ev[i].snd.cor, -ev[i].snd.pty)); 
		else st.insert(ev[i].snd);
		bool awhite = true;
		if((st.begin()->cor) != 0) awhite = false;	
		if(bwhite){
			if(hm > fim - ini + 1){
				ini = lwhite; 
				fim = ev[i].fst - 1; //Checar se lado direito é fechado 
			}
			if(!awhite) 
				lwhite = 1000000015;	
		}
		else if(awhite) 
			lwhite = ev[i].fst;
	}
	printf("%d %d\n", ini, fim+1); 
	return 0;
}
