#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAXN = 100010;

int n, t;
long long nw, nb, cw, cb, res;

struct {
	long long n;
	char t;
}  s[MAXN];

inline long long mdc(long long a,long long b){
	if(b==0) return a;
	return mdc(b,a%b);
}

int main (){
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		scanf("%d", &n);
		nw=nb=res=0;
		for(int a=0;a<n;a++){
			scanf("%lld %c", &s[a].n, &s[a].t);
			if(s[a].t=='W')
				nw+=s[a].n;
			else
				nb+=s[a].n;
		}
		if(nw==0 || nb==0){
			printf("%lld\n", nw+nb);
			continue;
		}
		long long d = mdc(nw,nb);
		nw/=d;
		nb/=d;
		cb=cw=0;
		for(int a=0;a<n;a++){
			if(s[a].t=='W'){
				if(cb!=0 && cb%nb==0){
					long long quero = (cb/nb)*nw;
					if(quero <= cw+s[a].n){
						cw = cw+s[a].n-quero;
						cb=0;
						res++;
					}
					else
						cw+=s[a].n;
				}
				else
					cw+=s[a].n;
			}
			else{
				if(cw!=0 && cw%nw==0){
					long long quero = (cw/nw)*nb;
					if(quero<=cb+s[a].n){
						cb = cb+s[a].n-quero;
						cw=0;
						res++;
					}
					else
						cb+=s[a].n;
				}
				else
					cb+=s[a].n;
			}
		}
		assert(cw+cb==0);
		printf("%lld\n", res);
	}
	return 0;
}
