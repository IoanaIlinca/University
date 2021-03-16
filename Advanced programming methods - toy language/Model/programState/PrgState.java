package Model.programState;

import Exceptions.EmptyStackException;
import Model.adt.*;
import Model.stmt.IStmt;
import Model.values.IntegerValue;
import Model.values.Value;
import org.javatuples.Pair;

import java.io.BufferedReader;

public class PrgState {

    private final IStack<IStmt> exeStack;
    private final IDict<String, Value> symTable;
    private final IList<String> outputStream;
    private final IFileTable<String, BufferedReader> fileTable;
    private final ISemaphore<Integer, Pair<IntegerValue, List<Integer>>>  semaphoreTable;

    public IBarrier<Integer, Pair<Integer, java.util.List<Integer>>> getBarrierTable() {
        return barrierTable;
    }

    private final IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable;



    private final ILock<Integer, Integer> Lock;



    private final ILatch<Integer, Integer> Latch;
    private final int id;
    private static int countIds = 0;
    private final IHeap<Integer, Value> heap;

    private synchronized static int manageIds () {
        countIds++;
        return countIds;
    }

    public ILock<Integer, Integer> getLock() {
        return Lock;
    }

    public ILatch<Integer, Integer> getLatch() {
        return Latch;
    }

    public ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> getSemaphoreTable() {
        return semaphoreTable;
    }

    public int getId () {
        return id;
    }

    public Boolean isNotCompleted() {
        if (!exeStack.isEmpty())
            return true;
        else
            return false;
    }

    public PrgState(IStack<IStmt> stack,
                    IDict<String, Value> Table,
                    IList<String> out,
                    IFileTable<String, BufferedReader> fTable,
                    IBarrier<Integer, Pair<Integer, java.util.List<Integer>>> barrierTable, IHeap<Integer, Value> he,
                    IStmt program, ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> semaphoreTable, ILock<Integer, Integer> lock, ILatch<Integer, Integer> latch)
    {
        this.barrierTable = barrierTable;
        this.semaphoreTable = semaphoreTable;
        Lock = lock;
        Latch = latch;
        id = manageIds();
        stack.push(program);
        exeStack = stack;
        symTable = Table;
        fileTable = fTable;
        outputStream = out;
        heap = he;
    }

    public PrgState oneStep() throws Exception {
        IStack<IStmt> stack = this.getExeStack();
        if(stack.isEmpty()) {
            throw new EmptyStackException("The stack is empty!");
        }
        IStmt currentStatement = stack.pop();
        return currentStatement.execute(this);
    }

    public IHeap<Integer, Value> getHeap() {
        return heap;
    }

    public IDict<String, Value> getSymTable() {
        return symTable;
    }

    public IList<String> getOutputStream() {
        return outputStream;
    }


    public IStack<IStmt> getExeStack() { return exeStack; }

    public IFileTable<String, BufferedReader> getFileTable() {
        return fileTable;
    }

    @Override
    public String toString() {
        String result = "\n";
        result += exeStack.toString().substring(11);
        result.trim();
        return result;
    }
}