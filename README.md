# C++ Personal Finance Manager

This is a comprehensive, menu-driven console application built in C++ for managing personal finances. It allows users to track expenses across multiple wallets and bank cards, and generate a wide variety of detailed reports to analyze spending habits.

## About The Project

This project is a powerful demonstration of Object-Oriented Programming (OOP) and data management in C++. It effectively uses C++ Standard Library containers and algorithms to provide complex functionality in a structured and organized way. It is an excellent example of a real-world application built as a console program.

### Concepts and Features Demonstrated

*   **Object-Oriented Design**: The application is built around well-defined classes (`FinancialManager`, `Wallet`, `Card`, `Transaction`) that encapsulate data and functionality.
*   **STL Containers**: Makes extensive use of `std::vector` to manage collections of wallets, cards, and transactions, and `std::map` to aggregate data for reports.
*   **The `<algorithm>` Library**: Uses `std::sort` with a custom lambda function to rank expenses and categories for "Top 3" reports.
*   **The `<iomanip>` Library**: Uses `std::setw` and `std::left` for creating clean, well-formatted, table-like reports in the console.
*   **File I/O (`<fstream>`)**: Includes functionality to save generated reports to an external text file.
*   **Data Aggregation and Reporting**: A core feature of the application is its ability to process a list of transactions and generate meaningful insights, such as expenses per category.
*   **Interactive Menu**: Provides a user-friendly, menu-driven interface for easy interaction.

## Core Functionality

The application allows a user to:
1.  **Create and Manage Wallets and Cards**: Add multiple cash wallets or bank cards (Debit/Credit).
2.  **Log Transactions**: Add expense transactions, specifying the amount, category, and date (`YYYY-MM-DD`).
3.  **Generate Rich Reports**:
    *   **Overall Expense Report**: A summary of total spending broken down by category.
    *   **Time-Based Reports**: Generate reports for specific days, weeks, or months.
    *   **Top Spenders Analysis**: Generate reports showing the "Top 3" spending categories or highest expense categories for a given week or month.
4.  **Save Reports**: Export a generated report for a wallet to a text file.

## How to Build and Run

You will need a C++ compiler that supports C++11 or newer (for range-based for loops, lambda functions, etc.).

1.  **Save the Code**: Save the source code of `newbank.cpp` as `main.cpp` or another preferred name.
2.  **Compile the Project**: Open a terminal or command prompt in the directory where you saved the file and compile it:
    ```sh
    g++ main.cpp -o finance_manager_app -std=c++11
    ```
3.  **Run the Application**:
    ```sh
    ./finance_manager_app
    ```
    On Windows:
    ```cmd
    finance_manager_app.exe
    ```

## Example Usage

The program will greet you with a main menu. You can then proceed to add a wallet, add some transactions, and generate reports.

**Sample Session:**

1.  **Choose `1. Add Wallet`**:
    *   Enter name: `MyCash`
2.  **Choose `3. Add Transaction to Wallet`**:
    *   Enter wallet index: `0`
    *   Enter amount: `15.50`
    *   Enter category: `Groceries`
    *   Enter date: `2024-10-26`
3.  **Choose `3. Add Transaction to Wallet`** again:
    *   Enter wallet index: `0`
    *   Enter amount: `40.00`
    *   Enter category: `Gas`
    *   Enter date: `2024-10-27`
4.  **Choose `5. Generate Report for Wallet`**:
    *   Enter wallet index: `0`

**Expected Report Output:**
```
Report for the period:
-----------------------------------------
Category                Amount
-----------------------------------------
Gas                     40
Groceries               15.5
-----------------------------------------
```
```
