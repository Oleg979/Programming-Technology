#include <math.h>
#include <stdio.h>
#include <locale>

//������ ������ ������ �����
//��������� ������ ���������///////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int X[] = {0,4,0,4,2,5};
const int Y[] = {0,0,4,4,2,1};
//��������� ������ ���������///////////////////////////////////////////////////////////////////////////////////////////////////////////////


//����������� ���������� ���������� �����
const int N = sizeof(X) / sizeof(X[0]);

//������� ��� �������������� �����
void printLine() {
	printf("\n\n********************************\n\n");
}

//������� ��� ���������� ���������� ����� �������
double findSpace(int n1, int n2) {
	double space = sqrt( 
			(X[n1] - X[n2])*(X[n1] - X[n2]) + 
			(Y[n1] - Y[n2])*(Y[n1] - Y[n2])
			);
	return space;	
}

//������� ��� ���������� ������� ������������
double findTriangleSquare(int n1, int n2, int n3) {
	int p11 = X[n1] - X[n3];
	int p12 = Y[n1] - Y[n3];
	int p21 = X[n2] - X[n3];
	int p22 = Y[n2] - Y[n3];
	
	double res = abs((p11*p22 - p12*p21));
	return res/2;
}


//������� ���  �������� �� ������� ����� � ������ ���������� �������
int isSquare(int n1, int n2, int n3, int n4) {
	
	double X12 = X[n2] - X[n1];
	double Y12 = Y[n2] - Y[n1];
	double X43 = X[n3] - X[n4];
	double Y43 = Y[n3] - Y[n4];
	
	//��������� �� �������������� ���� ���� ������(�������� 0/0)
	if (!((X43==0.0 && X12==0.0)||(Y43==0.0 && Y12==0.0)))
		if (abs(X43/X12) != abs(Y43/Y12)) return 0;
	
	double X23 = X[n3] - X[n2];
	double Y23 = Y[n3] - Y[n2];
	double X14 = X[n4] - X[n1];
	double Y14 = Y[n4] - Y[n1];
	
	//��������� �� �������������� ������ ���� ������(�������� 0/0)
	if (!((X14==0.0 && X23==0.0)||(Y14==0.0 && Y23==0.0)))
    	if (abs(X14/X23) != abs(Y14/Y23)) return 0;
	
	//��������� �� �������������� ���� �������� ������
    if((X12*X23 + Y12*Y23) != 0) return 0;
	if(findSpace(n1,n2) != findSpace(n2,n3)) return 0;
	
	return 1;	
}

//������� ���  �������� ��������� ��������� �����
//���� ���� �� � ����� ������� ��� ����� ���� �������, ������
//������� true
int isGroupSquare(int n1, int n2, int n3, int n4) {
	int arr[] = {n1, n2, n3, n4};
	for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if (j==i) continue;
				for(int k = 0; k < 4; k++)  {
					if(k==j || k==i) continue;
					for(int m = 0; m < 4; m++ ) {
						if(m==j || m==i || m==k) continue;
						if(isSquare(arr[i],arr[j],arr[k],arr[m])) {
							return 1;
						}		
					}	
				}
			}
		}
		
	return 0;
	
}


//������� ��� ���������� ������� ��������
//����� ���������� ���, ��� n1 � n2 �� ����� ������������ ������� ��������
//����� ����� ����� ������ ���� �����
double findSquareSquare(int n1, int n2, int n3, int n4) {
	int sq1 = findSpace(n1,n2)*findSpace(n1,n2);
	int sq2 = findSpace(n2,n3)*findSpace(n2,n3);
	return sq1 > sq2 ? sq2 : sq1;
}

int main() {

setlocale( LC_ALL,"Russian" );

//���� ����� � ������������ �����������//////////////////////////////////////////////////////////////////////////////////////////////////////
printLine();

	double space;
	double max = 0;
	
	//���� ����������� ��������� ����������
	for(int i = 0; i < N-1; i++) {
		for(int j = i+1; j < N; j++) {
			space = findSpace(j,i);
			if(space > max) max = space;
			}
		}
		
	printf("������������ ���������� = %lf. ����� � ����� �����������:", max);
	
	//������� ��� ����� � ������������ �����������
	for(int i = 0; i < N-1; i++)
		for(int j = i+1; j < N; j++)
			if(findSpace(j,i) == max) 
				printf("\n[%i][%i] � [%i][%i]", X[j], Y[j], X[i], Y[i]);
				
//���� ������������ � ������������ ��������///////////////////////////////////////////////////////////////////////////////////////////////////////// 					
printLine();
	
	double square;
	max = 0;
	
	//���� ����������� ��������� �������
	for(int i = 0; i < N-2; i++) {
		for(int j = i+1; j < N-1; j++) {
			for(int k = j+1; k < N; k++) {
				square = findTriangleSquare(i,j,k);
				if(square > max) max = square;
			}
		}
	}
	
	printf("������������ ������� ������������ =  %lf. �����, ������ ����� �������:", max); 
	
	//������� ��� ����� ������ ����� �����������
	for(int i = 0; i < N-2; i++) 
		for(int j = i+1; j < N-1; j++) 
			for(int k = j+1; k < N; k++) 
				if(findTriangleSquare(i,j,k) == max)
					printf("\n[%i][%i], [%i][%i] � [%i][%i]", 
					X[j], Y[j], X[i], Y[i], X[k], Y[k]);
	
//���� �������� � ������������ ��������///////////////////////////////////////////////////////////////////////////////////////////////////////// 					
printLine();

	square = 0;
	max = 0;
	
	
	//���� ����������� ��������� �������
	for(int i = 0; i < N-3; i++) {
		for(int j = i+1; j < N-2; j++) {
			for(int k = j+1; k < N-1; k++) {
				for(int m = k+1; m < N; m++ ) {
					if(isGroupSquare(i,j,k,m)) {
						square = findSquareSquare(i,j,k,m);
						if(square > max) max = square;

					}
				}
			}
		}
	}
	
	printf("������������ ������� �������� = %lf. �����, ������ ����� �������:", max); 
	
	//������� ��� ����� ������ ����� �������
	for(int i = 0; i < N-3; i++) {
		for(int j = i+1; j < N-2; j++) {
			for(int k = j+1; k < N-1; k++) {
				for(int m = k+1; m < N; m++ ) {
					if(isGroupSquare(i,j,k,m)) {
						square = findSquareSquare(i,j,k,m);
						if(square == max) 
						printf("\n[%i][%i], [%i][%i], [%i][%i], [%i][%i]", 
						X[j], Y[j], X[i], Y[i], X[k], Y[k],
						X[m], Y[m]);
					}
				}
			}
		}
	}
	
	
//���� �������� � ������������ ��������/////////////////////////////////////////////////////////////////////////////////////////////////////////		
printLine();
}

	
	

	
	
	
	
