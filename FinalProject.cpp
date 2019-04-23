#include<iostream>
#include<iomanip>
#include <ostream>
#include<windows.h>
#include<conio.h>
#include <fstream>
#include <stdlib.h>
#include <dos.h>

using namespace std;


void header(), makanan(), alat_tulis(), seragam(), loading(), login(), menu(), daftar(), verifikasi();

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
    cout << "--------------------"<< endl;
    cout << "| [1]. Makanan     |" << endl;
    cout << "--------------------" << endl;
    cout << "| [2]. Alat Tulis  |" << endl;
    cout << "--------------------" << endl;
    cout << "| [3]. Seragam     |" << endl;
    cout << "--------------------" << endl;
    cout << "| [4]. Keluar      |" << endl;
    cout << "--------------------" << endl<<endl;
    pilih2 :
    cout << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    switch(pilih)
    {
    case 1: makanan(); break;
    case 2: alat_tulis(); break;
    case 3: seragam(); break;
    case 4: exit(EXIT_FAILURE); break;
    default :
        cout << "Pilihan Anda Tidak Tersedia\n" << endl;
        goto pilih2;
    }
}

void header()
{
    cout << "======================***=====================" << endl;
    cout << ">> Aplikasi Inventori Gudang 'Kadang Koding'<<" << endl;
    cout << "======================***=====================" << endl<<endl;
}

void makanan()
{
    int pilih;
    awal_makanan :
    system("cls");
    header();
    cout << "===========***===========" << endl;
    cout << ">> Penyimpanan Makanan <<" << endl;
    cout << "===========***===========" << endl<<endl<<endl;


    cout << "---------------------" << endl;
    cout << "++ 1. Input Barang ++" << endl;
    cout << "---------------------" << endl;
    cout << "++ 2. Cek Stok     ++" << endl;
    cout << "---------------------" << endl;
    cout << "++ 3. Kembali      ++" << endl;
    cout << "---------------------" << endl<<endl;
    pilih1 :
    cout << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1)
    {
        int a;

        struct data{
                    int jumlah;
                    string nama;
                    string satuan;
                    } barang[20];
        simpan :
        cout << "\n>> Masukan Jumlah Barang Yang Ingin di Input >> : ";
        cin >> a;
        cout<<endl;
        for (int i=1; i<=a; i++)
        {
            cout << ">> - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << ">> Data Barang ke - " << i << endl;
            cout << "> Nama Barang                            : ";
            cin >> barang[i].nama;
            cout << "- - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << "> Jumlah Barang                          : ";
            cin >> barang[i].jumlah;
            cout << "- - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << "> Satuan Barang (Buah/Kg/Bungkus/...)    : ";
            cin >> barang[i].satuan;
            cout << "------------------------------------------" << endl;

            //simpan
            ofstream simpan_barang;
            simpan_barang.open("db_barang.txt", ios :: app);
            for (int i=1; i<=a; i++)
            {
            simpan_barang << barang[i].nama << "\t";
            simpan_barang << "\t" << barang[i].jumlah << "\t";
            simpan_barang << "\t" << barang[i].satuan << endl;
            simpan_barang.close();
            }

        }

        cout << "\n Data Sukses Disimpan " << endl;
        cout << "\n No";
        cout << "\t Nama Barang";
        cout << "\t Jumlah Barang";
        cout << "\t Satuan" << endl;
        for (int i=1; i<=a; i++)
        {
            cout << " " << i;
            cout << "\t " << barang[i].nama;
            cout << "\t\t " << barang[i].jumlah;
            cout << "\t\t " << barang[i].satuan << endl;
        }

        kembali1 :
        char yn;
        cout << "\n>> Apakah Anda ingin input data lagi? (Y/N) : ";
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
            cout << ">> Masukan huruf Y atau N !!!" << endl;
            goto kembali1;
        }
    }
    else if (pilih == 2)
    {

        string baca;
        string baris;
        ifstream data;
        data.open ("db_barang.txt"); // membuka file dataku.txt
        while(!data.eof()) //membaca data secara keseluruhan
        {
            getline(data, baris);
            baca += baris+"\n";

        }
        data.close();
        system("cls");
        header();
        cout << "\nNama Barang";
        cout << "\tJumlah Barang";
        cout << "\tSatuan" << endl;
        cout << baca; // menampilkan data ke layar


        char yn;
        kembali2:
        cout << "\n>> Apakah Anda kembali? (Y/N) : ";
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
            cout << ">> Masukan huruf Y atau N !!!" << endl;
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
        cout << "Pilihan Anda Tidak Tersedia \n" << endl;
        goto pilih1;
    }
}

