#include "stdafx.h"

/* �֐����FLDFinder                                       */
/* �t�@�C������<LD>����������                             */
/* �߂�l�F                                               */
/* 0�F�����񔭌��ł��Ȃ�����                              */
/* 1�F������𔭌�����                                    */
int fg_LDFinder(char *buff)
{
	if (strstr(buff, "<LD>") != NULL)
	{
		//�����񔭌�
		return 4;
	}
	//�����񖢔���
	return 5;
}

/* �֐����FStringFinder                                   */
/* ���������������                                       */
/* �߂�l�F                                               */
/*  0:�t�@�C�����J����                                    */
int fg_StringFinder(char *buff)
{
	int i = 0;			//buff�J�E���^
	int n = 0;			//String�J�E���^
	int StrFlag = 0;	//������J�n�t���O
	char String[20];	//������o�b�t�@

	//String�z��N���A
	memset(String, '\0', 20);

	while (*(buff + i) != NULL)
	{
		if (StrFlag == 0)
		{
			// < ���n�܂�O
			switch (*(buff + i))
			{
			case '\t':
				//�^�u����
				break;
			case ' ':
				//��
				break;
			case '<':
				//���̕�������J�E���g����
				StrFlag = 1;
				break;
			default:
				break;
			}
		}
		else {
			// < ���n�܂�������
			switch (*(buff + i))
			{
			case '\t':
				//�^�u����
				StrFlag = 0;
				break;
			case ' ':
				//��
				StrFlag = 0;
				break;
			case '>':
				//�J�E���g�I���
				StrFlag = 0;
				break;
			default:
				String[n] = *(buff + i);
				++n;
				break;
			}
		}
		//�J�E���^�@�C���N�������g
		++i;
	}
	printf("Find string:%s\n", String);
	return 0;
}