
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define mp make_pair
#define val first
#define ind second

const int MAXN  = 100010;

int n, s[MAXN];

set <pii> ing;

vector <int> resi, resj, resq, ind;

inline void todoscom(int i){
	if(i==-1) return ;
	for(int a=0;a<n;a++){
		if(s[a]==0 || a==i || s[i]==0) continue;
		int q = min(s[a],s[i]);
		resi.pb(a);
		resj.pb(i);	
		resq.pb(q);
		s[a] -= q;
		s[i] -= q;
	}	
}

bool cmp(int a,int b){
	return pii(resi[a],resj[a]) < pii(resi[b],resj[b]);
}

int main (){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d", &n);

	ing.insert(mp(0,-1));
	ll som = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		ing.insert(mp(s[a],a));
		som += s[a];
	}
	pii mai = *ing.rbegin();
	int i=0, j=1;
	while(mai.val < som  - mai.val){
		while(mai.ind == i || mai.ind == j){
			ing.erase(mai);
			mai = *ing.rbegin();
		}
		//printf("%d %d %d %d\n", i, j, mai.val, mai.ind);
		if(som - mai.val - 2*min(s[i], s[j]) < mai.val){
			int tira = (som+1)/2 - mai.val;  //?
		//	printf("tira %d de %d e %d\n", tira, i, j);
			s[i]-=tira;
			s[j]-=tira;
			resi.pb(i);
			resj.pb(j);
			resq.pb(tira);
			break;
		}
		int q = min(s[i], s[j]);
		resi.pb(i);
		resj.pb(j);
		resq.pb(q);
		if(!(s[j] > mai.val || (s[j]==mai.val && j > mai.ind)))
			ing.erase(mp(s[j],j));
		if(!(s[i] > mai.val || (s[i]==mai.val && i > mai.ind)))
			ing.erase(mp(s[i],i));
		s[j]-=q;
		s[i]-=q;
		som -=2*q;
		if(s[j]==0)
			j++;
		else
			ing.insert(mp(s[j],j));
		
		if(s[i]==0){
			i = j;
			j++;
		}
		else
			ing.insert(mp(s[i],i));	
		mai = *ing.rbegin();
	//	printf("termina com %d %d\n", i, j);
	}
	mai = *ing.rbegin();
//	printf("todos com %d\n", mai.ind);
	todoscom(mai.ind);
	//printf("result\n");
	printf("%d\n", (int)resi.size());
	for(int a=0;a<resi.size();a++){
		if(resi[a] > resj[a])
			swap(resi[a],resj[a]);
		ind.pb(a);
	}
	sort(ind.begin(),ind.end(),cmp);
	for(int a=0;a<resi.size();a++){
		int aa = ind[a];
		printf("%d %d %d\n", resi[aa]+1, resj[aa]+1, resq[aa]);
	}
	return 0;
}
