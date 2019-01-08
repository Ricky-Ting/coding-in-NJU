#include<iostream>
#include<string>
#include<map>
#include<algorithm>
//#include<stdio.h>
using namespace std;

struct Student{
	int p;
	int r;
	bool is_b;
} s[300000];

int P;
map<string, int> mapStudent;
int dp(int now){
	//printf("进入dp：%d %d\n", now, r);
	if(now == s[now].p){
		//printf("#退出dp：%d %d\n", now, r);
		return now;
	}
	else{
		
		int term = s[now].p;
		s[now].p = dp(term);
		s[now].r = (s[now].r+s[term].r)%3;
		//printf("@退出dp：%d %d\n", now, r);
		return s[now].p;
	}
}

int f_or_i(string &name){
	map<string, int>::iterator iter;
	iter = mapStudent.find(name);
	if(iter != mapStudent.end()){
		return iter->second;
	}
	else{
		s[P].p = P;
		s[P].r = 0;
		s[P].is_b = true;
		mapStudent[name] = P;
		P++;
		return P-1;
	}
}
int main(){	
	int T;
	cin >> T;
	while(T--){
		int K, num(0);
		cin >> K;
		P = 1;
		mapStudent.clear();
		int p_1, p_2, p_1d, p_2d;
		int r1, r2;
		while(K--){
			int op;
			string p1, p2;
			cin >> op;
			switch(op){
				case 0:
				case 1:
					cin >> p1 >> p2;
					p_1 = f_or_i(p1);
					p_2 = f_or_i(p2);
					
					if(op == 1 && p_1 == p_2){
						//printf("case 1 自己怼自己 检查num：%d\n", num);
						num++;
						break;
					}
					if(op == 0 && p_1 == p_2)
						break;
					
					p_1d = dp(p_1);
					p_2d = dp(p_2);
					
					if(p_1d != p_2d){
						s[p_2d].p = p_1d;
						s[p_2d].r = (3 + op + s[p_1].r - s[p_2].r)%3;
					}
					else{
						if(op == 0 && s[p_1].r != s[p_2].r){
							//printf("case 0 输出 检查num：%d\n", num);
							num++;
							break;
						}
						if(op == 1 && ((3 - s[p_1].r + s[p_2].r)%3 != op)){
							//printf("case 1 输出 检查num：%d\n", num);
							num++;
							break;
						}
					}
					s[p_1].is_b = false, s[p_2].is_b = false;
					break;
				case 2:
				case 3:
					cin >> p1;
					p_1 = f_or_i(p1);
					if(s[p_1].is_b && op == 2){
						//printf("case 2 输出 检查num：%d\n", num);
						num++;
						break;
					}
					
					if(!s[p_1].is_b && op == 3){
						//printf("case 3 输出 检查num：%d\n", num);
						num++;
						break;
					}
					
					if(op == 3){
						break;
					}
					s[P].p = P;
					s[P].r = 0;
					s[P].is_b = true;
					mapStudent[p1] = P;
					P++;
					break;
			}
		}
		cout << num <<endl;
	}
} 
