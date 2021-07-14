# Requirements

## Introduction
1. The objective of the “Supermarket Management System “is to produce  the monitoring the supermarket. 
2. The project SupermarketManagement System is developed with the objective of making the system reliable,easier, fast, and more informative
3. The admin can create a product,display all the products, display all the price list, Modify any product and can also delete any product.
4. The user can place the order of their interest with all the available products in the market.
4. The goal of this phase is to develop the internal logic of each of the modules identified during the system design.

## Features
The various features of the system are:
1. Easy to use
2. The user is allowed to
   -Create a product
   -Show a particular product
   -Display all the products
   -Display all the price list
   -Modify any product
   -Delete any product
3. End-to-end encrypted
4. Accessible from anywhere
5. Reduces time taken
6. Customer feedback is taken

## 4'Ws & 1'H
### WHO:
Shopkeeper who want to organize products in his/her supermarket. Customer who wants to buy products quickly.

### WHAT:
Supermarket management system helps shopkeeper to keep track of products,organize efficiently and supervise effectively.Hence he/she can give better service to the customer.

### WHEN:
When shopkeeper wants to make products available to customers without any delay.

### WHERE:
Can be used where products status in the supermarket/store changes frequently.

### HOW:
Supermarket management system provides multiple options to the shopkeeper such as add new product, view all products or specific product,modify any product,delete any product. Based on these details customer/shopkeeper can find product details accurately.

## SWOT ANALYSIS

![SWOT ANALYSIS](https://github.com/99004440-Arvindan/EMBEDDED_MINI_PROJECT/blob/main/Requirements/SWOT.PNG)

## High Level Requirements

|      ID          |Description                          |Status                         |
|----------------|-------------------------------|-----------------------------|
|H1|User class with required features    |Implemented            |
|H2|Customer class with required features   |Implemented|
|H3|File handling of User login details  |Implemented|
|H4| Product class with required features inherits from User class| Implemented|
|H5|Transactions/Billing using class Bill which inherits from Customer and Product class|Implemented|
|H6| Display of the menu and working of all the features                 |Implemented|

## Low Level Requirements

|      ID          |Description                          |Status                         |
|----------------|-------------------------------|-----------------------------|
|H1_L1|  User has own username and password maintained in the .txt file     |Implemented            |
|H1_L2| Adding User function in User class           |Implemented|
|H1_L3|  Verifying User function in User class           |Implemented|
|H2_L1|  Reading the customer details Customer class           |Implemented            |
|H2_L2| Displaying Customer details function in Customer class                  |Implemented|
|H3_L1|  Maintain the user.txt file     |Implemented            |
|H4_L1| Creating Product function in Product class        |Implemented|
|H4_L2|  Showing the Product function in Product class|Implemented|
|H4_L3|  Displaying all Product details function in Product class          |Implemented            |
|H4_L4| Displaying specific Product details function in Product class            |Implemented|
|H4_L5|  Price list of Product function in Product class     |Implemented            |
|H4_L6| Modify Product function in Product class           |Implemented|
|H4_L7| Admin menu function in Product class           |Implemented|
|H4_L8|  Deleting Product function in Product class|Implemented            |
|H5_L1| Placing order function in class Bill                |Implemented|
