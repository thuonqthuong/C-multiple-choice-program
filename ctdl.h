#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> //rand, srand
#include <thread>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include<cctype>
#include"mylib.h"
#include<stdlib.h>
#include <mutex>
#define MAXCAUHOI 200
#define MAXLOP 100
#define MAXMONHOC 200
using namespace std;
std::mutex mtx;  
int stop=0;
//==================1. danh sach cau hoi: DS TUYEN TINH====================
struct cau_hoi
{
	int id;
	string noidung;
	string A;
	string B;
	string C;
	string D;
	char DA;
};
typedef struct cau_hoi CAUHOI;
struct ds_cauhoi
{
	CAUHOI ds[MAXCAUHOI];
	int sl=0;
};
typedef struct ds_cauhoi DSCAUHOI;//Xem thu cac thao tac tren tree nhu the nao
//===================1.1 DS cau hoi da thuc hien=============================
struct chitietcauhoi
{
	int id;
	char svchon;
};
//==================2. danh sach mon hoc: CAY NHI PHAN TIM KIEM==============
struct monhoc
{
	char mamh[16];
	string tenmh;
	DSCAUHOI dsch;
};
typedef struct monhoc MONHOC;

struct dsmonhoc
{
	MONHOC mon;
	dsmonhoc *pLeft, *pRight;//08.07.2021
};
typedef struct dsmonhoc NODE;
typedef NODE* TREE;

TREE DSMONHOC = NULL;
//=================3. danh sach diem: DS LIEN KET DON=================
struct diem {
	char mamh[16];
	float score;
	chitietcauhoi* cauhoisv;
	int slCH;
};
typedef struct diem DIEM;
struct nodeDiem
{  
    DIEM info;
    nodeDiem *next ;
};
typedef struct nodeDiem* PTRDIEM;
//=================4. danh sach sinh vien: DS LIEN KET DON============
struct sinh_vien
{
	string masv;
	string ho;
	string tendem;
	string ten;
	string phai;
	string password;

	PTRDIEM dsdiem;
};
typedef struct sinh_vien SV;
struct ds_sinhvien
{
	SV data;
	ds_sinhvien *next;
	int sl = 0;
};
typedef struct ds_sinhvien DSSV;
typedef DSSV *PTRSV;
//===================5. danh sach lop: MANG CON TRO=================
struct lop
{
	string malop;
	string tenlop;
	PTRSV dssv;
};
typedef struct lop LOP;

struct dsLop
{
	LOP *dsl[MAXLOP];
	int sl=0;
};
typedef struct dsLop DSLOP;

