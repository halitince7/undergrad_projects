/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package paket;

import static java.lang.Math.pow;
import java.util.Random;

/**
 *
 * @author Halit İnce   ince@sakarya.edu.tr
 * @since 3.04.2018
 */
public class IMEINo {
    public long imei;
    
    public IMEINo(){
        Random rand = new Random();
        int [] array = new int[15];
        for(int i=0;i<14;i++){
            array[i]= rand.nextInt(10);
        }
        int top = 0;
        int temp;
        for(int i=0; i<14; i++){
            if(i % 2 == 0){
                top += array[i];
            }
            else{
                temp = (array[i]*2) % 10;
                if(array[i]*2 >= 10){
                    temp += 1;
                }
                top += temp;
            }
        }
        
        if(top % 10 != 0) array[14] = 10 - (top % 10);
        
        imei=0;
        for(int i=0;i<15;i++){
            imei += (long)((long)array[i]*(long)(pow(10,(14-i))));
            //System.out.print(array[i]+" ");
        }
        
    }
    
    public boolean isTrue(){
        long [] array = new long[15];
        long temp = imei;
        int den=0;
        for(int i=0;i<15;i++){
           array[14-i] = temp % 10;
           temp = (temp - (temp % 10)) / 10;
        }
        int top = 0;
        for(int i=0; i<14; i++){
            if(i % 2 == 0){
                top += array[i];
            }
            else{
                temp = (array[i]*2) % 10;
                if(array[i]*2 >= 10){
                    temp += 1;
                }
                top += temp;
            }
        }
        if(top % 10 != 0) {
            den = 10 - (top % 10);
        }
            
        return array[14] == den;
    }
}
