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

//�\���̂̐錾
struct _gPairData{
	char Element[20];	//�v�f������
	int StartLine;		//�J�n�s
	int EndLine;		//�I���s
};

#endif /*__STDAFX_H__*/