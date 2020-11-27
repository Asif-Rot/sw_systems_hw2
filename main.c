#include <stdio.h>
#include "myBank.h"

int main(){
  char Transaction; 
  while (1){
    printf("\nPlease choose a transaction type: \n");
    printf(" O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
    scanf(" %c", &Transaction);
    if(Transaction=='O'){
      double amount;
      printf("Please enter amount for deposit: \n");
      scanf("%lf", &amount);
      openAccount(amount);
    }
    if(Transaction=='B'){
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      checkBalance(accountNum);
    }
    if(Transaction=='D'){
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      deposit(accountNum);
    }

    if(Transaction=='W'){
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      withdraw(accountNum);
    }

    if(Transaction=='C'){
      int accountNum;
      printf("Please enter account number: \n");
      scanf("%d", &accountNum);
      closeAccount(accountNum);
    }

    if(Transaction=='I'){
      addInterest();
    }

    if(Transaction=='P'){
      printAccount();
    }

    if(Transaction=='E'){
      closeAccounts();
      break;
    }

    if(Transaction!='O'&&Transaction!='B'&&Transaction!='D'&&Transaction!='W'&&Transaction!='C'&&Transaction!='I'&&Transaction!='P'&&Transaction!='E'){
      printf("invaild command!\n");
  }
  }

  return 0;
}