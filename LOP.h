#pragma once
#include "function.h"


//============
int SearchLop(DSLOP &list, string ma) {
  for (int i =1; i <= list.sl ; i++)
     if (list.dsl[i]->malop.compare(ma)==0 ) return i;
  return -1;
}
int timlop(DSLOP dslop, string masv){
	PTRSV p;
	for(int i=1;i<=dslop.sl;i++){
		p=dslop.dsl[i]->dssv;
		p=searchStudent(p,masv);
		if(p==NULL){
			return -1;
		}else return i;
	}
}

int SearchSV(PTRSV list, string ma) {
  PTRSV p;int ktra=-1;
	p = list;
	while(p != NULL   )
		{
		if( p->data.masv.compare(ma)==0){ktra=1;break;}
		
		p = p->next;}
		
	return ktra ;
}
int SearchSV1(PTRSV list, string ma) {
 	PTRSV p;int ktra=1;
	p = list;
	while(p != NULL   )
		{
		if( p->data.masv.compare(ma)==0){return ktra;}
		ktra++;
		p = p->next;}
		
//	return ktra ;
}
//=============

PTRSV New_node(void)
{
  PTRSV p= new DSSV;
  p=NULL;
   return(p);
}


void clearlist(PTRSV &First)
{
   PTRSV p, q;  // q la nut truoc, p la nut sau
   p = First;
   while(First != NULL)
   {
      p = First;
      First = First->next;
      free(p);
   }
}
// Phep toan traverse: duyet danh sach lien ket
void traverse(PTRSV First)
{
   PTRSV p;
   int stt = 0;
   p = First;
   if(p == NULL)
      printf("\n   (Khong co sinh vien trong danh sach)");
   while(p != NULL)
   {
      cout<< p->data.masv<< p->data.ho<<p->data.ten<< p->data.phai<< p->data.password;
      p = p->next;
   }
}
void Insert_first(PTRSV &First, SV x)
{
   PTRSV p=new ds_sinhvien();
	p->data = x;
	p->next = NULL;
	if(First == NULL) First = p;
	else{
		p->next = First;
   		First = p;
	} 
   
}
void Insert_First1(PTRSV &First, PTRSV p)
{
   p->next = First;
   First = p;
}
/* Tac vu search_info: tim kiem theo phuong phap tim kiem tuyen tinh, neu khong tim thay ham nay tra ve NULL, neu tim thay ham nay tra ve con tro chi  nut tim thay */
PTRSV search_info(PTRSV First, string ma)
{
	PTRSV p;
	p = First;
	while(p != NULL && p->data.masv != ma  )
		p = p->next;
	return(p);
}
// Tac vu selectionsort: sap xep danh sach lien ket theo MSSV tang dan
void selectionsort(PTRSV &First)
{
   PTRSV p, q, pmin;
	SV min;
	for(p = First; p->next != NULL; p = p->next)
	{
		min = p->data;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next)
			if(min.masv > q->data.masv)
			{
				min = q->data;
				pmin = q;
			}
		// hoan doi truong info cua hai nut p va pmin
		pmin->data  = p->data;
		p->data 	  = min;
	}
}
int DemSinhVien1(PTRSV p)
{	
PTRSV q=p;
	int dem=0;
	
		while(q!=NULL){
		dem++;
		q=q->next;
		}
	return dem;
}


//==============
LOP* TaoLOP1()
{
	LOP *lop = new LOP;
	lop->malop="";
	lop->tenlop="";
	
	return lop;
}
int	 InsertLOP1(DSLOP &dslop, LOP lop, int i)
{
		dslop.dsl[i] = TaoLOP1();
		dslop.dsl[i]->malop = lop.malop;
		dslop.dsl[i]->tenlop= lop.tenlop;
}
void DeleteLop(DSLOP &dslop, int i)
{

	if (i<1 || i>dslop.sl )
	{
		return;
	}
	if (i == dslop.sl)
	{
		delete dslop.dsl[dslop.sl];
		dslop.sl--;
		dslop.dsl[dslop.sl+1] = NULL;
		return;
	}
	else
	{
		delete dslop.dsl[i];
		for (int temp = i ; temp <= dslop.sl; temp++)
		{
			dslop.dsl[temp - 1] = dslop.dsl[temp];
		}
		dslop.sl--;
		dslop.dsl[dslop.sl+1] = NULL; 
	}
	return;
}

