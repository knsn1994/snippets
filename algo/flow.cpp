#include <iostream>
#include <vector> 
#include <queue> 
#include <cstring>
using namespace std;
#define abs(x) x > 0 ? (x) : (-x)
// FLOYD FULKERSON FLOW MODULE STARTS 
int source, sink; 
int N;
vector<vector<int> > arr;
#define maxn 1000
#define INF 2000000001
int capacity[maxn][maxn]; 
int from[maxn], v[maxn];

int bfs(){
	queue<int> q; 
	memset(v,0,sizeof v);
	memset(from,-1,sizeof from); 
	v[source] = 1; 
	q.push(source);
	int where, next = -1, prev;
	while (!q.empty()) {
		where = q.front(); 
		q.pop();
		for(int i=0;i<arr[where].size();i++){
			next = arr[where][i]; 
			if(v[next] == 0 && capacity[where][next] > 0){
				from[next] = where;
				v[next] = 1; 
				if(next == sink) goto outofwhile; 
				q.push(next);
			}
		}
	} 
	outofwhile:
	int minCap = INF;
	where = sink; 
	while(from[where] != -1){
		prev = from[where]; 
		minCap = min(minCap,capacity[prev][where]);
		where = prev; 
	}
	where = sink; 
	while(from[where] != -1){
		prev = from[where]; 
		capacity[prev][where] -= minCap;
		capacity[where][prev] += minCap;
		where = prev; 
	}
	if(minCap == INF) return 0;
	return minCap; 
}
int maxFlow(){
	int ret = 0; 
	int temp;
	do{
		temp = bfs(); 
		ret += temp;
	} while(temp > 0); 
	return ret; 
}
//FLOYD FLUKERSON FLOW MODULE ENDS

long long x[666], y[666]; 
int main(int argc, char *argv[]) {
	int ts; 
	int p,t,s,c; 
	cin >> ts;
	while(ts--){
		cin >> p >> t >> s >> c; 
		long long d = s*1LL*c; 
		
		source = 0; 
		sink = p+t+1; 
		N = sink + 1;
		arr.clear(); 
		arr.resize(N);
		
		for(int i=1;i<=p+t;i++){
			cin >> x[i] >> y[i]; 
		}
		
		memset(capacity, 0, sizeof capacity); 
		for(int i=1;i<=p;i++){
			for(int j=p+1;j<=p+t;j++){
				if(abs(x[i]-x[j])*200+abs(y[i]-y[j])*200 <= d){
					arr[i].push_back(j);	
					capacity[i][j] = 1;  
				}
			}
			arr[source].push_back(i); 
			capacity[source][i] = 1; 
		}
		for(int i=p+1;i<=p+t;i++){
			capacity[i][sink] = 1; 
			arr[i].push_back(sink); 
		}
		cout << maxFlow() << endl; 
	}
}