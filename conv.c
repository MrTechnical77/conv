#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char *ascii = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

char buffer[32];
int pointer = 31;

int power2Check (int base)
{
	if (base != 0)
	{
		return (base & (base - 1)) == 0;
	}
	else return 0;
}

int length(char *ptr){
  int i = 0;
  int n = 0;
  while(*(ptr + i) !='\0')
  {
    ++n;
    ++i;
  }
  return n;
}

int power(int a, int b)
{
  int num = 1;
  //if(b) num*=a;
  for(int i = 1; i <= b; i++)
  {
    num*=a;
  }

  return num;
}

void other_base(int decimal, int base)
{
  int temp = decimal;

    int arr[36];
    int r;

    int i = 0;
    while (temp > 0) {
        r = temp % base;
        arr[i] = r;
        temp /= base;
        i++;
    }

    char carr[100];
    for (int n = 0; n < i; n++) {
        if (arr[n] > 9) {
            carr[n] = arr[n] + 'A'- 10;
        } else {
            carr[n] = arr[n] + '0';
        }
    }
    i--;
    while (i+1) {
        printf("%c", carr[i]);
        i--;
    }
    printf("\n");

}

void power2_base(int decimal, int base)
{
  int temp = decimal;

    int arr[36];
    int r;

    int i = 0;
    while (temp > 0) {
        r = temp % base;
        arr[i] = r;
        temp /= base;
        i++;
    }

    char carr[100];
    for (int n = 0; n < i; n++) {
        if (arr[n] > 9) {
            carr[n] = arr[n] + 'A' - 10;
        } else {
            carr[n] = arr[n] + '0';
        }
    }
    i--;
    while (i+1) {
        printf("%c", carr[i]);
        i--;
    }
    printf("\n");
}

void base_256(int decimal, int base)
{
  int temp = decimal;

    int arr[36];
    int r;

    int i = 0;
    while (temp > 0) {
        r = temp % base;
        arr[i] = r;
        temp /= base;
        i++;
    }

    i--;
    while (i+1) {
        printf("%d", arr[i]);
        if (i)
        printf(".");
        i--;
    }
    printf("\n");
}



int main(int argc, char **argv){

  if (argc != 3) return -1;

  char *base = argv[2];
  char *decimal = argv[1];
  int pcheck = 0;




	int base_int = 0;
  for (int i = 0; i < length(base); i++)
  {
    base_int += power(10, length(base) -1 - i) * (base[i] - '0');
  }

  int decimal_int = 0;
  for (int i = 0; i < length(decimal); i++)
  {
    decimal_int += power(10, length(decimal) -1 - i) * (decimal[i] - '0');
  }

  pcheck = power2Check(base_int);

  // Base error handling
  if (base_int < 2)
  {
    printf("INVALID BASE \n");
    return -1;
  }
  if (base_int > 64 && base_int != 256)
  {
    printf("INVALID BASE \n");
    return -1;
  }

  // Choosing what funcion to run based on the base
  if (base_int > 1 && base_int < 65 && pcheck == 1)
  {
    power2_base(decimal_int, base_int);
  }

  else if (base_int == 256)
  {
    base_256(decimal_int, base_int);
  }

  else
  {
    other_base(decimal_int, base_int);
  }


  return 0;
}
