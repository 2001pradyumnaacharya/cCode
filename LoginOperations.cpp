#include "GroceryMadeEasy.h"
void dataBaseBuild() {
    FILE *loginFileRead = fopen("UserInfo.txt", "r");

    if (loginFileRead==NULL) {
        printf("open file");
    }
    sizeOfArray=0;
    indexArray=0;
    datacount.userName=(char*)malloc(bufferSize*sizeof(char));
    datacount.password=(char*)malloc(bufferSize*sizeof(char));
    while (fscanf(loginFileRead,"%s %s",datacount.userName,datacount.password)!=EOF) {
        sizeOfArray++;
    }
    userCredentials=(struct credentials*)malloc(sizeOfArray*sizeof(struct credentials));
    rewind(loginFileRead);
    while (fscanf(loginFileRead,"%s %s",datacount.userName,datacount.password)!=EOF) {
        userCredentials[indexArray].userName=strdup(datacount.userName);
        userCredentials[indexArray].password=strdup(datacount.password);
        indexArray++;
    }
    free(datacount.userName);
    free(datacount.password);
    fclose(loginFileRead);
}

int checkLogin(){
    enteredName=(char*)malloc(bufferSize*sizeof(char));
    entredPasssword=(char*)malloc(bufferSize*sizeof(char));
    printf("enter the UserName: ");
    scanf("%s",enteredName);
    printf("enter the Password: ");
    scanf("%s",entredPasssword);
    for (int i = 0; i <= sizeOfArray; i++) {
            if (strcmp(userCredentials[i].userName,enteredName)==0 && strcmp(userCredentials[i].password,entredPasssword)!=0)
            {
                userFound=0;
                printf("Password is incorrect re_enter the password\n");
                free(entredPasssword);
                free(enteredName);
                checkLogin();
                return 1;
            }
            else if(strcmp(userCredentials[i].userName,enteredName)!=0 && strcmp(userCredentials[i].password,entredPasssword)==0)
            {
                userFound=0;
                printf("UserName is incorrect re_enter the password\n");
                free(entredPasssword);
                free(enteredName);
                checkLogin();
                return 1;
            }
            else if(strcmp(userCredentials[i].userName,enteredName)==0 && strcmp(userCredentials[i].password,entredPasssword)==0)
            {
                userFound=0;
                printf("logined in sucessfully\n");
                free(entredPasssword);
                free(enteredName);

                return 1;
            }
        }

        if (userFound) {
            free(enteredName);
            free(entredPasssword);
            for (int i = 0; i <= sizeOfArray; i++) {
                free( userCredentials[i].userName);
                free( userCredentials[i].password);
            }
            free(userCredentials);
            printf("user does't exists kindly register\n");
            checkRegisteration();
            return 1;
        }

    for (int i = 0; i <= sizeOfArray; i++) {
        free( userCredentials[i].userName);
        free( userCredentials[i].password);
    }
    free(userCredentials);
    return 0;
}

int checkRegisteration(){
    registerWrite=fopen("UserInfo.txt","a");
    registerEnterName=(char*)malloc(bufferSize*sizeof(char));
    registerEnterPassword=(char*)malloc(bufferSize*sizeof(char));
    registerEnterconformPassword=(char*)malloc(bufferSize*sizeof(char));
    printf("enter the UserName: ");
    scanf("%s",registerEnterName);
    printf("enter the Password: ");
    scanf("%s",registerEnterPassword);
    for (int i = 0; i < sizeOfArray; i++) {
        if(strcmp(userCredentials[i].userName,registerEnterName)==0 && strcmp(userCredentials[i].password,registerEnterPassword)==0)
        {
            printf("User Already Exists kindly Login\n");
            free(registerEnterName);
            free(registerEnterPassword);
            free(registerEnterconformPassword);
            fclose(registerWrite);
            checkLogin();
            return 0;
        }
    }
    printf("enter conform Password: ");
    scanf("%s",registerEnterconformPassword);
    if (strcmp(registerEnterconformPassword,registerEnterPassword)!=0)
    {
        printf("The conform password is in_correct kindly register again\n");
        free(registerEnterName);
        free(registerEnterPassword);
        free(registerEnterconformPassword);
        fclose(registerWrite);
        checkRegisteration();
        return 0;
    }
    else
    {
        fprintf(registerWrite,"%s %s",registerEnterName,registerEnterPassword);
        fprintf(registerWrite,"\n");
        userCredentials[indexArray].userName= strdup(registerEnterName);
        userCredentials[indexArray].password= strdup(registerEnterPassword);
        printf("registered sucesfully. Kindly Login..\n");
        instructions=1;
        free(registerEnterName);
        free(registerEnterPassword);
        free(registerEnterconformPassword);
        fclose(registerWrite);
        checkLogin();
        return 1;
    }
    free(registerEnterName);
    free(registerEnterPassword);
    free(registerEnterconformPassword);
    fclose(registerWrite);
    return 0;
}
