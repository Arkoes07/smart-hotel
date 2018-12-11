#include<stdio.h>

void judul_dan_penjelasan();
void petunjuk();
void continue_button();
void check_in();
void tampil_jenis_kamar();
void kamar_terpilih(int a, int b);
void tampilan_setelah_check_in();
void menu();
void menu_pilihan_mt();
void pilihan_mt_terpilih(int a, int b);
int hitung_biaya(int a);
int hitung_biaya_tambahan(int a);
void check_out(int a, int b);

int hitung_kamar[3]={0}, harga_kamar[3]={350000,400000,450000};
int hitung_pesanan_tambahan[3]={0}, harga_pesanan_tambahan[3]={40000,90000,50000};

int main(){
	int pilih, hitung, pilih_mt, banyak, jenis_kamar;
	int banyak_kamar, durasi;
	
	// TAMPILAN AWAL
	do{ 
    	judul_dan_penjelasan();
    	printf("\n1. PETUNJUK\n");
    	printf("2. LANJUT KE CHECK IN\n"); 
    	printf("Silahkan isi nomor yang anda pilih : ");
    	scanf("%d",&pilih);
    	if(pilih == 1){
            system("cls");
            petunjuk();
        }else if(pilih < 1 || pilih > 2){
            printf("\nMaaf. Anda harus memilih antara 1 dan 2. silahkan ulangi lagi.\n");
            continue_button();
        }
    	system("cls");
    }while(pilih != 2);
     
    //PROSES CHECK-IN
    do{
    	hitung_kamar[0] = 0;
    	hitung_kamar[1] = 0;
    	hitung_kamar[2] = 0;
		//MEMILIH BANYAK KAMAR                                                    
    	do{
        	check_in();
        	printf("\n>>> Isi berapa banyak kamar yang anda inginkan (isi '0' untuk melihat petunjuk) : ");
        	scanf("%d",&banyak_kamar);
        	if(banyak_kamar < 0){
            	printf("Maaf. Banyak kamar yang anda pilih harus minimal 1. Silahkan isi lagi.\n");
                continue_button();
            }else if(banyak_kamar == 0){
                system("cls");
                petunjuk();
            }
        }while(banyak_kamar < 1);
        
        //MEMILIH LAMA MENGINAP
    	do{
        	check_in();
        	printf("\n ~~~~~~~~ Anda telah memilih %d banyak kamar ~~~~~~~~\n",banyak_kamar);
        	printf("\n>>> Isi berapa malam anda menginap (isi '0' untuk melihat petunjuk) : ");
        	scanf("%d",&durasi);
        	if(durasi < 0){
                printf("\nMaaf. Anda harus menginap minimal 1 malam. Silahkan isi lagi.\n");
                continue_button();
            }else if(durasi == 0){
                system("cls");
                petunjuk();
            }
        }while(durasi < 1);
    	
    	//MEMILIH JENIS KAMAR
    	system("cls");
    	check_in();
    	printf("\n~~~~~~~~ Anda telah memilih %d banyak kamar untuk %d malam ~~~~~~~~\n",banyak_kamar,durasi); 
    	tampil_jenis_kamar();
    	for(hitung=1; hitung<= banyak_kamar; hitung++){
            do{
    	        printf("\n>>> Untuk kamar ke-%d. Masukkan angka jenis kamar yang anda inginkan: ",hitung);
                scanf("%d",&jenis_kamar);
                if(jenis_kamar<1 || jenis_kamar>3){
                    printf("\nMaaf. Anda hanya bisa memilih satu antara 1 - 3. Silahkan isi lagi.\n");
                }
				hitung_kamar[jenis_kamar - 1]++;
            }while(jenis_kamar<1 || jenis_kamar>3);
        kamar_terpilih(hitung,jenis_kamar);
        }
    	
    	//KONFIRMASI CHECK-IN           
    	printf("\nKONFIRMASI!\n1. LANJUT KE MAIN MENU\n2. ULANGI CHECK-IN\n"); 
    	do{
        	printf("Silahkan isi nomor yang anda pilih : ");
        	scanf("%d",&pilih);
        	if(pilih < 1 || pilih > 2){
                printf("\nMaaf. Anda harus memilih antara 1 dan 2. silahkan ulangi lagi.\n");
            }
        }while(pilih < 1 || pilih > 2);
    	
		system("cls");
	}while(pilih == 2);
	
	tampilan_setelah_check_in();
	
	//MAIN MENU
	do{
		menu();
    	printf("\n>>> Masukkan angka pilihan yang anda inginkan : ");
    	scanf("%d",&pilih);
    	switch(pilih){
    		case 1:		//PESANAN TAMBAHAN
    			do{
    				system("cls");
                    menu_pilihan_mt();
                    printf("\n>>> Masukkan angka pilihan yang anda inginkan : ");
                    scanf("\n%d",&pilih_mt);
                    banyak = 0;
                    switch(pilih_mt){
                    	case 1:		//MAKAN
                    		do{
                    			printf("\n>>> Masukkan banyak porsi makanan yang anda pesan (isi '0' jika tidak jadi) : ");
                                scanf("%d",&banyak);
                                if(banyak < 0){
                                	printf("\nMaaf. Anda harus memesan minimal 1 porsi. Silahkan isi lagi.\n");
                                }
							}while(banyak < 0);
							if(banyak == 0){
                                system("cls");
                                break;
                            }
                            pilihan_mt_terpilih(pilih_mt,banyak);
							hitung_pesanan_tambahan[0]+=banyak;
							continue_button();   
                    		break;
                    	case 2:		//EXTRABED
                    		pilihan_mt_terpilih(pilih_mt,banyak);
                    		hitung_pesanan_tambahan[1]++;
                    		continue_button();
                    		break;
                    	case 3:		//FITNESS
                    		do{
                    			printf("\n>>> Masukkan banyak orang yang akan menggunakan (isi '0' jika tidak jadi) : ");
                                scanf("%d",&banyak);
                                if(banyak < 0){
                                    printf("\nMaaf. Banyak perenang harus minimal 1 orang. Silahkan isi lagi.\n");
                                }				   
							}while(banyak < 0);
							if(banyak == 0){
                                system("cls");
                                break;
                            }
                            pilihan_mt_terpilih(pilih_mt,banyak);
                            hitung_pesanan_tambahan[2]+=banyak;
							continue_button();  
                    		break;
                    	case 4:	
							petunjuk();	
                    		break;
                    	case 5:
                    		system("cls");
                    		break;
                    	default:
                    		printf("\nMaaf. Anda hanya dapat memilih pesanan tambahan antara 1 - 3. atau pilih 4 untuk melihat petunjuk. silahkan coba lagi.\n");
                    		continue_button();
					}
				}while(pilih_mt > 5);
    			break;
    		case 2:		//CHECK-OUT
    			
				check_out(banyak_kamar, durasi);
				
    			break;
    		case 3:		//PETUNJUK
    			system("cls");
            	petunjuk();
    			break;
    		default:
				printf("\nMaaf. Anda hanya dapat memilih nomor pilihan antara 1 dan 2. Atau pilih 3 untuk melihat petunjuk. Silahkan coba lagi.\n");
                continue_button(); 
		}
	}while(pilih!=2);
	
	getch();
	return 0;
}

