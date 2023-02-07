#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//unt batas percobaan akun
int batas = 0;

struct login{
	char nama[50];
	char sandi[50];
}cek;

struct part{
	int kode;
	char kategori[40];
	char nama_brg[40];
	char kategorii[40];
	char nama_brgg[40];
	int stok;
	long int harga;
	struct part *next;
}*head, *tail, *prev_mode;


void tambahakhir(int kode, char* kategori, char* nama_brg, int stok, long int harga){
	struct part *part = (struct part *) malloc(sizeof(struct part));
	struct part *tail = head;
	part->kode = kode;
	strcpy(part->kategori, kategori);
	strcpy(part->nama_brg, nama_brg);
	part->stok = stok;
	part->harga = harga;
	part->next = NULL;
	
	if (head==NULL){
		head = part;
	}else{
		while(tail->next != NULL){
			tail = tail->next;
		}
		tail->next = part;
	}
}

void tambahtengah (int kode, char *kategori, char *nama_brg, int stok, long int harga){
	int i;
	struct part *part = (struct part *) malloc(sizeof(struct part));
	struct part *after = head;
	part->kode = kode;
	strcpy(part->kategori, kategori);
	strcpy(part->nama_brg, nama_brg);
	part->stok = stok;
	part->harga = harga;
	part->next = NULL;
	
	if (head==NULL){
		head = part;
		part->next = NULL;
		return;
	}
	printf("Barang Akan di Sisipkan Setelah Kode :  ");
	scanf("%d", &i);
	while(after->kode != i){
		if (after->next == NULL){
			printf("==============================================\n");
			printf("      Kode Data Barang Tidak Ditemukan!\n");
			printf("==============================================\n");
			getch();
			tambahin();
		}
		after = after->next;
	}
	part->next = after->next;
	after->next = part;	
}

void lihat(){
	struct part *temp = head;
	if (temp!=NULL){
		printf("Kode Barang\tSpare/Var\tNama Barang\tStok Barang\tHarga Barang\n");
		printf("=============================================================================\n");
	while (temp!=NULL){
		printf("%d\t\t", temp->kode);
		printf("%s\t\t", temp->kategori);
		printf("%s\t\t", temp->nama_brg);
		printf("%d\t\t", temp->stok);
		printf("%d\n", temp->harga);
		temp = temp->next;
	}
	}else{
		printf("\n\t\t\t    DATA KOSONG!!!!!");
	}
}

void edit(int kode){
	struct part *temp = head;
	while(temp!=NULL){
		if(temp->kode == kode){
			printf("==============================================\n");
			printf("          Kode Barang %d Ditemukan!!\n", kode);
			printf("==============================================\n");
			while ((getchar()) != '\n');
			printf("Ubah Kategori Barang Menjadi(s/v)\t: ");
			scanf(" %[^\n]s", temp->kategori);
			while ((getchar()) != '\n');
			printf("Ubah Nama Barang Menjadi\t\t: ");
			scanf(" %[^\n]s", temp->nama_brg);
			while ((getchar()) != '\n');
			printf("Ubah Stok Barang Menjadi\t\t: ");
			scanf("%d", &temp->stok);
			while ((getchar()) != '\n');
			printf("Ubah Harga Barang Menjadi\t\t: ");
			scanf("%li", &temp->harga);
			printf("==============================================\n");
			printf("          Data Barang Berhasil Diedit");
			return;
		}
		temp = temp->next;
	}
	printf("Kode Barang Tidak Ditemukan\n");
}

