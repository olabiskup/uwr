package com.company;

import java.util.Hashtable;

public abstract class BinOper extends Expression {

    Expression left, right;

    BinOper(Expression left, Expression right){
        this.left = left;
        this.right = right;
    }

    protected BinOper() {
    }

    @Override
    public abstract int evaluate(Hashtable<String, Integer> array);

    @Override
    public abstract String toString();
}


