#include<iostream>

#define black true
#define red false
struct node
{
	bool c;
	node * p;
	node * l;
	node * r;
	int key;
};

class MyRB_Tree
{
	public:
		node * root;
		node mynil;
		void Initial(void)
		{
			mynil.c=black;
			mynil.p=mynil.l=mynil.r=NULL;
			root=&mynil;
			mynil.key=-1;
		}
		void Insert(node * z);
	private:
		void Left_Rotate(node * x);
		void Right_Rotate(node * x);
		void Insert_Fixup(node * z);
};

void MyRB_Tree::Left_Rotate(node * x)
{
	node * y = x->r;
	x->r = y->l;
	if(y->l!=&mynil)
		y->l->p=x;
	y->p=x->p;
	if(x->p==&mynil)
		root=y;
	else if(x->p->l==x)
		x->p->l=y;
	else
		x->p->r=y;
	x->p=y;
	y->l=x;
}

void MyRB_Tree::Right_Rotate(node * x)
{
	node * y = x->l;
	x->l = y->r;
	if(y->r!=&mynil)
		y->r->p=x;
	y->p=x->p;
	if(x->p==&mynil)
		root=y;
	else if(x->p->l==x)
		x->p->l=y;
	else
		x->p->r=y;
	x->p=y;
	y->r=x;
}

void MyRB_Tree::Insert(node * z)
{
	node * y=&mynil;
	node * x=root;
	while(x!=&mynil)
	{
		y=x;
		if(z->key<x->key)
			x=x->l;
		else
			x=x->r;
	}
	z->p=y;
	if(y==&mynil)
		root=z;
	else if(z->key<y->key)
		y->l=z;
	else
		y->r=z;
	z->c=red;
	z->l=z->r=&mynil;
	MyRB_Tree::Insert_Fixup(z);
}

void MyRB_Tree::Insert_Fixup(node * z)
{
	while(z->p->c==red)
	{
		if(z->p==z->p->p->l)
		{
			node * x=z->p->p->r;
			if(x->c==red)
			{
				z->p->c=x->c=black;
				z->p->p->c=red;
				z=z->p->p;
			}
			else 
			{
				if(z==z->p->r)
				{
					z=z->p;
					MyRB_Tree::Left_Rotate(z);
				}
				z->p->c=black;
				z->p->p->c=red;
				MyRB_Tree::Right_Rotate(z->p->p);
			}
		}
		else
		{
			node * x=z->p->p->l;
			if(x->c==red)
			{
				z->p->c=x->c=black;
				z->p->p->c=red;
				z=z->p->p;
			}
			else 
			{
				if(z==z->p->l)
				{
					z=z->p;
					MyRB_Tree::Right_Rotate(z);
				}
				z->p->c=black;
				z->p->p->c=red;
				MyRB_Tree::Left_Rotate(z->p->p);
			}
		}
	}
	root->c=black;
}

int main(void)
{
	return 0;
}
