package com.company;

import java.util.Hashtable;

public class Divide extends BinOper {

    public Divide(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    public int evaluate(Hashtable<String, Integer> array) {
        return left.evaluate(array)/right.evaluate(array);
    }

    public String toString() {
        return String.format("(%s / %s)", left, right);
    }
}
