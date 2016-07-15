#include <bits/stdc++.h>
using namespace std;


const int MAXN = 51234;
const long double EPS = 1e-11;

int n;
struct ptn {
	long double x, y;
} s[MAXN];

int main (){
	while(scanf("%d", &n)!=EOF && n != 0){
		long double mini = DBL_MIN;
		for(int a=0;a<n;a++){
			scanf("%Lf %Lf", &s[a].x, &s[a].y);
			mini = max(mini, abs(s[a].y));
		}
		long double i = mini, j = 1e7;
		int it = 0;

		long double xi, xs;
		long double m;

		while(it < 400){
			m = (i + j)/2;
			xi = -3000000.0;
			xs = 3000000.0;	
			for(int a=0;a<n;a++){
				long double diff = m*m -s[a].y*s[a].y;
				if(diff > -EPS && diff < EPS){
					diff = 0;
				}	
				xi = max(xi, -sqrt(diff) + s[a].x);
				xs = min(xs, sqrt(diff) + s[a].x);
			}

			if(xi - xs > EPS)
				i = m;
			else
				j = m;
			
			it++;
		}
		printf("%.9Lf %.9Lf\n", xi, m);
	}
}