void Delete_first(PTRSV &First)
{
   PTRSV p;
   if(p==NULL)
      printf("Khong co sinh vien trong danh sach");
   else
   {
      p = First;    // nut can xoa la nut dau
      First = p->next;
      free(p);
   }
}
int deleteAfter(PTRSV &p) {
	if (p == NULL) {
		BaoLoi( "p = NULL ");
		return 0;
	}
	if(p->next==NULL){
		BaoLoi("p-> next null");
	}
	else {
		PTRSV q = p->next;
		p->next = q->next;
		delete q;
	}
	return 1;
}
void NhapLop(DSLOP &list){
	LOP *lop=new LOP[MAXLOP];
	char c,s;
	int check=0;
	int i=0;
	int stt=0;
	khungNhap();
	gotoxy(10,16);cout<<"HUONG DAN";
	gotoxy(4,18);cout<<"NHAN ESC DE THOAT CHE DO NHAP";
	gotoxy(4,19);cout<<"NHAN ENTER DE LUU";
MALOP:
	lop[stt].malop="";
	while(1){
	gotoxy(10+i,9);
	c=GetKey();
		if(c==ESC){
			return;
		}else if(c==SPACE){
			GhiChu("ma lop khong duoc nhap khoang trang", 50,30,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				lop[stt].malop=lop[stt].malop.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma lop khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{			
				check=SearchLop(list, lop[stt].malop);
				if(check==-1) {
					
					i=0;
					gotoxy(12+i,11);
					goto TENLOP;
					
				}
				else {
					GhiChu("ma lop da ton tai",3,28,1000);
					Normal();
					continue;
				}
				}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(10+i,9);
			cout<<c;
			lop[stt].malop+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,9);
			cout<<c;
			lop[stt].malop+=c;	
		}	else {
			BaoLoi("ma lop khong chua ky tu dac biet");
			continue;
		}i++;
	}
	
TENLOP:
	lop[stt].tenlop="";
	while (1){
		gotoxy(12+i,11);
		fflush(stdin);
		s=GetKey();
		if(s==ESC){
		//	list.dsl[list.sl+1]->tenlop = lop[stt].tenlop;
			InsertLOP1(list,lop[stt],list.sl+1);
			list.sl++;
			return;
			//break;
		}else if(s==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				lop[stt].tenlop=lop[stt].tenlop.substr(0,i);
				cout<<s<<" "<<s;
				continue;
			}
		}else if(s==ENTER){
			if(i==0){
				BaoLoi("ten lop khong duoc de trong");
				Normal();
				continue;
			}else{	
					InsertLOP1(list,lop[stt],list.sl+1);
					list.sl++;
					i=0;
					gotoxy(10,9);cout << setw(15) << setfill(char(32)) << " ";
					gotoxy(12,11);cout << setw(20) << setfill(char(32)) << " ";
					gotoxy(12,11);
					stt++;
					goto MALOP;
				}
				
		}else if(s>=65 && s<= 90 || s>=48 && s<=57||s== SPACE){
			gotoxy(12+i,11);
			cout<<s;
			lop[stt].tenlop+=s;
		}else if(s>=97 && s<=122){
			s-=32;
			gotoxy(12+i,11);
			cout<<s;
			lop[stt].tenlop+=s;
		}	else {
			BaoLoi("ten lop khong chua ky tu dac biet");
			continue;
		}
		i++;
		
	}

}

