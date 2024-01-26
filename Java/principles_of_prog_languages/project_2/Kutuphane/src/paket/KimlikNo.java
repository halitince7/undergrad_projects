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
public class KimlikNo {
    public long tcNo;
    
    public KimlikNo(){
        Random rand = new Random();
        int [] array = new int[11];
        array[0] = rand.nextInt(9)+1;
        for(int i=1;i<9;i++){
            array[i]= rand.  nextInt(10);
        }
        
        int top1 = (array[0]+array[2]+array[4]+array[6]+array[8])*7;
        int top2 = array[1]+array[3]+array[5]+array[7];
        array[9] = (top1-top2) % 10;
        int top=0;
        for(int i=0;i<10;i++){
            top += array[i];
        }
        array[10] = top % 10;
        
        tcNo=0;
        for(int i=0;i<11;i++){
            tcNo += (long)((long)array[i]*(long)(pow(10,(10-i))));
            //System.out.print(array[i]+" ");
        }
        //System.out.println();
        //System.out.print(tcNo);
    }
    
    public boolean isTrue(){
        long [] array = new long[11];
        long temp = tcNo;
        for(int i=0;i<11;i++){
           array[10-i] = temp % 10;
           temp = (temp - (temp % 10)) / 10;
        }
        
        long top1 = (array[0]+array[2]+array[4]+array[6]+array[8])*7;
        long top2 = array[1]+array[3]+array[5]+array[7];
        long top=0;
        for(int i=0;i<10;i++){
            top += array[i];
        }
        if(array[9] == (top1-top2) % 10  && array[10] == top % 10){
            //System.out.println("dogru");
            return true;
            
        }
        else{
            //System.out.println("yanlis");
            return false;
        }
        
    }
}
