#pragma once

/* stdafx.h */
#ifndef __STDAFX_H__
#define __STDAFX_H__

#include "targetver.h"

#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <stdlib.h>
#include "file.h"
#include "finder.h"
#include "analysis.h"

//構造体の宣言
struct _gPairData{
	char Element[20];	//要素文字列
	int StartLine;		//開始行
	int EndLine;		//終了行
};

#endif /*__STDAFX_H__*/