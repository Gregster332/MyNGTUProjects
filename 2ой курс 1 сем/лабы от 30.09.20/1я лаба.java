

package com.company;
import java.lang.*;


public class Main {

    public static void main(String[] args) {

        MyClass person = new MyClass(22, "Ivan");
        person.printInfo();

    }
}

class MyClass{

    String myName;
    int myAge;
    int myHeight = 160;


    MyClass(){
        myName = "Greg";
        myAge = 18;
        myHeight = 180;
    }

    MyClass(int age, String name){
        this.myName = name;
        this.myAge = age;
    }

    MyClass(int age, int height){
        this.myAge = age;
        this.myHeight = height;
    }

    void printInfo(){
        System.out.println("My name is "+myName+". Im "+myAge+" years old. My height is "+myHeight+".");
    }

}
