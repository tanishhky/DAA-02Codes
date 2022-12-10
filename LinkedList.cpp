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

struct node* deleteEnd(struct node* head){
    
    struct node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

struct node* deleteFront(struct node* head){
    head=head->next;
    return head;
}

struct node* deleteRandom(struct node* head,int pos){
    struct node* temp=head;
    int p=1;
    while(p<pos-2){
        temp=temp->next;
        p++;
    }
    temp->next=temp->next->next;
    
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
        head=insertEnd(head,d);
        head=insertFront(head,d);
    }
    
    display(head);
    head=insertRandom(head,6,3);
    display(head);
    head=deleteEnd(head);
    display(head);
    head=deleteFront(head);
    display(head);
    head=deleteRandom(head,2);
    display(head);
    
    return 0;
}
