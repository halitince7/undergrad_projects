/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pdp_odev1;

/**
 *
 * @author ACER
 */
class Sınıf {
    public String isim;
    public Degisken[] degiskenler = new Degisken[20];
    public Fonksiyon[] fonksiyonlar = new Fonksiyon[20];
    
    public Sınıf() {
        for (int i=0; i < 20; i++ ){
            degiskenler[i] = new Degisken();
            fonksiyonlar[i] = new Fonksiyon();
        }
    
    }
}
