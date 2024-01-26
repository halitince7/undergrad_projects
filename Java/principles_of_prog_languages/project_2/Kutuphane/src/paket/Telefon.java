/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package paket;

import java.util.Random;

/**
 *
 * @author Halit İnce   ince@sakarya.edu.tr
 * @since 3.04.2018
 */
public class Telefon {
    public String telNo;
    public final IMEINo imeiNo;
    
    public Telefon(){
        telNo = "05";
        imeiNo = new IMEINo();
        Random rand = new Random();
        String [] str = {"30","31","32","33","34","05","06","07","40","41","42",
        "43","44","45","55"};
        int rnd = rand.nextInt(15);
        telNo = telNo.concat(str[rnd]);
        for(int i=4;i<11;i++){
            rnd = rand.nextInt(10);
            telNo = telNo.concat(String.valueOf(rnd));
        }
        
        //System.out.print(telNo);
        
        
    }
}
