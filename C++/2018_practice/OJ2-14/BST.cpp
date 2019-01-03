//
//  main.cpp
//  debugger
//
//  Created by 丁保荣 on 2018/6/6.
//  Copyright © 2018 丁保荣. All rights reserved.
//

#include<iostream>
using namespace std;

struct node
{
    node * p;
    node * l;
    node * r;
    int key;
};

class BST
{
public:
    node * root;
    node mynil;
    void Initial()
    {
        root=&mynil;
    }
    void Inorder_tree_walk(node * x);
    void Preorder_tree_walk(node * x);
    void Postorder_tree_walk(node * x);
    node * Search(node * x, int k);
    node * Minimum(node * z);
    node * Maximum(node * z);
    node * Successor(node * x);
    node * Predecessor(node * x);
    void Insert(node * z);
    void Transplant(node * u, node * v);
    void Delete(node * z);
    
private:
    
};

void BST::Inorder_tree_walk(node * x)
{
    if(x!=&mynil)
    {
        BST::Inorder_tree_walk((*x).l);
        cout<<(*x).key;
        BST::Inorder_tree_walk((*x).r);
    }
}

void BST::Preorder_tree_walk(node * x)
{
    if(x!=&mynil)
    {
        cout<<(*x).key;
        BST::Preorder_tree_walk((*x).l);
        BST::Preorder_tree_walk((*x).r);
    }
}

void BST::Postorder_tree_walk(node * x)
{
    if(x!=&mynil)
    {
        BST::Postorder_tree_walk((*x).l);
        BST::Postorder_tree_walk((*x).r);
        cout<<(*x).key;
    }
}

node * BST::Search(node * x,int k)
{
    if(x==&mynil || k==(*x).key)
        return x;
    if(k<(*x).key)
        return BST::Search((*x).l,k);
    else
        return BST::Search((*x).r,k);
}

node * BST::Minimum(node * z)
{
    while((*z).l!=&mynil)
        z=(*z).l;
    return z;
}

node * BST::Maximum(node * z)
{
    while((*z).r!=&mynil)
        z=(*z).r;
    return z;
}

node * BST::Successor(node * x)
{
    if((*x).r!=&mynil)
        return BST::Minimum((*x).r);
    node * y=(*x).p;
    while(y!=&mynil && x==(*y).r)
    {
        x=y;
        y=(*y).p;
    }
    return y;
}

node * BST::Predecessor(node * x)
{
    if((*x).l!=&mynil)
        return BST::Maximum((*x).l);
    node * y=(*x).p;
    while(y!=&mynil && x==(*y).l)
    {
        x=y;
        y=(*y).p;
    }
    return y;
}

void BST::Insert(node * z)
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
}

void BST::Transplant(node * u, node * v)
{
    if((*u).p==&mynil)
        root=v;
    else if(u==(*(*u).p).l)
        (*(*u).p).l=v;
    else
        (*(*u).p).r=v;
    if(v!=&mynil)
        (*v).p=(*u).p;
}
void BST::Delete(node * z)
{
    node * y;
    if((*z).l==&mynil)
        BST::Transplant(z,(*z).r);
    else if((*z).r==&mynil)
        BST::Transplant(z,(*z).l);
    else
    {
        y=BST::Minimum((*z).r);
        if((*y).p!=z)
        {
            BST::Transplant(y,(*y).r);
            (*y).r=(*z).r;
            (*(*y).r).p=y;
        }
        BST::Transplant(z,y);
        (*y).l=(*z).l;
        (*(*y).l).p=y;
        
    }
}

BST T;

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
    
   
}
