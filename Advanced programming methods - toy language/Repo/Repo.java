package Repo;
import Exceptions.LogPrgStateException;
import Model.programState.PrgState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repo implements IRepo {
    private String logFilePath = "C:\\Users\\Ioana Ilinca\\Desktop\\Me.txt";

    private List<PrgState> myPrgStates;

    public Repo() {
        myPrgStates = new ArrayList<PrgState>();
    }
    public Repo(String logPath) {
        myPrgStates = new ArrayList<PrgState>();
        logFilePath = logPath;
    }
    /*
    @Override
    public PrgState getCrtPrg() {
        return myPrgStates.top();
    }*/

    @Override
    public void logPrgStateExec(PrgState prgState) throws LogPrgStateException {
        try {
            PrintWriter logFile= new PrintWriter(new BufferedWriter(new FileWriter(logFilePath, true)));
            logFile.write("State id: " + prgState.getId() + ":\n");
            logFile.write("Exe stack:\n" + prgState.getExeStack().toString());
            logFile.write("##########################################################\n");
            logFile.write( "SymTable:\n" + prgState.getSymTable().toString());
            logFile.write("##########################################################\n");
            logFile.write( "Heap:\n" + prgState.getHeap().toString());
            logFile.write("##########################################################\n");
            logFile.write("Out:\n" + prgState.getOutputStream().toString());
            logFile.write("##########################################################\n");
            logFile.write("File table:\n" + prgState.getFileTable().toString());
            logFile.write("##########################################################\n");
            logFile.write("Semaphore table:\n" + prgState.getSemaphoreTable().toString());
            logFile.write("##########################################################\n");
            /*logFile.write("Lock table:\n" + prgState.getLock().toString());
            logFile.write("##########################################################\n");
            logFile.write("Latch table:\n" + prgState.getLatch().toString());
            logFile.write("##########################################################\n");
            logFile.write("Barrier table:\n" + prgState.getBarrierTable().toString());
            logFile.write("##########################################################\n");*/
            logFile.write("\n");
            logFile.close();
        } catch (Exception e) {
            //System.out.println("Excuuuuuuse me");
            throw new LogPrgStateException(e.getMessage());
        }


    }

    @Override
    public List<PrgState> getPrgList() {
        return myPrgStates;
    }

    @Override
    public void setPrgList(List<PrgState> newPrgStates) {

        this.myPrgStates = newPrgStates;
        //System.out.println(myPrgStates.toString());
    }

    @Override
    public void addPrg(PrgState newPrg) {
        myPrgStates.add(newPrg);
    }
}
