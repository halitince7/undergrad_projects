/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package paket;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;

/**
 *
 * @author Halit İnce   ince@sakarya.edu.tr
 * @since 3.04.2018
 */
public class Kisi {
    public KimlikNo tcNo;
    public String adSoyad;
    public int yas;
    public Telefon tel;
    
    public Kisi() throws IOException{
        tcNo = new KimlikNo();
        tel = new Telefon();
        Random rand = new Random();
        yas = rand.nextInt(100);
        int temp = rand.nextInt(1000);
        int sayac = 0;
       
        BufferedReader br = null;
        String adres = "random_isimler.txt";
        br = new BufferedReader(new FileReader(adres));
        String line;
        while((line = br.readLine()) != null){
             if(sayac == temp){
                 adSoyad = line;
                 break;
             }
             sayac++;
       }
        
        
    }
}
