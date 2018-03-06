#include <iostream>

using namespace std;

template<typename T>
class Node{
    public:
        T nodeValue;
        Node<T> *next;

        Node(const T &item, Node<T> *ptr = Null):nodeValue(item),next(ptr){}
};

template<typename T>
class Queue{
    public:
        Node<T> *head, *tail;
        int queueSize;
    //---------- Constructor ---------------------------------------------------------------------------------------------------
        Queue(){
            head = tail = Null;
            queueSize = 0;
        }
    //---------- prototyped methods --------------------------------------------------------------------------------------------
        bool empty();
        int size();
        T front();
        T back();
        void push();
        T pop();
        ~Queue();

    //---------- empty method --------------------------------------------------------------------------------------------------
        void bool empty(){
            return head == Null && tail == Null;//returns true if the head and tail are empty
        }

    //---------- size method ---------------------------------------------------------------------------------------------------
        int size(){
            if(queueSize < 0){//size can't be less than zero
                queueSize = 0;//in that case, set the size to zero
            }
            return queueSize;
        }

    //---------- front method --------------------------------------------------------------------------------------------------
        T front(){
            if(head != Null){
                return head -> nodeValue;
            }
            else{
                cout <<"Queue is empty. There's nothing at the front"<<endl;
            }
        }
    //---------- back method ---------------------------------------------------------------------------------------------------
        T back(){
            if(tail != Null){
                return tail -> nodeValue;
            }
            else{
                cout <<"Queue is empty. There's nothing at the back"<<endl;
            }
        }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
