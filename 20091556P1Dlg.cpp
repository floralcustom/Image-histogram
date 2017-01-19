
// 20091556P1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "20091556P1.h"
#include "20091556P1Dlg.h"
#include "afxdialogex.h"
#define min(a,b)        ((a) < (b) ? (a) : (b)) // 삼항 연산자를 이용한 색 오류 검사 정의
#define max(a,b)        ((a) > (b) ? (a) : (b))

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy20091556P1Dlg 대화 상자




CMy20091556P1Dlg::CMy20091556P1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy20091556P1Dlg::IDD, pParent)
	, m_strPathName(_T(""))
	, H(NULL)
	, E(NULL)
	, nY(NULL)
	, nCb(NULL)
	, nCr(NULL)
	, EqualY(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20091556P1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy20091556P1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOAD, &CMy20091556P1Dlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_EQUAL, &CMy20091556P1Dlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// CMy20091556P1Dlg 메시지 처리기

BOOL CMy20091556P1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMy20091556P1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy20091556P1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy20091556P1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20091556P1Dlg::OnBnClickedLoad()
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	HDC hDC = dc.GetSafeHdc();
	Graphics G(hDC);
	
	for(int i = 0; i < 256; i++)  // 명암도 빈도수 초기화
		 m_Hist[i] = 0;    

	CFileDialog Load(TRUE,NULL,NULL,OFN_FILEMUSTEXIST); // 이미지파일 로드오류 확인 
	if(IDOK == Load.DoModal())
	{
        CString strPathName = Load.GetPathName(); 
	}
	CFile file;
	file.Open(Load.GetPathName(), CFile::modeRead | CFile::typeBinary); // 이미지파일 로드
	m_strPathName = file.GetFilePath();   // 경로에따른 이미지를 넣어줌
	file.Close();

	Bitmap dlg(m_strPathName);
	G.DrawImage(&dlg,35,55,300,190); // 이미지 출력


	H = (Color**)calloc(dlg.GetWidth(),sizeof(Color*)); // 불러온 이미지에 대한 동적 이차원 배열  // H 명암도를 가지고있는 변수
	for(int i = 0; i < dlg.GetWidth(); i++)
			H[i] = (Color*)calloc(sizeof(Color),dlg.GetHeight());
		

	for(int i = 0; i < dlg.GetWidth(); i++)
	{
		for(int j = 0; j < dlg.GetHeight(); j++)
		{
			dlg.GetPixel(i,j,&H[i][j]); // 불러온 이미지의 픽셀 색을 H 배열에 넣어줌
			Hist(H[i][j]); // 그림 픽셀의 명암도에 따른 빈도수 계산 함수  // 특정 명암도의 빈도수를 저장하는 배열
		}
	}

	int m_topHist = 0; // 히스토그램 그래프의 Y축 정규화 : 그림의 명암도에 대한 최대 빈도 픽셀수를 기준으로 잡음으로써 보기 쉬운 그래프를 도표하기위해 정의
	for(int i = 0; i < 256; i++) // 픽셀의 최대값을 구하는 반복문
	{
		if(m_Hist[i] > m_topHist)
			m_topHist = m_Hist[i];
	}

	Bitmap graph(256,m_topHist);
	if(graph.GetLastStatus() != Ok)
		return;

	for(int i = 0; i < 256; i++) // 가로
	{
		for(int j = 0; j < m_topHist; j++) // 세로
			graph.SetPixel(i,j,Color(255,255,255)); // 그래프 배경 흰색으로 초기화
	}

	for(int x = 0; x < 256; x++)
	{
		for(int y = 0; y < m_Hist[x]; y++) // Y축은 명암도 빈도수를 찍는다.
			graph.SetPixel(x,m_topHist-y,Color(0,0,0)); // 그림의 빈도수에 대한 그래프 출력 반복문(MFC는 좌표가 왼쪽위가 0,0 이기때문에 최대값에서 빈도수를 빼줘야 올바른 모양으로 나옴)
	}
	G.DrawImage(&graph,35,285,300,190); // 그래프 출력
}


