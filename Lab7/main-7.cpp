#include <iostream>
using namespace std;

class Link{
    public:
        int iData; //data
        double dData; //data
        Link *pNext; // pointer to next link

        Link(int id, double dd){ // constructor
            iData = id;
            dData = dd;
            pNext = NULL; // refer to nothing
            // until connected to other Link
        }

        void displayLink(){
            cout<<"{"<<iData<<", ";
            cout<<dData<<"} ";
        }

};

class LinkList{
    private:
        Link *pFirst; // ptr to first link on list

    public:
        int counter = 0;

        LinkList(){
            pFirst = NULL; // no links on list yet
        }

        bool isEmpty(){
            if(counter == 0){
                return true; //false if list is empty
            } else {
                return false; //true if list is empty
            }
        }

        void insertFirst(int id, double dd){
            Link *pNewLink = new Link(id,dd); // make new link
            pNewLink->pNext = pFirst; // newLink --> old first (1)
            pFirst = pNewLink; // first --> newLink
            counter++;
        }

        Link *getFirst(){
            return pFirst;
        }

        int getCounter(){
            return counter;
        }

        void removeFirst(){
            Link *pTemp = pFirst;
            pFirst = pFirst->pNext;
            delete pTemp;
            counter--;
        }

        void displayList(){
            cout << "List (first-->last): ";
            Link *pCurrent = pFirst; // start at beginning of list
            while(pCurrent != NULL){
                pCurrent->displayLink(); // show the link
                pCurrent = pCurrent->pNext; // move to next link
            }
            cout<<endl;
        }

        Link *find(int key){
            Link *pCurrent = pFirst;
            while(pCurrent->iData != key){
                if(pCurrent->pNext == NULL){//changed "!=" to "=="
                    return NULL;
                } else {
                    pCurrent = pCurrent->pNext;
                }
            }
            return pCurrent;
        }

        bool remove(int key){
            Link *pCurrent = pFirst;
            Link *pPrevious = pFirst;
            while(pCurrent->iData != key){
                if(pCurrent->pNext == NULL){
                    return false;
                } else {
                    pPrevious = pCurrent;
                    pCurrent = pCurrent->pNext;
                }
            }
            if(pCurrent == pFirst){
                pFirst = pFirst->pNext;
            } else {
                pPrevious->pNext = pCurrent->pNext;
            }
            delete pCurrent;
            counter--;
            return true;
        }

        int sumIdata() {
            int sum = 0;
            Link *pTemp = pFirst;
            for(int i = 1; i < counter; i++){
                sum += pTemp->iData;
                pTemp = pTemp->pNext;
            }
            return sum;
        }

        int min() {
            Link *pTemp = pFirst;
            int min = pTemp->iData;
            pTemp = pTemp->pNext;
            for(int i = 2; i < counter; i++){
                if(min > pTemp->iData){
                    min = pTemp->iData;
                }
                pTemp = pTemp->pNext;
            }
            return min;
        }

        int numLinks(){
            return counter;
        }
};

int main() {
    LinkList theList; // make new list
    theList.insertFirst(22, 2.99);
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);

    theList.displayList(); // show the list
    //List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

    while ( !theList.isEmpty() ){
        Link *pTemp = theList.getFirst(); // get first link
        cout<<"\nRemoving link with data ";
        pTemp->displayLink(); // display links data
        theList.removeFirst(); // remove it
    }

    cout<<endl<<"Empty list :";
    theList.displayList();

    theList.insertFirst(22, 2.99);
    theList.insertFirst(44, 4.99);
    theList.insertFirst(66, 6.99);
    theList.insertFirst(88, 8.99);
    cout<<"\nReinserting the links back"<<endl;
    theList.displayList();

    int findKey = 44;
    Link *pFind = theList.find(findKey);
    if(pFind != NULL){
        cout<<"Found link with key: "<<pFind->iData<<endl;
    } else {
        cout<<"Can't find link with key "<< findKey <<endl;
    }

    if(theList.remove(findKey)){
        cout<<"Deleted "<< findKey << " from the list.\n";
    } else {
        cout<<"Did not delete "<< findKey<<" from the list.\n";
    }
    cout<<"Link list after deletion\n";
    theList.displayList();

    int sum = theList.sumIdata();
    cout<<"\nThe sum of all links is: "<< sum <<endl;
    int minimum = theList.min();
    cout<<"\nThe minimum of all links is: "<< minimum << endl;
    cout<<"\nThe number of links in the list is: "<< theList.numLinks()<<endl;
}

/*
C:\Users\siddi\CLionProjects\p7\cmake-build-debug\p7.exe
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}

Removing link with data {88, 8.99}
Removing link with data {66, 6.99}
Removing link with data {44, 4.99}
Removing link with data {22, 2.99}
Empty list :List (first-->last):

Reinserting the links back
List (first-->last): {88, 8.99} {66, 6.99} {44, 4.99} {22, 2.99}
Found link with key: 44
Deleted 44 from the list.
Link list after deletion
List (first-->last): {88, 8.99} {66, 6.99} {22, 2.99}

The sum of all links is: 154 //SUM OF ALL LINKS FUNCTION

The minimum of all links is: 66 //LIST MINIMUM FUNCTION

The number of links in the list is: 3 //NUMBER OF ITEMS/LINKS IN LIST FUNCTION

Process finished with exit code 0

 *NOTE* I used the global variable "counter" in place of using a "while(pCurrent != NULL)" to keep track of loop iteration
 and the like in several of the above functions for the sake of simplicity
*/