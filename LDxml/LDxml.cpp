/* IEC63��xml�t�@�C������͂���v���O���� */
#include "stdafx.h"

int ErrorCheck(int funcRtn)
{
	switch (funcRtn)
	{
	case 0:
		//�t�@�C�����J�����@���s
		break;
	case 1:
		//�t�@�C���̍Ō�܂œǂ�
		break;
	case 2:
		//�ُ�I��
		exit(1);
	case -1:
		//�t�@�C�����J���Ȃ�����
		exit(1);
	default:
		break;
	}
	return 0;
}

int main()
{
	char buff[256];				//��s�o�b�t�@
	char pbuff[256];			//�t�@�C���p�X�p�o�b�t�@
	FILE *ReadFile = NULL;		//�t�@�C���ǂݍ��݃|�C���^
	FILE *pReadFile = NULL;		//�t�@�C���p�X�ꗗ�ǂݍ��݃|�C���^
	int funcRtn;				//�֐��߂�l�i�[�ϐ�

	//�t�@�C���ꗗ���쐬����
	fg_MakeFileList();

	//�t�@�C���p�X�ꗗ���J��
	funcRtn = fg_OpenFile("pathlist.txt", pbuff, pReadFile);
	ErrorCheck(funcRtn);
	//�t�@�C�����J��
	funcRtn = fg_OpenFile(pbuff, buff, ReadFile);
	//ErrorCheck(funcRtn);
	//�f�o�b�O
	printf("%s\n", buff);
	//<LD>����

	//���_�[����͂���

	//buff�N���A
	memset(buff, '\0', 256);

	memset(pbuff, '\0', 256);
	getchar();

    return 0;
}
