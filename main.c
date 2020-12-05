#include <stdio.h>
#include "myBank.h"

int main()
{
  char Transaction; 
  do
  {
    printf("\nPlease choose a transaction type:\n");
    printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    scanf(" %c", &Transaction);
    switch(Transaction)
    {
      case 'O':
        openAccount();
        break;

      case 'B':
        checkBalance();
        break;

      case 'D':
        deposit();
        break;

      case 'W':
        withdraw();
        break;

      case 'C':
        closeAccount();
        break;

      case 'I':
        addInterest();
        break;

      case 'P':
        printAccount();
        break;

      case 'E':
        closeAccounts();
        return 0;
        break;

      default:
        printf("Invalid transaction type\n");
        break;
    }
  }
  while(Transaction!='E');
  return 0;
}