void judul_dan_penjelasan(){
    printf("\t\t\t\t___________________________________________________\n");
    printf("\t\t\t\t|SELAMAT DATANG DI SISTEM (SMART-HOTEL) HOTEL LKJHG|\n");
    printf("\t\t\t\t|                     *****                        |\n");
    printf("\t\t\t\t|__________________________________________________|\n");
    printf("\t\t===================================================================================\n");
    printf("\n>>> Program untuk melakukan check-in, mendapat akses fasilitas, dan melakukan check-out hotel.\n");   
    printf("    Pilih petunjuk untuk memlihat langkah - langkah menjalankan program ini.\n");
}

void petunjuk(){
    printf("\nPetunjuk Program :\n1. Melakukan check-in.\n");
    printf("\t1.1 Masukkan berapa kamar yang anda inginkan\n");
    printf("\t>>> Anda harus memilih minimal 1 kamar.\n");
    printf("\t1.2 Masukkan berapa malam anda akan menginap\n");
    printf("\t>>> Anda harus memilih minimal 1 malam.\n");
    printf("\t1.3 Masukkan jenis kamar yang anda inginkan untuk tiap kamar.\n");
    printf("\t>>> Anda dapat memilih pilihan dari 1 - 3 jenis kamar.\n");
    printf("2. Main menu\n");
	printf(">>> Anda dapat memilih menu yang anda inginkan dengan menulis nomor menu. pilih antara 1 - 3.\n");
    printf("\t2.1 Pesanan tambahan\n");
    printf("\t>>> Dapat dipilih jika anda ingin melakukan pesanan tambahan. Akan menampilkan sub-menu.\n"); 
	printf("\t    Anda dapat memilih sub menu yang diinginkkan dengan melulis nomor sub-menu. Pilih antara 1-5.\n");
    printf("\t\t2.1.1 Memesan Makan\n");
    printf("\t\t>>> Anda dapat memesan makanan dengan memilih '1.' pada sub menu\n");
    printf("\t\t\t2.1.1.1. Masukkan berapa jumlah porsi yang akan dipesan.\n"); 
    printf("\t\t\t>>> Anda harus memilih memesan minimal 1.\n");
    printf("\t\t2.1.2 Memesan Extra bed\n");
    printf("\t\t>>> Anda dapat memesan Extra bed dengan memilih '2.' pada sub menu\n");
    printf("\t\t2.1.3 Menggunakan fitnes dan kolam renang\n");
    printf("\t\t>>> Anda dapat Menggunakan fitnes dan kolam renang dengan memilih '3.' pada sub menu\n");
    printf("\t\t\t2.1.3.1. Masukkan berapa jumlah orang yang akan Menggunakan fitnes dan kolam renang.\n"); 
    printf("\t\t\t>>> Anda harus menulis minimal 1 orang.\n");
    printf("\t\t2.1.4 Kembali ke main menu\n");
    printf("\t\t>>> Anda dapat Kembali ke main menu dengan memilih '5.' pada sub menu\n");
    printf("\t2.2 Check-out\n");
    printf("\t>>> Dapat dipilih jika anda ingin melakukan check-out.\n"); 
    printf("\t    Komulasi harga dari semua transaksi anda akan ditampilkan.\n");
    printf("\n!SEMUA INPUT BERUPA ANGKA!.\n");
    continue_button();
}

