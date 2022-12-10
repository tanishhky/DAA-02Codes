#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* insertEnd(struct node* head,int d){
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

struct node* insertFront(struct node* head,int d){
    //initialize a newNode
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=d;
    newNode->next=head;
    head=newNode;
    return head;
}

struct node* insertRandom(struct node* head,int d,int pos){
    //initialize a newNode
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=d;
    newNode->next=NULL;
    
    struct node* temp=head;
    int p=1;
    while(p<pos-1){
        temp=temp->next;
        p++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
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
        head=insertFront(head,d);
    }
    display(head);

    return 0;
}
