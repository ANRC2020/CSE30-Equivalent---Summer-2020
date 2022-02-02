#include <iostream>
using namespace std;

class EncapsulatedArray{
    private:
        int *array; // Dynamically allocated array
        int number_of_elements;
    public:
        EncapsulatedArray(int size);
        void add(int number_to_add);
        void show();
        void insertFirst(int number_to_add);
        void deleteNumber(int number_to_delete);
        void sort();
};

EncapsulatedArray::EncapsulatedArray(int size) {
    array = new int[size]; //Dynamically allocated array
    number_of_elements = 0;
}

void EncapsulatedArray::sort() {
    int size = sizeof(array);
    int temp;

    for(int i = 0; i < 4; i++){

        for(int j = 0; j < 4; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }

        }

    }
}

void EncapsulatedArray::deleteNumber(int number_to_delete){
    int size = sizeof(array);
    int index = 0;
    int counter = 0;

    while(counter == 0 || index != size){
        if(counter == 0 && number_to_delete == array[index]){
            counter++;
            break;
        }
        index++;
    }

    int x = index;
    if(counter == 0 && index == 0){

    } else {
        while(x < size){
            array[x] = array[x+1];
            x++;
        }
    }

}

void EncapsulatedArray::add(int number_to_add){
    array[number_of_elements] = number_to_add;
    number_of_elements++;
}

// show array as {9, 101, 9}
void EncapsulatedArray::show() {
    if(number_of_elements == 1){
        cout << "array = {" << array[0] << "}\n";
        return;
    }

    int i;
    cout << "array = {";
    for(i = 0; i < number_of_elements - 1; i++){
        cout << array[i] << ", ";
    }
    cout << array[i] << "}\n";
}

void EncapsulatedArray::insertFirst(int number_to_add) {
    int size = sizeof(array);
    int current = 0;
    int next = 0;
    for(int i = 0; i < size; i++){
        if(i == 0){
            current = array[i];
            array[i] = number_to_add;
            next = array[i+1];
            continue;
        }

        array[i] = current;
        current = next;
        next = array[i + 1];
    }

}

int main(){
    EncapsulatedArray anArray(5);
    anArray.add(3);
    anArray.show();
    anArray.add(2);
    anArray.show();
    anArray.add(5);
    anArray.show();
    anArray.insertFirst(7);
    anArray.show();
    anArray.deleteNumber(2);
    anArray.show();
    anArray.add(37);
    anArray.add(25);
    anArray.sort();
    anArray.show();

}
/*
C:\Users\siddi\CLionProjects\untitled3\cmake-build-debug\untitled3.exe
array = {3}
array = {3, 2}
array = {3, 2, 5}
array = {7, 3, 2}
array = {7, 3, 5}
array = {3, 5, 7, 25, 37}

Process finished with exit code 0
*/
