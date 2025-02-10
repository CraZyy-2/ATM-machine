#include <stdio.h> 

int main(){
    float balance = 1000.00;
    int choice;
    float added;
    float withdrawn;
    while (1) {
        printf("Would you like to : 1- Check Balance   2- Deposit Money  3- Withdraw Money  4- Exit \n");
        scanf(" %d", &choice);
            switch (choice){
                case 1:
                    printf("Your current balance is :  $%.2f\n", balance);
                    break;
                case 2: 
                    printf("How much would you like to deposit : ");
                    scanf("%f", &added);
                    if (added > 0) {
                        balance += added;
                        printf("$%.2f has been deposited to your account succesfully. New balance : $%.2f\n", added, balance);
                    } else {
                        printf("Invalid deposit amount");
                    }
                    break;
                case 3: 
                    printf("How much would you like to withdraw : ");
                    scanf("%f", &withdrawn);
                    if (withdrawn > 0 && withdrawn <= balance) {
                    balance -= withdrawn;
                    printf("$%.2f has been succesfully withdrawn from your account. New balance is : $%.2f\n", withdrawn, balance);
                    } else {
                    printf("Invalid deposit amount.\n");
                    }
                    break;
                case 4:
                    printf("See you next time!");
                    return 0;
                default:
                    printf("invalid");
            }
    }
}
