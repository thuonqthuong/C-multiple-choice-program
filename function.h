#pragma once
#include "ctdl.h"


const int so_item = 15;
int pointer = 0;
const int dong =5;
const int cot = 20 ;
const int Up = 72;
const int Down = 80;
const int SPACE = 32;
const int ENTER = 13;
const int ESC = 27;
const int BSPACE = 8;
const int TAB=9;
const int DOWN =-80;
const int UP =-72;
const int LEFT= -75;
const int RIGHT= -77;
const int Delete = -83;
const int INSERT = -82;
const int F1 = -59;
const int F2 = -60;
const int F4 = -62;
char* cauhoi = "CauHoi.txt";
void Normal () {
	SetColor(90);
	SetBGColor(247);
}

void HighLight () {
	SetColor(20);
	SetBGColor(15);
}
void box(int x, int y,int w,int h,int t_color,int b_color, string nd)
{

	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	SetColor(t_color);
	gotoxy(x + 1, y + 1);
	cout << nd;
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y);cout << char(218);
	gotoxy(x + w, y);cout << char(191);
	gotoxy(x, y + h);cout << char(192);
	gotoxy(x + w, y + h);cout << char(217);

}
void frame2(int x, int y,int w,int h, int t_color,int b_color, string nd1, string nd2)
{

	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
			
		}
	}
	SetColor(t_color);
	gotoxy(x + 1, y + 1);
	cout << nd1;
	gotoxy(x+w/2+1,y+1);
	cout<<nd2;
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int ix = x+1;ix < x + w;ix++){
		gotoxy(ix, y+2);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
		
	}
	
	for(int iy=y+1; iy<y+h;iy++){
		gotoxy(x + w/2, iy);
		cout << char(179);
	}
	gotoxy(x, y);cout << char(218);
	gotoxy(x + w, y);cout << char(191);
	gotoxy(x, y + h);cout << char(192);
	gotoxy(x + w, y + h);cout << char(217);
	

}
void frame3(int x, int y,int w,int h, int t_color,int b_color, string nd1, string nd2, string nd3)
{
//	SetBGColor(15);
	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
			
		}
	}
	SetColor(t_color);
	gotoxy(x + 1, y + 1);
	cout << nd1;
	gotoxy(x+w/3+1,y+1);
	cout<<nd2;
	gotoxy(x+2*w/3+2,y+1);
	cout<<nd3;
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int ix = x+1;ix < x + w;ix++){
		gotoxy(ix, y+2);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x+w, iy);
		cout << char(179);
	}
	
	for(int iy=y+1; iy<y+h;iy++){
		gotoxy(x + w/3, iy);
		cout << char(179);
		
		gotoxy(x + 2*w/3+1, iy);
		cout << char(179);
	}
	gotoxy(x, y);cout << char(218);
	gotoxy(x + w, y);cout << char(191);
	gotoxy(x, y + h);cout << char(192);
	gotoxy(x + w, y + h);cout << char(217);
}
void frame5(int x, int y,int w,int h, int t_color,int b_color, string nd1, string nd2, string nd3, string nd4, string nd5)
{

	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
			
		}
	}
	SetColor(t_color);
	gotoxy(x + 1, y + 1);
	cout << nd1;
	gotoxy(x+w/5+1,y+1);
	cout<<nd2;
	gotoxy(x+2*w/5+1,y+1);
	cout<<nd3;
	gotoxy(x+3*w/5+1,y+1);
	cout<<nd4;
	gotoxy(x+4*w/5+2,y+1);
	cout<<nd5;
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int ix = x+1;ix < x + w;ix++){
		gotoxy(ix, y+2);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
		
	}
	for(int iy=y+1; iy<y+h;iy++){
		gotoxy(x + w/5, iy);
		cout << char(179);
		gotoxy(x + 2*w/5, iy);
		cout << char(179);
		gotoxy(x + 3*w/5, iy);
		cout << char(179);
		gotoxy(x + 4*w/5, iy);
		cout << char(179);
	}
	gotoxy(x, y);cout << char(218);
	gotoxy(x + w, y);cout << char(191);
	gotoxy(x, y + h);cout << char(192);
	gotoxy(x + w, y + h);cout << char(217);

}
void frame6(int x, int y,int w,int h, int t_color,int b_color, string nd1, string nd2, string nd3, string nd4, string nd5, string nd6)
{
	Normal();

	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
			
		}
	}
	SetColor(t_color);
	gotoxy(x + 1, y + 1);
	cout << nd1;
	gotoxy(x+w/6+1,y+1);
	cout<<nd2;
	gotoxy(x+2*w/6+1,y+1);
	cout<<nd3;
	gotoxy(x+3*w/6+1,y+1);
	cout<<nd4;
	gotoxy(x+4*w/6+2,y+1);
	cout<<nd5;
	gotoxy(x+5*w/6+2,y+1);
	cout<<nd6;
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int ix = x+1;ix < x + w;ix++){
		gotoxy(ix, y+2);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
		
	}
	for(int iy=y+1; iy<y+h;iy++){
		gotoxy(x + w/6, iy);
		cout << char(179);
		gotoxy(x + 2*w/6, iy);
		cout << char(179);
		gotoxy(x + 3*w/6, iy);
		cout << char(179);
		gotoxy(x + 4*w/6, iy);
		cout << char(179);
		gotoxy(x + 5*w/6, iy);
		cout << char(179);
	}
	gotoxy(x, y);cout << char(218);
	gotoxy(x + w, y);cout << char(191);
	gotoxy(x, y + h);cout << char(192);
	gotoxy(x + w, y + h);cout << char(217);

}
int GetKey()
{
	char key;
	key = _getch();
	if (key == -32 || key == 0)
		return -_getch();
	else return key;
}
void HienThiTrang(int trang, int tongtrang, int x, int y) {
	SetBGColor(15);
	gotoxy(x, y); cout << " Trang:        ";
	gotoxy(x + 8, y); cout << trang << "/" << tongtrang;
	
}
void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  Sleep(4000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}
void GhiChu(char c[], int x, int y, int sleep)
{

	gotoxy(x, y);
	HighLight();
	cout << c;
	Sleep(sleep);
	gotoxy(x, y);
//	HighLight();
	for (int j = 0; j <= strlen(c); j++)
	{
		cout << ' ';
	}

}
string  NhapUser(string user, int max){
	gotoxy(50,4);
	int i=0;
	char c;
	while(i<=max){
		c = GetKey();
		if(c==SPACE){
			GhiChu("khong duoc nhap khoang trang!",35, 27,  1000);
			Normal();
			continue;
		}if(c==ENTER){
			if (i==0){
				GhiChu("username khong duoc de trong",35, 27, 1000);
				Normal();
				continue;
			}else
			{
				return user;
			}
		}
		if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				user=user.substr(0,i);
				cout << c << " " << c;
				continue;
			}
		} if(c==ESC){
			break;
		} if(i==max){
			Normal();
			GhiChu("vuot qua ky tu quy dinh",35, 27,  1000);
			continue;
		}else if(c>=65 && c<= 90 || c>=48 && c<=57){
			gotoxy(50+i,4);
			cout<<c;
			user += c;
				i++;
		}else if(c>=97 && c<=122){
			c-=32;
			user += c;
			gotoxy(50+i,4);
			cout << c;       //    user= GV	
				i++;
		}
		
	}
	return user;
}

