#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>



using namespace std;

#define MAXBUF 1024
#define MAXITEM 1024


int line;
int in_comment = 0;
int omit_line = 0;

int counter=1;
string sys[] = {"unsigned","sizeof","enum","auto","break","struct","extern","signed","union",
"goto","default","int","void","float","continue","static","double","char","long long","long","while","for","do","volatile","short","return","extern","switch",
"case","if","else","typedef","const","using","namespace","public","protected",
"private","class","asm","template"};

string sym[] = {">>=","<<=","++","--","&&","||","+=","-=","*=","/=","|=","&=","^=","->","==","!=","::","<<",">>","<=",">=","?","{","}","(",")","[","]","=","~","^","+","-","*",
"|","&","<",">","/","%","!",":",";",",","."};



int is_alpha(char s) {
	if( (s<='Z' && s>='A') || (s<='z' && s>='a') )
		return 1;
	return 0;
}

int is_digit(char s) {
	if( (s<='9' && s>='0')  )
		return 1;
	return 0;
}

int overspace(string buf, int cur) {
	while( buf[cur] == ' ' || buf[cur] == '\t') {
		cur++;
	}
	return cur;
}

int mystrncmp(string buf, int cur, string a) {
	for(int i=0;i<a.length();i++) {
		if(buf[cur+i]!=a[i])
			return -1;
	}
	return 0;
}

int match_sys(string buf, int cur) {
	for(int i=0; i< (int)sizeof(sys)/(int)sizeof(sys[0]); i++) {
			if(mystrncmp(buf,cur,sys[i])==0 && !( is_alpha(buf[cur+sys[i].length()]) || buf[cur+sys[i].length()] == '_' ||  is_digit(buf[cur+sys[i].length()]) ) ) {
				
				cur+=sys[i].length();
				cout<<"SYS"<<" ";//<<counter++<<endl;
				return cur;
			}
	}
	return cur;
}



int match_sym(string buf, int cur) {
	for(int i=0; i< (int)sizeof(sym)/(int)sizeof(sym[0]); i++) {
			if(mystrncmp(buf,cur,sym[i])==0 ) {
				if( buf[cur]=='.' &&   is_digit(buf[cur+1]) )
					return cur;
				cur+=sym[i].length();
				cout<<"SYM"<<" ";//<<"match"<<sym[i]<<counter++<<endl;
				return cur;
			}
	}
	return cur;
}


int match_comment(string buf, int cur) {
	if( buf[cur]=='#' || buf[cur] =='\0' || (buf[cur]=='/' && buf[cur+1]=='/') ) {
		omit_line = 1;
		return cur;
	}
		
	if(buf[cur]=='/' && buf[cur+1]=='*') {
		in_comment = 1;
		cur+=2;
		while( (buf[cur]!='\0') &&  (!(buf[cur]=='*' && buf[cur+1]=='/')) ) {
			cur++;
		}
		if(buf[cur]=='\0'){
			omit_line = 1;
			return cur;
		}
		cur+=2;
		in_comment = 0;
	}
	return cur;
}

int match_str(string buf, int cur) {
	if( buf[cur]=='\"' ) {
		char tmp = buf[cur];
		cur++;
		while(  (buf[cur]!='\0') && (buf[cur]!=tmp || ( (buf[cur])==tmp && (buf[cur-1]=='\\') && (buf[cur-2]!='\\')  )) )
			cur++;
		cur++;
		cout<<"STR"<<" ";//<<counter++<<endl;
	}
	return cur;
}

int isnum(string buf, int cur) {
	if( buf[cur]=='\'' ) {
		char tmp = buf[cur];
		cur++;
		while(  (buf[cur]!='\0') && (buf[cur]!=tmp || ( (buf[cur])==tmp && (buf[cur-1]=='\\') && (buf[cur-2]!='\\')  )) )
			cur++;
		cur++;
		cout<<"NUM"<<" ";//<<counter++<<endl;
		return cur;
	}

	if( (buf[cur]=='.' && is_digit(buf[cur+1])) || is_digit(buf[cur]) ) {
		cur++;
		while(buf[cur]=='.' || is_digit(buf[cur]) || is_alpha(buf[cur]) )
			cur++;
		cout<<"NUM"<<" ";//<<counter++<<endl;
	}
	return cur;

}


int isusr(string buf, int cur) {
	if( buf[cur]=='_' || is_alpha(buf[cur]) ){
		cur ++;
		while(buf[cur]=='_' || is_alpha(buf[cur]) || is_digit(buf[cur]))
			cur++;
		cout<<"USR"<<" ";//<<counter++<<endl;
	}
	return cur;
}



int main() {

	string buf;
	cin>>line;
	//cout<<line<<endl;
	getline(cin,buf);


	
	int cnt =1;
	int cur = 0;
	while(line--) {
		getline(cin,buf);
		//cout<<"\n Line"<<cnt++<<endl;

		cur = 0;
		

		if(in_comment) {
			while( (buf[cur]!='\0') &&  (!(buf[cur]=='*' && buf[cur+1]=='/')) ) {
				cur++;
			}
			if(buf[cur]=='\0')
				break;
			cur+=2;
			in_comment = 0;
		}

		//cur = overspace(buf,cur,size);
		int ret;
		while(1) {
			int flag = 1;
			while(flag) {
				flag = 0;
				cur = overspace(buf,cur);
				ret = match_comment(buf, cur);
				if(omit_line)
					break;
				if(cur!=ret) {
					cur = ret;
					flag = 1;
				}

				cur = overspace(buf,cur);
				ret = match_sys(buf,cur);
				if(ret!=cur) {
					cur = ret;
					flag = 1;
				}


				cur = overspace(buf,cur);
				ret = match_sym(buf,cur);
				if(ret!=cur) {
					cur = ret;
					flag = 1;
				}


				cur = overspace(buf,cur);
				ret = match_str(buf,cur);
				if(ret!=cur) {
					cur = ret;
					flag = 1;
				}

				cur = overspace(buf,cur);
				ret = isnum(buf, cur);
				if(ret!=cur) {
					cur = ret;
					flag = 1;
				}
			}


			cur = overspace(buf,cur);
			cur = isusr(buf, cur);

			

		

			if(omit_line)
				break;

		}

		if(omit_line == 1) {
			omit_line = 0;
			continue;
		}

		

		
		
	}
}