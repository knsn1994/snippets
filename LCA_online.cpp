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
#define gc getchar_unlocked
typedef vector<int> VI;
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}
const int maxN = 111111,maxL = 17;
int n,m;
int T[maxN],P[maxN][maxL],L[maxN]; 
int LCA(int x, int y){
	if(L[x] < L[y]) x^=y^=x^=y; // swap x and y
	int log; 
	for(log = 1; 1<< log <= L[x];log++); // log is log(L[x]) floor
	log--;
	for(int i = log ; i >= 0; i--)
		if(L[x] - (1<<i) >= L[y])
			x = P[x][i];
	if(x==y)return x; 
	for(int i=log;i >= 0; i--)
		if(P[x][i] != -1 && P[x][i] != P[y][i])
			x = P[x][i] , y = P[y][i];
	return T[x]; 	
} 
int ancestor(int v,int k){
	if(k==0)return v;
	int log = 1; 
	while(1 << log <= k)log++;log--;
	return ancestor(P[v][log],k-(1<<log));
}
int main(){
	int tests=fcin();
	int x,y; 
	while(tests--){
		n = fcin();
		memset(P,-1,sizeof P); 
		L[1] = 0; 
		T[1] = -1;
		int maxLevel = 0, farPoint = 1, diameter = 0;
		for(int i=2;i<=n;i++){
			x = fcin();
			T[i] = x; 
			L[i] = L[x] + 1;  
			P[i][0] = T[i];
			//make LCA Part
			for(int j=1;1<<j < n; j++)
				if(P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
			
			if(L[i] > maxLevel){
				maxLevel ++; 
				diameter ++; 
				cout << diameter << endl; 
				farPoint = i; 
			}
			else {
				int parent = LCA(i,farPoint);
				int temp = L[i] + maxLevel - 2*L[parent]; 
				if(temp > diameter){
					diameter = temp; 
				}
				cout << diameter << endl; 
			}
		} 
	}
}