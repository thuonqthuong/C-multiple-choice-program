#pragma once
//#include "ctdl.h"
#include "function.h"
//Chua rang buoc cac cau hoi nhap vao co noi dung khac nhau
//Can them ham sua noi dung cau hoi, va ham them cau hoi thu i
//==============================================
int Empty(DSCAUHOI &ds);
int Full(DSCAUHOI ds);
void LoadCauHoi(char *filename, DSCAUHOI &dsch);
void SaveDSCH(char *filename, DSCAUHOI &dsch);
void Traverse(DSCAUHOI &plist);
int Delete_item (DSCAUHOI &plist, int i);
void Search_info(DSCAUHOI &plist, int id);
CAUHOI nhap_1_cau_hoi(DSCAUHOI &plist, int i);
void Create_list(DSCAUHOI &plist);
int Insert_item( DSCAUHOI &list);
void Insert(DSCAUHOI &plist, CAUHOI ch);
void clearlist(DSCAUHOI &plist);

//==============================================
//------------------KT RONG---------------------
int Empty(DSCAUHOI &ds)//rong tra ve 1
{ return ds.sl==0 ;}
//------------------KT DAY----------------------
int Full(DSCAUHOI ds)// full tra ve 1
{ return ds.sl==MAXCAUHOI ;}
//-------------LOAI BO PHAN TU THU i-------------
int Delete_item (DSCAUHOI &plist, int i)
{
	int j;
	if(i < 0 || i >= plist.sl || plist.sl==0) return 0;
	for(j = i+1;  j< plist.sl ; j++)
		plist.ds[j-1] = plist.ds[j];
	plist.sl--;
	return 1; 
}
//----------------DUYET DANH SACH-----------------
void Traverse(DSCAUHOI &plist)
{
	int i;
	for(i = 0 ; i < plist.sl ; i++){
		gotoxy(40,11+i*6); cout << "Cau "<<plist.ds[i].id <<": ";
		gotoxy(49,11+i*6); cout<<  plist.ds[i].noidung << endl;
		gotoxy(40,12+i*6); cout<<"A. "<<  plist.ds[i].A<<endl;
		gotoxy(40,13+i*6); cout<<"B. "<<  plist.ds[i].B<<endl;
		gotoxy(40,14+i*6); cout<<"C. "<<  plist.ds[i].C<<endl;
		gotoxy(40,15+i*6); cout<<"D. "<<  plist.ds[i].D<<endl;
		HightLightDA();
		if(plist.ds[i].DA=='A')	gotoxy(40,12+i*6);
		if(plist.ds[i].DA=='B')	gotoxy(40,13+i*6);
		if(plist.ds[i].DA=='C')	gotoxy(40,14+i*6);
		if(plist.ds[i].DA=='D')	gotoxy(40,15+i*6);
		BG(0,15);
	}
}
//-------IN PHAN TU DAU TIEN CO GIA TRI INFO------
void Search_info(DSCAUHOI &plist, int id)
{
	for ( int i =0 ; i <plist.sl ; i++)
  	    if (plist.ds[i].id == id)
  	    {
  	     	cout << "\nCau hoi "<<plist.ds[i].id <<": ";
			cout<<  plist.ds[i].noidung << endl;
			cout<<"A. "<<  plist.ds[i].A<<endl;
			cout<<"B. "<<  plist.ds[i].B<<endl;
			cout<<"C. "<<  plist.ds[i].C<<endl;
			cout<<"D. "<<  plist.ds[i].D<<endl;
			cout<<"DAP AN: "<<  plist.ds[i].DA<<endl;
			return;
		}
	cout<<"Khong tim thay cau hoi co id = "<<id;
	return;
}
//------------CHECK NOI DUNG------------------
int CheckND(DSCAUHOI &plist, string s)
{
	for ( int i =0 ; i <plist.sl ; i++)
  	    if (plist.ds[i].noidung == s)
  	    	return i;
	return -1;
}
void Xoa_ky_tu(char str[], int vt)
{
	for(int i=vt+1;i<strlen(str);i++)
	{
		str[i-1]=str[i];
	}
	str[strlen(str)-1]='\0';
}
int NhapCauHoi(DSCAUHOI &plist, int position)
{		
	if(plist.sl==0)		plist.ds[plist.sl].id=0;
	plist.ds[plist.sl].id=plist.ds[plist.sl-1].id+1;
	CAUHOI ch;// Chua xu ly xoa man hinh consol
	char nd, a, b, c, d, da;
	int k=0;
	int dem=0;
	int i;//vi tri y
	// NHAP NOI DUNG
	do{
		i=0;
		ch.noidung="";
		gotoxy(40+i,11);cout << "Nhap cau hoi "<<position+1<<": ";
		for(i;i<80;)
		{
			fflush(stdin);
			nd=GetKey();
			gotoxy(51,35); cout<<"                                                                                    ";
			modifyCursor(1, true);
			gotoxy(56+i,11);
			if(i==0&&nd==SPACE)	continue;
			if(nd>0&&nd!=BSPACE&&nd!=ESC&&nd!=ENTER&&i>=0&&i<80)
			{
				cout<<nd;
			}
			else if(nd==ESC)		
			{
				ch.noidung="";
				return -1;
			}
			else if(nd==ENTER)
			{
				if(ch.noidung.length()>0)
				{
					i--;
					break;
				}	
				if(ch.noidung.length()==0)
				{
					gotoxy(51,35);cout<<"Ban chua dien noi dung cau hoi";
					continue;
				}
			}
			else if(i>0&&nd==BSPACE)		
			{
				--i;
				gotoxy(56+i,11);
				cout<<" ";
				modifyCursor(1, true);
				gotoxy(56+i,11);
				ch.noidung.erase(ch.noidung.size()-1);
			}
			else if(nd==F2)
			{
				gotoxy(51,35);cout<<"Khong the luu vi nhap cau hoi chua hoan tat!";
			}
			if(nd>0&&nd!=BSPACE&&nd!=ENTER&&nd!=ESC)
			{
				ch.noidung+=nd;
				i++;
			}
		}
		dem=ch.noidung.length();
		for(size_t p = 0; p < ch.noidung.length(); p++) //Xoa khoang trang thua
		{
			if(ch.noidung[0] == ' ')
			{
				ch.noidung.erase(0, 1);
				p--;
				i--;
			}
			else if(ch.noidung[p] == ' ' && ch.noidung[p + 1] == ' ')
			{
				ch.noidung.erase(p, 1);
				p--;
				i--;
			}
			else if(ch.noidung[ch.noidung.length() - 1] == ' ') 
			{
				ch.noidung.erase(ch.noidung.length() - 1, 1);
				i--;
			}
		}
		if(CheckND(plist, ch.noidung)!=-1)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(56+k,11); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap lai! Noi dung cau hoi trung voi cau thu "<<CheckND(plist, ch.noidung)+1;
		}
	}while(CheckND(plist, ch.noidung)!=-1);
	plist.ds[position].noidung=ch.noidung;
	
	// NHAP A
	i=0;
	gotoxy(40+i,12);cout << "Nhap dap an A: ";
	for(i;i<80;)
	{
		fflush(stdin);
		a=GetKey();
		gotoxy(51,35); cout<<"                                                                                    ";
		modifyCursor(1, true);
		gotoxy(55+i,12);
		if(i==0&&a==SPACE)	continue;
		if(a>0&&a!=BSPACE&&a!=ESC&&a!=ENTER&&i>=0&&i<=80)
		{
			cout<<a;
		}
		else if(a==ESC)		
		{
			ch.A="";
			return -1;
		}
		else if(a==ENTER)
		{
			if(ch.A.length()>0)
			{
				i--;
				break;
			}	
			if(ch.A.length()==0)
			{
				gotoxy(51,35);cout<<"Ban chua dien noi dung cau hoi";
				continue;
			}
		}
		else if(i>0&&a==BSPACE)		
		{
			--i;
			gotoxy(55+i,12);
			cout<<" ";
			modifyCursor(1, true);
			gotoxy(55+i,12);
			ch.A.erase(ch.A.size()-1);
		}
		else if(a==F2)
		{
			gotoxy(51,35);cout<<"Khong the luu vi nhap cau hoi chua hoan tat!";
		}
		if(a>0&&a!=BSPACE&&a!=ENTER&&a!=ESC)
		{
			ch.A+=a;
			i++;
		}
	}
	for(size_t p = 0; p < ch.A.length(); p++) //Xoa khoang trang thua
	{
		if(ch.A[0] == ' ')
		{
			ch.A.erase(0, 1);
			p--;
			i--;
		}
		else if(ch.A[p] == ' ' && ch.A[p + 1] == ' ')
		{
			ch.A.erase(p, 1);
			p--;
			i--;
		}
		else if(ch.A[ch.A.length() - 1] == ' ') 
		{
			ch.A.erase(ch.A.length() - 1, 1);
			i--;
		}
	}
	plist.ds[position].A=ch.A;
	// NHAP B
	do{
		i=0; 
		ch.B="";
		gotoxy(40+i,13);cout << "Nhap dap an B: ";
		for(i;i<80;)
		{
			fflush(stdin);
			b=GetKey();
			gotoxy(51,35); cout<<"                                                                                    ";
			modifyCursor(1, true);
			gotoxy(55+i,13);
			if(i==0&&b==SPACE)	continue;
			if(b>0&&b!=BSPACE&&b!=ESC&&b!=ENTER&&i>=0&&i<=80)
			{
				cout<<b;
			}
			else if(b==ESC)		
			{
				ch.B="";
				return -1;
			}
			else if(b==ENTER)
			{
				if(ch.B.length()>0)
				{
					i--;
					break;
				}	
				if(ch.B.length()==0)
				{
					gotoxy(51,35);cout<<"Ban chua dien noi dung cau hoi";
					continue;
				}
			}
			else if(i>0&&b==BSPACE)		
			{
				--i;
				gotoxy(55+i,13);
				cout<<" ";
				modifyCursor(1, true);
				gotoxy(55+i,13);
				ch.B.erase(ch.B.size()-1);
			}
			else if(b==F2)
			{
				gotoxy(51,35);cout<<"Khong the luu vi nhap cau hoi chua hoan tat!";
			}
			if(b>0&&b!=BSPACE&&b!=ENTER&&b!=ESC)
			{
				ch.B+=b;
				i++;
			}
		}
		for(size_t p = 0; p < ch.B.length(); p++) //Xoa khoang trang thua
		{
			if(ch.B[0] == ' ')
			{
				ch.B.erase(0, 1);
				p--;
				i--;
			}
			else if(ch.B[p] == ' ' && ch.B[p + 1] == ' ')
			{
				ch.B.erase(p, 1);
				p--;
				i--;
			}
			else if(ch.B[ch.B.length() - 1] == ' ') 
			{
				ch.B.erase(ch.B.length() - 1, 1);
				i--;
			}
		}
		if(ch.B==ch.A)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(55+k,13); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap noi dung khac dap an A";
		}
	}while(ch.B==ch.A);
	plist.ds[position].B=ch.B;
	// NHAP C
	do{
		i=0; 
		ch.C="";
		gotoxy(40+i,14);cout << "Nhap dap an C: ";
		for(i;i<80;)
		{
			fflush(stdin);
			c=GetKey();
			gotoxy(51,35); cout<<"                                                                                    ";
			modifyCursor(1, true);
			gotoxy(55+i,14);
			if(i==0&&c==SPACE)	continue;
			if(c>0&&c!=BSPACE&&c!=ESC&&c!=ENTER&&i>=0&&i<=80)
			{
				cout<<c;
			}
			else if(c==ESC)		
			{
				ch.C="";
				return -1;
			}
			else if(c==ENTER)
			{
				if(ch.C.length()>0)
				{
					i--;
					break;
				}	
				if(ch.C.length()==0)
				{
					gotoxy(51,35);cout<<"Ban chua dien noi dung cau hoi";
					continue;
				}
			}
			else if(i>0&&c==BSPACE)		
			{
				--i;
				gotoxy(55+i,14);
				cout<<" ";
				modifyCursor(1, true);
				gotoxy(55+i,14);
				ch.C.erase(ch.C.size()-1);
			}
			else if(c==F2)
			{
				gotoxy(51,35);cout<<"Khong the luu vi nhap cau hoi chua hoan tat!";
			}
			if(c>0&&c!=BSPACE&&c!=ENTER&&c!=ESC)
			{
				ch.C+=c;
				i++;
			}
		}
		for(size_t p = 0; p < ch.C.length(); p++) //Xoa khoang trang thua
		{
			if(ch.C[0] == ' ')
			{
				ch.C.erase(0, 1);
				p--;
				i--;
			}
			else if(ch.C[p] == ' ' && ch.C[p + 1] == ' ')
			{
				ch.C.erase(p, 1);
				p--;
				i--;
			}
			else if(ch.C[ch.C.length() - 1] == ' ') 
			{
				ch.C.erase(ch.C.length() - 1, 1);
				i--;
			}
		}
		if(ch.C==ch.A)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(55+k,14); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap noi dung khac dap an A";
		}
		if(ch.C==ch.B)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(55+k,14); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap noi dung khac dap an B";
		}
	}while(ch.C==ch.A||ch.C==ch.B);
	plist.ds[position].C=ch.C;
	// NHAP D
	do{
		i=0; 
		ch.D="";
		gotoxy(40+i,15);cout << "Nhap dap an D: ";
		for(i;i<80;)
		{
			fflush(stdin);
			d=GetKey();
			gotoxy(51,35); cout<<"                                                                                    ";
			modifyCursor(1, true);
			gotoxy(55+i,15);
			if(i==0&&d==SPACE)	continue;
			if(d>0&&d!=BSPACE&&d!=ESC&&d!=ENTER&&i>=0&&i<=80)
			{
				cout<<d;
			}
			else if(d==ESC)		
			{
				ch.D="";
				return -1;
			}
			else if(d==ENTER)
			{
				if(ch.D.length()>0)
				{
					i--;
					break;
				}	
				if(ch.D.length()==0)
				{
					gotoxy(51,35);cout<<"Ban chua dien noi dung cau hoi";
					continue;
				}
			}
			else if(i>0&&d==BSPACE)		
			{
				--i;
				gotoxy(55+i,15);
				cout<<" ";
				modifyCursor(1, true);
				gotoxy(55+i,15);
				ch.D.erase(ch.D.size()-1);
			}
			else if(d==F2)
			{
				gotoxy(51,35);cout<<"Khong the luu vi nhap cau hoi chua hoan tat!";
			}
			if(d>0&&d!=BSPACE&&d!=ENTER&&d!=ESC)
			{
				ch.D+=d;
				i++;
			}
		}
		for(size_t p = 0; p < ch.D.length(); p++) //Xoa khoang trang thua
		{
			if(ch.D[0] == ' ')
			{
				ch.D.erase(0, 1);
				p--;
				i--;
			}
			else if(ch.D[p] == ' ' && ch.D[p + 1] == ' ')
			{
				ch.D.erase(p, 1);
				p--;
				i--;
			}
			else if(ch.D[ch.D.length() - 1] == ' ') 
			{
				ch.D.erase(ch.D.length() - 1, 1);
				i--;
			}
		}
		if(ch.D==ch.A)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(55+k,15); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap noi dung khac dap an A";
		}
		if(ch.D==ch.B)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(55+k,15); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap noi dung khac dap an B";
		}
		if(ch.D==ch.C)
		{
			for(k=0; k<=i; k++)
			{
				gotoxy(55+k,15); cout<<" ";
			}
			gotoxy(51,35);cout<<"Vui long nhap noi dung khac dap an C";
		}
	}while(ch.D==ch.A||ch.D==ch.B||ch.D==ch.C);
	plist.ds[position].D=ch.D;
	// NHAP DAP AN
	ch.DA='\0';
	gotoxy(40,16);cout << "Nhap dap an cau hoi: ";
	while(1)
	{
		da = GetKey();
		gotoxy(51,35); cout<<"                                                                                    ";
		gotoxy(61,16);
		if(da==ESC)	return -1;
		else if(da=='A'||da=='B'||da=='C'||da=='D'||da=='a'||da=='b'||da=='c'||da=='d')
		{
			if(da=='a'||da=='b'||da=='c'||da=='d')
			{
				ch.DA=da-32;
			}
			else ch.DA=da;
			gotoxy(61,16);cout<<ch.DA;
		}
		else if(da==BSPACE)
		{
			ch.DA='\0';
			gotoxy(61,16); cout<<" ";
		}
		else if(da==ENTER)
		{
			if(ch.DA!=(char)0)
				break;
			else
			{
				gotoxy(51,35);cout<<"Ban chua dien noi dung dap an cho cau hoi";
				gotoxy(61,16);
				continue;
			}
		}
	}
	plist.ds[position].DA=ch.DA;
	plist.sl++;
	return 1;
}
void Createlist(DSCAUHOI &list)
{ int i;
  for(int i=0; i<MAXCAUHOI; i++)
  {
  	DeleteScreen();
  	if(NhapCauHoi(list, list.sl)==-1)
	  {
	  	break;
	  }	
  	gotoxy(28,8);cout<<list.sl;
  }
}
//----------------------XOA DS----------------------
void clearlist(DSCAUHOI &plist)
{
	plist.sl = 0;
}
