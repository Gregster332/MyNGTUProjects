package com.company;

public class Main {

    public static void main(String[] args) {

        Tree<Integer> tree = new Tree<>(2, null);
        tree.add(15, 3, 1, 5, 4, 6, 7, 8, 10, 12);
        //Распечатаем элементы дерева
        tree.print();
        //Удалим корень
        tree.remove(6);
        tree.remove(10);
        tree.print();



    }
}
