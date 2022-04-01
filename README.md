# CSVSorter

This project can sort a CSV file in numerous ways. You have to provide the file name, the name of the column, whether you want it sorted ascending or descending, and whether it is a numeric type, string type, or date type.

## How to run:

1. Clone this repository 
2. Go to the directory that you want this program in and type "git clone " followed by the "HTTPS" link you can find from the "Code" button
3. Enter the "CSVSorter" folder using ```cd CSVSorter```
4. Compile using this command: ```g++ -o Sorter compareFunctions.cpp convert1Dto2D.cpp getInfo.cpp HeaderRow.cpp init.cpp main.cpp```
5. In terminal, type: ```./Sorter.exe``` with command line arguments(which I will explain later)
### Alternatively:
1. Download the files of this repository by zipping it, and then open that folder through file explorer
2. If you are on a linux based shell: ```g++ -o Sorter compareFunctions.cpp convert1Dto2D.cpp getInfo.cpp HeaderRow.cpp init.cpp main.cpp``` should compile and ```./Sorter.exe```(with command line arguments) should run it
3. If you are on windows: ```gcc compareFunctions.cpp convert1Dto2D.cpp getInfo.cpp HeaderRow.cpp init.cpp main.cpp -o Sorter.exe``` should compile and ```Sorter.exe```(with command line arguments) should run it


## Running with command line arguments

Sorter.exe ```file name``` ```Column name``` ```Order``` ```Type```

After compiling, this is the order of the command line arguments you need to provide:
* ```file name```
  - The path to your CSV File
  - Example: C:\Users\Bob\Desktop\Employees.csv
* ```Column name```
  - The name of the column you want sorted in your CSV File
  - Example: Age
* ```Order```
  - Whether you want the column sorted in ascending or descending order
  - Possible options: A or D
    - A represents Ascending and D represents Descending
* ```Type```
  - What type of data your column stores
  - Possible options: N, S, or D
    - N represents numeric, S represents strings(words), and D represents dates

Finally, a full example:
```Sorter.exe C:\Users\Bob\Desktop\Employees.csv Age A N```

If you are using an excel file, make sure to save it as a csv!

## How it works

* Different elements can be accessed by finding commas since the input file is a CSV 
* Once all the data is stored, it is a matter of sorting the single column
  - Quicksort is used to sort the specific column]
* Then the code rewrites the file, modifying it to the desired outcome
