#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;
unsigned long long factorial(unsigned int n) {//создаем рекурсию
	if (n == 0) return 1;//if n = 0 то выход из функции
	return n*factorial(n - 1);//считаем n умножаем на функцию n - 1 и возращает значение
}
int main(){
	srand(time(NULL));
	int f = 6,p = 0;//f это будущий !6
	p = factorial(f);//p записывается возращенное значение полученное из функции
	cout << p;
	_getch();
	return 0;
}