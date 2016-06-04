
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

char m[5][5];

pii p[] = {pii(1, 1), pii(1, 2), pii(1, 3), pii(2, 3), pii(3, 3), pii(3, 2), pii(3, 1), pii(2, 1)};

int ant(int v){
	if(v<0) return 7;
	return v;
}

int main (){
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
			scanf(" %c", &m[a][b]);
		}
	}
	int min = 1000, imin;
	for(int a=0;a<8;a++){
		if(m[p[a].fst][p[a].snd]-'0' < min && m[p[a].fst][p[a].snd] != '?'){
			min = m[p[a].fst][p[a].snd] - '0';
			imin = a;
		}
	}
	int ok = 1;
	int mrk = 0;
	int num = -1;
	int esp = min;
	for(int d = imin;d != imin || mrk == 0;d = (d+1)%8){
		//printf("to em %d %d %c\n", p[d].fst, p[d].snd, m[p[d].fst][p[d].snd]);
		mrk=1;
		if(m[p[d].fst][p[d].snd] != '?'){
	//		printf("nao e ? %d\n", esp);
			if(m[p[d].fst][p[d].snd]-'0' != esp){
				ok = 0;
				break;
			}
		}
		esp = (esp-1)%8 + 2;
	}
	//printf("ok %d\n", ok);
	mrk = 0;
	if(ok){
		for(int d = imin;d != imin || mrk == 0;d = (d+1)%8){
			mrk=1;
			if(m[p[d].fst][p[d].snd] != '?'){
				num = m[p[d].fst][p[d].snd]-'0';
			}	
			if(m[p[d].fst][p[d].snd] == '?'){
				m[p[d].fst][p[d].snd] = num + '0';
			}
			num = (num-1)%8 + 2; 
		}
	}
	if(!ok){
		for(int d = imin;d != imin || mrk == 0;d = ant(d-1)){
			mrk=1;
			if(m[p[d].fst][p[d].snd] != '?'){
				num = m[p[d].fst][p[d].snd]-'0';
			}	
			if(m[p[d].fst][p[d].snd] == '?'){
				m[p[d].fst][p[d].snd] = num + '0';
			}
			num = (num-1)%8 + 2; 
		}		
	}
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
			printf("%c", m[a][b]);
		}
		printf("\n");
	}
}
