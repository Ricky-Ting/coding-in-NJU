#include<iostream>
#include<string>
#include<cctype>
#include<cassert>
using namespace std;

string keyword[] = {"unsigned","sizeof","enum","auto","break","struct","extern","signed","union",
"goto","default","int","void","float","continue","static","double","char","long long","long","while","for","do","volatile","short","return","extern","switch",
"case","if","else","typedef","const","using","namespace","public","protected",
"private","class","asm","template"};

string punc[] = {">>=","<<=","++","--","&&","||","+=","-=","*=","/=","|=","&=","^=","->","==","!=","::","<<",">>","<=",">=","?","{","}","(",")","[","]","=","~","^","+","-","*",
"|","&","<",">","/","%","!",":",";",",","."};

string test_array[3000];

void test(string a){
	/*
	static int t = 0;
	assert(a.compare(test_array[t]) == 0);
	t++;
	*/
}
int mycounter=1;
int main(){
	/*
	string a;
	a = "111";
	int t = 0;
	while(a[0] != '0'){
		cin >> test_array[t];
		a = test_array[t];
		t++;
	}
	cout << "Fucking coming ��" << endl;
	*/
	int line_num;
	cin >> line_num;
	
	bool is_maltiline_comment = false; 
	while(line_num--){
		//cout << endl;
		
		string line;
		getline(cin, line);
		//��Ժ����� 
		if(line[0] == '#')
			continue;
		
		//USR��SYS���ж� 
		int i = 0;
		//for(int i(0);i < (int)line.length();i++){
		while(i < (int)line.length()){
			//��Կո�����ж� 
			if(line[i] == ' ' || !isprint(line[i])){
				i++;
				continue;
			}
			//���//ע�ͽ����ж�
			if(line[i] == '/' && i+1 < (int)line.length() && line[i+1] == '/')
				break;
			//���/**/ע�ͽ����ж�
			if(is_maltiline_comment){
				if(line[i] == '*' && i+1 < (int)line.length() && line[i+1] == '/'){
					//cout << endl << "on no @@@ " << i << endl;
					is_maltiline_comment = false;
					i += 2;
					//cout << line[i] << endl;
					continue;
				}
				else{
					i++;
					continue;
				}
			}
			if(line[i] == '/' && i+1 < (int)line.length() && line[i+1] == '*'){
				//cout << endl << "ou yes sir ### " << i << endl;
				is_maltiline_comment = true;
				i += 2;
				continue;
			}
			
			
			int loc = -1;
			int loc_l = -1;
			if(isalpha(line[i])){
				//cout << i << " " << line[i] << " " << endl << line << endl;
				assert(i == 0 || !(isalnum(line[i-1]) || line[i-1] == '_') );
				
				for(int j(0);j < (int)sizeof(keyword)/(int)sizeof(keyword[0]);j++)
					if(line.compare(i, keyword[j].length(), keyword[j]) == 0)
						if((int)keyword[j].length() > loc_l){
							loc = j;
							loc_l = keyword[j].length();
						}
				//�Ҳ���ƥ��,����ƥ�䵫�Ǻ��滹����ĸ���»��߻�������ƥ�� 
				if(loc == -1 || isalnum(line[i+keyword[loc].length()]) 
							 || line[i+keyword[loc].length()] == '_'){
					cout << "USR "<<mycounter++<<endl;
					test("USR");
					while(isalnum(line[i]) || line[i] == '_')
						i++;
				}
				else{
					cout << "SYS "<<mycounter++<<endl;
					test("SYS");
					i += keyword[loc].length();
					//���long long����������ж� 
					if(keyword[loc].compare("long") == 0)
						if(line.compare(i, 5, " long") == 0)
							i += 5;
				}
			}
			//NUM���ж� 
			else if(isdigit(line[i]) || line[i] == '\'' 
						|| (line[i] == '.' && isdigit(line[i+1]))){
				assert(i == 0 || !(isalnum(line[i-1]) || line[i-1] == '_') );
				cout << "NUM "<<mycounter++<<endl;
				test("NUM");
				if(line[i] == '\''){
					do{i++;}while(line[i] != '\'');
					i++;
				}
				else{
					while(isalnum(line[i]) || line[i] == '.')
						i++;
				}
				
			}
			//STR���ж� 
			else if(line[i] == '"'){
				cout << "STR "<<mycounter++<<endl;
				test("STR");
				i++;
				while(line[i] != '"' || line[i-1] == '\\')
					i++;
				i++;
				//cout << endl << "### " << line[i] << i << endl;
			}
			//SYM���ж� 
			else{
				cout << "SYM "<<mycounter++<<endl;
				test("SYM");
				for(int j(0);j < (int)sizeof(punc)/(int)sizeof(punc[0]);j++)
					if(line.compare(i, punc[j].length(), punc[j]) == 0)
						if((int)punc[j].length() > loc_l){
							loc = j;
							loc_l = punc[j].length();
						}
				//cout << i << " " << line[i] << " " << loc << " @@@@" << endl << line << endl;
				assert(loc >= 0);
				/*
				if(!(loc >= 0)){
					cout << endl << i << " " << line[i] << " " << loc << " @@@@" << endl << line << endl;
					return 0;
				}
				*/
				i += punc[loc].length();
			}
			
			
		}
	}
} 