void CMy20091556P1Dlg::OnBnClickedEqual()
{
	// TODO: Add your control notification handler code here
	int sum=0, total_pixels=0, k=0;
	int sum_of_hist[256];     // 축적히스토그램 저장
	
	CClientDC dc(this);
	HDC hDC = dc.GetSafeHdc();
	Graphics G(hDC);
	
	Bitmap dlg(m_strPathName);
	
	E = (Color**)calloc(dlg.GetWidth(),sizeof(Color*)); // 불러온 이미지에 대한 동적 이차원 배열
	for(int i = 0; i< dlg.GetWidth(); i++)
		E[i] = (Color*)calloc(sizeof(Color),dlg.GetHeight());

	nY = (int**)calloc( dlg.GetWidth(),sizeof(int*)); // 입력 영상 Y에 대한 동적 이차원 배열
	for(int i = 0; i< dlg.GetWidth(); i++)
		nY[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	nCb = (int**)calloc( dlg.GetWidth(),sizeof(int*)); // 입력 영상 Cb에 대한 동적 이차원 배열
	for(int i = 0; i< dlg.GetWidth(); i++)
		nCb[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	nCr = (int**)calloc(dlg.GetWidth(),sizeof(int*)); // 입력 영상 Cr에 대한 동적 이차원 배열
	for(int i = 0; i< dlg.GetWidth(); i++)
		nCr[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	EqualY = (int**)calloc(dlg.GetWidth(),sizeof(int*)); // 정규화 시킨 값에 대한 동적 이차원 배열
	for(int i = 0; i< dlg.GetWidth(); i++)
		EqualY[i] = (int*)calloc(sizeof(int),dlg.GetHeight());

	for(int i=0; i<256; i++) // 명암도 축척 히스토그램!
	{
		sum=sum+m_Hist[i];  // 누적빈도수
		sum_of_hist[i]=sum;
	}

	total_pixels=dlg.GetWidth()*dlg.GetHeight();
	Bitmap m_ResultImg(dlg.GetWidth(), dlg.GetHeight());
	for(int i = 0; i < dlg.GetWidth(); i++) // 매핑
	{
		for(int j = 0; j < dlg.GetHeight(); j++)
		{
			dlg.GetPixel(i,j,&E[i][j]); // 불러온 이미지의 픽셀 색을 E 배열에 넣어줌
			nY[i][j]=SaveY(E[i][j]);
			nCb[i][j]=SaveCb(E[i][j]);
			nCr[i][j]=SaveCr(E[i][j]);

			EqualY[i][j] = sum_of_hist[nY[i][j]]*(255.0/total_pixels); // 축적 히스토그램의 정규화    축적히스토그램* 명도의최대값/총픽셀의개수
			m_ResultImg.SetPixel(i,j,SetRGB(EqualY[i][j],nCb[i][j],nCr[i][j]));
		}
	}

	G.DrawImage(&m_ResultImg,545,55,300,190); // 평활화된 이미지 출력
	

	for(int i = 0; i < 256; i++) // 명암도 빈도수 초기화
		 m_Hist[i] = 0;

	for(int i = 0; i < dlg.GetWidth(); i++) // 평준화된 명암도의 빈도수를 계산하기위한 반복문
	{
		for(int j = 0; j < dlg.GetHeight(); j++)
		{
			EqualHist(EqualY[i][j]); // 그림 픽셀의 명암도에 따른 빈도수 계산 함수
		}
	}

	int m_EqualtopHist = 0; // 히스토그램 그래프의 Y축 정규화 : 그림의 명암도에 대한 최대 빈도 픽셀수를 긴준으로 잡으므로써 보기 쉬운 그래프를 도표하기위해 정의
	
	for(int i = 0; i < 256; i++) // 픽셀의 최대값을 구하는 반복문
	{
		if(m_Hist[i] > m_EqualtopHist)
			m_EqualtopHist = m_Hist[i];
	}
	Bitmap Equalgraph(256,m_EqualtopHist);
	if(Equalgraph.GetLastStatus() != Ok)
		return;
	
	
	for(int i = 0; i < 256; i++) // 가로		
	{
		for(int j = 0; j < m_EqualtopHist; j++) // 세로
			Equalgraph.SetPixel(i,j,Color(255,255,255)); // 그래프 배경 흰색으로 초기화
	}
	
	for(int x = 0; x < 256; x++)
	{
		for(int y = 0; y < m_Hist[x]; y++) // Y축은 명암도 빈도수를 찍는다.
			Equalgraph.SetPixel(x,m_EqualtopHist-y,Color(0,0,0)); 
	}
	G.DrawImage(&Equalgraph,545,285,300,190);
}


void CMy20091556P1Dlg::Hist(Color a) // 명도값에 대한 빈도수를 조사하는 함수
{
	int R, G, B, L;

	R = a.GetR();
	G = a.GetG();
	B = a.GetB();
	L = 0.30*R + 0.59*G + 0.11*B; // RGB에서 명도 추출 공식
	m_Hist[L]++; // 빈도수 조사
}


double CMy20091556P1Dlg::SaveY(Color a) // 추출한 Y값 저장 함수
{
	int Y;
	Y = 0.29900*a.GetR() + 0.58700*a.GetG() + 0.11400*a.GetB();
	Y = min(255,max(0,Y));
	return Y;
}


double CMy20091556P1Dlg::SaveCb(Color a) // 추출한 Cb값 저장 함수
{
	int Cb;
	Cb = -0.16874*a.GetR() - 0.33126*a.GetG() + 0.50000*a.GetB();
	Cb = min(255,max(0,Cb));
	return Cb;
}


double CMy20091556P1Dlg::SaveCr(Color a) // 추출한 Cr값 저장 함수
{
	int Cr;
	Cr = 0.50000*a.GetR() - 0.41869*a.GetG() - 0.08131*a.GetB();
	Cr = min(255,max(0,Cr));
	return Cr;
}


Color CMy20091556P1Dlg::SetRGB(int Y, int Cb, int Cr) // Y, Cb, Cr값을 RGB로 바꿔주는 함수
{
	Color a;
	int R, G, B;

	R = 1.00000*Y + 1.40200*Cr;
	G = 1.00000*Y - 0.34414*Cb - 0.71414*Cr;
	B = 1.00000*Y + 1.77200*Cb;

	//R = min(255,max(0,R));
	//G = min(255,max(0,G));
	//B = min(255,max(0,B));

	a.SetFromCOLORREF(RGB(R,G,B));
	return a;
}


void CMy20091556P1Dlg::EqualHist(int EqualY)
{
	m_Hist[EqualY]++;
}