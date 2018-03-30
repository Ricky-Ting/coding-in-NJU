#include<iostream>
#include<vector>

using namespace std;


struct nodetype
{
	int roadnum;
	int linkednum;
	bool musted;
	bool deleted;
	bool protecteds;
	vector<int> v;
	vector<int> linked;
};

int musted_num=0;
int deleted_num=0;
int protected_num=0;
int n;

void process(nodetype node[]);
void delete_node(nodetype node[], int i);
void protect_node(nodetype node[], int i);

int main(void)
{
	ios::sync_with_stdio(false);

	while(cin>>n)
	{
		musted_num=0;
		deleted_num=0;
		protected_num=0;
		nodetype node[1501];
		
		for(int i=0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			getchar();
			getchar();
			cin>>node[tmp].roadnum;


			node[tmp].musted=false;
			node[tmp].deleted=false;
			node[tmp].protecteds=false;


			getchar();
			for(int j=1;j<=node[tmp].roadnum;j++)
			{
				int tmp1;
				cin>>tmp1;
				node[tmp].v.push_back(tmp1);
				node[tmp1].linked.push_back(tmp);
			}
		}
		
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		process(node);
		cout<<musted_num<<endl;

	}
	return 0;
}

void process(nodetype node[])
{
	if(protected_num==n)
		return;
	else
	{
		for(int i=0;i<n;i++)
		{
			if(!node[i].deleted && node[i].roadnum==0)
			{
				if(node[i].protecteds)
				{
					delete_node(node,i);
				}
				else
				{
					if(protected_num==n-1)
					{
						musted_num++;
						return;
					} 
					if(node[i].linked.size()>0)
					{
						node[node[i].linked[0]].musted=true; musted_num++;
						if(!node[node[i].linked[0]].protecteds)
						{
							node[node[i].linked[0]].protecteds=true;
							protected_num++;
						}

						protect_node(node,node[i].linked[0]);
					}
				}
			}
		}
		process(node);		
	
	}


}



void delete_node(nodetype node[], int i)
{
	node[i].deleted=true;
	/*for(int j=0;j<node[node[i].linked[0]].v.size();j++)
		if(node[node[i].linked[0]].v[j]==i)
		{
			tmp=j;
			//node[node[i].linked[0]].v.erase(node[node[i].linked[0]].v.begin()+j);
			//node[node[i].linked[0]].roadnum--;

		}
	node[node[i].linked[0]].v.erase(node[node[i].linked[0]].v.begin()+tmp,1);
	node[node[i].linked[0]].roadnum--;
	*/
		
	
	for(vector<int>::iterator Iter=node[node[i].linked[0]].v.begin();Iter!=node[node[i].linked[0]].v.end();)
	{
		if((*Iter)==i)
		{
			Iter=node[node[i].linked[0]].v.erase(Iter);
			node[node[i].linked[0]].roadnum--;
			break;
		}
		else
			Iter++;
	}

	
	deleted_num++;
		
}

void protect_node(nodetype node[], int i)
{
	for(int j=0;j<node[i].v.size();j++)
		if(!node[node[i].v[j]].protecteds)
		{
			node[node[i].v[j]].protecteds=true;
			protected_num++;
		}

	for(int j=0;j<node[i].linked.size();j++)
		if(!node[node[i].linked[j]].protecteds)
		{
			node[node[i].linked[j]].protecteds=true;
			protected_num++;
		}
	return;
}

