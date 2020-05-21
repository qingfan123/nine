#pragma once
#include "resource.h"
#include <windows.h>
#include <tchar.h>
#include <cmath>
// �������
static struct ResultData
{
	double Down = 0;			// �׸�
	double FirstMonth = 0;		// ÿ���¹�
	double TotalLoan = 0;		// �����ܶ�
	double Payment = 0;			// ֧����Ϣ
	double Amount = 0;			// �����ܶ�
	double MentMonths = 0;		// ��������
}ResData;

// ��ҵ/���������
static class Commerce
{
private:	// ˽��
	double HousPrice = 0;			// �û����� ���ݵ���
	double HousArea = 0;			// �û����� �������
	double MortYears = 0;			// �û����� ��������
	double loanRate = 0;			// �û����� ��������
	double Rental = 0;				// �û����� �����ܶ�
public:		// ����
	int Capital = 0;				// �ȶ�� 1==ѡ�� 0 == δѡ��
	int Interest = 0;				// �ȶϢ 1==ѡ�� 0 == δѡ��
	int iCommerce = 0;				// ��ҵ���� 1==ѡ�� 0 == δѡ��
	int Fund = 0;					// ��������� 1==ѡ�� 0 == δѡ��

	


	DWORD dwHousPriceID = IDC_EDIT1;		// ���ݵ���ID
	DWORD dwHousAreaID= IDC_EDIT3;			// �������ID
	DWORD dwMortYearsID = IDC_EDIT4;		// ��������ID
	DWORD dwloanRateID= IDC_EDIT6;			// ��������ID
	DWORD dwRentalID = IDC_EDIT2;			// �����ܶ�ID

	DWORD dwCapitalID = IDC_RADIO2;			// �ȶ��ID
	DWORD dwInterestID = IDC_RADIO1;		// �ȶϢID
	DWORD dwCommerceID = IDC_RADIO3;		// ��ҵ����ID
	DWORD dwFundID = IDC_RADIO4;			// ���������ID
	
public:		// ����
	

	void GetHousPrice(HWND hWnd);	// ��ȡ�û�����ķ��ݵ���
	void GetHousArea(HWND hWnd);	// ��ȡ�û�����ķ������
	void GetMortYears(HWND hWnd);	// ��ȡ�û�����İ�������
	void GetloanRate(HWND hWnd);	// ��ȡ�û�����Ĵ�������
	void GetRental(HWND hWnd);		// ��ȡ�û�����Ĵ����ܶ�
	void GetCommerSele(HWND hWnd);	// ��ȡ�û������ѡ��

	void GetCommerceData(HWND hWnd);// ��ȡ���е�������

	void CountFund();				// ���㹫�������
	void CountCommerce();			// ������ҵ����

	void SetResult(HWND hWnd);		// ������������ʾ���ı���

	void CommerceAllCall(HWND hWnd);// �ܵ���
	void ClearText(HWND hWnd);		// ����ı���
}Commer;

// ��ϴ���
static class Group
{
private:	// ˽��
	double ComerNum = 0;			// �û����� ��ҵ�����
	double ComerRate = 0;			// �û����� �̴�����
	double FundNum = 0;				// �û����� ����������
	double FundRate = 0;			// �û����� ����������
	double MortYear = 0;			// �û����� ��������


public:		// ����
	int Capital = 0;				// �ȶ�� 1==ѡ�� 0 == δѡ��
	int Interest = 0;				// �ȶϢ 1==ѡ�� 0 == δѡ��
	
	DWORD dwComerNumID = IDC_EDIT7;			// ��ҵ�����	�ı���ID
	DWORD dwComerRateID = IDC_EDIT9;		// �̴�����		�ı���ID
	DWORD dwFundNumID = IDC_EDIT10;			// ����������  �ı���ID
	DWORD dwFundRateID = IDC_EDIT8;			// ����������	�ı���ID
	DWORD dwMortYearsID = IDC_EDIT11;		// ��������		�ı���ID
	



public:		// ����
	void GetComerNum(HWND hWnd);	// ��ȡ �û����� ��ҵ�����
	void GetComerRate(HWND hWnd);	// ��ȡ �û����� �̴�����
	void GetFundNum(HWND hWnd);		// ��ȡ �û����� ����������
	void GetFundRate(HWND hWnd);	// ��ȡ �û����� ����������
	void GetMortYear(HWND hWnd);	// ��ȡ �û����� ��������
	void GetGroupSele(HWND hWnd);	// ��ȡ�û������ѡ��
	void GetGroupData(HWND hWnd);	// ��ȡ���е�������

	void CountGroup();				// ������
	void SetResult(HWND hWnd);		// ��ʾ������ı���
	void GroupAllCall(HWND hWnd);	// �ܵ���
	void ClearText(HWND hWnd);		// ����ı���

}group;

/*
	�̴�����  0.002708  IDC_EDIT9
	���������� 0.012708  IDC_EDIT8
	�������� 0.003958
*/
