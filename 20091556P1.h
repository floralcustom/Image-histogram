
// 20091556P1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy20091556P1App:
// �� Ŭ������ ������ ���ؼ��� 20091556P1.cpp�� �����Ͻʽÿ�.
//

class CMy20091556P1App : public CWinApp
{
public:
	CMy20091556P1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy20091556P1App theApp;