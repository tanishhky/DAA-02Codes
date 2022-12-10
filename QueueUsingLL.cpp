#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* enqueue(struct node* head,int d){
    //initialize a newNode
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=d;
    newNode->next=NULL;
    
    if(head==NULL){
        return newNode;
    }
    else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

struct node* dequeue(struct node* head){
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
        head=enqueue(head,d);
    }
    
    display(head);
    head=dequeue(head);
    display(head);
    
    return 0;
}
