#include <stdio.h>
#include <locale>
#include <malloc.h>

//Ïðîâåðÿåò, åñòü ëè óæå òàêîå ÷èñëî â ìàññèâå
int isAlreadyExists(int* res, int num, int len) {
	
	for(int i = 0; i < len; i++)
		if(res[i] == num) return 1;
		
	return 0;
}

int main() {
	
	setlocale( LC_ALL,"Russian" );
	
	//ÌÅÍßÒÜ ÄÀÍÍÛÅ ÒÎËÜÊÎ ÇÄÅÑÜ
	/////////////////////////////////////////////////////////
	int arr[] = {1,4,2,7,1,2,5,7,2,4,4};
    /////////////////////////////////////////////////////////
    
	//Äèíàìè÷åñêè îïðåäåëÿåì äëèíó ìàññèâà
	const int N = sizeof(arr) / sizeof(arr[0]);
	
	//Âûäåëÿåì ïàìÿòü ïîä ðåçóëüòèðóþùèé ìàññèâ
	int* res = (int*)malloc(N*sizeof(int));
	
	//Âûâîäèì íà÷àëüíûé ìàññèâ
	printf("Íà÷àëüíûé ìàññèâ: [");
	for(int i = 0; i < N; i++)
		printf("%i ", arr[i]);
	printf("]\n");
	
	//Ôèëüòðóåì óíèêàëüíûå ýëåìåíòû
	int j = 0;
	for(int i = 0; i < N; i++) {
		if(!isAlreadyExists(res,arr[i],j))
			res[j++] = arr[i];
	}
	
	//Âûâîäèì ðåçóëüòàò
	printf("Ðåçóëüòàò: [");
	for(int i = 0; i < j; i++)
		printf("%i ", res[i]);
	printf("]");
}
