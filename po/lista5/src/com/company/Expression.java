package com.company;

import java.util.Hashtable;

public abstract class Expression {
    public abstract int evaluate(Hashtable<String, Integer> array);
    public abstract String toString();
}