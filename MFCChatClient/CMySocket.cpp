#include "pch.h"
#include "CMySocket.h"
#include "MFCChatClient.h"
#include "MFCChatClientDlg.h"

CMySocket::CMySocket() {

}
CMySocket::~CMySocket()
{

}

void CMySocket::OnConnect(int nErrorCode)
{
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();

	CString strShow;
	CString strInfo = _T("");
	CString strMsg = _T("����������ӳɹ�");
	strShow = dlg->CatShowString(strInfo, strMsg);

	dlg->m_list.AddString(strShow);
	   
	CAsyncSocket::OnConnect(nErrorCode);
}

void CMySocket::OnReceive(int nErrorCode)
{
	
	TRACE("####Client OnReceive");
	CMFCChatClientDlg* dlg = (CMFCChatClientDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[SEND_MAX_BUF] = { 0 };
	Receive(szRecvBuf, SEND_MAX_BUF, 0);
	TRACE("####Client Receive %s", szRecvBuf);

	//2��ʾbuf
	USES_CONVERSION;
	CString strRecvMsg = A2T(szRecvBuf);


	CString strShow;
	CString strInfo = _T("����ˣ�");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);

	dlg->m_list.AddString(strShow);
	CAsyncSocket::OnReceive(nErrorCode);
	
}