void xoaLop(DSLOP &dslop){
	LOP *lop=new LOP[MAXLOP];
	char c,s;
	int check=0;
	
	int stt=0;

	box(3,7,30,8,10,10,"KHUNG XOA");
	for(int i=0;i<30;i++){
		gotoxy(4+i,10);cout<<char(196);
	}
	gotoxy(4,11);cout<<"MASV: ";
	gotoxy(10,16);cout<<"HUONG DAN";
	gotoxy(4,18);cout<<"NHAN ESC DE THOAT CHE DO XOA";
	gotoxy(4,19);cout<<"NHAN ENTER DE XOA";
MALOP:
	int i=0;
	lop[stt].malop="";
	while(1){
	gotoxy(12+i,11);
	c=GetKey();
		if(c==ESC){
			break;
		}else if(c==SPACE){
			GhiChu("ma lop khong duoc nhap khoang trang", 50,30,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				lop[stt].malop=lop[stt].malop.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma lop khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{			
				check=SearchLop(dslop, lop[stt].malop);
				if(check==-1) {
					GhiChu("ma lop chua ton tai",3,28,1000);
					Normal();
					continue;
				}
				else {
					if(dslop.dsl[check]->dssv!=NULL){
						GhiChu("danh sach lop da co sinh vien",3,28,1000);
						Normal();
						continue;
					}
					else {
					DeleteLop(dslop,check);
//					stt++;
//					gotoxy(12,11);cout << setw(15) << setfill(char(32)) << " ";
					break;
				//	goto MALOP;
					}
				}
				}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(12+i,11);
			cout<<c;
			lop[stt].malop+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(12+i,11);
			cout<<c;
			lop[stt].malop+=c;	
		}	else {
			BaoLoi("ma lop khong chua ky tu dac biet");
			continue;
		}i++;
	}
}
void suaLop(DSLOP &list){
	LOP *lop=new LOP[MAXLOP];
	char c,s;
	int check=0;
	int i=0;
	int stt=0;
	khungNhap();
	gotoxy(10,16);cout<<"HUONG DAN";
	gotoxy(4,18);cout<<"NHAN ESC DE THOAT CHE DO SUA";
	gotoxy(4,19);cout<<"NHAN ENTER DE LUU";
MALOP:
	lop[stt].malop="";
	while(1){
	gotoxy(10+i,9);
	c=GetKey();
		if(c==ESC){
			return;
		}else if(c==SPACE){
			GhiChu("ma lop khong duoc nhap khoang trang", 50,30,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				lop[stt].malop=lop[stt].malop.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma lop khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{			
				check=SearchLop(list, lop[stt].malop);
				if(check==-1) {
					GhiChu("ma lop chua ton tai",3,28,1000);
					Normal();
					continue;	
				}
				else {
					list.dsl[check]->malop = lop[stt].malop;
					i=0;
					gotoxy(12,11); goto TENLOP;
					
				}
				}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(10+i,9);
			cout<<c;
			lop[stt].malop+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,9);
			cout<<c;
			lop[stt].malop+=c;	
		}	else {
			BaoLoi("ma lop khong chua ky tu dac biet");
			continue;
		}i++;
	}
	
TENLOP:
	lop[stt].tenlop="";
	while (1){
		fflush(stdin);
		s=GetKey();
		if(s==ESC){
			list.dsl[check]->tenlop = lop[stt].tenlop;
			
			return;
			
		}else if(s==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				lop[stt].tenlop=lop[stt].tenlop.substr(0,i);
				cout<<c<<" "<<s;
				continue;
			}
		}else if(s==ENTER){
			if(i==0){
				BaoLoi("ten lop khong duoc de trong");
				Normal();
				continue;
			}else{	
					list.dsl[check]->tenlop = lop[stt].tenlop;
					i=0;
					gotoxy(10,9);cout << setw(15) << setfill(char(32)) << " ";
					gotoxy(12,11);cout << setw(20) << setfill(char(32)) << " ";
					gotoxy(12,11);
					stt++;
					goto MALOP;
				}
				
		}else if(s>=65 && s<= 90 || s>=48 && s<=57||s== SPACE){
			gotoxy(12+i,11);
			cout<<s;
			lop[stt].tenlop+=s;
		}else if(s>=97 && s<=122){
			s-=32;
			gotoxy(12+i,11);
			cout<<s;
			lop[stt].tenlop+=s;
		}	else {
			BaoLoi("ten lop khong chua ky tu dac biet");
			continue;
		}
		i++;
		
	}

}



