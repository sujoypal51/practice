#include <iostream>
using namespace std;
template <typename T>
class QueueusingArray{
    T *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;

    public:
    QueueusingArray(int s){
        data=new T(s);
        nextindex=0;
        firstindex=-1;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if(size==capacity){
            cout<<"queue full"<<endl;
            return;
        }
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        if(firstindex==-1){
            firstindex=0;
        }
        size++;
    }
    T front(){
        if(isEmpty()){
            cout<<"queue is full"<<endl;
            return 0;
        }
        return data[firstindex];
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"queue is full"<<endl;
            return 0;
        }
        T ans=data[firstindex];
        firstindex++;
        size--;
        if(size==0){
            firstindex=-1;
            nextindex=0;
        }
        return ans;
    }
};
int main(){
    QueueusingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}