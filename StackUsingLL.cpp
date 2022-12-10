#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* head,int d){
    //initialize a newNode
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=d;
    newNode->next=head;
    head=newNode;
    return head;
}

struct node* pop(struct node* head){
    head=head->next;
    return head;
}

void display(struct node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    int n;
    cin>>n;
    struct node* head=NULL;
    int d;
    
    for(int i=0;i<n;i++){
        cin>>d;
        head=push(head,d);
    }
    display(head);
    head=pop(head)
    
    return 0;
}