void continue_button(){
    printf("\nTekan apapun untuk melanjutkan");
    getch();
    system("cls");
}
     
void check_in(){
    system("cls");
    printf("\n\n   SILAHKAN MELAKUKAN CHECK-IN TERLEBIH DAHULU\n");
    printf("  ================================================\n");
}

void tampil_jenis_kamar(){
    printf("\n\nHotel LKJHG menyediakan 3 jenis kamar hotel yaitu:");
    printf("\n\n1. STANDARD ROOM          (350.000/malam)\n");
    printf("   Kamar dengan luas 20m2 yang dilengkapi dengan single bed dan televisi");
    printf("\n\n2. DELUXE ROOM            (400.000/malam)\n");
    printf("   Kamar dengan luas 30m2 yang dilengkapi dengan twin bed atau king bed, televisi, coffee maker, dan kulkas.");
    printf("\n\n3. SUITE ROOM             (450.000/malam)\n");
    printf("   Kamar dengan luas 42m2 yang dilengkapi dengan twin bed atau king bed, televisi, coffee maker, dan kulkas");
    printf("\n   Dilengkapi dengan fasilitas dan furniture kualitas terbaik\n");
}

void kamar_terpilih(int a, int b){  //a = hitung, b = jenis_kamar
    switch(b){
        case 1:
        	printf("\t\t=====================================\n");
        	printf("\t\tKamar ke-%d, kamar standard terpilih!\n",a);
            printf("\t\tkamar anda terletak pada lantai 1\n");
            printf("\t\t=================================\n");
            break;
    	case 2:
            printf("\t\t=====================================\n");
            printf("\t\tKamar ke-%d, kamar deluxe terpilih!\n",a);
            printf("\t\tkamar anda terletak pada lantai 2\n");
            printf("\t\t=================================\n");
            break;
        case 3:
            printf("\t\t=====================================\n");
            printf("\t\tKamar ke-%d, kamar suite terpilih!\n",a);
            printf("\t\tkamar anda terletak pada lantai 3\n");
            printf("\t\t=================================\n");
            break;
	}
}

void tampilan_setelah_check_in(){
    printf("\n\n  ================================================================================================");
    printf("\n     PROSES CHECK-IN TELAH SELESAI");
    printf("\n     SELAMAT BERLIBUR!");
    printf("\n  ================================================================================================\n");
}

void menu(){	
	printf("=========\n");
    printf("MAIN MENU\n");
    printf("=========");
    printf("\n1. PESANAN TAMBAHAN");
    printf("\n2. CHECK-OUT");
    printf("\n3. PETUNJUK\n");
}

void menu_pilihan_mt(){
    printf("\n1. MAKAN                       (40.000/porsi)");
    printf("\n   Nasi goreng khas hotel LKJHG, dengan potongan ayam dan telur mata sapi\n");
    printf("\n2. EXTRA BED                   (90.000)");
    printf("\n   Kasur kurang besar? Tidak perlu khawatir! Hotel LKJHG menyediakan ExtraBed!\n");
    printf("\n3. FITNESS DAN KOLAM RENANG    (50.000/orang)");
    printf("\n   Peralatan fitness lengkap ditambah dengan kolam renang air hangat premium\n");
    printf("\n4. PETUNJUK");
    printf("\n5. KEMBALI\n");
}

