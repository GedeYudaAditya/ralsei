#include<windows.h>
#include<cstdlib>
#include<iostream>
using namespace std;

//Struktur yang dapat menyimpan berbagai variabel dengan jenis data yang berbeda ataupun sama
struct input{
	int select;
	string nama;
	string e;
	int umur;
};
input input; //membuat variabel untuk structur agar dapat di panggil
//Struct di bawah ini hanya untuk jaga jaga, tidak terlalu penting
struct ingame{
	
};
ingame ingame;

//Deklarasi Fungsi
//Sintak ini berfungsi agar fungsi menu dapat memanggil fungsi yang ada di bawahnya
int perkenalan(string nama, int umur, int select);
int selection(int select);
int pilihan(int select);
int menu(int select);
int tentang(int select, string nama);
int mulai(string nama, int umur, int select);
void ex_error(string e);

//Fungsi berbagai Suara
void starting(){
	//system("D:\\Deltarune\\SURVEY_PROGRAM\\mus\\legend.ogg");
	Beep(500,100);
	Beep(700,100);
	Beep(900,100);
}
void sound_confirm(){
	Beep(500,250);
}
void sound_error(){
	Beep(500,250);
	Beep(1000,250);
	Beep(1500,250);
}
void sayonara(){
	Beep(500,250);
	Beep(500,250);
	Beep(1500,500);
	Beep(1000,500);
}
void hm(){
	Beep(500,150);
	Beep(1000,150);
}
void happy_noies(){
	Beep(1000,30);
	Beep(1000,30);
	Beep(1000,200);
}

//Fungsi indikator warna
void normal(){
	system("color b");
}
void error(){
	system("color c");
}

int ambilkan(string nama){
	char* ambil[900];
	cout<<"\n";
	cout<<"Ralsei : Umm.. beritahu aku dimana tempat file tersebut "<<input.nama<<".\n";
	cout<<"\n";
	cout<<"================================================================\n";
	cout<<"HINT : Tulislah dengan format seperti ini C/D:\\folder_file\\file.\n";
	cout<<"Misalkan C:\\WINDOWS\\system32\\noteped.exe.\n";
	cout<<"================================================================\n";
	cout<<"Direktori/Tempat file : ";cin>>ambil[900];
	sound_confirm();
	system(ambil[900]);
	cout<<"Ralsei : Maaf jika file tidak dapat di tampilkan, mungkin file tersebut tidak ada di sistemmu.\n";
	mulai(input.nama,input.umur,input.select);
}
void tambah(){
	
}
void kurang(){
	
}
void bagi(){
	
}
void kali(){
	
}
void sama_dengan(){
	
}
void tidak_sama_dengan(){
	
}
void dan(){
	
}
void atau(){
	
}
void tidak(){
	
}
int matematika(int select,string nama){
	cout<<"Ralsei : Ok, Tinggal sebutkan 2 nilai dan operatornya "<<input.nama<<".\n";
	cout<<"Pilih operator :\n";
	cout<<"1. +     6. Tidak Sama Dengan.\n";
	cout<<"2. -     7. AND\n";
	cout<<"3. /     8. OR\n";
	cout<<"4. *     9. Not\n";
	cout<<"5. =     10.Kembali.\n";
	selection(input.select);
	switch(input.select){
		case 1:sound_confirm();tambah();break;
		case 2:sound_confirm();kurang();break;
		case 3:sound_confirm();bagi();break;
		case 4:sound_confirm();kali();break;
		case 5:sound_confirm();sama_dengan();break;
		case 6:sound_confirm();tidak_sama_dengan();break;
		case 7:sound_confirm();dan();break;
		case 8:sound_confirm();atau();break;
		case 9:sound_confirm();tidak();break;
		case 10:sound_confirm();mulai(input.nama,input.umur,input.select);break;
		default:error();sound_error();matematika(input.select,input.nama);break;
	}
}
int game(){
	
}
int error_mulai(int select){
	error();
	cout<<"Ralsei : Aku sangat meminta maaf. Aku tidak bisa melakukan hal itu.\n";
	sound_error();
	cout<<"HINT : Pilih yang ada di pilihan.\n";
	mulai(input.nama,input.umur,input.select);
}
int in_jawab(int select, int umur, string nama){
	if(input.select == 1){
		sound_confirm();
		cout<<"-----------------------------------------------------------------------------------------------------\n";
		cout<<""<<input.nama<<"   : Umurku... ";cin>>input.umur;
		cout<<"???    : Jadi Usiamu "<<input.umur<<"\n";
	}else if(input.select == 2){
		sound_confirm();
		cout<<"-----------------------------------------------------------------------------------------------------\n";
		cout<<""<<input.nama<<"   : Untuk apa kau menanyakan hal itu ?\n";
		cout<<"???    : Aw maafkan aku. Tak apa kalau tidak ingin mengatakannya. Terkadang hal itu memang tidak sopan bagi seseorang.\n";
	}else if(input.select == 3){
		sound_confirm();
		cout<<"-----------------------------------------------------------------------------------------------------\n";
		cout<<""<<input.nama<<"   : Aku tidak harus menjawabnya.\n";
		cout<<"???    : Aw maafkan aku. Aku tidak sopan menanyakan hal seperti itu\n";
	}else{
		error();
		sound_error();
		cout<<"-----------------------------------------------------------------------------------------------------\n";
		cout<<"???    : Um.. aku tidak mengerti.\n";
	}
}

