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
    void insertionSort();
    void sort();
    //NEW FUNCTIONS BELOW
    void bubbleSort();
    void swap(int index1, int index2);
    void selectionSort();
    void deleteIndex(int i);
    void noDups();

    void insert_in_order(int i);
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

void EncapsulatedArray::bubbleSort(){
    for(int i=0; i<number_of_elements-1; i++){
        for(int j=0; j<number_of_elements-1; j++){
            if(array[j]>array[j+1]){
                swap(j,j+1);
            }
        }
    }

}

void EncapsulatedArray::swap(int index1, int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void EncapsulatedArray::selectionSort(){
    int min, min_index;

    for(int current_index =0 ; current_index<number_of_elements-1; current_index++){
        min_index = current_index;
        for(int i = current_index+1; i<number_of_elements; i++){
            if(array[i]<array[min_index]){
                min_index=i;
            }
        }
        swap(current_index,min_index);
    }
}

void EncapsulatedArray::insertionSort(){
    int in, out, temp;

    for(out=1; out<number_of_elements; out++){
        in = out;
        temp = array[in];//1)
        while(in>0 && array[in -1]>temp){//2)
            array[in]=array[in-1];//3)
            in--;
        }
        array[in]=temp; //4)

    }
}

void EncapsulatedArray::deleteIndex(int i) {
    for(int j = i; j < number_of_elements - 1; j++) {
        if (j < number_of_elements - 1) {
            array[j] = array[j + 1];
        }
    }
    number_of_elements--;
}

void EncapsulatedArray::noDups() {
    for(int i=0; i<number_of_elements; i++){
        for(int j = i+1; j<number_of_elements; j++){
            if(array[i] == array[j]){
                for(int k = i; k < number_of_elements - 1; k++) {
                    if (k < number_of_elements - 1) {
                        array[k] = array[k + 1];
                    }
                }
                number_of_elements--;
                for(int k = j-1; k < number_of_elements - 1; k++) {
                    if (k < number_of_elements - 1) {
                        array[k] = array[k + 1];
                    }
                }
                number_of_elements--;
                break;
            }
        }
    }
}

void EncapsulatedArray::insert_in_order(int x) {
    for(int i=0;i < number_of_elements; i++ ){
        if(x < array[i]){
            number_of_elements++;
            int j;
            for(j = number_of_elements - 1; i < j; j--){
                array[j] = array[j - 1];
            }
            array[j]=x;
            break;
        }
    }
}

int main(){
    EncapsulatedArray anArray(5);
    anArray.add(3);
    anArray.add(2);
    anArray.add(5);
    anArray.add(8);
    anArray.add(8);
    anArray.add(1);
    anArray.show();
    anArray.bubbleSort();
    anArray.show();
    anArray.swap(0,4);
    anArray.show();
    anArray.selectionSort();
    anArray.show();
    anArray.deleteIndex(2);
    anArray.show();
    anArray.noDups();
    anArray.show();
    anArray.insert_in_order(3);
    anArray.show();
}
/*
C:\Users\siddi\CLionProjects\p5\cmake-build-debug\p5.exe
array = {3, 2, 5, 8, 8, 1} //Original array
array = {1, 2, 3, 5, 8, 8} //Bubble Sort function
array = {8, 2, 3, 5, 1, 8} //Swap function; swapped indices 0 and 4
array = {1, 2, 3, 5, 8, 8} //Selection Sort function
array = {1, 2, 5, 8, 8} //Delete Index function; deleted index 2
array = {1, 2, 5} //Nodups function; removed 8's
array = {1, 2, 3, 5} //Insert_in_order function; inserted 3 in the appropriate place

Process finished with exit code 0
*/
