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
	return 0;
}