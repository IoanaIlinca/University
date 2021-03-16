/*
package View;
import Model.adt.*;
import Model.exp.*;
import Model.stmt.*;
import Model.types.IntegerType;
import Model.types.RefType;
import Model.types.StringType;
import Model.types.Type;
import Model.values.IntegerValue;
import Model.values.StringValue;
import Model.values.Value;
import Repo.Repo;
import Controller.Controller;
import Model.programState.PrgState;
import View.RunExample;
import java.io.BufferedReader;

public class Main {


    public static void main(String[] args) throws Exception {

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));

        IStmt originalProgram = new IfStmt(new ConstExp(10),
                new CompStmt(new CompStmt(new VarDeclarationStmt(new IntegerType(), "v"), new AssignStmt("v", new ConstExp(5))),
                        new PrintStmt(new ArithExp("/",
                                new VarExp("v"), new ConstExp(5)))),
                new PrintStmt(new ConstExp(100)));
        IDict<String, Type> typeEnv1 = new Dict<String, Type>();
        try {
            originalProgram.typecheck(typeEnv1);
            Repo myRepository = new Repo("1.txt");
            Controller myController = new Controller(myRepository);
            ClassStack<IStmt> exeStack = new ClassStack<IStmt>();
            IHeap<Integer, Value> heap = new ClassHeap<Integer, Value>();
            //exeStack.push(originalProgram);
            IDict<String, Value> symTable = new Dict<String, Value>();
            IList<String> out = new List<String>();
            IFileTable<String, BufferedReader> FileTable = new FileTable<String, BufferedReader>();
            //symTable.add("v", new IntegerValue(5));
            PrgState myPrgState = new PrgState(exeStack, symTable, out, FileTable, heap, originalProgram);

            //System.out.println(exeStack);
            myController.addProgram(myPrgState);
            menu.addCommand(new RunExample("1",originalProgram.toString(),myController,myPrgState));
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }





        IStmt otherProgram = new IfStmt(new ConstExp(10),
                new CompStmt(new AssignStmt("v", new ConstExp(5)),
                        new PrintStmt(new ArithExp("/",
                                new VarExp("v"), new ConstExp(3)))),
                new PrintStmt(new ConstExp(100)));

        IDict<String, Type> typeEnv2 = new Dict<String, Type>();
        try {
            otherProgram.typecheck(typeEnv2);
            Repo myOtherRepository = new Repo("2.txt");
            Controller myOtherController = new Controller(myOtherRepository);
            ClassStack<IStmt> otherExeStack = new ClassStack<IStmt>();
            IHeap<Integer, Value> otherHeap = new ClassHeap<Integer, Value>();
            //exeStack.push(originalProgram);
            IDict<String, Value> otherSymTable = new Dict<String, Value>();
            IList<String> otherOut = new List<String>();
            IFileTable<String, BufferedReader> otherFileTable = new FileTable<String, BufferedReader>();
            //symTable.add("v", new IntegerValue(5));
            PrgState otherPrgState = new PrgState(otherExeStack, otherSymTable, otherOut, otherFileTable, otherHeap,otherProgram);

            //System.out.println(otherExeStack);
            myOtherController.addProgram(otherPrgState);
            menu.addCommand(new RunExample("2",otherProgram.toString(),myOtherController, otherPrgState));

        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            //e.printStackTrace();
        }



        IStmt testProgram = new CompStmt(
                new VarDeclarationStmt(new StringType(), "varf"),
                new CompStmt(
                        new AssignStmt(
                                "varf", new ValExp(new StringValue("H:\\Faculta\\an 2\\MAP\\assignment2_example\\Interpretor_template1\\Interpretor_template1\\src\\View\\test.in"))
                        ),

                        new CompStmt(
                                new OpenRFile(new VarExp("varf")),
                                new CompStmt(
                                    new VarDeclarationStmt(new IntegerType(), "varc"),
                                    new CompStmt(
                                            new ReadFile("varc", new VarExp("varf")),
                                            new CompStmt(
                                                    new PrintStmt(new VarExp("varc")),
                                                    new CompStmt(
                                                            new ReadFile("varc", new VarExp("varf")),
                                                            new CompStmt(
                                                                    new PrintStmt(new VarExp("varc")),
                                                                    new CloseRFile(new VarExp("varf")))
                                                    )
                                                )
                                            )
                                )
                        )
                )
        );

        IDict<String, Type> typeEnv3 = new Dict<String, Type>();
        try {
            testProgram.typecheck(typeEnv3);

            Repo testRepository = new Repo("3.txt");
            Controller testController = new Controller(testRepository);
            ClassStack<IStmt> testExeStack = new ClassStack<IStmt>();
            IHeap<Integer, Value> testHeap = new ClassHeap<Integer, Value>();
            IDict<String, Value> testSymTable = new Dict<String, Value>();
            IList<String> testOut = new List<String>();
            IFileTable<String, BufferedReader> testFileTable = new FileTable<String, BufferedReader>();
            //symTable.add("v", new IntegerValue(5));
            PrgState testState = new PrgState(testExeStack, testSymTable,testOut, testFileTable, testHeap, testProgram);

            //System.out.println(otherExeStack);
            testController.addProgram(testState);

            menu.addCommand(new RunExample("3",testProgram.toString(),testController, testState));
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }




        IStmt whileProgram = new CompStmt(
                new CompStmt(
                        new RefDeclarationStmt(new IntegerType(), "v"),
                        new CompStmt(
                            new AllocateHeapStmt("v", new ValExp(new IntegerValue(4))),
                                new AllocateHeapStmt("v", new ValExp(new IntegerValue(5)))
                            )
                        ),
                new CompStmt(
                        new WhileStatement(new RelExp(">", new ReadHeapExp(new VarExp("v")), new ConstExp(0)),
                                new CompStmt (
                                        new PrintStmt(new ReadHeapExp(new VarExp("v"))),
                                        new WriteHeapStmt("v", new ArithExp("-", new ReadHeapExp(new VarExp("v")), new ConstExp(1)))
                                    )
                                ),
                        new PrintStmt(new ReadHeapExp(new VarExp("v")))
                        )
                );

        IDict<String, Type> typeEnv4 = new Dict<String, Type>();
        try {
            whileProgram.typecheck(typeEnv4);
            Repo whileRepository = new Repo("4.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, whileHeap, whileProgram);


            whileController.addProgram(whileState);
            menu.addCommand(new RunExample("4",whileProgram.toString(),whileController, whileState));
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }




        IStmt forkProgram =
                new CompStmt(
                        new CompStmt(
                                new VarDeclarationStmt(new IntegerType(), "v"),
                                new RefDeclarationStmt(new IntegerType(), "a")
                        ),
                        new CompStmt(
                                new CompStmt(
                                        new AssignStmt("v", new ConstExp(10)),
                                        new AllocateHeapStmt("a", new ConstExp(22))
                                ),
                                new CompStmt(
                                        new ForkStmt(
                                                new CompStmt(
                                                    new CompStmt(
                                                            new WriteHeapStmt("a", new ConstExp(30)),
                                                             new AssignStmt("v", new ConstExp(32))
                                                    ),
                                                        new CompStmt(
                                                                new PrintStmt(new VarExp("v")),
                                                                new PrintStmt(new ReadHeapExp(new VarExp("a")))
                                                        )

                                                        )
                                        ),
                                        new CompStmt(
                                                new CompStmt(
                                                        new PrintStmt(new ValExp(new StringValue("hello"))),
                                                        new PrintStmt(new VarExp("v"))
                                                        ),
                                                new PrintStmt(new ReadHeapExp(new VarExp("a")))
                                        )

                                )
                        )
                );
        IDict<String, Type> typeEnv5 = new Dict<String, Type>();
        try {
            forkProgram.typecheck(typeEnv5);
            Repo forkRepository = new Repo("5.txt");
            Controller forkController = new Controller(forkRepository);
            ClassStack<IStmt> forkStack = new ClassStack<IStmt>();
            IHeap<Integer, Value> forkHeap = new ClassHeap<Integer, Value>();
            //exeStack.push(originalProgram);
            IDict<String, Value> forkSymTable = new Dict<String, Value>();
            IList<String> forkOut = new List<String>();
            IFileTable<String, BufferedReader> forkFileTable = new FileTable<String, BufferedReader>();
            //symTable.add("v", new IntegerValue(5));
            PrgState forkPrgState = new PrgState(forkStack, forkSymTable, forkOut, forkFileTable, forkHeap, forkProgram);

            //System.out.println(exeStack);
            forkController.addProgram(forkPrgState);
            menu.addCommand(new RunExample("5",forkProgram.toString(),forkController, forkPrgState));

        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }



        menu.show();
    }
}
*/
