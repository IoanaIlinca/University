package View;

import Controller.Controller;
import Model.adt.*;
import Model.exp.*;
import Model.programState.PrgState;
import Model.stmt.*;
import Model.types.IntegerType;
import Model.types.RefType;
import Model.types.StringType;
import Model.types.Type;
import Model.values.IntegerValue;
import Model.values.StringValue;
import Model.values.Value;
import Repo.Repo;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import org.javatuples.Pair;

import java.io.BufferedReader;
import java.util.ArrayList;

public class MainInterpreter extends Application {
    private void raiseError(String m) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText(null);
            alert.setContentText("Error: " + m);
            Button confirm = (Button) alert.getDialogPane().lookupButton( ButtonType.OK );
            confirm.setDefaultButton(false);
            confirm.setStyle("-fx-focus-color: transparent; -fx-faint-focus-color: transparent;");
            alert.showAndWait();

    }

    private ArrayList<Command> allCommands()
    {

        ArrayList<Command> listOfPrograms = new ArrayList();
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
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            //exeStack.push(originalProgram);
            IDict<String, Value> symTable = new Dict<String, Value>();
            IList<String> out = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> FileTable = new FileTable<String, BufferedReader>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> semaphoreTable = new SemaphoreTable<>();
            //ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> semaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState myPrgState = new PrgState(exeStack, symTable, out, FileTable, barrierTable, heap, originalProgram, semaphoreTable, lock, latch);

            //System.out.println(exeStack);
            myController.addProgram(myPrgState);

            listOfPrograms.add(new RunExample("1",originalProgram.toString(),myController,myPrgState));
        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }




    /*
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
            IList<String> otherOut = new Model.adt.List<String>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();

            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            IFileTable<String, BufferedReader> otherFileTable = new FileTable<String, BufferedReader>();
            ISemaphore<Integer, Triplet<IntegerValue, List<Integer>, IntegerValue>> otherSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState otherPrgState = new PrgState(otherExeStack, otherSymTable, otherOut, otherFileTable, otherHeap,otherProgram, otherSemaphoreTable, lock, latch);

            //System.out.println(otherExeStack);
            myOtherController.addProgram(otherPrgState);
            listOfPrograms.add(new RunExample("2",otherProgram.toString(),myOtherController, otherPrgState));

        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }*/



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
            IList<String> testOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> testFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> testSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState testState = new PrgState(testExeStack, testSymTable,testOut, testFileTable, barrierTable, testHeap, testProgram, testSemaphoreTable, lock, latch);

            //System.out.println(otherExeStack);
            testController.addProgram(testState);

            listOfPrograms.add(new RunExample("3",testProgram.toString(),testController, testState));
        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }




        IStmt whileProgram = new CompStmt(
                new CompStmt(
                        new CompStmt(
                                new RefDeclarationStmt(new IntegerType(), "v"),
                                new RefDeclarationStmt(new RefType(new IntegerType()), "ref")
                                ),
                        new CompStmt(
                                new CompStmt(
                                    new AllocateHeapStmt("v", new ValExp(new IntegerValue(4))),
                                    new AllocateHeapStmt("ref", new VarExp("v"))
                                ),
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
            IList<String> whileOut = new Model.adt.List<String>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, whileProgram, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("4",whileProgram.toString(),whileController, whileState));
        }
        catch (Exception e) {
            raiseError(e.getMessage());
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
            IList<String> forkOut = new Model.adt.List<String>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            IFileTable<String, BufferedReader> forkFileTable = new FileTable<String, BufferedReader>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> forkSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState forkPrgState = new PrgState(forkStack, forkSymTable, forkOut, forkFileTable, barrierTable, forkHeap, forkProgram, forkSemaphoreTable, lock, latch);

            //System.out.println(exeStack);
            forkController.addProgram(forkPrgState);
            listOfPrograms.add(new RunExample("5",forkProgram.toString(),forkController, forkPrgState));

        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }

        IStmt semaphoreExample= ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                new RefDeclarationStmt(new IntegerType(), "v1"),
                new VarDeclarationStmt(new IntegerType(), "cnt"),
                new AllocateHeapStmt("v1", new ValExp(new IntegerValue(1))),
                new createSemaphore("cnt", new ReadHeapExp(new VarExp("v1"))),
                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                        new Acquire("cnt"),
                        new WriteHeapStmt("v1",new ArithExp("*", new ReadHeapExp( new VarExp("v1")),new ValExp(new IntegerValue(10)))),
                        new PrintStmt(new ReadHeapExp(new VarExp("v1"))),
                        new Release("cnt")
                )))),
                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                        new Acquire("cnt"),
                        new WriteHeapStmt("v1",new ArithExp("*", new ReadHeapExp( new VarExp("v1")),new ValExp(new IntegerValue(10)))),
                        new WriteHeapStmt("v1",new ArithExp("*", new ReadHeapExp( new VarExp("v1")),new ValExp(new IntegerValue(2)))),
                        new PrintStmt(new ReadHeapExp(new VarExp("v1"))),
                        new Release("cnt")
                )))),
                new Acquire("cnt"),
                new PrintStmt(new ArithExp("-", new ReadHeapExp(new VarExp("v1")), new ValExp(new IntegerValue(1)))),
                new Release("cnt")
        )));

        IDict<String, Type> typeEnv6 = new Dict<String, Type>();
        try {
            semaphoreExample.typecheck(typeEnv6);
            Repo forkRepository = new Repo("6.txt");
            Controller forkController = new Controller(forkRepository);
            ClassStack<IStmt> forkStack = new ClassStack<IStmt>();
            IHeap<Integer, Value> forkHeap = new ClassHeap<Integer, Value>();
            //exeStack.push(originalProgram);
            IDict<String, Value> forkSymTable = new Dict<String, Value>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            IList<String> forkOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> forkFileTable = new FileTable<String, BufferedReader>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> forkSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState forkPrgState = new PrgState(forkStack, forkSymTable, forkOut, forkFileTable, barrierTable, forkHeap, semaphoreExample, forkSemaphoreTable, lock, latch);

            //System.out.println(exeStack);
            forkController.addProgram(forkPrgState);
            listOfPrograms.add(new RunExample("6",semaphoreExample.toString(),forkController, forkPrgState));

        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }
        /*

        IStmt st =  ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                new VarDeclarationStmt(new BooleanType(), "b"),
                new VarDeclarationStmt(new IntegerType(), "c"),
                new AssignStmt("b", new ValExp(new BooleanValue(true))),
                new CondAssignStmt("c", new VarExp("b"), new ValExp(new IntegerValue(100)), new ValExp(new IntegerValue(200))),
                new PrintStmt(new VarExp("c")),
                new CondAssignStmt("c", new ValExp(new BooleanValue(false)), new ValExp(new IntegerValue(100)), new ValExp(new IntegerValue(200))),
                new PrintStmt(new VarExp("c"))
        )));
        IDict<String, Type> typeEnv7 = new Dict<String, Type>();
        try {
            //semaphoreExample.typecheck(typeEnv7);
            Repo forkRepository = new Repo("7.txt");
            Controller forkController = new Controller(forkRepository);
            ClassStack<IStmt> forkStack = new ClassStack<IStmt>();
            IHeap<Integer, Value> forkHeap = new ClassHeap<Integer, Value>();
            //exeStack.push(originalProgram);
            IDict<String, Value> forkSymTable = new Dict<String, Value>();
            IList<String> forkOut = new Model.adt.List<String>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            IFileTable<String, BufferedReader> forkFileTable = new FileTable<String, BufferedReader>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> forkSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState forkPrgState = new PrgState(forkStack, forkSymTable, forkOut, forkFileTable, barrierTable, forkHeap, st, forkSemaphoreTable, lock, latch);

            //System.out.println(exeStack);
            forkController.addProgram(forkPrgState);
            listOfPrograms.add(new RunExample("7",st.toString(),forkController, forkPrgState));

        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }

        IStmt forStatement = ComposeStmt.compose(new ArrayList<IStmt>(java.util.List.of(
                new RefDeclarationStmt(new IntegerType(), "a"),
                new AllocateHeapStmt("a", new ValExp(new IntegerValue(20))),
                new VarDeclarationStmt(new IntegerType(), "v"),
                new ForStmt("v", new ValExp(new IntegerValue(0)), new ValExp(new IntegerValue(3)), new ArithExp("+", new VarExp("v"), new ValExp(new IntegerValue(1))),
                    new ForkStmt(new CompStmt(
                                new PrintStmt(new VarExp("v")),
                                new AssignStmt("v", new ArithExp("*", new VarExp("v"), new ReadHeapExp(new VarExp("a")))
                                ))
                )),
                new PrintStmt(new ReadHeapExp(new VarExp("a")))
        )));

        IDict<String, Type> typeEnv8 = new Dict<String, Type>();
        try {
            forStatement.typecheck(typeEnv8);
            Repo whileRepository = new Repo("8.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, forStatement, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("8",forStatement.toString(),whileController, whileState));
        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }

        IStmt lockStatement = ComposeStmt.compose(new ArrayList<IStmt>(java.util.List.of(
                    new RefDeclarationStmt(new IntegerType(), "v1"),
                    new RefDeclarationStmt(new IntegerType(), "v2"),
                    new VarDeclarationStmt(new IntegerType(), "x"),
                    new VarDeclarationStmt(new IntegerType(), "q"),
                    new AllocateHeapStmt("v1", new ValExp(new IntegerValue(20))),
                    new AllocateHeapStmt("v2", new ValExp(new IntegerValue(30))),
                    new NewLock("x"),
                    new ForkStmt(
                            ComposeStmt.compose(new ArrayList<IStmt>(java.util.List.of(
                                    new ForkStmt(
                            ComposeStmt.compose(new ArrayList<IStmt>(java.util.List.of(
                                    new Lock("x"),
                                    new WriteHeapStmt("v1", new ArithExp("-", new ReadHeapExp(new VarExp("v1")), new ValExp(new IntegerValue(1)))),
                                    new Unlock("x")
                            )))),
                                    new Lock("x"),
                                    new WriteHeapStmt("v1", new ArithExp("*", new ReadHeapExp(new VarExp("v1")), new ValExp(new IntegerValue(10)))),
                                    new Unlock("x")

                    )))),
                new NewLock("q"),
                new ForkStmt(
                        ComposeStmt.compose(new ArrayList<IStmt>(java.util.List.of(
                                new ForkStmt(
                                        ComposeStmt.compose(new ArrayList<IStmt>(java.util.List.of(
                                                new Lock("q"),
                                                new WriteHeapStmt("v2", new ArithExp("+", new ReadHeapExp(new VarExp("v2")), new ValExp(new IntegerValue(5)))),
                                                new Unlock("q")
                                        )))),
                                new Lock("q"),
                                new WriteHeapStmt("v2", new ArithExp("*", new ReadHeapExp(new VarExp("v2")), new ValExp(new IntegerValue(10)))),
                                new Unlock("q")

                        )))),
                        new NoOperationStmt(),
                        new NoOperationStmt(),
                        new NoOperationStmt(),
                        new NoOperationStmt(),
                        new Lock("x"),
                        new PrintStmt(new ReadHeapExp(new VarExp("v1"))),
                        new Unlock("x"),
                        new Lock("q"),
                        new PrintStmt(new ReadHeapExp(new VarExp("v2"))),
                        new Unlock("q")
        )));
        IDict<String, Type> typeEnv9 = new Dict<String, Type>();
        try {
            lockStatement.typecheck(typeEnv9);
            Repo whileRepository = new Repo("9.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, lockStatement, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("9",lockStatement.toString(),whileController, whileState));
        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }

        IStmt switchExample= ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                new VarDeclarationStmt(new IntegerType(), "a"),
                new VarDeclarationStmt(new IntegerType(), "b"),
                new VarDeclarationStmt(new IntegerType(), "c"),
                new AssignStmt("a", new ValExp(new IntegerValue(1))),
                new AssignStmt("b", new ValExp(new IntegerValue(2))),
                new AssignStmt("c", new ValExp(new IntegerValue(5))),
                new SwitchStmt(new ArithExp("*",new VarExp("a"),new ValExp(new IntegerValue(10))),
                        new ArithExp("*",new VarExp("b"),new VarExp("c")),
                        new ValExp(new IntegerValue(10)),
                        ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                                new PrintStmt(new VarExp("a")),
                                new PrintStmt(new VarExp("b"))
                        ))),
                        ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                                new PrintStmt(new ValExp(new IntegerValue(100))),
                                new PrintStmt(new ValExp(new IntegerValue(200)))
                        ))),
                        new PrintStmt(new ValExp(new IntegerValue(300)))
                ),
                new PrintStmt(new ValExp(new IntegerValue(300)))
        )));
        IDict<String, Type> typeEnv10 = new Dict<String, Type>();
        try {
            switchExample.typecheck(typeEnv9);
            Repo whileRepository = new Repo("10.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, switchExample, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("10",switchExample.toString(),whileController, whileState));
        }

        catch (Exception e) {
            raiseError(e.getMessage());
        }
        IStmt repeatExample= ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                new VarDeclarationStmt(new IntegerType(), "v"),
                new AssignStmt("v", new ValExp(new IntegerValue(0))),
                new RepeatUntilStmt(
                        new RelExp("==",new VarExp("v"), new ValExp(new IntegerValue(3))),
                        ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                                        new PrintStmt(new VarExp("v")),
                                        new AssignStmt("v", new ArithExp("-",new VarExp("v"),new ValExp(new IntegerValue(1))))
                                )))),
                                new AssignStmt("v", new ArithExp("+",new VarExp("v"),new ValExp(new IntegerValue(1))))
                        )))
                ),
                new SleepStmt(new IntegerValue(4)),
                new PrintStmt(new ArithExp("*",new VarExp("v"),new ValExp(new IntegerValue(10)))),
                new VarDeclarationStmt(new IntegerType(), "vv"),
                new AssignStmt("vv", new ConstExp(20)),
                new WaitStmt(new IntegerValue(10)),
                new PrintStmt(new ArithExp("*",new VarExp("vv"),new ValExp(new IntegerValue(10))))
        )));

        IDict<String, Type> typeEnv11 = new Dict<String, Type>();
        try {
            repeatExample.typecheck(typeEnv11);
            Repo whileRepository = new Repo("11.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, repeatExample, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("11",repeatExample.toString(),whileController, whileState));
        }
        catch (Exception e) {
            raiseError(e.getMessage());
        }

        IStmt latchExample= ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                new RefDeclarationStmt(new IntegerType(), "v1"),
                new RefDeclarationStmt(new IntegerType(), "v2"),
                new RefDeclarationStmt(new IntegerType(), "v3"),
                new VarDeclarationStmt(new IntegerType(), "cnt"),
                new AllocateHeapStmt("v1", new ConstExp(2)),
                new AllocateHeapStmt("v2", new ConstExp(3)),
                new AllocateHeapStmt("v3", new ConstExp(4)),
                new newLatch("cnt", new ReadHeapExp(new VarExp("v2"))),
                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                        new WriteHeapStmt("v1", new ArithExp("*", new ReadHeapExp(new VarExp("v1")), new ConstExp(10))),
                        new PrintStmt(new ReadHeapExp(new VarExp("v1"))),
                        new CountDown("cnt"),
                        new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                                new WriteHeapStmt("v2", new ArithExp("*", new ReadHeapExp(new VarExp("v2")), new ConstExp(10))),
                                new PrintStmt(new ReadHeapExp(new VarExp("v2"))),
                                new CountDown("cnt"),
                                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                                        new WriteHeapStmt("v3", new ArithExp("*", new ReadHeapExp(new VarExp("v3")), new ConstExp(10))),
                                        new PrintStmt(new ReadHeapExp(new VarExp("v3"))),
                                        new CountDown("cnt")
                                ))))
                        ))))
                )))),
                new Await("cnt"),
                new PrintStmt(new ConstExp(100)),
                new CountDown("cnt"),
                new PrintStmt(new ConstExp(100))
        )));

        IDict<String, Type> typeEnv12 = new Dict<String, Type>();
        try {
            latchExample.typecheck(typeEnv12);
            Repo whileRepository = new Repo("12.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, latchExample, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("12",latchExample.toString(),whileController, whileState));
        }

        catch (Exception e) {
            raiseError(e.getMessage());
        }

        IStmt barrierExample= ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                new RefDeclarationStmt(new IntegerType(), "v1"),
                new RefDeclarationStmt(new IntegerType(), "v2"),
                new RefDeclarationStmt(new IntegerType(), "v3"),
                new VarDeclarationStmt(new IntegerType(), "cnt"),
                new AllocateHeapStmt("v1", new ConstExp(2)),
                new AllocateHeapStmt("v2", new ConstExp(3)),
                new AllocateHeapStmt("v3", new ConstExp(4)),
                new newBarrier("cnt", new ReadHeapExp(new VarExp("v2"))),
                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                        new AwaitBarrier("cnt"),
                        new WriteHeapStmt("v1", new ArithExp("*", new ReadHeapExp(new VarExp("v1")), new ConstExp(10))),
                        new PrintStmt(new ReadHeapExp(new VarExp("v1")))

                )))),
                new ForkStmt(ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                        new AwaitBarrier("cnt"),
                        new WriteHeapStmt("v2", new ArithExp("*", new ReadHeapExp(new VarExp("v2")), new ConstExp(10))),
                        new WriteHeapStmt("v2", new ArithExp("*", new ReadHeapExp(new VarExp("v2")), new ConstExp(10))),
                        new PrintStmt(new ReadHeapExp(new VarExp("v2")))
                )))),
                new AwaitBarrier("cnt"),
                new PrintStmt(new ReadHeapExp(new VarExp("v3")))
        )));

        IDict<String, Type> typeEnv13 = new Dict<String, Type>();
        try {
            //latchExample.typecheck(typeEnv13);
            Repo whileRepository = new Repo("13.txt");
            Controller whileController = new Controller(whileRepository);
            ClassStack<IStmt> whileExeStack = new ClassStack<IStmt>();
            IDict<String, Value> whileSymTable = new Dict<String, Value>();
            IHeap<Integer, Value> whileHeap = new ClassHeap<Integer, Value>();
            IList<String> whileOut = new Model.adt.List<String>();
            IFileTable<String, BufferedReader> whileFileTable = new FileTable<String, BufferedReader>();
            ILock<Integer, Integer> lock = new LockTable<Integer, Integer>();
            ILatch<Integer, Integer> latch = new Latch<Integer, Integer>();
            IBarrier<Integer, Pair<Integer, java.util.List<Integer>>>  barrierTable = new BarrierTable<>();
            
            ISemaphore<Integer, Pair<IntegerValue, List<Integer>>> whileSemaphoreTable = new SemaphoreTable<>();
            //symTable.add("v", new IntegerValue(5));
            PrgState whileState = new PrgState(whileExeStack, whileSymTable,whileOut, whileFileTable, barrierTable, whileHeap, barrierExample, whileSemaphoreTable, lock, latch);


            whileController.addProgram(whileState);
            listOfPrograms.add(new RunExample("13",barrierExample.toString(),whileController, whileState));
        }

        catch (Exception e) {
            raiseError(e.getMessage());
        }
        */
        return listOfPrograms;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        FXMLLoader loader=new FXMLLoader();
        loader.setLocation(MainInterpreter.class.getResource("MainWindow.fxml")); //URL
        StackPane rootLayout= (StackPane) loader.load();
        PrgListController ctrl=loader.getController();// Show the scene containing the root layout.

        ctrl.setStatementObservableList(allCommands());

        Scene scene = new Scene(rootLayout);
        primaryStage.setScene(scene);
        primaryStage.show();

    }


    public static void main(String[] args) {



        launch(args);



    }
}

