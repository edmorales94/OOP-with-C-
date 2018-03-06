#include <iostream>
#include <cstddef>

using namespace std;

template<typename T>
class Node{
    public:
        T nodeValue;
        Node<T> *next;

        Node(const T &item, Node<T> *ptr = NULL):nodeValue(item),next(ptr){}
};

template<typename T>
class Queue{
    public:
        Node<T> *head, *tail;
        int queueSize;
    //---------- Constructor ---------------------------------------------------------------------------------------------------
        Queue(){
            head = tail = NULL;
            queueSize = 0;
        }
    //---------- prototyped methods --------------------------------------------------------------------------------------------
       // bool empty();
       // int size();
       // T front();
        //T back();
        //void push(T value);
       // T pop();
       // ~Queue();

    //---------- empty method --------------------------------------------------------------------------------------------------
        bool empty(){
            return head == NULL && tail == NULL;//returns true if the head and tail are empty
        }

    //---------- size method ---------------------------------------------------------------------------------------------------
        int size(){
            if(queueSize < 0){//size can't be less than zero
                queueSize = 0;//in that case, set the size to zero
            }
            cout<<"size of queue: "<<queueSize<<endl;
            return queueSize;
        }

    //---------- front method --------------------------------------------------------------------------------------------------
        T front(){
            if(head != NULL){
                cout<<"first element: "<<head->nodeValue<<endl;
                return head -> nodeValue;
            }
            else{
                cout <<"Queue is empty. There's nothing at the front"<<endl;
            }
        }

    //---------- back method ---------------------------------------------------------------------------------------------------
        T back(){
            if(tail != NULL){
                cout<<"Last element: " << tail ->nodeValue<<endl;
                return tail -> nodeValue;
            }
            else{
                cout <<"Queue is empty. There's nothing at the back"<<endl;
            }
        }

    //---------- push method ---------------------------------------------------------------------------------------------------
        void push(T value){
            if(head == NULL){
                head = new Node<T>(value);
                tail = head;
                queueSize++;
                cout<<value<<" was successfully inserted at the front of the queue"<<endl;
            }
            else{
                tail->next = new Node<T>(value);
                tail = tail ->next;
                queueSize++;
                cout<<value<<" was successfully inserted at the end of the queue"<<endl;
            }
        }

    //---------- pop method ----------------------------------------------------------------------------------------------------
        T pop(){
            if(head == NULL){
                cout <<"Queue is empty. Can't pop anything"<<endl;
                return NULL;
            }
            else if(head == tail){
                T temp = head->nodeValue;
                head = NULL;
                tail = NULL;
                --queueSize;
                return temp;
            }
            else{
                T value = head -> nodeValue;
                head = head ->next;
                --queueSize;
                cout<<"popping the first element: "<<value<<endl;
                return value;
            }
        }

    //---------- display method ------------------------------------------------------------------------------------------------
        void display(){
            Node<T> *temp = head;
            cout<<"Current elements in the queue: ";
            while(temp != NULL){
                cout<<temp -> nodeValue <<" ";
                temp = temp ->next;
            }
            cout<<endl;
        }

};
int main()
{
    Queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(6);
    myQueue.push(10);
    myQueue.size();
    myQueue.empty();
    myQueue.display();
    myQueue.front();
    myQueue.back();
    myQueue.pop();
    myQueue.display();
    myQueue.size();
    myQueue.pop();
    myQueue.display();
    myQueue.pop();
    myQueue.display();
    myQueue.pop();
    myQueue.display();
    myQueue.pop();
    myQueue.display();
    myQueue.size();
    myQueue.front();
    myQueue.back();
    return 0;
}
