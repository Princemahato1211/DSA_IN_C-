#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node * next;
} node;

int count_cll(node * tail);
node * create_cll();
void display_list(node * tail);
void insert_at_beg(node * tail);
node *insert_at_end(node * tail);
void insert_at_Ipos(node *tail, int pos);
void delete_at_beg(node *tail);
node *delete_at_end(node * tail);
void delete_at_Ipos(node*tail, int pos);
node *reverse_link_list(node * tail);

int main(){
    node * tail=0;
    cout<<"create a link list "<<endl;
    tail=create_cll();
    cout<<"the link list are: ";
    display_list(tail);

    cout << "\nto insert data at the beginning" << endl;
    insert_at_beg(tail);
    cout << "the doubly linklist after insertion data at the beginning: " << endl;
    display_list(tail);

    cout << "\nto insert data at the ending" << endl;
    tail=insert_at_end(tail);
    cout << "the doubly linklist after insertion data at the ending: " << endl;
    display_list(tail);

    cout<<"\nenter the position you want to entered tha data: ";
    int k;
    cin>>k;
    insert_at_Ipos(tail,k);
    cout<<"linklist after insert data at "<<k<<" position:"<<endl;
    display_list(tail);

    delete_at_beg(tail);
    cout<<"\nlinked list after deleting node at begining: "<<endl;
    display_list(tail);

    tail=delete_at_end(tail);
    cout<<"\nlinked list after deleting node at ending: "<<endl;
    display_list(tail);

    cout<<"\nenter the position you want to delete tha data: ";
    int l;
    cin>>l;
    delete_at_Ipos(tail,l);
    cout<<"linklist after delete data at "<<l<<" position:"<<endl;
    display_list(tail);

    tail=reverse_link_list(tail);
    cout<<"the link list after reverse: "<<endl;
    display_list(tail);
    return 0;
}

int count_cll(node * tail){
    int a=1;
    node * temp;
    temp=tail->next;
    while(temp->next!=tail->next){
        temp=temp->next;
        a++;
    }
    return a;
}

node * create_cll(){
    node*tail, *temp, *newnode;
    tail=0;
    int choice =1;
    do
    {
       newnode=(node*)malloc(sizeof(node));
       cout<<"Enter the data: ";
       cin>>newnode->data;
       if(tail==0){
           tail=newnode;
           tail->next=newnode;
       }
       else{
           newnode->next=tail->next;
           tail->next=newnode;
           tail=newnode;
       }
       cout<<"to continue enter (1): ";
       cin>>choice;
    } while (choice==1);
    return tail;
}

void display_list(node * tail){
    node *temp;
    temp=tail->next;
    while(temp->next!=tail->next){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

void insert_at_beg(node * tail){
    node * temp,*newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    cout<<"enter data: ";
    cin>>newnode->data;
    newnode->next=tail->next;
    tail->next=newnode;
}

node *insert_at_end(node * tail){
    node *newnode;
    newnode=(node *)malloc(sizeof(node*));
    cout<<"Enter tha data: ";
    cin>>newnode->data;
    newnode->next=tail->next;
    tail->next=newnode;
    return newnode;
}

void insert_at_Ipos(node *tail, int pos){
    int count;
    count=count_cll(tail);
    if(pos>count){
        cout<<"the data can't be entered";
    }
    else{
        int i=1;
        node *temp,* newnode;
        temp=tail->next;
        newnode=(node*)malloc(sizeof(node));
        cout<<"Enter the data: ";
        cin>>newnode->data;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void delete_at_Ipos(node*tail,int pos){
    int count;
    count=count_cll(tail);
    if(pos>count){
        cout<<"there are no node at this position"<<endl;
    }
    else{
        node  *temp, *current;
        int i=1;
        temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        current=temp->next;
        temp->next=current->next;
        free(current);
    }
}

void delete_at_beg(node *tail){
    node *temp=tail->next;
    tail->next=temp->next;
    free(temp);
}

node *delete_at_end(node * tail){
    node*temp;
    temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    return temp;
}

node *reverse_link_list(node * tail){
    node *nextnode;
    if(tail==0){
        cout<<"there are no node in link list";
    }
    else{
        node *prev,*current;
        current=tail->next;
        nextnode=current->next;
        while(current!=tail){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=current;
    }
    return nextnode;
}