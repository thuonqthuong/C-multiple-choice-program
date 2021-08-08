#pragma once
#include "ctdl.h"
#include "InOutFile.h"
//============================================================
void menu();
void themLop(DSLOP &dsl);
void xuatDSL(DSLOP &dsl);
int ktTrung(string a, DSLOP dsl);
void xoa(DSLOP dsl);
string taoMaLop(DSLOP dsl);
//============================================================
void menu()
{
	DSLOP dsl;
	bool kt=true;
	//=======load file===============
	doc_file(dsl);
	while(kt==true)
	{
		system("cls");
		cout<<"1. Them lop."<<endl;
		cout<<"2. Xuat DSL"<<endl;
		cout<<"3. Xoa Lop"<<endl;
		cout<<"0. Thoat"<<endl;
		int luachon;
		cout<<"Nhap vao lua chon: ";
		cin>>luachon;
		switch(luachon)
		{
			case 1:
				{
					themLop(dsl);
					break;
				}
			case 2:
				{
					xuatDSL(dsl);
					system("pause");
					break;
				}
			case 3:
				{
					xoa(dsl);
					break;
				}
			case 0:
				{
					kt=false;
					break;
				}
		}
	}
}

void themLop(DSLOP &dsl)
{
	LOP *p =  new LOP;
	p->malop = taoMaLop(dsl);
	cout<<"Nhap ten lop: ";
	cin.ignore();
	getline(cin, p->tenlop);
	dsl.ds[dsl.sl]=p;
	dsl.sl++;
}

void xuatDSL(DSLOP &dsl)
{
	for(int i=0; i<dsl.sl; i++)
	{
		cout<<"==================LOP "<<i<<"==================="<<endl;
		cout<<"Ma lop: "<<dsl.ds[i]->malop<<endl;
		cout<<"Ten lop: "<<dsl.ds[i]->tenlop<<endl;
	}
}

int ktTrung(string a, DSLOP dsl)
{
	for(int i=0; i<dsl.sl;i++)
	{
		if(dsl.ds[i]->malop==a)
		{
			return i;
		}
	}
	return -1;
}

void xoa(DSLOP dsl)
{
	string a;
	cout<<"Nhap vao ma lop: ";
	cin>>a;
	int vt = ktTrung(a, dsl);
	//======== xoa ========
	if (vt < 0)
	{
		cout << "Lop khong ton tai" << endl;
		system("pause");
	}
	else
	{
		for (int i = vt;i < dsl.sl - 1;i++)
		{
			dsl.ds[i]->malop = dsl.ds[i + 1]->malop;
			dsl.ds[i]->tenlop = dsl.ds[i + 1]->tenlop;
		}
		//giam sl
		LOP *tam = dsl.ds[dsl.sl - 1];
		dsl.sl--;
		delete tam;
		cout << "Da xoa thanh cong !" << endl;
		system("pause");
	}	
}

string taoMaLop(DSLOP dsl)
{
	string a = "LP0000";
	do
	{
		for(int i=3;i<a.length();i++)
		{
			a[i]=rand()%(57-48+1)+48;
		}
	}while(ktTrung(a, dsl)>=0);
	return a;
}
