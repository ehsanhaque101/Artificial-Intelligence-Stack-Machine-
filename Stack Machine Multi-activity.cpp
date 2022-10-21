#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
    double* key;
    Node* next;
    Node()
    {
        next=NULL;
    }
    Node(double value)
    {
        key=new double(value);
        next=NULL;
    }
};

class Stack
{
public:
    Node* head;
    Stack()
    {
        head=NULL;
    }
    void push(double key);
    void pop();
    double* top();
    void print();
    bool empty();
    int size();
};

void Stack::push(double key)
{
    Node* node = new Node(key);
    node->next = head;
    head = node;
}

void Stack::pop()
{
    if(head==NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;

    delete temp;
}
double* Stack::top()
{
    return head->key;
}
bool Stack::empty()
{
    if(head==NULL)
        return true;
    else
        return false;
}

void Stack::print()
{
    Node* p=head;
    if(p==NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    while(p!= NULL)
    {
        cout <<*(p->key)<< " ";
        p = p->next;
    }
    cout << endl;
}


int Stack::size()
{
    Node* p=head;
    int c=0;
    while(p!= NULL)
    {
        //cout <<*(p->key)<< " ";
        p = p->next;
        c++;
    }
    return c;
}


bool isOperator(string c)
{
    if(c=="+" || c=="-" || c=="/" || c=="*" || c=="^")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValid(string exp[], int n)
{
    int a=2,b=0,c=0,d=0;
    for(int i=0; i<=n-1; i++)
    {
        if(!isOperator(exp[i]) && (a%2)==0)
        {
            a = a - 1;
        }
        else
        {
            a = a + 1;
        }
    }
    if(a==1)
    {

        return true;
    }
    else
    {
        //printf("\nInvalid Expression. Try Again!!!");
        return false;
    }
}

void stackMachine(string exp[],int n)
{


    Stack* temp = new Stack;
    for(int i=0; i<=n-1; i++)
    {
        if(!isOperator(exp[i]))
        {
            double d=stod(exp[i]);
            temp->push(d);
            cout<<"\nStack after push: ";
            temp->print();

        }
        else
        {
            i++;
            double c = stod(exp[i]);

            temp->push(c);
            cout<<"\nStack after push: ";
            temp->print();


            if(temp->empty())
            {
                cout<<"The Given Expression is not correct"<<endl;
                return;
            }

            double x= *(temp->top());
            temp->pop();
            cout<<"\nStack after pop: ";
            temp->print();

            if(temp->empty())
            {
                cout<<"The Given Expression is not correct"<<endl;
                return;
            }

            double y= *(temp->top());
            temp->pop();
            cout<<"\nStack after pop: ";
            temp->print();

            if(exp[i-1]=="+")
            {
                temp->push(y+x);
                cout<<"\nStack after addition: ";
                temp->print();
            }
            else if(exp[i-1]=="-")
            {
                temp->push(y-x);
                cout<<"\nStack after subtraction: ";
                temp->print();
            }
            else if(exp[i-1]=="*")
            {
                temp->push(y*x);
                cout<<"\nStack after multiplication: ";
                temp->print();
            }
            else if(exp[i-1]=="/")
            {
                temp->push(y/x);
                cout<<"\nStack after division: ";
                temp->print();
            }
            else if(exp[i-1]=="^")
            {
                temp->push(pow(y,x));
                cout<<"\nStack after ^: ";
                temp->print();
            }
        }
    }

    double result=*(temp->top());
    temp->pop();
    cout<<"\nStack after pop: ";
    temp->print();

    if(!temp->empty())
    {
        cout<<"The Given Expression is not correct"<<endl;
        return;
    }
    cout<<"\nResult: "<<result<<endl;

}

void menu()
{
    cout<<"\n1. Push\n";
    cout<<"2. Pop\n";
    cout<<"3. Add\n";
    cout<<"4. Subtract\n";
    cout<<"5. Multiplication\n";
    cout<<"6. Division\n";
    cout<<"7. Enter any expression\n";
    cout<<"8. Exit\n\n";
}


int main()
{
    cout<<"\n******* 'Stack Machine' *******\n";
    Stack* stack1 = new Stack;
    //cout<<"Enter 'stop'  to exit: "<<endl;
    //cout<<"Operations are 'push', 'pop', 'add', 'sub', 'mul', 'div'"<<endl;
    menu();
    int ch;
    double num;
    for(int i=0; ; i++)
    {
        cin>>ch;


        if(ch==1)
        {
            cout<<"\nPush: ";
            cin>>num;
            stack1->push(num);
            cout<<"Stack: ";
            stack1->print();
            menu();
        }
        else if(ch==2)
        {
            cout<<"\nPop Done\n";
            stack1->pop();
            cout<<"Stack: ";
            stack1->print();
            menu();
        }
        else if(ch==3)
        {

            if(stack1->size() > 1)
            {
                cout<<"\nADD\n";
                double top = *(stack1->top());
                stack1->pop();
                double add = top + *(stack1->top());
                stack1->pop();
                stack1->push(add);
                cout<<"Stack: ";
                stack1->print();

            }
            else
            {
                cout<<"\nAt Least Two Elements Required To Perform ADD!!!\n";
            }
            menu();

        }

        else if(ch==4)
        {
            if(stack1->size()>1)
            {
                cout<<"\nSUB\n";
                double top = *(stack1->top());
                stack1->pop();
                double sub = *(stack1->top()) - top;
                stack1->pop();
                stack1->push(sub);
                cout<<"Stack: ";
                stack1->print();
            }
            else
            {
                cout<<"\nAt Least Two Elements Required To Perform SUB!!!\n";
            }

            menu();

        }

        else if(ch==5)
        {
            if(stack1->size()>1)
            {
                cout<<"\nMUL\n";
                double top = *(stack1->top());
                stack1->pop();
                double mul = top **(stack1->top());
                stack1->pop();
                stack1->push(mul);
                cout<<"Stack: ";
                stack1->print();
            }
            else
            {
                cout<<"\nAt Least Two Elements Required To Perform MUL!!!\n";
            }

            menu();

        }

        else if(ch==6)
        {
            if(stack1->size() > 1)
            {
                cout<<"\nDIV\n";
                double top = *(stack1->top());
                stack1->pop();
                double divi = *(stack1->top())/top;
                stack1->pop();
                stack1->push(divi);
                cout<<"Stack: ";
                stack1->print();
            }
            else
            {
                cout<<"\nAt Least Two Elements Required To Perform DIV!!!\n";
            }

            menu();

        }


        else if(ch==7)
        {
            stack<string>s1_stack;
            string st;
            double val;
            cout<<"\nEnter 'stop' to stop taking input\n"<<endl;

            while (true)
            {

                cin>>st;
                if(st=="stop")
                {
                    break;
                }
                s1_stack.push(st);
            }

            int len=s1_stack.size();

            string expression[len];


            for(int i=len-1; i>=0; i--)
            {
                expression[i]= s1_stack.top();
                s1_stack.pop();
            }

            //
            //val = isValid(expression, len);
            if(!isValid(expression, len))
            {
                printf("\nInvalid Expression. Try Again!!!\n");
                menu();
                continue;
            }
            else
            {
                stackMachine(expression,len);
                menu();
            }
            //

        }

        else if(ch==8)
        {
            break;
        }

        else
        {
            cout<<"Invalid Input";
        }
    }



    return 0;
}