string  NhapPass(int max){
	gotoxy(50,5);
	int i=0;
	char c;
	string pass="";
	while(i<=max){
		c = GetKey();
		if(c==SPACE){
			GhiChu("khong duoc nhap khoang trang!",35, 27,  1000);
			Normal();
			continue;
		}else if(c==ENTER){
			if (i==0){Normal();
				GhiChu("password khong duoc de trong",35, 27, 1000);
				Normal();
				continue;
			}else
			{
				gotoxy(50,5);cout<< "*";
				return pass;
			}
		}
		else if(c==BSPACE){
			if (i == 0)	continue;
			else 
			{
				--i;
				pass=pass.substr(0,i);
				cout << c << " " << c;
				continue;
			}
		}else if(c==ESC){
			break;
		}else if(i==max){
			Normal();
			GhiChu("vuot qua ky tu quy dinh",35, 27,  1000);
		}else if(c>=65 && c<= 90 || c>=48 && c<=57) {
			pass += c;
			gotoxy(50+i,5);cout << "*";
		}else if(c>=97 && c<=122){
			c=c-32;
			pass += c;
			gotoxy(50+i,5);cout << "*";
		}
		i++;
	}
	return pass;
}
void khungNhap(){
	Normal();
	box(3,5,30,10,10,10,"nhap dang sach lop");
	for(int i=0;i<30;i++){
		gotoxy(4+i,7);cout<<char(196);
	}
	gotoxy(4,9);cout<<"MALOP: ";
	gotoxy(4,11);cout<<"TENLOP: ";
}
void khungnhapSV(){
	Normal();
	box(3,5,30,10,10,10,"Nhap Danh Sach Sinh Vien");
	for(int i=0;i<30;i++){
		gotoxy(4+i,7);cout<<char(196);
	}
	gotoxy(4,9);cout<<"MASV: ";
	gotoxy(4,10);cout<<"HO: ";
	gotoxy(4,11);cout<<"TENDEM: ";
	gotoxy(4,12);cout<<"TENSV: ";
	gotoxy(4,13);cout<<"PHAI: ";
	gotoxy(4,14);cout<<"PASSWORD: ";
	
}

