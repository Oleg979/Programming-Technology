#include <stdio.h>
#include <locale>
#include <malloc.h>

//������� �������
void insert(int* arr, int num, int len) {
	
	//���� ������� ����� �������
	if(num > arr[len-1]) arr[len] = num;
	
	//���� ����� ���������
	else if(num < arr[0]) {
		for(int i = len; i > 0; i--)
			arr[i] = arr[i-1];
		arr[0] = num;
	}
	
	//���������� � ������ ��������� � ��������� �����
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
	
	//������ ������ ������ �����
	/////////////////////////////////////////////////////////
	int arr1[] = {-1,1,2,5,8};
	int arr2[] = {0,3,4,6,9};
    /////////////////////////////////////////////////////////
    
    //����������� ���������� ����� ��������
	const int N1 = sizeof(arr1)/sizeof(arr1[0]);
	const int N2 = sizeof(arr2)/sizeof(arr2[0]);
	
	//������� ������� �� �����
	printf("������ ������: [ ");
	for(int i = 0; i < N1; i++)
		printf("%i ",arr1[i]);
	printf("]\n");
	
	printf("������ ������: [ ");
	for(int i = 0; i < N2; i++)
		printf("%i ",arr2[i]);
	printf("]\n");
	
	//������� ������ ��� ���������
	int* res = (int*) malloc((N1+N2)*sizeof(int));
	
	//��������� � ��������� �������� ������� �������
	for(int i = 0; i < N1; i++)
		res[i] = arr1[i];
		

	//��������� �������� ������� ������� � ���������
	for(int i = 0,len = N1; i < N2; i++,len++)
		insert(res, arr2[i], len);
    
    //������� �����
    printf("���������: [ ");
    for(int i = 0; i < N1+N2; i++)
    	printf("%i ",res[i]);
    printf("]");
}
