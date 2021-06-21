#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;

    Node(int data){
        this -> data=data;
        next=NULL;
    }
};
class Pair{
    public:
        Node *head;
        Node *tail;
};
Pair reversell_2(Node *head){
    if(head==NULL||head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns=reversell_2(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}
Node* reversell_3(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *smallAns=reversell_3(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallAns;
}
Node* reversell_Better(Node*head){
    return reversell_2(head).head;
}
Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data !=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
    }

Node *insertNode(Node *head, int i, int data){
    Node *newNode =new Node(data);
    int count=0;
    Node *temp=head;

    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while (temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node*a=temp->next;
        temp->next=newNode;
        newNode->next=a;
    }
    return head;
}
Node *deleteNode(Node *head, int i){
    int count=0;
    Node *temp=head;

    if(i==0){
        Node *a=temp->next;
        head=temp->next;
        return head;
    }
    while (temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){

        Node*a=temp->next;
        Node*b=a->next;
        temp->next=b;
        delete a;
    }
    return head;
}
Node* reversell(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *smallAns=reversell(head->next);
    Node *temp = smallAns;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return smallAns;
}
void print(Node *head){
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    
}
int main()
{
    // Node n1(1);
    // Node *head=&n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next=&n3;
    // n3.next=&n4;
    // n4.next=&n5;
    Node *head=takeInput();
    // print(head);
    // int i,data;
    // cin>>i>>data;
    // head=insertNode(head,i,data);
    // print(head);
    // cin>>i;
    // head=deleteNode(head,i);
    // print(head);
    head=reversell_3(head);
    print(head);
}