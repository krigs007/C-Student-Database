//****************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//****************************************************************
//                   STURUCTURE USED IN PROJECT
//****************************************************************

struct student
//Format Struktur File
{
 int npm;
 char grade;
 char name[50];
 int std;
 int matek, diskrit, RL, OAK, DRE, Proglan;
 float rata;
}st;

//****************************************************************
//        				GLOBAL DECLARATION
//****************************************************************
FILE *fptr;
//fptr adalah File Pointer  yang digunakan untuk merujuk pada struct student

//****************************************************************
//					PROTECT PROGRAM
//****************************************************************


int passwordbenar;
char pass[8], password[8];

void ambil_password();
void selesai();


void password_() {
	
	ambil_password();
	printf("Login\n\n");
	printf("Masukkan password : ");
	scanf("%s", &pass);
	passwordbenar=strcmp(pass,password);
	if(passwordbenar !=0){
		printf("\n\nMaaf, password yang anda masukkan salah! Anda akan keluar dari Program");
		getch();
		system("cls");
		exit (0);
	}
}

void ambil_password(){
	FILE *file;
	file=fopen("password.txt", "r");
	fscanf(file, "%s", password);
	fclose(file);
}

n
//****************************************************************
//        			FUNCTION TO WRITE IN FILE
//****************************************************************

void write_student()
   {
    fptr=fopen("student.dat","ab");
    printf("\nSilahkan Masukkan Data Baru Dari Mahasiswa \n");
    printf("\n\nMasukkan NPM Mahasiswa 						: ");
    scanf("%d",&st.npm);
    fflush(stdin);
    //fflush adalah fungsi untuk menghapus input buffer
    printf("\n\nMasukkan Nama Mahasiswa 					: ");
    gets(st.name);
    printf("\nMasukkan Nilai Mata Kuliah Matematika Teknik 			: ");
    scanf("%d",&st.matek);
    printf("\nMasukkan Nilai Mata Kuliah Struktur Diskrit 			: ");
    scanf("%d",&st.diskrit);
    printf("\nMasukkan Nilai Mata Kuliah Rangkaian Listrik 			: ");
    scanf("%d",&st.RL);
    printf("\nMasukkan Nilai Mata Kuliah Organisasi dan Arsitektur Komputer 	: ");
    scanf("%d",&st.OAK);
    printf("\nMasukkan Nilai Mata Kuliah Dasar Rangkaian Elektronika 		: ");
    scanf("%d",&st.DRE);
    printf("\nMasukkan Nilai Mata Kuliah Program Lanjut 			: ");
    scanf("%d",&st.Proglan);
    st.rata=(st.matek+st.diskrit+st.RL+st.OAK+st.DRE+st.Proglan)/6.0;
    if(st.rata>=80 &&st.rata<=100)
       st.grade='A';
    else if(st.rata>=65 &&st.rata<80)
      st.grade='B';
    else if(st.rata>=55 &&st.rata<65)
      st.grade='C';
    else if(st.rata>=40 &&st.rata<55)
      st.grade='D';
    else
     st.grade='E';
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nData Mahasiswa Telah Tersimpan ");
    getch();
}


//****************************************************************
//          	FUNCTION TO READ ALL RECORDS FROM FILE
//****************************************************************

void display_all()
{
    system("cls");
    printf("\n\n\n\t\tMENAMPILKAN SEMUA HASIL\n\n");
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\n\n========================================================================================");
      printf("\n========================================================================================\n");
      printf("\nNPM Mahasiswa 							: %d",st.npm);
      printf("\nNama Mahasiswa 							: %s",st.name);
      printf("\nNilai Mata Kuliah Matematika Teknik 				: %d",st.matek);
      printf("\nNilai Mata Kuliah Struktur Diskrit  				: %d",st.diskrit);
      printf("\nNilai Mata Kuliah Rangkaian Listrik 				: %d",st.RL);
      printf("\nNilai Mata Kuliah Organisasi dan Arsitektur Komputer 		: %d",st.OAK);
      printf("\nNilai Mata Kuliah Dasar Rangkaian Elektronika 			: %d",st.DRE);
      printf("\nNilai Mata Kuliah Program Lanjut 				: %d",st.Proglan);
      printf("\n\nNilai Rata-rata Mahasiswa  					: %.2f",st.rata);
      printf("\nNilai Akhir Mahasiswa 						: %c",st.grade);
      printf("\n\n========================================================================================");
      printf("\n========================================================================================\n");
      printf("\nTekan Tombol Apa Saja Untuk Menempilkan Hasil Selanjutnya");
      getch();
    }
    fclose(fptr);
    getch();
}


