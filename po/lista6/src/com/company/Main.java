//Aleksandra Biskup 317424
//Lista 6 - zadanie 1 i 2
package com.company;

import java.io.*;

public class Main {

    public static void main(String[] args) {
        ListaLeniwa test = new ListaLeniwa();
        System.out.println("zadanie 1: ");
        System.out.println(test.element(5));
        try {
            FileOutputStream f = new FileOutputStream(new File("myObjects.txt"));
            ObjectOutputStream o = new ObjectOutputStream(f);

            o.writeObject(test);

            o.close();
            f.close();

            FileInputStream fi = new FileInputStream(new File("myObjects.txt"));
            ObjectInputStream oi = new ObjectInputStream(fi);

            ListaLeniwa pr1 = (ListaLeniwa) oi.readObject();
            System.out.println("Odczytane z pliku: " + pr1.element(5));

            oi.close();
            fi.close();

        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            System.out.println("Error initializing stream");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("zadanie 2:");
        System.out.println("Czy list jest pusta?");
        if(test.isEmpty()) System.out.println("true");
        else System.out.println("false");
        //konwersja listy na tablicę
        Object[] test_arr = test.toArray();
        for (int i=0; i<test_arr.length; i++)
            System.out.print(test_arr[i] + "; ");

    }
}
