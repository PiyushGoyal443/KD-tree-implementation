#include <iostream>
#include <stdlib.h>

#define DIM 2

using namespace std;

class Node{
public:
    int x[DIM];
    Node *left;
    Node *right;
    Node(){
        left=NULL;
        right=NULL;
    }
    Node(int a,int y){
        x[0]=a;
        x[1]=y;
    }
    Node(Node *p){
        for(int i=0;i<DIM;i++){
            x[i]=p->x[i];
        }
    }
    void display(){
        for(int i=0;i<DIM;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl<<endl;
    }
};

class Kd_tree{
    Node *head;
    void pinsert(Node *p,Node *t,int cd){
        if(p->x[cd]<t->x[cd]){
            if(t->left!=NULL){
                pinsert(p,t,((cd+1)%DIM));
            }
            else{
                t->left=new Node(p);
                t->left->left=NULL;
                t->left->right=NULL;
            }
        }
        if(p->x[cd]>t->x[cd]){
            if(t->right!=NULL){
                pinsert(p,t,((cd+1)%DIM));
            }
            else{
                t->right=new Node(p);
                t->right->left=NULL;
                t->right->right=NULL;
            }
        }
    }
    void display(Node *t){
        if(t!=NULL){
            display(t->left);
            t->display();
            display(t->right);
        }
    }
public:
    Kd_tree(){
        head=NULL;
    }
    void pinsert(Node *p){
        if(head==NULL){
            head=new Node(p);
            head->left=NULL;
            head->right=NULL;
        }
        else{
            pinsert(p,head,0);
        }
    }
    void display(){
        display(head);
    }
};

int main(){
    Kd_tree t;
    Node *p=new Node(1,2);
    t.pinsert(p);
    Node *s=new Node(0,3);
    t.pinsert(s);
    Node *tt=new Node(5,6);
    t.pinsert(tt);
    t.display();
}