void xemdslop(DSLOP &dslop){
	int key;
	int dem = 0;
	int trang = 0, tongtrang = 0;
	Normal();
	box(1,1,135,30,10,10,"");
	
	while (1)
	{
	Normal();
	box(3,5,30,22,10,10,"");
	gotoxy(3,3);cout<<"DANG NHAP VOI VAI TRO GIAO VIEN";
	gotoxy(6,9);cout<<"HUONG DAN";
	gotoxy(4,12);cout<<"NHAN INSERT DE NHAP";
	gotoxy(4,13);cout<<"NHAN DELETE DE XOA";
	gotoxy(4,14);cout<<"NHAN F4 DE SUA";
	gotoxy(4,15);cout<<"NHAN ESC DE TRO VE";
	
		if (dslop.sl == 0)
		{
			BaoLoi("dsrong");
		}
		else {
			if (dslop.sl < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((dslop.sl - 1) / 15 + 1);
			}
		}
		
		Normal();
		xoaKhung(50,1);
		frame3(50,2,60,18,10,10,"STT","MA LOP","TEN LOP");
		dem = 0;
		for (int i = trang * 15; i < 15 + trang * 15 && i < dslop.sl; i++)
		{
			gotoxy(60,5+dem);cout<<i+1;
			gotoxy(71,5+dem);cout<<dslop.dsl[i+1]->malop;
			gotoxy(92,5+dem); cout<<dslop.dsl[i+1]->tenlop;
		dem++;
		}
		HienThiTrang(trang + 1, tongtrang, 73, 26);
		key = GetKey(); 
		if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
		if ((key == LEFT || key == UP) && trang > 0) { trang--; }
		if(key==INSERT) {NhapLop(dslop);}
		if(key==Delete) {xoaLop(dslop);}
		if(key==F4) {suaLop(dslop);}
		if(key==ESC){break;}
}
}
void xemTrang(DSLOP dslop,int trang){
	int dem=1;
	for(int i=trang*15;i<trang*15+15 && i<dslop.sl;i++){
			gotoxy(60,3+dem);cout<<i+1;
			gotoxy(71,3+dem);cout<<dslop.dsl[i+1]->malop;
			gotoxy(92,3+dem); cout<<dslop.dsl[i+1]->tenlop;
		dem++;
	}
}
void in1sv(SV sv,int dem){
		gotoxy(36,4+dem);cout<<sv.masv;
		gotoxy(51,4+dem); cout<<sv.ho;
		gotoxy(66,4+dem); cout<<sv.tendem;
		gotoxy(81,4+dem); cout<<sv.ten;
		gotoxy(97,4+dem); cout<<sv.phai;
		gotoxy(111,4+dem); cout<<sv.password;
}
void xemTrangSv(PTRSV p,int trang){
	Normal();
	PTRSV q=p;
	int dem=0;
	int sl=DemSinhVien1(q);
	SV *sv=new SV[sl];
	for(int i=0;i<sl;i++){
		sv[i]=q->data;
		q=q->next;	
	}
	for(int i=trang*15;i<sl && i<trang*15+15;i++){
		in1sv(sv[i],dem);
	
		dem++;
	}
}
void xuly1dong(DSLOP dslop, int trang,int vitri,int mau){
	if (mau == 1)
		HighLight();
	else Normal();
	gotoxy(60,3+vitri);cout<<vitri;
	gotoxy(71,3+vitri);cout<<dslop.dsl[15*trang+vitri]->malop;
	gotoxy(92,3+vitri);cout<<dslop.dsl[15*trang+vitri]->tenlop;
}
int chonLOP(DSLOP dslop){
  int key;
	int dem = 0;
	int trang = 0, tongtrang = 0;
	int chon=1;
	Normal();
	box(1,1,115,30,10,10,"");
	box(3,7,30,20,10,10,"");
	gotoxy(3,3);cout<<"DANG NHAP VOI VAI TRO GIAO VIEN";
	gotoxy(10,9);cout<<"HUONG DAN";
	gotoxy(4,12);cout<<"NHAN ENTER DE CHON LOP ";
	gotoxy(6,14);cout<<"^";
	gotoxy(6,16);cout<<"v";
	gotoxy(4,15);cout<<"<";
	gotoxy(8,15);cout<<">";
	while (1)
	{
		if (dslop.sl == 0)
		{
			BaoLoi("dsrong");
		}
		else {
			if (dslop.sl < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((dslop.sl - 1) / 15 + 1);
			}
		}
		Normal();
		frame3(50,1,60,18,10,10,"STT","MA LOP","TEN LOP");
		xemTrang(dslop,trang);
		HienThiTrang(trang + 1, tongtrang, 73, 26);
		
		xuly1dong(dslop,trang,chon,1);
		key = GetKey();
		switch(key){
		case RIGHT: {
				
			if(trang<tongtrang-1)trang ++;
			Normal();
              	gotoxy(50,5+chon);//xuly1dong(dslop,trang,chon,0);
				chon=1;	
				Normal();
              	gotoxy(50,5+chon);xuly1dong(dslop,trang,chon,1);
			break;
		}
		case LEFT:{
			if(trang>0)trang--;
			break;
		}case UP :{
			if(chon==1){
    			Normal();
              	gotoxy(50,5+chon);xuly1dong(dslop,trang,chon,0);
              	if(tongtrang-trang>1){chon=15;}
              	else chon=dslop.sl-trang*15;
              	HighLight();
              	gotoxy(50,5+chon);xuly1dong(dslop,trang,chon,1);
				break;
		}	else if (chon >1)
  			  {
              	xuly1dong(dslop,trang,chon,0);
              	chon -=1;
              	xuly1dong(dslop,trang,chon,1);
  				
  			  }
			break;
		}case DOWN:{
			if(chon==15){
              	xuly1dong(dslop,trang,chon,0);
              	chon =1;
              	xuly1dong(dslop,trang,chon,1);
				break;
		}	else if (chon <dslop.sl-trang*15)
  			  {
              	xuly1dong(dslop,trang,chon,0);
              	chon +=1;
              	xuly1dong(dslop,trang,chon,1);	
  			  }
			break;
		}case ESC:{
			break;
		}case ENTER:{
			 return chon+trang*15;
			
		}
	}
}
}
void NhapSV(PTRSV &p){

	char c;
	PTRSV sv;
	LOP lop;
	
	int i;
MASV:
	xoaKhungNhapSV(3,5);
	khungnhapSV();
	gotoxy(4,18);cout<<"NHAN ENTER DE LUU ";
	gotoxy(4,19);cout<<"NHAN ESC DE THOA CHE DO NHAP";
	sv=new DSSV;
	 i=0;
while(1){
		gotoxy(10+i,9);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==SPACE){
			GhiChu("ma sinh vien khong duoc nhap khoang trang", 50,30,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.masv=sv->data.masv.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma sinh vien khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{		
	
				int checkSV=SearchSV(p, sv->data.masv);
				if(checkSV==-1) {
					gotoxy(10,10);
					goto HO;
					
				}
				else {
					BaoLoi("ma sinh vien da ton tai");
					Normal();
					continue;
				}
				}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(10+i,9);
			cout<<c;
			sv->data.masv+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,9);
			cout<<c;
			sv->data.masv+=c;	
		}i++;
	}
