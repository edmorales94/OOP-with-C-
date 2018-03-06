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

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
