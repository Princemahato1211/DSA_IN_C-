#include<iostream>
#include<string>
using namespace std;

typedef struct stack
{
    char data;
    struct stack *prev;
} stack;
stack *top = 0;

typedef struct node
{
    string data1;
    node *prev1;
} node;
node *top1 = 0;

void push_char(char x);
void push_str(string str);
void pop(int x);
char peak();
string peak1();
bool isEmpty(int x);
void display(int x);
int precedance(char x);
string reverse(string data);

string infix_to_postfix(string infix);
string Infix_To_Prefix(string infix);
string postfix_to_infix(string postfix);
string prefix_to_infix(string prefix);
string postfix_to_prefix(string postfix);
string prefix_to_postfix(string prefix);

int main()
{
    string infix_exp, postfix_exp, prefix_exp;
    cout << "Enter the infix expression: ";
    cin >> infix_exp;

    //   infix to postfix and prefix
    postfix_exp = infix_to_postfix(infix_exp);
    cout << "\nPOSTFIX EXPRESSION: " << postfix_exp;
    prefix_exp = Infix_To_Prefix(infix_exp);
    cout << "\nPREFIX EXPRESSION: " << prefix_exp << endl;

    // postfix to infix
    string infix_post;
    infix_post = postfix_to_infix(postfix_exp);
    cout << "\nINFIX EXPRESSION: " << infix_post;

    // prefix to infix
    string infix_pre;
    infix_pre = prefix_to_infix(prefix_exp);
    cout << "\nINFIX EXPRESSION: " << infix_pre << endl;

    // postfix to prefix
    string post_to_pre;
    post_to_pre = postfix_to_prefix(postfix_exp);
    cout << "\nPREFIX EXPRESSION: " << post_to_pre;

    // prefix to postfix
    string pre_to_post;
    pre_to_post = prefix_to_postfix(prefix_exp);
    cout << "\nPOSTFIX EXPRESSION: " << pre_to_post;

    return 0;
}

void push_char(char x)
{
    stack *newnode;
    newnode = (stack *)malloc(sizeof(stack));
    newnode->data = x;
    newnode->prev = top;
    top = newnode;
}

void push_str(string str)
{
    node *newnode1;
    newnode1 = (node *)malloc(sizeof(node));
    newnode1->data1 = str;
    newnode1->prev1 = top1;
    top1 = newnode1;
}

void pop(int x)
{
    if (x == 0)
    {
        if (top == 0)
        {
            cout << "the stack is empty";
        }
        else
        {
            stack *temp = top;
            top = top->prev;
            free(temp);
        }
    }
    else if (x = 1)
    {
        if (top1 == 0)
        {
            cout << "the stack is empty";
        }
        else
        {
            node *temp = top1;
            top1 = top1->prev1;
            free(temp);
        }
    }
}

char peak()
{
    return top->data;
}
string peak1()
{
    return top1->data1;
}

bool isEmpty(int x)
{
    if (x == 0)
    {
        if (top == 0)
        {
            return true;
        }
    }
    else if (x == 1)
    {
        if (top1 == 0)
        {
            return true;
        }
    }
    return false;
}

void display(int x)
{
    if (x == 0)
    {
        stack *temp;
        temp = top;
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }
    else if (x == 1)
    {
        node *temp;
        temp = top1;
        while (temp != 0)
        {
            cout << temp->data1 << " ";
            temp = temp->prev1;
        }
    }
}

int precedance(char x)
{
    if (x == '^')
    {
        return 3;
    }
    else if (x == '*' or x == '/')
    {
        return 2;
    }
    else if (x == '+' or x == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string reverse(string data)
{
    string answer;
    for (int i = 0; i < data.length(); i++)
    {
        push_char(data[i]);
    }
    for (int i = 0; i < data.length(); i++)
    {
        answer += peak();
        pop(0);
    }
    return answer;
}

string infix_to_postfix(string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        char temp = infix[i];
        if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            postfix += temp;
        }
        else if (temp == '(')
        {
            push_char(temp);
        }
        else if (temp == ')')
        {
            while (!isEmpty(0) && peak() != '(')
            {
                char x = peak();
                postfix += x;
                pop(0);
            }
            if (peak() == '(')
            {
                pop(0);
            }
        }
        else if (isOperator(temp))
        {
            if (isEmpty(0))
            {
                push_char(temp);
            }
            else
            {
                if (precedance(temp) > precedance(peak()))
                {
                    push_char(temp);
                }
                else if ((precedance(temp) == precedance(peak())) && (temp == '^'))
                {
                    push_char(temp);
                }
                else
                {
                    while ((!isEmpty(0)) && (precedance(temp) <= precedance(peak())))
                    {
                        postfix += peak();
                        pop(0);
                    }
                    push_char(temp);
                }
            }
        }
    }
    while (!isEmpty(0))
    {
        postfix += peak();
        pop(0);
    }
    return postfix;
}

