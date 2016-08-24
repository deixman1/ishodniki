#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>
using namespace std;
template<typename t, typename t2>
auto find(t arr, t2 element, int left, int right) -> decltype(arr)
{
	int index = (left + right) / 2;
	t2 middle = arr[index];
	if (left == index) {
		if (arr[left + 1] == element)
			return arr + (left + 1);
		else if (arr[left] == element)
			return arr + (left);
		else
			return NULL;
	}
	if (middle == element)
		return arr + index;
	else if (middle > element)
		find(arr, element, left, index);
	else find(arr, element, index, right);
}
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
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n = 1000000;
	int *arr = new int[n];//создаем динамический массив

	for (int i(0); i < n; i++) {
		arr[i] = i+1;//в каждую яйчейку записываем i+1 число
	}
	double t1 = clock();//создаем измеритель времени до функции
	QuickSort(arr, 0, n - 1);//вызываем функцию сортировки
	double t2 = clock() - t1;//создаем измеритель времени после функции
	cout << t2 / CLOCKS_PER_SEC;//выводим время в секундах
	double t3 = clock();//создаем измеритель времени до функции
	int *p = find(arr, -1, 0, n);//вызываем функцию поиска числа. 1 параметр это массив. 2 искомое число. 3 от 0 яйчейки. 4 до n яйчейки
	if (p == NULL) {
		cout << "\nчисло не найдено\n";
	}
	else {
		cout << endl << *p << endl;//выводим искомое число
	}
	double t4 = clock() - t1;//создаем измеритель времени после функции
	cout << t4 / CLOCKS_PER_SEC;//выводим время в секундах
	delete[] arr;//очистка массива
	_getch();
	return 0;
}