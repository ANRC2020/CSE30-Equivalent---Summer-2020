#include <iostream>
#include <iomanip>
using namespace std;

class Link{
public:
    int data;
    Link *pNext, *pPrev;
    Link(int newData){
        data = newData;
        pNext = NULL;
        pPrev = NULL;
    }
    void display(){
        cout<<"{ " << setw(3) << data << "\t:\t" << setw(14) << pPrev << "\t:\t\t" << &data << "\t:\t" << setw(14) << pNext << " }\n";
    }

};

class DoubleEndedList{
private:
    Link *pFirst, *pLast;
public:
    DoubleEndedList() {
        pFirst = NULL;
        pLast = NULL;
    }
    void displayFirst(){
        cout << "First: ";
        pFirst->display();
    }
    void displayLast(){
        cout << "Last: ";
        pLast->display();
    }
    void displayList(){ // Displays list front -> end
        Link *temp = pFirst;
        cout << "Begin List: \n";
        cout << "{ data\t:\t\tpPrev\t\t\t  self\t\t\t\tpNext  }\n";
        while(temp != pLast){
                temp->display();
                temp = temp->pNext;
        }
        temp->display(); // Needed to print out the last number
        cout << "/End List" << endl;
        displayFirst();
        displayLast();
        cout << endl;
    }
    void displayBackward(){ // Display list end -> front
        Link *temp = pLast;
        cout << "End of list: \n";
        cout << "{ data\t:\t\tpPrev\t\t\t  self\t\t\t\tpNext  }\n";
        while(temp != pFirst){
            temp->display();
            temp = temp->pPrev;
        }
        temp->display(); // Needed to print out the last number
        cout << "/Beginning of List" << endl;
        displayFirst();
        displayLast();
        cout << endl;
    }
    void insert(int newValue){ // Inserts in order (ascending)
        Link *newLink = new Link(newValue);
        if(pFirst == NULL && pLast == NULL){
            cout << "Inserting the First/Last link: \n";
            newLink->display();

            newLink->pNext = NULL;
            newLink->pPrev = NULL;
            pFirst = newLink; // Sets pFirst to address of newLink
            pLast = newLink; // Sets pLast to address of newLink
            return;
        }
        if(newValue < pFirst->data){
            cout << "Inserting new First link: \n";
            newLink -> display();

            pFirst->pPrev = newLink;
            newLink->pPrev = NULL;
            newLink->pNext = pFirst;
            pFirst = newLink;
            return;
        }
        if(newValue > pLast->data){
            cout << "Inserting new Last link: \n";
            newLink->display();

            pLast->pNext = newLink;
            newLink->pPrev = pLast;
            newLink->pNext = NULL;
            pLast = newLink;
            return;
        }
        cout << "Inserting (somewhere b/w First and Last) the new link: \n";
        newLink->display();

        Link *Next = pFirst;
        while(Next != pLast){
            if(newValue < Next->data){
                break;
            }
            Next = Next->pNext;
        }
        newLink->pNext= Next;
        newLink->pPrev= Next->pPrev;
        Next->pPrev->pNext = newLink;
        Next->pPrev = newLink;
    }
    void removeFirst(){ // Removes first link
        cout << "Removed the first link of value: " << pFirst->data << endl;
        pFirst = pFirst->pNext;
        pFirst->pPrev = NULL;
    }
    void removeLast(){ // Removes last link
        cout << "Removed the last link of value: " << pLast->data << endl;
        pLast = pLast->pPrev;
        pLast->pNext = NULL;
    }
    void removeValue(int value){ // Removes link with given value
        Link *current = pFirst;
        while(current != pLast){
            if(value == current->data){
                break;
            }
            current = current->pNext;
        }
        if(value == current->data) {
            cout << "Removed link of value: " << current->data;
            current->pPrev->pNext = current->pNext;
            current->pNext->pPrev = current->pPrev;
        } else {
            cout << "Link with value " << value << " not found." << endl;
        }

    }
};

