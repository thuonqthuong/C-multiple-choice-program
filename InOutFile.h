#pragma once
#include"ctdl.h"
//#include"function.h"

void khoitaolist(DSLOP &dslop){
	for(int i=1;i<=dslop.sl;i++){
		dslop.dsl[i]->dssv=NULL;
	}
}
PTRSV  khoitaonode(SV sv){
	PTRSV p= new DSSV;
	p->data=sv;
	p->next=NULL;
	return p;
}
void Insert_TailSV(PTRSV &DSSV, SV sv) {
	PTRSV p = new ds_sinhvien;
	p->data = sv;
	p->next = NULL;
	if (DSSV == NULL) {
		DSSV = p;
	}
	else {
		for (PTRSV k = DSSV; k != NULL; k = k->next)
		{
			if (k->next == NULL)	//Tim ra Node Tail
			{
				k->next = p;
				k = p;
			}
		}
		
	}
}
void Insert_first1(PTRSV &First, SV x)
{
   PTRSV p=new ds_sinhvien;
//   p = khoitaonode()
   p->data = x;
   p->next = First;
   First = p;
}

//==================doc file ds lop==================
LOP* TaoLOP()
{
	LOP *lop = new LOP;
	lop->malop="";
	lop->tenlop="";
	
	return lop;
}
int	 InsertLTC(DSLOP &dslop, LOP lop, int i)
{
		dslop.dsl[i] = TaoLOP();
		dslop.dsl[i]->malop = lop.malop;
		dslop.dsl[i]->tenlop= lop.tenlop;
}


void DocFileLop(DSLOP &dslop)
{
	ifstream infile;
	infile.open("DSLOP.txt", ios::in);
	if (!infile)
	{
		cout << "\nFile Khong Ton Tai!";
		return;
	}
	int i = 0;

	int sl;
		infile >> sl;
		dslop.sl=sl;infile.ignore();
	for(int i=1;i<=sl;i++)
	{
		LOP lop;
		
		getline(infile,lop.malop);
		getline(infile,lop.tenlop);
		InsertLTC(dslop, lop,i);
		
	}
	infile.close();
}

void GhiFileLop(DSLOP l)
{
	ofstream lopwrite;
	lopwrite.open("DSLOP.txt");
	lopwrite << l.sl << endl;

	for (int i = 1; i <= l.sl; i++)
	{
		
		lopwrite << l.dsl[i]->malop<<endl ;
		lopwrite << l.dsl[i]->tenlop<<endl;
	}
	lopwrite.close();
}
//============= danh sach sinh vien=======================
void DocFileSV(DSLOP &dslop)
{
	khoitaolist(dslop);
	int temp, vitri;
	char a[20];
	SV sv;
	string data;
	
	int slsv=0;
	ifstream infile;
	infile.open("DSSV.txt", ios::in);

	if (!infile) { return; }
	for (int i=1;i<=dslop.sl;i++)
	{	
		getline(infile,data);	 
		infile>>slsv;
		infile.ignore();
		
			for(int j=0;j<slsv;j++){
				getline(infile,sv.masv);
				getline(infile,sv.ho);
				getline(infile,sv.tendem);
				getline(infile,sv.ten);
				getline(infile,sv.phai);
				getline(infile,sv.password);
				khoitaonode(sv);
				Insert_TailSV(dslop.dsl[i]->dssv,sv);
		
		}
	}
	infile.close();
}

int DemSinhVien(PTRSV p)
{	
	int dem=0;
		while(p!=NULL){
		dem++;
		p=p->next;
		}
		return dem;
}
void ghi1SV(PTRSV p){
		ofstream outfile;
	//	outfile.open("DSSV.txt");system("cls");
			for(p ;p!=NULL;p=p->next){

			cout<<"masv: "<<p->data.masv<<endl;
			
			outfile<<p->data.masv<<"\n"<<
			p->data.ho<<"\n"
			<<p->data.tendem<<"\n"
			<<p->data.ten<<"\n"<<
			p->data.phai<<"\n"<<
			p->data.password<<"\n";
		}
			
	//	outfile.clear(); 
	
	//outfile.close();
}
void GhiFileSV(DSLOP dslop){
	ofstream outfile;
	outfile.open("DSSV.txt");
		for(int i=1;i<=dslop.sl;i++){
			
			outfile << dslop.dsl[i]->malop<<"\n";
			
			outfile<<DemSinhVien(dslop.dsl[i]->dssv)<<endl;
			
	//		ghi1SV(dslop.dsl[i]->dssv);
//			cout<<"dem: "<<DemSinhVien(dslop.dsl[i]->dssv)<<endl;
			PTRSV k = dslop.dsl[i]->dssv;
			for(k ;k!=NULL;k=k->next){
			
			cout<<"malop: "<<dslop.dsl[i]->malop<<endl;
			cout<<"masv: "<<k->data.masv<<endl;
			
			outfile<<k->data.masv<<"\n"<<
			k->data.ho<<"\n"
			<<k->data.tendem<<"\n"
			<<k->data.ten<<"\n"<<
			k->data.phai<<"\n"<<
			k->data.password<<"\n";
		}
			
		}
	
	outfile.close();
}
void Insert_firstDiem(PTRDIEM &First, DIEM x)
{
   PTRDIEM p = new nodeDiem;

   p->info= x;
   p->next = First;
   First = p;
}

void DocFileDiem(DSLOP &dslop){
	khoitaolist(dslop);
	int temp, vitri;
	
	SV sv;
	string data;
	DIEM diem;
	
	int slsv=0;
	ifstream infile;
	infile.open("DIEM.txt", ios::in);

	if (!infile) { return; }
	for (int i=1;i<=dslop.sl;i++)
	{	
		getline(infile,data);	 
		infile>>slsv;
		infile.ignore();
			int slmon=0;
			infile>>slmon;infile.ignore();
			for(int j=0;j<slsv;j++){
				getline(infile,data);
				for(int k=0;k<slmon;k++){
					getline(infile,data,'|');
					strcpy(diem.mamh,data.c_str());
					infile>>diem.score;
					Insert_firstDiem(dslop.dsl[i]->dssv->data.dsdiem,diem);
					cout<<"mamh: "<<dslop.dsl[1]->dssv->data.dsdiem->info.mamh<<endl;
					cout<<"diem: "<<dslop.dsl[1]->dssv->data.dsdiem->info.score<<endl;
				}
		}
	}
	
	infile.close();
}
void GhiFileDiem(DSLOP dslop){
}



