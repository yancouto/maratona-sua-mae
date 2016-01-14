#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 510;

int n,m, s[MAXN*MAXN], apa;

vector <int> ant;

map<int,int> mrk;

bool cmp(int a,int b){
	return a>b;
}

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void apaga(int v){
	for(int a=0;a<ant.size();a++){
		int val = ant[a];
		int aux = gcd(val,v);
		mrk[aux]+=2;
	}
	ant.pb(v);
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n*n;a++){
		scanf("%d", &s[a]);
	}
	sort(s,s+n*n,cmp);
	for(int a=0;a<n*n;a++){
		if(mrk.find(s[a])!=mrk.end() && mrk[s[a]] != 0){
			mrk[s[a]]--;
		}
		else{
			apaga(s[a]);
			printf("%d ", s[a]);
		}
	}
}