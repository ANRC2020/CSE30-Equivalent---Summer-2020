#include <iostream>
using namespace std;

class Queue{
    private:
        int size, front, rear, number_items=0;
        int *queueArray;
    public:
        Queue(int newSize) { //constructor
            size = newSize;
            queueArray = new int[size];
            front = 0;// front moves forward (+) upon remove
            rear = -1;// nothing there yet, rear moves forward (+) upon insert
        }

        // rear++ upon insertion, if rear reached far right, move it to far left
        void insert(int newValue){// put item at rear of queue
            // deal with wraparound
            if(rear == size - 1){//reached the far right
                rear = -1;// move to beginning, so rear++ goes to 0
            }
            rear++;// increment rear
            queueArray[rear] = newValue;// insert
            number_items++; // one more item added
        }

        //front++ upon removal, if front reaches far right, ove it to far left
        int remove(){
            int temp = queueArray[front++];
            if(front == size){
                front = 0;
            }
            number_items--;// one less item
            return temp;
        }

        int peekFront(){
            return queueArray[front];
        }

        int peekRear(){
            return queueArray[rear];
        }

        bool isEmpty(){
            if(number_items == 0){
                return true;
            }
            return false;
        }

        bool isFull(){
            return (number_items==size);
        }

        int qsize(){
            return number_items;
        }

        void insertLeft(int value){//insert value before the index 0
            if(front>0){
                front --;
                number_items++;
                queueArray[front] = value;
            } else {
                number_items++;
                for(int i=number_items; i>0 ;i--){
                    queueArray[i] = queueArray[i-1];
                }
                queueArray[0] = value;
            }
        }

        void insertRight(int value){//insert value after last index
            rear++;
            number_items++;
            queueArray[rear] = value;
        }
};

int main() {
    Queue aQueue(7);    //{ };                  front=0, rear=-1
    aQueue.insert(10); //{10};                 front=0, rear=0
    aQueue.insert(20); //{10,20};              front=0, rear=1
    aQueue.insert(30); //{10,20,30};           front=0, rear=2
    aQueue.insert(40); //{10,20,30,40};        front=0, rear=3
    //                        Front^        ^REAR
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aQueue.insertRight(50);
    aQueue.insertRight(60);
    aQueue.insertLeft(0);
    while(!aQueue.isEmpty()){
        cout << aQueue.peekFront() << " ";
        aQueue.remove();
    }
}

/*
C:\Users\siddi\CLionProjects\Queue\cmake-build-debug\Queue.exe
0 10 20 30 40 50 60 // used two calls to insertRight to add in 50 and 60 and insertLeft to add in 0 in front
Process finished with exit code 0
 */
