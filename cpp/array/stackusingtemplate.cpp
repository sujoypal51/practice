#include <iostream>
using namespace std;
template <typename T>
class StackusingArray{
    T *data;
    int nextIndex;
    int capacity;
    public:
    // StackusingArray(int totalsize)
    StackusingArray(){
        data=new T(4);
        // data=new int(totalsize);
        nextIndex=0;
        capacity=4;
    }
    
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(T element){
        if(nextIndex==capacity){
            T *newdata=new T[2*capacity];
            for(int i;i<capacity;i++){
                newdata[i]=data[i];
            }
            capacity*=2;
            delete []data;
            data=newdata;
            // cout<<"stack full"<<endl;
            // return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
}};
int main() {
    StackusingArray<char> s;
        s.push(100);
        s.push(101);
        s.push(102);
        s.push(104);
        s.push(105);
        s.push(107);
        cout<<s.top()<<endl;
        cout<<s.pop()<<endl;
        cout<<s.pop()<<endl;
        cout<<s.size()<<endl;
        cout<<s.isEmpty()<<endl;
}