HO:
	 i=0;
while(1){
		gotoxy(10+i,10);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.ho=sv->data.ho.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ho sinh vien khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{	
					gotoxy(10,11);
					goto TENDEM;
					
				}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(10+i,10);
			cout<<c;
			sv->data.ho+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,10);
			cout<<c;
			sv->data.ho+=c;	
		}i++;	
}
TENDEM:
	i=0;
while(1){
		fflush(stdin);
		int vitri=DemSinhVien1(p);
		
		gotoxy(13+i,11);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;sv->data.tendem=sv->data.tendem.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){	
					gotoxy(13+i,12);
					goto TEN;
		
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(13+i,11);
			cout<<c;
			sv->data.tendem+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(13+i,11);
			cout<<c;
			sv->data.tendem+=c;	
		}i++;	
}
TEN:
	sv->data.ten=""; i=0;
	while(1){
		fflush(stdin);
	
		gotoxy(13+i,12);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.ten=sv->data.ten.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){	
			if(i==0){
				BaoLoi("TENSV khong duoc de trong");
				continue;
			}
			else{
					gotoxy(13+i,13);
					goto PHAI;
	}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(13+i,12);
			cout<<c;
			sv->data.ten+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(13+i,12);
			cout<<c;
			sv->data.ten+=c;	
		}i++;	
}
PHAI:
	 i=0;
	while(1){
		fflush(stdin);
		gotoxy(13+i,13);
		c=GetKey();
		if(c==ESC){	
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.phai=sv->data.phai.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(sv->data.phai.compare("NAM")==0||sv->data.phai.compare("NU")==0)	
					{
					gotoxy(13+i,14);
					goto PASS;	}
			else{
				BaoLoi("NAM or NU");continue;
			}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(13+i,13);
			cout<<c;
			sv->data.phai+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(13+i,13);
			cout<<c;
			sv->data.phai+=c;	
		}i++;	
}
PASS:
sv->data.password=""; i=0;
while(1){
		
		gotoxy(15+i,14);
		c=GetKey();
		if(c==ESC){
		if(i<6) { BaoLoi("Password it nhat 6 ky tu!");continue;}
		else Insert_First1(p,sv);
		return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.password=sv->data.password.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){	

					Insert_First1(p,sv);
					goto MASV;
						
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(15+i,14);
			cout<<c;
			sv->data.password+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(15+i,14);
			cout<<c;
			sv->data.password+=c;	
		}i++;	
}

}
void xoaSV(PTRSV &p){
	char c;
	PTRSV sv;
	LOP lop;
	int i;
MASV:
	box(3,7,30,8,10,10,"KHUNG XOA SINH VIEN");
	for(int i=0;i<30;i++){
		gotoxy(4+i,10);cout<<char(196);
	}
	gotoxy(4,12);cout<<"MA LOP: ";
	gotoxy(4,18);cout<<"NHAN ENTER DE XOA ";
	gotoxy(4,19);cout<<"NHAN ESC DE THOAT CHE DO XOA ";
	sv=new DSSV;
	 i=0;
while(1){
		gotoxy(10+i,12);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==SPACE){
			GhiChu("ma sinh vien khong duoc nhap khoang trang", 50,30,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.masv=sv->data.masv.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma sinh vien khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{		
	
				int check=SearchSV(p, sv->data.masv);
				if(check==-1){
					GhiChu("ma sinh vien chua ton tai",50,30,900);
					Normal();
					continue;
				}else{
					int check1=SearchSV1(p,sv->data.masv);
					if(check1==1)Delete_first(p);
					else {PTRSV q=nodepointer(p,check1-1);
					deleteAfter(q);	}
					gotoxy(10,12);cout << setw(25) << setfill(char(32)) << " ";
					BaoLoi("da xoa ma sinh vien!!!");
					break;
					}	
				
			}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(10+i,12);
			cout<<c;
			sv->data.masv+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,12);
			cout<<c;
			sv->data.masv+=c;	
		}i++;
	}


}
void insv(SV sv){
	gotoxy(10,9);cout<<sv.masv;
	gotoxy(10,10);cout<<sv.ho;
	gotoxy(13,11);cout<<sv.tendem;
	gotoxy(13,12);cout<<sv.ten;
	gotoxy(13,13);cout<<sv.phai;
	gotoxy(15,14);cout<<sv.password;
}
void suaSV(PTRSV &p){

	char c;
	int i;
MASV:
	PTRSV sv=new DSSV;
	PTRSV checkSV;
	xoaKhungNhapSV(3,5);
	khungnhapSV();
	gotoxy(4,18);cout<<"NHAN ENTER DE LUU ";
	gotoxy(4,19);cout<<"NHAN ESC DE THOAT  ";
	sv->data.masv="";
	 i=0;
while(1){
		gotoxy(10+i,9);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==SPACE){
			GhiChu("ma sinh vien khong duoc nhap khoang trang", 50,30,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.masv=sv->data.masv.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma sinh vien khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{		
	
				 checkSV=searchStudent(p, sv->data.masv);
				if(checkSV==NULL) {
					BaoLoi("ma sinh vien chua ton tai");
					Normal();
					continue;
				}
				else {
					insv(checkSV->data);
					gotoxy(10+checkSV->data.ho.length(),10);
					
					goto HO;
					
				}
				}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(10+i,9);
			cout<<c;
			sv->data.masv+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,9);
			cout<<c;
			sv->data.masv+=c;	
		}i++;
	}
