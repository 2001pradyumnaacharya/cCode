#include"GroceryMadeEasy.h"
#include"DisplayOperations.cpp"

void displayProducts(){
    displayOperations();
    if (instructions==1)
    {//instruction displayed only when new user registers and then login.
        printf("\nTo make your shopping experience smooth, please follow these simple steps\nOnce you've selected a category, browse through the available products in that category\nExample: If you select Dairy, you might choose from Milk, Cheese, Yogurt, etc.\n\n");
        sleep(5);
        instructions=0;
    }
    printf("1: diry Essentials\n2: vegAndFruitrs\n3: Bathroom Essentials\n4: Cooking Essentials\n5: Colddrinks and beverages\n6: Snecks and biscties\n7: Ice cream\n\n");
    printf("Enter your choice: ");
    fflush(stdin);
    if(scanf("%d",&genericChoice)!=1)
    {
        printf("Invalid input.\n\n");
        displayProducts();
    }else if ((genericChoice<1) || (genericChoice>7)) {
        printf("\nThe Generics doesnt exists sorry for your inconvenince\n\n");
        displayProducts();
    }

    printf("PRODUCTID                          PRODUCTNAME                           PRICE\n");
    printf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < noofProducts; i++) {
        if (products[i].genericId==genericChoice)
        {
            printf(" %-36d %-36s %d\n",products[i].productId,products[i].productName,products[i].productPrice);

        }
    }
    while (1) {
        printf("Enter b to get back to generics or Enter a to move to Cart\n");
        fflush(stdin);
        if (scanf(" %c", &backToGeneric)!=1)
        {
            printf("invalid Input....");

        }
        else if (backToGeneric == 'b' || backToGeneric == 'B')
        {
            displayProducts();
            break;
        }
        else if (backToGeneric == 'a' || backToGeneric == 'A')
        {
            printf("thankYou for shopping with us...\n");
            return;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }

    }
}
