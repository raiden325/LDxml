#include "stdafx.h"

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
	char *next_token = NULL;	//strtok_s用

	if (ReadFile == NULL)
	{
		//ファイルポインタがヌルなら初回オープン
		if ((err = fopen_s(&ReadFile, FileName, "r")) == 0)
		{
			//ファイルを開けた
			if (fgets(buff, sizeof(char) * 256, ReadFile) != NULL)
			{
				//一行読み込み
				strtok_s(buff, "\n\0", &next_token);

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
		if (fgets(buff, sizeof(char) * 256, ReadFile) != NULL)
		{
			//一行読み込み
			return 0;
		}
		else {
			//ファイルの最後まで読んだ
			return 1;
		}
	}
	return 2;
}

int fg_MakeFileList()
{
	//ファイル一覧作成バッチファイルを実行する
	system("MakePathlist.bat");
	return 0;
}