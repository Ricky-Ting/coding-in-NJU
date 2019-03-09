#include<cstdio>
#include<string>
using namespace std;
int tmp;
int is_prime[1505];
int satisfied(char * s);
void get_prime();

int main() {
	get_prime();
	printf("hello\n");
	char buf[20];
	unsigned long long maxi=1000000000000000000;
	for(unsigned long long i=1;i<maxi;i++){
		sprintf(buf,"%llu",i);
		//printf("%s\n",buf);
		if(satisfied(buf)){
			printf("%llu\n",i);
		}
	}
}

int satisfied(char * s){
	int sum=0; int ssum=0;
	for(int i=0;i<strlen(s);i++){
		tmp = (s[i]-'0');
		sum+=tmp;
		ssum += (tmp*tmp);
	}
	if(is_prime[sum] && is_prime[ssum])
		return 1;
	return 0;
}



void get_prime(){
	memset(is_prime,1,sizeof(is_prime));
	is_prime[0]=is_prime[1]=0;
	int counter=2;
	while(counter<1500) {
		for(int i=2;i<=(1500/counter);i++) {
			if(i*counter<1500){
				is_prime[i*counter]=0;
			}
			//printf("counter=%d\n",counter);
		}
		counter++;
		while(counter<1500 && is_prime[counter]==0){
			counter++;
			//printf("counter=%d\n",counter);
		}
	}
	return;
}