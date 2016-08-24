#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;
template <typename T> //создаем шаблон
void QuickSort(T arr, int l, int r)//создаем функцию сортировки. l принимает левый элемент. r правый.
{
	int i, j;
	i = l;//i присваиваем левый
	j = r;//j присваеваем правый
	int middle = arr[(i + j) / 2];//находим средний элемент массива и присваиваем middle
	do {
		while (middle > arr[i]) i++;//i переносится в право
		while (middle < arr[j]) j--;//j переносится в лево
		if (i <= j) {//если не выполняется while
			swap(arr[i], arr[j]);//меняем значение переменных
			//сдвигаем
			i++;
			j--;
		}
	} while (i < j);//i < j выполняется цикл
	if (i < r) QuickSort(arr, i, r);//рассматриваем правую часть
	if (j > l) QuickSort(arr, l, j);//рассматриваем левую часть
}
int main(){
	srand(time(NULL));
	int n = 1000000;
	int *arr = new int[n];//создаем динамический массив

	for (int i(0); i < n; i++) {
		arr[i] = rand();//в каждую яйчейку записываем рандомное число
	}
	double t1 = clock();//создаем измеритель времени до функции
	QuickSort(arr, 0, n - 1);//вызываем функцию сортировки
	double t2 = clock() - t1;//создаем измеритель времени после функции
	cout << t2 / CLOCKS_PER_SEC;//выводим время в секундах
	delete[] arr;//очистка массива
	_getch();
	return 0;
}