//****************************************************************
//        	FUNCTION TO READ SPECIFIC RECORD FROM FILE
//****************************************************************

void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.npm==n)
        {
         system("cls");
         	printf("\nMenampilkan Hasil yang Anda Minta");
	      	printf("\nNPM Mahasiswa 							: %d",st.npm);
	      	printf("\nNama Mahasiswa 							: %s",st.name);
	      	printf("\nNilai Mata Kuliah Matematika Teknik 				: %d",st.matek);
	      	printf("\nNilai Mata Kuliah Struktur Diskrit  				: %d",st.diskrit);
	      	printf("\nNilai Mata Kuliah Rangkaian Listrik 				: %d",st.RL);
	      	printf("\nNilai Mata Kuliah Organisasi dan Arsitektur Komputer 		: %d",st.OAK);
	      	printf("\nNilai Mata Kuliah Dasar Rangkaian Elektronika 			: %d",st.DRE);
	      	printf("\nNilai Mata Kuliah Program Lanjut 				: %d",st.Proglan);
	      	printf("\n\nNilai Rata-rata Mahasiswa  					: %.2f",st.rata);
	      	printf("\nNilai Akhir Mahasiswa 						: %c",st.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\n\n\tData yang Anda Cari Tidak Ditemukan");
 printf("\n\n\n\n\tTekan ENTER untuk kembali ke MENU UTAMA");
    getch();
}


//****************************************************************
//              FUNCTION TO MODIFY RECORD OF FILE
//****************************************************************

void modify_student()
{
    int no,found=0;
    system("cls");
    printf("\n\n\tUntuk Mengubah Data ");
    printf("\n\n\tSilahkan Masukkan NPM Mahasiswa : ");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.npm==no)
           {
            printf("\nNPM Mahasiswa 						: %d",st.npm);
            printf("\nNama Mahasiswa 						: %s",st.name);
            printf("\nNilai Mata Kuliah Matematika Teknik 				: %d",st.matek);
            printf("\nNilai Mata Kuliah Struktur Diskrit 			: %d",st.diskrit);
            printf("\nNilai Mata Kuliah Rangkaian Listrik 			: %d",st.RL);
            printf("\nNilai Mata Kuliah Organisasi dan Arsitektur Komputer 		: %d",st.OAK);
            printf("\nNilai Mata Kuliah Dasar Rangkaian Elektronika 				: %d",st.DRE);
            printf("\nNilai Mata Kuliah Program Lanjut 		: %d",st.Proglan);
            printf("\n\nNilai Rata-rata Mahasiswa  				: %.2f",st.rata);
            printf("\nNilai Akhir Mahasiswa 					: %c",st.grade);
            printf("\n\n\nSilahkan Masukkan Data Baru Mahasiswa \n");
            printf("\n\nMasukkan NPM Mahasiswa 					: ");
		    scanf("%d",&st.npm);
		    fflush(stdin);
		    printf("\n\nMasukkan Nama Mahasiswa 				: ");
		    gets(st.name);
		    printf("\nMasukkan Nilai Mata Kuliah Matematika Teknik 			: ");
		    scanf("%d",&st.matek);
		    printf("\nMasukkan Nilai Mata Kuliah Struktur Diskrit 		: ");
		    scanf("%d",&st.diskrit);
		    printf("\nMasukkan Nilai Mata Kuliah Rangkaian Listrik 		: ");
		    scanf("%d",&st.RL);
		    printf("\nMasukkan Nilai Mata Kuliah Organisasi dan Arsitektur Komputer 	: ");
		    scanf("%d",&st.OAK);
		    printf("\nMasukkan Nilai Mata Kuliah Dasar Rangkaian Elektronika 			: ");
		    scanf("%d",&st.DRE);
		    printf("\nMasukkan Nilai Mata Kuliah Program Lanjut 	: ");
		    scanf("%d",&st.Proglan);
            st.rata=(st.matek+st.diskrit+st.RL+st.OAK+st.DRE+st.Proglan)/6.0;
            if(st.rata>=80 &&st.rata<=100)
		       st.grade='A';
		    else if(st.rata>=65 &&st.rata<80)
		      st.grade='B';
		    else if(st.rata>=55 &&st.rata<65)
		      st.grade='C';
		    else if(st.rata>=40 &&st.rata<55)
		      st.grade='D';
		    else
 		      st.grade='E';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Data Diperbarui");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Data Yang Diminta Tidak Ditemukan ");
    printf("\n\n\n\n\n Tekan ENTER Untuk kembali ke MENU UTAMA");
    getch();
}


