// (10^p_len) signifies the number system in which bigints are stored.
// N should be set in a way to account for the largest possible bigint needed
// It doesn't have a sign variable for negative bigints. That is usually never required but that // is easy to extend, if needed.


#define p_len 4
const int p=10000;
#define NN 30/p_len

struct BigInt
{
	int len;
	int A[NN];
	BigInt(LL n=0)
	 {
		for(len=0;n>0;n/=p) A[len++]=n%p;
	 }
};

void operator+=(BigInt &a,const BigInt &b)
{
	int i,div=0;
	for(i=0;i<a.len || i<b.len;i++)
	 {
		if(i<a.len) div+=a.A[i];
		if(i<b.len) div+=b.A[i];
		  a.A[i]=div%p;
		div/=p;
	 }
	if(div>0) a.A[i++]=div;
	 a.len=i;
}

void operator-=(BigInt &a,const BigInt &b)
{
	int i,div=0;
	for(i=0;i<a.len;i++)
	 {
		div+=a.A[i]-(i<b.len?b.A[i]:0)+2*p;
		  a.A[i]=div%p;
		div=div/p-2;
	 }
	for(;i-->=0 && a.A[i]==0;);
	 a.len=i+1;
}

BigInt operator*(BigInt &a,BigInt&b)
{
	 BigInt prod(0);
	memset(prod.A,0,sizeof prod.A);
	if(b.len==0 || a.len==0) return prod;
	int i,j,div;
	for(i=0;i<a.len;i++)
	 {
		if(a.A[i]>0)
		  {
			div=0;
			for(j=0;j<b.len;j++)
			   {
					div+=prod.A[i+j]+a.A[i]*b.A[j];
					prod.A[i+j]=div%p;
					div/=p;
			   }
			if(div>0) prod.A[i+j]=div;
		  }
	 }
	 prod.len=a.len+b.len;
	if(prod.A[prod.len-1]==0) prod.len--;
	return prod;
}

BigInt operator*(int b,const BigInt &a)
{
	 BigInt prod(0);
	if(b==0) return prod;
	int i,div=0;
	for(i=0;i<a.len;i++)
	 {
		div+=a.A[i]*b;
		  prod.A[i]=div%p;
		div/=p;
	 }
	for(;div>0;div/=p) prod.A[i++]=div%p;
	 prod.len=i;
	return prod;
}

void operator*=(BigInt &a,int b)
{
	if(b==0) a.len=0; else
	 {
		int i,div=0;
		for(i=0;i<a.len;i++)
		  {
			div+=a.A[i]*b;
			   a.A[i]=div%p;
			div/=p;
		  }
		for(;div>0;div/=p) a.A[i++]=div%p;
		  a.len=i;
	 }
}

bool operator>(const BigInt &a,const BigInt &b)
{
	if(a.len!=b.len) return (a.len>b.len);
	int i;
	for(i=a.len-1;i>=0 && a.A[i]==b.A[i];i--);
	return (i>=0 && a.A[i]>b.A[i]);
}

void operator/=(BigInt &a,int q)
{
	int c=0,i;
	for(i=a.len-1;i>=0;i--)
	 {
		  c=p*c+a.A[i];
		  a.A[i]=c/q;
		c%=q;
	 }
	for(i=a.len-1;i>=0 && a.A[i]==0;i--);
	 a.len=i+1;
}

BigInt operator%(BigInt &a,BigInt &b)
{
	 BigInt s,w;
	int i,j,v,vv=0,m=b.len;
	 s.len=0;
	for(i=0;i<=m;i++) s.A[i]=0;
	if(b.A[m-1]<p/2)
	 {
		vv=p/(b.A[m-1]+1);
		a*=vv;b*=vv;
	 }
	 v=b.A[m-1];
	for(i=a.len-1;i>=0;i--)
	 {
		for(j=s.len;j>0;j--) s.A[j]=s.A[j-1];
		s.A[0]=a.A[i];
		for(j=s.len;j>=0 && s.A[j]==0;j--);
		  s.len=j+1;
		int q=(p*s.A[m]+s.A[m-1])/v;
		if(q>=p) q=p-1;
		if(q*b>s){q--;if(q*b>s)q--;}
		  w.A[i]=q;
		s-=q*b;
	 }
	if(vv)
	 {
		a/=vv;b/=vv;s/=vv;
	 }
	for(i=a.len-1;i>=0 && w.A[i]==0;i--);
	 w.len=i+1;
	return s;
}


