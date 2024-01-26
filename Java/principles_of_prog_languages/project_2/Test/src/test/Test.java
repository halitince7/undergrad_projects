/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import paket.RastgeleKisi;

/**
 *
 * @author Halit İnce   ince@sakarya.edu.tr
 * @since 3.04.2018
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int secim = 0;
        
        while(secim != 3){
            System.out.println("1-  Rastgele Kişi Üret");
            System.out.println("2-  Üretilmiş Dosya Kontrol");
            System.out.println("3-  Çıkış");
            secim = in.nextInt();
            if(secim == 1){
                BufferedWriter writer = new BufferedWriter(new FileWriter("Kisiler.txt",true));
                System.out.println("Kaç kişi üretmek istiyorsunuz?");
                int sayi = in.nextInt();
                for(int i = 0; i<sayi; i++){
                    RastgeleKisi rs = new RastgeleKisi();
                    writer.append(rs.kisi.tcNo.tcNo +" "+rs.kisi.adSoyad +" "+rs.kisi.yas+" "+rs.kisi.tel.telNo+" "+"("+rs.kisi.tel.imeiNo.imei+")"+"\n" );
                }
                writer.close();
            }
            else if(secim == 2){
                BufferedReader reader = new BufferedReader(new FileReader("Kisiler.txt"));
                int imeiDog = 0;
                int imeiYan = 0;
                int tcDog = 0;
                int tcYan = 0;
                String str;
                while ((str = reader.readLine()) != null) {
                    RastgeleKisi rs = new RastgeleKisi();
                    String [] dizi = str.split(" ");
                    rs.kisi.tcNo.tcNo = Long.valueOf(dizi[0]).longValue();
                    rs.kisi.tel.imeiNo.imei = Long.valueOf(dizi[5].substring(dizi[5].indexOf("(")+1  , dizi[5].indexOf(")"))).longValue();
                    if(rs.kisi.tcNo.isTrue()) tcDog++; else tcYan++;
                    if(rs.kisi.tel.imeiNo.isTrue() ) imeiDog++; else imeiYan++;
		}
                System.out.println("T.C. Kimlik Kontrol");
                System.out.println(tcDog +"    Geçerli");
                System.out.println(tcYan +"    Geçersiz");
                System.out.println();
                System.out.println("IMEI Kontrol");
                System.out.println(imeiDog +"    Geçerli");
                System.out.println(imeiYan +"    Geçersiz");
                System.out.println();
                reader.close();
                        
            }
            else if(secim == 3){
                break;
            }
            else{
                secim = 0;
            }
        }
    }
    
}
