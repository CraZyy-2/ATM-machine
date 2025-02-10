#include <stdio.h> 

int main(){
    float balance = 1000.00;
    char choice;
    float amount;
    while (1) {
        printf("Would you like to : 1- Check Balance   2- Deposit Money  3- Withdraw Money  4- Exit ");
        scanf(" %c", &choice);
            switch (choice){
                case '1':
                    printf("Your current balance is :  $%.2f\n", balance);
                    break;
                case '2': 
                    printf("How much would you like to deposit : ");
                    scanf("%f", &amount);
                    if (amount > 0) {
                        balance += amount;
                        printf("$%.2f has been deposited to your account succesfully. New balance : $%.2f\n", amount, balance);
                    } else {
                        printf("Invalid deposit amount");
                    }
                    break;
                case '3': 
                    printf("How much would you like to withdraw : ");
                    scanf("%f", &amount);
                    if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("$%.2f has been succesfully withdrawn from your account. New balance is : $%.2f\n", amount, balance);
                    } else {
                    printf("Invalid deposit amount.\n");
                    }
                    break;
                case '4':
                    printf("See you next time!");
                    return 0;

                default:
                printf("Invalid choice. Please choose a valid option.\n");    
            }
    }
        return 0;
}
