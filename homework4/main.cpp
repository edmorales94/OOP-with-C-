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

    //---------- Destructor ----------------------------------------------------------------------------------------------------
    ~Queue(){
        while(head != NULL){
            Node<T> *temp = head;//Save the current head
            head = head->next;//move the current head to the next element, which becomes the new head
            delete temp;//delete the former head
        }
        tail = NULL;
        cout<<"The queue was destroyed"<<endl;
    }
    //---------- empty method --------------------------------------------------------------------------------------------------
        bool empty(){
            return head == NULL && tail == NULL;//returns 1(true) if the head and tail are empty
        }

    //---------- size method ---------------------------------------------------------------------------------------------------
        int size(){
            if(queueSize < 0){//size can't be less than zero
                queueSize = 0;//in that case, set the size to zero
            }
            cout<<"size of queue: "<<queueSize<<endl;
            return queueSize;//return the number of elements in the queue
        }

    //---------- front method --------------------------------------------------------------------------------------------------
        T front(){
            if(head != NULL){//if there's an element in the queue
                cout<<"first element: "<<head->nodeValue<<endl;
                return head -> nodeValue;//return the first element
            }
            else{
                cout <<"Queue is empty. There's nothing at the front"<<endl;
            }
        }

    //---------- back method ---------------------------------------------------------------------------------------------------
        T back(){
            if(tail != NULL){//if there's an element in the queue
                cout<<"Last element: " << tail ->nodeValue<<endl;
                return tail -> nodeValue;//return the element at the end
            }
            else{
                cout <<"Queue is empty. There's nothing at the back"<<endl;
            }
        }

    //---------- push method ---------------------------------------------------------------------------------------------------
        void push(T value){
            if(head == NULL){//if the queue is empty
                head = new Node<T>(value);//the inserted element will be the first element
                tail = head;//tail is pointing at the same element
                ++queueSize;//increase the queue's size
                cout<<value<<" was successfully inserted at the front of the queue"<<endl;
            }
            else{//there are more than one element
                tail->next = new Node<T>(value);//tail's next element will be the new value
                tail = tail ->next;//tail is point now to the next element, which becomes now the tail
                ++queueSize;//increase the queue's size
                cout<<value<<" was successfully inserted at the end of the queue"<<endl;
            }
        }

    //---------- pop method ----------------------------------------------------------------------------------------------------
        T pop(){
            if(head == NULL){//if the queue is empty
                cout <<"Queue is empty. Can't pop anything"<<endl;
                return NULL;
            }
            else if(head == tail){//if there is just one element in the queue
                T temp = head->nodeValue;//get that value
                head = NULL;//reset the head
                tail = NULL;//reset the tail
                --queueSize;//decrease the size
                return temp;//return the saved value
            }
            else{//there is more than one element
                T value = head -> nodeValue;//save the head's value
                head = head ->next;//move the head to its next element, which becomes the new head
                --queueSize;//decrease the queue's size
                cout<<"popping the first element: "<<value<<endl;
                return value;//return the saved value
            }
        }

    //---------- display method ------------------------------------------------------------------------------------------------
        void display(){
            Node<T> *temp = head;//get a copy of the head
            cout<<"Current elements in the queue: ";
            while(temp){//while the temp is not null
                cout<<temp -> nodeValue <<" ";//get the current value
                temp = temp ->next;//next will be the copy of the next value
            }
            cout<<endl;
        }

};
//---------- main method --------------------------------------------------------------------------------------------------------
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
    cout << "is myQueue empty? : " << myQueue.empty()<<endl;
    return 0;
}
