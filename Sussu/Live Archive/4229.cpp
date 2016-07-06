#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

char s[100];

int res, tam;

map <char, int> val;

int eha(char x){
	return (x=='A');
}

int ganhei(int a, int b){
	if(a > 21) 
		return 0;
	if(b > 21)
		return 1;
	if(a >= b)
		return 1;
	return 0;
}

bool pega(int n){
	int pa, pb, aa, ab;
	pa = val[s[0]] + val[s[2]];
	pb = val[s[1]] + val[s[3]];
	aa = eha(s[0]) + eha(s[2]);
	ab = eha(s[1]) + eha(s[3]);

	for(int a=0;a<n;a++){
		//printf("com pega(%d) peguei %c\n", n, s[a+4]);
		pa += val[s[a+4]];
		aa += eha(s[a+4]);
	}

	for(int a=0;a<aa;a++){
		if(pa + 10 <= 21)
			pa += 10;
	}
	int used = 0;
	if(pb + 10 <= 21 && ab){
		used = 1;
		pb += 10;
	}

	for(int a=n+4;a<tam;a++){
		if(pb < 17){
			pb += val[s[a]];
			if(eha(s[a]) && pb + 10 <= 21){
				pb += 10;
				ab++;
				used = 1;
			}
			if(pb > 21 && used){
				pb -= 10;
				used = 0;
			}

		}
		else
			break;
	}
	if(pb < 17) pb = 22;
	//printf("mao a %d mao b %d\n", pa, pb);
	res = max(res, ganhei(pa, pb));
	return (pa <= 21);
}

int main (){
	for(char a='2';a<='9';a++){
		val[a] = (int)a-'0';
	}
	val['J'] = 10;
	val['Q'] = 10;
	val['K'] = 10;
	val['T'] = 10;
	val['A'] = 1; 	
	while(scanf(" %s", s)!= EOF &&  s[1] != 'O'){
		res = 0;
		tam = strlen(s);
		//printf("%d\n", tam-4);
		for(int a=0;a<=tam-4;a++){
			if(!pega(a))
				break;
		}
		if(res)
			puts("Yes");
		else
			puts("No");
	}
}
