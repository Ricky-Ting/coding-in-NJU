#include<iostream>

using namespace std;


bool atnewline=true;
bool tested=false;
int wordcounter=0;
char word[80];
int word_num=0;
bool spacehasbeen=false;
bool isword=true;

void hr(void);
void br(void);
void printword(void);

int main(void)
{
	char ch;
	ch=getchar();
	while(ch!=EOF)
	{
		if(tested)
		{
			if(ch=='h')
				hr();
			else
				br();
			ch=getchar();
			ch=getchar();
			ch=getchar();
			tested=false;
			ch=getchar();
			spacehasbeen=false;
			isword=false;
		}
		else if (ch=='<')
		{
			tested=true;
			ch=getchar();
			spacehasbeen=false;
		}
		else if (int(ch)>=33 && int(ch)<=126)
		{
			word[word_num]=ch;
			word_num++;
			ch=getchar();
			spacehasbeen=false;

		}
		else 
		{
			printword();
			ch=getchar();
		}

	}
	cout<<endl;

}

void hr(void)
{
	
	if(!atnewline)
		cout<<endl;
	for(int i=1;i<=80;i++)
	{
		cout<<'-';
	}
	cout<<endl;
	atnewline=true;
	wordcounter=0;


}

void br(void)
{
	cout<<endl;
	atnewline=true;
	wordcounter=0;
}

void printword(void)
{
	
	/* if(!spacehasbeen && isword)
	{
			cout<<' ';
			wordcounter++;
			spacehasbeen=true;
			isword=false;
	} */
	if(word_num==0)
		return;
	if(wordcounter+word_num+1>80)
	{
		cout<<endl;
		atnewline=true;
		wordcounter=0;

	}
	if(!atnewline)
		cout<<' ';
	for(int i=0;i<word_num;i++)
	{
		cout<<word[i];
		word[word_num]='\0';
	}
	wordcounter=wordcounter+word_num+1;

	atnewline=false;
	word_num=0;
	isword=true;

	
}