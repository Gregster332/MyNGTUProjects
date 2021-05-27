package com.company;

import java.util.*;

public class Main {
    public static final int SIZE=10;
    public static Stack <Integer> stack= new Stack<>();
    public static Scanner sc = new Scanner(System.in);



    public static void main(String[] args) {
	int num = sc.nextInt();
	stack.add(num);
	OurThread ourThread = new OurThread();
	ourThread.start();
    while (!stack.isEmpty() && stack.size() < SIZE){
        num=sc.nextInt();
        try{
            if(num==stack.peek()+1) {
                stack.push(num);
            }
            else {
                System.out.println("Ошибка!");
            }
        }catch (EmptyStackException e){
            System.out.println(e.getLocalizedMessage());
        }

        System.out.println("\n"+stack+"\n");
    }
    }

    public static class OurThread extends Thread{
        @Override
        public void run(){

            while (!stack.isEmpty() && stack.size() < SIZE){

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if(stack.size() >= SIZE-1){
                    break;
                }
                stack.pop();
                System.out.println("\n"+stack+"\n");

            }
            System.out.println("Игра окончена");
            System.exit(0);
        }
    }

}
