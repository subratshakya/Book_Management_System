# Book Shop Management System

## Description
This Book Shop Management System is a C++ program designed to handle various daily aspects of a book shop, meeting the requirements of both administrators and customers. It utilizes Object-Oriented Programming (OOP) concepts to manage a large amount of book data, track inventory, and calculate purchase and lending amounts.

## Features
- Secure admin access with password protection
- Book inventory management (add, modify, delete)
- Book information display
- Sales and lending calculation
- Data persistence using file handling

## Object-Oriented Concepts Used
- Data Encapsulation
- Modularity
- Reusability

## System Requirements

### Hardware
- Processor: Pentium III or higher
- RAM: 64 MB or more
- Hard Disk: 20 GB or more
- Printer (for document printing)
- Compact Drive

### Software
- Operating System: Windows XP (Note: May work on newer versions, but not tested)
- Compiler: Turbo C++

## Header Files Used
- `fstream.h`: File handling, cin and cout operations
- `conio.h`: Console input/output functions
- `process.h`: Process control functions
- `string.h`: String handling functions
- `iomanip.h`: I/O manipulators
- `stdio.h`: Standard input/output operations

## Main Class: Books

### Data Members
| Member     | Type   | Description                       |
|------------|--------|-----------------------------------|
| book_id    | float  | Unique identifier for each book   |
| price      | float  | Price of the book                 |
| copies     | int    | Number of copies available        |
| book_name  | char   | Name of the book                  |
| autr_name  | char   | Name of the author                |
| category   | char   | Category of the book              |
| c          | int    | Choice variable (yes/no)          |

### Member Functions
| Function           | Return Type | Description                                |
|--------------------|-------------|--------------------------------------------|
| get_book()         | void        | Input book details                         |
| disp_book()        | void        | Display book details                       |
| display_bookdata() | void        | Display book data                          |
| modify_copy(int)   | void        | Modify number of copies                    |
| modify_book()      | void        | Modify book details                        |
| retname()          | char        | Return book name                           |
| retid()            | int         | Return book ID                             |
| retprice()         | float       | Return book price                          |
| retcopy()          | int         | Return number of copies                    |

## How to Run
1. Ensure you have Turbo C++ installed on a Windows system.
2. Clone this repository or download the source code.
3. Open the project in Turbo C++.
4. Compile and run the program.

## Note
This project was originally designed for an older system configuration. For modern use, consider updating the development environment and potentially refactoring the code for compatibility with current C++ standards and practices.

## Contributing
Contributions to improve and modernize this project are welcome. Please feel free to fork the repository and submit pull requests.

## License
[MIT License]
