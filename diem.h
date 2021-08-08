#include "LOP.h"
#include "treemonhoc.h"
void Insert_First(PTRDIEM &First, DIEM diem)
{
   PTRDIEM p = new nodeDiem;
   p->info= diem;
   p->next = First;
   First = p;
}
void DocDiem(char *filename, DSLOP &dslop)
{
	ifstream filein;
	filein.open(filename, ios_base::in);
	PTRSV sv;
	DIEM diemthi;
	int i;
	string mssv, malop, tenlop;
	if (filein.fail())
	{
		cout << "Failed to open this file!" << endl;
		return;
	}
	while (filein.eof() != true)
	{
		diemthi.slCH=0;
		filein>>diemthi.mamh;
		filein.ignore();
		filein>>diemthi.slCH;
		filein.ignore();
		getline(filein, mssv, '\n');
		for(int i=1;i<=dslop.sl;i++){
			sv=dslop.dsl[i]->dssv;
			sv=searchStudent(sv,mssv);
			if(sv!=NULL)	
				break;
		}
		diemthi.cauhoisv = new chitietcauhoi[diemthi.slCH];
		for(i=0; i<diemthi.slCH; i++)// ID
		{
			filein>>diemthi.cauhoisv[i].id;
			filein.ignore(1,'|');
		}
		filein.ignore();
		for(i=0; i<diemthi.slCH; i++)// DAP AN
		{
			filein>>diemthi.cauhoisv[i].svchon;
			filein.ignore(1,'|');
		}
		filein.ignore();
		filein>>diemthi.score;
		filein.ignore();
		nodeDiem* node=new nodeDiem();
		node->info=diemthi;
		node->next=NULL;
		Insert_First(sv->data.dsdiem,node->info);
	}
	filein.close();
}
void Initialize(PTRDIEM &First)
{
   First= NULL;
}

