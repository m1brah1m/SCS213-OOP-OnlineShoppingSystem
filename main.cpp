#include <iostream>
#include <string>



using namespace std;



class Item{

    private:
        static int countOfItems;
        int ID_;  
        string name_;
        int quantity_;
        double price_;

    public:



        /* Constructors */
        Item ( );
        Item (string, int, double);
        Item (const Item&);
        /* Setters */
        void setName (string);
        void setQuantity (int);
        void setPrice (double);
        /* Getters */
        int getID ( );
        string getName ( );
        int getQuantity ( );
        double getPrice ( );
        /* Operators Overloading */
        bool operator== (const Item&);
        void operator+= (const Item&);
        void operator-= (const int);
        /*Stream Insertion and Extraction Operators Overloading*/
        friend ostream& operator<< (ostream& output, const Item& item);
        friend istream& operator>> (istream& input, Item& item);
        /*Friend Classes */
        friend class Seller;


};
int Item::countOfItems = 0;
                        /* Constructors */

/* Default Constructor:
    - Executed when an instance is created without a parameter list
    - Doesn't return any value
    What it does:
    - Increments the count of items
    - Assigns an ID to the item
    - Assigns default values to name,quantity and price of the item
*/
Item::Item ( ){
    countOfItems++;
    ID_ = countOfItems;
    name_ = "Item of ID " + to_string(ID_);
    quantity_ = 0;
    price_ = 0;

}

/* Parameterized Constructor:
    - Executed when an instance is created with a parameter list of order (string,int,double)
    - Doesn't return any value
    What it does:
    - Increments the count of items
    - Assigns an ID to the item
    - Assigns parameters' values to name,quantity and price of the item
*/
Item::Item (string name, int quantity, double price){
    countOfItems++;
    ID_ = countOfItems;
    name_ = name;
    quantity_ = quantity;
    price_ = price;
}

/* Copy Constructor:
    - Executed when an instance is created with a parameter being another instance of class Item
    - Doesn't return any value
    What it does:
    - Increments the count of items
    - Assigns an ID to the item
    - Assigns  parameter instance's values to name,quantity and price of the item
*/
Item::Item (const Item& item){
    countOfItems++;
    ID_ = countOfItems;
    name_ = item.name_;
    quantity_ = item.quantity_;
    price_ = item.price_;    
}

                        /* Setters */
/* void setName:
    - Sets the item's name to the value of the parameter string passed
    - Doesn't return any value
*/
void Item::setName (string name){
    name_ = name;
}

/* void setQuantity:
    - Sets the item's quantity to the value of the parameter integer passed
    - Doesn't return any value
*/
void Item::setQuantity (int quantity){
    quantity_ = quantity;
}

/* void setPrice:
    - Sets the item's price to the value of the parameter double passed
    - Doesn't return any value
*/
void Item::setPrice (double price){
    price_ = price;
}

                        /* Getters */

/* int getID:
    - Doesn't take any parameter
    - returns item's ID value;
*/                        
int Item::getID ( ){
    return ID_;
}

/* string getName:
    - Doesn't take any parameter
    - returns item's name value;
*/ 
string Item::getName ( ){
    return name_;
}

/* int getQuantity:
    - Doesn't take any parameter
    - returns item's quantity value;
*/  
int Item::getQuantity ( ){
    return quantity_;
}

/* double getPrice:
    - Doesn't take any parameter
    - returns item's price value;
*/ 
double Item::getPrice ( ){
    return price_;
}

                        /* Operators Overloading */

/* 
    Overloaded == :
        - Takes an item as a parameter(the one on the right) and compares its name with the item(the one on the left)
        - If they have the same name then they are equal and boolean (true) is returned
        - If they don't have the same name then they aren't equal and boolean (false) is returned
*/
bool Item::operator== (const Item& item){
    if(name_ == item.name_){
        return true;
    }else{
        return false;
    }
}

/* 
    Overloaded += :
        - Takes an item as a parameter(the one on the right) and adds the parameter's quantity to the quantity of the item(the one on the left)
        - Doesn't return any value
*/
void Item::operator+= (const Item& item){
    quantity_= quantity_ + item.quantity_;
}