void xoaKhung(int x, int y){
	for(int i = 0; i < 20; i++){
		gotoxy(x, y+i);
		cout << setw(65) << setfill(char(32)) << " ";
	}
}
void xoaKhungNhapSV(int x, int y){
	for(int i = 0; i < 10; i++){
		gotoxy(x, y+i);
		cout << setw(30) << setfill(char(32)) << " ";
	}
}
PTRSV searchStudent(PTRSV First, string ma)
{
	for(PTRSV p = First; p != NULL; p = p->next)
		if(p->data.masv.compare(ma)==0)	return p;
	return NULL;
}
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
int dangNhap(DSLOP dslop, string user, string pass){
	PTRSV p;
	for(int i=1;i<=dslop.sl;i++){
		p=dslop.dsl[i]->dssv;
		p=searchStudent(p,user);
		if(p==NULL){
			return -1;
		}else{
			if(pass.compare(p->data.password)==0) return 1;
			else return -1;
		}
	}
}
void resizeConsole(int width, int height) //Dieu chinh kich thuoc console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void EmptyBox1(int x, int y,int w,int h,int b_color)
{

	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y);cout << char(218);
	gotoxy(x + w, y);cout << char(191);
	gotoxy(x, y + h);cout << char(192);
	gotoxy(x + w, y + h);cout << char(217);

}

void EmptyBox2(int x, int y,int w,int h,int b_color)
{

	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	//============= ve vien =============

	SetColor(b_color);
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoxy(ix, y);
		cout << char(205);
		gotoxy(ix, y + h);
		cout << char(205);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoxy(x, iy);
		cout << char(186);
		gotoxy(x + w, iy);
		cout << char(186);
	}
	gotoxy(x, y);cout << char(201);
	gotoxy(x + w, y);cout << char(187);
	gotoxy(x, y + h);cout << char(200);
	gotoxy(x + w, y + h);cout << char(188);

}

