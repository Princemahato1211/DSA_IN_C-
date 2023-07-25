#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node;

int count1(node *);
node *create_Link_List();
void display_Link_List(node *head);
node *insert_At_Beg(node *head);
node *insert_At_end(node *head);
void insert_At_I_pos(node *head, int pos);
void delete_At_I_pos(node *head, int pos1);
node *delete_At_Beg(node *head);
node *delete_At_end(node *tail);
node *reverse_List(node *head, node *tail);

int main()
{
    node *head, *tail;
    head = create_Link_List();
    display_Link_List(head);

    cout << "\nto insert data at the beginning" << endl;
    head = insert_At_Beg(head);
    cout << "the doubly linklist after insertion data at the beginning: " << endl;
    display_Link_List(head);

    cout << "\nto insert data at the ending" << endl;
    tail = insert_At_end(head);
    cout << "the doubly linklist after insertion data at the ending: " << endl;
    display_Link_List(head);

    int pos;
    cout << "\nto insert data at Ith position: ";
    cin >> pos;
    insert_At_I_pos(head, pos);
    display_Link_List(head);

    int posi;
    cout << "\nto delete data at Ith position: ";
    cin >> posi;
    delete_At_I_pos(head, posi);
    display_Link_List(head);

    cout << "\nafter deleting the data at beginning: " << endl;
    head = delete_At_Beg(head);
    display_Link_List(head);

    cout << "\nafter deleting the data at ending: " << endl;
    tail = delete_At_end(tail);
    display_Link_List(head);

    cout << "\nafter revrsing thelink list: " << endl;
    head= reverse_List(head,tail);
    display_Link_List(head);
}

int count1(node *head)
{
    node *temp;
    int a = 0;
    temp = head;
    while (temp != 0)
    {
        a++;
        temp = temp->next;
    }
    return a;
}

void display_Link_List(node *head)
{
    node *temp;
    temp = head;
    cout << "the linklist are: ";
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

node *create_Link_List()
{
    node *head, *temp, *newnode;
    head = 0;
    int choice = 1;
    while (choice == 1)
    {
        newnode = (node *)malloc(sizeof(node));
        cout << "enter the data: ";
        cin >> newnode->data;
        newnode->next = 0;
        newnode->previous = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->previous = temp;
            temp = newnode;
        }
        cout << "if you want to continue plzz enter (1) :";
        cin >> choice;
    }
    return head;
}

node *insert_At_Beg(node *head)
{
    node *temp, *newnode;
    newnode = (node *)malloc(sizeof(node));
    cout << "enter the data :";
    cin >> newnode->data;
    newnode->previous = 0;
    newnode->next = head;
    head = newnode;
    return head;
}

node *insert_At_end(node *head)
{
    node *temp = head;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    cout << "enter tha data: ";
    cin >> newnode->data;
    newnode->next = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->previous = temp;
    return newnode;
}

void insert_At_I_pos(node *head, int pos)
{
    int count;
    count = count1(head);
    if (pos > count)
    {
        cout << "the data van't be entered: ";
    }
    else
    {
        node *newnode, *temp, *next;
        temp = head;
        int i = 1;
        newnode = (node *)malloc(sizeof(node));
        cout << "enter the data: ";
        cin >> newnode->data;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        (temp->next)->previous = newnode;
        newnode->next = temp->next;
        newnode->previous = temp;
        temp->next = newnode;
    }
}

void delete_At_I_pos(node *head, int posi)
{
    int count;
    count = count1(head);
    if (posi > count)
    {
        cout << "there are no element at this position" << endl;
    }
    else
    {
        node *newnode, *temp, *nextone;
        temp = head;
        int i = 1;
        while (i < posi)
        {
            temp = temp->next;
            i++;
        }
        (temp->previous)->next = temp->next;
        (temp->next)->previous = temp->previous;
        free(temp);
    }
}

node *delete_At_Beg(node *head)
{
    node *temp;
    temp = head;
    head = temp->next;
    head->previous = 0;
    free(temp);
    return head;
}

node *delete_At_end(node *tail)
{
    node *temp;
    temp = tail->previous;
    temp->next = 0;
    free(tail);
    return temp;
}

node *reverse_List(node *head, node *tail)
{
    node *temp, *swapi;
    temp = head;
    while (temp != 0)
    {
        swapi = temp->next;
        temp->next = temp->previous;
        temp->previous = swapi;
        temp = temp->previous;
    }
    return tail;
}