HO:
	sv->data.ho=checkSV->data.ho; 
	 i=sv->data.ho.length();
while(1){
		gotoxy(10+i,10);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.ho=sv->data.ho.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ho sinh vien khong duoc de trong",50,30,900);
				Normal();
				continue;
			}else{			
					gotoxy(10,11);
					checkSV->data.ho=sv->data.ho;
					goto TENDEM;
					
				}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(10+i,10);
			cout<<c;
			sv->data.ho+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(10+i,10);
			cout<<c;
			sv->data.ho+=c;	
		}i++;	
}
TENDEM:
	sv->data.tendem=checkSV->data.tendem;
	i=sv->data.tendem.length();
while(1){
		fflush(stdin);
		int vitri=DemSinhVien1(p);
		
		gotoxy(13+i,11);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;sv->data.tendem=sv->data.tendem.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){	
					checkSV->data.tendem=sv->data.tendem;
					gotoxy(13+i,12);
					goto TEN;
		
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(13+i,11);
			cout<<c;
			sv->data.tendem+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(13+i,11);
			cout<<c;
			sv->data.tendem+=c;	
		}i++;	
}
TEN:
	sv->data.ten=checkSV->data.ten;
	i=sv->data.ten.length();
	while(1){
		fflush(stdin);
	
		gotoxy(13+i,12);
		c=GetKey();
		if(c==ESC){
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.ten=sv->data.ten.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){	
			if(i==0){
				BaoLoi("TENSV khong duoc de trong");
				continue;
			}
			else{
					checkSV->data.ten=sv->data.ten;
					gotoxy(13+i,13);
					goto PHAI;
	}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(13+i,12);
			cout<<c;
			sv->data.ten+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(13+i,12);
			cout<<c;
			sv->data.ten+=c;	
		}i++;	
}
PHAI:
	sv->data.phai=checkSV->data.phai;
	i=sv->data.phai.length();
	while(1){
		fflush(stdin);
		gotoxy(13+i,13);
		c=GetKey();
		if(c==ESC){	
			return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.phai=sv->data.phai.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(sv->data.phai.compare("NAM")==0||sv->data.phai.compare("NU")==0)	
					{
					checkSV->data.phai=sv->data.phai;
					gotoxy(13+i,14);
					goto PASS;	}
			else{
				BaoLoi("NAM or NU");continue;
			}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(13+i,13);
			cout<<c;
			sv->data.phai+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(13+i,13);
			cout<<c;
			sv->data.phai+=c;	
		}i++;	
}
PASS:
	sv->data.password=checkSV->data.password;
	i=sv->data.password.length();
