#include <stdio.h>

int main(void){


int rows[15],cols[15];
int matr[15][15];


int sum_for_row=0;
for (int i=0;i<15;i++){
	sum_for_row=0;
	for (int j=0;j<15;j++){
		int num;
		scanf("%d ",&num);
		sum_for_row+=num;
		matr[i][j]=num;
		//printf("%d \n", matr[i][j]);
	}
	rows[i]=sum_for_row;
}

int sum_for_col=0;
for (int i=0;i<15;i++){//col
	sum_for_col=0;
	for (int j=0;j<15;j++){//row
		sum_for_col+=matr[j][i];

	}
	cols[i]=sum_for_col;
}	

for (int i=0; i<15;i++){//col
	for (int j=0;j<15;j++){//row
		if (rows[j]==cols[i]){
			printf("%d %d \n",j,i);}
}
}
for (int i=0; i<15;i++){//row
	for (int j=0;j<15;j++){//row
		if (rows[i]==rows[j] & i>j){
			printf("%d %d \n",j,i);}
}
}
for (int i=0; i<15;i++){//col
	for (int j=0;j<15;j++){//col
		if (cols[i]==cols[j] & i>j){
			printf("%d %d \n",j,i);}
}
}
}
