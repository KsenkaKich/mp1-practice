#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define n 8
char* names[n] = { "Big Party","Kinder","Lemonade","Mars","Sandwich","Snickers","Chips","Doshirak"};
int prices[n] = { 120,100,140,60,200,60,100,70};
char* codes[n] = { "1234", "5580", "8932", "1108", "7051", "9602", "4306", "3947" };
int discount[n] = { 35,5,10,50,0,15,0,5 };
int check[n];

int idx(char* barcode) {
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(barcode, codes[i]) == 0)
            return i;
    }
    return -1;
}
void entercodes()
{
    int con;
    do
    {
        int id;
        char barcode[5];
        printf("Input the barcode: \n");
        scanf("%s", barcode);
        printf("Continue?\n");
        scanf("%d", &con);
        id = idx(barcode);
        if (id < 0)
        {
            printf("Incorrect barcode\n");
            continue;
        }

        check[id]++;


    } while (con == 1);
}
void printcheck()
{
    int j;
    for (j = 0; j < n; j++)
    {
        if (check[j] != 0)
        {
            printf("Name: %s. Price: %d. Discount: %d. Amount: %d. Total price: %f\n",
                names[j], prices[j], discount[j], check[j], prices[j] * ((100 - discount[j]) * 0.01) * check[j]);

        }
    }
    return;
}
void total()
{
    double todiscount = 0, toprice = 0;
    int l;
    for (l = 0; l < n; l++)
    {
        if (check[l] != 0)
        {
            todiscount += prices[l] * (discount[l] * 0.01) * check[l];
            toprice += prices[l] * ((100 - discount[l]) * 0.01) * check[l];
        }
    }
    printf("Total discount: %lf. Total price: %lf", todiscount, toprice);
    return;
}
int main()
{
    double todiscount = 0, toprice = 0;

    entercodes();
    printcheck();
    total();

    return 0;
}
