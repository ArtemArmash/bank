#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <iomanip>
#include <algorithm>


using namespace std;


class Transaction {
private:
    double amount;
    string category;
    string date;

public:
    Transaction(double amount, string category, string date) : amount{ amount }, category{ category }, date{ date } {}
    double getAmount() {
        return amount;
    }

    string getCategory() {
        return category;
    }

    string getDate() {
        return date;
    }
};

class Wallet {
private:
    string name;
    double balance;
    vector<Transaction> transactions;

public:
    Wallet(string name) : name{ name }, balance{ 0.0 } {}
    Wallet(string name, double balance, vector<Transaction>& transactions) : name{ name }, balance{ balance }, transactions{ transactions } {}
    vector<Transaction> getTrans() {
        return transactions;
    }
    void AddTrans(Transaction& trans) {
        transactions.push_back(trans);
    }
    double GetBal() {
        return balance;
    }
    
    void spend(double amount,  string& category,  string& date) {
        balance -= amount;
        Transaction transaction(amount, category, date);
        transactions.push_back(transaction);
    }
    void GenerateReport(vector<Transaction>& transactions) {
        map<string, double> categoryExpenses;
        for (auto& transaction : transactions) {
            categoryExpenses[transaction.getCategory()] += transaction.getAmount();
        }
        cout << "Report for the period:" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Category\t\tAmount" << endl;
        cout << "-----------------------------------------" << endl;
        for (auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }
        cout << "-----------------------------------------" << endl;
    }
    void GenerateDailyReport(const string& date) {
        double totalExpenses = 0.0;
        map<string, double> categoryExpenses;

        cout << "Daily report for " << date << ":\n";
        cout << "-----------------------------------------\n";
        cout << "Category\t\tAmount\n";
        cout << "-----------------------------------------\n";

        for (auto& trans : transactions) {
            if (trans.getDate() == date) {
                totalExpenses += trans.getAmount();
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        for (const auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }

        cout << "-----------------------------------------\n";
        cout << "Total expenses: " << totalExpenses << endl;
        cout << "-----------------------------------------\n";
    }

    void GenerateWeeklyReport(const string& startDate, const string& endDate) {
        double totalExpenses = 0.0;
        map<string, double> categoryExpenses;

        cout << "Weekly report from " << startDate << ":\n";
        cout << "-----------------------------------------\n";
        cout << "Category\t\tAmount\n";
        cout << "-----------------------------------------\n";

        for (auto& trans : transactions) {
            if (trans.getDate() >= startDate && trans.getDate() <= endDate) {
                totalExpenses += trans.getAmount();
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        for (const auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }

        cout << "-----------------------------------------\n";
        cout << "Total expenses: " << totalExpenses << endl;
        cout << "-----------------------------------------\n";
    }

    void GenerateMonthlyReport(const string& month) {
        double totalExpenses = 0.0;
        map<string, double> categoryExpenses;

        cout << "Monthly report for " << month << ":\n";
        cout << "-----------------------------------------\n";
        cout << "Category\t\tAmount\n";
        cout << "-----------------------------------------\n";

        for (auto& trans : transactions) {
            if (trans.getDate().substr(0, 7) == month) {
                totalExpenses += trans.getAmount();
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        for (auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }

        cout << "-----------------------------------------\n";
        cout << "Total expenses: " << totalExpenses << endl;
        cout << "-----------------------------------------\n";
    }

    void GenerateTopExpensesWeekly(const string& startDate, const string& endDate) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate() >= startDate) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedExpenses(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedExpenses.begin(), sortedExpenses.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 expenses for the week starting from " << startDate << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedExpenses.size()); ++i) {
            cout << setw(20) << left << sortedExpenses[i].first << "\t" << sortedExpenses[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }

    void GenerateTopCategoriesWeekly(const string& startDate, const string& endDate) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate() >= startDate) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedCategories(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedCategories.begin(), sortedCategories.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 categories for the week starting from " << startDate << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedCategories.size()); ++i) {
            cout << setw(20) << left << sortedCategories[i].first << "\t" << sortedCategories[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }

    void GenerateTopExpensesMonthly(const string& month) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate().substr(0, 7) == month) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedExpenses(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedExpenses.begin(), sortedExpenses.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 expenses for " << month << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedExpenses.size()); ++i) {
            cout << setw(20) << left << sortedExpenses[i].first << "\t" << sortedExpenses[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }

    void GenerateTopCategoriesMonthly(const string& month) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate().substr(0, 7) == month) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedCategories(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedCategories.begin(), sortedCategories.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 categories for " << month << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedCategories.size()); ++i) {
            cout << setw(20) << left << sortedCategories[i].first << "\t" << sortedCategories[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }
};

class Card {
private:
    string type;
    double balance;
    vector<Transaction> transactions;

public:
    Card(string type) : type{ type }, balance{ 0.0 } {}
    Card(string type, double balance, vector<Transaction>& transactions) : type{ type }, balance{ balance }, transactions{ transactions } {}
    vector<Transaction> getTrans() {
        return transactions;
    }
    void AddTrans(Transaction& trans) {
        transactions.push_back(trans);
    }
    double GetBal() {
        return balance;
    }
   
    void spend(double amount, string& category, string& date) {
        balance -= amount;
        Transaction transaction(amount, category, date);
        transactions.push_back(transaction);
    }

    void GenerateReport(vector<Transaction>& transactions) {
        map<string, double> categoryExpenses;
        for (auto& transaction : transactions) {
            categoryExpenses[transaction.getCategory()] += transaction.getAmount();
        }
        cout << "Report for " << type << " card for the period:" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Category\t\tAmount" << endl;
        cout << "-----------------------------------------" << endl;
        for (auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }
        cout << "-----------------------------------------" << endl;
    }
    void GenerateDailyReport(const string& date) {
        double totalExpenses = 0.0;
        map<string, double> categoryExpenses;

        cout << "Daily report for " << date << ":\n";
        cout << "-----------------------------------------\n";
        cout << "Category\t\tAmount\n";
        cout << "-----------------------------------------\n";

        for (auto& trans : transactions) {
            if (trans.getDate() == date) {
                totalExpenses += trans.getAmount();
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        for (const auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }

        cout << "-----------------------------------------\n";
        cout << "Total expenses: " << totalExpenses << endl;
        cout << "-----------------------------------------\n";
    }

    void GenerateWeeklyReport(const string& startDate, const string& endDate) {
        double totalExpenses = 0.0;
        map<string, double> categoryExpenses;

        cout << "Weekly report from " << startDate << ":\n";
        cout << "-----------------------------------------\n";
        cout << "Category\t\tAmount\n";
        cout << "-----------------------------------------\n";

        for (auto& trans : transactions) {
            if (trans.getDate() >= startDate && trans.getDate() <= endDate) {
                totalExpenses += trans.getAmount();
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        for (auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }

        cout << "-----------------------------------------\n";
        cout << "Total expenses: " << totalExpenses << endl;
        cout << "-----------------------------------------\n";
    }

    void GenerateMonthlyReport(const string& month) {
        double totalExpenses = 0.0;
        map<string, double> categoryExpenses;

        cout << "Monthly report for " << month << ":\n";
        cout << "-----------------------------------------\n";
        cout << "Category\t\tAmount\n";
        cout << "-----------------------------------------\n";

        for (auto& trans : transactions) {
            if (trans.getDate().substr(0, 7) == month) {
                totalExpenses += trans.getAmount();
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        for (const auto& pair : categoryExpenses) {
            cout << setw(20) << left << pair.first << "\t" << pair.second << endl;
        }

        cout << "-----------------------------------------\n";
        cout << "Total expenses: " << totalExpenses << endl;
        cout << "-----------------------------------------\n";
    }

    void GenerateTopExpensesWeekly(const string& startDate) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate() >= startDate) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedExpenses(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedExpenses.begin(), sortedExpenses.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 expenses for the week starting from " << startDate << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedExpenses.size()); ++i) {
            cout << setw(20) << left << sortedExpenses[i].first << "\t" << sortedExpenses[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }
    void GenerateTopCategoriesWeekly(const string& startDate) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate() >= startDate) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedCategories(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedCategories.begin(), sortedCategories.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 categories for the week starting from " << startDate << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedCategories.size()); ++i) {
            cout << setw(20) << left << sortedCategories[i].first << "\t" << sortedCategories[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }

    void GenerateTopExpensesMonthly(const string& month) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate().substr(0, 7) == month) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedExpenses(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedExpenses.begin(), sortedExpenses.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 expenses for " << month << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedExpenses.size()); ++i) {
            cout << setw(20) << left << sortedExpenses[i].first << "\t" << sortedExpenses[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }
    void GenerateTopCategoriesMonthly(const string& month) {
        map<string, double> categoryExpenses;

        for (auto& trans : transactions) {
            if (trans.getDate().substr(0, 7) == month) {
                categoryExpenses[trans.getCategory()] += trans.getAmount();
            }
        }

        vector<pair<string, double>> sortedCategories(categoryExpenses.begin(), categoryExpenses.end());
        sort(sortedCategories.begin(), sortedCategories.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.second > b.second;
            });

        cout << "Top 3 categories for " << month << ":\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < min(3, (int)sortedCategories.size()); ++i) {
            cout << setw(20) << left << sortedCategories[i].first << "\t" << sortedCategories[i].second << endl;
        }
        cout << "-----------------------------------------\n";
    }
};



class FinancialManager{
    
public:
    vector<Wallet> wallets;
    vector<Card>cards;
    void AddWallet(Wallet& wal) {
        wallets.push_back(wal);
    }
    void AddCard(Card& card) {
        cards.push_back(card);
    }


    void AddTransactionWallet(int WalletIndex, Transaction& transaction) {
        if (WalletIndex >= 0 && WalletIndex < wallets.size())
        {
            wallets[WalletIndex].AddTrans(transaction);
        }
    }

    void AddTransactionCard(int CardIndex, Transaction& transaction) {
        if (CardIndex >= 0 && CardIndex < cards.size())
        {
            cards[CardIndex].AddTrans(transaction);
        }
    }
};

int main() {
    int ch = 0;
    FinancialManager fin_man;
    vector<Transaction> alltransaction;

    do {
        cout << "\t\t\tYou are welcome from Privat 24\n";
        cout << "\t\t\tMenu operation\n";
        cout << "\t\t\t1. Add Wallet\n";
        cout << "\t\t\t2. Add Card\n";
        cout << "\t\t\t3. Add Transaction to Wallet\n";
        cout << "\t\t\t4. Add Transaction to Card\n";
        cout << "\t\t\t5. Generate Report for Wallet\n";
        cout << "\t\t\t6. Generate Report for Card\n";
        cout << "\t\t\t7. Generate Report for Wallet by month\n";
        cout << "\t\t\t8. Generate Top Expenses for Wallet by week\n";
        cout << "\t\t\t9. Generate Top Expenses for Wallet by month\n";
        cout << "\t\t\t10. Generate Top Categories for Wallet by week\n";
        cout << "\t\t\t11. Generate Top Categories for Wallet by month\n";
        cout << "\t\t\t12. Exit\n\n\n\n";

        cin >> ch;

        switch (ch) {
        case 1: {
            string name_wallet;
            cout << "\nEnter name of wallet: ";
            cin >> name_wallet;
            Wallet tmp_wal(name_wallet);
            fin_man.AddWallet(tmp_wal);
            cout << "\nWallet added\n";
            break;
        }
        case 2: {
            string type_card;
            double initial_balance = 0.0;
            cout << "Enter type of card (Debit or Credit): ";
            cin >> type_card;
            if (type_card == "Debit") {
                Card tmp_card(type_card);
                fin_man.AddCard(tmp_card);
                cout << "Debit card added\n";
            }
            else if (type_card == "Credit") {
                cout << "Enter initial balance for the credit card: ";
                cin >> initial_balance;
                Card tmp_card(type_card, initial_balance, alltransaction);
                fin_man.AddCard(tmp_card);
                cout << "Credit card added\n";
            }
            else {
                cout << "Invalid card type\n";
            }
            break;
        }

        case 3: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                double amount;
                string category, date;
                cout << "Enter the amount: ";
                cin >> amount;
                cout << "Enter the category: ";
                cin >> category;
                cout << "Enter the date: ";
                cin >> date;
                Transaction transaction(amount, category, date);
                fin_man.AddTransactionWallet(walletIndex, transaction);
                cout << "Transaction added to wallet successfully.\n";
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 4: {
            int cardIndex;
            cout << "Enter the index of the card: ";
            cin >> cardIndex;
            if (cardIndex >= 0 && cardIndex < fin_man.cards.size()) {
                double amount;
                string category, date;
                cout << "Enter the amount: ";
                cin >> amount;
                cout << "Enter the category: ";
                cin >> category;
                cout << "Enter the date: ";
                cin >> date;
                Transaction transaction(amount, category, date);
                fin_man.AddTransactionCard(cardIndex, transaction);
                cout << "Transaction added to card successfully.\n";
            }
            else {
                cout << "Invalid card index.\n";
            }
            break;
        }
        case 5: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                Wallet wallet = fin_man.wallets[walletIndex];
                vector<Transaction> transactions = wallet.getTrans();
                wallet.GenerateReport(transactions);
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 6: {
            int cardIndex;
            cout << "Enter the index of the card: ";
            cin >> cardIndex;
            if (cardIndex >= 0 && cardIndex < fin_man.cards.size()) {
                Card card = fin_man.cards[cardIndex];
                vector<Transaction> transactions = card.getTrans();
                card.GenerateReport(transactions);
            }
            else {
                cout << "Invalid card index.\n";
            }
            break;
        }


        case 7: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                string month;
                cout << "Enter the month (YYYY-MM): ";
                cin >> month;
                fin_man.wallets[walletIndex].GenerateMonthlyReport(month);
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 8: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                string startDate, endDate;
                cout << "Enter the start date of the week (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter the end date of the week (YYYY-MM-DD): ";
                cin >> endDate;
                fin_man.wallets[walletIndex].GenerateTopExpensesWeekly(startDate, endDate);
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 9: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                string month;
                cout << "Enter the month (YYYY-MM): ";
                cin >> month;
                fin_man.wallets[walletIndex].GenerateTopExpensesMonthly(month);
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 10: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                string startDate, endDate;
                cout << "Enter the start date of the week (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter the end date of the week (YYYY-MM-DD): ";
                cin >> endDate;
                fin_man.wallets[walletIndex].GenerateTopCategoriesWeekly(startDate, endDate);
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 11: {
            int walletIndex;
            cout << "Enter the index of the wallet: ";
            cin >> walletIndex;
            if (walletIndex >= 0 && walletIndex < fin_man.wallets.size()) {
                string month;
                cout << "Enter the month (YYYY-MM): ";
                cin >> month;
                fin_man.wallets[walletIndex].GenerateTopCategoriesMonthly(month);
            }
            else {
                cout << "Invalid wallet index.\n";
            }
            break;
        }
        case 12: {
            cout << "Exiting program...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (ch != 12);

    return 0;
}