void alat_tulis()
{
int pilih;
    awal_alat :
    system("cls");
    header();
    cout << "=============***============" << endl;
    cout << ">> Penyimpanan Alat Tulis <<" << endl;
    cout << "=============***============" << endl<<endl<<endl;

    cout << "---------------------" << endl;
    cout << "++ 1. Input Barang ++" << endl;
    cout << "---------------------" << endl;
    cout << "++ 2. Cek Stok     ++" << endl;
    cout << "---------------------" << endl;
    cout << "++ 3. Kembali      ++" << endl;
    cout << "---------------------" << endl<<endl;
    pilih3 :
    cout << ">> Masukan Pilihan Anda : ";
    cin >> pilih;

    if (pilih == 1)
    {
        int a;

        struct data{
                    int jumlah;
                    string nama;
                    } alat[20];
        simpan_alat_tulis :
        cout << "\n>> Masukan Jumlah Barang Yang Ingin di Input : ";
        cin >> a;
        cout<<endl;
        for (int i=1; i<=a; i++)
        {
            cout << ">> - - - - - - - - -" << endl;
            cout << ">> Data Barang ke - " << i << endl;
            cout << "> Nama Barang    : ";
            cin >> alat[i].nama;
            cout << "- - - - - - - - -" << endl;
            cout << "> Jumlah Barang  : ";
            cin >> alat[i].jumlah;
            cout << "- - - - - - - - -" << endl;

            //simpan
            ofstream simpan_alat;
            simpan_alat.open("db_alat_tulis.txt", ios :: app);
            for (int i=1; i<=a; i++)
            {
            simpan_alat << alat[i].nama << "\t";
            simpan_alat << alat[i].jumlah << endl;
            simpan_alat.close();
            }

        }

        cout << "\nData Sukses Disimpan " << endl;
        cout << "\nNo";
        cout << "\tNama";
        cout << "\tJumlah Barang" << endl;

        for (int i=1; i<=a; i++)
        {
            cout << i;
            cout << "\t" << alat[i].nama;
            cout << "\t" << alat[i].jumlah << endl;
        }

        kembali :
        char yn;
        cout << "\n >> Apakah Anda ingin input data lagi? (Y/N) : ";
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
            cout << ">> Masukan huruf Y atau N !!!" << endl;
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
        cout << baca; // menampilkan data ke layar

        char yn;
        kembali2:
        cout << "\n >> Apakah Anda kembali? (Y/N) : ";
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
            cout << ">> Masukan huruf Y atau N !!!" << endl;
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
        cout << "Pilihan Anda Tidak Tersedia \n" << endl;
        goto pilih3;
    }
}

