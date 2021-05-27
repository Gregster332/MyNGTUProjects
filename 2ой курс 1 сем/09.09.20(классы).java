package com.company;
import  java.util.Scanner;



public class Main {


    // создаем массив объектов класса Person
    private static Person[] array;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        //Начальное меню
        System.out.println("Привет! Давай создадим пару объектов. СКолько ты хочешь их создать? Введи число");
        int personCount = sc.nextInt();
        array = new Person[personCount];
        System.out.println(array.length);
	    for(int i = 0; i < personCount; i++) {
	    System.out.println("Создаем челика номер " + (i+1));
	    array[i] = new Person();
	    array[i].createPerson();
	        }

	    //вывод информации обо всех пользователях
	    System.out.println("Вывожу инфу обо всех пользователях: ");
	    for(int i = 0; i < personCount; i++) {
            array[i].aboutPerson();
	     }

	    //выбор действия для созданных объектов
	    System.out.println("Мы создали пользователей! Балдеж! Что мы будем с ними делать? 1-Изменить номер телефона любого из челиков, 2-Сравнить челиков по имени, 3-Выход");
	    int randomChoice = sc.nextInt();
	    switch (randomChoice){
            case 1:
                System.out.println("Вы выбрали изменить номер телефона одного из челиков. Чей номер будем менять? Введи номер этого человека: ");
                int chelikChoice = sc.nextInt();
                switch(chelikChoice){
                    case 1:
                        System.out.println("Вы выбрали "+ chelikChoice +"-го человека, а точнее "+array[chelikChoice-1].name + ". Введи новый номер: ");
                        String newNumber = sc.next();
                        array[chelikChoice-1].numberPhoneChanger(newNumber);
                        System.out.println("Новые данные: ");
                        array[chelikChoice-1].aboutPerson();
                        break;
                    case 2:
                        System.out.println("Вы выбрали "+ chelikChoice +"-го человека, а точнее "+array[chelikChoice-1].name + ". Введи новый номер: ");
                        String newNumber2 = sc.next();
                        array[chelikChoice-1].numberPhoneChanger(newNumber2);
                        System.out.println("Новые данные: ");
                        array[chelikChoice-1].aboutPerson();
                        break;
                    case 3:
                        System.out.println("Вы выбрали "+ chelikChoice +"-го человека, а точнее "+array[chelikChoice-1].name + ". Введи новый номер: ");
                        String newNumber3 = sc.next();
                        array[chelikChoice-1].numberPhoneChanger(newNumber3);
                        System.out.println("Новые данные: ");
                        array[chelikChoice-1].aboutPerson();
                        break;
                    case 4:
                        System.out.println("Вы выбрали "+ chelikChoice +"-го человека, а точнее "+array[chelikChoice-1].name + ". Введи новый номер: ");
                        String newNumber4 = sc.next();
                        array[chelikChoice-1].numberPhoneChanger(newNumber4);
                        System.out.println("Новые данные: ");
                        array[chelikChoice-1].aboutPerson();
                        break;
                    default:
                        break;
                }
            case 2:
                System.out.println("Вы выбрали сравнение по именам. Кого будем сравнивать? Введи номер этого человека: ");
                int parametr = sc.nextInt();
                System.out.println("Теперь выбери с кем будем сравнивать. Так же укажи номер челика: ");
                int parametr2 = sc.nextInt();
                if(array[parametr-1].equalss(array[parametr2-1])){
                    System.out.println("Имена одинаковы");
                }else{
                    System.out.println("Имена разные");
                }
                break;
            case 3: break;
        }



    }


}


//сам класс Рerson
class Person{
    String name;
    int age;
    String phone;
    String numberPhone;

    //конструктор по умолчанию
    Person(){
        this.name = "none";
        this.age = 0;
        this.phone = "none";
        this.numberPhone = "none";
    }

    //конструктор с указанием конкретных параметров
    Person(String name, int age, String phone, String numberPhone){
        this.name = name;
        this.age =age;
        this.phone = phone;
        this.numberPhone = numberPhone;
    }


    //фу-я изменения номера телефона
    public void numberPhoneChanger(String number){
        this.numberPhone = number;

    }


    //фу-я создания нового объекта класса
    void createPerson(){
        Scanner scc = new Scanner(System.in);
        System.out.println("Создадим нового челика");
        System.out.println("Введите имя: ");
        String name = scc.next();
        this.name = name;
        System.out.println("Введите возраст: ");
        int age = scc.nextInt();
        this.age = age;
        System.out.println("Введите модель телефона: ");
        String modelPhone = scc.next();
        this.phone = modelPhone;
        //while(checkNum() == false){
        System.out.println("Введите номер телефона: ");
        String numbrePhone = scc.next();
        this.numberPhone = numbrePhone;

        }





        //фу-я проверки номера телефона(надо переделать)
    public boolean checkNum() {
        if ((this.numberPhone.length() == 12) && (this.numberPhone.substring(0,1)).equals("+")) {
            System.out.println("true");
            return true;
        } else {
            System.out.println("false");
            return false;
        }
    }

    //ф-я вывода информации  о пользователе
    void aboutPerson(){
        System.out.println("Имя: " + this.name +","+"Возраст: " + this.age + ","+"Модель телефона: " + this.phone + ","+"Номер телефона: " + this.numberPhone);
    }


    //ф-я сравнения объектов класса по именам
    boolean equalss(Person person){
        if(this.name.equals(person.name)){

            return true;
        }else{

            return false;
        }


    }

}