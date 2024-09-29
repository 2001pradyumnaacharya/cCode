#include"GroceryMadeEasy.h"
#include"LogineManagement.cpp"
#include"DisplayProduct.cpp"
int main()
{
    if (loginManagement()) {
        displayProducts();
    }
    // printf("hello world\n");
    return 0;
}
