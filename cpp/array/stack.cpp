#include <iostream>
using namespace std;
class StackusingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    // StackusingArray(int totalsize)
    StackusingArray(){
        data=new int(4);
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
    void push(int element){
        if(nextIndex==capacity){
            int *newdata=new int[2*capacity];
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
    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT8_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT8_MIN;
        }
        return data[nextIndex-1];
}};
int main() {
    StackusingArray s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(70);
        s.push(90);
        s.push(70);
        cout<<s.top()<<endl;
        cout<<s.pop()<<endl;
        cout<<s.pop()<<endl;
        cout<<s.size()<<endl;
        cout<<s.isEmpty()<<endl;
}