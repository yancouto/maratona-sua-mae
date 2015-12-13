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


const int MAXN = 110;

int n, k, t[MAXN], nres, tres, tem;

bool cmp(int a,int b){
	return a<b;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &t[a]);
	}
	if(t[k]<=300){
		nres++;
		tres+=t[k];	
		tem+=t[k];
		t[k] = 10000;
	}
	else{
		puts("0 0");
		return 0;
	}
	sort(t,t+n,cmp);
	for(int a=0;a<n;a++){
		if(t[a] + tem <= 300){
			nres++;
			tres += t[a]+tem;
			tem += t[a];
		}
		else
			break;
	}
	printf("%d %d\n", nres, tres);
	return 0;
}