/* IEC63のxmlファイルを解析するプログラム */
#include "stdafx.h"

//ファイルスコープ関数の宣言
int fs_ErrorCheck(int funcRtn);

//構造体の宣言
extern struct _gPairData BlkData;

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
	case  6:
		//ブロックの終わりを発見
		printf("ブロックの終わりを発見しました。\n");
		break;
	case 7:
		//ブロックの終わりと一致する始まりが見つからなかった
		printf("ブロックの終わりを発見しましたが、対応するブロックの始まりが見つかりませんでした。\n");
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
	_gPairData BlkData[1000];	//ブロックのデータ構造体配列
	int BlkCnt;					//ブロックのデータ構造体配列の要素カウンタ
	int LineCnt;				//行カウンタ
	bool LDFlag;				//<LD>発見フラグ

	//ファイル一覧を作成する
	fg_MakeFileList();

	do
	{
		//変数の初期化
		BlkCnt = 0;
		LineCnt = 0;
		LDFlag = false;
		//構造体の初期化
		memset(BlkData, '\0', sizeof(_gPairData)*1000);
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
			//printf("%s\n", buff);
			if (funcRtn == 2)
			{
				//ファイルの最後まで読んだ
				break;
			}

			if (LDFlag == false)
			{
				//<LD>検索
				funcRtn = fg_LDFinder(buff);
				//戻り値チェック
				fs_ErrorCheck(funcRtn);
				if (funcRtn == 4)
				{
					//<LD>を発見した
					strcpy_s(BlkData[BlkCnt].Element, "LD");
					BlkData[BlkCnt].StartLine = LineCnt;
					BlkCnt++;
					break;
				}
			}
			else {
				//文字列の検索
				fg_StringFinder(buff, BlkData, &BlkCnt, LineCnt);
				//戻り値チェック
				fs_ErrorCheck(funcRtn);
				if (funcRtn == 6)
				{
					//ブロックの終わりを発見した

					break;
				}
			}
			//debug
			printf("Element(%d):%s\n", BlkCnt, BlkData[BlkCnt - 1].Element);
			LineCnt++;

		} while (buff != NULL);
		//ファイルを閉じる
		fclose(ReadFile);

	} while (pbuff != NULL);
	//ファイルを閉じる
	fclose(pReadFile);
	printf("End\n");
	getchar();
	return 0;
}
