package com.company;

import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
       /* Scanner sc = new Scanner(System.in);
        System.out.println("Введите первое число:");
        int first = sc.nextInt();
        System.out.println("Введите второе число:");
        int second = sc.nextInt();


            try {
                int result = first / second;
                System.out.println(result);

                int result2 = second/first;
                System.out.println(result2);
            } catch (Exception ex) {
                System.out.println("division by zero");
            } */ // 1я прога



        //2я программа
       /* Scanner sc = new Scanner(System.in);
        PrintWriter wr = new PrintWriter("aaa.txt");
        try  {
           int nums[];
           nums = new int[201];

           for (int i = 0; i < 201; i++){
               nums[i] = (int) (Math.random()* 1000);
               wr.print("\n");
               wr.print(i+"-" + (nums[i] + 1));

           }

       } catch (Exception e) {
           System.out.println(e.getMessage());
       }

        wr.close();

        System.out.println("Введите индекс, по которому нужно вывести число: ");
        String ind = sc.next();
        File f = new File("aaa.txt");
        Scanner scc = new Scanner(f);

        while(scc.hasNext()){
            String line = scc.next();

            String[] parts = line.split("-");

            String part1 = parts[0];
            String part2 = parts[1];

            if (part1.equals(ind)){
                System.out.println(part2);
            }


        }*/


       //3я прога

        Scanner sc = new Scanner(System.in);
        PrintWriter wr1 = new PrintWriter("t1.txt");
        PrintWriter wr2 = new PrintWriter("t2.txt");
        String wordsForFirst = "Hello ";
        String wordsForSecond = "world!";

        try{

                wr1.print(wordsForFirst);
                wr2.print(wordsForSecond);


        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }

       wr1.close();
        wr2.close();

        reverseString(wordsForFirst);
        reverseString(wordsForSecond);


//        //File file1 = new File("t1.txt");
//        Scanner sc1 = new Scanner(file1);
//        File file2 = new File("t2.txt");
//        Scanner sc2 = new Scanner(file2);


        System.out.println("Меняем файлы местами? 1-да, 2-нет");
        int choice = sc.nextInt();

        PrintWriter pw1 = new PrintWriter("t1.txt");
        PrintWriter pw2 = new PrintWriter("t2.txt");



        switch (choice){
            case 1:

                pw1.print(reverseString(wordsForSecond));
                pw2.print(reverseString(wordsForFirst));
                pw1.close();
                pw2.close();

            case 2:
               return;
        }

    }

    public static String reverseString(String str) {
        return new StringBuilder(str).reverse().toString();
    }
}