void Traverse(PTRDIEM First)
{ PTRDIEM p;
   if(p == NULL)
      printf("\n   (Khong co phan tu trong danh sach)");
	for (p = First ; p != NULL; p = p->next)
      {
      	PTRDIEM q;
      	q=p;
      	cout<<q->info.mamh<<endl<<q->info.score<<endl;
      	cout<<q->info.slCH;
		for(int i=0;i<q->info.slCH ; i++)
		{
			cout<<endl<<q->info.cauhoisv[i].id<<": "<<q->info.cauhoisv[i].svchon<<" ";
		}	
		cout<<endl<<endl;
	  }
}
string NhapMa(int y)
{
	int i, k;
	char input[16], kt;
	for(i=0; i<16;)//=====================MA LOP=======================
	{
		k=0;kt='\0';
		gotoxy(23+i,y);
		input[i]=GetKey();
		if(i==15)// TRUONG HOP KY TU CUOI CUNG DUOC PHEP NHAP
		{
			for(k; k<60; k++)// Xoa o thong bao
			{
				gotoxy(9+k,4);
				cout<<" ";
			}
			gotoxy(9,4);cout<<"MSSV da dat den do dai toi da, khong the nhap tiep";
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
			return input;
		}
		if(input[i]>=97 && input[i]<=122)	input[i]=input[i]-32;	
		if(input[i]>=65 && input[i]<= 90 || input[i]>=97 && input[i]<=122|| input[i]>=48 && input[i]<=57)	
		cout<<input[i];
		if((input[i]==BSPACE&&i>0)||(kt==BSPACE&&i>0))// TRUONG HOP NHAN PHIM XOA
		{
			Xoa_ky_tu(input,i);
			i--;
			gotoxy(23+i,y);
			cout<<" ";
		}
		else if(input[i]==SPACE) 
			continue;
		else if(input[i]==ESC||kt==ESC)// TRUONG HOP ESC
		{
			gotoxy(9,4);cout<<"                                                           ";
			return "";
		}
		else if(input[i]==ENTER)// TRUONG HOP NHAN ENTER
		{
			if(i>0)	
			{
				input[i]='\0';
				--i;
				string str(input);
				return str;
			}
			else if(i==0)
			{
				for(k; k<60; k++)// Xoa o thong bao
				{
					gotoxy(9+k,4);
					cout<<" ";
				}
				gotoxy(9,4);cout<<"Vui long nhap ma sinh vien, bao gom cac ky tu so hoac chu";
				continue;
			}
		}
		else if(input[i]>=65 && input[i]<= 90 || input[i]>=97 && input[i]<=122|| input[i]>=48 && input[i]<=57)// TRUONG HOP CAC KY TU CHO PHEP
		{
			i++;
			for(k; k<60; k++)// Xoa o thong bao
			{
				gotoxy(9+k,4);
				cout<<" ";
			}
		}
		else
		{
			for(k; k<60; k++)// Xoa o thong bao
			{
				gotoxy(9+k,4);
				cout<<" ";
			}
			gotoxy(9,4);cout<<"Vui long nhap ma sinh vien, bao gom cac ky tu so hoac chu";
			continue;
		}
	}
}
void FrameChiTietCauHoiThi()
{
	BG(0,15);
	resizeConsole(550,400);
	EmptyBox2(15,5,40,2,1);//MSSV
	EmptyBox2(15,8,40,2,1);//MAMH
	BG(0,3);
	gotoxy(9,2);cout<<"NHAP VAO MSSV VA MA MON HOC DE XEM CHI TIET CAU HOI THI";
	BG(0,15);
	gotoxy(17,6);cout<<"MSSV: ";
	gotoxy(17,9);cout<<"MAMH: ";
	gotoxy(5,21);
}
void ShowChiTiet(MONHOC mh, int sl, int id[], char svchon[])
{
	char c;
	int soTrang = (sl%4>0)?sl/4+1:sl/4;
	int trang=1, flag=0, i, j;
	int slcauhoi=0;
	gotoxy(28,6);cout<<mh.tenmh;
	gotoxy(28,7);cout<<mh.mamh;
	gotoxy(28,8);cout<<sl;
	while(1){
		flag=0;
		j=0;
		DeleteScreen();
		modifyCursor(1, false);
		for(i = 0; i<sl&&flag<4; i++)
		{
			if(slcauhoi==sl)	break;	
			gotoxy(40,10+j); cout << "Cau "<<id[slcauhoi]<<": ";//slcauhoi+1
			gotoxy(48,10+j); cout << mh.dsch.ds[id[slcauhoi]].noidung;
			gotoxy(40,11+j); cout<<"A. "<<mh.dsch.ds[id[slcauhoi]].A;
			gotoxy(40,12+j); cout<<"B. "<<mh.dsch.ds[id[slcauhoi]].B;
			gotoxy(40,13+j); cout<<"C. "<<mh.dsch.ds[id[slcauhoi]].C;
			gotoxy(40,14+j); cout<<"D. "<<mh.dsch.ds[id[slcauhoi]].D;
			SetBGColor(14);
			gotoxy(40,15+j);cout<<"Dap an cau hoi: "<<mh.dsch.ds[id[slcauhoi]].DA<<" - Dap an nguoi dung chon: "<<svchon[slcauhoi];
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
void TimNhungMonSVThi(DSLOP dslop, TREE t, string masv, string mamh, int flag)// 0: in mon da thi; 1: cau hoi da thi
{
	PTRSV p;int vt=0;
	for(int i=1;i<=dslop.sl;i++){
			p=dslop.dsl[i]->dssv;
			p=searchStudent(p,masv);
			if(p!=NULL){	
				break;
			}
	}
	for(PTRDIEM q=p->data.dsdiem; q!=NULL; q=q->next)
	{
		NODE *m= TimKiem(t,q->info.mamh);
		if(m!=NULL){
			gotoxy(15,11+(++vt)); cout<<"MAMH: "<<q->info.mamh<<" - "<<m->mon.tenmh<<" - "<<q->info.score<<" diem ("<<q->info.slCH<<"cau)";
			int id[q->info.slCH+1]; char svchon[q->info.slCH+1];
			if(flag==1&&(mamh.compare(q->info.mamh))==0){
				BG(0,15);
				gotoxy(9,2);cout<<"                                                        ";
				gotoxy(9,3);cout<<"                                                        ";
				framecase11(0,"","","");
				for(int j=0; j<q->info.slCH; j++)
				{
					id[j]=q->info.cauhoisv[j].id;
					svchon[j]=q->info.cauhoisv[j].svchon;
				}
				ShowChiTiet(m->mon, q->info.slCH, id, svchon);
			}
		}
	}
}

void ChiTietBaiThi(DSLOP dslop, TREE t)
{
	FrameChiTietCauHoiThi();
	PTRSV p;string masv = NhapMa(6);
	if(masv!="")
	{
		gotoxy(23,6);cout<<masv;
	}
	for(int i=1;i<=dslop.sl;i++){
		p=dslop.dsl[i]->dssv;
		p=searchStudent(p,masv);
		if(p!=NULL)
			break;
		else 
		{
			gotoxy(20,12);BG(0,12);cout<<"MA SINH VIEN KHONG TON TAI";BG(0,15);
			return;
		}
	}
	for(int k=0; k<60; k++)// Xoa o thong bao
	{
		gotoxy(9+k,4);
		cout<<" ";
	}
	int lop=timlop(dslop, masv);
	SetBGColor(14);
	gotoxy(11,3);cout<<"Ho va ten: "<<p->data.ho+" "+p->data.tendem+" "+p->data.ten<<" - Lop: "<<dslop.dsl[lop]->tenlop;
	SetBGColor(15);
	TimNhungMonSVThi(dslop, t, masv, "", 0);
	string mamh = NhapMa(9);
	if(mamh!="")	TimNhungMonSVThi(dslop, t, masv, mamh, 1);
}
void FrameNhapDeXemDSDiem()//Khung lua chon de xem diem
{
	BG(0,15);
	resizeConsole(550,400);
	EmptyBox2(15,5,40,2,1);//MSSV
	EmptyBox2(15,8,40,2,1);//MAMH
	BG(0,3);
	gotoxy(14,2);cout<<"NHAP VAO MA LOP VA MA MON HOC DE XEM DIEM THI";
	BG(0,15);
	gotoxy(16,6);cout<<"MALOP: ";
	gotoxy(16,9);cout<<"MAMH: ";
	gotoxy(5,15);	
}
void FrameXemDSDiem()//Khung in diem
{
	BG(0,15);
	resizeConsole(800,750);
	EmptyBox2(15,6,75,30,1);
	for(int i=0; i<30; i++)
	for(int j=25; j<75;j+=25)
	{
		gotoxy(15+j,7+i);cout<<char(186);
	}
	gotoxy(40,6);cout<<char(203);
	gotoxy(65,6);cout<<char(203);
	gotoxy(40,36);cout<<char(202);
	gotoxy(65,36);cout<<char(202);
	for(int i=0; i<75;i++)
	{
		gotoxy(16+i,8);cout<<char(205);
	}
	gotoxy(15,8);cout<<char(204);
	gotoxy(40,8);cout<<char(206);
	gotoxy(65,8);cout<<char(206);
	gotoxy(90,8);cout<<char(185);
	SetColor(4);
	gotoxy(26,7);cout<<"MSSV";
	gotoxy(48,7);cout<<"HO VA TEN";
	gotoxy(74,7);cout<<"DIEM THI";
	BG(0,11);
	gotoxy(45,2);cout<<"BANG DIEM MON HOC";
	gotoxy(40,3);cout<<"LOP: ";
	gotoxy(40,4);cout<<"MON: ";
	gotoxy(4,35);
	BG(0,15);
}
void DiemTheoLop(DSLOP dslop, TREE t)//Lay thong tin diem theo lop va mon
{
	int vt=0;FrameNhapDeXemDSDiem();string malop=NhapMa(6);
	for(int i=1; i<=dslop.sl; i++)
	{
		if(malop.compare(dslop.dsl[i]->malop)==0)
		{
			string mamh=NhapMa(9);
			gotoxy(14,2);cout<<"                                                                    ";
			gotoxy(14,3);cout<<"                                                                    ";
			gotoxy(14,5);cout<<"                                                                    ";
			gotoxy(14,6);cout<<"                                                                    ";
			gotoxy(14,7);cout<<"                                                                    ";
			FrameXemDSDiem();
			BG(0,14);
			gotoxy(45,3);cout<<dslop.dsl[i]->malop<<" - "<<dslop.dsl[i]->tenlop;BG(0,15);
			
			for(PTRSV p=dslop.dsl[i]->dssv; p!=NULL; p=p->next)
			{
				NODE *m= TimKiem(t,p->data.dsdiem->info.mamh);
				if(m!=NULL) {
					gotoxy(45,4);cout<<m->mon.tenmh;
				}
				{
					gotoxy(23,9+vt);cout<<p->data.masv;
					gotoxy(42,9+vt);cout<<p->data.ho+" "+p->data.tendem+" "+p->data.ten;
					if(mamh.compare(p->data.dsdiem->info.mamh)!=0){gotoxy(73,9+vt);cout<<"Chua thi";}
					else{gotoxy(73,9+vt);cout<<p->data.dsdiem->info.score;}
				}vt++;
			}
			break;
		}
	}
	system("pause");
}
