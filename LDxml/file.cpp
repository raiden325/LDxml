#include "stdafx.h"

//ファイルスコープ関数の宣言
int fs_CRLFDel(char *buff);

/* 関数名：OpenFile                                       */
/* ファイルを開く                                         */
/* 戻り値：                                               */
/*  0:ファイルを開けた                                    */
/* -1:ファイルを開けなかった                              */
/*  1:ファイルの最後まで読んだ                            */
/*  2:異常終了                                            */
int fg_OpenFile(char *FileName, char *buff, FILE *ReadFile)
{
	errno_t err;	//ファイルオープン戻り値格納用変数

	if (ReadFile == NULL)
	{
		//ファイルポインタがヌルなら初回オープン
		if ((err = fopen_s(&ReadFile, FileName, "r")) == 0)
		{
			//ファイルを開けた
			if (fgets(buff, 256, ReadFile) != NULL)
			{
				printf("file pointer:%p\n", (void*)ReadFile);
				//一行読み込み
				fs_CRLFDel(buff);
				return 0;
			}
			else {
				//ファイルの最後まで読んだ
				return 1;
			}
		}
		else {
			//ファイルが開けなかった
			printf("Can't open file(%s).\n", FileName);
			return -1;
		}
	}
	else {
		//ファイルを開けた
		if (fgets(buff, 256, ReadFile) != NULL)
		{
			//一行読み込み
			fs_CRLFDel(buff);
			return 0;
		}
		else {
			//ファイルの最後まで読んだ
			return 1;
		}
	}
	return 2;
}

/* 関数名：fg_MakeFileList                                */
/* ファイルを開く                                         */
/* 戻り値：                                               */
/*  0:ファイルを開けた                                    */
int fg_MakeFileList()
{
	//ファイル一覧作成バッチファイルを実行する
	system("MakePathlist.bat");
	return 0;
}

/* 関数名：fs_CRLFDel                                     */
/* ファイルを開く                                         */
/* 戻り値：                                               */
/*  0:ファイルを開けた                                    */
int fs_CRLFDel(char *buff)
{
	int i;
	for (i = 0; i < strlen(buff); i++)
	{
		//文字列の長さだけループ
		if (*(buff + i) == '\n')
		{
			//CRLFがあればNULLにする
			*(buff + i) = '\0';
			return 0;
		}
	}
	return 0;
}
