#include<bits/stdc++.h>
using namespace std;

int power(long long n){
	long long ret=1,cur=2;
	for(long long i=0;i<63;i++){
		if(n&((long long )1<<i))
			ret=(ret*cur)%98777;
		cur=(cur*cur)%98777;
	}
	return ret;
}

int main(){
	int t;
	long long n,last;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n%2){
			n++;
			last=(n-1)*2;
			n=((n-2)/2)*last+last/2;
			n=n-last+1;
		}
		else{
			last=(n-1)*2;
			n=((n-2)/2)*last+last/2;
		}
		printf("%d\n",power(n));
	}
}
