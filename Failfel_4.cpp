#include <stdio.h>
#include <locale>
#include <malloc.h>

//Функция вставки
void insert(int* arr, int num, int len) {
	
	//Если элемент самый большой
	if(num > arr[len-1]) arr[len] = num;
	
	//Если самый маленький
	else if(num < arr[0]) {
		for(int i = len; i > 0; i--)
			arr[i] = arr[i-1];
		arr[0] = num;
	}
	
	//Сравниваем с каждым элементом и вставляем слева
	else {
		int j;
		for(int i = 1; i < len; i++)
			if(num < arr[i]) {
				for(j = len; j > i; j--)
					arr[j] = arr[j-1];
				arr[j] = num;
				return;
			}	
	}
		
}

int main() {
	
	setlocale( LC_ALL,"Russian" );
	
	//МЕНЯТЬ ДАННЫЕ ТОЛЬКО ЗДЕСЬ
	/////////////////////////////////////////////////////////
	int arr1[] = {-1,1,2,5,8};
	int arr2[] = {0,3,4,6,9};
    /////////////////////////////////////////////////////////
    
    //Динамически определяем длины массивов
	const int N1 = sizeof(arr1)/sizeof(arr1[0]);
	const int N2 = sizeof(arr2)/sizeof(arr2[0]);
	
	//Выводим массивы на экран
	printf("Первый массив: [ ");
	for(int i = 0; i < N1; i++)
		printf("%i ",arr1[i]);
	printf("]\n");
	
	printf("Второй массив: [ ");
	for(int i = 0; i < N2; i++)
		printf("%i ",arr2[i]);
	printf("]\n");
	
	//Выделим память под результат
	int* res = (int*) malloc((N1+N2)*sizeof(int));
	
	//Скопируем в результат элементы первого массива
	for(int i = 0; i < N1; i++)
		res[i] = arr1[i];
		

	//Вставляем элементы второго массива в результат
	for(int i = 0,len = N1; i < N2; i++,len++)
		insert(res, arr2[i], len);
    
    //Выводим ответ
    printf("Результат: [ ");
    for(int i = 0; i < N1+N2; i++)
    	printf("%i ",res[i]);
    printf("]");
}
