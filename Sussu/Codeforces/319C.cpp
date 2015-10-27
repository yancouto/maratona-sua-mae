#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;


const int MAXN = 100010;
const long long INF = 100000000000;
int n, deg;

long long dp[MAXN];

struct arvore{
	long long c, h;
} arv[MAXN];

struct convex{
	long long x;
	int i;
} s[MAXN];

inline void recebe(long long xx,int ii){
	//printf("recebe %d %f %d\n", deg, xx, ii);
	s[deg].x=xx;
	s[deg].i=ii;
	deg++;
}

inline double xcontato(int i,int j){
	//printf("entra xcontato deg %d a %d\n", i, j);
	long long a1 = arv[i].c, a2 = arv[j].c; 
	long long b1 = dp[i], b2 = dp[j]; // na real que eh dp
	long long xres = (long long)ceil((double)(b2-b1)/((double)(a1-a2)));
	//printf("xcontato deu %f\n", xres);
	return xres;
}

inline int bb(int i,int f,double val){
	while(i<f){
		int m = (i+f+1)/2;
		if(s[m].x <= val)	
			i=m;	
		else
			f=m-1;
	}
	//printf("bb de %f deu %d\n", val, i);
	return i;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++)
		cin >> arv[a].h;
	for(int a=1;a<=n;a++)
		cin >> arv[a].c;
	recebe(-INF,0);
	dp[0]=0;
	for(int a=1;a<=n;a++){
		int degaux = bb(0,deg-1,arv[a].h);
		int ind = s[degaux].i;
		dp[a] = dp[ind] + arv[a].h*arv[ind].c;
		while(deg>1 && xcontato(s[deg-1].i,a)<=s[deg-1].x){
			deg--;
		}
		recebe(xcontato(s[deg-1].i,a),a);
	}
	cout << dp[n];
	return 0;
}
