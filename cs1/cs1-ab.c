#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @func	getPrimeNum
 * @brief	�G���g�X�e�l�X��⿂Ŏ��R��N�܂ł̑f���𔻒�
 *			�f���̗v�f�ԍ������v�f�ɂ�0, �������ɂ�1���i�[
 * @param	���R��N
 * @param	�z����m�ۂ��邽�߂̐擪�A�h���X
 * @return	�Ȃ�
 */
void getPrimeNum(int N, bool *prime)
{
	printf("�G���g�X�e�l�X���\n");
	int i, j, k;
	
	//�z��̗v�f���𓮓I�Ɋm�ۂ���
	prime = (bool*)calloc(N + 1, sizeof(bool*));
	
	if(N<1)
	{
		printf("�f������ɂ͎��R������͂��Ă�������\n");
	} else {
		//0��1�͍������Ȃ̂�1�Ƃ���
		prime[0] = 1;
		prime[1] = 1;
		
		//�G���g�X�e�l�X���
		for (i=2;i*i<=N;++i) 
		{
			if (prime[i]) continue;
			for (j=i*i; j<=N; j+=i)
			{
			    prime[j] = 1;
			}
		}
		
		//���ʏo��
		for (k=0;k<=N;++k) printf("%2d",prime[k]);
		printf("\n");
	}
}

/**
 * @func	getDisjoint
 * @brief	��]�⊄��Z��p���Ȃ��Ō݂��ɑf�𔻒肷��
 *			�݂��ɑf�ƂȂ�v�f�ԍ��̗v�f�ɂ�1, ����ȊO��0���i�[
 * @param	���R��N
 * @param	�񎟌��z����m�ۂ��邽�߂̐擪�A�h���X
 * @return	�Ȃ�
 */
void getDisjoint(int N, bool **tmp)
{
    printf("�݂��ɑf\n");
    int i, j, k;
    
    //�z��̗v�f�������N�ɑ΂��ē��I�Ɋm�ۂ���(C�����߂���)
    tmp = (bool **)malloc((N + 1)*sizeof(bool *));
    for (i = 0; i <= N + 1; i++)
    {
        tmp[i] = (bool *)malloc((N + 1)*sizeof(bool));
    }
    //�z���1�ŏ���������(������C++�׋����悤�ƌ���)
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            tmp[i][j] = true;
        }
    }
    
    /* 	1�͂ǂ�Ȑ����Ƒg��ł��݂��ɑf������2����l����
     * 	�݂��ɑf�ƂȂ�g�̐����{�݂͌��ɑf�ł͂Ȃ�
     * 	k��N/j�ȉ�(k*j<=N)�ƂȂ鐮���{�ɂ��čl����΂悢
     */
    for (i = 1; i <= N; ++i)
    {
        for (j = i; j <= N; ++j)
        {
            if (!tmp[i][j])
            {
                continue;	//����for���͔�΂��Ă��̑O��for���ɖ߂�
            }
            for (k = 2; j * k <= N; ++k)
            {
            	//�ő���񐔂�i��j�̏����Ɉˑ����Ȃ�
                tmp[i * k][j * k] = 0;
                tmp[j * k][i * k] = 0;
            }
        }
    }
    
    //�o��
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            printf("%2d", tmp[i][j]);
        }
        printf("\n");
    }
}

//main�֐�
int main(void){
  	int N;
	bool *a;
	bool **b;
	
	scanf("%d", &N);
	
	getPrimeNum(N, a);	//�G���g�X�e�l�X���
    getDisjoint(N, b);	//�݂��ɑf
    return 0;
}
