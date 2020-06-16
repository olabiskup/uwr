//do zadania 4
package com.company;

import java.util.Hashtable;

public class Derivative extends Expression {
    Expression e;
    Derivative(Expression e){
        this.e = derive(e);
    }

    public Expression derive(Expression e){
        if(e instanceof Variable) return new Constant(1);
        if(e instanceof Constant) return new Constant(0);
        if(e instanceof Add) return new Add(new Derivative(((Add) e).left), new Derivative(((Add) e).right));
        if(e instanceof Subtract) return new Subtract(new Derivative(((Subtract) e).left),new Derivative(((Subtract) e).right));
        if(e instanceof Multiply) return new Add(new Multiply(new Derivative(((Multiply) e).left), ((Multiply) e).right), new Multiply(((Multiply) e).left, new Derivative(((Multiply) e).right)));
        if(e instanceof Divide) return new Divide(new Subtract(new Multiply(new Derivative(((Divide) e).left), ((Divide) e).right), new Multiply(((Divide) e).left, new Derivative(((Divide) e).right))), new Multiply(((Divide) e).right, ((Divide) e).right));
        return null;
    }
    
    @Override
    public int evaluate(Hashtable<String, Integer> array) {
        return e.evaluate(array);
    }

    @Override
    public String toString() {
        return e.toString();
    }
}
