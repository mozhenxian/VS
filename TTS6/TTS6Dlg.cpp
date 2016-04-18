// TTS6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "TTS6.h"
#include "TTS6Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTTS6Dlg dialog

CTTS6Dlg::CTTS6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTTS6Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTTS6Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_x=0;
	m_y=0;
	m_stop=FALSE;
}

void CTTS6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTTS6Dlg)
	DDX_Control(pDX, IDC_RICHEDIT1, m_wndRichEdit);
	DDX_Control(pDX, IDC_AGENT, m_Agent);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTTS6Dlg, CDialog)
	//{{AFX_MSG_MAP(CTTS6Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SETFONT, OnSetfont)
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_FONT2, OnFont2)
	ON_BN_CLICKED(IDC_RECOGNITION, OnRecognition)
	ON_BN_CLICKED(IDC_SPIRIT, OnSpiritInit)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STOPREG, OnStopreg)
	ON_BN_CLICKED(IDC_STARTREG, OnStartreg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTTS6Dlg message handlers

BOOL CTTS6Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//OnSpiritInit();//初始化精灵

	// TODO: Add extra initialization here
	OnFont2();//设置字体
	m_wndRichEdit.SetBackgroundColor(FALSE,RGB(0,0,0));//设置Rich控件背景颜色

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTTS6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTTS6Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTTS6Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTTS6Dlg::ModifyFont()
{
	CFontDialog dlg;						//初始化字体信息
	if(dlg.DoModal()==IDOK)				//判断是否按下"确定"按钮
	{
		LOGFONT temp;					//声明LOGFONT结构指针
		dlg.GetCurrentFont(&temp);			//获取当前字体信息
		CHARFORMAT cf;				//声明CHARFORMAT变量
		memset(&cf, 0, sizeof(CHARFORMAT));	//分配内存
		m_wndRichEdit.GetDefaultCharFormat(cf);	//获得缺省的字符格式化属性
		cf.yHeight  = temp.lfWeight;		//设置字号
		cf.dwMask = CFM_COLOR | CFM_SIZE | CFM_FACE;	//设置标记属性
		cf.dwEffects = CFE_BOLD;			//设置标记属性有效
		cf.crTextColor = dlg.GetColor();		//设置颜色
		strcpy(cf.szFaceName,temp.lfFaceName);//设置字体
		m_wndRichEdit.SetWordCharFormat(cf);	//设置控件显示字体
		m_wndRichEdit.SetSel(-1,-1);			//选择最后一行
		m_wndRichEdit.ReplaceSel("\n");		//插入换行符
		m_wndRichEdit.SetSel(-1,-1);			//选择最后一行
	}
}

void CTTS6Dlg::OnSetfont() 
{
	ModifyFont();	
}

#include "sapi.h"
BOOL CTTS6Dlg::Spreak()
{

	CString strBuffer;
	m_wndRichEdit.GetWindowText(strBuffer);
	
	ISpVoice * pVoice;
	if(FAILED(::CoInitialize(NULL)))//初始化COM库
	{
		return FALSE;
	}
	
	HRESULT hr= CoCreateInstance(CLSID_SpVoice,NULL,
		CLSCTX_ALL,IID_ISpVoice,(void**)&pVoice);//创建实例，返回接口
	if(FAILED(hr))
	{
		return FALSE;
	}
	wchar_t szBuffer[256]={ 0 };

	pVoice->SetVolume(100);//设置音量范围是(0-100)
	pVoice->SetRate(0);//设置朗读速率范围(-10到10)
	pVoice->Speak(strBuffer.AllocSysString(),0,NULL);//朗读编辑框中的文字	
	
	pVoice->Release(); 
	pVoice = NULL; 
	::CoUninitialize();
	return 0;
}


void CTTS6Dlg::OnRead() 
{
	AfxBeginThread(ReadThread,this);
}

UINT CTTS6Dlg::ReadThread(LPVOID pParam)
{
	CTTS6Dlg *pThis=(CTTS6Dlg*)pParam;
	pThis->Spreak();
	AfxEndThread(1002);
	return 0;
}

void CTTS6Dlg::OnFont2() 
{
	CHARFORMAT cf;				//声明CHARFORMAT变量
	memset(&cf, 0, sizeof(CHARFORMAT));	//分配内存
	m_wndRichEdit.GetDefaultCharFormat(cf);	//获得缺省的字符格式化属性
	cf.yHeight  = 300;		//设置字号
	cf.dwMask = CFM_COLOR | CFM_SIZE | CFM_FACE;	//设置标记属性
	cf.dwEffects = CFE_BOLD;			//设置标记属性有效
	cf.crTextColor = RGB(0,255,0);		//设置颜色
	strcpy(cf.szFaceName,"楷体");//设置字体
	m_wndRichEdit.SetWordCharFormat(cf);//设置编辑框字体(颜色，大小，哪种字体等属性)
	
}

BOOL CTTS6Dlg::Move_To(int x,int y,LPVOID pParam)
{
	CTTS6Dlg *pThis=(CTTS6Dlg*)pParam;
	VARIANT vant;
	vant.vt=(VT_I2);
	vant.iVal=10;
	m_Static_m_Ex->MoveTo(x,y,vant);
	return TRUE;
}


#include <sapi.h>//sapi库
#include <atlbase.h>//atl库
#include "sphelper.h"

inline HRESULT BlockForResult(ISpRecoContext * pRecoCtxt, ISpRecoResult ** ppResult)
{
    HRESULT hr = S_OK;
    CSpEvent event;
	
    while (SUCCEEDED(hr) &&
		SUCCEEDED(hr = event.GetFrom(pRecoCtxt)) &&
		hr == S_FALSE)
    {
        hr = pRecoCtxt->WaitForNotifyEvent(INFINITE);
    }
	
    *ppResult = event.RecoResult();
    if (*ppResult)
    {
        (*ppResult)->AddRef();
    }
	
    return hr;
}

const WCHAR * StopWord()
{
    const WCHAR * pchStop;
    
    LANGID LangId = ::SpGetUserDefaultUILanguage();
	
    switch (LangId)
    {
	case MAKELANGID(LANG_JAPANESE, SUBLANG_DEFAULT):
		pchStop = L"}42N86\0b70e50fc0ea0e70fc/05708504608a087043";;
		break;
		
	default:
		pchStop = L"Stop";
		break;
    }
    return pchStop;
}


BOOL CTTS6Dlg::Recognition(LPVOID pParam)
{
	HRESULT hr;
	bool fUseTTS = true;            // turn TTS play back on or off
    bool fReplay = true;            // turn Audio replay on or off
	if (SUCCEEDED(hr = ::CoInitialize(NULL)))//初始化COM 库
    {
        {
            CComPtr<ISpRecoContext> cpRecoCtxt;//
            CComPtr<ISpRecoGrammar> cpGrammar;
            CComPtr<ISpVoice> cpVoice;
            hr = cpRecoCtxt.CoCreateInstance(CLSID_SpSharedRecoContext);//获取接口
            if(SUCCEEDED(hr))
            {
                hr = cpRecoCtxt->GetVoice(&cpVoice);
            }
			
			WCHAR wszXMLFile[256]=L""; 
			MultiByteToWideChar(CP_ACP, 0, (LPCSTR)"CmdCtrl.xml", -1, wszXMLFile, 256);//ANSI转UNINCODE 
			ULONGLONG                  ullGramId = 1;
			

			if(!(cpVoice&&cpRecoCtxt))
			{
				AfxMessageBox("cpVoice||cpRecoCtxt==NULL");
				return FALSE;
			}
			
			if(FAILED(hr = cpRecoCtxt->SetNotifyWin32Event()))
			{
				AfxMessageBox("Error::SetNotifyWin32Event");
				return FALSE;
			}

			if(FAILED(hr = cpRecoCtxt->SetInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION))))
			{
				AfxMessageBox("Error::SetInterest");
				return FALSE;
			}

			if(FAILED(hr = cpRecoCtxt->SetAudioOptions(SPAO_RETAIN_AUDIO, NULL, NULL)))
			{
				AfxMessageBox("Error::SetAudioOptions");
				return FALSE;
			}

			if(FAILED(hr = cpRecoCtxt->CreateGrammar(ullGramId, &cpGrammar)))
			{
				AfxMessageBox("Error::CreateGrammar");
				return FALSE;
			}

			if(FAILED(hr = cpGrammar->LoadCmdFromFile(wszXMLFile, SPLO_DYNAMIC)))
			{
				AfxMessageBox("Error::LoadCmdFromFile");
				return FALSE;
			}

			if(FAILED(hr = cpGrammar->SetRuleState( NULL,NULL,SPRS_ACTIVE )))
			{
				AfxMessageBox("Error::SetRuleState");
				return FALSE;
			}

            /*
			if (cpRecoCtxt && cpVoice &&
                SUCCEEDED(hr = cpRecoCtxt->SetNotifyWin32Event()) &&
                SUCCEEDED(hr = cpRecoCtxt->SetInterest(SPFEI(SPEI_RECOGNITION), SPFEI(SPEI_RECOGNITION))) && 
                SUCCEEDED(hr = cpRecoCtxt->SetAudioOptions(SPAO_RETAIN_AUDIO, NULL, NULL)) &&
                SUCCEEDED(hr = cpRecoCtxt->CreateGrammar(ullGramId, &cpGrammar)) &&//AfxMessageBox("Su")&&
                //SUCCEEDED(hr = cpGrammar->LoadDictation(NULL, SPLO_STATIC)) &&
				SUCCEEDED(hr = cpGrammar->LoadCmdFromFile(wszXMLFile, SPLO_DYNAMIC)) &&
                //SUCCEEDED(hr = cpGrammar->SetDictationState(SPRS_ACTIVE)))
				SUCCEEDED(hr = cpGrammar->SetRuleState( NULL,NULL,SPRS_ACTIVE )))//C&C
			*/
			if(SUCCEEDED(hr))
            {
                USES_CONVERSION;
				
                const WCHAR * const pchStop = StopWord();
                CComPtr<ISpRecoResult> cpResult;
				
                //printf( "I will repeat everything you say. Say %s to exit. ", W2A(pchStop) );
				
                while (SUCCEEDED(hr = BlockForResult(cpRecoCtxt, &cpResult))&&m_stop==FALSE)
                {
                    cpGrammar->SetDictationState( SPRS_INACTIVE );
					
                    CSpDynamicString dstrText;
					
                    if (SUCCEEDED(cpResult->GetText(SP_GETWHOLEPHRASE, SP_GETWHOLEPHRASE, 
						TRUE, &dstrText, NULL)))
                    {
                        //printf("我听到: %s ", W2A(dstrText));
						
                        if (fUseTTS)
                        {
							m_strListen+=W2A(dstrText);
                            //cpVoice->Speak( L"我听到", SPF_ASYNC, NULL);
							m_wndRichEdit.SetWindowText(m_strListen);
                            //cpVoice->Speak( dstrText, SPF_ASYNC, NULL );
							if(strcmp(W2A(dstrText),"电脑")==0)
							{
								//m_x=650;
								//m_y=320;
							}
							else if(strcmp(W2A(dstrText),"向上")==0)
							{
								//m_x=650;
								m_y=100;
							}

							else if(strcmp(W2A(dstrText),"向下")==0)
							{
								//m_x=650;
								m_y=690;
							}
							else if(strcmp(W2A(dstrText),"向左")==0)
							{
								m_x=50;
								//m_y=320;
							}
							else if(strcmp(W2A(dstrText),"向右")==0)
							{
								m_x=1300;
								//m_y=320;
							}
                        }
						
                        if (fReplay)
                        {	
                            if (fUseTTS);
                               // cpVoice->Speak( L"当你说", SPF_ASYNC, NULL);
                            else;
                                //printf ("当你说");
                            cpResult->SpeakAudio(NULL, 0, NULL, NULL);//说出真实录音
						}
						
						cpResult.Release();
                    }
                    if (_wcsicmp(dstrText, pchStop) == 0)
                    {
                        break;
                    }
                    
                    cpGrammar->SetDictationState( SPRS_ACTIVE );
                } 
            }
			else
			{
				AfxMessageBox("Error");
			}
        }
        ::CoUninitialize();
    }
	return TRUE;
}