while(1){
		
		gotoxy(15+i,14);
		c=GetKey();
		if(c==ESC){
		if(i<6) { BaoLoi("Password it nhat 6 ky tu!");continue;}
		else {checkSV->data.password=sv->data.password;}
		return;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				sv->data.password=sv->data.password.substr(0,i);
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){	

				//	Insert_First1(p,sv);
				checkSV->data.password=sv->data.password;
					goto MASV;
						
		}else if(c>=65 && c<= 90 || c>=48 && c<=57|| c==SPACE){
			gotoxy(15+i,14);
			cout<<c;
			sv->data.password+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(15+i,14);
			cout<<c;
			sv->data.password+=c;	
		}i++;	
}
}

void xemdssv(DSLOP &dslop,int malop){

	int key;
	int dem = 0;
	int trang = 0, tongtrang = 0;
	int slsv=0;
		slsv=DemSinhVien1(dslop.dsl[malop]->dssv);
		
			BG(0,15);
			box(1,1,125,30,10,10,"");
			
		
		//	system("cls");Normal();
			frame6(35,1,90,18,0,10,"MASV","HO","TENDEM","TEN","PHAI","PASSWORD");
		while(1){
			box(3,4,30,23,10,10,"");
			SetColor(4);
			gotoxy(3,3);cout<<"DANG NHAP VOI VAI TRO GIAO VIEN";
			SetColor(0);
			SetBGColor(11);
			gotoxy(4,9); cout<<"      HUONG DAN";
			SetBGColor(15);
			gotoxy(4,12);cout<<"   NHAN INSERT DE NHAP";
			gotoxy(4,13);cout<<"   NHAN DELETE DE XOA";
			gotoxy(4,14);cout<<"   NHAN F4 DE SUA";
			gotoxy(4,15);cout<<"   NHAN ESC DE TRO VE";
			if (slsv < 15)
			{
				tongtrang = 1;
				trang = 0;
			}
			else {
				tongtrang = ((slsv - 1) / 15 + 1);
			}
			
			xemTrangSv(dslop.dsl[malop]->dssv,trang);
			Normal();
			HienThiTrang(trang + 1, tongtrang, 73, 26);	
			key = GetKey(); //Bat Phim
			if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
			if ((key == LEFT || key == UP) && trang > 0) { trang--; }
			if(key==INSERT){NhapSV(dslop.dsl[malop]->dssv);} 
			if(key==Delete){xoaSV(dslop.dsl[malop]->dssv);}
			if(key==F4){suaSV(dslop.dsl[malop]->dssv);}
			if(key==ESC)break;
		
		}
}

void IndsLop(DSLOP &ds){
	for(int i=1; i<=ds.sl;i++){
	
	cout<<"danh sach: "<<i<<endl;
	cout<<"ma lop:"<<ds.dsl[i]->malop<<",";
	 cout<<"ten lop: "<<ds.dsl[i]->tenlop<<endl;
	}
}
void Indssv(DSLOP dslop)
{
	for(int i=1;i<=dslop.sl;i++){
		cout<<"\n=========";
		cout<<"\n ma lop: "<<dslop.dsl[i]->malop;
		PTRSV p=dslop.dsl[i]->dssv;
		while(p!=NULL){
			
			cout<<"\n ma sv: "<< p->data.masv;
			cout<<"\n ten sv"<< p->data.ten;
			p=p->next;
		}
	
	}
}
