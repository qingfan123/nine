// MortgageCalculator.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "MortgageCalculator.h"
#include "Commerce.h"
#define WIN_MAIN_WND IDD_DIALOG1

HINSTANCE g_hInst;
HWND g_hWnd;

// 全局变量:
LRESULT CALLBACK    MainWndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    AboutWndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	g_hInst = hInstance;
	// TODO: 在此处放置代码。
	DialogBox(hInstance, MAKEINTRESOURCE(WIN_MAIN_WND), NULL, (DLGPROC)MainWndProc);
}




//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    g_hWnd = hWnd;
    switch (message)
    {
        case WM_INITDIALOG:		// 初始化
        {
            SetWindowText(GetDlgItem(hWnd, IDC_EDIT9), TEXT("0.002708"));
            SetWindowText(GetDlgItem(hWnd, IDC_EDIT8), TEXT("0.002708"));
            return TRUE;
        }

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {


            case IDM_ABOUT:
            {
				DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, AboutWndProc);
                return TRUE;
            }
                
            case IDM_EXIT:
            {
				DestroyWindow(hWnd);
                return TRUE;
            }
			case WM_DESTROY:/// 当窗口被摧毁时 右上角的 X
			{
				PostQuitMessage(0);	/// 退出线程 - 退出码 
                return TRUE;
			}
               
            case IDC_BUTTON1:// 公积金/商业贷款 开始计算
            {
                
                Commer.CommerceAllCall(hWnd);
                return TRUE;
            }
            case IDC_BUTTON2:// 公积金/商业贷款 清空
            {
                Commer.ClearText(hWnd);
                return TRUE;
            }

            case IDC_BUTTON3:// 组合型 开始计算
            {
                group.GroupAllCall(hWnd);
                return TRUE;
            }

			case IDC_BUTTON4:// 组合型 清空
			{
                group.ClearText(hWnd);
				return TRUE;
			}


            }
            return FALSE;
        }
        
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
            return TRUE;
        }
        
    case WM_DESTROY:
    {
		PostQuitMessage(0);
        return TRUE;
    }
        
    
    }
    return (INT_PTR)FALSE;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK AboutWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
