/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pdp_odev1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author ACER
 */

/**
*
* @author Halit İnce ine@sakarya.edu.tr Emre Kişi ekisi@sakarya.edu.tr
* @since Programın yazıldığı tarih
* <p>
* Açıklama
* </p>
*/
public class Pdp_odev1 {

    /**
     * @param args the command line arguments
     */
   
    
    
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        int altEleman=0;
        int uyeFonk=0;
        String sinifAdi = "yok";  
        String fonkAdi = "yok";
        String param = "yok";
        
        
        BufferedReader br = null;
        String adres = "C:\\Users\\mathatin\\Desktop\\program.java";
        br = new BufferedReader(new FileReader(adres));
        String line;
        while((line = br.readLine()) != null){
             if( line.contains(";")){
                if(line.contains("private") || line.contains("public")){
                    altEleman++;
                }
            }
            if( line.contains("{") && line.contains("(") ){
                uyeFonk++;
            }
       }
        
        int count=0;
        br = new BufferedReader(new FileReader(adres));
        while((line = br.readLine()) != null){
            
            
            if( line.contains("class")){
                sinifAdi = line.substring(line.indexOf("class")+6, line.indexOf("{") );
                System.out.println("Sınıf Adı: " + sinifAdi);
                System.out.println("Alt Elemanlar: " + altEleman);
            }
            
            if( line.contains(";")){
                if(line.contains("private") || line.contains("public")){
                    System.out.println(line.substring(line.indexOf(" "), line.indexOf(";") )); 
                    
                }
            }
            
            
            
            if( line.contains("{") && line.contains("(") ){
                count++;
                if(count == 1){
                    System.out.println("Üye Fonksiyonlar: " + uyeFonk + " adet");
                }
                fonkAdi = line.substring(line.indexOf(" "), line.indexOf("(") );
                //System.out.println("Fonksiyon Adi: " + fonkAdi );
                if(line.contains("(")){
                    param = line.substring(line.indexOf("(")+1, line.indexOf(")") );
                    //System.out.println("Parametre: " + param);
                    
                    String[] fonkEleman = fonkAdi.split(" ");
                    String[] paramEleman = param.split(", ");
                   
                    
                    if(fonkEleman.length == 2){
                        System.out.println(fonkEleman[1]);
                        System.out.println("Dönüş Türü: Yok");
                        if(line.indexOf(")") - line.indexOf("(") == 1 ){
                            System.out.println("Aldığı Parametre: 0 " );
                        }
                        else{
                            System.out.println("Aldığı Parametre: "+ paramEleman.length );
                        }
                        
                        if(line.indexOf(")") - line.indexOf("(") != 1){
                            for(int i=0;i<paramEleman.length;i++){
                                String[] params = paramEleman[i].split(" ");
                                System.out.println( params[1] + "-" + params[0] );
                            }
                        }
                        
                    }
                    else if(fonkEleman.length == 3){
                        System.out.println(fonkEleman[2]);
                        System.out.println("Dönüş Türü: " + fonkEleman[1]);
                        if(line.indexOf(")") - line.indexOf("(") == 1 ){
                            System.out.println("Aldığı Parametre: 0" );
                        }
                        else{
                            System.out.println("Aldığı Parametre: "+ paramEleman.length );
                        }
                        if(line.indexOf(")") - line.indexOf("(") != 1){
                            for(int i=0;i<paramEleman.length;i++){
                                String[] params = paramEleman[i].split(" ");
                                System.out.println( params[1] + "-" + params[0] );
                            }
                        }
                        
                    }
                    
                    
                    System.out.println("----------");
                    
                }
                
                
                
                
            }
            
            
            
        }
       
        
       
      
        
        
       
        
        
        
        
    }
    
}
