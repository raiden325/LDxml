#include "stdafx.h"

/* �֐����FOpenFile                                       */
/* �t�@�C�����J��                                         */
/* �߂�l�F                                               */
/*  0:�t�@�C�����J����                                    */
/* -1:�t�@�C�����J���Ȃ�����                              */
/*  1:�t�@�C���̍Ō�܂œǂ�                            */
/*  2:�ُ�I��                                            */
int fg_OpenFile(char *FileName, char *buff, FILE *ReadFile)
{
	errno_t err;	//�t�@�C���I�[�v���߂�l�i�[�p�ϐ�
	char *next_token = NULL;	//strtok_s�p

	if (ReadFile == NULL)
	{
		//�t�@�C���|�C���^���k���Ȃ珉��I�[�v��
		if ((err = fopen_s(&ReadFile, FileName, "r")) == 0)
		{
			//�t�@�C�����J����
			if (fgets(buff, sizeof(char) * 256, ReadFile) != NULL)
			{
				//��s�ǂݍ���
				strtok_s(buff, "\n\0", &next_token);

				return 0;
			}
			else {
				//�t�@�C���̍Ō�܂œǂ�
				return 1;
			}
		}
		else {
			//�t�@�C�����J���Ȃ�����
			printf("Can't open file(%s).\n", FileName);
			return -1;
		}
	}
	else {
		//�t�@�C�����J����
		if (fgets(buff, sizeof(char) * 256, ReadFile) != NULL)
		{
			//��s�ǂݍ���
			return 0;
		}
		else {
			//�t�@�C���̍Ō�܂œǂ�
			return 1;
		}
	}
	return 2;
}

int fg_MakeFileList()
{
	//�t�@�C���ꗗ�쐬�o�b�`�t�@�C�������s����
	system("MakePathlist.bat");
	return 0;
}