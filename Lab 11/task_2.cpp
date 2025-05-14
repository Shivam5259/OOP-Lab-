#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
    T* data;
    int size, capacity;

public:
    Queue(int cap) : size(0), capacity(cap) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value){
        if (size == capacity){
            throw QueueOverflowException();
        }
        data[size++] = value;
    }

    T dequeue(){
        if (size == 0){
            throw QueueUnderflowException();
        }
        T value = data[size--];
        return value;
    }
};

int main() {
    Queue<int> q(3);

    try{
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }
    try {
        Queue<int> q(2);
        q.dequeue();
    }
    catch (exception& e) {
        cout<< e.what() <<endl;
    }

}
