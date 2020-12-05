#include <stdio.h>
#include "myBank.h"

int main()
{
<<<<<<< HEAD
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
=======
  char Transaction = ' ';
  
  while (1)
  {
    printf("\nPlease choose a transaction type: \n");
    printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdraw\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    scanf(" %c", &Transaction);

    switch(Transaction) {

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
      printf("invalid command!\n");
      break;

    }
  }
>>>>>>> ea3d5ae349c07b6c085f213eb27afc30c1e5be16
  return 0;
}