#include"GroceryMadeEasy.h"
#include"LoginOperations.cpp"
int loginManagement(){
    printf("Wellcome to Grocery Made Easy\n");
    printf("0.Login\n1.Register\n");
    printf("Enter your choice 0 for login, 1 for register: ");
    if (scanf("%d", &userChoice) != 1)
    {
        printf("Invalid Input\n");
        fflush(stdin);
        return loginManagement();
        exit(0);
    }
    autherigation=userChoice;
    if (autherigation==LOGIN)
    {
        dataBaseBuild();
        if (checkLogin()) {
            return 1;
        }
    }
    else if(autherigation==REGISTER)
    {
        dataBaseBuild();
        if (checkRegisteration()) {
            return 1;
        }
    }
    else if (userChoice!=1||userChoice!=0) {
        return loginManagement();
       exit(0);
    }
    return 0;
}