//Fungsi perkenalan
int perkenalan(string nama, int umur, int select){
	cout<<"???    : Aw ada pengunjung. Hello.. selamat datang, umm siapa namamu ?\n";
	cout<<"Kau    : Owh hello, Um.. namaku... ";cin>>input.nama;
	cout<<"???    : "<<input.nama<<"! Aw.. nama yang bagus, lalu umurmu ?\n";
	cout<<"\n";
	cout<<"-----------------------------------------------------------------------------------------------------\n";
	cout<<"Pilih Tanggapanmu:\n";
	cout<<"1. Jawab  2. Menghindari pertanyaan 3. Jangan Katakan.\n";
	selection(input.select);
	in_jawab(input.select, input.umur, input.nama);
	cout<<"Ralsei : Aw hampir lupa, Aku Ralsei, tanyakan apapun yang bisa ku lakukan untuk mu, "<<input.nama<<".\n";
	cout<<"\n";
	cout<<"                         +++++ ketik angka apapun untuk lanjut. +++++\n";
	cout<<"\n";
	cout<<"-----------------------------------------------------------------------------------------------------\n";
	selection(input.select);
	system("cls");
	switch(input.select){
		case 1 : normal();sound_confirm();menu(input.select);
		default : normal();sound_confirm();menu(input.select);
	}
}

//Fungsi Menu Exit
int ex(string e){
	printf("\a");
	cout<<"Ralsei : Apakah Kau ingin pergi ?(y/n) : ";cin>>input.e;
	if(input.e == "y"||input.e =="Y"){
		normal();
		cout<<"Ralsei : Umm baiklah. Sampai Jumpa Lagi.";
		sayonara();
		exit(0);
	}else if(input.e == "n" || input.e == "N"){
		normal();
		cout<<"Ralsei : Haha.. baiklah.\n";
		happy_noies();
		menu(input.select);
	}else{
		ex_error(input.e);
	}
}

//Fungsi input pilihan
int selection(int select){
	cout<<"Number Selection : ";cin>>input.select;
}

//Fungsi Menu Exit input Error
void ex_error(string e){
	error();
	cout<<"Ralsei : Umm.. aku tidak mengerti.\n";
	sound_error();
	ex(input.e);
}

//Fungsi Menu input Error
int menu_error_input(int select){
	error();
	cout<<"Ralsei : Hmmm.. Sepertinya itu tidak ada di pilihan. Coba yang lain.\n";
	menu(input.select);
}

//Fungsi Tentng input Error
int tentang_error_input(int select){
	error();
	cout<<"Ralsei : Hmmm.. Sepertinya itu tidak ada di pilihan. Coba yang lain.\n";
	tentang(input.select,input.nama);
}
//Fungsi Menu
int menu(int select){
	cout<<"============================================================\n";
	cout<<"=                  Pilih Hal Salah satu.                   =\n";
	cout<<"============================================================\n";
	cout<<"\n";
	cout<<"                     1. Bantu aku\n";
	cout<<"                     2. Tentang mu.\n";
	cout<<"                     3. Keluar.\n";
	cout<<"\n";
	cout<<"============================================================\n";
	selection(input.select);
	if(input.select != 1 && input.select != 2 && input.select != 3){
		sound_error();
		system("cls");
		pilihan(input.select);
	}else if(input.select == 3){
		normal();
		hm();
		system("cls");
		pilihan(input.select);
	}else{
		normal();
		sound_confirm();
		system("cls");
		pilihan(input.select);
	}
}
//Fungsi mulai
int mulai(string nama, int umur,int select){
	cout<<"============================================================\n";
	cout<<"Ralsei : Aku akan membantumu sebisaku "<<input.nama<<".\n";
	cout<<"Ralsei : Katakan saja apa yang harus ku lakukan.\n";
	cout<<"\n";
	cout<<"1. Ambilkan/Jalankan aku sebuah file/program di Komputer ku.\n";
	cout<<"2. Bantu aku untuk menghitung angka.\n";
	cout<<"3. Sebenarnya aku hanya ingin bermain dengan mu.\n";
	cout<<"4. Kembali.\n";
	cout<<"============================================================\n";
	selection(input.select);
	system("cls");
	switch(input.select){
		case 1 :sound_confirm();ambilkan(input.nama);break;
		case 2 :sound_confirm();matematika(input.select,input.nama);break;
		case 3 :sound_confirm();game();break;
		case 4 :sound_confirm();system("cls");menu(input.select);break;
		default :error_mulai(input.select);break;
	}
}
//Fungsi Menu Tentang
int tentang(int select, string nama){
	cout<<"=========================================\n";
	cout<<"\t\tTENTANG\t\t\n";
	cout<<"=========================================\n";
	cout<<"Aku adalah sebuah aplikasi yang berguna untuk\n";
	cout<<"Menyelesaikan masalah mu, "<<input.nama<<".\n";
	cout<<"Dan mungkin, umm.. dapat membuat mu senang.\n";
	cout<<"-----------------------------------------\n";
	cout<<"Pengembang : Gede Yuda Aditya\n";
	cout<<"Prodi      : Pendidikan Teknik Informatika\n";
	cout<<"-----------------------------------------\n";
	cout<<"All Right Reserved to Gede Yuda Aditya @2020\n";
	cout<<"-----------------------------------------\n";
	cout<<"1. Kembali.\n";
	cout<<"=========================================\n";
	selection(input.select);
	if(input.select != 1){
		sound_error();
		system("cls");
	}else{
		normal();
		sound_confirm();
		system("cls");
	}
	switch(input.select){
		case 1: menu(input.select);
		default : tentang_error_input(input.select);
	}
}
//Fungsi sistem pilihan
int pilihan(int select){
	switch(input.select){
		case 1: mulai(input.nama,input.umur,input.select);break;
		case 2: tentang(input.select,input.nama);break;
		case 3: ex(input.e);break;
		default : menu_error_input(input.select);break;
	}
}

main(){
	starting();
	normal();
	perkenalan(input.nama, input.umur, input.select);
	//menu(input.select);
}
