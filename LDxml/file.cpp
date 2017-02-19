#include "stdafx.h"

//�t�@�C���X�R�[�v�֐��̐錾
int fs_CRLFDel(char *buff);

/* �֐����FOpenFile                                       */
/* �t�@�C�����J��                                         */
/* �߂�l�F                                               */
/*  0:�t�@�C�����J����                                    */
/*  1:�t�@�C�����J���Ȃ�����                              */
/*  2:�t�@�C���̍Ō�܂œǂ�                            */
/*  3:�ُ�I��                                            */
int fg_OpenFile(char *FileName, char *buff, FILE **ReadFile)
{
	FILE *temp = NULL;	//�ꎞ�I�ȃt�@�C���|�C���^
	errno_t err;		//�t�@�C���I�[�v���߂�l�i�[�p�ϐ�

	if (*ReadFile == NULL)
	{
		//�t�@�C���|�C���^���k���Ȃ珉��I�[�v��
		if ((err = fopen_s(ReadFile, FileName, "r")) == 0)
		{
			//�t�@�C�����J����
			if (fgets(buff, 256, *ReadFile) != NULL)
			{
				//printf("file pointer1:%p\n", (void*)ReadFile);
				//��s�ǂݍ���
				fs_CRLFDel(buff);
				return 0;
			}
			else {
				//�t�@�C���̍Ō�܂œǂ�
				return 2;
			}
		}
		else {
			//�t�@�C�����J���Ȃ�����
			printf("Can't open file(%s).\n", FileName);
			return 1;
		}
	}
	else {
		//�t�@�C�����J����
		if (fgets(buff, 256, *ReadFile) != NULL)
		{
			//printf("file pointer2:%p\n", (void*)ReadFile);
			//��s�ǂݍ���
			fs_CRLFDel(buff);
			return 0;
		}
		else {
			//�t�@�C���̍Ō�܂œǂ�
			return 2;
		}
	}
	return 3;
}

/* �֐����Ffg_MakeFileList                                */
/* �t�@�C�����J��                                         */
/* �߂�l�F                                               */
/*  0:�t�@�C�����J����                                    */
int fg_MakeFileList()
{
	//�t�@�C���ꗗ�쐬�o�b�`�t�@�C�������s����
	system("MakePathlist.bat");
	return 0;
}

/* �֐����Ffs_CRLFDel                                     */
/* �t�@�C�����J��                                         */
/* �߂�l�F                                               */
/*  0:�t�@�C�����J����                                    */
int fs_CRLFDel(char *buff)
{
	int i;
	for (i = 0; i < strlen(buff); i++)
	{
		//������̒����������[�v
		if (*(buff + i) == '\n')
		{
			//CRLF�������NULL�ɂ���
			*(buff + i) = '\0';
			return 0;
		}
	}
	return 0;
}
