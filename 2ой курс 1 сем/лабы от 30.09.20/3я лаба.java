package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Money m1 = new Money(MoneyTypes.RUB, "Россия");
        System.out.println("Валютой из "+m1.country+" является " + m1.type);

        switch(m1.type){
            case RUB:
                System.out.println("Рубль");
            case EUR:
                System.out.println("Евро");
            case USD:
                System.out.println("Доллар");
            case GRN:
                System.out.println("Гривна");
            case PND:
                System.out.println("Фунт");
            case SEK:
                System.out.println("Крона");

        }

    }
}

class Money{


    String country;
    MoneyTypes type;

    Money(MoneyTypes type, String country){

        this.type = type;
        this.country = country;

    }
}


enum MoneyTypes {
    RUB, USD, EUR, PND, GRN, SEK

}


