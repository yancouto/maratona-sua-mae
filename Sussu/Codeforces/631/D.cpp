
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m;

map <pii, int> ind;

pii rev[MAXN];

pii s[MAXN], q[MAXN], sc[MAXN], qc[MAXN];

int h[MAXN], nd[MAXN], ff[MAXN];
ll res;

int degs, degq;

bool pod(pii a,pii b){
	return a.snd == b.snd && a.fst >= b.fst;
}

int main (){
	scanf("%d%d", &n, &m);
	char c;
	for(int a=0;a<n;a++){
		scanf("%I64d-%c", &s[a].fst, &c);
		s[a].snd = c;
	}
	for(int a=0;a<m;a++){
		scanf("%I64d-%c", &q[a].fst, &c);
		q[a].snd = c;
	}
	int ult=-1;
	degs = 0;
	for(int a=0;a<n;a++){
		if(s[a].snd == ult){
			sc[degs-1].fst += s[a].fst;
		}
		else{
			ult = s[a].snd;
			sc[degs] = s[a];
			degs++;
		}

	}
	ult=-1;
	degq = 0;
	for(int a=0;a<m;a++){
		if(q[a].snd == ult){
			qc[degq-1].fst += q[a].fst;
		}
		else{
			ult = q[a].snd;
			qc[degq] = q[a];
			degq++;
		}
	}
	int degi = 1;
	if(degq > 2){
		for(int a=0;a<degs;a++){
			if(ind.find(sc[a]) == ind.end()){
				rev[degi] = sc[a];
				ind[sc[a]] = degi++;
			}
			h[a+1] = ind[sc[a]];
		}
		for(int a=1;a<degq-1;a++){
			if(ind.find(qc[a]) == ind.end()){
				ind[qc[a]] = degi++;
			}
			nd[a] = ind[qc[a]];
		}
		ff[0] = 0;ff[1] = 0;
		int tam = degq - 2; 
		for(int a=2;a<=tam;a++){
			int aa = a-1;
			while(aa!=0 && nd[ff[aa]+1]!=nd[a]){
				aa=ff[aa];
			}
			if(nd[ff[aa]+1]==nd[a]) ff[a]=ff[aa]+1;
			else ff[a]=0;
			//printf("%d %d\n", a, ff[a]);
		}
		int t = degs;
		int i=0;
		for(int a=0;a<t;a++){
			while(i!=0 && h[a]!=nd[i+1]){
				i=ff[i];
			}
			if(h[a]==nd[i+1]){
				i++;
				if(i==tam){
				//	printf("achei mais ou men %d ve se pod %d e qc[0] e sc[%d] qc[%d]\n", a, a-tam, a+1, degq-1);
					i=ff[i];
					if(a-tam > 0 && pod(sc[a-tam-1], qc[0]) && pod(sc[a], qc[degq-1]))
						res++;
				}
			}
		}
	}
	else{
		if(degq == 1){
			for(int a=0;a<degs;a++){
				if(pod(sc[a], qc[0])){
	//				printf("pode %d\n", a);
					res += sc[a].fst - qc[0].fst + 1;
				}
			}
		}
		else{
			for(int a=0;a<degs-1;a++){
				if(pod(sc[a], qc[0]) && pod(sc[a+1], qc[1]))
					res++;
			}
		}
	}
	printf("%I64d", res);
}
