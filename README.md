# 🏦 Banking System – C Console Application

A simple **banking system** implemented in **C** that lets users check their balance, deposit money, withdraw money, and view a complete transaction history — all from the command line.

---

## ✨ Features
- Check Balance: View the current account balance at any time.  
- Deposit Money: Add funds to your account with instant updates.  
- Withdraw Money: Securely withdraw funds while preventing overdrafts.  
- Transaction History: View a detailed list of all transactions (date, type, amount, updated balance).  
- Timestamps: Each transaction is automatically time-stamped.  
- Clean ASCII Interface: Easy-to-read box-style console UI.

---

## 🛠️ Requirements
- C Compiler (e.g., GCC, Clang, or MSVC)  
- Standard C libraries: `stdio.h`, `stdlib.h`, `string.h`, `time.h`  

No external dependencies required.

---

## 🚀 Installation & Compilation

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/banking-system-c.git
   cd banking-system-c
   ```
2. **Compile the program**
```bash
gcc banking_system.c -o banking_system
```

Run the executable
```bash
./banking_system
```

##🎯 How to Use

When you start the program, a menu appears:

1. Check Balance
2. Deposit Money
3. Withdraw Money
4. Transaction History
5. Exit


Enter a number (1–5) to select an option.

## Operations

Check Balance: Displays the current balance in a formatted box.

Deposit Money: Enter a positive amount to add funds. Balance updates instantly.

Withdraw Money: Enter an amount to withdraw.

- Allowed if funds are sufficient.

- Shows an error if the amount exceeds the balance or is invalid.

Transaction History: Lists all transactions with:

- Date & Time (YYYY-MM-DD HH:MM:SS)

- Type (Initial, Deposit, or Withdrawal)

- Amount

- Balance after each transaction

Exit: Ends the program with a closing message.

## 🗂️ Project Structure
```bash
banking-system-c/
├── banking_system.c   # Main source code
└── README.md          # Project documentation
```

## 💡 Code Highlights

- Transaction Tracking
Uses a Transaction struct to record:
```bash
typedef struct {
    char date[20];
    char type[20];
    float amount;
    float balance_after;
} Transaction;
```

- Dynamic Date/Time
Uses time.h to create timestamps for every transaction.

- Input Validation
Ensures deposits/withdrawals are positive and withdrawals don’t exceed the current balance.

## ⚙️ Customization

Starting balance: change the balance variable in main() (default: $1000.00).

Transaction limit: update #define MAX_TRANSACTIONS (default: 100).

Interface: adjust the ASCII box formatting to your style.

## 📜 License

MIT License – free to use, modify, and distribute.
