#pragma once
#include "cauhoi.h"
//=============================================================================
//chua xu ly trung ma mon, chua chuan hoa bo het space, in hoa moi ma, chua rang buoc nhap qua 16, chua rang buoc nhap rong
//==============================================================================zz
void KhoiTaoCay(TREE &t);
void ThemNodeVaoCay(TREE &t, MONHOC monhoc);
void DuyetNLR(TREE t, int x, int y, int page, int hold);
int Dem(TREE &t, int &d);
NODE* TimKiem(TREE &t, char x[16]);
bool TrungMaMonHoc(TREE root, char x[16]);
void TreeToMang(TREE p, TREE *m, int &dem);
void MaMonHocTangDan(TREE &root, int x, int y, int page);
void TenMonHocTangDan(TREE &root, int x, int y, int page);
void ChuanHoaMa(string &s); // Xoa khoang trang vs in hoa het - ten mon hoc
void Xoa_ky_tu(char str[], int vt);
void ChuanHoa(string &s);
void DeleteScreenMonHoc();
void DeleteSuaTenMon();
string NhapMonCanSua();
string SuaTenMon();
int NhapMonHoc(TREE &t, int &y, int &page);
char NhapDA(int x, int y);
void ShowDeThi(MONHOC mh, int soCH, int tflag, string ma);// flag 0: giang vien thi, flag 1: sinh vien thi
void run(MONHOC mh, int soCH);
void startTimerJob(int time_in_second);
void startTimer(MONHOC mh, int soCH, int time, int flag, string ma);
void XemDSCH(MONHOC &mh, TREE &t);
void TimMonHoc(TREE &t, int x, int y, int flag, int tflag, string ma);
void NodeTheMang(TREE &x, TREE &y);
void XoaMonHoc(TREE &t, char ma[16]);
void QuanLyMonHoc(TREE &t);
void DocFile(char *filename, TREE &t);
void LuuFile(char *filename, TREE &t);

//khoi tao cay
void KhoiTaoCay(TREE &t)//TREE &t = NODE* t
{
	t = NULL;
}

