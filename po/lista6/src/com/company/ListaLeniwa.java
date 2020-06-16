package com.company;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Random;

public class ListaLeniwa implements Serializable, Collection<Integer> {
    Random rnd = new Random();

    ArrayList myList = new ArrayList();

    ListaLeniwa(){}

    protected int Fill(){
        return rnd.nextInt();
    }

    public int GetSize(){
        return myList.size();
    }

    public int element(int x){
        while (x >= GetSize()){
            myList.add(Fill());
        }
        return (int) myList.get(x);
    }

    @Override
    public int size() {
        return GetSize();
    }

    @Override
    public boolean isEmpty() {
        return GetSize() == 0;
    }

    @Override
    public boolean contains(Object o) {
        for(int i = 0; i<GetSize(); i++){
            if(this.element(i)==(int) o) return true;
        }
        return false;
    }

    @Override
    public Iterator<Integer> iterator() {
        return null;
    }

    @Override
    public Object[] toArray() {
        Object[] array = new Object[GetSize()];
        for(int i = 0; i<GetSize(); i++){
            array[i] = this.element(i);
        }
        return array;
    }

    @Override
    public <T> T[] toArray(T[] ts) throws UnsupportedOperationException {
        throw new UnsupportedOperationException();
    }

    @Override
    public boolean add(Integer integer) {
        myList.add(integer);
        return true;
    }

    @Override
    public boolean remove(Object o) {
        for(int i = 0; i<GetSize(); i++){
            if(this.element(i)==(int) o) {
                for(int j = i; j<GetSize()-1; j++){
                    myList.set(j, myList.get(j+1));
                }
                myList.set(GetSize(), null);
                myList.subList(GetSize()-1, GetSize()).clear();
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean containsAll(Collection<?> collection) {
        throw new UnsupportedOperationException();
    }

    @Override
    public boolean addAll(Collection<? extends Integer> collection) {
        throw new UnsupportedOperationException();
    }

    @Override
    public boolean removeAll(Collection<?> collection) {
        throw new UnsupportedOperationException();
    }

    @Override
    public boolean retainAll(Collection<?> collection) {
        throw new UnsupportedOperationException();
    }

    @Override
    public void clear() {

    }
}
