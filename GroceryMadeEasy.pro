TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        DisplayOperations.cpp \
        DisplayProduct.cpp \
        LoginOperations.cpp \
        LogineManagement.cpp \
        main.c

HEADERS += \
    GroceryMadeEasy.h

DISTFILES += \
    build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/ProductsList.txt \
    build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/UserInfo.txt