void CTTS6Dlg::OnRecognition( ) 
{
	OnSpiritInit();//初始化精灵
	AfxBeginThread(RegThread,this);//启动线程
	SetTimer(1001,1000*1,NULL);
	//AfxBeginThread(RespondThread,this);//启动响应线程
	
}

UINT CTTS6Dlg::RegThread(LPVOID pParam)
{
	CTTS6Dlg *pThis=(CTTS6Dlg*)pParam;
	pThis->Recognition(pParam);
	return 0;
}

CAgentCtlCharacterEx *CTTS6Dlg::m_Static_m_Ex=NULL;

void CTTS6Dlg::OnSpiritInit() 
{
	COleVariant Character("0");//角色
	m_Characters=m_Agent.GetCharacters();
	m_Request=m_Characters.Load("Genie",COleVariant("C:\\Windows\\msagent\\chars\\Genie.acs"));
	m_Ex=m_Characters.Character("Genie");//m_Ex是这个控件的别名
	m_Ex.Show(Character);

	//**************机器人开场白*********Begin
	VARIANT variant1={0};
	VARIANT variant2={0};
	variant1.vt=VT_BSTR;
	variant2.vt=VT_BSTR;
	CString strText="hello,what can I help you?I am a intelligent machina,\
		I can deal with every thing that you want.";

	variant1.bstrVal=strText.AllocSysString();
	variant2.bstrVal=L"";

	m_Ex.Speak(variant1,variant2);
	//**************机器人开场白*********End

	
}