//them node vao cay, chu y trung hop khoa co b trung hay khong
void ThemNodeVaoCay(TREE &t, MONHOC monhoc)
{
	if(t==NULL)
	{
		NODE *p = new NODE;//Khoi tao 1 cai node de them vao cay
		p->mon = monhoc;//Gan du lieu vao node
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;//node p - x chinh a root
	}
	else //Cay co ton tai phan tu
	{
		if(strcmp(t->mon.mamh, monhoc.mamh) > 0)//Neu phan tu them vao nho hon node goc, them trai
			ThemNodeVaoCay(t->pLeft, monhoc);
		else if(strcmp(t->mon.mamh, monhoc.mamh) < 0)//Them phai.....do cay nhi phan chi co nhung gia tri rieng biet 
			ThemNodeVaoCay(t->pRight,monhoc);//khong trung nhau nen khong co dieu kien t->data=x
	}
}
//Ham xuat theo NLR
void DuyetNLR(TREE t, int x, int y, int page, int hold)
{
	if(t!=NULL)
	{
		if(hold>=(page-1)*23)
		{
			gotoxy(x,y);cout<<t->mon.mamh;//xuat du lieu trong node
			gotoxy(x+26,y);cout<<t->mon.tenmh;
		}
		if(y==26)	
		{
			if(hold>=(page-1)*23)	return; // hang nay la sao - hien thi du thi dung, khong in nua, hold ch
			y=3;
		}
		hold++;
		DuyetNLR(t->pLeft, x, y+1, page, hold);//duyet trai
		DuyetNLR(t->pRight, x, y+1, page, hold);//duyet phai
	}
}
int Dem(TREE &t, int &d)
{ 
	if(t!=NULL){
		d++;
		Dem(t->pLeft, d);
		Dem(t->pRight, d);
	}
	return d;
}
NODE* TimKiem(TREE &t, char x[16])
{
	if(t==NULL)	return NULL;
	else
	{
		if(strcmp(t->mon.mamh, x) > 0)	TimKiem(t->pLeft, x);
		else if(strcmp(t->mon.mamh, x) < 0)	TimKiem(t->pRight, x);
		else	return t;
	}
}
bool TrungMaMonHoc(TREE root, char x[16])//1. trung 0. Khong trung
{
	const int STACKSIZE = MAXMONHOC;
    TREE Stack [STACKSIZE];
    TREE p = root;
    int sp = -1;	 // Khoi tao Stack rong
    do
	{ 
		while (p != NULL)
		{	 
			Stack[++sp] = p;
			p = p->pLeft;
        }
        if (sp != -1)
        {	 
			p = Stack [sp--];
			if (strcmp(p->mon.mamh, x) == 0) return true;
			p = p->pRight;
        }
        else break;
	} while (1);
	return false; 
}
// Chuyen cay nhi phan thanh mang - 08.07.2021
void TreeToMang(TREE p, TREE *m, int &dem) 
{
	if(p != NULL)
	{
		TreeToMang(p->pLeft, m, dem);
		m[++dem] = p;
		TreeToMang(p->pRight, m, dem);
	}
}
void MaMonHocTangDan(TREE &root, int x, int y, int page) //de tham chieu di, dang nao cung doc vo file, thay doi co sao dau nhi
{
	TREE m[MAXMONHOC];
	int i, j, dem = -1;
	TREE temp;
	TreeToMang(root, m, dem);// dem =0 -> sl-1
	dem++;
	for(i = 0; i < dem; i++)
		for(j = i + 1; j < dem; j++)
			if(strcmp(m[i]->mon.mamh, m[j]->mon.mamh) > 0)
			{
				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
	i=0; 
	while(i<dem)//In mang
	{
		if(i%23==0)	
		{
			BG(0,15);
			int k, m;
			for (m = 1; m < 24; m++)//Xoa man hinh nhap mon
			{
				gotoxy(45, 3 + m);
				for (k = 0; k < 16; k++) 	cout << " ";
				gotoxy(71, 3 + m);
				for (k = 0; k < 42; k++)	cout<< " ";
			}
			y=4;
			page++;	
			gotoxy(87,28);cout<<"Trang "<<page<<"/"<<page;
		}
		gotoxy(x,y);cout<<m[i]->mon.mamh<<endl;//xuat du lieu trong node
		gotoxy(x+26,y);cout<<m[i]->mon.tenmh<<endl;
		i++;
		y++;
	}
}
void TenMonHocTangDan(TREE &root, int x, int y, int page) //de tham chieu di, dang nao cung doc vo file, thay doi co sao dau nhi
{
	TREE m[MAXMONHOC];
	int i, j, dem = -1;
	TREE temp;
	TreeToMang(root, m, dem);// dem =0 -> sl-1
	dem++;
	for(i = 0; i < dem; i++)
		for(j = i + 1; j < dem; j++)
		{
			if(m[i]->mon.tenmh > m[j]->mon.tenmh)
			{
				temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
			else if(m[i]->mon.tenmh == m[j]->mon.tenmh)
			{
				if(strcmp(m[i]->mon.mamh, m[j]->mon.mamh) > 0)
				{
					temp = m[i];
					m[i] = m[j];
					m[j] = temp;
				}
			}
		}
	i=0; 
	while(i<dem)//In mang
	{
		if(i%23==0)	
		{
			BG(0,15);
			int k, m;
			for (m = 1; m < 24; m++)//Xoa man hinh nhap mon
			{
				gotoxy(45, 3 + m);
				for (k = 0; k < 16; k++) 	cout << " ";
				gotoxy(71, 3 + m);
				for (k = 0; k < 42; k++)	cout<< " ";
			}
			y=4;
			page++;	
			gotoxy(87,28);cout<<"Trang "<<page<<"/"<<page;
		}
		gotoxy(x,y);cout<<m[i]->mon.mamh<<endl;//xuat du lieu trong node
		gotoxy(x+26,y);cout<<m[i]->mon.tenmh<<endl;
		i++;
		y++;
	}
}
void ChuanHoaMa(string &s) // Xoa khoang trang vs in hoa het - ten mon hoc
{
	for(size_t i = 0; i < s.length(); i++) //Xoa khoang trang thua
	{
		if(s[i] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
	}
	for(size_t i = 0; i < s.length(); i++) //In hoa het
	{
		if(s[i] >= 97 && s[i] <= 122)
		{
			s[i] = s[i] - 32;
		}
	}
}
void ChuanHoa(string &s) // Xoa khoang trang thua vs in hoa chu cai dau
{
	for(size_t i = 0; i < s.length(); i++) //Xoa khoang trang thua
	{
		if(s[0] == ' ')
		{
			s.erase(0, 1);
			i--;
		}
		else if(s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
		else if(s[s.length() - 1] == ' ') s.erase(s.length() - 1, 1);
	}
	for(size_t i = 0; i < s.length(); i++) //In hoa het
	{
		if(s[i] >= 97 && s[i] <= 122)
		{
			s[i] = s[i] - 32;
		}
	}
}
void NodeTheMang(TREE &x, TREE &y)//NODE *y=t->pRight;
{
//	Cach 1: tim node trai nhat cua cay con phai
	if(y->pLeft!=NULL)	NodeTheMang(x,y->pLeft);//tim node trai nhat
	else	
	{
		strcpy(x->mon.mamh, y->mon.mamh);//01.07.2020 GAN KEY
		x=y;
		y=y->pRight;//cap nhat lai moi lien ket cho node cha cua node the mang
	}
}
void XoaMonHoc(TREE &t, char ma[16])
{
	if(t==NULL)		return;
	else
	{
		if(strcmp(t->mon.mamh, ma) > 0)	XoaMonHoc(t->pLeft, ma);
		else if(strcmp(t->mon.mamh, ma) < 0)	XoaMonHoc(t->pRight, ma);
		else
		{
			NODE *x=t;
			if(t->pLeft==NULL)
			{
				t=t->pRight;	
			}
			else if(t->pRight==NULL)
			{
				t=t->pLeft;	
			}
			else//node can xoa co 2 con
			{
				NodeTheMang(x,t->pRight);
			}
			delete x;
		}	
	}
}
void QuanLyMonHoc(TREE &t)
{
	int page = 0, hold = 0, count = 0;
	count = Dem(t, count);
	page=(count%23==0)?(count/23):(count/23+1);
	gotoxy(87,28);cout<<"Trang "<<page<<"/"<<page;
	DuyetNLR(t,45,4,page, hold);
	gotoxy(45,4+(count%23));
	int y, dem;
	if(count>0)		y = wherey();
	else 	 y = 4;
	for(int i=count; i<MAXMONHOC; i++)
	{
		dem=0;
		SetBGColor(11);
	  	gotoxy(41, 28);cout<<"SO LUONG MON HOC: "<<Dem(t,dem)<<endl;
	  	SetBGColor(15);
	  	int nhap=NhapMonHoc(t, y, page);
	  	if(nhap==-1||nhap==2)
		  	break;
		if(nhap==F4)
		{
			string s=NhapMonCanSua();
			if(s=="")	continue;
			int n = s.length();	
			char char_array[n + 1];
			strcpy(char_array, s.c_str());
			NODE* p=TimKiem(t,char_array);
			if(p!=NULL)
			{
				gotoxy(11,12);cout<<p->mon.mamh;
				gotoxy(11,13);cout<<p->mon.tenmh;
				gotoxy(11,14);
				p->mon.tenmh=SuaTenMon();
				y--;
				DeleteAPart();
				DeleteScreenMonHoc();
				DuyetNLR(t,45,4,page,hold);
			}
			if(p==NULL)		
			{
				DeleteAPart();
				gotoxy(53,31);
				cout<<"MA MON HOC KHONG TON TAI";
				continue;
			}
		}
		if(nhap==Delete)
		{
			string s=NhapMonCanSua();
			if(s=="")	continue;
			int n = s.length();	
			char char_array[n + 1];
			strcpy(char_array, s.c_str());
			NODE* p=TimKiem(t,char_array);
			if(p!=NULL)
			{
				if(p->mon.dsch.sl>0){
					gotoxy(53,31);
					cout<<"MON HOC KHONG THE XOA DO MON HOC CHUA DANH SACH CAU HOI";
					continue;
				}
				gotoxy(11,12);cout<<p->mon.mamh;
				gotoxy(11,13);cout<<p->mon.tenmh;
				BG(0,12);
				gotoxy(13,15);cout<<"BAN CO CHAC MUON XOA?";
				gotoxy(20,16);cout<<"Y/N?";
				BG(0,15);
				char choice=GetKey();
				if(choice=='Y'||choice=='y')
				{
					XoaMonHoc(t,p->mon.mamh);
					DeleteScreenMonHoc();
					DeleteAPart();
					y=y-2;modifyCursor(1, false);
					DuyetNLR(t,45,4,page,hold);
				}
				else
				{
					DeleteAPart();
					continue;
				}		
			}
			if(p==NULL)		
			{
				DeleteAPart();
				gotoxy(53,31);
				cout<<"MA MON HOC KHONG TON TAI";
				continue;
			}
		}
		count++;
		y++;
	}
	LuuFile(cauhoi, t);	
}
int NhapMonHoc(TREE &t, int &y, int &page)
{
	MONHOC mh;
	int i=0, hold;
	int d=0, k;
	d=Dem(t,d);
	char input[16], nd, move, kt;
	int inpage = page;
	gotoxy(45,y);modifyCursor(1, true);
	if(d%23==0&&d!=0)	
	{
		DeleteScreenMonHoc();
		y=4;
		page++;
		gotoxy(87,28);cout<<"Trang "<<page<<"/"<<page;
		gotoxy(45,4);
	}
	while(1)
	{
		char move=GetKey();gotoxy(87,27);
		if((move==LEFT&&inpage==1)||(move==RIGHT&&inpage==page)||move==UP||move==DOWN)	continue;
		else if(move==RIGHT&&inpage<page)
		{
			inpage++;hold=0;modifyCursor(1, false);
			gotoxy(87,28);cout<<"Trang "<<inpage<<"/"<<page;
			DeleteScreenMonHoc();
			DuyetNLR(t,45,4,inpage,hold);
		}
		else if(move==LEFT&&page>1)
		{
			inpage--;hold=0;modifyCursor(1, false);
			gotoxy(87,28);cout<<"Trang "<<inpage<<"/"<<page;
			DeleteScreenMonHoc();
			DuyetNLR(t,45,4,inpage,hold);
		}
		else if(move>=65 && move<= 90 || move>=97 && move<=122|| move>=48 && move<=57||move=='_')
		{
			if(inpage<page)		continue;
			if(move>=97 && move<=122)	move=move-32;
			input[0]=move;i=1;
			gotoxy(45,y);cout<<move;
			break;
		}
		else if(move==ESC)	return -1;
		else if(move==F4)
		{
			gotoxy(12,10);cout<<"NHAP: ";modifyCursor(1, true);
			return F4;
		}
		else if(move==Delete)
		{
			gotoxy(12,10);cout<<"NHAP: ";modifyCursor(1, true);
			return Delete;
		}
		else 
		{
			if(inpage<page)		continue;
			i=0;
			break;
		}
	}
	do
	{
		for(i; i<16;)//=====================MA LOP=======================
		{
			k=0; kt='\0';
			if(move==F4)
				gotoxy(18+i,10);
			else gotoxy(45+i,y);
			modifyCursor(1, true);
			input[i]=GetKey();
			if(i==15)// TRUONG HOP KY TU CUOI CUNG DUOC PHEP NHAP
			{
				for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
				gotoxy(53,31);cout<<"Ma mon dat do dai toi da";
				while(1)
				{
					kt=GetKey();
					if(kt==ENTER||kt==ESC||kt==BSPACE)	break;
					else continue;		
				}
			}
			if(kt==ESC)		return -1;
			if(kt==ENTER)	break;
			if(input[i]>=97 && input[i]<=122)	input[i]=input[i]-32;	
			if(input[i]>=65 && input[i]<= 90 || input[i]>=97 && input[i]<=122|| input[i]>=48 && input[i]<=57||input[i]=='_')	
			cout<<input[i];
			if((input[i]==BSPACE&&i>0)||(kt==BSPACE&&i>0))// TRUONG HOP NHAN PHIM XOA
			{
				Xoa_ky_tu(input,i);
				i--;
				if(move==F4)
				gotoxy(18+i,10);
				else gotoxy(45+i,y);
				cout<<" ";
			}
			else if(input[i]==SPACE) 
				continue;
			else if(input[i]==ESC)// TRUONG HOP ESC
			{
				return -1;
			}
			else if(input[i]==ENTER)// TRUONG HOP NHAN ENTER
			{
				if(i>0)	
				{
					input[i]='\0';
					--i;
					break;
				}
				else if(i==0)
				{
					for(k; k<65; k++)// Xoa o thong bao
					{
						gotoxy(53+k,31);
						cout<<" ";
					}
					gotoxy(53,31);cout<<"Vui long nhap ma, bao gom cac ky tu so, chu hoac ky tu _";
					continue;
				}
			}
			else if(input[i]>=65 && input[i]<= 90 || input[i]>=97 && input[i]<=122|| input[i]>=48 && input[i]<=57||input[i]=='_')// TRUONG HOP CAC KY TU CHO PHEP
			{
				i++;
				for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
			}
			else
			{
				for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
				gotoxy(53,31);cout<<"Vui long nhap ma, bao gom cac ky tu so, chu hoac ky tu _";
				continue;
			}
		}
		strcpy(mh.mamh, input);
		if(TrungMaMonHoc(t, mh.mamh)==1){
			for(int x=0; x<strlen(mh.mamh); x++)
			{
				gotoxy(45+x,y);
				cout<<" ";
			}
			i=0;
			gotoxy(53,31);cout<<"Trung ma mon hoc, vui long nhap lai!";
		}
	}while(TrungMaMonHoc(t, mh.mamh)==1);
	gotoxy(71, y);//=====================TEN MON HOC=======================
	for(i=0;i<45;)
	{
		k=0;
		fflush(stdin);
		nd=GetKey();
		modifyCursor(1, true);
		gotoxy(71+i,y);
		if(i==0&&nd==SPACE)	continue;
		if(nd>=97 && nd<=122)	nd=nd-32;
		if(nd>0&&nd!=BSPACE&&nd!=ESC&&nd!=ENTER&&i>=0&&i<80)
		{
			cout<<nd;
		}
		else if(nd==ENTER)
		{
			if(mh.tenmh.length()>0)
			{
				i--;
				ChuanHoa(mh.tenmh);
				ThemNodeVaoCay(t,mh);
				return 1;
			}	
			if(mh.tenmh.length()==0)
			{
				for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
				gotoxy(53,31);cout<<"Ban chua dien noi dung cau hoi";
				continue;
			}
		}
		else if(nd==ESC)		
		{//Khi an ESC thoat thi noi dung cau hoi neu co, mon hoc duoc luu
			if(mh.tenmh!="")
			{
				ChuanHoa(mh.tenmh);
				ThemNodeVaoCay(t,mh);
				return -1;// 
			}
			else
			{
				for(int j=0; j<i; j++)
				Xoa_ky_tu(mh.mamh,j);
				return -1;
			}
		}
		else if(i>0&&nd==BSPACE)		
		{
			--i;
			gotoxy(71+i,y);
			cout<<" ";
			modifyCursor(1, true);
			gotoxy(71+i,y);
			mh.tenmh.erase(mh.tenmh.size()-1);
		}
		else if(nd==F2)
		{
			if(mh.tenmh!="")
			{
				ChuanHoa(mh.tenmh);
				ThemNodeVaoCay(t,mh);
				gotoxy(53,31);cout<<"DA LUU VAO CSDL";
				return 2;// 
			}
			for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
			gotoxy(53,31);cout<<"Khong the luu vi nhap cau hoi chua hoan tat!";
		}
		if(nd>0&&nd!=BSPACE&&nd!=ENTER&&nd!=ESC)
		{
			mh.tenmh+=nd;
			i++;
		}
	}
	return 1;
}
string NhapMonCanSua()
{	
	int i, k;
	char input[16], kt;
	for(i=0; i<16;)//=====================MA LOP=======================
	{
		k=0;kt='\0';
		gotoxy(18+i,10);
		input[i]=GetKey();
		if(i==15)// TRUONG HOP KY TU CUOI CUNG DUOC PHEP NHAP
		{
			for(k; k<65; k++)// Xoa o thong bao
			{
				gotoxy(53+k,31);
				cout<<" ";
			}
			gotoxy(53,31);cout<<"Ma mon dat do dai toi da";
			while(1)
			{
				kt=GetKey();
				if(kt==ENTER||kt==ESC||kt==BSPACE)	break;
				else continue;		
			}
		}
		if(kt==ENTER)
		{
			input[i]='\0';
			--i;
			DeleteAPart();
			return input;
		}
		if(input[i]>=97 && input[i]<=122)	input[i]=input[i]-32;	
		if(input[i]>=65 && input[i]<= 90 || input[i]>=97 && input[i]<=122|| input[i]>=48 && input[i]<=57||input[i]=='_')	
		cout<<input[i];
		if((input[i]==BSPACE&&i>0)||(kt==BSPACE&&i>0))// TRUONG HOP NHAN PHIM XOA
		{
			Xoa_ky_tu(input,i);
			i--;
			gotoxy(18+i,10);
			cout<<" ";
		}
		else if(input[i]==SPACE) 
			continue;
		else if(input[i]==ESC||kt==ESC)// TRUONG HOP ESC
		{
			DeleteHuongDan();
			KhungHuongDanCase5();
			gotoxy(53,31);cout<<"                                                           ";
			return "";
		}
		else if(input[i]==ENTER)// TRUONG HOP NHAN ENTER
		{
			if(i>0)	
			{
				input[i]='\0';
				--i;
				DeleteAPart();
				return input;
			}
			else if(i==0)
			{
				for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
				gotoxy(53,31);cout<<"Vui long nhap ma, bao gom cac ky tu so, chu hoac ky tu _";
				continue;
			}
		}
		else if(input[i]>=65 && input[i]<= 90 || input[i]>=97 && input[i]<=122|| input[i]>=48 && input[i]<=57||input[i]=='_')// TRUONG HOP CAC KY TU CHO PHEP
		{
			i++;
			for(k; k<65; k++)// Xoa o thong bao
			{
				gotoxy(53+k,31);
				cout<<" ";
			}
		}
		else
		{
			for(k; k<65; k++)// Xoa o thong bao
			{
				gotoxy(53+k,31);
				cout<<" ";
			}
			gotoxy(53,31);cout<<"Vui long nhap ma, bao gom cac ky tu so, chu hoac ky tu _";
			continue;
		}
	}
}
string SuaTenMon()
{	
	int i, k;
	char nd;
	string tenmh="";
	gotoxy(11+i, 14);//=====================TEN MON HOC=======================
	for(i=0;i<45;)
	{
		k=0;
		fflush(stdin);
		nd=GetKey();
		modifyCursor(1, true);
		gotoxy(11+i, 14);
		if(i==0&&nd==SPACE)	continue;
		if(nd>=97 && nd<=122)	nd=nd-32;
		if(nd>0&&nd!=BSPACE&&nd!=ESC&&nd!=ENTER&&i>=0&&i<80)
		{
			cout<<nd;
		}
		else if(nd==ENTER)
		{
			if(tenmh.length()>0)
			{
				i--;
				ChuanHoa(tenmh);
				return tenmh;
			}	
			if(tenmh.length()==0)
			{
				for(k; k<65; k++)// Xoa o thong bao
				{
					gotoxy(53+k,31);
					cout<<" ";
				}
				gotoxy(53,31);cout<<"Ban chua dien noi dung cau hoi";
				continue;
			}
		}
		else if(nd==ESC)		
		{//Khi an ESC thoat thi noi dung cau hoi neu co, mon hoc duoc luu
			if(tenmh!="")
			{
				ChuanHoa(tenmh);
				return tenmh;// 
			}
			else
				return "";
		}
		else if(i>0&&nd==BSPACE)		
		{
			--i;
			gotoxy(11+i,14);
			cout<<" ";
			modifyCursor(1, true);
			gotoxy(11+i,14);
			tenmh.erase(tenmh.size()-1);
		}
		if(nd>0&&nd!=BSPACE&&nd!=ENTER&&nd!=ESC)
		{
			tenmh+=nd;
			i++;
		}
	}
	return tenmh;
}
void DeleteScreenMonHoc()
{
	BG(0,15);
	int i,j;
	for(int i=1; i<24; i++)
	{
		gotoxy(41,3+i);
		for(j=0; j<24; j++)		cout<<" ";
		gotoxy(67,3+i);
		for(j=0; j<51; j++)		cout<<" ";
	}	
}
void DeleteSuaTenMon()
{
	BG(0,15);
	int i,j;
	for(int i=1; i<6; i++)
	{
		gotoxy(11,11+i);
		for(j=0; j<24; j++)		cout<<" ";
	}
	gotoxy(12,10);
	for(j=0; j<22; j++)		cout<<" ";
}
void ShowDeThi(MONHOC mh, int soCH, int tflag, string ma)// flag 0: giang vien thi, flag 1: sinh vien thi
{
	char c, userchon[soCH], da[soCH], ch;
	ofstream fout;
	int array[mh.dsch.sl], i, stt=0;
	for(i=0; i<mh.dsch.sl; i++)
	{
		array[i]=i;
	}
	random(array, mh.dsch.sl, soCH);
	if(tflag==1)
	{
		fout.open("CTThiThu.txt", ios_base::app);
		fout << mh.mamh << '\n'
		 << soCH << '\n'
		 << ma << endl;
		for (i = mh.dsch.sl-soCH; i < mh.dsch.sl; i++)
			fout << mh.dsch.ds[array[i]].id << '|';
		fout<<endl;
	}
	for (i = mh.dsch.sl-soCH; i < mh.dsch.sl; i++)
		{
			da[stt]=mh.dsch.ds[array[i]].DA;
			userchon[stt]=' ';
			stt++;
		}
	const int soTrang = (soCH%4>0)?soCH/4+1:soCH/4;
	int trang=1, flag=0, j, currentflag;
	int slcauhoi=0;
	while(stop==0){
		flag=0;
		j=0;DeleteScreen();
		for(i = mh.dsch.sl-soCH; i<mh.dsch.sl&&flag<4; i++)
		{
			if(slcauhoi==soCH)	break;	
			slcauhoi++;
			mtx.lock();
			gotoxy(40,11+j); cout << "Cau "<<slcauhoi<<": ";
			gotoxy(48,11+j); cout << mh.dsch.ds[array[i+trang*4-4]].noidung;
			gotoxy(40,12+j); cout<<"A. "<<mh.dsch.ds[array[i+trang*4-4]].A;
			gotoxy(40,13+j); cout<<"B. "<<mh.dsch.ds[array[i+trang*4-4]].B;
			gotoxy(40,14+j); cout<<"C. "<<mh.dsch.ds[array[i+trang*4-4]].C;
			gotoxy(40,15+j); cout<<"D. "<<mh.dsch.ds[array[i+trang*4-4]].D;
			j+=6;
			flag++;
			mtx.unlock();
		}
		BG(0,11);
		mtx.lock();
		gotoxy(78,8);cout<<"Trang "<<trang<<"/"<<soTrang;
		mtx.unlock();BG(0,15);
		j=0;
		currentflag=flag;
		for(i=trang*4-4+1;currentflag>0;i++)
		{
			gotoxy(9,17+j);
			mtx.lock();
			cout<<i;mtx.unlock();
			currentflag--;
			j+=2;
		}
		j=0;
		currentflag=flag;
		for(i=trang*4-4; currentflag>0&&stop==0;)//IN DAP AN
		{
			ch='\0';
			gotoxy(11, 17+j);
			modifyCursor(1, true);
			if(stop==1)		break;
			ch=NhapDA(11, 17+j);
			if(ch=='A'||ch=='B'||ch=='C'||ch=='D')
			{
				userchon[i]=ch;
				j+=2;
				currentflag--;
				i++;
				continue;
			}
			if(ch=='X')
			{
				if(j==6)
					continue;
				j+=2;
				currentflag--;
				i++;
				continue;
			}
			if(ch=='U')
			{
				if(j==0)
					continue;
				j-=2;
				currentflag++;
				i--;
				continue;
			}
			if(ch==' ')		continue;
			if(ch=='R'&&trang==soTrang)		continue;
			if(ch=='L'||ch=='R'||ch=='S'||ch=='E')	
				break;
		}
		if(ch=='E')		break;
		if((ch=='L')&&trang==1)		
		{
			slcauhoi=0;
			continue;
		}
		else if(ch=='L'&&trang>1)
		{
			DeleteChonDA();
			slcauhoi=(trang-1)*4-4;
			trang--;
			j=0;
			for(i=trang*4-4; i<trang*4&&i<soCH;)
			{
				gotoxy(11,17+j);
				mtx.lock();
				cout<<userchon[i];
				mtx.unlock();
				j+=2;
				i++;
			}
			continue;			
		}
		else if(ch=='R'&&trang<soTrang)
		{	
			DeleteChonDA();
			trang++;
			j=0;
			for(i=trang*4-4; i<trang*4&&i<soCH;)
			{
				gotoxy(11,17+j);
				mtx.lock();
				cout<<userchon[i];
				mtx.unlock();
				j+=2;
				i++;
			}
			continue;			
		}
		else if(ch=='S')
		{
			if(trang==soTrang)	slcauhoi=soCH%4+(soTrang-1)*4;
			if(slcauhoi>=4&&trang!=soTrang)	slcauhoi-=4;
			continue;
		}
		c=GetKey();	
		if(c==ESC)	break;
		if((c==LEFT)&&trang==1)		slcauhoi=0;
		if((c==LEFT)&&trang>1)
		{
			DeleteChonDA();
			slcauhoi=(trang-1)*4-4;
			trang--;
			j=0;
			for(i=trang*4-4; i<trang*4&&i<soCH;)
			{
				gotoxy(11,17+j);
				mtx.lock();
				cout<<userchon[i];
				mtx.unlock();
				j+=2;
				i++;
			}
			continue;			
		}
		if((c==RIGHT)&&trang<soTrang)
		{	
			DeleteChonDA();
			trang++;
			j=0;
			for(i=trang*4-4; i<trang*4&&i<soCH;)
			{
				gotoxy(11,17+j);
				mtx.lock();
				cout<<userchon[i];
				mtx.unlock();
				j+=2;
				i++;
			}
			continue;			
		}
		else //if(c==SPACE)	
		{
			if(trang==soTrang)	slcauhoi=soCH%4+(soTrang-1)*4;
			if(slcauhoi>=4&&trang!=soTrang)	slcauhoi-=4;
			continue;
		}
	}
	stop=1;
	int mark=0;
	for(int i=0; i<soCH; i++)
	{
		if(tflag==1) fout << userchon[i] << "|";
		if(userchon[i]==da[i])	mark++;
	}
	if(tflag==1)
	{
		fout<<endl;
		fout<<setprecision(2)<<((float)mark/soCH)*10<<endl;
		fout.close();		
	}
	if(c==ESC||ch=='E')
	{mtx.lock();
		gotoxy(51,35);
		cout<<"KET THUC QUA TRINH LAM BAI THI DO NGUOI DUNG   ";mtx.unlock();
		BG(0,12);
		gotoxy(70,8); cout<<"DIEM THI: "<<setprecision(2)<<(((float)mark/soCH)*10)<< " ("<<mark<<"/"<<soCH<<")";
		BG(0,15);
		Sleep(2700);
	}
}
void startTimerJob(int time_in_second){
	int h, m;
	h=time_in_second/3600;
	m=(time_in_second-h*3600)/60;
	time_in_second=time_in_second-h*3600-m*60;mtx.lock();
	gotoxy(70,7); cout <<"THOI GIAN CON LAI: ";mtx.unlock();
	while(time_in_second>=0 && stop==0){
		mtx.lock();
		if(h<10) 
		{
			gotoxy(89,7); cout<< "0" << h <<":";
		}
		else	gotoxy(89,7); cout<< h <<":";
		if(m<10) 
		{
			gotoxy(92,7); cout<< "0" << m <<":";
		}
		else	gotoxy(92,7); cout<< m <<":";
		if(time_in_second<10) 
		{
			gotoxy(95,7); cout<< "0";
		}
		else	gotoxy(95,7); cout<< time_in_second;
		mtx.unlock();
		if(time_in_second==0&&m>0)
        {
        	m--;
        	time_in_second=60;
		}
		if(m==0&&h>0)
		{
			h--;
			m=60;
		}
        Sleep(980);		time_in_second-=1; 
	}
	if (stop==0) 
	{mtx.lock();
		gotoxy(51,35);
		cout<<"HET THOI GIAN, NHAN "<<char(17)<<" DE XEM DIEM THI";  mtx.unlock();
	}
	stop=1; 
}
void startTimer(MONHOC mh, int soCH, int time, int flag, string ma){//flag cua showdethi 0:GV; 1:SV
	thread timer;
	timer=thread(startTimerJob,time*60); // tao luong cho CTC startTimerJob chay trong 5 giay
	Sleep(10);
	ShowDeThi(mh, soCH, flag, ma);
	timer.join(); // ket thuc luong cap cho CTC startTimerJob
}
char NhapDA(int x, int y)
{
	char input, userchon;
	userchon='\0';
	while(1)
	{
		input = GetKey();
		gotoxy(x,y);
		if(input=='A'||input=='B'||input=='C'||input=='D'||input=='a'||input=='b'||input=='c'||input=='d')
		{
			if(input=='a'||input=='b'||input=='c'||input=='d')
			{
				userchon=input-32;
			}
			else userchon=input;
			mtx.lock();
			gotoxy(x,y);cout<<userchon;mtx.unlock();
		}
		else if(input==ESC&&userchon!='\0')		return userchon;
		else if(input==BSPACE)
		{
			userchon=' ';mtx.lock();
			gotoxy(x,y); cout<<" ";mtx.unlock();continue;
		}
		if(input==ESC)		return 'E';
		if((input==ENTER||input==UP||input==DOWN)&&userchon!='\0')
			return userchon;
		if(input==ENTER&&userchon=='\0')		return ' ';
		if(input==DOWN)		return 'X';
		if(input==UP)		return 'U';
		if(input==LEFT)		return 'L';
		if(input==RIGHT)	return 'R';
		if(!isalpha(input))		return 'S';
	}
}
void KhungHuongDan()
{
	DeleteHuongDan();
	EmptyBox1(8,15,26,20,1);// box huong dan
	SetColor(1);//chu - VANG HUONG DAN
	gotoxy(17,15); cout<<"HUONG DAN";
	SetColor(3);	// DO DAM
	gotoxy(10,11); cout<<"BAN DANG DANG NHAP VOI";
	gotoxy(10,12); cout<<" TU CACH GIANG VIEN!";
	SetColor(0);
	gotoxy(21,17); cout<<"NHAP CAU HOI";
	gotoxy(21,19); cout<<"XEM";
	gotoxy(21,21); cout<<"CHINH SUA";
	gotoxy(21,23); cout<<"THOAT";
	gotoxy(21,25); cout<<"QUA PHAI";
	gotoxy(21,27); cout<<"QUA TRAI";
	gotoxy(21,29); cout<<"LEN TREN";
	gotoxy(21,31); cout<<"XUONG DUOI";
	gotoxy(21,33); cout<<"XOA";
	SetColor(0);//phim - DEN HUONG DAN
	gotoxy(14,17); cout<<"F1";
	gotoxy(14,19); cout<<"F2";
	gotoxy(14,21); cout<<"F4";
	gotoxy(14,23); cout<<"ESC";
	gotoxy(14,25); cout<<char(16);
	gotoxy(14,27); cout<<char(17);
	gotoxy(14,29); cout<<char(30);
	gotoxy(14,31); cout<<char(31);
	gotoxy(12,33); cout<<"DELETE";

}
void XemDSCH(MONHOC &mh, TREE &t)
{
	char c;
	int soTrang = (mh.dsch.sl%4>0)?mh.dsch.sl/4+1:mh.dsch.sl/4;
	int trang=1, flag=0, i, j, id;
	int slcauhoi=0;
	while(1){
		flag=0;
		j=0;
		DeleteScreen();
		modifyCursor(1, false);
		for(i = 0; i<mh.dsch.sl&&flag<4; i++)
		{
			if(slcauhoi==mh.dsch.sl)	break;	
			gotoxy(40,10+j); cout << "Cau "<<slcauhoi+1<<": ";
			gotoxy(48,10+j); cout << mh.dsch.ds[slcauhoi].noidung;
			gotoxy(40,11+j); cout<<"A. "<<mh.dsch.ds[slcauhoi].A;
			gotoxy(40,12+j); cout<<"B. "<<mh.dsch.ds[slcauhoi].B;
			gotoxy(40,13+j); cout<<"C. "<<mh.dsch.ds[slcauhoi].C;
			gotoxy(40,14+j); cout<<"D. "<<mh.dsch.ds[slcauhoi].D;
			SetBGColor(14);
			gotoxy(40,15+j);cout<<"Dap an: "<<mh.dsch.ds[slcauhoi].DA;
			SetBGColor(15);
			j+=6;
			flag++;
			slcauhoi++;
		}
		BG(0,11);
		gotoxy(80,8);cout<<"Trang "<<trang<<"/"<<soTrang;
		BG(0,15);
		j=0;
		c=GetKey();	
		if(c==Delete)
		{
			i=0;
			char idcauhoi[4], temp[4];
			DeleteHuongDan();
			EmptyBox1(8,14,25,2,1);
			do
			{
				SetColor(0);
				gotoxy(11,15);cout<<"NHAP MA CAU HOI: ";
				while(i<4)
				{
					gotoxy(28+i,15);modifyCursor(1, true);
					temp[i]=GetKey();
					if(isalpha(temp[i])||temp[i]==UP||temp[i]==DOWN||temp[i]==LEFT||temp[i]==RIGHT)	continue;
					gotoxy(28+i,15);cout<<temp[i];
					if(temp[i]==BSPACE&&i>0)	
					{
						Xoa_ky_tu(temp,i);
						i--;
						gotoxy(28+i,15);cout<<" ";
						continue;
					}
					if(temp[0]==BSPACE)	i--;
					if(temp[i]==ESC||temp[i]==ENTER)	break;
					i++;
					if(i==4)	
					{
						i=0;temp[0]='\0';
						gotoxy(28+i,15);cout<<"    ";
						gotoxy(53,35);
						cout<<"NHAP TOI DA 3 CHU SO!";
						continue;
					}
				}
				strcpy(idcauhoi,temp);
				id = atoi(idcauhoi);
				if(temp[i]==ESC)	break;
				if(id>mh.dsch.sl)
				{
					gotoxy(53,35);
					cout<<"MA CAU HOI KHONG TON TAI, VUI LONG KIEM TRA LAI";
					i=0;
					gotoxy(28,15);cout<<"   ";
				}
			}while(id>mh.dsch.sl);
			gotoxy(53,35);cout<<"                                                  ";
			if(temp[i]==ESC)	
			{
				slcauhoi=(trang*4)-4;
				DeleteHuongDan();KhungHuongDan();
				continue;
			}
			gotoxy(9,17);
			SetBGColor(12);
			cout<<"BAN CO THAT SU MUON XOA?";
			gotoxy(19,18);cout<<"Y/N";
			SetBGColor(15);
			char del=getch();
			slcauhoi=(trang*4)-4;
			if(del=='Y'||del=='y')
			{
				Delete_item(mh.dsch, id-1);
				soTrang = (mh.dsch.sl%4>0)?mh.dsch.sl/4+1:mh.dsch.sl/4;
				gotoxy(10,8); cout<<"SO LUONG CAU HOI: "<<mh.dsch.sl;
			}
			DeleteHuongDan();KhungHuongDan();
			continue;
		}
		if(c==F4)
		{
			i=0;
			char idcauhoi[4], temp[4];
			DeleteHuongDan();
			EmptyBox1(8,14,25,2,1);
			do
			{
				SetColor(0);
				gotoxy(11,15);cout<<"NHAP MA CAU HOI: ";
				while(i<4)
				{
					gotoxy(28+i,15);modifyCursor(1, true);
					temp[i]=GetKey();
					if(isalpha(temp[i])||temp[i]==UP||temp[i]==DOWN||temp[i]==LEFT||temp[i]==RIGHT)	continue;
					gotoxy(28+i,15);cout<<temp[i];
					if(temp[i]==BSPACE&&i>0)	
					{
						Xoa_ky_tu(temp,i);
						i--;
						gotoxy(28+i,15);cout<<" ";
						continue;
					}
					if(temp[0]==BSPACE)	i--;
					if(temp[i]==ESC||temp[i]==ENTER)	break;
					i++;
					if(i==4)	
					{
						i=0;temp[0]='\0';
						gotoxy(28+i,15);cout<<"    ";
						gotoxy(53,35);
						cout<<"NHAP TOI DA 3 CHU SO!";
						continue;
					}
				}
				strcpy(idcauhoi,temp);
				id = atoi(idcauhoi);
				if(temp[i]==ESC)	break;
				if(id>mh.dsch.sl)
				{
					gotoxy(53,35);
					cout<<"MA CAU HOI KHONG TON TAI, VUI LONG KIEM TRA LAI";
					i=0;
					gotoxy(28,15);cout<<"   ";
				}
			}while(id>mh.dsch.sl);
			gotoxy(53,35);cout<<"                                                  ";
			if(temp[i]==ESC)	
			{
				slcauhoi=(trang*4)-4;
				DeleteHuongDan();KhungHuongDan();
				continue;
			}	
			DeleteScreen();
			gotoxy(40,19); cout << "Cau "<<slcauhoi+1<<": ";
			gotoxy(48,19); cout << mh.dsch.ds[id-1].noidung;
			gotoxy(40,20); cout<<"A. "<<mh.dsch.ds[id-1].A;
			gotoxy(40,21); cout<<"B. "<<mh.dsch.ds[id-1].B;
			gotoxy(40,22); cout<<"C. "<<mh.dsch.ds[id-1].C;
			gotoxy(40,23); cout<<"D. "<<mh.dsch.ds[id-1].D;
			gotoxy(40,24);cout<<"Dap an: "<<mh.dsch.ds[id-1].DA;
			SetBGColor(3);
			gotoxy(40,18); cout<<"SUA CAU HOI "<<id;
			SetBGColor(15);
			CAUHOI tam=mh.dsch.ds[id-1];
			if(NhapCauHoi(mh.dsch, id-1)==-1)	mh.dsch.ds[id-1]=tam;
			else mh.dsch.sl--;
			DeleteScreen();DeleteHuongDan();KhungHuongDan();
			slcauhoi=(trang*4)-4;
			continue;
		}
		if(c==F1)
		{
			DeleteScreen();
			TimMonHoc(t, 60, 12, 0, 0, "");
			break;
		}
		if(c==ESC)	break;
		if((c==LEFT)&&trang==1)		slcauhoi=0;
		if((c==LEFT)&&trang>1)
		{
			slcauhoi=(trang-1)*4-4;
			trang--;
			continue;			
		}
		if((c==RIGHT)&&trang==soTrang)
		{
			slcauhoi=(trang)*4-4;
			continue;
		}	
		if((c==RIGHT)&&trang<soTrang)
		{	
			trang++;slcauhoi=(trang*4)-4;
			continue;			
		}
		else //if(c==SPACE)	
		{
			if(trang==soTrang)	slcauhoi=mh.dsch.sl%4+(soTrang-1)*4;
			if(slcauhoi>=4&&trang!=soTrang)	slcauhoi-=4;
			continue;
		}
	}
}
void TimMonHoc(TREE &t, int x, int y, int flag, int tflag, string ma) //flag 0 nhap mon, flag 1 thi thu, flag = 2 xem danh sach CH
{
	EmptyBox2(59,12,50,18,1);
	for(int i=60;i<109;i++)		
	{
		gotoxy(i,14);cout<<char(196);
	}
	if(flag==2)
	{
		BG(0,11);gotoxy(59,10);	cout<<"      BAN DANG THUC HIEN XEM DANH SACH CAU HOI     ";
	}
	if(flag==0)
	{
		BG(0,11);gotoxy(59,10);	cout<<"      BAN DANG THUC HIEN CHUC NANG NHAP CAU HOI    ";
	}
	SetBGColor(15);
	TREE m1[MAXMONHOC];//Moi phan tu trong danh sach la m[i]
	int n = -1;
	TreeToMang(t, m1, n);
	n++;
	TREE m[MAXMONHOC];
	gotoxy(x + 1, y + 1); cout << "Nhap:";
	int i, j, dem, contro = 0, muiten = 0;
	char kytu;
	string temp;
	gotoxy(x - 3, y + 3); MuiTen();
	gotoxy(x + 7, y + 1);
	do
	{
		modifyCursor(1, true);
		BG(0,15);
		kytu = GetKey();
		if(kytu == -72)//Up
		{
			if(muiten > 0)
			{
				gotoxy(x - 3, y + 3 + muiten); cout << "  ";
				muiten--;
				gotoxy(x - 3, y + 3 + muiten); MuiTen();
				BG(0,15);
				gotoxy(x + 7 + contro, y + 1);
			}
		}
		else if(kytu == -80)//Down
		{
			if(muiten < 15 - 1 && muiten < dem - 1)//bang
			{
				gotoxy(x - 3, y + 3 + muiten); cout << "  ";
				muiten++;
				gotoxy(x - 3, y + 3 + muiten); MuiTen();
				BG(0,15);
				gotoxy(x + 7 + contro, y + 1);
			}	
		}
		else if(kytu == ENTER && dem != 0)
		{
			DeleteScreen();
			gotoxy(28,6);cout<<m[muiten]->mon.tenmh;
			gotoxy(28,7);cout<<m[muiten]->mon.mamh;
			gotoxy(28,8);cout<<m[muiten]->mon.dsch.sl;
			modifyCursor(1, false);
			if(flag==0)	{//QUAN LY CAU HOI
				gotoxy(28,8);cout<<m[muiten]->mon.dsch.sl;
				gotoxy(80,8);cout<<"          ";
				Createlist(m[muiten]->mon.dsch);
				XemDSCH(m[muiten]->mon, t);
			}
			if(flag==1)	// THI
			{
				int sl, tg, i=0;
				if(m[muiten]->mon.dsch.sl==0)
				{
					gotoxy(51,20);
					BG(0,12);
					cout<<"KHONG THE THI "<<m[muiten]->mon.tenmh<<" DO SO LUONG CAU HOI BANG 0";
					BG(0,15);
					Sleep(2700);
					return;
				}
				char temp[4], sl1[4];
				do{
					gotoxy(70,6);cout<<"NHAP SO CAU HOI: ";
					while(i<4)
					{
						gotoxy(87+i,6);modifyCursor(1, true);
						temp[i]=GetKey();
						if(isalpha(temp[i])||temp[i]==UP||temp[i]==DOWN||temp[i]==LEFT||temp[i]==RIGHT)	continue;
						gotoxy(87+i,6);cout<<temp[i];
						if(temp[i]==BSPACE&&i>0)	
						{
							Xoa_ky_tu(temp,i);
							i--;
							gotoxy(87+i,6);cout<<" ";
							continue;
						}
						if(temp[0]==BSPACE)	i--;
						if(temp[i]==ESC||temp[i]==ENTER)	break;
						i++;
					}
					strcpy(sl1,temp);
					sl = atoi(sl1);
					if(temp[i]==ESC)	return;
					if(sl>m[muiten]->mon.dsch.sl)
					{
						gotoxy(51,35);
						cout<<"Vui long nhap so luong cau hoi thi nho hon hoac bang "<<m[muiten]->mon.dsch.sl;
						i=0;gotoxy(87+i,6);cout<<"    ";
						gotoxy(87+i,6);
					}
				}while(sl>m[muiten]->mon.dsch.sl);
				strcpy(temp,"000");
				i=0;
				gotoxy(70,7); cout <<"NHAP THOI GIAN: ";
				while(1)
					{
						gotoxy(86+i,7);modifyCursor(1, true);
						temp[i]=GetKey();
						if(isalpha(temp[i])||temp[i]==UP||temp[i]==DOWN||temp[i]==LEFT||temp[i]==RIGHT)	continue;
						gotoxy(86+i,7);cout<<temp[i];
						if(temp[i]==BSPACE&&i>0)	
						{
							Xoa_ky_tu(temp,i);
							i--;
							gotoxy(86+i,7);cout<<" ";
							continue;
						}
						if(temp[0]==BSPACE)	i--;
						if(temp[i]==ESC||temp[i]==ENTER)	break;
						i++;
						if(i==2){i=0;continue;}
					}
					strcpy(sl1,temp);
					tg = atoi(sl1);
				if(temp[i]==ESC)	return;
				modifyCursor(1, false);
				gotoxy(70,6);cout<<"                     ";
				gotoxy(70,6);cout<<"SO CAU HOI: "<<sl;
				if(tflag==0) startTimer(m[muiten]->mon, sl, tg, 0, ma);//tflag=0: giang vien thi
				if(tflag==1) 	startTimer(m[muiten]->mon, sl, tg, 1, ma);
			}
			if(flag==2)
			{
				XemDSCH(m[muiten]->mon, t);
			}
			contro = 0;
			muiten = 0;
			dem = 0;
			temp = "";
			BG(0,15);
			break;		}
		else if((kytu >= 32 && kytu <= 126) || (kytu == BSPACE && contro > 0))
		{
			if(kytu >= 32 && kytu <= 126)
			{
				temp += kytu;
				gotoxy(x + 7 + contro, y + 1); cout << kytu;
				contro++;
			}
			else if(kytu == BSPACE && contro > 0)
			{
				temp = temp.substr(0, --contro);
				gotoxy(x + 7 + contro, y + 1); cout << " ";
				gotoxy(x + 7 + contro, y + 1);
			}
			modifyCursor(1, false);
			for(i = 0; i < 15; i++) // Xoa trong bang tim kiem
			{
				for(j = 0; j < 46; j++) { gotoxy(x + 1 + j, y + 3 + i); cout << " "; }
			}
			modifyCursor(1, true);
			dem = 0;
			string temp2 = temp; //Dung bien temp2 de tim ten mon
			ChuanHoa(temp2);
			for(i = 0; i < n; i++)
			{
				if(m1[i]->mon.tenmh.find(temp2) != string::npos)
				{
					m[dem] = m1[i];
					gotoxy(x + 2, y + 3 + dem); cout << m1[i]->mon.tenmh;
					dem++;
					if(dem > 15 - 1) break;//bang
				}
			}
			if(dem == 0) {gotoxy(x + 2, y + 3); cout << "Khong tim thay ket qua";}
			gotoxy(x + 7 + contro, y + 1);
		}
		else if(kytu == ESC)
		{
			DeleteScreen();
			return;
		}
	} while(1);
}
void DocFile(char *filename, TREE &t)
{
	int n;
	int i=0, j;
	ifstream filein;
	filein.open(filename, ios_base::in);
	MONHOC mh;
	string s;
	char ma[16];
	if (filein.fail())
	{
		cout << "Failed to open this file!" << endl;
		return;
	}
	while (filein.eof() != true)
	{
		filein>>n;
		filein.ignore();
		for(i; i<n; i++)
		{
			getline(filein, s, '\n');
			if(s=="")	return;
			ChuanHoaMa(s);
			getline(filein, mh.tenmh);
			char char_array[s.length() + 1];
			strcpy(char_array, s.c_str());
			strcpy(mh.mamh, s.c_str());
			fflush(stdin);
			filein >> mh.dsch.sl;
			for(j = 0; j<  mh.dsch.sl; j++)
			{
				filein>>mh.dsch.ds[j].id;
				filein.ignore(1,'|');
				getline(filein, mh.dsch.ds[j].noidung,'|');
				getline(filein, mh.dsch.ds[j].A,'|');
				getline(filein, mh.dsch.ds[j].B,'|');
				getline(filein, mh.dsch.ds[j].C,'|');
				getline(filein, mh.dsch.ds[j].D,'|');
				filein>> mh.dsch.ds[j].DA;
				filein.ignore();
			}
			if(mh.dsch.sl==0)	filein.ignore();
			ThemNodeVaoCay(t, mh);
		}
	}
	filein.close();
}
void LuuFile(char *filename, TREE &t) //17.07.2021
{
	int k = 0;
	ofstream fout;
	fout.open(filename, ios_base::out);
	const int STACKSIZE = 100;
    TREE Stack[STACKSIZE];
    TREE p = t;
    fout<<Dem(t,k)<<endl;
    int sp = -1;	 // Khoi tao Stack rong
    do //LNR
	{ 
		while (p != NULL)
		{	 
			Stack[++sp] = p;
			p = p->pLeft;
        }
        if (sp != -1)
        {	 
			p = Stack[sp--];
			fout << p->mon.mamh << endl
				 << p->mon.tenmh << endl
				 << p->mon.dsch.sl << endl;
				for (int i = 0; i < p->mon.dsch.sl; i++)
				{
					fout << p->mon.dsch.ds[i].id << '|'
					     << p->mon.dsch.ds[i].noidung << '|'
					     << p->mon.dsch.ds[i].A << '|'
					     << p->mon.dsch.ds[i].B << '|'
					     << p->mon.dsch.ds[i].C << '|'
						 << p->mon.dsch.ds[i].D << '|'
						 << p->mon.dsch.ds[i].DA << endl;
				}
			p = p->pRight;
        }
        else break;
	} while (1);
    fout.close();
}