int main() {
    DoubleEndedList *list = new DoubleEndedList();
    list->insert(10);
    list->displayList();
    list->insert(7);
    list->insert(22);
    list->insert(18);
    list->insert(9);
    list->insert(15);
    list->insert(13);
    list->displayList();
    list->removeFirst();
    cout << endl;
    list->displayList();
    list->removeLast();
    cout << endl;
    list->displayList();
    list->removeValue(100);
    cout << endl;
    list->displayList();
    list->removeValue(13);
    list->displayList();
    list->displayBackward();
    list->displayLast();
    list->displayFirst();

}
/*
C:\Users\siddi\CLionProjects\p9\cmake-build-debug\p9.exe
Inserting the First/Last link:                                                                     // Inserted first number
{  10   :             00000000  :               008CCA10        :             00000000 }
Begin List:                                                                                        // Tested display function (normal)
{ data  :               pPrev                     self                          pNext  }
{  10   :             00000000  :               008CCA10        :             00000000 }
/End List
First: {  10    :             00000000  :               008CCA10        :             00000000 }
Last: {  10     :             00000000  :               008CCA10        :             00000000 }

Inserting new First link:                                                                          // Inserted new first link
{   7   :             00000000  :               008CCD58        :             00000000 }
Inserting new Last link:                                                                           // Inserted new last link
{  22   :             00000000  :               008CCA48        :             00000000 }
Inserting (somewhere b/w First and Last) the new link:                                             // Inserted new link in between 10 and 22
{  18   :             00000000  :               008CCA80        :             00000000 }
Inserting (somewhere b/w First and Last) the new link:                                             // Inserted new link in between 7 and 10
{   9   :             00000000  :               008CCCE8        :             00000000 }
Inserting (somewhere b/w First and Last) the new link:                                             // Inserted new link in between 10 and 18
{  15   :             00000000  :               008CCB98        :             00000000 }
Inserting (somewhere b/w First and Last) the new link:                                             // Inserted new link in between 10 and 15
{  13   :             00000000  :               008CCCB0        :             00000000 }
Begin List:                                                                                        // Tested Display method (normal)
{ data  :               pPrev                     self                          pNext  }
{   7   :             00000000  :               008CCD58        :             008CCCE8 }
{   9   :             008CCD58  :               008CCCE8        :             008CCA10 }
{  10   :             008CCCE8  :               008CCA10        :             008CCCB0 }
{  13   :             008CCA10  :               008CCCB0        :             008CCB98 }
{  15   :             008CCCB0  :               008CCB98        :             008CCA80 }
{  18   :             008CCB98  :               008CCA80        :             008CCA48 }
{  22   :             008CCA80  :               008CCA48        :             00000000 }
/End List
First: {   7    :             00000000  :               008CCD58        :             008CCCE8 }
Last: {  22     :             008CCA80  :               008CCA48        :             00000000 }

Removed the first link of value: 7                                                                  // Tested removeFirst function; removed link of value 7

Begin List:
{ data  :               pPrev                     self                          pNext  }
{   9   :             00000000  :               008CCCE8        :             008CCA10 }
{  10   :             008CCCE8  :               008CCA10        :             008CCCB0 }
{  13   :             008CCA10  :               008CCCB0        :             008CCB98 }
{  15   :             008CCCB0  :               008CCB98        :             008CCA80 }
{  18   :             008CCB98  :               008CCA80        :             008CCA48 }
{  22   :             008CCA80  :               008CCA48        :             00000000 }
/End List
First: {   9    :             00000000  :               008CCCE8        :             008CCA10 }
Last: {  22     :             008CCA80  :               008CCA48        :             00000000 }

Removed the last link of value: 22                                                                 // Tested removeLast function; removed link of value 22

Begin List:                                                                                        // Displays updated list
{ data  :               pPrev                     self                          pNext  }
{   9   :             00000000  :               008CCCE8        :             008CCA10 }
{  10   :             008CCCE8  :               008CCA10        :             008CCCB0 }
{  13   :             008CCA10  :               008CCCB0        :             008CCB98 }
{  15   :             008CCCB0  :               008CCB98        :             008CCA80 }
{  18   :             008CCB98  :               008CCA80        :             00000000 }
/End List
First: {   9    :             00000000  :               008CCCE8        :             008CCA10 }
Last: {  18     :             008CCB98  :               008CCA80        :             00000000 }

Link with value 100 not found.                                                                     // Tested removeValue function with 100; couldn't find link of such a value

Begin List:                                                                                        // No change to the list
{ data  :               pPrev                     self                          pNext  }
{   9   :             00000000  :               008CCCE8        :             008CCA10 }
{  10   :             008CCCE8  :               008CCA10        :             008CCCB0 }
{  13   :             008CCA10  :               008CCCB0        :             008CCB98 }
{  15   :             008CCCB0  :               008CCB98        :             008CCA80 }
{  18   :             008CCB98  :               008CCA80        :             00000000 }
/End List
First: {   9    :             00000000  :               008CCCE8        :             008CCA10 }
Last: {  18     :             008CCB98  :               008CCA80        :             00000000 }

Removed link of value: 13                                                                          // Tested removeValue fun. for 13; it worked

Begin List:                                                                                        // Shows updated list
{ data  :               pPrev                     self                          pNext  }
{   9   :             00000000  :               008CCCE8        :             008CCA10 }
{  10   :             008CCCE8  :               008CCA10        :             008CCB98 }
{  15   :             008CCA10  :               008CCB98        :             008CCA80 }
{  18   :             008CCB98  :               008CCA80        :             00000000 }
/End List
First: {   9    :             00000000  :               008CCCE8        :             008CCA10 }
Last: {  18     :             008CCB98  :               008CCA80        :             00000000 }

End of list:                                                                                       // Tested displayBackwards function
{ data  :               pPrev                     self                          pNext  }
{  18   :             008CCB98  :               008CCA80        :             00000000 }
{  15   :             008CCA10  :               008CCB98        :             008CCA80 }
{  10   :             008CCCE8  :               008CCA10        :             008CCB98 }
{   9   :             00000000  :               008CCCE8        :             008CCA10 }
/Beginning of List
First: {   9    :             00000000  :               008CCCE8        :             008CCA10 }
Last: {  18     :             008CCB98  :               008CCA80        :             00000000 }

Last: {  18     :             008CCB98  :               008CCA80        :             00000000 }   // Tested displayLast function
First: {   9    :             00000000  :               008CCCE8        :             008CCA10 }   // Tested displayfirst function

Process finished with exit code 0

*/