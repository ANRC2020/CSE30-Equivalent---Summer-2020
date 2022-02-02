#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

class Node{
public:
    int data;
    Node *pLeftChild;
    Node *pRightChild;

    Node(){
        data = 0;
        pLeftChild = NULL;
        pRightChild = NULL;
    }

    void displayNode(){
        cout << "{" << data << "}";
    }

};

class Tree{
private:
    Node *pRoot;
public:
    Tree(){
        pRoot = NULL;
    }

    Node* find(int key){
        Node *pCurrent = pRoot;
        while(pCurrent->data != key){
            if(key < pCurrent->data){
                pCurrent = pCurrent->pLeftChild;
            } else {
                pCurrent = pCurrent->pRightChild;
            }
            if(pCurrent == NULL){
                return NULL;
            }
        }
        return pCurrent;
    }

    void insert(int newData){
        Node *pNewNode = new Node;
        pNewNode->data = newData;

        if(pRoot == NULL){
            pRoot = pNewNode;
        } else {
            Node *pCurrent = pRoot;
            Node *pParent;
            while(true){
                pParent = pCurrent;
                if(newData < pCurrent->data){
                    pCurrent = pCurrent->pLeftChild;
                    if(pCurrent == NULL){
                        pParent->pLeftChild = pNewNode;
                        return;
                    }
                } else {
                    pCurrent = pCurrent->pRightChild;
                    if(pCurrent == NULL){
                        pParent->pRightChild = pNewNode;
                        return;
                    }
                }
            }
        }
    }

    void traverse(int treverseType){
        if(treverseType == 1){
            inOrder(pRoot);
        }
        if(treverseType == 2){
            postOrder(pRoot);
        }
        if(treverseType == 3){
            preOrder(pRoot);
        }
    }

    void inOrder(Node *pLocalRoot){
        if(pLocalRoot != NULL){
            inOrder(pLocalRoot->pLeftChild);
            cout << pLocalRoot->data << " ";
            inOrder(pLocalRoot->pRightChild);
        }
    }

    void preOrder(Node* pLocalRoot){
        if(pLocalRoot != NULL){
            cout << pLocalRoot->data << " ";
            preOrder(pLocalRoot->pLeftChild);
            preOrder(pLocalRoot->pRightChild);
        }
    }

    void postOrder(Node *pLocalRoot){
        if(pLocalRoot != NULL){
            postOrder(pLocalRoot->pLeftChild);
            postOrder(pLocalRoot->pRightChild);
            cout << pLocalRoot->data << " ";
        }
    }

    void minimum() {
        Node *pCurrent, *pLast;
        pCurrent = pRoot;
        while(pCurrent != NULL){
            pLast = pCurrent;
            pCurrent = pCurrent->pLeftChild;
        }
        cout << pLast->data << endl;
    }

    void displayTree() {
        stack <Node*> globalStack;
        globalStack.push(pRoot);
        int nBlanks = 32;
        bool isRowEmpty = false;
        cout <<".................................................................." << endl;
        while (isRowEmpty==false){
            stack<Node*> localStack;
            isRowEmpty = true;
            for(int j = 0; j<nBlanks; j++){
                cout << ' ';
            }
            while(globalStack.empty() == false){
                Node* temp = globalStack.top();
                globalStack.pop();
                if(temp != NULL){
                    cout << temp->data;
                    localStack.push(temp->pLeftChild);
                    localStack.push(temp->pRightChild);

                    if(temp->pLeftChild != NULL || temp->pRightChild != NULL){
                        isRowEmpty = false;
                    }
                } else {
                    //cout << "__";
                    //localStack.push(NULL);
                    //localStack.push(NULL);
                }

                cout << endl;
                nBlanks /= 2;
                while(localStack.empty()==false){
                    globalStack.push(localStack.top());
                    localStack.pop();
                }
            }

        }
        cout <<".................................................................." << endl;

        /*
        while (isRowEmpty==false){
            stack<Node*> localStack;
            isRowEmpty = true;
            for(int j = 0; j<nBlanks; j++){
                cout << ' ';
            }
            while(globalStack.empty() == false){
                Node* temp = globalStack.top();
                globalStack.pop();
                if(temp != NULL){
                    cout << temp->data;
                    localStack.push(temp->pLeftChild);
                    localStack.push(temp->pRightChild);

                    if(temp->pLeftChild != NULL || temp->pRightChild != NULL){
                        isRowEmpty = false;
                    }
                } else {
                    cout << "__";
                    localStack.push(NULL);
                    localStack.push(NULL);
                }
                for(int j = 0; j<nBlanks*2 - 2; j++){
                    cout << ' ';
                }
                cout << endl;
                nBlanks /= 2;
                while(localStack.empty()==false){
                    globalStack.push(localStack.top());
                    localStack.pop();
                }
            }
            cout << "..................................................................";
            cout << endl;

        }*/
    }

    void maximum() {
        Node *pCurrent, *pLast;
        pCurrent = pRoot;
        while(pCurrent != NULL){
            pLast = pCurrent;
            pCurrent = pCurrent->pRightChild;
        }
        cout << pLast->data << endl;
    }
};

int main() {
    Tree tree;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);

    Node *found = tree.find(25);
    if(found != NULL){
        cout << "Found the node with key 25" << endl;
    } else {
        cout << "Could not find node with key 25" << endl;
    }
    cout<<"tree inOrder():";
    tree.traverse(1);
    cout<<endl;
    tree.displayTree();
    cout<<"smallest value:";
    tree.minimum();
    cout <<"largest value:";
    tree.maximum();
    cout << "post order method: ";
    tree.traverse(2);
    cout << endl << "pre order method: ";
    tree.traverse(3);

}

/*
C:\Users\siddi\CLionProjects\p10p2\cmake-build-debug\p10p2.exe
Found the node with key 25 // Inserted 25, 50 and 75; then searched for 25
tree inOrder():25 50 75 // Tested traverse method (1)
.................................................................. // Tested display method
                                50
25


75


..................................................................
smallest value:25 //Tested min method
largest value:75 // Tested max method
post order method: 25 75 50 // Tested post order method via traverse method (2)
pre order method: 50 25 75 // Tested pre order method via traverse method(3)
Process finished with exit code 0

*/