void seragam()
{
    int pilih;
    awal_seragam :
    system("cls");
    header();
    cout << "===========***===========" << endl;
    cout << ">> Penyimpanan Seragam <<" << endl;
    cout << "===========***===========" << endl<<endl<<endl;


    cout << "---------------------" << endl;
    cout << "++ 1. Input Barang ++" << endl;
    cout << "---------------------" << endl;
    cout << "++ 2. Cek Stok     ++" << endl;
    cout << "---------------------" << endl;
    cout << "++ 3. Kembali      ++" << endl;
    cout << "---------------------" << endl<< endl;
    pilih4 :
    cout << ">> Masukan Pilihan Anda : ";
    cin >> pilih;
    cout<<endl;
    if (pilih == 1)
    {
        int a;

        struct data{
                    int jumlah;
                    string nama;
                    string ukuran;
                    } sera_gam[20];
        simpan_data :
        cout << ">> Masukan Jumlah Barang Yang Ingin di Input >> : ";
        cin >> a;
        cout<<endl;
        for (int i=1; i<=a; i++)
        {
            cout << ">> - - - - - - - - -" << endl;
            cout << ">> Data Barang ke - " << i << endl;
            cout << "> Nama Barang    : ";
            cin >> sera_gam[i].nama;
            cout << "- - - - - - - - -" << endl;
            cout << "> Jumlah Barang  : ";
            cin >> sera_gam[i].jumlah;
            cout << "- - - - - - - - -" << endl;
            cout << "> Ukuran         : ";
            cin >> sera_gam[i].ukuran;
            cout << "- - - - - - - - -" << endl;

            //simpan
            ofstream simpan_seragam;
            simpan_seragam.open("db_seragam.txt", ios :: app);
            for (int i=1; i<=a; i++)
            {
            simpan_seragam << sera_gam[i].nama << "\t";
            simpan_seragam << sera_gam[i].jumlah << "\t";
            simpan_seragam << sera_gam[i].ukuran << endl;
            simpan_seragam.close();
            }

        }

        cout << "\nData Sukses Disimpan " << endl;
        cout << "\nNo";
        cout << "\tNama Barang";
        cout << "\tJumlah Barang";
        cout << "\tUkuran" << endl;
        for (int i=1; i<=a; i++)
        {
            cout << i;
            cout << "\t" << sera_gam[i].nama;
            cout << "\t" << sera_gam[i].jumlah;
            cout << "\t" << sera_gam[i].ukuran << endl;
        }

        kembali :
        char yn;
        cout << ">>\n Apakah Anda ingin input data lagi? (Y/N) : ";
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
            cout << ">> Masukan huruf Y atau N !!!" << endl;
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
        cout << baca; // menampilkan data ke layar

        char yn;
        kembali2:
        cout << ">>\n Apakah Anda kembali? (Y/N) : ";
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
            cout << ">> Masukan huruf Y atau N !!!" << endl;
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
        cout << "Pilihan Anda Tidak Tersedia \n" << endl;
        goto pilih4;
    }
}

void loading()
{
    system("color 0a");
 std::cout << "\n\n\n\t\t\t\tMemuat Program\n\n";
 char a=177, b=219;
 std::cout<<"\t\t\t\t";
 for (int i=0;i<=15;i++)
 std::cout<<a;
 std::cout<<"\r";
 std::cout<<"\t\t\t\t";
 for (int i=0;i<=15;i++)
 {
  std::cout<<b;
  for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
 }
}

void login()
{
    int i;
char ch;
cout << "=============**=============\n";
cout << "Selamat Datang di Form Login \n";
cout << "=============**=============\n";
cout << endl<<endl;
    for (i=1; i<=3; i++) {
       string user = "";
       string pass = "";

       cout << ">> Belum punya akun? ketik 1 di username dan password untuk mendaftar <<"<<endl;
       cout<<endl<<endl;

       cout << "> Username : "; cin>>user;
       cout << "> Password : ";
            ch = _getch();
            while(ch != 13){//character 13 is enter
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
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
         cout << ">>\n\nMaaf Username & Password anda masukan salah.\n\n<<";
        }
   }
   while (i <= 3);

   cout << ">Anda telah 3x memasukan Username & Password yang salah.\n<";
   cout << ">Mohon maaf akun anda kami blokir untuk sementara. \n<";
   cout << ">Silahkan hubungi kami melalui e-mail support@email.com, Terima Kasih..<";
   getch();
}
void daftar()
{

    char nohp[20];

cout << "===================***==================\n";
cout << ">> Selamat Datang di Form Pendaftaran <<\n";
cout << "===================***==================\n";
cout << endl;

    cout<<">> Masukan Username     : "; cin>>userbaru;
    cout<<">> Masukan Password     : "; cin>>passbaru;
    cout<<">> Masukan No Handphone : "; cin>>nohp;
    cout<<endl<<endl;

    cout<<"[ Kami telah mengirim kode verifikasi ke no hp anda! ]"<<endl<<endl;
    verifikasi();


}
void verifikasi()
{
    string kodeverif;
    string kodelogin;

    cout<<">> Masukan kode verifikasi >> : "; cin>>kodeverif;
    cout<<endl<<endl;
    if (kodeverif == "unsika")
    {
        cout<<">> Selamat anda telah terdaftar!"<<endl;
        system("pause");
            system("cls");
            login();
    }else
    {
        cout<<"[ Kode verifikasi yang anda masukan salah! ]"<<endl<<endl;
    }
    verifikasi();
}
