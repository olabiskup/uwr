package com.company;

import java.util.Hashtable;

public class Constant extends Expression {

    int value;

    public Constant(int value){
        this.value = value;
    }

    @Override
    public int evaluate(Hashtable<String, Integer> array) {
        return value;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }
}
