#include "pch.h"
#include "CChatSocket.h"
#include "MFCChatServer.h"
#include "MFCChatServerDlg.h"
CChatSocket::CChatSocket()
{

}
CChatSocket::~CChatSocket()
{

}
void CChatSocket::OnReceive(int nErrorCode)
{
	TRACE("####Server OnReceive");
	CMFCChatServerDlg* dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[MAX_SERVER_BUF] = { 0 };
	Receive(szRecvBuf, MAX_SERVER_BUF, 0);
	TRACE("####Server Receive %s", szRecvBuf);

	//2ÏÔÊ¾buf
	USES_CONVERSION;
	CString strRecvMsg = A2T(szRecvBuf);
	
	CString strShow;
	CString strInfo = _T("¿Í»§¶Ë:");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);

	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);


	


}