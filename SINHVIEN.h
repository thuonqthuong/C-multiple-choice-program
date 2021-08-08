//------------ danh sach sinh vien----------
//-----------lien ket don-------------
#include "ctdl.h"
#include "function.h"
 PTRSV First;
 SV sv;
 PTRSV p;

void khoitaolist(DSLOP &dslop){
	for(int i=1;i<=dslop.sl;i++){
		dslop.dsl[i].dssv=NULL;
	}
}
PTRSV  khoitaonode(SV sv){
	PTRSV p= new DSSV;
	p->data=sv;
	p->next=NULL;
	return p;
}

// Phep toan New_node: cap phat mot nut cho danh sach lien ket
PTRSV New_node(void)
{
  PTRSV p= new DSSV;
  p=NULL;
   //p = (PTRSV)malloc(sizeof(struct DSSV));
   return(p);
}
/* Tac vu nodepointer: xac dinh con tro cua nut i trong danh sach lien ket
   (i = 2, ...) */
PTRSV nodepointer(PTRSV First, int i)
{
	PTRSV p;
	int vitri=1;
	p = First;
	while(p != NULL && vitri < i)
	{
		p = p->next;
		vitri++;
	}
	return(p);
}
// Tac vu position: xac dinh vi tri cua nut p trong danh sach lien ket
int position(PTRSV First, PTRSV p)
{
	int vitri;
	PTRSV q;
	q = First;
	vitri = 1;
	while(q != NULL && q != p)
	{
		q = q->next;
		vitri++;
	}
   if(q == NULL)
      return(-1);
   return(vitri);
}
// Phep toan initialize: khoi dong danh sach lien ket
void initialize(PTRSV &First)
{
   First = NULL;
}
// Tac vu Empty: kiem tra danh sach lien ket co bi rong khong
int Empty(PTRSV First)
{
   return(First == NULL ? TRUE : FALSE);
}
// Phep toan Insert_first: them nut moi vao dau danh sach lien ket
void Insert_first(PTRSV &First, SV x)
{
   PTRSV p;
   p = New_node();
   p->data = x;
   p->next = First;
   First = p;
}
// Phep toan Insert_after: them nut moi sau nut co dia chi p
void Insert_after(PTRSV p, SV x)
{
   PTRSV q;
   if(p == NULL)
		printf("khong them sinh vien vao danh sach duoc");
   else
   {
      q = New_node();
      q->data = x;
      q->next = p->next;
      p->next = q;
   }
}
// Phep toan Delete_first: xoa nut o dau danh sach lien ket
void Delete_first(PTRSV &First)
{
   PTRSV p;
   if(Empty(First))
      printf("Khong co sinh vien trong danh sach");
   else
   {
      p = First;    // nut can xoa la nut dau
      First = p->next;
      free(p);
   }
}
// Tac vu Delete_after: xoa nut sau nut p
void Delete_after(PTRSV p)
{
   PTRSV q;
   // neu p la NULL hoac p chi nut cuoi
   if((p == NULL) || (p->next == NULL))
      printf("khong xoa sinh vien nay duoc");
   else
   {
      q = p->next;  // q chi nut can xoa
      p->next = q->next;
      free(q);
   }
}
/* Phep toan Insert_Order: Phep toan nay chi su dung khi them nut vao danh sach lien ket da co thu tu */
void Insert_Order(PTRSV &First, SV x)
{
   PTRSV p, q;  // q la nut truoc, p la nut sau
   q = NULL;
   for(p = First; p != NULL && p->data.masv< x.masv; p = p->next)
      q = p;
   if(q == NULL)  // them nut vao dau danh sach lien ket
      Insert_first(First, x);
   else           // them nut vao sau nut q
      Insert_after(q, x);
}
// Phep toan clearlist: xoa tat ca cac nut trong danh sach lien ket
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

int NhapSV(DSLOP &dslop){
	char c,ten,td,ho,p,pa;
	int check=0;
	int i=0;
	SV sv;
	LOP lop;
	gotoxy(1,1);cin>>lop.malop;
	check=SearchLop(dslop,lop.malop);
	if(check==-1){
		GhiChu("ma lop khong ton tai!",50,50,900);
	}else {
		// nhap ma sinh vien
MASV:
while(1){
		fflush(stdin);
		int vitri=0;
		gotoxy(25+i,vitri);
		c=GetKey();
		if(c==ESC){
			for(int j=0;j<=i;i++)
			return ESC;
		}else if(c==SPACE){
			GhiChu("ma sinh vien khong duoc nhap khoang trang", 50,50,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma sinh vien khong duoc de trong",50,50,900);
				Normal();
				continue;
			}else{			
				check=SearchSV(dslop.dsl[check].dssv, sv.masv);
				if(check==-1) {
					dslop.dsl[check].dssv->data.masv=sv.masv;
					i=0;
					gotoxy(41+25+i,3+vitri);
					goto HO;
					
				}
				else {
					BaoLoi("ma lop da ton tai");
					Normal();
					continue;
				}
				}
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(41+i,3+vitri);
			cout<<c;
			sv.masv+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(41+i,3+vitri);
			cout<<c;
			sv.masv+=c;	
		}i++;
	}
HO:
while(1){
		fflush(stdin);
		int vitri=0;
		gotoxy(25+i,vitri);
		c=GetKey();
		if(c==ESC){
			for(int j=0;j<=i;i++)
			return ESC;
		}else if(c==SPACE){
			GhiChu("ma sinh vien khong duoc nhap khoang trang", 50,50,900);
			Normal();
			continue;
		}else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				cout<<c<<" "<<c;
				continue;
			}
		}else if(c==ENTER){
			if(i==0){
				GhiChu("ma sinh vien khong duoc de trong",50,50,900);
				Normal();
				continue;
			}else{			
				
					dslop.dsl[check].dssv->data.masv=sv.masv;
					i=0;
					gotoxy(41+25+i,3+vitri);
					goto HO;
					
				}
			
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(41+i,3+vitri);
			cout<<c;
			sv.masv+=c;
		}else if(c>=97 && c<=122){
			c-=32;
			gotoxy(41+i,3+vitri);
			cout<<c;
			sv.masv+=c;	
		}i++;
	
	
}
//HO:
//TEN:
//PHAI:
//PASS:
}

}




