
#pragma once
//#include"function.h"
#include "diem.h"
#include "treemonhoc.h"
#include"InOutFile.h"


//#include"SINHVIEN.h"
using namespace std;





char thucdon [so_item][50] = {"1. QUAN LY LOP","",
			                  "2. QUAN LY SINH VIEN     ","",
			                  "3. QUAN LY MON HOC      ","",
			                  "4. QUAN LY CAU HOI THI       ","",
							  "5. QUAN LY DIEM","",
							  "6. CHI TIET CAU HOI THI","",
							  "7. THI THU","",
							  "8. THOAT"};
int MenuDongGV(char td [so_item][50]){
  Normal();
  int x=5, y=3,w=100,h=20, t=10, b=10;
  string tile="";
  box(x,y,w,h,t,b,tile);
  int chon =0;
  int i; 
  for ( i=0; i<= so_item+1 ; i+=2)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
while (1){
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if(chon==0){
    			Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon =14;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
				break;
		}	else if (chon+2 >1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon -=2;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if(chon==14){
    			Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon =0;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
				break;
			}else if (chon+2 <so_item){
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon +=2;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  
  } 
}


string menulogin(DSLOP dslop){

	int x=39, y=3,w=50,h=5, t=10, b=10;
	string nd="";
	box(x,y,w,h,t,b,nd);
	gotoxy(40, 4);cout<<"username: "<<endl;
	gotoxy(40,5);cout<<"password: "<<endl;
	
	string user;
	string us=NhapUser(user, 10);
	string pass;
	string pa=NhapPass(10);
	if(us.compare("GV")==0 && pa.compare("GV")==0||us.compare("GV")==0 && pa.compare("gv")==0){
		return us;
	}else if(dangNhap(dslop,us,pa)==1){
		return us;
	}
	else return "0";
}
void menuMain(){
	HighLight();
	string s="THI TRAC NGHIEM !!!";
	gotoxy(40,1);cout<<s;
	
}


int main(){

	DSLOP dslop;
	DocFileLop(dslop);
	DocFileSV(dslop);
	TREE t;
	KhoiTaoCay(t);
	DocFile(cauhoi, t);
	DocDiem("CTThiThu.txt", dslop);	
	MONHOC mh;
	int chon;
	HighLight();
	string s="THI TRAC NGHIEM !!!";
	gotoxy(40,1);cout<<s;	
	Normal();
	while(1){
	
	string login=menulogin(dslop);
	int lg=0;
	if(login=="GV")lg=1;
	else if(login=="0")	lg=-1;
	else lg=2;
	switch(lg){
	
	case 1: {
		while(1){
		int chon;
		system("cls");
		gotoxy(40,2);
		SetColor(22);
		cout<<"DANG NHAP VOI VAI TRO GIAO VIEN";
		Normal();
		chon = MenuDongGV (thucdon);
		switch (chon){
    	case 1:  { // quan ly lop
    		system("cls");
			xemdslop(dslop);
			GhiFileLop(dslop);
			break;
		}
    	
    	case 3:{//quan li sinh vien
    	
    	 	system("cls");
    	 	int chonlop=chonLOP(dslop);
			
			xemdssv(dslop,chonlop);
			GhiFileSV(dslop);
			break;
		}
    	
    	case 5:{// quan ly mon hoc
			system("cls");
			int page = 1;
    		framecase5();
    		QuanLyMonHoc(t);
			break;
		}
    	
    	case 7:{// quan ly cau hoi thi
    		system("cls");
			framecase7();
			BG(0,12);
			gotoxy(20,17); cout<<" NHAP CAU HOI ";
			gotoxy(20,19); cout<<" XEM ";
			BG(0,15);
			while(1)
			{
				char c=GetKey();
				if(c==INSERT){
					DeleteScreen();
					TimMonHoc(t, 60, 12, 0, 0, "");
					LuuFile(cauhoi, t);
					break;
				}
				else if(c==F2)
				{
					DeleteScreen();
					TimMonHoc(t, 60, 12, 2, 0, "");
					LuuFile(cauhoi, t);
					break;
				}
				else if(c==ESC)	break;
				else continue;
			}
			break;
		}
    	
    	
    	case 9: {//quan ly diem thi
    		system("cls");
			DiemTheoLop(dslop, t);
    		break;
		}
		case 11:
			{
				system("cls");
				ChiTietBaiThi(dslop, t);
				break;
			}
    	
    	case 13:{// thi thu
    		system("cls");
    		framecase11(0,"","","");
    		TimMonHoc(t, 60, 12, 1, 0, "");
			break;
		} case 15:{
			
			return 0;
			break;
		}
	}
}
		break;
	}case 2:{
		system("cls");
		gotoxy(60,2);SetColor(20);
		cout<<"DANG NHAP VOI VAI TRO SINH VIEN";
		SV sv; 
		sv.masv=login;
		PTRSV p;
		string ten;
		for(int i=1;i<=dslop.sl;i++){
			p=dslop.dsl[i]->dssv;
			p=searchStudent(p,sv.masv);
			if(p!=NULL){	
				ten=p->data.ho+" "+p->data.tendem+" "+p->data.ten;
			}
		}
		int lop=timlop(dslop, sv.masv);
		framecase11(1, dslop.dsl[lop]->malop, sv.masv, ten);
    	TimMonHoc(t, 60, 12, 1, 1, sv.masv);
		DeleteScreen();
		return 0;
		break;

	}case -1:	
	{
		GhiChu("Username hoac Password khong dung!",50,10,1000);
		break;
	}
}}
//	return 0;
}
