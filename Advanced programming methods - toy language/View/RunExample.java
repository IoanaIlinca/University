package View;

import Controller.Controller;
import Model.programState.PrgState;

public class RunExample extends Command {
    private Controller ctr;
    PrgState prgState;
    public RunExample(String key, String desc,Controller ctr, PrgState prgState){
        super(key, desc);
        this.ctr=ctr;
        this.prgState = prgState;
    }

    public Controller getController(){
        return ctr;
    }
    @Override
    public void execute() {
        try{
            ctr.allStep(prgState); }
        catch (Exception e) {
            System.out.println(e.getMessage());
            //e.printStackTrace();
        }
    }
    @Override
    public String toString(){
        return this.getDescription();
    }
}