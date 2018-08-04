/*
finding the prime number in 100 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define MAX 100

int list[10];
int list2[10];

void findPrime(){
	int primes[MAX]; //starting from zero  	
	for(int i=0;i<MAX;i++)
		primes[i] = 1;//initiall assume all the numbers are prime
	primes[0] = 0;//zero and one are not prime number
	primes[1] = 0;

	//starting from 2, and eliminate the from that base multiplier
	for(int i=2; i<MAX; i++){
		if(primes[i] == 1){
			for(int j = 2; i*j<=MAX; j++)
				primes[i*j] = 0;
		}
	}

	for(int i=0; i<=MAX; i++){
		if(primes[i] == 1)
			printf("%d ", i);
	}
	printf("\n");
}
//O(N), since it runs n time
void findFactor(int x){
	int* ptr = list;
	for(int i=1; i<=x; i++){
		if(x%i == 0){
			*ptr = i;
			ptr++;
		}
	}
}

//we can shirnk it by sqaure root, the reason behind it is that
//a*b=n, once we find a and known n, then we can just got b
//O(N^(1/2))
void findFactor2(int x){
	int* ptr = list2;
	for(int i=1; i<= sqrt(x); i++){
			if(x%i == 0){
			*ptr = i;
			ptr++;
			*ptr = x/i;
			ptr++;
		}
	}
}

//O(n)
void primeFactorization(int n){
	int num[10];
	int f[10];
	int* p1 = num;
	int* p2 = f;
	//int* p3 = num;

	for(int i=2; i<=n; i++){
		if(n%i == 0){
			int counter = 0;
			while(n%i == 0){
				n=n/i;
				counter++;
			}
			*p1 = i;
			*p2 = counter;
			p1++;
			p2++;
		}
	}

	for(int i=0; i<10; i++){
		if(num[i]!=NULL && f[i]!=NULL)
			printf("%d^%d ", num[i], f[i]);
	}
	printf("\n");
}

void primeFactorization2(int n){
	int num[10];
	int f[10];
	int* p1 = num;
	int* p2 = f;
	//int* p3 = num;

	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
			int counter = 0;

			while(n%i == 0){
				n=n/i;
				counter++;
			}
			*p1 = i;
			*p2 = counter;
			p1++;
			p2++;
		}
		if(n!=1){
			*p1 = n;
			*p2 = 1;
			p1++;
			p2++;
			break; //break the for loop	
		}
	}

	for(int i=0; i<10; i++){
		if(num[i]!=NULL && f[i]!=NULL)
			printf("%d^%d ", num[i], f[i]);
	}
	printf("\n");
}

int main(){
	findPrime();
	findFactor(12);
	for(int i=0; i<10; i++)
		if(list[i]!=0)
			printf("%d ", list[i]);
	printf("\n");

	findFactor2(12);
	for(int i=0; i<10; i++)
		if(list2[i]!=0)
			printf("%d ", list2[i]);
	printf("\n");

	primeFactorization(45);
	primeFactorization2(44);

}