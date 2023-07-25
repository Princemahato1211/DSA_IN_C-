#include<iostream>
using namespace std;

typedef struct node
{
  int data;
  struct node * next;
  struct node * previous;
}node;

int count_node(node *tail);
node *create_doubly_Cll(); 
void display_list(node *tail);
void insert_at_beg(node *tail);
node *insert_at_end(node *tail);
void insert_at_Ipos(node *tail,int pos);
void delete_at_beg(node *tail);
node *delete_at_end(node *tail);
void delete_at_Ipos(node *tail, int pos);
node *reverse_list(node *tail);

int main(){
  node *tail;
  cout<<"to create a link list: "<<endl;
  tail=create_doubly_Cll();
  cout<<"the linked list are: ";
  display_list(tail);
  
  cout<<"\n\nto insert data at the begining: "<<endl;
  insert_at_beg(tail);
  cout<<"linked list after inserting data at begining: "<<endl;
  display_list(tail);

  cout<<"\n\nto insert data at the ending: "<<endl;
  tail=insert_at_end(tail);
  cout<<"linked after inserting data at  the ending: "<<endl;
  display_list(tail);
  
  cout<<"\n\nenter th position you want insert: ";
  int k;
  cin>>k;
  insert_at_Ipos(tail,k);
  cout<<"the linked after insertng data at the "<<k<<" position"<<endl;
  display_list(tail);

  cout<<"\n\nlinked after deleting node at the beginning:"<<endl;
  delete_at_beg(tail);
  display_list(tail);

  cout<<"\n\nlinked after deleting node at the ending:"<<endl;
  tail=delete_at_end(tail);
  display_list(tail);

  cout<<"\n\nEnter the position you want to delete: ";
  int l;
  cin>>l;
  delete_at_Ipos(tail,l);
  cout<<"the linked list after deleting the "<<l<<" position"<<endl;
  display_list(tail);

  cout<<"\n\nlinklist after reversing: "<<endl;
  tail=reverse_list(tail);
  display_list(tail);
  return 0;
}

int count_node(node *tail){
  node *temp;
  int a=1;
  temp=tail->next;
  while(temp->next!=tail->next){
    a++;
    temp=temp->next;
  }
  return a;
}

node *create_doubly_Cll()
{
  node *tail, *newnode,*head,*temp;
  head=0;
  int choice=1;
  do
  {
    newnode=(node*)malloc(sizeof(node));
    cout<<"Enter the data: ";
    cin>>newnode->data;
    if(head==0){
      head=tail=newnode;
    }
    else{
      newnode->previous=tail;
      tail->next=newnode;
      tail=newnode;
    }
    cout<<"to continue enter (1): ";
    cin>>choice;
  } while(choice==1);
  newnode->next=head;
  head->previous=newnode;
  return newnode;
}

void display_list(node *tail){
  node *temp;
  temp=tail->next;
  while(temp->next!=tail->next){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<temp->data;
}

void insert_at_beg(node * tail){
  node *newnode;
  newnode=(node *)malloc(sizeof(node));
  cout<<"Enter tha data:";
  cin>>newnode->data;
  newnode->next=tail->next;
  newnode->next->previous=newnode;
  newnode->previous=tail;
  tail->next=newnode;
}

node *insert_at_end(node * tail){
  node *head,*newnode;
  newnode=(node*)malloc(sizeof(node));
  cout<<"Enter tha data: ";
  cin>>newnode->data;
  newnode->next=tail->next;
  newnode->previous=tail;
  tail->next=newnode;
  (newnode->next)->previous=newnode;
  return newnode;
}

void insert_at_Ipos(node *tail,int pos){
  int count;
  count=count_node(tail);
  if(pos>count){
    cout<<"the data can't be entered: "<<endl;
  }
  else{
    node*temp,*newnode;
    newnode=(node*)malloc(sizeof(node));
    cout<<"Enter the data:";
    cin>>newnode->data;
    temp=tail->next;
    int i=1;
    while(i<pos-1){
      temp=temp->next;
      i++;
    }
    (temp->next)->previous=newnode;
    newnode->next=temp->next;
    newnode->previous=temp;
    temp->next=newnode;
  }
}

void delete_at_beg(node *tail){
  node *temp;
  temp=tail->next;
  tail->next=temp->next;
  (temp->next)->previous=temp->previous;
  free(temp);
}

node *delete_at_end(node *tail){
  node *temp;
  temp=tail->previous;
  temp->next=tail->next;
  (tail->next)->previous=temp;
  free(tail);
  return temp;
}

void delete_at_Ipos(node *tail, int pos){
  int count;
  count=count_node(tail);
  if(pos>count){
    cout<<"no any node are present at this position"<<endl;
  }
  else{
    node *temp;
    temp=tail->next;
    int i=1;
    while(i<pos){
      temp=temp->next;
      i++;
    }
    (temp->next)->previous=temp->previous;
    (temp->previous)->next=temp->next;
    free(temp);
  }
}

node *reverse_list(node *tail){
  node *temp,*swap,*head;
  temp=head=tail->next;
  while(temp->next!=tail->next){
    swap=temp->next;
    temp->next=temp->previous;
    temp->previous=swap;
    temp=temp->previous;
  }
  swap=temp->next;
  temp->next=temp->previous;
  temp->previous=swap;
  return head;
}