/*
    Authors: Mostafa Ibrahim , Youssef Emam
*/

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
        /*Static member function to get countOfItems*/
        static int getCountOfItems();


};
/*Static member variable that holds the count of items and a static member function that returns the count value*/
int Item::countOfItems = 0;
int Item::getCountOfItems(){
    return countOfItems;
}
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
        void printItems();
        Item* findAnItemById(int);
        
        

};
/* Constructors */

/* Parameterized Constructor:
    - Doesn't return any valueb
    What it does:
    - Assings parameters' values to name, email, maxItems
    - Allocate memory for the dynamically allocated array items_
*/
Seller::Seller(string name, string email, int maxItems)
{
    name_ = name;
    email_ = email;
    maxItems_= maxItems;
    items_ = new Item[maxItems];
}

/* Destrucor:
    - Executed at program's termination
    - Doesn't return any value
    What it does:
    - Deallocates memory of the dynamic array items
    - Sets pointer items_ to 0
*/
Seller::~Seller()
{
    delete [] items_;
    items_ = 0;
}

/* 
    Overloaded << (stream insertion operator) :
        - friend of Item class
        - Overloaded to print Seller's info
        - Takes two parameters an ostream object and seller
        - Appends to the ostream some customized messages with the seller's members
        - ostream object is returned
*/
ostream& operator<< (ostream& output, const Seller& seller)
{
    output << "\nSeller's Name: " << seller.name_ << endl;
    output << "Email: " << seller.email_ << endl;
    output << "Store Capacity: " << seller.maxItems_ << endl;

    return output;
}

/*
    bool addAnItem:
        - Takes an item as a parameter
        - Searches for the entered item
        - If the items was found, the quantity is increased by 1 and returns true
        - If it was not found a new entry is added and returns true
        - Returns false otherwise
*/
bool Seller::addAnItem(const Item& item)
{
    bool isFound;

    // indexOfItem is set to -1 to avoid false detection of index 0 in the array
    int indexOfItem = -1;

    isFound = false;
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

        // Checking if the item is not found 
        if(indexOfItem == -1)
        {
            cout << "There are no empty entries in items." << endl;
            return false;
        }

        else
        {
            //Changing the count of items to its correct value again, due to duplication occured because of creation of the instance that is passed to the function
            Item::countOfItems=Item::countOfItems-1;

            items_[indexOfItem].name_ = item.name_;
            items_[indexOfItem].quantity_ = item.quantity_;
            items_[indexOfItem].price_ = item.price_;

            return true;
        }
        
    }
    
    return false;
}

/*
    bool sellAnItem:
        - Takes an item and int quantity as parameters
        - Checks for the entered item
        - If the item was found and the quantity wanted is smaller than the available, function returns true
        - If item is not found or the quantity wanted is larger than the available, the function returns false
        
*/
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
        
        return false;
    }

    else // main
    {
        if(quantity <= items_[indexOfItem].quantity_)
        {
            items_[indexOfItem].quantity_ -= quantity;
            return true;
        }
        else if (items_[indexOfItem].quantity_ !=0)
        {
            cout << "There is only " << items_[indexOfItem].quantity_ << " left for this item." << endl;
            return false;
        }
        else
        {
            cout << "This item is sold out." << endl;
            return false;
        }
    }
}

/*
    void printItems:
        - Doesn't take any parameters
        - Prints all non empty entries in items_ array
        - Checks if an item is empty by comparing the price of the item to 0
        - Doesn't return any value
*/
void Seller::printItems()
{
    cout<<name_<<"'s Items :"<<endl;

    for(int i = 0; i < maxItems_; i++)
    {   
        if (items_[i].price_ != 0)
        {
            cout<<"-Item "<<i+1<<" :"<<endl;
            cout<<items_[i];
            cout << endl;
        }
    
        
    }
}

/*
    Item* findAnItemById
        - Takes an int as a parameter
        - Returns a pointer to the item with the same ID  
*/
Item* Seller::findAnItemById(int id){
    if (id >= 1 && id <= Item::countOfItems)
    {
        return &items_[id-1];
    }
    
    else 
    {
        return 0;
    }
    
}

/*
    void checkinput:
        - Takes a referenced int as a parameter
        - Doesn't return any value
        - Checks if input is an integer and is a positive number
*/
void checkInput(int& input)
{
    // A goto statement to be executed when the user inputs a letter then a number
    inputIsNumeric:

    // while (cin): checks if the input is the required type, returns false if the user entered a differnet type, true otherwise
    while (cin && input <= 0)    
    {   

        cout << "Please enter a positive number." << endl;

        cout << "Input: ";
        cin >> input;

        // Loop breaks if the input is a non-integer
        if(!cin)
        {
            break;
        }
    }

    while(!cin)
    {
        cin.clear();
        cin.ignore(10,'\n');

        cout << "Please enter a number." << endl;

        cout << "Input: ";
        cin >> input;

        // goto inputIsNumeric if the user enters an integer
        if(cin)
        {
            goto inputIsNumeric;
        }
    }
}

