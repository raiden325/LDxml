#include "stdafx.h"

/* 関数名：LDFinder                                       */
/* ファイル内の<LD>を検索する                             */
/* 戻り値：                                               */
/* 0：文字列発見できなかった                              */
/* 1：文字列を発見した                                    */
int fg_LDFinder(char *buff)
{
	if (strstr(buff, "<LD>") != NULL)
	{
		//文字列発見
		return 4;
	}
	//文字列未発見
	return 5;
}

/* 関数名：StringFinder                                   */
/* 文字列を検索する                                       */
/* 戻り値：                                               */
/*  0:ファイルを開けた                                    */
int fg_StringFinder(char *buff)
{
	return 0;
}