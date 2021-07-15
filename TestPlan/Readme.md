# TEST PLAN:
## For High-Level
| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Status** |**Type Of Test**  |    
|:-------------:|:--------------------------------------------------------------:|:------------:|:-------------:|:----------------:|:------------------:|
|  H_01       |Maintaining the User Login credentials in .txt file |username and password  |.txt file has all user data  |Passed|Requirement Based|
|  H_02       |Maintaining product details in .dat file  |product class input|.dat has all product details|Passed |Requirement Based    |
|  H_03       |Printing the bill|User and Product class |generation of bill|Passed|Requirement Based    |
|  H_04       |Display of menu for user|Inputting the choice in product class  |Display of menu|Passed|Requirement Based    |
|  H_05       |Fetching the product details based on product id  |product id|Display of product details|Passed|Requirement Based |

## For Low-Level 

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|:-------------:|:--------------------------------------------------------------:|:------------:|:-------------:|:----------------:|:------------------:|
|  L_01       |Displaying the price list | Choosing the price list option in admin menu|Display of price list|Passed|Requirement based |
|  L_02       |Modifying the product available in .dat file|  product id |Printing "Record updated"| Passed|Requirement based    |
|  L_03       |Deleting product available in .dat file|product id|Delete product from .dat file|Passed|Requirement based    |
|  L_04       |Display of admin menu for various functions|option in integer format |Going to corresponding function|Passed|Requirement Based    |
|  L_05       |Modifying the poduct not availble in .dat file  |invalid product id|Printing "Record not found" |Passed|Scenario Based    |
|  L_06       |Invalid choice for admin menu  |inavlid choice in integer format| Printing "Invalid Choice"|Passed|Boundary Based    |
|  L_07       |Deleting invalid product from .dat file  |invalid product id|Printing "Record not found" |Passed|Scenario Based    |
|L_08|Creating new product|Valid product ID|Product is created|Passed|Requirement based|
|L_09|Creating new product|Invalid product ID|Incorrect product ID|Passed|Scenario based|
|L_10|Displaying specific product|Valid product ID|Product is created|Passed|Requirement based|
|L_11|Displaying specific product|Invalid product ID|Incorrect product ID|Passed|Scenario based|