/*
    void checkPrice:
        - Takes a referenced double as a parameter
        - Doesn't return any value
        - Checks if input is a double and is a positive number
        - Uses same logic as checkInput() function
*/
void checkPrice(double& input)
{
    // A goto statement to be executed when the user inputs a letter then a number
    inputIsNumeric:
    while (cin && input <= 0)    
    {   

        cout << "Please enter a positive number." << endl;

        cout << "Input: ";
        cin >> input;

        // Loop breaks if the input is not double
        if(!cin)
        {
            break;
        }
    }

    while(!cin)
    {
        cin.clear();
        cin.ignore(10,'\n');

        cout << "Please enter a number." << endl;

        cout << "Input: ";
        cin >> input;

        // goto inputIsNumeric if the user enters a double
        if(cin)
        {
            goto inputIsNumeric;
        }
    }
}



int main()
{   
    
    string name, email;
    int maxItems,occupiedSlots;
    occupiedSlots=0;
    bool isProgramRunning;

    cout<<"\nSeller's name: ";
    getline(cin, name); 

    cout<<"Seller's email: ";
    getline(cin, email);

    cout<<"Store Capacity: ";
    cin>>maxItems;
    
    // Using custom function to validate input
    checkInput(maxItems);

    Seller seller(name, email, maxItems);
    
    string menuDisplayChoice;
    string horizontalLine(90,'_');//This is used just to separate outputs in the console (after each iteration)
    int loopCount;

    loopCount=0; 
    isProgramRunning = true;      
    while (isProgramRunning)
    {
        if(loopCount != 0)
        {
            cout<<"\n\nDo you want the choice menu to be displayed again? (y/n)     Note: y for yes and n for no\n"
            "Enter (y/n): ";

            cin>>menuDisplayChoice;
            cout<<"\n";

            while(menuDisplayChoice != "y" && menuDisplayChoice != "Y" && menuDisplayChoice != "n" && menuDisplayChoice != "N")
            {
                cout<<"\nInvalid Choice.\n"
                "Enter (y/n): ";
                cin>>menuDisplayChoice;
            }

            cout<<horizontalLine<<endl;
            cout<<"\n";
        }
        
        if(loopCount == 0 || menuDisplayChoice == "y" || menuDisplayChoice == "Y")
        {
            cout<<
            "\n"
            "Choose from this menu: \n"
            "1) Print My Info\n"
            "2) Add An Item\n"
            "3) Sell An Item\n"
            "4) Print Items\n"
            "5) Find an Item by ID\n"
            "6) Exit\n";
        }

        int choice;

        cout<<"Choice: ";
        cin>>choice;
        
        cout << endl;

    
         checkInput(choice);

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
        {
            cout << "Invalid Choice!" << endl;
        }

            
            
        
        

        switch (choice)
        {
            // Prints seller's info
            case 1:
            {
                cout << seller;
                break;
            }

            // Adds an item
            case 2:
            {

                string itemName;

                int itemQuantity;
                double itemPrice; // double??

                bool isExecutedCorrectly = false;
                
               /* if(occupiedSlots == maxItems)
                {
                    cout<<"Store reached its maximum capacity."<<endl;
                    break;
                }*/

                cin.clear();
                cin.ignore(10,'\n');

                cout << "Enter Item Name: ";
                getline(cin, itemName);

                cout << "Enter Item Quantity: ";
                cin >> itemQuantity;

                // Calling function to validate the input
                checkInput(itemQuantity);
            
                cout << "Enter Item Price: ";
                cin >> itemPrice;

                // Calling function to validate the input
                checkPrice(itemPrice);
                
                Item newItem(itemName, itemQuantity, itemPrice);

                isExecutedCorrectly = seller.addAnItem(newItem);

                if(!isExecutedCorrectly)
                {
                    cout << "Process not executed correctly." << endl;
                    cout << "Please try again." << endl;
                
                }
                else if (isExecutedCorrectly)
                {
                    cout << "The item was added successfully." << endl;
                }
                
                occupiedSlots++;
                break;
            }
            // Sell an item
            case 3: 
            {
                string itemName;
                int itemQuantity;
                bool isExecutedCorrectly = false;

                if (occupiedSlots == 0)
                {
                    cout << "Store is empty." << endl;
                    break;
                }
                
                cin.clear();
                cin.ignore(10,'\n');
                cout << "Enter Item Name: ";
                getline(cin, itemName);

                cout << "Enter Item Quantity: ";
                cin >> itemQuantity;

                checkInput(itemQuantity);

                isExecutedCorrectly = seller.sellAnItem(itemName, itemQuantity);

                if(!isExecutedCorrectly)
                {
                    cout << "Process not executed correctly." << endl;
                    cout << "Please try again." << endl;
                
                }
                else
                {
                    cout << "The process was completed successfully." << endl;
                }
                break;
            }

            // Print items
            case 4: 
            {
                if (occupiedSlots == 0)
                {
                    cout << "Store is empty." << endl;
                    break;
                }
                else
                {
                    seller.printItems();
                    break;
                }
                
            }

            // Search for an item with it's ID
            case 5: 
            {   
                int id;

                if (occupiedSlots == 0)
                {
                    cout << "Store is empty." << endl;
                    break;
                }
                
                cout << "Enter ID of the required Item: " ;
                cin >> id;

                checkInput(id);

                if(id>Item::getCountOfItems())
                {
                    cout<<"ID not found.\n"
                        << "Please enter a valid ID and try again." << endl;
                    break;
                }

                else
                {
                    cout << (*seller.findAnItemById(id));
                }
                
                break;
            }
               
            case 6:
            {   
                cout<<"Exit!"<<endl;
                isProgramRunning = false;
                
                break;
            }
            
            
        }
        
        cout<<horizontalLine<<endl;
        loopCount++;

        }
    

     
    
    
    return 0;
}
