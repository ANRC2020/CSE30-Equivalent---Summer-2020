#include <iostream>;
using namespace std;

class Stack{
    private:
        int size;//size of stackArray
        int top;// top of stackArray
        int *stackArray;
    public:
        Stack(int newSize){
            size = newSize; // set array size
            stackArray = new int[size]; // make a new dynamic array
            top = -1; // no items yet
        }

        // put item on topof stack
        void push(int newValue){
            stackArray[++top] = newValue;/* increment top, insert item*/
        }

        int pop(){
            return stackArray[top--]; /*access item, decrement top*/
        }

        int peek() {
            return stackArray[top]; //access item
        }

        bool isEmpty() {
            return(top==-1);
        }

        bool isFull() {
            return (top == size -1);
        }
};

class CharStack{
    private:
        int size;//size of stackArray
        int top;// top of stackArray
        int *stackArray;
    public:
        CharStack(int newSize){
            size = newSize; // set array size
            stackArray = new int[size]; // make a new dynamic array
            top = -1; // no items yet
        }

        // put item on topof stack
        void push(int newValue){
            stackArray[++top] = newValue;/* increment top, insert item*/
        }

        int pop(){
            return stackArray[top--]; /*access item, decrement top*/
        }

        int peek() {
            return stackArray[top]; //access item
        }

        bool isEmpty() {
            return(top==-1);
        }

        bool isFull() {
            return (top == size -1);
        }

};

int main() {
    /*
    Stack aStack(10);

    aStack.push(20);
    aStack.push(40);
    aStack.push(60);
    aStack.push(80);

    cout << "popping the values out of the stack: ";
    while(!aStack.isEmpty()){
        cout<< aStack.pop()<< " ";
    }
    cout << endl;
    */
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    char a[] = {'h','e','l','l','o',' ', 'w','o','r','l','d','!'};
    CharStack reverse(12);

    for(int i = 11; i >= 0; i--){
        cout<<a[i];
        reverse.push(a[i]);
    }
    cout<<endl;
}

/*
C:\Users\siddi\CLionProjects\CharStack.ccp\cmake-build-debug\CharStack_ccp.exe
!dlrow olleh

Process finished with exit code 0
*/