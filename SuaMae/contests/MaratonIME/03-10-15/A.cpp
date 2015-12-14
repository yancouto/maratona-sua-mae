
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

const int MAXC = 110;

const ll DOIS = (1LL << 32)-1;

int n, val[500], ta, tb, tr;

char op, A[MAXC], B[MAXC], R[MAXC], bas[100];

bool valid(ll a,ll b,ll c){
	if(a<1 || b<1 || a>DOIS || b>DOIS || c>DOIS)
		return false;
	if(op=='+')
		return (a+b==c);
	else if(op=='-')
		return (a-b==c && c>0);
	else if(op=='*')
		return (a*b==c);
	else{
		if(b==0) return false;
		return (a%b==0 && a/b==c);
	}
}

int main (){
	for(int a=1;a<10;a++){
		val['1'+a-1]=a;
		bas[a]='1'+a-1;
		printf("%c - > %d\n", '1'+a-1, a);
	}
	for(int a='a';a<='z';a++){
		val[a]=10+a-'a';
		bas[10+a-'a']=a;
		printf("%c -> %d\n", a, val[a]);
	}
	bas[36]='0';
	for(int a=1;a<=36;a++){
		printf("%d >> %c\n", a, bas[a]);
	}
	scanf("%d", &n);
	for(int z=0;z<n;z++){
		scanf(" %s", A);
		scanf(" %c", &op);
		scanf(" %s", B);
		scanf(" = ");
		scanf(" %s", R);
	//	printf("leitura strings:\n%s\n", A);
	//	printf("%s\n%s\n%c\n", B, R, op);
		ta= strlen(A);
		tb = strlen(B);
		tr = strlen(R);
		int mc=0;
		for(int a=0;a<ta;a++){
			mc=max(mc,val[A[a]]);
		}
		for(int a=0;a<tb;a++){
			mc=max(mc,val[B[a]]);
		}
		for(int a=0;a<tr;a++){
			mc = max(mc,val[R[a]]);
		}
	//	printf("mc %d\n\n", mc);
		int ver=0;
		if(mc==1) mc--;
		int fodeu=0;
		for(int b = mc+1;b<=36;b++){
			long long va=0, vb=0, vr=0;
			for(int a=0;a<ta;a++){
				va*=b;
				va+=val[A[a]];
				if(va>DOIS){
					fodeu=1;
					break;
				}
			}
			if(fodeu==1) break;
			for(int a=0;a<tb;a++){
				vb*=b;
				vb+=val[B[a]];
				if(vb>DOIS){
					fodeu=1;
					break;
				}
			}
			if(fodeu==1) break;
			for(int a=0;a<tr;a++){
				vr*=b;
				vr+=val[R[a]];
				if(vr>DOIS){
					fodeu=1;
					break;
				}
			}
			if(fodeu==1) break;
			if(valid(va,vb,vr)){
				printf("%c", bas[b]);
				ver=1;
			}
		}
		if(ver==0) printf("invalid");
		ver=0;
		printf("\n");
	}
	return 0;
}
