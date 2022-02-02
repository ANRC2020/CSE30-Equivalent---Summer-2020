#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//////////////////////////// HASH TABLE //////////////////////////////////
//hash.cpp
//display hash table with linear probing
//////////////////////////////////////////////////////////////////////////
class DataItem { //(could have more data)
public:
    int data;
    //--------------------------------------------------------------------
    DataItem(int newData){
        data = newData;
    } //constructor {}
    //--------------------------------------------------------------------
    //end class DataItem
};
///////////////////////////////////////////////////////////////////////////
class HashTable {
private:
    vector<DataItem*> hashArray; //vector holds hash table
    int arraySize;
    DataItem* pNonItem; //for deleted items

public:
    //---------------------------------------------------------------------
    HashTable(int size){ //constructor
        arraySize = size;
        hashArray.resize(arraySize); //size the vector
        for(int j = 0; j < arraySize; j++){
            hashArray[j] = NULL;
        }
        pNonItem = new DataItem(-1);
    }

    //----------------------------------------------------------------------
    void displayTable(){
        cout << "Table: ";
        for(int j = 0; j<arraySize; j++){
            if(hashArray[j] != NULL){
                cout << hashArray[j]->data << " ";
            } else {
                cout << "** ";
            }
        }
        cout << endl;
    }
    //----------------------------------------------------------------------
    int hashFunc(int key){
        return key % arraySize; //hash function
    }
    //----------------------------------------------------------------------
    void insert(DataItem* pItem) { //Insert a DataItem
        //{assumes table not full}
        int key = pItem->data;// extract key
        int hashVal = hashFunc(key);//hash the key
                                    //until empty cell or -1
        while(hashArray[hashVal] != NULL && hashArray[hashVal] -> data != -1){
            ++hashVal; //go to next cell
            hashVal %= arraySize; //wraparound if necessary
        }
        hashArray[hashVal] = pItem;//insert item
        //end insert()
    }
    //-----------------------------------------------------------------------
    DataItem* find(int key){
        int hashVal = hashFunc(key);
        //cout << "hashVal stored value: " << hashVal << endl;
        HashTable checker (1);
        while(hashArray[hashVal] != NULL){
            if(hashArray[hashVal]->data == key){
                return hashArray[hashVal];
            }
            ++hashVal;//go to next cell
            hashVal %= arraySize;
        }
        return  NULL;
    }
    //-----------------------------------------------------------------------
    DataItem* remove(int key){  //remove a DataItem
        int hashVal = hashFunc(key);
        while(hashArray[hashVal] != NULL){
            if(hashArray[hashVal]->data == key){
                DataItem* pTemp = hashArray[hashVal];
                hashArray[hashVal] = pNonItem;
                return pTemp;
            }
            ++hashVal;
            hashVal %+ arraySize;
        }
        return NULL;
    }
    //-----------------------------------------------------------------------
};
///////////////////////////////////////////////////////////////////////////
int main() {
    DataItem* pDataItem;
    int aKey, size, n, keysPerCell;
    time_t aTime;
    char choice = 'b';
    //get sizes
    cout << "Enter size or hash table:";
    cin >> size;
    cout << "Enter initial number of items:";
    cin >> n;
    keysPerCell = 10;

    HashTable theHashTable(size);//makes table
    srand(static_cast<unsigned>(time(&aTime)) ); // make a random list numbers
    for(int j=0; j<n; j++){ // insert data
        aKey = rand() % (keysPerCell*size); // r
        pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
    }
    while(choice != 'x') { //interact with user
        cout << "\n";
        cout << "Enter first letter of show, insert, delete, or find:";
        char choice;
        cin >> choice;

        switch(choice){
            case 's':
                theHashTable.displayTable();
                break;
            case 'i':
                cout << "Enter key value to insert:";
                cin >> aKey;
                pDataItem = new DataItem(aKey);
                theHashTable.insert(pDataItem);
                break;
            case 'd':
                cout << "Enter key value to delete:";
                cin >> aKey;
                theHashTable.remove(aKey);
                break;
            case 'f':
                cout << "Enter key value to find:";
                cin >> aKey;
                pDataItem = theHashTable.find(aKey);
                //cout << "pDataItem: " << pDataItem << endl;
                if(pDataItem != NULL){
                    cout << "Found " << aKey << endl;
                } else {
                    cout << "Could not find " << aKey << endl;
                }
                break;
            case 'x':
                cout << "Exiting the program...";
                break;
            default:
                cout << "Invalid entry\n";
        } //end switch
        if(choice == 'x'){
            break;
        }
    } //end while
    cout << "done!";
} //end main()

/*
C:\Users\siddi\CLionProjects\HashTable\cmake-build-debug\HashTable.exe
Enter size or hash table:12                                             //Initialize vector to size 12
Enter initial number of items:8                                         //Randomly populate 8 cells of the 12 avalible

Enter first letter of show, insert, delete, or find:s                   //Display method called
Table: ** ** 86 27 100 39 100 ** 44 21 105 **                           //Display method's output

Enter first letter of show, insert, delete, or find:f                   //Find method called to find value of 1
Enter key value to find:1
Could not find 1                                                        //Find method's output; 1 was not present in the hashtable

Enter first letter of show, insert, delete, or find:f                   //Find method called to find value of 100
Enter key value to find:100
Found 100                                                               //Find method's output; 100 was present in the hashtable

Enter first letter of show, insert, delete, or find:i                   //Insert method called to insert a value of 1
Enter key value to insert:1

Enter first letter of show, insert, delete, or find:s                   //Display method shows that 1 has been added to the hashtable
Table: ** 1 86 27 100 39 100 ** 44 21 105 **

Enter first letter of show, insert, delete, or find:d                   //Delete method called to remove value 86
Enter key value to delete:86

Enter first letter of show, insert, delete, or find:s                   //Display method shows that 86 has been removed from the hashtable
Table: ** 1 -1 27 100 39 100 ** 44 21 105 **

Enter first letter of show, insert, delete, or find:x                   //User typed 'x' to end program
Exiting the program...done!
Process finished with exit code 0
 */