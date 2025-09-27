
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char date[20];
    char type[20];
    float amount;
    float balance_after;
} Transaction;

Transaction transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

void add_transaction(const char* type, float amount, float balance_after) {
    if (transaction_count < MAX_TRANSACTIONS) {
        time_t t = time(NULL);
        struct tm* tm_info = localtime(&t);
        strftime(transactions[transaction_count].date, 20, "%Y-%m-%d %H:%M:%S", tm_info);
        strcpy(transactions[transaction_count].type, type);
        transactions[transaction_count].amount = amount;
        transactions[transaction_count].balance_after = balance_after;
        transaction_count++;
    }
}

void display_transactions() {
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║                       TRANSACTION HISTORY                ║\n");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    printf("║ %-19s %-12s %-10s %-12s ║\n", "Date", "Type", "Amount", "Balance");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    
    for (int i = 0; i < transaction_count; i++) {
        printf("║ %-19s %-12s $%-9.2f $%-11.2f ║\n", 
               transactions[i].date, transactions[i].type, 
               transactions[i].amount, transactions[i].balance_after);
    }
    printf("╚══════════════════════════════════════════════════════════╝\n");
}

void display_balance(float balance) {
    printf("\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║                      ACCOUNT BALANCE                     ║\n");
    printf("╠══════════════════════════════════════════════════════════╣\n");
    printf("║                 Current Balance: $%-10.2f           ║\n", balance);
    printf("╚══════════════════════════════════════════════════════════╝\n");
}

int main() {
    float balance = 1000.00;
    int choice;
    float amount;
    
    add_transaction("Initial", 0.0, balance);
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║                    BANKING SYSTEM                        ║\n");
        printf("╠══════════════════════════════════════════════════════════╣\n");
        printf("║ 1. Check Balance                                         ║\n");
        printf("║ 2. Deposit Money                                         ║\n");
        printf("║ 3. Withdraw Money                                        ║\n");
        printf("║ 4. Transaction History                                   ║\n");
        printf("║ 5. Exit                                                  ║\n");
        printf("╠══════════════════════════════════════════════════════════╣\n");
        printf("║ Enter your choice (1-5): ");
        scanf("%d", &choice);
        printf("╚══════════════════════════════════════════════════════════╝\n");

        switch (choice) {
            case 1:
                display_balance(balance);
                break;
                
            case 2:
                printf("\n╔══════════════════════════════════════════════════════════╗\n");
                printf("║                         DEPOSIT                          ║\n");
                printf("╠══════════════════════════════════════════════════════════╣\n");
                printf("║ Enter amount to deposit: $");
                scanf("%f", &amount);
                printf("╚══════════════════════════════════════════════════════════╝\n");
                
                if (amount > 0) {
                    balance += amount;
                    add_transaction("Deposit", amount, balance);
                    printf("\n╔══════════════════════════════════════════════════════════╗\n");
                    printf("║                    TRANSACTION SUCCESS                  ║\n");
                    printf("╠══════════════════════════════════════════════════════════╣\n");
                    printf("║ Deposit Amount:  $%-10.2f                      ║\n", amount);
                    printf("║ New Balance:     $%-10.2f                      ║\n", balance);
                    printf("╚══════════════════════════════════════════════════════════╝\n");
                } else {
                    printf("\n╔══════════════════════════════════════════════════════════╗\n");
                    printf("║                     INVALID AMOUNT                      ║\n");
                    printf("╠══════════════════════════════════════════════════════════╣\n");
                    printf("║          Please enter a positive amount                 ║\n");
                    printf("╚══════════════════════════════════════════════════════════╝\n");
                }
                break;
                
            case 3:
                printf("\n╔══════════════════════════════════════════════════════════╗\n");
                printf("║                         WITHDRAW                         ║\n");
                printf("╠══════════════════════════════════════════════════════════╣\n");
                printf("║ Enter amount to withdraw: $");
                scanf("%f", &amount);
                printf("╚══════════════════════════════════════════════════════════╝\n");
                
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    add_transaction("Withdrawal", amount, balance);
                    printf("\n╔══════════════════════════════════════════════════════════╗\n");
                    printf("║                    TRANSACTION SUCCESS                  ║\n");
                    printf("╠══════════════════════════════════════════════════════════╣\n");
                    printf("║ Withdrawal Amount: $%-10.2f                      ║\n", amount);
                    printf("║ New Balance:       $%-10.2f                      ║\n", balance);
                    printf("╚══════════════════════════════════════════════════════════╝\n");
                } else if (amount > balance) {
                    printf("\n╔══════════════════════════════════════════════════════════╗\n");
                    printf("║                   INSUFFICIENT FUNDS                    ║\n");
                    printf("╠══════════════════════════════════════════════════════════╣\n");
                    printf("║          Withdrawal amount exceeds balance              ║\n");
                    printf("║               Available balance: $%-10.2f          ║\n", balance);
                    printf("╚══════════════════════════════════════════════════════════╝\n");
                } else {
                    printf("\n╔══════════════════════════════════════════════════════════╗\n");
                    printf("║                     INVALID AMOUNT                      ║\n");
                    printf("╠══════════════════════════════════════════════════════════╣\n");
                    printf("║          Please enter a positive amount                 ║\n");
                    printf("╚══════════════════════════════════════════════════════════╝\n");
                }
                break;
                
            case 4:
                display_transactions();
                break;
                
            case 5:
                printf("\n╔══════════════════════════════════════════════════════════╗\n");
                printf("║                  THANK YOU FOR BANKING                   ║\n");
                printf("║                     WITH US TODAY!                       ║\n");
                printf("╚══════════════════════════════════════════════════════════╝\n");
                return 0;
                
            default:
                printf("\n╔══════════════════════════════════════════════════════════╗\n");
                printf("║                    INVALID SELECTION                     ║\n");
                printf("╠══════════════════════════════════════════════════════════╣\n");
                printf("║          Please enter a number between 1-5              ║\n");
                printf("╚══════════════════════════════════════════════════════════╝\n");
        }
    }
}

