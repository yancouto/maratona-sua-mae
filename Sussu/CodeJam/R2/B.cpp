
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXC = 20;

ll res, resa, resb;

int tam;

char s1[MAXC], s2[MAXC];

ll num(char c){
	return (ll)(c - '0');
}

ll abs(ll a, ll b){
	if(a > b) return a-b;
	return b-a;
}

void f(ll a, ll b, int ig, int i){
	//printf("entrei com %lld %lld %d %d\n", a, b, ig, i);
	if(i == tam){
//		printf("%lld %lld %d %d\n", a, b, ig, i);
		if(abs(a,b) < res || (abs(a,b) == res && a < resa) || (abs(a, b) == res && a == resa && b < resb)){
			resa = a;
			resb = b;
			res = abs(a,b);
		}
		return;
	}
	if(ig == -1){
		if(s1[i] == '?' && s2[i] == '?'){
			f(a*10ll + 1, b*10ll, 0, i+1);
			f(a*10ll, b*10ll, ig, i+1);
			f(a*10ll, b*10ll + 1, 1, i+1);
			
		}
		else if(s1[i] == '?'  || s2[i] == '?'){
			if(s1[i] == '?'){
				f(a*10ll + num(s2[i]), b*10ll + num(s2[i]), ig, i+1);
				if(num(s2[i]) != 9) f(a*10ll + num(s2[i])+1, b*10ll + num(s2[i]), 0, i+1);
				if(num(s2[i]) != 0) f(a*10ll + num(s2[i])-1, b*10ll + num(s2[i]), 1, i+1);
			}
			else{
				f(a*10ll + num(s1[i]), b*10ll + num(s1[i]), ig, i+1);
				if(num(s1[i]) != 9) f(a*10ull + num(s1[i]), b*10ll + num(s1[i])+1, 1, i+1);
				if(num(s1[i]) != 0) f(a*10ll + num(s1[i]), b*10ll + num(s1[i])-1, 0, i+1);
			}
		}
		else{
			//printf("%lld %lld %d %d\n", a, b, ig, i);
			int igu = -1;
			if(num(s1[i]) < num(s2[i]))
				igu = 1;
			else if(num(s1[i]) > num(s2[i]))
				igu = 0;
			f(a*10ll + num(s1[i]), b*10ll + num(s2[i]), igu, i+1);
		}
	}
	else if(ig == 0){
		if(s1[i] == '?' && s2[i] == '?')
			f(a*10ll, b*10ll + 9, ig, i+1);
		else if(s1[i] == '?')
			f(a*10ll, b*10ll + num(s2[i]), ig, i+1);
		else if(s2[i] == '?')
			f(a*10ll + num(s1[i]), b*10ll + 9, ig, i+1);
		else
			f(a*10ll + num(s1[i]), b*10ll + num(s2[i]), ig, i+1);
	}
	else{
		if(s1[i] == '?' && s2[i] == '?')
			f(a*10ll + 9, b*10ll, ig, i+1);
		else if(s1[i] == '?')
			f(a*10ll + 9, b*10ll + num(s2[i]), ig, i+1);
		else if(s2[i] == '?')
			f(a*10ll +num(s1[i]), b*10ll, ig, i+1);
		else
			f(a*10ll + num(s1[i]), b*10ll + num(s2[i]), ig, i+1);
	}
}

void pr(ll num){
	ll dez = 1;
	for(int a=0;a<tam;a++){
		if(num/dez==0)
			printf("0");
		dez *= 10;
	}
	if(num != 0)
		printf("%llu", num);
}

int main (){
	for_tests(t, tt){
		res = ULLONG_MAX;
		scanf(" %s %s", s1, s2);
		tam = strlen(s1);
		f(0, 0, -1, 0);
		printf("Case #%d: ", tt);
		
		pr(resa);
		printf(" ");
		pr(resb);
		printf("\n");
	}
}
