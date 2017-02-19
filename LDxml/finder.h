#pragma once
/* finder.h */
#ifndef __FINDER_H__
#define __FINDER_H__

extern struct _gPairData BlkData;

int fg_LDFinder(char *buff);
int fg_StringFinder(char *buff, _gPairData *BlkData, int *BlkCnt, int LineCnt);

#endif /*__FINDER_H__*/