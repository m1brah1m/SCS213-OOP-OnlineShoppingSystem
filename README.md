# SCS213-OOP-OnlineShoppingSystem
## Class "Item"
### Class Attributes:
#### Private:
- [ ] ID (not set by user)
- [ ] name
- [ ] quantity
- [ ] price

### Class Methods:
#### Public:
- [ ] Default Constructor
- [ ] Parameterized Constructor
- [ ] Copy Constructor
- [ ] Setters
- [ ] Getters
- Operator Overloading
- [ ] ==
- [ ] +=
- [ ] -=
- [ ] << (stream insertion operator)
- [ ] >> (stream extraction operator)

---
## Class "Seller"
### Class Attributes:
#### Private:
- [ ] name
- [ ] email
- [ ] items (dynamic array of objects of type **Item** with the size maxItems)
- [ ] maxItems
### Class Methods:
#### Public:
- [ ] Parameterized Constructor
- [ ] Destructor
- Operator Overloading
- [ ] << (stream insertion operator)
- *Add An Item*
- [ ] Takes an **Item** object as a parameter
- [ ] Function Body
  - (Use Operator == where an item is equal to another If They have the same name)
  - If the item exists Increase the item’s quantity by the quantity of the parameter item using the (+=) of **Item** class
  - And the price of the parameter object will be ignored
  - **Else :**
  - You will add it to the seller's items
  - **Return (boolean) :**
  - true if item addition was successful (If there is a place in the array)
  - false otherwise

- *Sell An Item*
- [ ] Takes item name and quantity as parameters
- [ ] If the parameter quantity <= item's quantity then decrease it from item using the (-=) of **Item** class
  - **Else :** (parameter quantity more than that of the item)
  - Print " There is only {item's quantity} left for this item "
  - **Return (boolean):**
  - true if the item was found
  - false otherwise
  
- *Print Items*
- [ ] Print all the item info for the seller (print each item using << of **Item** class)

- *Find an Item by ID*
- [ ] This returns an Item object (or a pointer to Item) with the specified ID if there is an item with such ID. 

---

## Main Function
- [ ] Ask Seller to input his detalis (seller's info)
- [ ] Ask Seller for his store capacity (maxNumberOfItems)
-  Menu To Choose from:
- [ ] 1) Print My info (print seller's info using << of **Seller* class)
- [ ] 2) Add an Item
- [ ] 3) Sell an Item
- [ ] 4) Print Items
- [ ] 5) Find an Item by ID
- [ ] 6) Exit



