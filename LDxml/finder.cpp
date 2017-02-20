#include "stdafx.h"

/* �֐����FLDFinder                                       */
/* �t�@�C������<LD>����������                             */
/* �߂�l�F                                               */
/* 4�F������𔭌�����                                    */
/* 5�F�����񔭌��ł��Ȃ�����                              */
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
/*  4:������𔭌�����                                    */
/*  6:�u���b�N�̏I���𔭌�����                          */
/*  7:�u���b�N�̏I���𔭌��������Ή�����n�܂肪�Ȃ�    */
int fg_StringFinder(char *buff, _gPairData *BlkData, int *BlkCnt, int LineCnt)
{
	int i = 0;				//buff�J�E���^
	int n = 0;				//String�J�E���^
	bool StrFlag = false;	//������J�n�t���O
	char String[20];		//������o�b�t�@
	bool SlFlag = false;	//�u���b�N�I���t���O

	//String�z��N���A
	memset(String, '\0', 20);

	while (*(buff + i) != NULL)
	{
		if (StrFlag == false)
		{
			// < ���n�܂�O
			switch (*(buff + i))
			{
			case '/':
				//�X���b�V��
				break;
			case '\t':
				//�^�u����
				break;
			case ' ':
				//��
				break;
			case '<':
				//���̕�������J�E���g����
				StrFlag = true;
				break;
			default:
				break;
			}
		}
		else {
			// < ���n�܂�������
			switch (*(buff + i))
			{
			case '/':
				//�X���b�V��
				SlFlag = true;
				break;
			case '\t':
				//�^�u����
				StrFlag = false;
				break;
			case ' ':
				//��
				StrFlag = false;
				break;
			case '>':
				//�J�E���g�I���
				StrFlag = false;
				break;
			default:
				if (SlFlag == false)
				{
					//�u���b�N�̎n�܂�
					String[n] = *(buff + i);
					++n;
				}
				else {
					//�u���b�N�̏I���
					String[n] = *(buff + i);
					++n;
				}
				break;
			}
		}
		//�J�E���^�@�C���N�������g
		++i;
	}

	if (SlFlag == false)
	{
		//�u���b�N�̎n�܂�
		printf("Find string:%s\n", String);
		//������R�s�[
		strcpy_s(BlkData[*BlkCnt].Element, String);
		//�s���i�[����
		BlkData[*BlkCnt].StartLine = LineCnt;
		//�v�f��i�߂�
		*BlkCnt = *BlkCnt + 1;
		return 4;
	}
	else {
		//�u���b�N�̏I���
		int i;
		//�\���̗̂v�f�Ɣ�r����
		for(i = 0; i < *BlkCnt; i++)
		{
			if(strcmp(BlkData[i].Element,String) == 0)
			{
				//��v
				//�s���i�[����
				BlkData[i].EndLine = LineCnt;
				return 6;
			}
		}
		//�Ή�����u���b�N�Ȃ�
		return 7;
	}
}