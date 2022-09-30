/**
 * @author      : Shekhar Suman (shekhar0050m@gmail.com)
 * @file        : apartmentHunting
 * @created     : Thursday Sep 29, 2022 17:14:23 IST
 */

import java.util.ArrayList;
import java.util.Arrays;

public class apartmentHunting {
    public static void main(String[] args) {
        ArrayList<ArrayList<String>> arr = new ArrayList<>();
        arr.add(new ArrayList<>(Arrays.asList("Sc")));
        arr.add(new ArrayList<>(Arrays.asList("G")));
        arr.add(new ArrayList<>(Arrays.asList("G", "Sc")));
        arr.add(new ArrayList<>(Arrays.asList("Sc")));
        arr.add(new ArrayList<>(Arrays.asList("Sc", "St")));
        moreEfficient(arr);
    }

    private static void moreEfficient(ArrayList<ArrayList<String>> arr) {
        int n=arr.size();
        int[] g = new int[n];
        int[] Sc = new int[n];
        int[] St = new int[n];
        Arrays.fill(g,n);
        Arrays.fill(Sc,n);
        Arrays.fill(St,n);
        for(int i=0;i<n;i++){
            if(blockContainsGym(arr.get(i))){
                g[i]=0;
            }
            if(blockContainsSchool(arr.get(i))){
                Sc[i]=0;
            }
            if(blockContainsStore(arr.get(i))){
                St[i]=0;
            }
        }
        for(int i=1;i<n;i++){
            g[i]=Math.min(g[i],g[i-1]+1);
            Sc[i]=Math.min(Sc[i],Sc[i-1]+1);
            St[i]=Math.min(St[i],St[i-1]+1);
        }
        for(int i=n-2;i>=0;i--){
            g[i]=Math.min(g[i],g[i+1]+1);
            Sc[i]=Math.min(Sc[i],Sc[i+1]+1);
            St[i]=Math.min(St[i],St[i+1]+1);
        }
        ArrayList<ArrayList<Integer>> gScSt = new ArrayList<>();
        for(int i=0;i<n;i++){
            gScSt.add(new ArrayList<>(Arrays.asList(g[i],Sc[i],St[i])));
        }
        System.out.println(gScSt);
    }

    private static void lessEfficient(ArrayList<ArrayList<String>> arr) {
        ArrayList<ArrayList<Integer>> gScSt = new ArrayList<>();
        for (int i = 0; i < arr.size(); i++) {
            int gInt = Integer.MAX_VALUE;
            int ScInt = Integer.MAX_VALUE;
            int StInt = Integer.MAX_VALUE;
            int pos = i;
            while (pos >= 0) {
                if (blockContainsGym(arr.get(pos))) {
                    gInt = Math.min(gInt, i - pos);
                }
                if (blockContainsSchool(arr.get(pos))) {
                    ScInt = Math.min(ScInt, i - pos);
                }
                if (blockContainsStore(arr.get(pos))) {
                    StInt = Math.min(StInt, i - pos);
                }
                pos--;
            }
            pos = i + 1;
            while (pos < arr.size()) {
                if (blockContainsGym(arr.get(pos))) {
                    gInt = Math.min(gInt, pos - i);
                }
                if (blockContainsSchool(arr.get(pos))) {
                    ScInt = Math.min(ScInt, pos - i);
                }
                if (blockContainsStore(arr.get(pos))) {
                    StInt = Math.min(StInt, pos - i);
                }
                pos++;
            }
            gScSt.add(new ArrayList<>(Arrays.asList(gInt, ScInt, StInt)));
        }
        System.out.println();
    }

    private static boolean blockContainsGym(ArrayList<String> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).equals("G")) {
                return true;
            }
        }
        return false;
    }

    private static boolean blockContainsSchool(ArrayList<String> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).equals("Sc")) {
                return true;
            }
        }
        return false;
    }

    private static boolean blockContainsStore(ArrayList<String> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).equals("St")) {
                return true;
            }
        }
        return false;
    }
}

//G - Gym
//Sc - School
//St - Store

