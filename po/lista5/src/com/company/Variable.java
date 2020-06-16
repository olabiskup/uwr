package com.company;

import java.util.Hashtable;

public class Variable extends Expression {
    String name;

    public Variable(String name){
        this.name = name;
    }

    @Override
    public int evaluate(Hashtable<String, Integer> array) {
        return array.get(name);
    }

    @Override
    public String toString() {
        return name;
    }
}