void CTTS6Dlg::OnClose() 
{
	m_Characters.Unload("Genie");//这句一定要有不然，关闭不了（不能正常退出）
	
	CDialog::OnClose();
}

UINT CTTS6Dlg::RespondThread(LPVOID pParam)//此线程暂时已作废
{
	CTTS6Dlg *pThis=(CTTS6Dlg*)pParam;
	int Old_m_x=0;
	
	CAgentCtlCharacters Characters=NULL;
	CAgentCtlCharacterEx Act;
	CAgentCtlRequest Request;

	COleVariant Character("0");//角色
	Characters=pThis->m_Agent.GetCharacters();
	Request=Characters.Load("Genie",COleVariant("C:\\Windows\\msagent\\chars\\Genie.acs"));
	Act=Characters.Character("Genie");//m_Ex是这个控件的别名
	Act.Show(Character);

	while(1)
	{
		if(pThis->m_x!=Old_m_x)
		{
			Old_m_x=pThis->m_x;
		}

	}
	return 0;
}

void CTTS6Dlg::OnTimer(UINT nIDEvent) 
{
	static int Old_m_x=0;
	if(m_x!=Old_m_x)	
	{
		Move_To(m_x,m_y,NULL);
		Old_m_x=m_x;
	}
	CDialog::OnTimer(nIDEvent);
}

void CTTS6Dlg::OnStopreg() 
{
	m_stop=TRUE;//关闭语音识别	
}

void CTTS6Dlg::OnStartreg() 
{
	m_stop=FALSE;//开启语音识别
}
