#include"GroceryMadeEasy.h"
void displayOperations(){
    productDatabase= fopen("ProductsList.txt","r");
    if (productDatabase==NULL) {
        printf("Sorry for the inconvenience, the app is under maintenance\n\n");
        exit(1);
        return;
    }
    productDataBase.productName=(char*)malloc(bufferSize*sizeof(char));
    noofProducts=0;
    indexofProduct=0;
    while (fscanf(productDatabase,"%d %s %d %d %d",&productDataBase.productId,productDataBase.productName,&productDataBase.productPrice,&productDataBase.productQuintety,&productDataBase.genericId)!=EOF) {
        noofProducts++;
    }
    products=(struct display*)malloc(noofProducts*sizeof(struct display));
    rewind(productDatabase);
    while (fscanf(productDatabase,"%d %s %d %d %d",&productDataBase.productId,productDataBase.productName,&productDataBase.productPrice,&productDataBase.productQuintety,&productDataBase.genericId)!=EOF) {
        products[indexofProduct].productId=productDataBase.productId;
        products[indexofProduct].productName=strdup(productDataBase.productName);
        products[indexofProduct].productPrice=productDataBase.productPrice;
        products[indexofProduct].productQuintety=productDataBase.productQuintety;
        products[indexofProduct].genericId=productDataBase.genericId;
        indexofProduct++;
    }
    free( productDataBase.productName);

}
