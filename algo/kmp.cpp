#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define cin(n) scanf("%d",&n)
#define gc getchar
typedef vector<int> VI;
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}
const int max_n = (int)1e6;
int pi[max_n];
char P[max_n], T[max_n]; 
int n,m;
void table()
{    
	pi[0] = -1;
	int k = -1;
	for(int i = 1; i <= m; i++) {
		while(k >= 0 && P[k+1] != P[i])
		k = pi[k];
		pi[i] = ++k;
	}
}
void kmp()
{
	int k = 0;
	for(int i = 1; i <= n; i++) {
		while(k >= 0 && P[k+1] != T[i])
			k = pi[k];
		k++;
		if(k == m) {
			cout << i-m+1 << endl;
			k = pi[k];
		}
	}	
}
int main(){
	int N; 
	while(scanf("%d",&N) != EOF){
		scanf("%s",P+1);
		scanf("%s",T+1);
		n = strlen(T+1);
		m = strlen(P+1);
		table();
		kmp();
		cout << endl; 	
	}
}
