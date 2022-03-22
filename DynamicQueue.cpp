// Implementation of Queues using Linked List ( Dynamic Implementation )
#include <iostream>
#include <string>
using namespace std;
class Node                     // class to represent data members of every element ( Node ) 
{
    public:
    int data;         // Data value
    Node* next;       // Node pointer
    public:
    Node(int val)                   // Parametrized Constructor
    {data = val; next = NULL;}
};
class Queue            //  Class for Queue Implementation ( First-In First-Out ) 
{
    public:
    Node* front;       // Node pointer for head ( front )
    Node* back;        // Node pointer for tail ( back ) 
    public:
    Queue (){              //  Parametrized Constructor
        front = NULL;
        back = NULL;
    }
    public:
    void Enqueue(int val)    // Adding Node to Queue is always done at back Node.. O(1) time
    {
        Node* n = new Node(val);
        if(front == NULL)            //  If Queue is Empty
        {
            front = n;     // Front and back are same
            back = n;
            return;      // Control moves out of the function
        }
        back -> next = n;     // back Node pointer points to the new Node
        back = n;             // back becomes the new Node
    }public:
    void Dequeue()      // Deleting Node from Queue is always done from front Node.. O(1) time
    {
        if(front == NULL)   // If Queue is empty then nothing can be popped out
        {
            cout << "The Queue is currently Empty !!" << endl;
            return;
        }
        Node* temp = front;       // Temporary Node created and front Node value stored
        front = temp -> next;     // Front Node changed
        delete temp;              // Temporary Node is deleted
    }
    public:
    void Peek()    // Peeking into front and back Nodes in the Queue.. O(1) time
    {
        if(front == NULL)
        {
            cout << "No data in Queue right now !!" << endl;
            return;      // control moves out of the function
        }
        cout << "The data in the Queue at front element is : " << front -> data << endl;
        cout << "The data in the Queue at back element is : " << back  -> data << endl;
    }
    public:
    bool IsQueueEmpty()   // Checking if Queue is Empty is done by seeing front Node.. O(1) time
    {
        if(front == NULL)    // If front Node points to Null then Queue is Empty
        {
            cout << "The Queue is currently empty !!" << endl;
            return true;
        }
        return false;     //  Retruring subsequent boolean result
    }
    public:
    void DisplayQueue()    // Displaying all Nodes of the Queue by Traversing.. O(n) time
    {
        Node* temp = front;   // Temporary Node created and front Node copied to it
        int iter = 1;
        if(temp -> next == NULL)   // If there is only One Node then there is no back Node
        {
            cout << temp -> data << " ---> Top " << endl;
            return;
        }
        for( ; temp != back ; temp = temp -> next, iter++)  // Traversal for loop
        {
            if(iter == 1)   // Condition for proper printing of Nodes
                cout << temp -> data << " ---> Top" << endl;
            if(iter > 1)    // Condition for proper printing of Nodes
            {
                cout << "^" << endl;
                cout << temp -> data << endl;
            }
        }
        cout << "^" << endl;
        cout << back -> data << " ---> Base" << endl;
    }
    public:
    void SizeOfQueue()   // Checking Size of Queue using front Node pointer.. O(1) time
    {
        Node* temp = front;
        int iter = 0;
        for( ; temp -> next != NULL; temp = temp -> next, iter++);     //Traversing Loop
        cout << "The Size of Queue currently is : " << iter+1 << endl;
    }
};
int main()
{
    Queue queue;   // Object creation of class Queue
    int s, x;
    cout << "Enter the number of Operations to perform on Queue Data Structure : ";
    cin >> s;
    string str;  // String variable by <string> preprocessor directives 
    bool ck;
    for(int i = 0; i < s; i++)   // Loop for performing operations
    {
        cout << "Write Eq to Enqueue, Dq to Dequeue, P to peek into the front and back, Size to get Size of Queue, empty to check if Queue is empty : ";
        cin >> str;
        if(str == "Eq" || str == "EQ" || str == "eq")
        {
            cout << "Enter Node data : ";
            cin >> x;
            queue.Enqueue(x);
            queue.DisplayQueue();
        }
        if(str == "Dq" || str == "DQ" || str == "dq")
        {
            queue.Dequeue();
            if(queue.front != NULL)     // If the Queue is not Empty
                queue.DisplayQueue();
            if(queue.front == NULL)      // Queue Underflow condition when Queue is Empty
                cout << "QUEUE UNDERFLOW" << endl;
        }
        if(str == "P" || str == "p")
            queue.Peek();
        if(str == "Empty" || str == "EMPTY" || str == "empty")
        {
            ck = queue.IsQueueEmpty();
            if(ck == false)
                cout << "The Queue is not Empty !!" << endl;
        }
        if(str == "Size" || str == "SIZE" || str == "size")
            queue.SizeOfQueue();
        cout << "The total Operations performed till now are : " << i+1 << endl;
    }
    return 0;  // End of the Program
}