string Infix_To_Prefix(string infix)
{
    string prefix;
    infix = reverse(infix);
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' and infix[i] <= 'Z'))
        {
            prefix += infix[i];
        }
        else if (infix[i] == ')')
        {
            push_char(infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (isEmpty(0) != true && peak() != ')')
            {
                char temp = peak();
                prefix += temp;
                pop(0);
            }
            if (peak() == ')')
            {
                pop(0);
            }
        }
        else
        {
            if (isEmpty(0) == true)
            {
                push_char(infix[i]);
            }
            else
            {
                if (precedance(infix[i]) > precedance(peak()))
                {
                    push_char(infix[i]);
                }
                else if (precedance(infix[i]) == precedance(peak()) && infix[i] != '^')
                {
                    push_char(infix[i]);
                }
                else
                {
                    while (isEmpty(0) != true && (precedance(infix[i])) < precedance(peak()))
                    {
                        prefix += peak();
                        pop(0);
                    }
                    push_char(infix[i]);
                }
            }
        }
    }
    while (isEmpty(0) != true)
    {
        prefix += peak();
        pop(0);
    }
    prefix = reverse(prefix);
    return prefix;
}

string postfix_to_infix(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        if ((postfix[i] >= 'a' and postfix[i] <= 'z') || (postfix[i] >= 'A' & postfix[i] <= 'Z'))
        {
            string op(1, postfix[i]);
            push_str(op);
        }
        else if (isOperator(postfix[i]))
        {
            string s1, s2;
            s1 = peak1();
            pop(1);
            s2 = peak1();
            pop(1);
            push_str("(" + s2 + postfix[i] + s1 + ")");
        }
    }
    string ans = peak1();
    pop(1);
    return ans;
}

string prefix_to_infix(string prefix)
{
    string infix, prefix_1;
    prefix_1 = reverse(prefix);
    infix = postfix_to_infix(prefix_1);
    infix = reverse(infix);
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    return infix;
}

string postfix_to_prefix(string postfix)
{
    string prefix;
    for (int i = 0; i < postfix.length(); i++)
    {
        if ((postfix[i] >= 'a' & postfix[i] <= 'z') || (postfix[i] >= 'A' & postfix[i] <= 'Z'))
        {
            string op(1, postfix[i]);
            push_str(op);
        }
        else if (isOperator(postfix[i]))
        {
            string s1, s2;
            s1 = peak1();
            pop(1);
            s2 = peak1();
            pop(1);
            push_str(postfix[i] + s2 + s1);
        }
    }
    string ans = peak1();
    pop(1);
    return ans;
}

string prefix_to_postfix(string prefix)
{
    for (int i=prefix.length() - 1; i >= 0; i--)
    {
        if ((prefix[i] >= 'a' & prefix[i] <= 'z') || (prefix[i] >= 'A' & prefix[i] <= 'Z'))
        {
            string op(1, prefix[i]);
            push_str(op);
        }
        else if (isOperator(prefix[i]))
        {
            string s1, s2;
            s1 = peak1();
            pop(1);
            s2 = peak1();
            pop(1);
            push_str(s1+s2+ prefix[i]);
        }
    }
    string ans = peak1();
    pop(1);
    return ans;
}

// example = ((a+b-c)*d^e^f)/g
//output for postfix = ab+c-def^^*g/
//output for prefix = /*-+abc^^defg

//example= k+l-m*n+(o^P)*w/u/v*t+q
// output for postfix = kl+mn*-op^w*u/v/t*+q+
// output for prefix = ++-+kl*mn*//*^opwuvtq
