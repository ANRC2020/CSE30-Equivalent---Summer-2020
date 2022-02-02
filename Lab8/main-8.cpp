#include <iostream>
using namespace std;

class Link {
    public:
        int data;
        Link *next;

        Link(int newData) {
            data = newData;
            next = NULL;
        }

        void show() {
            cout << "{" << data << "}";
        }
};

class CircularList {
    private:
        Link *current;
        int numLinks;
    public:
        CircularList() {
            current = NULL;
            numLinks = 0;
        }

        bool empty()
        {
            return (numLinks == 0);
        }

        bool search(int valueToFind) {
            if(!empty()){
                for(int i = 0; i<numLinks; i++){
                    if(current->data == valueToFind){
                        return true;
                    }
                    current = current -> next;
                }
            }
            return false;
        }

        void insertInitialLink(int newValue){
            Link *newLink = new Link(newValue);
            if(numLinks == 0){                  //if-else statement used to connect individual links to each other's next
                current = newLink;
                current->next=current;
            } else {
                newLink->next=current->next;
                current->next=newLink;
            }
            numLinks++;
        }

        void displayList(){
            current = current -> next;
            for(int i = 0; i < numLinks; i++){
                if(current->data != NULL){
                    current->show();
                }
                current = current -> next;
                current -> data;
            }
        }


    void insertAfterValueFound(int newValue, int valueToFind) {

        current = current -> next;
        for(int i = 0; i < numLinks; i++){
            if(current->data == valueToFind){
                Link *temp = current;
                Link *newLink = new Link(newValue);
                newLink->next=current->next;
                current->next=newLink;
                numLinks++;
                break;
            }
            current = current -> next;
            current -> data;
        }

    }

    bool deleteLink(int valueToFind){
        for(int i = 0; i < numLinks; i++){
            if(current->data == valueToFind){
                current->data=NULL;
                numLinks--;
                return true;
            }
            current = current -> next;
            current -> data;
        }
        return false;
    }
};

int main() {
    CircularList theList; // make new list
    theList.insertInitialLink(10); // insert values; 10 is the last link
    theList.insertInitialLink(20);
    theList.insertInitialLink(30);
    theList.insertInitialLink(40); // 40 is the first link

    theList.displayList();
    cout<<endl;

    cout<<endl<<theList.search(50)<<endl;
    cout<<theList.search(20)<<endl;

    cout<<endl;
    theList.insertAfterValueFound(35,30);
    theList.displayList();

    cout<<endl;
    cout<<endl<<theList.deleteLink(30)<<endl;
    cout<<endl;
    theList.displayList();
    cout<<endl;

}
/*
C:\Users\siddi\CLionProjects\p8\cmake-build-debug\p8.exe
{40}{30}{20}{10} //Used displayList() to display all inserted values

0 // Returned FALSE or 0 for search(50) method
1 // Returned TRUE or 1 for  search(20) method

{35}{20}{10}{40}{30} // Inserted value of 35 after 30

1 // Successfully found and deleted 30 from the circular list

{35}{20}{10}{40} // Display updated list

Process finished with exit code 0

 */