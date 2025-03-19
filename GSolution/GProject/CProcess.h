#pragma once

// CProcess 명령 대상

class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

	int GetStarInfo(CImage* image, int nTh = 100);
	int GetStarInfo(CImage* image, int nTh, CRect rect);
};