void hapus(int kode){
	struct part *temp1 = head;
	struct part *temp2 = head;
	
	while(temp1 != NULL){
		if(temp1->kode == kode){
			printf("       Barang Dengan Kode %d Ditemukan!\n", kode);
			
			if(temp1==temp2){
				head = head->next;
				free(temp1);
			}
			else{
				temp2->next = temp1->next;
				free(temp1);
			}
			printf("        DATA BARANG BERHASIL DIHAPUS \n");
			printf("==============================================\n");
			return;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
	printf("Barang Berkode %d Tidak Ditemukan!!!\n", kode);
}

void cari(int kode){
	struct part *temp = head;
	while(temp!=NULL){
		if(temp->kode == kode){
			printf("==============================================\n");
			printf("              Barang Ditemukkan!!!!\n");
			printf("==============================================\n");
			printf("Kode Barang\t\t : %d\n", temp->kode);
			printf("Kategori Barang(s/v)\t : %s\n", temp->kategori);
			printf("Nama Barang\t\t : %s\n", temp->nama_brg);
			printf("Stok Barang\t\t : %d\n", temp->stok);
			printf("Harga Barang\t\t : %d\n", temp->harga);
			printf("==============================================\n");
			printf("      Tekan Apapun Untuk Kembali ke Menu");
			return;
		}
		temp = temp->next;
	}
	printf("Barang Dengan Kode %d Tidak Ditemukan\n", kode);
}

int sortkec(){
	struct part *temp = head;
	struct part *p;
	int kodee;
	int stokk;
	long int hargaa;
	char kategorii[40];
	char nama_brgg[40];
	
	while(temp!=NULL){
		p=temp->next;
		while(p!=NULL){
			if(temp->kode>p->kode){
				kodee=temp->kode;   stokk=temp->stok;   hargaa=temp->harga;   strcpy(temp->kategorii, temp->kategori);   strcpy(temp->nama_brgg, temp->nama_brg);
				temp->kode=p->kode; temp->stok=p->stok; temp->harga=p->harga; strcpy(temp->kategori, p->kategori);       strcpy(temp->nama_brg, p->nama_brg);
				p->kode=kodee;      p->stok=stokk;      p->harga=hargaa;      strcpy(p->kategori, temp->kategorii);      strcpy(p->nama_brg, temp->nama_brgg);
			}p=p->next;
		}temp = temp->next;
	}
	
	temp = head;
	system("cls");
	printf("============================================================================= \n");
	printf("\t\t\tSORTIR BARANG GUDANG UHUYYY");
	time_t t;
   	time(&t);
	printf("\n\t\t\t %s", ctime(&t));
	printf("============================================================================= \n");
	printf("Kode Barang\tSpare/Var\tNama Barang\tStok Barang\tHarga Barang\n");
	printf("============================================================================= \n");
	if (temp!=NULL){	
		while (temp!=NULL){
			printf("%d\t\t", temp->kode);
			printf("%s\t\t", temp->kategori);
			printf("%s\t\t", temp->nama_brg);
			printf("%d\t\t", temp->stok);
			printf("%li\n", temp->harga);
			temp = temp->next;
		}
	}else{
		printf("\n\t\t\t    DATA KOSONG!!!!!");
	}
	getchar();	
}

int sortbes(){
	struct part *temp = head;
	struct part *p;
	int kodee;
	int stokk;
	long int hargaa;
	char kategorii[40];
	char nama_brgg[40];
	
	while(temp!=NULL){
		p=temp->next;
		while(p!=NULL){
			if(temp->kode<p->kode){
				kodee=temp->kode;   stokk=temp->stok;   hargaa=temp->harga;   strcpy(temp->kategorii, temp->kategori);   strcpy(temp->nama_brgg, temp->nama_brg);
				temp->kode=p->kode; temp->stok=p->stok; temp->harga=p->harga; strcpy(temp->kategori, p->kategori);       strcpy(temp->nama_brg, p->nama_brg);
				p->kode=kodee;      p->stok=stokk;      p->harga=hargaa;      strcpy(p->kategori, temp->kategorii);      strcpy(p->nama_brg, temp->nama_brgg);
			}p=p->next;
		}temp = temp->next;
	}
	
	temp = head;
	system("cls");
	printf("============================================================================= \n");
	printf("\t\t\tSORTIR BARANG GUDANG UHUYYY");
	time_t t;
   	time(&t);
	printf("\n\t\t\t %s", ctime(&t));
	printf("============================================================================= \n");
	printf("Kode Barang\tSpare/Var\tNama Barang\tStok Barang\tHarga Barang\n");
	printf("============================================================================= \n");
	
	if (temp!=NULL){
		while (temp!=NULL){
			printf("%d\t\t", temp->kode);
			printf("%s\t\t", temp->kategori);
			printf("%s\t\t", temp->nama_brg);
			printf("%d\t\t", temp->stok);
			printf("%li\n", temp->harga);
			temp = temp->next;
		}
	}else{
		printf("\n\t\t\t    DATA KOSONG!!!!!");
	}
	getchar();	

}



int masuk(){
	printf("==============================================\n");
	printf("\t SELAMAT DATANG DI MENU LOGIN\n");
	printf("==============================================\n");
	int tes = 0;
	char nama[50];
	char sandi[50];

	FILE *data = fopen("akun.txt", "rb");
	fflush(stdin);
	printf("Masukkan Nama Pengguna\t: ");
	scanf("%s", &nama);
	printf("Masukkan Kata Sandi\t: ");
	scanf("%s", &sandi);
		
	while(fscanf(data,"%s %s\n\n", &cek.nama, cek.sandi) !=EOF){
		if(strcmp(nama,cek.nama)==0){
			if(strcmp(sandi, cek.sandi)==0){
				tes=1;
				animasijadi();
				break;
			}
		}
	}if(!tes){
		if(batas<3){
			printf("==============================================\n");
			printf("          Akun Tidak Terdaftar!!!\n"
			       "         Silahkan Ulangi Kembali!!\n"
				   "         (Kesempatan %d Kali Lagi)\n", 3-batas);
			printf("==============================================\n");
			batas++;
		}else if(batas>2){
			salah();
		}
		getch();
		system("cls");
		masuk();
	}fclose(data);
	
	return 0;
}

int salah(){
	int pilihan;
	system("cls");
	printf("==============================================\n");
	printf("     BATAS PERCOBAAN MASUK TELAH DICAPAI\n");
	printf("==============================================\n");
	printf("Apakah Anda Ingin Membuat Akun Baru?\n");
	printf("1. Iya\n");
	printf("2. Tidak, Saya Ingin Keluar\n");
	printf("Pilihan : ");
	scanf("%d", &pilihan);
			
	if(pilihan==1){
		system("cls");
		daftar();
	}else if(pilihan==2){
		keluar();
		getchar();
		exit(0);
	}else{
		printf("=============================================\n");
		printf("           Inputan Anda Salah!\n"
			   "     Tekan Apapun Untuk Mengulang Pilihan\n");
		printf("=============================================\n");
		getch();
		salah();
	}
}

int daftar(){
	int a;
	for (a=0; a<46; a++){
		printf ("=");
	}
	printf("\n         SELAMAT DATANG DI MENU DAFTAR\n");
	for (a=0; a<46; a++){
		printf ("=");
	}

	char nama[50],sandi[50];	
	FILE *data = fopen("akun.txt", "a");
	
	fflush(stdin);
	printf("\nDaftarkan Nama Pengguna\t: ");
	scanf("%s", &nama); 
	printf("Daftarkan Kata Sandi\t: ");
	scanf("%s", &sandi); 

	fprintf(data,"%s %s\n\n",nama,sandi);	
	fclose(data);
	
	for (a=0; a<46; a++){
		printf ("=");
	}
	printf("\n           Pendaftaran Berhasil!\n"
	       "   Tekan Apapun Untuk Masuk ke Halaman Login!\n");
	for (a=0; a<46; a++){
		printf ("=");
	}
	getch();
	system("cls");
	masuk(batas=0);
	
	return 0;
}

int awalan(){
	int a;
	for (a=0; a<46; a++){
		printf ("=");
	}
	printf("\n\t   Albertus Bima Krisnawan \n\t\t  672020095\n");
	for (a=0; a<46; a++){
		printf ("=");
	}
	printf ("\n");
	return 0;
}

int menu(){	
	struct part *temp = head;
	struct part *head = NULL;
	struct part *tail = NULL;
	struct part *prev_node = NULL;
	char kategori[40];
	char nama_brg[40];
	int kode;
	int stok;
	int harga;
	
	
	system("cls");
	printf("======================================\n");
	printf("   SELAMAT DATANG DI GUDANG UHUYYY");
	time_t t;
    time(&t);
	printf("\n       %s", ctime(&t));
	printf("======================================\n");
	
	int pil;
	printf("Silahkan Pilih Menu: \n"
	"1. Tampilkan Barang\n"
	"2. Tambahkan Barang\n"
	"3. Edit Barang\n"
	"4. Cari Barang\n"
	"5. Hapus Barang\n"
	"6. Sortir Barang Dari Kecil ke Besar\n"
	"7. Sortir Barang Dari Besar ke Kecil\n"
	"8. Keluar\n"
	"Pilihan: ");
	scanf("%d",&pil);
	
	
	//ubah pakek switch case aja
	if(pil==1){
		system("cls");
		printf("============================================================================= \n");
		printf("\t\t\tDATA BARANG GUDANG UHUYYY");
		time_t t;
   	 	time(&t);
		printf("\n\t\t\t %s", ctime(&t));
		printf("============================================================================= \n");
		lihat(head);
		getch();
		system("cls");
		menu();
	}else if(pil==2){
		tambahin();
	}else if(pil==3){
		system("cls");
		printf("==============================================\n");
		printf("\tMENU EDIT BARANG GUDANG UHUYYY");
		time_t t;
		time(&t);
		printf("\n\t    %s", ctime(&t));
		printf("==============================================\n");
		printf("Masukkan Kode Barang Yang Ingin Diedit : ");
		scanf("%d", &kode);
		edit(kode);
		getch();
		system("cls");
		menu();
	}else if(pil==4){
		system("cls");
		printf("==============================================\n");
		printf("\tMENU CARI BARANG GUDANG UHUYYY");
		time_t t;
		time(&t);
		printf("\n\t    %s", ctime(&t));
		printf("==============================================\n");
		printf("Masukkan Kode Barang Yang Ingin Dicari : ");
		scanf("%d", &kode);
		cari(kode);
		getch();
		system("cls");
		menu();
	}else if(pil==5){
		system("cls");
		printf("==============================================\n");
		printf("\tMENU HAPUS BARANG GUDANG UHUYYY");
		time_t t;
		time(&t);
		printf("\n\t    %s", ctime(&t));
		printf("==============================================\n");
		printf("Masukkan Kode Barang Yang Ingin Dihapus : ");
		scanf("%d", &kode);
		printf("==============================================\n");
		hapus(kode);
		getch();
		system("cls");
		menu();
	}else if(pil==6){
		sortkec();
		getchar();
		menu();
	}else if(pil==7){
		sortbes();
		getchar();
		menu();
	}else if(pil==8){
		keluar();
	}else{
		printf("======================================\n");
		printf("         Inputan Anda Salah\n"
			   " Tekan Apapun Untuk Mengulang Program\n");
		printf("======================================\n");
		getch();
		system("cls");
		menu();
	}
	
	return 0;
}

int tambahin(){
	struct part *temp = head;
	struct part *head = NULL;
	struct part *tail = NULL;
	struct part *prev_node = NULL;
	char kategori[40];
	char nama_brg[40];
	int kode;
	int stok;
	int harga;
		int tambah;
		system("cls");
			printf("==============================================\n");
			printf("\tMENU TAMBAH BARANG GUDANG UHUYYY");
			time_t t;
		    time(&t);
			printf("\n\t    %s", ctime(&t));
			printf("==============================================\n");
			printf("Pilih Letak Data Barang Yang Ingin Ditambahkan:"
			"\n1. Letakkan Di Akhir Data" 
			"\n2. Sisipkan Data Barang Dari Data Yang Ada"
			"\nInput pilihan\t\t     : ");
			scanf("%d", &tambah);
			if(tambah<1 || tambah>2){
				printf("==============================================\n");
				printf("        Inputan Yang Dimasukkan Salah!!\n"
					   "       Tekan Apapun Untuk Kembali Memilih\n");
				printf("==============================================\n");
				getch();
				tambahin();
			}else{
				if(temp==NULL && tambah==2){
					printf("==============================================\n");
					printf("              DATA MASIH KOSONG\n"
						   "        TIDAK DAPAT MENAMBAHKAN DATA!\n");
					printf("==============================================\n");
					getch();
					tambahin();
				}
			printf("Masukkan Kode Barang\t     : ");
			scanf("%lli", &kode);
			
			while(temp!=NULL){
			if(temp->kode == kode){
				printf("==============================================\n");
				printf("         Kode Barang Telah Dipakai!!!!\n");
				printf("==============================================\n");
				getch();
				tambahin();
			}
		temp = temp->next;
	}
			
			while ((getchar()) != '\n');
			printf("SparePart(s)/Variasi(v)\t     : ");
			scanf(" %[^\n]s", kategori);
			while ((getchar()) != '\n');
			printf("Masukkan Nama Barang\t     : ");
			scanf(" %[^\n]s", nama_brg);
			while ((getchar()) != '\n');
			printf("Masukkan Stok Barang\t     : ");
			scanf("%d", &stok);
			while ((getchar()) != '\n');
			printf("Masukkan Harga Barang\t     : ");
			scanf("%li", &harga);
			while ((getchar()) != '\n');
			if(tambah==1){
				tambahakhir(kode, kategori, nama_brg, stok, harga);
				printf("==============================================\n");
				printf("           Data Berhasil Ditambahkan!\n"
				       "           Tekan Apapun Untuk Kembali\n");
				printf("==============================================\n");
			}else if(tambah==2){
				tambahtengah(kode, kategori, nama_brg, stok, harga);
				printf("==============================================\n");
				printf("           Data Berhasil Ditambahkan!\n"
				       "           Tekan Apapun Untuk Kembali\n");
				printf("==============================================\n");
			}
			getch();
			system("cls");
			menu();
			}
}

int keluar(){
	system("cls");
	printf("==============================================\n");
	printf(" TERIMA KASIH TELAH MENGUNJUNGI GUDANG UHUYYY\n");
	printf("==============================================\n");
	getch();
	exit(0);
	return 0;
}

void main(){

	awalan();
	int pilih;
	
	printf("Apakah Anda Sudah Mempunyai Akun di Toko Kami?\n");
	printf("            Tekan 1 Sudah Punya\n"
		   "            Tekan 2 Belum Punya\n"
		   "            Tekan 3 Untuk Keluar\n");
	printf("                Pilihan : ");
	scanf("%d", &pilih);
	
	if(pilih==1){
		system("cls");
		masuk();
	}else if(pilih==2){
		system("cls");
		daftar();
	}else if(pilih==3){
		keluar();
		getchar();
	}else{
		int a;
		for (a=0; a<46; a++){
		printf ("=");}
		printf("\n           Inputan anda salah\n"
			   " Tekan Tombol Apapun Untuk Mengulang Program\n");
		for (a=0; a<46; a++){
		printf ("=");}
		getch();
		system("cls");
		main();	
	}
}

//ANIMASI

// kecepatan animasi
void tunggu( unsigned int a){
    unsigned int b;
    unsigned int c;

    for(b = 500; b < a ; b++ ){
        for(c = 500; c < b ; c++ ){}
    }
}
// karakter animasi
const char animasi[] =
    " __    __      __      ___\n\
| |   | |     /  \\     | |  \n\
| |   | |    / /\\ \\    | | \n\
| |===| |   / /__\\ \\   | |  \n\
| |   | |  / ______ \\  | |  \n\
|_|   |_| /_/      \\_\\ |_|    \n\
";
int animasijadi(){

    int spasiatas;
    const int sometunggu = 7000;
    int spasibawah;

    //spasiatas= animasi bisa mulai dari bawah
    for (spasiatas = 0; spasiatas < 50; spasiatas++){
        printf("\n");
    }

	//fputs = 
	//stdout = 
    fputs(animasi,stdout);

    for (spasibawah = 0; spasibawah < 50; spasibawah++)
    {
        // agar nyambung ke kecepatan animasi
        tunggu(sometunggu);
        
        // agar animasi naik
        printf("\n");
    }
    system("cls");
    menu();
    return 0;
}

