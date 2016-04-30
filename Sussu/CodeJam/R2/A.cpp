
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


const int MAXC = 2010;

char s[MAXC];

int mrk[500];

vector<int> res;

inline void f(char a){
	mrk[a]--;
}

int main(){
	for_tests(t, tt){
		memset(mrk, 0, sizeof(mrk));
		scanf(" %s", s);
		int tam = strlen(s);
		for(int a=0;a<tam;a++){
			mrk[s[a]]++;
		}
		for(int a=0;mrk['Z']>0;a++){
			f('Z');
			f('E');
			f('R');
			f('O');
			res.pb(0);	
		}
		for(int a=0;mrk['W']>0;a++){
			f('T');
			f('W');
			f('O');
			res.pb(2);	
		}
		for(int a=0;mrk['X']>0;a++){
			f('S');
			f('I');
			f('X');
			res.pb(6);	
		}
		for(int a=0;mrk['U']>0;a++){
			f('F');
			f('O');
			f('U');	
			f('R');
			res.pb(4);	
		}
		for(int a=0;mrk['O']>0;a++){
			f('O');
			f('N');	
			f('E');
			res.pb(1);	
		}
		for(int a=0;mrk['F']>0;a++){
			f('F');
			f('I');	
			f('E');
			f('V');
			res.pb(5);	
		}
		for(int a=0;mrk['S']>0;a++){
			f('S');
			f('V');	
			f('E');
			f('E');
			f('N');
			res.pb(7);	
		}
		
		for(int a=0;mrk['R']>0;a++){
			f('T');
			f('H');	
			f('R');
			f('E');
			f('E');
			res.pb(3);	
		}
		
		for(int a=0;mrk['H']>0;a++){
			f('E');
			f('H');	
			f('I');
			f('G');
			f('T');
			res.pb(8);	
		}
		for(int a=0;mrk['N']>0;a++){
			f('N');
			f('I');
			f('N');
			f('E');
			res.pb(9);
		}
		sort(res.begin(), res.end());
		printf("Case #%d: ", tt);
		for(int a : res){
			printf("%d", a);
		}
		res.clear();
		printf("\n");




	}
}
