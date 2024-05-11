#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <ctime>

struct Transaction {
    enum Type { DEPOSIT, WITHDRAWAL };
    Type type;
    double amount;
    time_t timestamp;
};

template <typename T>
class Account {
private:
    std::string accountNumber;
    double balance;
    std::stack<Transaction> transactionHistory;

public:
    Account(const std::string& accNumber, double initialBalance)
            : accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        Transaction transaction = { Transaction::DEPOSIT, amount, time(nullptr) };
        transactionHistory.push(transaction);
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            Transaction transaction = { Transaction::WITHDRAWAL, amount, time(nullptr) };
            transactionHistory.push(transaction);
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    std::stack<Transaction> getTransactionHistory() const {
        return transactionHistory;
    }
};

void displayAccountDetails(const std::vector<std::shared_ptr<Account<double>>>& accounts) {
    for (const auto& account : accounts) {
        std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
        std::cout << "Balance: " << account->getBalance() << std::endl;

        std::stack<Transaction> history = account->getTransactionHistory();
        std::cout << "Transaction History:" << std::endl;
        while (!history.empty()) {
            Transaction transaction = history.top();
            history.pop();
            std::cout << "- Type: " << (transaction.type == Transaction::DEPOSIT ? "Deposit" : "Withdrawal")
                      << ", Amount: " << transaction.amount
                      << ", Timestamp: " << std::asctime(std::localtime(&transaction.timestamp));
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::shared_ptr<Account<double>>> accounts;

    auto acc1 = std::make_shared<Account<double>>("ACC001", 1000.0);
    auto acc2 = std::make_shared<Account<double>>("ACC002", 2000.0);

    acc1->deposit(500.0);
    acc1->withdraw(200.0);
    acc2->deposit(1000.0);
    acc2->withdraw(300.0);

    accounts.push_back(acc1);
    accounts.push_back(acc2);

    displayAccountDetails(accounts);

    return 0;
}