void BG(int t_color, int bg_color) {
	SetColor(t_color);
	SetBGColor(bg_color);
}
void KhungHuongDanCase5()
{
	EmptyBox1(10,6,25,21,3);//box huong dan
	for(int i=11;i<35;i++)
	{
		gotoxy(i,18);
		cout<<char(196);
	}
	EmptyBox1(10,3,25,2,4);//box tim kiem mon
	EmptyBox1(11,9,23,2,4);//box nhap mon
	gotoxy(18,4);cout<<"HUONG DAN";
	EmptyBox2(40,30,78,2,1);//box thong bao
	SetColor(0);
	gotoxy(50,2);cout<<"MA MON";
	gotoxy(83,28);cout<<char(17);
	gotoxy(99,28);cout<<char(16);
	gotoxy(88,2);cout<<"TEN MON";
	gotoxy(11,7);cout<<"  DELETE: XOA MON HOC";
	gotoxy(11,8);cout<<" F4: CHINH SUA MON HOC";
	gotoxy(15,20);cout<< char(17)<<"      SANG TRAI";
	gotoxy(15,22);cout<< char(16)<<"      SANG PHAI";
	gotoxy(16,4);cout<<char(14);
	gotoxy(28,4); cout<<char(14);
	gotoxy(10,31);
}
void framecase5()
{
	SetBGColor(15);
	resizeConsole(1000,600);
	BG(0,15);
	EmptyBox2(7,0,115,33,0);//box lon nhat
	EmptyBox2(40,3,25,24,1);//Box ma mon hoc
	EmptyBox2(66,3,52,24,1);//box ten mon hoc
	KhungHuongDanCase5();
}
void framecase7()
{
	SetBGColor(7);
	resizeConsole(1100,650);
	BG(0,15);// NEN XANH NGOC
	SetConsoleTitle(TEXT("MON HOC"));
	EmptyBox2(5,4,133,34,0);// Hop lon nhat
	EmptyBox2(6,9,30,28,1);// box trai
	EmptyBox2(37,9,100,28,1);//box phai
	EmptyBox1(8,15,26,20,1);// box huong dan
	SetColor(3);	// DO DAM
	gotoxy(10,11); cout<<"BAN DANG DANG NHAP VOI";
	gotoxy(10,12); cout<<" TU CACH GIANG VIEN!";
	SetColor(1);//chu - VANG HUONG DAN
	gotoxy(17,15); cout<<"HUONG DAN";
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
	gotoxy(14,17); cout<<"INSERT";
	gotoxy(14,19); cout<<"F2";
	gotoxy(14,21); cout<<"F4";
	gotoxy(14,23); cout<<"ESC";
	gotoxy(14,25); cout<<char(16);
	gotoxy(14,27); cout<<char(17);
	gotoxy(14,29); cout<<char(30);
	gotoxy(14,31); cout<<char(31);
	gotoxy(12,33); cout<<"DELETE";
	SetColor(0);
	gotoxy(10,6); cout<<"TEN MON: ";
	gotoxy(10,7); cout<<"MA MON: ";
	gotoxy(10,8); cout<<"SO LUONG CAU HOI: ";
	SetColor(1);// XANH DA TROI
	for(int i=38;i<137;i++)
	{
		gotoxy(i,34);
		cout<<char(205);
	}
	SetColor(12); // DO
	gotoxy(39,35); cout<<" THONG BAO: ";
	BG(0,15);
	gotoxy(5,38);
}
void DeleteChonDA()
{
	BG(0,15);
	int i,j;
	for(int i=1; i<9; i+=2)
	{
		gotoxy(9,16+i);
		for(j=0; j<24; j++)		
		{
			mtx.lock();
			cout<<" ";
			mtx.unlock();
		}
	}
}
void DeleteAPart()
{
	BG(0,15);
		int i,j;
		gotoxy(12,10);cout<<"                      ";
		for(int i=1; i<7; i++)
		{
			gotoxy(11,11+i);
			for(j=0; j<24; j++)		
			{
				cout<<" ";
			}
		}	
		gotoxy(36,13);cout<<"    ";
		SetColor(1);
		gotoxy(40,13);cout<<char(186);
		SetColor(3);
		gotoxy(35,13);cout<<char(179);
		SetColor(0);
}
void DeleteHuongDan()
{
{
	BG(0,15);
	int i,j;
	for(int i=1; i<28; i++)
	{
		gotoxy(7,9+i);
		for(j=0; j<29; j++)		
		{
			cout<<" ";
		}
	}
}
}
void DeleteScreen() //Xoa nguyen man hinh tru menu, huong dan, tieu de
{
	BG(0,15);//37,9,100,28
	//EmptyBox2(37,9,100,28,1);
	int i, j;
	for (i = 1; i < 25; i++)
	{
		gotoxy(38, 9 + i);
		for (j = 0; j < 99; j++) 
		{
			mtx.lock();
			cout << " ";
			mtx.unlock();
		}
	}
}
void random(int a[], int n, int sl)
{
	int temp, ran;
	srand(time(NULL));
	for(int i=0;i<n&&sl>0;)
   {
   		ran = (rand() % (n));
   		temp = a[ran];
   		a[ran] = a[n-1];
   		a[n-1] = temp;
   		n--;
   		sl--;
   }
}
void framecase11(int flag, string lop, string mssv, string ten)//flag=0:GV   1:SV
{
	resizeConsole(1100,650);
	BG(0,15);// NEN XANH NGOC
	for(int i=38;i<137;i++)
	{
		gotoxy(i,34);
		cout<<char(205);
	}
	SetConsoleTitle(TEXT("MON HOC"));
	EmptyBox2(5,4,133,34,0);// Hop lon nhat
	EmptyBox2(6,9,30,28,1);// box trai
	EmptyBox2(37,9,100,28,1);//box phai
	EmptyBox1(8,14,26,11,1);// box huong dan
	if(flag==0)
	{
		SetColor(3);	// DO DAM
		gotoxy(10,11); cout<<"BAN DANG THI THU VOI";
		gotoxy(10,12); cout<<" TU CACH GIANG VIEN";
	}
	if(flag==1)
	{
		SetColor(4);	// DO DAM
		gotoxy(10,10); cout<<"                      ";
		gotoxy(10,10); cout<<" LOP: "<<lop;
		gotoxy(10,11); cout<<"                      ";
		gotoxy(10,11); cout<<" MSSV: "<<mssv;
		gotoxy(10,12); cout<<"                     ";
		gotoxy(10,12); cout<<" TEN: "<<ten;
	}
	SetColor(0);
	gotoxy(9,15);cout<<" DAP AN NGUOI DUNG CHON";
	gotoxy(10,6); cout<<"TEN MON: ";
	gotoxy(10,7); cout<<"MA MON: ";
	gotoxy(10,8); cout<<"SO LUONG CAU HOI: ";
	SetColor(12); // DO
	gotoxy(39,35); cout<<" THONG BAO: ";
	BG(0,15);
	gotoxy(5,38);
}
void MuiTen() //Mui ten tu trai qua phai -->
{
	SetColor(0);
	SetBGColor(15);
	cout << (char)196 << ">";
}
void HightLightDA()
{
	SetColor(15);
	SetBGColor(12);
}






