#include <stdio.h>
#include <string.h>

void twosComplement(int n, char* r);

void intToBinary(int n, char* str);

void addBinary(char* str, int n, char* r);

void complement(char* str, char* r);

char itoc(int n);

int ctoi(char c);

int main()
{
    char r[32];
    int num;

    printf("Enter an int: ");
    scanf("%d", &num);

    twosComplement(num,r);

    printf("%s\n", r);
}

void twosComplement(int n, char* r)
{
    char str[32];

    intToBinary(n, str);

    complement(str, r);
}

void intToBinary(int n, char* str)
{
    for (int i=31; i>=0; i--)
    {
        str[i]=(itoc(n%2));
        n/=2;
    }
}

void addBinary(char* str, int n, char* r)
{
    char str2[32];
    intToBinary(n, str2);

    int c=0; 
    for(int i=31; i>=0; i--)
    {
        int temp=(ctoi(str[i]))+(ctoi(str2[i]))+c; //conver the values from char to int, then add
        if (temp>=2)
        {
            r[i]=itoc(temp-2);
            c=1;
        }
        else
        {
            r[i]=itoc(temp);
            c=0;
        }
    }

}

void complement(char* str, char* r)
{
    for (int i=31; i>=0; i--)
    {
        if(str[i]=='0')
        {
            r[i]='1';
        }
        else if (str[i]=='1')
        {
            r[i]='0';
        }
        else
        {
            printf("%s\n", "error. binary value holds a value that is not 0 or 1");
        }
    }
    addBinary(r, 1, r);
}

char itoc(int n)
{
    return n+'0';
}

int ctoi(char c)
{
    return c-'0';
}