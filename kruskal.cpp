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
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}

typedef vector<int> VI;
typedef pair<int,int> PI;
struct str{int p,l;str(int P=0,int L=0){p=P;l=L;}}; // profit & loss
bool operator<(str a,str b){return a.p > b.p ||(a.p == b.p && a.l < b.l);} //compare for str
typedef pair<str,PI> PIP;
vector<PIP> edges; 
VI Set;
int n,m1,m2,m;

void merge(int x, int y)
{
    Set[Set[x]]=Set[y];
}

int retSet(int x)
{
              if(Set[x]==x)return x;
              return Set[x]=retSet(Set[x]);
}

str kruskal()
{
    PIP temp;int x,y;str cost = str();int counter=0;
    for(int i=0;i<m;i++)
    {
            temp=edges[i];
            x = retSet(temp.second.first);
            y = retSet(temp.second.second);
            if(x==y)continue;
			merge(x,y);
            cost.p+=temp.first.p;
            cost.l+=temp.first.l;
			counter++;
    }
    if(counter<n-1)return str(-1,-1);
    return cost;
}

int main()
{
	int t = fcin();
    int x,y,c;
	while (t--) {
		n = fcin();
		m1 = fcin();
		m2 = fcin();
		m = m1+m2;
		edges.clear();
		Set.clear();
		Set.resize(n);
		for(int i=0;i<n;i++)Set[i]=i; 
		for(int i=0;i<m1;i++){
			x = fcin();
			y = fcin();
			c = fcin();
			edges.push_back(make_pair(str(0,c),make_pair(x,y)));
		}
		for(int i=0;i<m2;i++){
			x = fcin();
			y = fcin();
			c = fcin();
			edges.push_back(make_pair(str(c,c),make_pair(x,y)));
		}
		sort(edges.begin(),edges.end());
		
		str ans = kruskal();
		if(ans.p == -1)cout <<"Impossible"<<endl;
		else cout<<ans.p <<" " << ans.l<< endl;
	}
}
