#include<iostream>
#include<algorithm>
using namespace std;

#define red false 
#define black true

int counter=0;
struct node
{
    bool c; // true is black and false is red.
    int key;
    node * p;
    node * l;
    node * r;
};
class myRB_Tree
{
public:
    node mynil;
    node * root;
    void Initial()
    {
        mynil.c=true;
        mynil.p=mynil.l=mynil.r=NULL;
        mynil.key=-1;
        root=&mynil;
    }
    void Insert(node * z);
    void Delete(node * z);
    node * Search(node * x, int k);
    node * Minimum(node * z);
    void Preorder_tree_walk(node * x);
    
private:
    void Insert_Fixup(node * z);
    void Transplant(node * u, node * v);
    void Left_Rotate(node * x);
    void Right_Rotate(node * x);
    void Delete_Fixup(node * x);
};


void myRB_Tree::Preorder_tree_walk(node * x)
{
    if(x!=&mynil)
    {
        cout<<(*x).key<<":"<<((*x).c?"black":"red")<<endl;
        myRB_Tree::Preorder_tree_walk((*x).l);
        myRB_Tree::Preorder_tree_walk((*x).r);
    }
}



void myRB_Tree::Insert(node * z)
{
    node * y=&mynil;
    node * x=root;
    while(x!=&mynil)
    {
        y=x;
        if((*z).key<(*x).key)
            x=(*x).l;
        else
            x=(*x).r;
    }
    (*z).p=y;
    if(y==&mynil)
        root=z;
    else if((*z).key<(*y).key)
        (*y).l=z;
    else
        (*y).r=z;
    (*z).l=&mynil;
    (*z).r=&mynil;
    (*z).c=0;
    myRB_Tree::Insert_Fixup(z);
}

void myRB_Tree::Insert_Fixup(node * z)
{
    while((*(*z).p).c==false)
    {
        if((*z).p==(*(*(*z).p).p).l)
        {
            node * y=(*(*(*z).p).p).r;
            if((*y).c==false)
            {
                (*(*z).p).c=true;
                (*y).c=true;
                (*(*(*z).p).p).c=false;
                z=(*(*z).p).p;
            }
            else
            {
                if(z==(*(*z).p).r)
                {
                    z=(*z).p;
                    myRB_Tree::Left_Rotate(z);
                }
                (*(*z).p).c=true;
                (*(*(*z).p).p).c=false;
                myRB_Tree::Right_Rotate((*(*z).p).p);
            }
            
        }
        else
        {
            node * y=(*(*(*z).p).p).l;
            if((*y).c==false)
            {
                (*(*z).p).c=true;
                (*y).c=true;
                (*(*(*z).p).p).c=false;
                z=(*(*z).p).p;
            }
            else
            {
                if(z==(*(*z).p).l)
                {
                    z=(*z).p;
                    myRB_Tree::Right_Rotate(z);
                }
                (*(*z).p).c=true;
                (*(*(*z).p).p).c=false;
                myRB_Tree::Left_Rotate((*(*z).p).p);
            }
        }
    }
    (*root).c=true;
}


void myRB_Tree::Left_Rotate(node * x)
{
    node * y= (*x).r;
    (*x).r=(*y).l;
    if((*y).l!=&mynil)
        (*(*y).l).p=x;
    (*y).p=(*x).p;
    if((*x).p==&mynil)
        root=y;
    else if(x==(*(*x).p).l)
        (*(*x).p).l=y;
    else
        (*(*x).p).r=y;
    (*y).l=x;
    (*x).p=y;
}

void myRB_Tree::Right_Rotate(node * x)
{
    node * y= (*x).l;
    (*x).l=(*y).r;
    if((*y).r!=&mynil)
        (*(*y).r).p=x;
    (*y).p=(*x).p;
    if((*x).p==&mynil)
        root=y;
    else if(x==(*(*x).p).r)
        (*(*x).p).r=y;
    else
        (*(*x).p).l=y;
    (*y).r=x;
    (*x).p=y;
}

