#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 80;
bool hashTable[maxn] = { false };

int gethash(char c){
	if ((c > 'A') && (c < 'Z')){
		return (c - 'A' + 10);
	}
	else if ((c>'a') && (c < 'z')){
		return ((c - 'a') + 36);
	}
	else{
		return (c - '0');
	}
}
char P[maxn];
void Generate(char* target, int index,int len){
	if (index == len ){
		P[index] = '\0';
		printf("%s\n", P);
	}
	else{
		for (int j = 0; j < len; j++){
			int x = gethash(target[j]);
			if (hashTable[x] == false){
				hashTable[x] = true;
				P[index] = target[j];
				Generate(target,index + 1,len);
				hashTable[x] = false;
			}
		}
	}
	
};
//下面这个是用于生成整型数组的全排列
//void Generate(int index){
//	if (index == n + 1){
//		for (int i = 1; i <= n; i++){
//			printf("%c", P[i]);
//		}
//		printf("\n");
//	}
//	else{
//		for (int j = 1; j <= n; j++){
//			if (hashTable[j] == false){
//				hashTable[j] = true;
//				P[index] = j;
//				Generate(index + 1);
//				hashTable[j] = false;
//			}
//		}
//	}
//};
int main(){
	char tar[20];
	scanf("%s", tar);
	int len = strlen(tar);
	sort(tar, tar + len);
	Generate(tar,0,len);
	system("pause");
	return 0;
}