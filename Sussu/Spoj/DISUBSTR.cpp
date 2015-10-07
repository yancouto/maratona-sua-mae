#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXC = 1010, P1 = 223, P2 = 349;

int sa[MAXC], tam, lc[MAXC];

ll h1[MAXC], h2[MAXC], exp1[MAXC], exp2[MAXC], res;

string pal;

bool cmp(int a,int b){
    /*cout << "cmp " << a << " " << b << " strings : '"+pal.substr(a,tam-a)+"' e '"+pal.substr(b,tam-b)+"'";
    if(pal.substr(a,tam-a)<pal.substr(b,tam-b))
        printf(" deu\n");
    else
        printf(" n deu\n");*/
    return pal.substr(a,tam-a)<pal.substr(b,tam-b);
}

int lcp(int a,int b){
    if(a>b) swap(a,b);
    int i=0, f = tam-b;
    int m;
    while(i<f){
        m = (i+f+1)/2;
        ll ha1, ha2, ha1b, ha2b;
        ha1=mod(mod(h1[a+m]+modn-mod(h1[a-1]*exp1[m]))*exp1[b-a]);
        ha2=mod(mod(h2[a+m]+modn-mod(h2[a-1]*exp2[m]))*exp2[b-a]);
        ha1b=mod(h1[b+m]+modn-mod(h1[b-1]*exp1[m]));
        ha2b=mod(h2[b+m]+modn-mod(h2[b-1]*exp2[m]));
        printf("%d %d  i %d f %d: %lld == %lld && %lld == %lld\n", a, b, i, f, ha1, ha1b, ha2, ha2b);
        if(ha1==ha1b && ha2==ha2b)
            i=m;
        else
            f=m-1;
    }
    printf("bb deu %d\n", f);
    if(pal[a+f-1]==pal[b+f-1]) f++;
    return f;
}

int main (){
	for_tests(t,tt){
        cin >> pal;
        tam = pal.size();
        exp1[0]=1;
        exp2[0]=1;
        for(int a=1;a<=tam;a++){
            h1[a]=mod(h1[a-1]*P1+(pal[a-1]-'A'));
            h2[a]=mod(h2[a-1]*P2+(pal[a-1]-'A'));
            printf("%lld %lld\n", h1[a], h2[a]);
            sa[a]=a-1;
            exp1[a]=mod(exp1[a-1]*P1);
            exp2[a]=mod(exp2[a-1]*P2);
        }
        exp1[tam]=mod(exp1[tam-1]*P1);
        exp2[tam]=mod(exp2[tam-1]*P2);
        sort(sa,sa+tam,cmp);
        res=(tam*(tam-1))/2;
        for(int a=1;a<=tam-1;a++){
            lc[a]=lcp(sa[a],sa[a+1]);
            res-=lc[a];
        }
        printf("%lld\n", res);
	}
	return 0;
}

