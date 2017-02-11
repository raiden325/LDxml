/* IEC63のxmlファイルを解析するプログラム */
#include "stdafx.h"

int ErrorCheck(int funcRtn)
{
	switch (funcRtn)
	{
	case 0:
		//ファイルを開けた　続行
		break;
	case 1:
		//ファイルの最後まで読んだ
		break;
	case 2:
		//異常終了
		exit(1);
	case -1:
		//ファイルを開けなかった
		exit(1);
	default:
		break;
	}
	return 0;
}

int main()
{
	char buff[256];				//一行バッファ
	char pbuff[256];			//ファイルパス用バッファ
	FILE *ReadFile = NULL;		//ファイル読み込みポインタ
	FILE *pReadFile = NULL;		//ファイルパス一覧読み込みポインタ
	int funcRtn;				//関数戻り値格納変数

	//ファイル一覧を作成する
	fg_MakeFileList();

	//ファイルパス一覧を開く
	funcRtn = fg_OpenFile("pathlist.txt", pbuff, pReadFile);
	ErrorCheck(funcRtn);
	//ファイルを開く
	funcRtn = fg_OpenFile(pbuff, buff, ReadFile);
	//ErrorCheck(funcRtn);
	//デバッグ
	printf("%s\n", buff);
	//<LD>検索

	//ラダーを解析する

	//buffクリア
	memset(buff, '\0', 256);

	memset(pbuff, '\0', 256);
	getchar();

    return 0;
}