//****************************************************************
//        FUNCTION TO DELETE RECORD OF FILE
//****************************************************************

void delete_student()
   {
    int no;
    FILE *fptr2;
    //fptr2 digunakan agar tidak tertukar dengan fptr yang pertama yang fungsinya untuk write
    system("cls");
    printf("\n\n\n\tHapus Data");
    printf("\n\nSilahkan Masukkan NPM Mahasiswa yang Akan Dihapus Datanya : ");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.npm!=no)
       {
     		fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("\n\n\tData Telah Dihapus");
    getch();
}


//****************************************************************
//        FUNCTION TO DISPLAY ALL STUDENTS GRADE REPORT
//****************************************************************

void class_result()
    {
     system("cls");
     fptr=fopen("student.dat","rb");
     
	  //Menampilkan seluruh data yang sudah diinput dengan bentuk tabel
      printf("\n\n\t\t\t\t\t\t\t\tDATA SELURUH MAHASISWA \n\n");
      printf("=====================================================================================================================================================\n");
      printf("NPM.             		Nama         			Matek    Diskrit    RL       OAK     DRE     Proglan     Rata-rata    Nilai Akhir |\n");
      printf("=====================================================================================================================================================\n");

      while((fread(&st,sizeof(st),1,fptr))>0)
     { 
       printf("%-6d 		%-10s 			%-3d 	  %-3d 	    %-3d      %-3d 	 %-3d        %-3d 	    %-3.2f  	    %-1c\n", st.npm, st.name, st.matek, st.diskrit, st.RL, st.OAK, st.DRE, st.Proglan, st.rata, st.grade);
     }
     printf("\n\n\n\n\n\nTekan ENTER untuk kembali ke menu utama\n");
     fclose(fptr);
     getch();
}


//****************************************************************
//                FUNCTION TO DISPLAY RESULT MENU
//****************************************************************

void result()
   {
   	int ans;
    char ch;
    system("cls");
    printf("\n\n\nMENU HASIL");
    printf("\n\n\n1. DATA KELAS\n\n");
	printf("2. KARTU RAPOR MAHASISWA\n\n");
	printf("3. TAMPILKAN SEMUA DATA MAHASISWA\n\n");
	printf("4. KEMBALI KE MENU UTAMA");
    printf("\n\n\nMasukkan Pilihan (1-4) ");
    ch=getche();
    switch(ch)
    {
     case '1' : class_result();break;
     case '2' :
		{
        do
        
		//perintah do digunakan untuk mencari data yang tersedia satu persatu
		{
			int npm;	
        	char ans;
        	system("cls");
        	printf("\n\n\tSilahkan Masukkan NPM Mahasiswa : ");
        	scanf("%d",&npm);
        	display_sp(npm);
        }while(ans=='y'|| ans=='Y');
        break;
        }
        
     	case '3' : display_all(); break;
		case '4' : break;
     	default  : printf("\a");
    	}
 }


//****************************************************************
//        				INTRODUCTION FUNCTION
//****************************************************************

void intro()  //Judul Halaman Depan Program
{	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tSTUDENT");
	printf("\n\t\t\t\t\t\t\t\t\t      REPORT CARD");
	printf("\n\t\t\t\t\t\t\t\t\t\tPROJECT");
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tMADE BY : KRISTIAN GIRSANG V HOSEA YOARANA");
	printf("\n\n\t\t\t\t\t\t\t\t\t  FACULTY OF ENGINEERING");
	printf("\n\n\t\t\t\t\t\t\t\t\t  UNIVERSITAS INDONESIA");
	getch();
}


