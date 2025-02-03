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
}

void twosComplement(int n, char* str)
{
    intToBinary(n, str);

    printf("%s", "In Binary: ");
    printf("%s\n", str);

    invertBinary(str);

    addBinary(str, 1);
}

void intToBinary(int n, char* str)
{
    int origN=n;

    if (n<0) //itoc breaks if n<1
    {
        n*=-1;
    }

    for (int i=31; i>=0; i--)
    {
        str[i]=(itoc(n%2));
        n/=2;
    }

    if (origN<0) //fix negative values
    {
        invertBinary(str);
        addBinary(str, 1);
    }
}

void addBinary(char* str, int n)
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

void invertBinary(char* str)
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
            printf("%s\n", "error. binary value holds a value that is not 0 or 1");
        }
    }
}

char itoc(int n)
{
    return n+'0';
}

int ctoi(char c)
{
    return c-'0';
}