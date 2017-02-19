#include "stdafx.h"

/* 関数名：LDFinder                                       */
/* ファイル内の<LD>を検索する                             */
/* 戻り値：                                               */
/* 4：文字列を発見した                                    */
/* 5：文字列発見できなかった                              */
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
/*  4:文字列を発見した                                    */
/*  6:ブロックの終わりを発見した                          */
int fg_StringFinder(char *buff, _gPairData *BlkData, int *BlkCnt, int LineCnt)
{
	int i = 0;				//buffカウンタ
	int n = 0;				//Stringカウンタ
	bool StrFlag = false;	//文字列開始フラグ
	char String[20];		//文字列バッファ
	bool SlFlag = false;	//ブロック終了フラグ

	//String配列クリア
	memset(String, '\0', 20);

	while (*(buff + i) != NULL)
	{
		if (StrFlag == false)
		{
			// < が始まる前
			switch (*(buff + i))
			{
			case '/':
				//スラッシュ
				break;
			case '\t':
				//タブ文字
				break;
			case ' ':
				//空白
				break;
			case '<':
				//次の文字からカウントする
				StrFlag = true;
				break;
			default:
				break;
			}
		}
		else {
			// < が始まったあと
			switch (*(buff + i))
			{
			case '/':
				//スラッシュ
				SlFlag = true;
				break;
			case '\t':
				//タブ文字
				StrFlag = false;
				break;
			case ' ':
				//空白
				StrFlag = false;
				break;
			case '>':
				//カウント終わり
				StrFlag = false;
				break;
			default:
				if (SlFlag == false)
				{
					//ブロックの始まり
					String[n] = *(buff + i);
					++n;
				}
				else {
					//ブロックの終わり
					//一時的にここで戻る
					//対になるブロックの構造体に最終行を格納したいので
					//文字列を入れた後、比較するルーチン追加
					//一致する構造体へ最終行を格納する
#if 0
					String[n] = *(buff + i);
					++n;
#endif
					return 6;
				}
				break;
			}
		}
		//カウンタ　インクリメント
		++i;
	}
	if (SlFlag == false)
	{
		//ブロックの始まり
		printf("Find string:%s\n", String);
		//文字列コピー
		strcpy_s(BlkData[*BlkCnt].Element, String);
		//行を格納する
		BlkData[*BlkCnt].StartLine = LineCnt;
		//要素を進める
		*BlkCnt++;
		return 4;
	}
	else {
		//ブロックの終わり
		int i = 0;
		//構造体の要素と比較する
		while (BlkData[i].Element == NULL)
		{
			if(strcmp(BlkData[i].Element,String) == 0)
			{
				//一致
				//行を格納する
				BlkData[i].EndLine = LineCnt;
				return 6;
			}
			i++;
		}
		//対応するブロックなし
		return 7;
	}
}