//****************************************************************
//        			ENTRY / EDIT MENU FUNCTION
//****************************************************************

void entry_menu()
{
	
    char ch2;
   	system("cls");
   
   //Masuk Tampilan Pilihan di Entry Menu
	printf("\n\n\n\tENTRY MENU");
	printf("\n\n\t1. BUAT DATA BARU");
	printf("\n\n\t2. EDIT DATA MAHASISWA");
	printf("\n\n\t3. HAPUS DATA MAHASISWA");
	printf("\n\n\t4. KEMBALI KE MENU UTAMA");
	printf("\n\n\t Silahkan Masukkan Pilihan Anda(1-4) ");
	ch2=getche();
	switch(ch2)
  {
    case '1': system("cls");
          write_student();
          break;
    case '2': modify_student();break;
    case '3': delete_student();break;
    case '4': break; //Kembali ke menu utama
    default :	printf("\a");
	  			entry_menu();
   }
}


//***************************************************************
//                  	HELP FUNCTION
//***************************************************************

void help()
{
	system ("cls");
	char ch;
	printf("\n\n\n\nSelamat Datang Di Fitur Bantuan");
	printf("\n\n\nSilahkan Pilih Bantuan yang Anda Perlukan");
	printf("\n\n1. MENU HASIL");
	printf("\n\n2. MENU EDIT/TAMBAH DATA");
	printf("\n\n3. KEMBALI KE MENU UTAMA");
	printf("\n\nSilahkan masukkan pilihan Anda (1-3)  ");
	ch=getche();
	switch(ch)
	{
		case '1' : help_hasil();
			break;
		case '2' : help_edit();
			break;
		case '3' : main2();
		default  : printf("\a");
	}while(ch!='3');
}

help_hasil()
{
	system("cls");
	char ch;
	printf("\n\n\n\nPada Menu Ini, Terdapat Dua Pilihan Menu, Yaitu : \n");
	printf("\n1. Data Kelas");
	printf("\n\tPada Data Kelas, Akan Ditampilkan Data Seluruh Mahasiswa yang Telah Dimasukkan Sebelumnya");
	printf("\n2. Kartu Rapor Mahasiswa");
	printf("\n\tPada Menu ini, Akan Ditampilkan Data Rapor Setiap Mahasiswa");
	printf("\n\tSebelum Ditampilkan, Anda Masukkan NPM Mahasiswa yang Akan Dilihat Data Rapornya");
	printf("\n\n\n\tUntuk kembali ke Menu Utama, Silahkan Tekan Enter\n\n");
	getch();
	return main2();
}


void baru()
{
	system("cls");
	printf("\n\n\n\nPANDUAN UNTUK MEMBUAT DATA BARU");
	printf("\n1. Masukkan NPM mahasiswa yang akan dimasukkan nilainya");
	printf("\n2. Masukkan nama mahasiswa yang akan dimasukkan nilainya");
	printf("\n3. Masukkan nilai mahasiswa di setiap mata kuliah dengan rentang nilai 1-100");
	printf("\n4. Setelah nilai sudah diinput semua, maka secara otomatis nilai yang anda masukkan sudah tersimpan");
	printf("\n\n\t\tSelamat mencoba");
	printf("\n\n\nTekan ENTER untuk kembali ke MENU UTAMA\n\n");
	system("pause");
	main2();
}

void semua_data()
{
	system("cls");
	printf("\n\n\nPANDUAN UNTUK MENAMPILKAN SEMUA DATA MAHASISWA");
	printf("\n\n1. Data mahasiswa yang pertama akan ditampilkan setelah anda menekan tombol 'TAMPILKAN SEMUA DATA'");
	printf("\n2. Tekan ENTER untuk menampilkan data mahasiswa selanjutnya");
	printf("\n3. Setelah data mahasiswa terakhir ditampilkan, maka secara otomatis anda akan kembali ke menu utama");
	printf("\n\t\tSelamat Mencoba");
	printf("\n\n\n\nTekan ENTER untuk kembali ke MENU UTAMA\n\n");
	system("pause");
	main2();
}

