#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int length2(int *ptr){
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
		char buffer[36];
		int len;
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
		len = length(carr);
		i = 0;

		while(len > 0)
		{
			buffer[len - 1] = carr[i];
			len--;
			i++;
		}

		printf("%s\n", buffer);
}

void power2_base(int decimal, int base)
{
	int temp = decimal;

    int arr[36];
		char buffer[36];
		int len;
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

		len = length(carr);
		i = 0;

		while(len > 0)
		{
			buffer[len - 1] = carr[i];
			len--;
			i++;
		}

    buffer[i] = '\0';

		printf("%s\n", buffer);
}

void base_256(const long long decimal, const int base)
{
  //int temp = decimal;
	char buffer[36];
	char buffer2[36];
	double test;

      long long m = decimal;
      long long b = base;
      int i = 0;

      long long temp = m;

      while (temp > 0) {
          i++;
          temp /= b;
      }

      i++;

      long long parquos[i];

      temp = m;
      for (int j = 0; j < i; j++) {
          parquos[j] = temp;
          temp /= b;

      }

      long long arr[i];

      for (int j = 0; j < i; j++) {
          arr[j] = parquos[j] % b;
      }

    i--;
    i--;
		int c = 0;
		int d = 0;
    while (i + 1) {
				sprintf(buffer2, "%lld", arr[i]);
				d = 0;
				while(buffer2[d] != '\0'){
        buffer[c] = buffer2[d];
				c++;
				d++;
				}
        if (i){
        buffer[c] = '.';
				c++;
				}
        i--;
    }
    buffer[c] = '\0';
    printf("%s\n", buffer);
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

  long long decimal_int = 0;

  decimal_int = atoll(decimal);

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
