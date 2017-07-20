#include<bits/stdc++.h>
using namespace std;
bool p[1000001];
vector<unsigned int>primes;
bool isprime(unsigned int n){
	for(int i=0;primes[i]*primes[i]<=n;i++){
		if(!(n%primes[i]))return 0;
		if(primes[i]==65521)return 1;
	}
	return 1;
}
int main(){
	memset(p,-1,sizeof p);
	p[0]=p[1]=0;
	for(int i=2;i<=1000;i++)
		if(p[i])
			for(int j=i+i;j<1000001;j+=i)
				p[j]=0;
	for(int i=2;i<65536;i++)
		if(p[i])primes.push_back(i);
	int t;
	long long n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n==3){puts("2");continue;}
		if(n>4294967291){
			printf("4294967291\n");
			continue;
		}
		if( n & 1 ) n -= 2;
		else n -= 1;
		if(n<1000000){
			for(int i=n;i>=1;i-=2)
				if(p[i])printf("%d\n",i),i=3;
		}
		else
		for(unsigned int i=n;i>1;i-=2)
			if(isprime(i))printf("%u\n",i),i=3;
	}
}
