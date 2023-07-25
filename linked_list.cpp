/*this code are used 
1)to make a linked list.
2)add data in begining 
3) add data in ending
4)add data in ith postion  
5) delete a data at ith position
6)deleting data at the begining
7) deleting data at the ending 
8) reversing the array */

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node * reverseLink(struct node * head);
void DeclareLinkList(struct node *head);

int main(){
    // 1) FIRST CODE
    struct node *head;
    struct node *temp;
    struct node  *newcode;
    head=0;
    int count=0;
    int choice=1;
    while(choice==1){
        newcode=(struct node*) malloc(sizeof(struct node));
        count++;
        cout<<"enter data: ";
        cin>>newcode->data;
        newcode->next=0;
        if(head==0){
            head=temp=newcode;
        }else{
            temp->next=newcode;
            temp=newcode;
        }
        cout<<"do you want to continue(1 or 0): ";
        cin>>choice;
    }

    // to print a linked list
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }


    //2) SECOND CODE
    cout<<"\n\ninsert data at the begining: "<<endl;
    newcode=(struct node*) malloc(sizeof(struct node));
    cout<<"enter data: ";
    cin>>newcode->data;
    newcode->next=head;
    head=newcode;
    count++;

    cout<<"\nlinked after inserting data at the begining: "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    
    //3) THIRD CODE
    temp=head;
    cout<<"\n\nentering data at the end of linked list "<<endl;
    newcode=(struct node*) malloc(sizeof(struct node));
    cout<<"enter the data :";
    cin>>newcode->data;
    newcode->next=0;
    count++;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newcode;

    cout<<"\nlinked after inserting data at the ending: "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    

    //4) FOURTH CODE
    cout<<"\n\nenter the position you want to insert the data in linked list :"<<endl;
    int pos;
    cin>>pos;
    if(pos>count){
        cout<<"data can't be entered";
    }
    else{
        temp=head;
        int i=1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newcode= (struct node*) malloc(sizeof(struct node)); 
        count++;
        cout<<"enter the data: ";
        cin>>newcode->data;
        newcode->next=temp->next;
        temp->next=newcode;
    }
    cout<<"\nlinked after inserting data at the I position : "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }


    // 5) FIFTH CODE
    int posi;
    int i=1;
    cout<<"\n\nenter the position you want to delete the data in linked list :";
    cin>>posi;
    if(posi>count){
        cout<<"the position you select is greater than number of element in linked list";
    }else{
        struct node * coding;
        temp=head;
        while(i<posi-1){
            temp=temp->next;
            i++;
        }
        coding=temp->next;
        temp->next=coding->next;
        free(coding);
        cout<<coding->data;
        count--;
    }
    cout<<"\nlinked after deleting data at the I position : "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }


    //6) SIXTH CODE
    temp=head;
    head=temp->next;
    free(temp);
    cout<<temp->data;
    count--;
    cout<<"\n\nlinked after deleting data at the begining: "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    //7) SEVENTH CODE
    temp=head;
    struct node * previous;
    while(temp->next!=0){
        previous=temp;
        temp=temp->next;
    }
    previous->next=0;
    free(temp);
    cout<<temp->data;
    cout<<"\n\nlinked after deleting data at the ending: "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    //8) EIGHT CODE
    head=reverseLink(head);
    cout<<"\n\nlinked after reversing: "<<endl;
    temp=head;
    cout<<"the linked list are : ";
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}

//8) EIGHT CODE
struct node* reverseLink(struct node *head){
    struct node *previous , *temp, *newone;
    previous=0;
    temp=newone=head;
    while(newone!=0){
        newone=newone->next;
        temp->next=previous;
        previous=temp;
        temp=newone;
    }
    return previous;
}


// for adding two polynomial using link list
/*
node *add_polynomial(node *head1, node*head2){   
    node *head, *temp, *temp1, *temp2, *newnode;
    head=0;
    temp1=head1;
    temp2=head2;
    while(temp1!=0 && temp2!=0){
        if(head==0){
            newnode=(node*)malloc(sizeof(node));
            newnode->next=0;
            head=temp=newnode;
        }
        else{
            newnode=(node*)malloc(sizeof(node));
            newnode->next=0;
            temp->next=newnode;
            temp=newnode;
        }
        if(temp1->pow<temp2->pow){
            temp->pow=temp1->pow;
            temp->coef=temp1->coef;
            temp1=temp1->next;
        }
        else if(temp2->pow<temp1->pow){
            temp->pow=temp2->pow;
            temp->coef=temp2->coef;
            temp2=temp2->next;
        }
        else{
            temp->pow=temp1->pow;
            temp->coef=temp1->coef+temp2->coef;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    // inserting the remaining data of the polynomial 
    while(temp1!=0){
        if(head==0){
            newnode=(node*)malloc(sizeof(node));
            newnode->next=0;
            head=temp=newnode;
        }
        else{
            newnode=(node*)malloc(sizeof(node));
            newnode->next=0;
            temp->next=newnode;
            temp=newnode;
        }
        temp->pow=temp1->pow;
        temp->coef=temp1->coef;
        temp1=temp1->next;
    }
    while(temp2!=0){
        if(head==0){
            newnode=(node*)malloc(sizeof(node));
            newnode->next=0;
            head=temp=newnode;
        }
        else{
            newnode=(node*)malloc(sizeof(node));
            newnode->next=0;
            temp->next=newnode;
            temp=newnode;
        }
        temp->pow=temp2->pow;
        temp->coef=temp2->coef;
        temp2=temp2->next;
    }
    return head;
}
*/