void myRB_Tree::Transplant(node * u, node * v)
{
    if((*u).p==&mynil)
        root=v;
    else if(u==(*(*u).p).l)
        (*(*u).p).l=v;
    else
        (*(*u).p).r=v;
    (*v).p=(*u).p;
}

void myRB_Tree::Delete(node * z)
{
    node * y=z;
    node * x;
    bool y_original_color=(*y).c;
    if((*z).l==&mynil)
    {
        x=(*z).r;
        myRB_Tree::Transplant(z,(*z).r);
    }
    else if((*z).r==&mynil)
    {
        x=(*z).l;
        myRB_Tree::Transplant(z,(*z).l);
    }
    else
    {
        y=myRB_Tree::Minimum((*z).r);
        y_original_color=(*y).c;
        x=(*y).r;
        if((*y).p==z)
            (*x).p=y;
        else
        {
            myRB_Tree::Transplant(y,(*y).r);
            (*y).r=(*z).r;
            (*(*y).r).p=y;
        }
        myRB_Tree::Transplant(z,y);
        (*y).l=(*z).l;
        (*(*y).l).p=y;
        (*y).c=(*z).c;
    }
    if(y_original_color==true)
        myRB_Tree::Delete_Fixup(x);
}

void myRB_Tree::Delete_Fixup(node * x)
{
    node * w;
    while(x!=root and (*x).c==true)
    {
        if(x==(*(*x).p).l)
        {
            w=(*(*x).p).r;
            if((*w).c==false)
            {
                (*w).c=true;
                (*(*x).p).c=false;
                myRB_Tree::Right_Rotate((*x).p);
                w=(*(*x).p).r;
            }
            if((*(*w).l).c==true && (*(*w).r).c==true)
            {
                (*w).c=false;
                x=(*x).p;
            }
            else
            {
                if((*(*w).r).c==true)
                {
                    (*(*w).l).c=true;
                    (*w).c=false;
                    myRB_Tree::Left_Rotate(w);
                    w=(*(*x).p).r;
                }
                (*w).c=(*(*x).p).c;
                (*(*x).p).c=true;
                (*(*w).r).c=true;
                myRB_Tree::Right_Rotate((*x).p);
                x=root;
            }
        }
        else
        {
            w=(*(*x).p).l;
            if((*w).c==false)
            {
                (*w).c=true;
                (*(*x).p).c=false;
                myRB_Tree::Right_Rotate((*x).p);
                w=(*(*x).p).l;
            }
            if((*(*w).r).c==true && (*(*w).l).c==true)
            {
                (*w).c=false;
                x=(*x).p;
            }
            else
            {
                if((*(*w).l).c==true)
                {
                    (*(*w).r).c=true;
                    (*w).c=false;
                    myRB_Tree::Left_Rotate(w);
                    w=(*(*x).p).l;
                }
                (*w).c=(*(*x).p).c;
                (*(*x).p).c=true;
                (*(*w).l).c=true;
                myRB_Tree::Right_Rotate((*x).p);
                x=root;
            }
        }
    }
}

node * myRB_Tree::Minimum(node * z)
{
    while((*z).l!=&mynil)
        z=(*z).l;
    return z;
}

node * myRB_Tree::Search(node * x,int k)
{
    if(x==&mynil || k==(*x).key)
        return x;
    if(k<(*x).key)
    {
        counter++;
        return myRB_Tree::Search((*x).l,k);
    }
    else
    {
        counter++;
        return myRB_Tree::Search((*x).r,k);
    }
}
myRB_Tree T;
void myinsert(int key)
{
    node * p=new node;
    (*p).key=key;
    p->l=&T.mynil;
    p->r=&T.mynil;
    T.Insert(p);
}

void mydelete(int key)
{
    node * p = T.Search(T.root,key);
    T.Delete(p);
    delete(p);
}

int main(void)
{
    
    T.Initial();
    int m,n;
    cin>>m>>n;
    int key;
    for(int i=1;i<=m;i++)
    {
        cin>>key;
        myinsert(key);
    }
    T.Preorder_tree_walk(T.root);
    for(int i=1;i<=n;i++)
    {
        cin>>key;
        counter=0;
        T.Search(T.root, key);
        cout<<counter<<endl;
    }
    return 0;
}
