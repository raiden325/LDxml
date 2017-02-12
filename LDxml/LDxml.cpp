/* IEC63のxmlファイルを解析するプログラム */
#include "stdafx.h"

//ファイルスコープ関数の宣言
int fs_ErrorCheck(int funcRtn);

/* 関数名：fs_ErrorCheck                                  */
/* 戻り値ごとに処理を分ける                               */
/* 戻り値：                                               */
/*  0:正常終了                                            */
int fs_ErrorCheck(int funcRtn)
{
	switch (funcRtn)
	{
	case 0:
		//ファイルを開けた　続行
		break;
	case 1:
		//ファイルを開けなかった
		exit(1);
	case 2:
		//ファイルの最後まで読んだ
		//printf("ファイルの最後まで読み終わりました。\n");
		break;
	case 3:
		//異常終了
		exit(1);
	case 4:
		//文字列を発見した
		//printf("文字列を発見しました。\n");
		break;
	case 5:
		//文字列未発見
		//printf("文字列が見つかりません。\n");
		break;
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

	do
	{
		//バッファのクリア
		memset(pbuff, '\0', 256);
		//ファイルパス一覧を開く
		funcRtn = fg_OpenFile("pathlist.txt", pbuff, &pReadFile);
		//戻り値チェック
		fs_ErrorCheck(funcRtn);
		if (funcRtn == 2)
		{
			//ファイルの最後まで読んだ
			break;
		}
		do
		{
			//buffクリア
			memset(buff, '\0', 256);
			//ファイルを開く
			funcRtn = fg_OpenFile(pbuff, buff, &ReadFile);
			//戻り値チェック
			fs_ErrorCheck(funcRtn);
			//デバッグ
			printf("%s\n", buff);
			if (funcRtn == 2)
			{
				//ファイルの最後まで読んだ
				break;
			}

			//<LD>検索
			funcRtn = fg_LDFinder(buff);
			//戻り値チェック
			fs_ErrorCheck(funcRtn);
			//ラダーを解析する
			fg_StringFinder(buff);

		} while (buff != NULL);
		//ファイルを閉じる
		fclose(ReadFile);

	} while (pbuff != NULL);
	//ファイルを閉じる
	fclose(pReadFile);
	getchar();
	return 0;
}
