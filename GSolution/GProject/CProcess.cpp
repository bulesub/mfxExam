// CProcess.cpp: 구현 파일
//

#include "pch.h"
#include "GProject.h"
#include "CProcess.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}

int CProcess::GetStarInfo(CImage* pImage, int nTh)
{
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeight = pImage->GetHeight();
	int nPitch = pImage->GetPitch();

	int nSum = 0;
	for (int k = 0; k < nWidth * nHeight; k++)
	{
		if (fm[k] > nTh)
			nSum++;
	}

	return nSum;
}


// CProcess 멤버 함수
