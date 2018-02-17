#include <stdio.h>
#include <locale>
#include <malloc.h>

//Проверяет, есть ли уже такое число в массиве
int isAlreadyExists(int* res, int num, int len) {
	
	for(int i = 0; i < len; i++)
		if(res[i] == num) return 1;
		
	return 0;
}

int main() {
	
	setlocale( LC_ALL,"Russian" );
	
	//МЕНЯТЬ ДАННЫЕ ТОЛЬКО ЗДЕСЬ
	/////////////////////////////////////////////////////////
	int arr[] = {1,4,2,7,1,2,5,7,2,4,4};
    /////////////////////////////////////////////////////////
    
	//Динамически определяем длину массива
	const int N = sizeof(arr)/sizeof(arr[0]);
	
	//Выделяем память под результирующий массив
	int* res = (int*)malloc(N*sizeof(int));
	
	//Выводим начальный массив
	printf("Начальный массив: [");
	for(int i = 0; i < N; i++)
		printf("%i ", arr[i]);
	printf("]\n");
	
	//Фильтруем уникальные элементы
	int j = 0;
	for(int i = 0; i < N; i++) {
		if(!isAlreadyExists(res,arr[i],j))
			res[j++] = arr[i];
	}
	
	//Выводим результат
	printf("Результат: [");
	for(int i = 0; i < j; i++)
		printf("%i ", res[i]);
	printf("]");
}
