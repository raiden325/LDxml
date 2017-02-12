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
	int i = 0;			//buffカウンタ
	int n = 0;			//Stringカウンタ
	int StrFlag = 0;	//文字列開始フラグ
	char String[20];	//文字列バッファ

	//String配列クリア
	memset(String, '\0', 20);

	while (*(buff + i) != NULL)
	{
		if (StrFlag == 0)
		{
			// < が始まる前
			switch (*(buff + i))
			{
			case '\t':
				//タブ文字
				break;
			case ' ':
				//空白
				break;
			case '<':
				//次の文字からカウントする
				StrFlag = 1;
				break;
			default:
				break;
			}
		}
		else {
			// < が始まったあと
			switch (*(buff + i))
			{
			case '\t':
				//タブ文字
				StrFlag = 0;
				break;
			case ' ':
				//空白
				StrFlag = 0;
				break;
			case '>':
				//カウント終わり
				StrFlag = 0;
				break;
			default:
				String[n] = *(buff + i);
				++n;
				break;
			}
		}
		//カウンタ　インクリメント
		++i;
	}
	printf("Find string:%s\n", String);
	return 0;
}