package com.company;

public class Main {

    public static void main(String[] args) {

     Dog dog = new Dog();
     Barks[] value = Barks.values();
     for(Barks bark : value){
         System.out.println(bark);
     }

    }
}

class Dog{
    String name;
    String color;
    int age;

    //	Конструкторы
    Dog(String name, String color, int age){
        this.name = name;
        this.color = color;
        this.age = age;
    }

    Dog(String name, String color){
        this(name, color, 0);
    }

    Dog(String name, int age){
        this(name,"browwn", age);
    }

    Dog(int age){
        this("sharik", "white", age);
    }

    Dog(){
        this("marsik", "black", 5);
    }


    void bark(){
        System.out.println("Bark-Bark");
    }

    void bark(String s){
        System.out.println(s);
    }

    void bark(Barks var){
        switch (var){
            case BARK:
                bark();
                break;
            case WAF:
                bark("WAF-Waf wafff");
                break;
            case UUU:
                bark("auuuufuufuf");
                break;
            case UMM:
                bark("Ummmmm....");
                break;
        }
    }
}

enum Barks{
    BARK, WAF, UUU, UMM
}