/* 
    Overloaded -= :
        - Takes an integer(quantity) as a parameter and subtracts it from the quantity of the item(the one on the left)
        - Doesn't return any value
*/
void Item::operator-= (const int quantitySold){
    quantity_= quantity_ - quantitySold;
}

                        /*Stream Insertion and Extraction Operators Overloading*/

/* 
    Overloaded << (stream insertion operator) :
        - friend of Item class
        - Overloaded to print Item's objects
        - Takes two parameters an ostream object and an item
        - Appends to the ostream some customized messages (including item's members)
        - ostream object is returned
*/
ostream& operator<< (ostream& output, const Item& item){
    output << "Item ID: " << item.ID_ << endl;
    output << "Item Name: " << item.name_ << endl;
    output << "Item Quantity: " << item.quantity_ << endl;
    output << "Item Price: " << item.price_ << endl;

    return output;

}

/* 
    Overloaded >> (stream extraction operator) :
        - friend of Item class
        - Overloaded to print Item's objects
        - Takes two parameters an istream object and an item
        - Appends to the istream, the input of item's members (name,quantity,price)
        - istream object is returned
*/
istream& operator>> (istream& input, Item& item){
    cout << "Item Name: " << endl;
    input >> item.name_;
    cout << "Item Quantity: " << endl;
    input >> item.quantity_;
    cout << "Item Price: " << endl;
    input >> item.price_;
    return input;
}

class Seller
{
    private:
        string name_;
        string email_;
        int maxItems_;
        Item* items_;

    public:
        Seller(string,string,int);
        ~Seller();
        friend ostream& operator<< (ostream& output, const Seller& seller);
        bool addAnItem(const Item&);
        bool sellAnItem(string, int);
        
        

};

Seller::Seller(string name, string email, int maxItems)
{
    name_ = name;
    email_ = email;
    maxItems_= maxItems;
    items_ = new Item[maxItems];
}

Seller::~Seller()
{
    delete [] items_;
    items_ = 0;
}

ostream& operator<< (ostream& output, const Seller& seller)
{
    output << "Seller's Name: " << seller.name_ << endl;
    output << "Email: " << seller.email_ << endl;
    output << "Store Capacity: " << seller.maxItems_ << endl;

    return output;
}

bool Seller::addAnItem(const Item& item)
{
    bool isFound = false;
    int indexOfItem = -1;

    for (int i = 0; i < maxItems_; i++)
    {
        if (items_[i] == item)
        {
            isFound = true;
            indexOfItem = i;
        } 
        
    }

    if (isFound)
    {
        items_[indexOfItem] += item;
        return true;
    }

    else
    {
        for (int i = 0; i < maxItems_; i++)
        {
            if (items_[i].price_ == 0)
            {
                indexOfItem = i;
                break;
            }
        }

        if(indexOfItem == -1)
        {
            cout << "There are no empty entries in items." << endl;
            //cout << "Addition of this item failed." << endl;
            return false;
        }

        else
        {
            items_[indexOfItem].ID_ = item.ID_;
            items_[indexOfItem].name_ = item.name_;
            items_[indexOfItem].quantity_ = item.quantity_;
            items_[indexOfItem].price_ = item.price_;

            return true;
        }
        
    }
    
    return false;
}

bool Seller::sellAnItem(string itemName, int quantity)
{
    int indexOfItem = 0;
    bool isFound = false;

    for(int i = 0; i < maxItems_; i++)
    {
        if(items_[i].name_ == itemName)
        {
            isFound = true;
            indexOfItem = i;
        }
    }
    
    if(!isFound)
    {
        //cout << "Item is not found" << endl;
        return false;
    }

    else // main
    {
        if(quantity <= items_[indexOfItem].quantity_)
        {
            items_[indexOfItem].quantity_ -= quantity;
            return true;
        }
        else
        {
            //cout << "There is only " << items_[indexOfItem].quantity_ << "left for this item."
            return false;
        }
    }
}


int main( ){
    
    

    
   return 0; 
    
}