#include<iostream>
using namespace std;
int numofquarters,numofdimes,numofpennies;
void compute_coin(int coin_value,int* number,int* amount_left);
int main(void)
{
	int n;
	while(cin>>n)
	{
		numofquarters=numofdimes=numofpennies=0;
		while(n>0)
			if(n>=25)
				compute_coin(25,&numofquarters,&n);
			else if(n>=10)
				compute_coin(10,&numofdimes,&n);
			else
				compute_coin(1,&numofpennies,&n);
		cout<<numofquarters<<" quarters(s) "<<numofdimes<<" dime(s) "<<numofpennies<<" penny(pennies)"<<endl;
	}
	
	return 0;
}

void compute_coin(int coin_value,int* number,int* amount_left)
{
	if((*amount_left)==0)
		return;
	*number=(*amount_left)/coin_value;
	*amount_left=(*amount_left)%coin_value;
	return;
}
