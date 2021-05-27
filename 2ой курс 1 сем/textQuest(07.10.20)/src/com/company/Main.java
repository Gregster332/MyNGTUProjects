package com.company;


import javax.rmi.ssl.SslRMIClientSocketFactory;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Приветствую тебя на нашей парковке! В данный момент парковка пустует, но мы можем ее заполнить! Давай сделаем это! Сколько человек оставят тут свои машины? Максимум 15 мест. Укажи чмсло:");
        int sizeOfArray = sc.nextInt();

        if (sizeOfArray > 15){
            System.out.println("Вы ввели число больще 15. На парковке нет столько мест. Мы вместим только 15 машин");
            sizeOfArray = 15;
        }

        ArrayList<User> users = new ArrayList<>();

int k =0;



        System.out.println("Давай заполним информацию о пользователях: ");
//вместо фор вайл бесмконечный (пока сайзоф не равно 0б то выполняем то что в фор сейчас)
        while (sizeOfArray != 0){

            System.out.println("Введи имя "+(k+1)+" владельца: ");

            String name  = sc.next();

            if(users.isEmpty()){

                System.out.println("Введи возраст "+(k+1)+" владельца: ");
                int age = sc.nextInt();
                int id = k+1;

                users.add(new User(name, age, id));

                System.out.println(users.size());
// тут уменьшаю сайз оф на 1
                sizeOfArray--;
                k++;
                addCar(users.get(0));
                continue;
            }

            for (Iterator<User> it = users.iterator(); it.hasNext(); ) {
                User user = it.next();
                if (!user.nameOfUser.equals(name)){

                    System.out.println("Введи возраст "+(k+1)+" владельца: ");
                    int age = sc.nextInt();
                    int id = k+1;

                    users.add(new User(name, age, id));

                    addCar(users.get(k));

                    // тут уменьшаю сайз оф на 1
                    sizeOfArray--;
                    k++;
                }else{
                    addCar(user);
                }
            }




        }

        for (int i = 0; i< users.size(); i++){
            System.out.println("Все имебщиеся машины на парковке: ");
            users.get(i).printInfoAboutUser();
        }

        boolean choice = true;

        while (choice){
        System.out.println("Мы заполнили парковку машинами! Что теперь ты хочешь сделать? 1-Показать инфу о конкретном водителе, 2-Удалить машину с парковки, 3-Присовить машинам нового владельца, 4 - Выйти");
        int num = sc.nextInt();
        switch (num) {
            case 1:

                System.out.println("Вы выбрали показать инфу о конкретном пользователе. О каком именно показать инфу? Введи номер пользователя:");
                int numOfUser = sc.nextInt();

                users.get(numOfUser - 1).printInfoAboutUser();
                break;


                case 2:
                 System.out.println("Вы выбрали удалить машину с парковки. Какую машину будем удалять? Введи Id водителя: ");
                 int numOfDeletedCar = sc.nextInt();

                 users.remove(numOfDeletedCar-1);


                 for (int i = 0; i < users.size(); i++) {

                     users.get(i).printInfoAboutUser();

                 }
                 break;

            case 3:
                System.out.println("Вы выбрали присвоить машине нового владельцца. У какой машины вы хотите поменять водителя? Введи id водителя");
                int numOfNewOwner = sc.nextInt();

                System.out.println("Отлично! Введи новое имя владельца и его возраст: ");
                users.get(numOfNewOwner-1).nameOfUser = sc.next();
                users.get(numOfNewOwner-1).age = sc.nextInt();

                System.out.println("Вот и обновленная информация: ");

                users.get(numOfNewOwner-1).printInfoAboutUser();

                break;


            case 4:
                choice = false;
                break;

        }

        }


    }

    public static void addCar(User user){
        Scanner sc = new Scanner(System.in);

        System.out.println(user.nameOfUser);
        System.out.println("Введи информацию о машине этого же владельца: ");
        System.out.println("Название: ");
        String name = sc.next();
        System.out.println("Модель: ");
        String model = sc.next();
        System.out.println("Цена: ");
        int cost = sc.nextInt();
        System.out.println("Вес: ");
        int weight = sc.nextInt();
        user.car.add(new Car(name, model, cost, weight));
    }
}


class Car{

    String name;
    String model;
    int cost;
    int weight;


    Car(){
        name = "NoName";
        model = "NoModel";
        cost = 0;
        weight = 0;
    }

    Car(String name, String model, int cost, int weight){
        this.name =  name;
        this.model =  model;
        this.cost = cost;
        this.weight = weight;

    }

    //Cars(String name, String model, int weight){
     //   this.name =  name;
     //   this.model =  model;
     //   this.weight = weight;
   // }

    Car(String name, int cost, int weight){
        this.name =  name;
        this.cost =  cost;
        this.weight = weight;
    }

    public void printInfo(){
        System.out.println("Имя машины: "+name);
        System.out.println("Модель машины: "+model);
        System.out.println("Цена машины: "+cost);
        System.out.println("Масса машины: "+weight);
    }
}

class User{

    ArrayList<Car>  car;
    String nameOfUser;
    int age;
    int id;

    User(){
        car = new ArrayList<>();
        nameOfUser = "NoName";
        age = 18;
        id = 0;
    }

    User(String name, int age, int id){
        this.nameOfUser = name;
        this.age = age;
        this.id = id;
        this.car = new ArrayList<>();
    }

    User(Car car, String name, int age, int id){
        this.nameOfUser = name;
        this.age = age;
        this.car.add(car);
        this.id = id;
    }

    public void printInfoAboutUser(){
        System.out.println("------------------------");
        System.out.println("ID владельца: "+id);
        System.out.println("Имя владельца: "+nameOfUser);
        System.out.println("Возраст владельца: "+age);
        for (Car c: car) {
            System.out.println("Название машины: " + c.name);
            System.out.println("Модель машины: " + c.model);
            System.out.println("Цена машины: " + c.cost);
            System.out.println("Вес машины: " + c.weight);
            System.out.println("------------------------");
        }
    }

}
