#include <iostream>
using namespace std;

class Item {
private:
    string name;
    double cost;
public:
    Item() {
        name = "";
        cost = 0.0;
    }

    Item(string newName, double newCost) {
        name = newName;
        cost = newCost;
    }

    void show() {
        cout << "-" << name << " $" << cost << endl;
    }

    string get_name() {
        return name;
    }

    double get_cost() {
        return cost;
    }

    void set_item(string newName, double newCost) {
        name = newName;
        cost = newCost;
    }

    void setItem(Item item) {
        name = item.get_name();
        cost = item.get_cost();
    }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Bag{
    private:
        Item *items;
        int number_items;
        int max;

    public:
        Bag(int Max){
            items = new Item[Max]; // an array of items
            number_items = 0; // this is the index of current item
            max = Max; // size of the bag/array
        }

        void insert_item(string name, double cost){
            items[number_items].set_item(name,cost);
            number_items++;
        }

        void insertItem(Item item){
            //items[number_items].set_item( item.get_name(), item.get_cost() );
            items[number_items].setItem(item);
            number_items++;
        }

        int size() {
            return max;
        }

        void showItems(){
            //shift all the elements one to the left
            for(int i = 0; i < max-1; i++){
                items[i].show();
            }
            // Removed "number_items--; //resize bag", it reduced the
            //size of the array by one each time "showItems" was called
        }

        void delete_first(){
            // shift all the elements one to the left
            for(int i = 0; i < max-1; i++){
                items[i] = items[i+1];
            }
            number_items--;// resize bag
        }

        bool contains (string name_to_find){
            for(int i = 0; i < number_items; i++){
                if(name_to_find == items[i].get_name()){
                    return true;
                }
                //Moved "return false;" outside of the loop
            }

            return false;
        }

        void sort_by_cost_acending(){// bubble sort
            for(int i = 0; i < number_items-1; i++){
                for(int j = 0; j < number_items-1; j++){
                    if(items[j].get_cost() > items[j+1].get_cost()){
                        swap(j,j+1);
                    }
                }
            }
        }

        void swap(int index1, int index2){
            Item temp = items[index1];
            items[index1] = items[index2];
            items[index2] = temp;
        }

        void most_expensive(){
            int index = 0;
            int price = items[0].get_cost();
            for(int i = 1; i < number_items -1; i++){
                if(price < items[i].get_cost()){
                    price = items[i].get_cost();
                    index = i;
                }
            }
            cout<<"Most expensive fruit is "<<items[index].get_name()<<endl;
        }

        void show_reverse(){
            int size = number_items;
            for(int i = size; i >= 0; i--){
                cout<<"-"<<items[i].get_name()<<" $"<<items[i].get_cost()<<endl;
            }
        }

        void get_frequency(Item item){
            int counter = 0;
            for(int i = 0; i<number_items; i++){
                if(item.get_name() == items[i].get_name()){
                    counter++;
                }
            }
            cout<<item.get_name()<<" appeared "<<counter<<" times";
        }

        Item converter(string name){
            int i;
            for(i = 0; i < number_items; i++){
                if(name == items[i].get_name()){
                    break;
                }
            }
                return items[i];
        }

        bool deleteItem(Item item){
            bool found = false;
            int i;
            for(i = 0; i<number_items; i++){
                if(item.get_name() == items[i].get_name()){
                    found = true;
                    break;
                }
            }

            for(int j = i; j < max-1; j++){
                items[j] = items[j+1];
            }
            number_items--;// resize bag

            if(found == true){
                return true;
            } else {
                return false;
            }

        }

        int get_index_of(Item item){
            int i;
            int number_found = 0;
            for(i = 0; i < max; i++){
                if(item.get_name() == items[i].get_name()){
                    number_found = 1;
                    break;
                }
            }
            if(number_found == 1){
                return i;
            } else {
                return -9999;
            }

        }

        double sum_of_all(){
            double sum = 0;
            for(int i = 0; i<max; i++){
                sum+=items[i].get_cost();
            }
            return sum;
        }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    /// Test to see if Item works
    cout << "Testing Item: ";
    Item anItem("Fuji Apple", 4.99);
    anItem.show();
    /// Test to see if Bag works
    cout << endl;
    Bag x(5);
    x.insert_item("Taro", 0.99);
    x.insert_item("Banana", 1.50);
    x.insert_item("Orange", 2);
    x.insert_item("Kiwi", 1.75);
    x.showItems();
    cout << endl;
    x.delete_first();
    x.showItems();
    cout << endl;
    string found;
    if(x.contains("Orange")){
        found = "true";
    } else {
        found = "false";
    }
    cout << "Name found: " << found << endl;
    cout<<endl;
    x.sort_by_cost_acending();
    x.showItems();
    cout<<endl;
    x.swap(0,2);
    x.showItems();
    cout<<endl;
    x.most_expensive();
    cout<<endl;
    x.show_reverse();
    cout<<endl;
    x.get_frequency(x.converter("Orange"));
    cout<<endl;
    int deleted = x.deleteItem(x.converter("Orange"));
    if(deleted == 1){
        cout<<"Deleted: true"<<endl;
    } else {
        cout<<"Deleted: false"<<endl;
    }
    x.showItems();
    cout<<endl;
    int searchIndex = x.get_index_of(x.converter("Kiwi"));
    if(searchIndex != 9999){
        cout<<"Index: "<<searchIndex<<endl;
    } else {
        cout<<"Item not found"<<endl;
    }
    cout<<endl;
    double totalSum = x.sum_of_all();
    cout<<totalSum<<endl;
    cout<<endl;

}

/*
C:\Users\siddi\CLionProjects\p4\cmake-build-debug\p4.exe
Testing Item: -Fuji Apple $4.99
//TESTED INSERT_ITEM FUNCTION; ADDED 0.Taro 1.Banana 2.Orange 3.Kiwi
-Taro $0.99
-Banana $1.5
-Orange $2
-Kiwi $1.75
//TESTED DELETE_FIRST FUNCTION; DELETED TARO
-Banana $1.5
-Orange $2
-Kiwi $1.75
- $0
//TESTED CONTAINS FUNCTION; FOUND ORANGE IN LIST
Name found: true
//TESTED SORT_COST_BY_ACSENDING FUNCTION; *NOTE* NO VALUE WAS STORED AT INDEX OF 3
-Banana $1.5
-Kiwi $1.75
-Orange $2
- $0
//TESTED SWAP FUNCTION; SWAPPED BANANA AND ORANGE AND PRINTED BUT MADE NO CHANGE IN THE ACTUAL LIST
-Orange $2
-Kiwi $1.75
-Banana $1.5
- $0
//TESTED MOST_EXPENSIVE FUNCTION
Most expensive fruit is Orange
//TESTED REVERSE FUNCTION
- $0
-Banana $1.5
-Kiwi $1.75
-Orange $2
//TESTED GET_FREQUENCY FUNCTION; SEARCHED FOR ORANGE
Orange appeared 1 times
//TESTED DELETEITEM FUNCTION; DELETED ORANGE
Deleted: true
-Kiwi $1.75
-Banana $1.5
- $0
- $0
//TESTED GET_INDEX_OF FUNCTION; GOT INDEX OF KIWI
Index: 0
//TESTED SUM_OF_ALL FUNCTION; 
3.25


Process finished with exit code 0

*/