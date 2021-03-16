package Tests;

import Controller.Controller;
import Repo.Repo;

public class Tests {
    static Repo myRepository = new Repo();
    static Controller myController = new Controller(myRepository);

    public void TestingDivisionBy0 () {
        /*
        IStmt originalProgram = new IfStmt(new ConstExp(10),
                new CompStmt(new CompStmt(new VarDeclarationStmt(new IntegerType(), "v"), new AssignStmt("v", new ConstExp(5))),
                        new PrintStmt(new ArithExp("/",
                                new VarExp("v"), new ConstExp(0)))),
                new PrintStmt(new ConstExp(100)));
        ClassStack<IStmt> exeStack = new ClassStack<IStmt>();
        //exeStack.push(originalProgram);
        IDict<String, Value> symTable = new Dict<String, Value>();
        IList<String> out = new List<String>();
        //symTable.add("v", new IntegerValue(5));
        PrgState myPrgState = new PrgState(exeStack, symTable, out, originalProgram);

        //System.out.println(exeStack);
        myController.addProgram(myPrgState);
        try {
            myController.allStep(myPrgState);
        }
        catch (Exception ex) {
            assert(ex.getMessage() == "Cannot divide by 0");
        }
    }


    public void TestingNormal () {
        IStmt originalProgram = new IfStmt(new ConstExp(10),
                new CompStmt(new CompStmt(new VarDeclarationStmt(new IntegerType(), "v"), new AssignStmt("v", new ConstExp(5))),
                        new PrintStmt(new ArithExp("/",
                                new VarExp("v"), new ConstExp(5)))),
                new PrintStmt(new ConstExp(100)));
        ClassStack<IStmt> exeStack = new ClassStack<IStmt>();
        //exeStack.push(originalProgram);
        IDict<String, Value> symTable = new Dict<String, Value>();
        IList<String> out = new List<String>();
        //symTable.add("v", new IntegerValue(5));
        PrgState myPrgState = new PrgState(exeStack, symTable, out, originalProgram);

        //System.out.println(exeStack);
        myController.addProgram(myPrgState);
        try {
            myController.allStep(myPrgState);
        }
        catch (Exception ex) {
            assert(ex.getMessage() == "");
        }
    }

    public void TestingVariableNotDeclared (){
        IStmt otherProgram = new IfStmt(new ConstExp(10),
                new CompStmt(new AssignStmt("v", new ConstExp(5)),
                        new PrintStmt(new ArithExp("/",
                                new VarExp("v"), new ConstExp(3)))),
                new PrintStmt(new ConstExp(100)));

        ClassStack<IStmt> otherExeStack = new ClassStack<IStmt>();
        //exeStack.push(originalProgram);
        IDict<String, Value> otherSymTable = new Dict<String, Value>();
        IList<String> otherOut = new List<String>();
        //symTable.add("v", new IntegerValue(5));
        PrgState otherPrgState = new PrgState(otherExeStack, otherSymTable, otherOut, otherProgram);

        //System.out.println(otherExeStack);
        myController.addProgram(otherPrgState);
        try {
            myController.allStep(otherPrgState);
        }
        catch (Exception ex) {
            assert(ex.getMessage() == "The variable was not declared");
        }
    }

    public void TestingIfZero() {
        IStmt originalProgram = new IfStmt(new ConstExp(0),
                new CompStmt(new CompStmt(new VarDeclarationStmt(new IntegerType(), "v"), new AssignStmt("v", new ConstExp(5))),
                        new PrintStmt(new ArithExp("/",
                                new VarExp("v"), new ConstExp(5)))),
                new PrintStmt(new ConstExp(100)));
        ClassStack<IStmt> exeStack = new ClassStack<IStmt>();
        //exeStack.push(originalProgram);
        IDict<String, Value> symTable = new Dict<String, Value>();
        IList<String> out = new List<String>();
        //symTable.add("v", new IntegerValue(5));
        PrgState myPrgState = new PrgState(exeStack, symTable, out, originalProgram);

        //System.out.println(exeStack);
        myController.addProgram(myPrgState);
        try {
            myController.allStep(myPrgState);
            assert(out.toString() == "List\n100");
        }
        catch (Exception ex) {
            System.out.println(ex.getMessage());
        }*/
    }
}