void cari()
{
	system("cls");
	printf("\n\n\nPANDUAN UNTUK MENCARI DATA MAHASISWA");
	printf("\n\nUntuk mencari data mahasiswa, anda harus memasukkan NPM mahasiswa yang akan dicari datanya");
	printf("\nData yang anda minta akan langsung ditampilkan setelah anda memasukkan NPM mahasiswa");
	printf("\nUntuk kembali ke MENU UTAMA, anda dapat menekan tombol apa saja");
	printf("\nSelamat Mencoba");
	printf("\n\nTekan ENTER untuk kembali ke MENU UTAMA\n\n");
	system("pause");
	main2();
}

void edit()
{
	system("cls");
	printf("\n\n\nPANDUAN EDIT DATA MAHASISWA");
	printf("\n\n1. Masukkan NPM mahasiswa yang akan di edit datanya");
	printf("\n2. Masukkan NPM baru mahasiswa");
	printf("\n3. Masukkan Nilai baru mahasiswa");
	printf("\n4. Nilai baru yang dimasukkan akan secara otomatis tersimpan");
	printf("\n5. Untuk kembali ke MENU UTAMA, tekan ENTER\n\n");
	system("pause");
	main2();
}

void hapus()
{
	system("cls");
	printf("\n\n\nPANDUAN UNTUK HAPUS DATA MAHASISWA");
	printf("\n1. Masukkan NPM maahsiswa yang akan  dihapus datanya");
	printf("\n2. Secara otomatis data dari NPM yang disebutkan akan terhapus");
	printf("\n3. Tekan ENTER untuk kembali ke MENU UTAMA");
	printf("\n\nSelamat Mencoba\n\n");
	system("pause");
	main2();
}


help_edit()
{
	system("cls");
	char ch;
	printf("\n\n\n\nPada menu Edit, Terdapat 6 Pilihan yang akan Anda Pilih");
	printf("\n\nSilahkan Pilih Bantuan yang Anda Butuhkan");
	printf("\n\n01. BUAT DATA BARU");
	printf("\n\n02. TAMPILKAN SEMUA DATA");
	printf("\n\n03. CARI DATA MAHASISWA");
	printf("\n\n04. EDIT DATA MAHASISWA");
	printf("\n\n05. HAPUS DATA MAHASISWA");
	printf("\n\n06. KEMBALI KE MENU UTAMA");
	printf("\n\n\n Silahkan Masukkan Pilihan Anda (1-6)	");
	ch=getche();
	switch(ch)
	{
		case '1' : baru();
			break;
		case '2' : semua_data();
			break;
		case '3' : cari();
			break;
		case '4' : edit();
			break;
		case '5' : hapus();
			break;
		case '6' : main();
		default : printf("\a");
	}while(ch!='6');
}



//**************************************************************
//        		THE MAIN FUNCTION OF PROGRAM
//**************************************************************

main() {
  intro();
  system("cls");
  password_();
  main2();
}
//Menu Awal
//Digunakan Void Karena Tidak ada Pengolahan Data
main2() {
  char ch;
  system("cls");
  do
    {
      system("cls"); //Untuk Menutup tampilan Sebelumnya dan Emnampilkna Tampilan Selanjutnya
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. MENU HASIL");
      printf("\n\n\t02. EDIT/TAMBAH DATA");
      printf("\n\n\t03. BANTUAN");
      printf("\n\n\t04. KELUAR");
      printf("\n\n\tSilahkan Masukkan Pilihan Anda (1-4) ");
      ch=getche(); //Untuk memasukkan Pilihan tanpa Menekan tombol enter
      switch(ch)
      {
        case '1': system("cls");
				  result();
            break;
        case '2': entry_menu();
            break;
        case '3': help();
          	break;
        case '4': exit(0);
        default : printf("\a");
    }
    }while(ch!='4');//jika input tidak sama dengan deskripsi case, maka input ditolak
}


//***************************************************************
//                		   END OF PROJECT
//***************************************************************
