#include <stdio.h>

void twosComplement(int n, char* r);
void intToBinary(int n, char* str);
void addBinary(char* str, int n);
void invertBinary(char* str);
char itoc(int n);
int ctoi(char c);

int main()
{
    //we're working in 32bit
    char str[32]="";
    int num;

    printf("Enter an int: ");
    scanf("%d", &num);

    printf("%s", "You entered: ");
    printf("%d\n", num);

    twosComplement(num,str);

    printf("%s", "Two's Complement: ");
    printf("%s\n", str);

    return 0;
}

void twosComplement(int n, char* str) //returns two's complement of an integer value
{
    intToBinary(n, str);

    printf("%s", "In Binary: ");
    printf("%s\n", str);

    invertBinary(str);

    addBinary(str, 1);
}

void intToBinary(int n, char* str) //convert an integer value to its binary equivalent
{
    int origN=n;

    if (n<0) //itoc breaks if n<0
    {
        n*=-1;
    }
    for (int i=31; i>=0; i--)
    {
        str[i]=(itoc(n%2));
        n/=2;
    }
    if (origN<0) //fix negative values via two's complement
    {
        invertBinary(str);

        addBinary(str, 1);
    }
}

void addBinary(char* str, int n) //adds an int value to a binary value
{
    char str2[32];
    intToBinary(n, str2);

    int c=0; //hold carry value for addition
    for(int i=31; i>=0; i--)
    {
        int temp=(ctoi(str[i]))+(ctoi(str2[i]))+c;
        if (temp>=2)
        {
            str[i]=itoc(temp-2);
            c=1;
        }
        else
        {
            str[i]=itoc(temp);
            c=0;
        }
    }
}

void invertBinary(char* str) //inverts a binary value, swapping 1s and 0s
{
    for (int i=31; i>=0; i--)
    {
        if(str[i]=='0')
        {
            str[i]='1';
        }
        else if (str[i]=='1')
        {
            str[i]='0';
        }
        else //should never happen
        {
            printf("%s\n", "error: binary holds a value that is not 0 or 1");
        }
    }
}

char itoc(int n) //returns an int as a char, value must be 0-9
{
    return n+'0';
}

int ctoi(char c) //returns a char as an int
{
    return c-'0';
}
