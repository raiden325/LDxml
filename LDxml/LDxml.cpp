/* IEC63��xml�t�@�C������͂���v���O���� */
#include "stdafx.h"

//�t�@�C���X�R�[�v�֐��̐錾
int fs_ErrorCheck(int funcRtn);

//�\���̂̐錾
extern struct _gPairData BlkData;

/* �֐����Ffs_ErrorCheck                                  */
/* �߂�l���Ƃɏ����𕪂���                               */
/* �߂�l�F                                               */
/*  0:����I��                                            */
int fs_ErrorCheck(int funcRtn)
{
	switch (funcRtn)
	{
	case 0:
		//�t�@�C�����J�����@���s
		break;
	case 1:
		//�t�@�C�����J���Ȃ�����
		exit(1);
	case 2:
		//�t�@�C���̍Ō�܂œǂ�
		//printf("�t�@�C���̍Ō�܂œǂݏI���܂����B\n");
		break;
	case 3:
		//�ُ�I��
		exit(1);
	case 4:
		//������𔭌�����
		//printf("������𔭌����܂����B\n");
		break;
	case 5:
		//�����񖢔���
		//printf("�����񂪌�����܂���B\n");
		break;
	case  6:
		//�u���b�N�̏I���𔭌�
		printf("�u���b�N�̏I���𔭌����܂����B\n");
		break;
	case 7:
		//�u���b�N�̏I���ƈ�v����n�܂肪������Ȃ�����
		printf("�u���b�N�̏I���𔭌����܂������A�Ή�����u���b�N�̎n�܂肪������܂���ł����B\n");
		break;
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
	_gPairData BlkData[1000];	//�u���b�N�̃f�[�^�\���̔z��
	int BlkCnt;					//�u���b�N�̃f�[�^�\���̔z��̗v�f�J�E���^
	int LineCnt;				//�s�J�E���^
	bool LDFlag;				//<LD>�����t���O

	//�t�@�C���ꗗ���쐬����
	fg_MakeFileList();

	do
	{
		//�ϐ��̏�����
		BlkCnt = 0;
		LineCnt = 0;
		LDFlag = false;
		//�\���̂̏�����
		memset(BlkData, '\0', sizeof(_gPairData)*1000);
		//�o�b�t�@�̃N���A
		memset(pbuff, '\0', 256);
		//�t�@�C���p�X�ꗗ���J��
		funcRtn = fg_OpenFile("pathlist.txt", pbuff, &pReadFile);
		//�߂�l�`�F�b�N
		fs_ErrorCheck(funcRtn);
		if (funcRtn == 2)
		{
			//�t�@�C���̍Ō�܂œǂ�
			break;
		}
		do
		{
			//buff�N���A
			memset(buff, '\0', 256);
			//�t�@�C�����J��
			funcRtn = fg_OpenFile(pbuff, buff, &ReadFile);
			//�߂�l�`�F�b�N
			fs_ErrorCheck(funcRtn);
			//�f�o�b�O
			//printf("%s\n", buff);
			if (funcRtn == 2)
			{
				//�t�@�C���̍Ō�܂œǂ�
				break;
			}

			if (LDFlag == false)
			{
				//<LD>����
				funcRtn = fg_LDFinder(buff);
				//�߂�l�`�F�b�N
				fs_ErrorCheck(funcRtn);
				if (funcRtn == 4)
				{
					//<LD>�𔭌�����
					strcpy_s(BlkData[BlkCnt].Element, "LD");
					BlkData[BlkCnt].StartLine = LineCnt;
					BlkCnt++;
					break;
				}
			}
			else {
				//������̌���
				fg_StringFinder(buff, BlkData, &BlkCnt, LineCnt);
				//�߂�l�`�F�b�N
				fs_ErrorCheck(funcRtn);
				if (funcRtn == 6)
				{
					//�u���b�N�̏I���𔭌�����

					break;
				}
			}
			//debug
			printf("Element(%d):%s\n", BlkCnt, BlkData[BlkCnt - 1].Element);
			LineCnt++;

		} while (buff != NULL);
		//�t�@�C�������
		fclose(ReadFile);

	} while (pbuff != NULL);
	//�t�@�C�������
	fclose(pReadFile);
	printf("End\n");
	getchar();
	return 0;
}
