#include<iostream>
#include<iomanip>
#include <ostream>
#include<windows.h>
#include<conio.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dos.h>
using namespace std;

void gotoxy(int x, int y)
{
 COORD k = {x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}
void header(), header_makanan(), header_alat_tulis(),header_seragam();
void makanan(), alat_tulis(), seragam(), loading(), login(), menu(), daftar(), verifikasi(), horisamadengan();

    string userbaru;
    string passbaru;
main()
{
    loading();
    system("cls");
    login();
    system("cls");
}
void menu()
{
    int pilih;
    header();
    gotoxy(5,5);horisamadengan();
    gotoxy(5,6);cout << "|";
    gotoxy(25,6);cout<<"Menu Utama";
    gotoxy(56,6);cout << "|";
    gotoxy(5,7);horisamadengan();
    gotoxy(5,8);cout << "--------------------"<< endl;
    gotoxy(5,9);cout << "| [1]. Makanan     |" << endl;
    gotoxy(5,10);cout << "--------------------" << endl;
    gotoxy(5,11);cout << "| [2]. Alat Tulis  |" << endl;
    gotoxy(5,12);cout << "--------------------" << endl;
    gotoxy(5,13);cout << "| [3]. Seragam     |" << endl;
    gotoxy(5,14);cout << "--------------------" << endl;
    gotoxy(5,15);cout << "| [4]. Keluar      |" << endl;
    gotoxy(5,16);cout << "--------------------" << endl<<endl;
    pilih2 :
    cout << setw(31) << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    switch(pilih)
    {
    case 1: makanan(); break;
    case 2: alat_tulis(); break;
    case 3: seragam(); break;
    case 4: exit(EXIT_FAILURE); break;
    default :
        cout << endl;
        cout << setw(50) << "[ Pilihan Anda Tidak Tersedia ]\n" << endl;
        goto pilih2;
    }
}
void header()
{
    gotoxy(5,1);horisamadengan();
    gotoxy(5,2);cout << "|";
    gotoxy(5,3);cout << "|";
    gotoxy(11,2);cout<<"Aplikasi Inventori Gudang 'Kadang Koding'\n";
    gotoxy(13,3);cout<<"----- Created by Luky and Rona -----\n";
    gotoxy(56,2);cout << "|";
    gotoxy(56,3);cout << "|";
    gotoxy(5,4);horisamadengan();
}
void header_makanan()
{
    gotoxy(5,5);horisamadengan();
    gotoxy(5,6);cout << "|";
    gotoxy(28,6);cout<<"Makanan";
    gotoxy(56,6);cout << "|";
    gotoxy(5,7);horisamadengan();
}
void header_alat_tulis()
{
    gotoxy(5,5);horisamadengan();
    gotoxy(5,6);cout << "|";
    gotoxy(27,6);cout<<"Alat Tulis";
    gotoxy(56,6);cout << "|";
    gotoxy(5,7);horisamadengan();
}
void header_seragam()
{
    gotoxy(5,5);horisamadengan();
    gotoxy(5,6);cout << "|";
    gotoxy(28,6);cout<<"Seragam";
    gotoxy(56,6);cout << "|";
    gotoxy(5,7);horisamadengan();
}
void makanan()
{
    int pilih;
    awal_makanan :
    system("cls");
    header();
    header_makanan();
    gotoxy(5,8);cout << "---------------------" << endl;
    gotoxy(5,9);cout << "++ 1. Input Barang ++" << endl;
    gotoxy(5,10);cout << "---------------------" << endl;
    gotoxy(5,11);cout << "++ 2. Cek Stok     ++" << endl;
    gotoxy(5,12);cout << "---------------------" << endl;
    gotoxy(5,13);cout << "++ 3. Kembali      ++" << endl;
    gotoxy(5,14);cout << "---------------------" << endl<<endl;
    pilih1 :
    cout << setw(31) << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1)
    {
        simpan :
        system("cls");
        header();
        header_makanan;
        int a;
        struct data{
                    int jumlah;
                    string nama;
                    string satuan;
                    } barang[50];
        cout << endl;
        header_makanan();
        cout << "\n" << setw(52) << ">> Masukan Jumlah Barang Yang Ingin di Input : ";
        cin >> a;
        cout<<endl;
        for (int i=1; i<=a; i++)
        {
            cout << setw(6); horisamadengan();
            cout << setw(6) << "|";
            cout << setw(33) << "Data Barang ke - " << i << setw(17) << "|" << endl;
            cout << setw(6); horisamadengan();
            cout << endl;
            string spasi;
            cout<<"";
            std :: getline(std :: cin, spasi);
            cout << setw(46) << ">> Nama Barang                         : ";
            std :: getline(std :: cin, barang[i].nama);
            cout << setw(46)<< ">> Jumlah Barang                       : ";
            cin >> barang[i].jumlah;
            cout << setw(46) << ">> Satuan Barang (Buah/Kg/Bungkus/...) : ";
            cin >> barang[i].satuan;
            cout << endl;
        }
            //simpan
            for (int i=1; i<=a; i++)
            {
                int n = 30 - barang[i].nama.length(); //jarak nama dengan jumlah
                int o = 10 + barang[i].satuan.length();
                int p = 10 - barang[i].satuan.length();
                ofstream simpan_barang;
                simpan_barang.open("db_barang.txt", ios :: app);
                simpan_barang << "\n     | " << barang[i].nama;
                simpan_barang << setw(n) << barang[i].jumlah;
                simpan_barang << setw(o) << barang[i].satuan;
                simpan_barang << setw(p)<< "|";
                simpan_barang.close();
            }
        system("cls");
        header();
        header_makanan();
        gotoxy(5,9);horisamadengan();
        gotoxy(5,10);cout << "|";
        gotoxy(20,10);cout << "Data Berhasil Disimpan";
        gotoxy(56,10);cout << "|";
        gotoxy(5,11);horisamadengan();
        gotoxy(5,13);horisamadengan();
        gotoxy(5,14);cout << "| No";
        gotoxy(12,14);cout << "Nama Barang";
        gotoxy(28,14);cout << "Jumlah Barang";
        gotoxy(44,14);cout << "Satuan";
        gotoxy(56,14);cout << "|";
        gotoxy(5,15);horisamadengan();
        for (int i=1; i<=a; i++)
        {
            gotoxy(5,15+i);cout << "| " << i;
            gotoxy(12,15+i);cout << barang[i].nama;
            gotoxy(35,15+i);cout << barang[i].jumlah;
            gotoxy(44,15+i);cout << barang[i].satuan;
            gotoxy(56,15+i);cout << "|";
        }
        cout << "\n" << setw(6); horisamadengan();
        kembali1 :
        char yn;
        cout << "\n" << setw(51) << ">> Apakah Anda ingin input data lagi? (Y/N) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto simpan;
        }
        else if (yn == 'N' || yn == 'n')
        {
            goto awal_makanan;
        }
        else
        {
            cout << "\n" << setw(50) << "[ Masukan Huruf Y atau N !!! ]" << endl;
            goto kembali1;
        }
    }
    else if (pilih == 2)
    {
        string baca;
        string baris;
        ifstream data;
        data.open ("db_barang.txt"); // membuka databse
        while(!data.eof()) //membaca data secara keseluruhan
        {
            getline(data, baris);
            baca += baris+"\n";
        }
        data.close();
        system("cls");
        header();
        header_makanan();
        gotoxy(5,9);horisamadengan();
        gotoxy(5,10);cout << "|";
        gotoxy(29,10);cout << "Stok";
        gotoxy(56,10);cout << "|";
        gotoxy(5,11);horisamadengan();
        gotoxy(5,13);horisamadengan();
        gotoxy(5,14);cout << "| Nama Barang";
        gotoxy(28,14);cout << "Jumlah Barang";
        gotoxy(47,14); cout << "Satuan   |" << endl;
        gotoxy(5,15);
        for(int i=0; i<52; i++)
        {
        cout<<"=";
        }
        cout << baca; // menampilkan data ke layar
        cout << setw(6); horisamadengan();
        char yn;
        kembali2:
        cout << "\n" << setw(37) << ">> Apakah Anda kembali? (Y/N) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto awal_makanan;
        }
        else if (yn == 'N' || yn == 'n')
        {
            exit(EXIT_FAILURE);
        }
        else
        {
            cout << "\n" << setw(50) << "[ Masukan Huruf Y atau N !!! ]" << endl;
            goto kembali2;
        }
    getch();
    }
    else if (pilih == 3)
    {
        system("cls");
        menu();
    }
    else
    {
        cout << endl;
        cout << setw(50) << "[ Pilihan Anda Tidak Tersedia ]\n" << endl;
        goto pilih1;
    }
}
void alat_tulis()
{
int pilih;
    awal_alat :
    system("cls");
    header();
    header_alat_tulis();
    gotoxy(5,8);cout << "---------------------" << endl;
    gotoxy(5,9);cout << "++ 1. Input Barang ++" << endl;
    gotoxy(5,10);cout << "---------------------" << endl;
    gotoxy(5,11);cout << "++ 2. Cek Stok     ++" << endl;
    gotoxy(5,12);cout << "---------------------" << endl;
    gotoxy(5,13);cout << "++ 3. Kembali      ++" << endl;
    gotoxy(5,14);cout << "---------------------" << endl<<endl;
    pilih3 :
    cout << setw(31) << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1)
    {
        simpan_alat_tulis :
        system("cls");
        header();
        header_alat_tulis();
        int a;
        struct data{
                    int jumlah;
                    string nama;
                    } alat[20];
        cout << endl;
        header_alat_tulis();
        cout << "\n" << setw(52) << ">> Masukan Jumlah Barang Yang Ingin di Input : ";
        cin >> a;
        cout<<endl;
        for (int i=1; i<=a; i++)
        {
            cout << setw(6); horisamadengan();
            cout << setw(6) << "|";
            cout << setw(33) << "Data Barang ke - " << i << setw(17) << "|" << endl;
            cout << setw(6); horisamadengan();
            cout << endl;
            string spasi;
            cout<<"";
            std :: getline(std :: cin, spasi);
            cout << setw(26) << ">> Nama Barang     : ";
            std :: getline(std :: cin, alat[i].nama);
            cout << setw(26)<< ">> Jumlah Barang   : ";
            cin >> alat[i].jumlah;
            cout << endl;
        }
            //simpan
            for (int i=1; i<=a; i++)
            {
                int n = 40 - alat[i].nama.length();
                ofstream simpan_alat;
                simpan_alat.open("db_alat_tulis.txt", ios :: app);
                simpan_alat << "\n     | " << alat[i].nama;
                simpan_alat << setw(n) << alat[i].jumlah;
                simpan_alat << setw(10)<< "|";
                simpan_alat.close();
            }

        system("cls");
        header();
        header_alat_tulis();
        gotoxy(5,9);horisamadengan();
        gotoxy(5,10);cout << "|";
        gotoxy(20,10);cout << "Data Berhasil Disimpan";
        gotoxy(56,10);cout << "|";
        gotoxy(5,11);horisamadengan();
        gotoxy(5,13);horisamadengan();
        gotoxy(5,14);cout << "| No";
        gotoxy(12,14);cout << "Nama Barang";
        gotoxy(38,14);cout << "Jumlah Barang";
        gotoxy(56,14);cout << "|";
        gotoxy(5,15);horisamadengan();
        for (int i=1; i<=a; i++)
        {
            gotoxy(5,15+i);cout << "| " << i;
            gotoxy(12,15+i);cout << alat[i].nama;
            gotoxy(45,15+i);cout << alat[i].jumlah;
            gotoxy(56,15+i);cout << "|";
        }
        cout << "\n" << setw(6); horisamadengan();
        kembali :
        char yn;
        cout << "\n" << setw(51) << ">> Apakah Anda ingin input data lagi? (Y/N) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto simpan_alat_tulis;
        }
        else if (yn == 'N' || yn == 'n')
        {
            goto awal_alat;
        }
        else
        {
            cout << "\n" << setw(50) << "[ Masukan Huruf Y atau N !!! ]" << endl;
            goto kembali;
        }
    }
    else if (pilih == 2)
    {
        string baca;
        string baris;
        ifstream data;
        data.open ("db_alat_tulis.txt"); // membuka file dataku.txt
        while(!data.eof()) //membaca data secara keseluruhan
        {
            getline(data, baris);
            baca += baris+"\n";
        }
        data.close();
        system("cls");
        header();
        header_alat_tulis();
        gotoxy(5,9);horisamadengan();
        gotoxy(5,10);cout << "|";
        gotoxy(29,10);cout << "Stok";
        gotoxy(56,10);cout << "|";
        gotoxy(5,11);horisamadengan();
        gotoxy(5,13);horisamadengan();
        gotoxy(5,14);cout << "| Nama Barang";
        gotoxy(38,14);cout << "Jumlah Barang";
        gotoxy(56,14); cout << "|" << endl;
        gotoxy(5,15);
        for(int i=0; i<52; i++)
        {
        cout<<"=";
        }
        cout << baca; // menampilkan data ke layar
        cout << setw(6); horisamadengan();

        char yn;
        kembali2:
        cout << "\n" << setw(37) << ">> Apakah Anda kembali? (Y/N) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto awal_alat;
        }
        else if (yn == 'N' || yn == 'n')
        {
            exit(EXIT_FAILURE);
        }
        else
        {
            cout << "\n" << setw(50) << "[ Masukan Huruf Y atau N !!! ]" << endl;
            goto kembali2;
        }
        getch();
    }
    else if (pilih == 3)
    {
        system("cls");
        menu();
    }
    else
    {
        cout << endl;
        cout << setw(50) << "[ Pilihan Anda Tidak Tersedia ]\n" << endl;
        goto pilih3;
    }
}
void seragam()
{
    int pilih;
    awal_seragam :
    system("cls");
    header();
    header_seragam();
    gotoxy(5,8);cout << "---------------------" << endl;
    gotoxy(5,9);cout << "++ 1. Input Barang ++" << endl;
    gotoxy(5,10);cout << "---------------------" << endl;
    gotoxy(5,11);cout << "++ 2. Cek Stok     ++" << endl;
    gotoxy(5,12);cout << "---------------------" << endl;
    gotoxy(5,13);cout << "++ 3. Kembali      ++" << endl;
    gotoxy(5,14);cout << "---------------------" << endl<<endl;
    pilih4 :
    cout << setw(31) << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1)
    {
        simpan_data :
        system("cls");
        header();
        header_seragam;
        int a;
        struct data{
                    int jumlah;
                    string nama;
                    string ukuran;
                    } sera_gam[20];

        cout << endl;
        header_seragam();
        cout << "\n" << setw(52) << ">> Masukan Jumlah Barang Yang Ingin di Input : ";
        cin >> a;
        cout<<endl;
        for (int i=1; i<=a; i++)
        {
            cout << setw(6); horisamadengan();
            cout << setw(6) << "|";
            cout << setw(33) << "Data Barang ke - " << i << setw(17) << "|" << endl;
            cout << setw(6); horisamadengan();
            cout << endl;
            string spasi;
            cout<<"";
            std :: getline(std :: cin, spasi);
            cout << setw(26) << ">> Nama Barang     : ";
            std :: getline(std :: cin, sera_gam[i].nama);
            cout << setw(26) << ">> Jumlah Barang   : ";
            cin >> sera_gam[i].jumlah;
            cout << setw(26) << ">> Ukuran          : ";
            cin >> sera_gam[i].ukuran;
            cout << endl;
        }
            //simpan
            for (int i=1; i<=a; i++)
            {
                int n = 30 - sera_gam[i].nama.length(); //jarak nama dengan jumlah
                int o = 10 + sera_gam[i].ukuran.length();
                int p = 10 - sera_gam[i].ukuran.length();
                ofstream simpan_seragam;
                simpan_seragam.open("db_seragam.txt", ios :: app);
                simpan_seragam << "\n     | " << sera_gam[i].nama;
                simpan_seragam << setw(n) << sera_gam[i].jumlah;
                simpan_seragam << setw(o) << sera_gam[i].ukuran;
                simpan_seragam << setw(p) << "|";
                simpan_seragam.close();
            }

        system("cls");
        header();
        header_seragam();
        gotoxy(5,9);horisamadengan();
        gotoxy(5,10);cout << "|";
        gotoxy(20,10);cout << "Data Berhasil Disimpan";
        gotoxy(56,10);cout << "|";
        gotoxy(5,11);horisamadengan();
        gotoxy(5,13);horisamadengan();
        gotoxy(5,14);cout << "| No";
        gotoxy(12,14);cout << "Nama Barang";
        gotoxy(28,14);cout << "Jumlah Barang";
        gotoxy(44,14);cout << "Ukuran";
        gotoxy(56,14);cout << "|";
        gotoxy(5,15);horisamadengan();
        for (int i=1; i<=a; i++)
        {
            gotoxy(5,15+i);cout << "| " << i;
            gotoxy(12,15+i);cout << sera_gam[i].nama;
            gotoxy(35,15+i);cout << sera_gam[i].jumlah;
            gotoxy(44,15+i);cout << sera_gam[i].ukuran;
            gotoxy(56,15+i);cout << "|";
        }
        cout << "\n" << setw(6); horisamadengan();
        kembali :
        char yn;
        cout << "\n" << setw(51) << ">> Apakah Anda ingin input data lagi? (Y/N) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto simpan_data;
        }
        else if (yn == 'N' || yn == 'n')
        {
            goto awal_seragam;
        }
        else
        {
            cout << "\n" << setw(50) << "[ Masukan Huruf Y atau N !!! ]" << endl;
            goto kembali;
        }
    }
    else if (pilih == 2)
    {
        string baca;
        string baris;
        ifstream data;
        data.open ("db_seragam.txt"); // membuka file database
        while(!data.eof()) //membaca data secara keseluruhan
        {
            getline(data, baris);
            baca += baris+"\n";

        }
        data.close();
        system("cls");
        header();
        header_seragam();
        gotoxy(5,9);horisamadengan();
        gotoxy(5,10);cout << "|";
        gotoxy(29,10);cout << "Stok";
        gotoxy(56,10);cout << "|";
        gotoxy(5,11);horisamadengan();
        gotoxy(5,13);horisamadengan();
        gotoxy(5,14);cout << "| Nama Barang";
        gotoxy(28,14);cout << "Jumlah Barang";
        gotoxy(47,14); cout << "Ukuran   |" << endl;
        gotoxy(5,15);
        for(int i=0; i<52; i++)
        {
        cout<<"=";
        }
        cout << baca; // menampilkan data ke layar
        cout << setw(6); horisamadengan();
        char yn;
        kembali2:
        cout << "\n" << setw(37) << ">> Apakah Anda kembali? (Y/N) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y')
        {
            goto awal_seragam;
        }
        else if (yn == 'N' || yn == 'n')
        {
            exit(EXIT_FAILURE);
        }
        else
        {
            cout << "\n" << setw(50) << "[ Masukan Huruf Y atau N !!! ]" << endl;
            goto kembali2;
        }

        getch();

    }
    else if (pilih == 3)
    {
        system("cls");
        menu();
    }
    else
    {
        cout << endl;
        cout << setw(50) << "[ Pilihan Anda Tidak Tersedia ]\n" << endl;
        goto pilih4;
    }
}
void loading()
{
    header();
    system("color 0a");
    gotoxy(25,8);cout << "Memuat Program";
    char a=177, b=219;
    gotoxy(21,10);
    for (int i=0;i<=20;i++)
    std::cout<<a;
    std::cout<<"\r";
    gotoxy(21,10);
    for (int i=0;i<=20;i++)
    {
        std::cout<<b;
        for (int j=0;j<=3e7;j++);
    }
}
void login()
{
    header();
    int i;
    char ch;
    gotoxy(5,5);horisamadengan();
    gotoxy(5,6);cout << "|";
    gotoxy(28,6);cout<<"Login";
    gotoxy(56,6);cout << "|";
    gotoxy(5,7);horisamadengan();
    gotoxy(5,8);cout << ">> Belum punya akun? "<< endl;
    gotoxy(5,9);cout << ">> Ketik 1 di username & password untuk daftar"<<endl;
    cout<<endl<<endl;

    for (i=1; i<=3; i++)
    {
        string user;
        string pass;
        cout << setw(18) << "> Username : "; cin>>user;
        cout << setw(18) << "> Password : ";
        ch = getch();

            while(ch != 13)
                {

                    if (ch == '\b')
                    {
                        cout << "\b \b";
                        pass.erase(pass.size() - 1, 1);
                        ch = getch();
                        continue;
                    }
                    else
                    {
                        pass.push_back(ch);
                        cout << '*';
                        ch = getch();
                        continue;
                    }
                }

       if (user == "luky" && pass == "12345")
        {
         system("cls");
         menu();
        }
       else if (user == "ronafbrn" && pass == "12345")
        {
         system("cls");
         menu();
        }
        else if (user == "1" && pass == "1")
        {
            system("cls");
            daftar();
        }
        else if (user == userbaru && pass == passbaru)
        {
            system("cls");
            menu();
        }
       else
        {
         cout << "\n\n" << setw(57) << "[ Maaf Username & Password anda masukan salah ] \n" << endl;
        }
   }
   while (i <= 3);

   cout << setw(63) << "> Anda telah 3x memasukan Username & Password yang salah.\n";
   cout << setw(61) << "> Silahkan hubungi kami melalui e-mail support@email.com";
   cout << "\n\n" << setw(42) << "[ Terima Kasih ] \n" << endl;
   exit(EXIT_FAILURE);
}
void daftar()
{

    char nohp[20];
    header();
    gotoxy(5,5);horisamadengan();
    gotoxy(5,6);cout << "|";
    gotoxy(12,6); cout << "Selamat Datang di Form Pendaftaran\n";
    gotoxy(56,6);cout << "|";
    gotoxy(5,7);horisamadengan();
    cout << endl;
    cout << setw(31) << ">> Masukan Username     : "; cin>>userbaru;
    cout << setw(31) << ">> Masukan Password     : "; cin>>passbaru;
    cout << setw(31) << ">> Masukan No Handphone : "; cin>>nohp;
    cout<<endl<<endl;
    verifikasi();
}
void verifikasi()
{
    int kodeverif, x, n = 10000;
    srand((unsigned)time(NULL));
    x = rand()%n;

    cout << setw(40) << "[ Kode Verifikasi : " << x  << " ]" << endl;
    cout << endl;
    balik :
    cout << setw(34) << ">> Masukan kode verifikasi : "; cin>>kodeverif;
    cout<<endl;
    if (kodeverif == x)
    {
        cout << setw(50) <<"[ Selamat anda telah terdaftar! ]"<<endl;
        cout << endl;
        system("pause");
            system("cls");
            login();
    }
    else
    {
        cout << setw(52) << "[ Kode verifikasi yang anda masukan salah! ]"<<endl<<endl;
        goto balik;
    }
    verifikasi();
    getch();
}
void horisamadengan()
{
    for(int i=0; i<52; i++)
    {
        cout<<"=";
    }
    cout << endl;
}
