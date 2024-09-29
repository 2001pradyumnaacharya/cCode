#ifndef GROCERYMADEEASY_H
#define GROCERYMADEEASY_H
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
long long sizeOfArray;
long long indexArray;
int userFound=1;
int bufferSize=500;
char *enteredName;
char *entredPasssword;
char *registerEnterName;
char *registerEnterPassword;
char *registerEnterconformPassword;
int userChoice;
int genericChoice;
long long noofProducts;
int indexofProduct;
int instructions=0;
char backToGeneric;
enum authontction{
    LOGIN,
    REGISTER
};

struct credentials
{
    char *userName;
    char *password;
};
struct database
{
    char *userName;
    char *password;
};
struct display{
    int productId;
    char *productName;
    int productPrice;
    int productQuintety;
    int genericId;
};
struct productdata{
    int productId;
    char *productName;
    int productPrice;
    int productQuintety;
    int genericId;
};
struct productdata productDataBase;
struct display *products;
struct database datacount;
struct credentials *userCredentials;
enum authontction autherigation;
FILE *loginFileRead;
FILE *registerWrite;
FILE *productDatabase;
int loginManagement();
int checkLogin();
int checkRegisteration();
void dataBaseBuild();
void displayProducts();
void displayOperations();
#endif // GROCERYMADEEASY_H
