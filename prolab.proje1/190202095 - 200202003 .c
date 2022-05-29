#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ogrenci ogrenci;
struct ogrenci
{
    int ogrno;
    int *ogradres;
    int derskodu;
    int puan;
};

void kayitekle()
{

    ogrenci *o;
    FILE *fp;
    int i,n,j;
    int adres;

    printf("\t*************************");
    printf("\n\tKac ogrenci eklemek istiyorsunuz? : ");
    scanf("%d",&n);

    o = (ogrenci*)calloc(n,sizeof(ogrenci));
    fp = fopen("ogrencilerim.dat","a+b");

    for(i=0; i<n; i++)
    {

        printf("\t %d. Ogrencinin numarasini giriniz : ",i+1);
        scanf("%d",&o[i].ogrno);

        adres = &o[i].ogrno;
        o[i].ogradres = adres;

        printf("\t%d. Ogrencinin ders kodunu giriniz : ",i+1);
        scanf("%d",&o[i].derskodu);

        printf("\t%d. Ogrencinin %d kodlu dersinin puanini giriniz : ",i+1,o[i].derskodu);
        scanf("%d",&o[i].puan);

        fwrite(&o[i],sizeof(ogrenci),1,fp);


    }
    fclose(fp);
    printf("\t\nKayit ekleme islemi gerceklestirildi.\n\n");
}

void kayitbul()
{
    system("cls");
    ogrenci o;
    int bulno;
    printf("Aranacak Numarayi girin:");
    scanf("%d",&bulno);
    FILE *dosya;
    dosya=fopen("index.txt","r");
    rewind(dosya);
    fflush(stdin);
    while(!feof(dosya))
    {
        fscanf(dosya,"%d%d%d%d",&o.ogrno,&o.derskodu,&o.puan,&o.ogradres);
        fflush(stdin);
        if(bulno==o.ogrno)
        {
            printf("%d\t%d\t%d\t%d\n",o.ogrno,o.derskodu,o.puan,o.ogradres);
        }
    }
    fclose(dosya);
}
void kayitsil()
{
    system("cls");
}
void kayitguncelle()
{
    system("cls");
    ogrenci o;
    int guncelno;
    int yenipuan,ders_kodu;
    printf("Guncellenecek numarayi girin:");
    scanf("%d",&guncelno);
    printf("Guncellenecek ders kodunu girin:");
    scanf("%d",&ders_kodu);
    FILE *dosya,*verid;
    dosya=fopen("index.txt","r");
    verid=fopen("ogrencilerim.dat","a+b");
    int a=0,i=0;
    rewind(dosya);
    while(!feof(dosya))
    {
        fscanf(dosya,"%d%d%d%d",&o.ogrno,&o.derskodu,&o.puan,&o.ogradres);
        a++;
    }
    for(i=0; i<(a-1); i++)
    {
        if(guncelno==o.ogrno&& ders_kodu==o.derskodu)
        {
            printf("puani giriniz");
            scanf("%d",&yenipuan);
            fflush(stdin);
            o.puan=yenipuan;
            fseek(verid,sizeof(o),SEEK_CUR);
            fwrite(&o,sizeof(o),1,verid);

        }
    }
    fclose(dosya);
    fclose(verid);

}

void veridosyasinigoster()
{

    ogrenci o;
    FILE *file;
    file = fopen("ogrencilerim.dat","rb+");

    printf("\n%s\t\t%s\t%s\t%s\t","Numara","Ders Kodu","Puan","Adres");

    fread(&o,sizeof(ogrenci),1,file);

    while( !feof(file))
    {
        printf("\n%d\t\t%d\t\t%d\t%d\t",o.ogrno,o.derskodu,o.puan,o.ogradres);
        fread(&o,sizeof(ogrenci),1,file);
    }
    fclose(file);



}
void indeksdosyasiniolustur()
{
    system("cls");
    ogrenci o;
    FILE *file,*indf;
    file = fopen("ogrencilerim.dat","rb");
    indf=fopen("index.txt","w+");
    while( fread(&o,sizeof(ogrenci),1,file)==1)
    {
        fprintf(indf,"\n%d\t\t%d\t\t%d\t%d\t",o.ogrno,o.derskodu,o.puan,o.ogradres);

    }
    fclose(file);
    fclose(indf);

}
void indeksdosyasinigoster()
{
    system("cls");
    ogrenci o;
    FILE *indf;
    indf = fopen("index.txt","r");
    if(indf==NULL)
    {
        printf("dosya bulunamadi");
        exit(1);

    }
    int i =0;
    while( !feof(indf))
    {
        fscanf(indf,"%d%d%d%d",&o.ogrno,&o.derskodu,&o.puan,&o.ogradres);
        printf("\n%d\t\t%d\t\t%d\t%d\t",o.ogrno,o.derskodu,o.puan,o.ogradres);
        i++;

    }
    fclose(indf);


}
void indeksdosyasinisil()
{
    system("cls");
    int silat = remove("index.txt");

  if(silat == 0){
    fprintf(stdout, "Dosya silindi");
  } else {
    fprintf(stderr, "Dosya silinemedi");
    return -1;
  }

}



int main()
{
    int menuno;
    do
    {
        printf("\n\t\t****************   MENU   ****************\n");
        printf("\t\t1.Kayit Ekle\n");
        printf("\t\t2.Kayit Bul\n");
        printf("\t\t3.Kayit Sil\n");
        printf("\t\t4.Kayit Guncelle\n");
        printf("\t\t5.Veri Dosyasini Goster\n");
        printf("\t\t6.Indeks Dosyasini Olustur\n");
        printf("\t\t7.Indeks Dosyasini Goster\n");
        printf("\t\t8.Indeks Dosyasini Sil\n");
        printf("\t\tCikis icin 0'a basiniz.\n\n");
        printf("\t\tGerceklestirmek isteginiz islem:");
        scanf("%d",&menuno);

        switch(menuno)
        {
        case 1:
            kayitekle();
            break;
        case 2:
            kayitbul();
            break;
        case 3:
            kayitsil();
            break;
        case 4:
            kayitguncelle();
            break;
        case 5:
            veridosyasinigoster();
            break;
        case 6:
            indeksdosyasiniolustur();
            break;
        case 7:
            indeksdosyasinigoster();
            break;
        case 8:
            indeksdosyasinisil();
            break;
        }
    }
    while(menuno!=0);

    return 0;
}
