//Aleksandra Biskup 317424
//zadanie 2, klasa Derivative do zadania 4
package com.company;

import java.util.Hashtable;

public class Main {
    public static void main(String[] args) {
        Hashtable<String, Integer> array = new Hashtable<String, Integer>();
        array.put("a", 6);
        array.put("b", 2);
        array.put("c", 1);

        Expression test = new Divide(new Variable("a"), new Variable("b"));
        test = new Subtract(test, new Constant(3));

        Expression der = new Derivative(new Add(new Constant(1), new Multiply(new Variable("b"), new Variable("b"))));

        System.out.println(test.toString() + " = " + test.evaluate(array));
        System.out.println(der.toString() + " = " + der.evaluate(array));
    }
}