void pilihan_mt_terpilih(int a, int b){       // a = pilih_mt, b = banyak
	switch(a){
    	case 1:
        	printf("\n>>> Makanan sebanyak %d porsi akan segera diantar ke kamar anda",b);
            printf("\n    Biaya akan ditambahkan pada saat anda melakukan check out\n");
            break;
        case 2:
            printf("\n>>> Extra bed akan segera diantarkan ke kamar anda");
            printf("\n    Biaya akan ditambahkan pada saat anda melakukan check out\n");
            break;
        case 3:
            printf("\n>>> %d Orang telah ditambahkan sebagai pengguna fasilitas fitness dan kolam renang atas nomor kamar anda",b);
            printf("\n    Biaya akan ditambahkan pada saat anda melakukan check out\n");
            break;
    }
}

int hitung_biaya(int a){ 	// a = hitung
	int b;
	b = hitung_kamar[a] * harga_kamar[a];
	return b;
}

int hitung_biaya_tambahan(int a){	// a = hitung
	int b;
	b = hitung_pesanan_tambahan[a] * harga_pesanan_tambahan[a];
	return b;
}

void check_out(int a, int b){ 	//a = banyak_kamar, b = durasi
	
	int hitung, total_biaya_kamar, total_biaya_tambahan, total_biaya, pilih_out, c = 0;
	int harga_masing_kamar[3]={0},harga_masing_tambahan[3]={0};
	
	//HITUNG BIAYA
	for(hitung=0; hitung<3; hitung++){
		c =	hitung_biaya(hitung);
		harga_masing_kamar[hitung] = c;
	}
	total_biaya_kamar = harga_masing_kamar[0] + harga_masing_kamar[1] +harga_masing_kamar[2];
	c = 0;
	for(hitung=0; hitung<3; hitung++){
		c =	hitung_biaya_tambahan(hitung);
    	harga_masing_tambahan[hitung] = c;
	}
	total_biaya_tambahan = harga_masing_tambahan[0] + harga_masing_tambahan[1] + harga_masing_tambahan[2];
	total_biaya = total_biaya_kamar + total_biaya_tambahan;
	
	system("cls");
	do{ 
        printf("\n>>> Total biaya yang harus anda bayarkan sebesar %d rupiah", total_biaya);
        printf("\n    Silahkan bayar ke resepsionis\n\n");
        printf("1. RINCIAN HARGA\n");
        printf("2. SELESAI\n"); 
        printf("silahkan isi nomor yang anda pilih : ");
        scanf("%d",&pilih_out);
        if(pilih_out == 1){		//TAMPILKAN RINCIAN HARGA
        	system("cls");
            printf("\n\n>>> RINCIAN HARGA :\n");
            printf("1. Kamar sebanyak %d selama %d malam                               \t:\n",a,b);
            printf("   1.1 Kamar standard sebanyak %d (350000 Rupiah/malam)            \t: %d Rupiah\n",hitung_kamar[0], harga_masing_kamar[0]);
            printf("   1.2 Kamar deluxe sebanyak %d (400000 Rupiah/malam)              \t: %d Rupiah\n",hitung_kamar[1], harga_masing_kamar[1]);
            printf("   1.3 Kamar suite sebanyak %d (450000 Rupiah/malam)               \t: %d Rupiah\n",hitung_kamar[2], harga_masing_kamar[2]);
            printf("       Total biaya kamar                                           \t: %d Rupiah\n",total_biaya_kamar);
            printf("2. Akumulasi memesan makan sebanyak %d kali                        \t: %d Rupiah\n",hitung_pesanan_tambahan[0], harga_masing_tambahan[0]);
            printf("3. Akumulasi memesan extra bed sebanyak %d kali                    \t: %d Rupiah\n",hitung_pesanan_tambahan[1], harga_masing_tambahan[1]);
            printf("4. Akumulasi menggunakan fitnes dan kolam renang sebanyak %d orang \t: %d Rupiah\n",hitung_pesanan_tambahan[2], harga_masing_tambahan[2]);
            printf("\n>>> Total biaya                                                  \t: %d Rupiah\n",total_biaya);
           	continue_button();
        }else if(pilih_out < 1 || pilih_out > 2){
            printf("\nAnda harus memilih antara 1 dan 2. silahkan ulangi lagi.\n");
            continue_button();
        }
    }while(pilih_out != 2);
    system("cls");                
    printf("\n  ================================================================================================");
    printf("\n   TERIMAKASIH TELAH MEMILIH HOTEL KAMI!");
    printf("\n   SEMOGA LIBURAN KALI INI BERKESAN");
    printf("\n   SENANG MELAYANI ANDA");
    printf("\n  ================================================================================================");
}

