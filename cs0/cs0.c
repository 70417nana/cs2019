#include<stdio.h>

int main(){
	int row, col;	//col:�� row:�s

	printf("1���\n");
/**
*	1. �s���Ƃɗ��for���[�v���܂킷
*	2. �s�~��̌v�Z���ʂ��o�͂���
**/
	for(row=1;row<10;row++){
		for(col=1;col<row+1;col++){
			printf("%3d",row*col);
		}
	printf("\n");
	}

	printf("2���\n");
/**
*	1. �s���Ƃɗ��for���[�v���܂킷
*	2. �s�̒l����̒l�ȉ��Ȃ�s�~��̌v�Z���ʂ��o�͂���
*	   �����łȂ��Ȃ甼�p�X�y�[�X��3�o�͂���
**/
	for(row=1;row<10;row++){
		for(col=1;col<10;col++){
			if(row<=col){
				printf("%3d",row*col);
			}else{
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
}