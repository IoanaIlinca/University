package Model.stmt;

import Exceptions.ExpectedBooleanException;
import Model.adt.IDict;
import Model.exp.Exp;
import Model.exp.RelExp;
import Model.exp.VarExp;
import Model.programState.PrgState;
import Model.types.IntegerType;
import Model.types.Type;

import java.util.ArrayList;

public final class ForStmt implements IStmt {
    private final String v;
    private final Exp exp1;
    private final Exp exp2;
    private final Exp exp3;
    private final IStmt statement;

    public ForStmt(String v, Exp exp1, Exp exp2, Exp exp3, IStmt statement) {
        this.v = v;
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.exp3 = exp3;
        this.statement = statement;
    }


    @Override
    public PrgState execute(PrgState state) throws Exception {


        IStmt s = ComposeStmt.compose(new ArrayList<>(java.util.List.of(
                //new VarDeclarationStmt(new IntegerType(), v),
                new AssignStmt(v, exp1),
                new WhileStatement(new RelExp("<", new VarExp(v), exp2), new CompStmt(statement, new AssignStmt(v, exp3)))
        )));

        state.getExeStack().push(s);
        return null;
    }

    @Override
    public String toString() {
        String res = "";
        res += "for(" + v + " = " + exp1.toString() + "; " + v + " < " + exp2.toString() + "; " + v + " = "+ exp3.toString() + ")\n" + statement.toString() + "\n";
        return res;
    }

    @Override
    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception {
        Type typexp1 = exp1.typecheck(typeEnv);
        //System.out.println(typexp1.toString() + "1");
        Type typexp2 = exp2.typecheck(typeEnv);
        //System.out.println(typexp2.toString() + "2");
        Type typexp3 = exp3.typecheck(typeEnv);
        //System.out.println(typexp3.toString() + "3");
        //Type vtype =
        //System.out.println(typexp);
        if (typexp1.equals(new IntegerType()) && typexp2.equals(new IntegerType()) && typexp3.equals(new IntegerType()))  {
            return typeEnv;
        }
        else throw new ExpectedBooleanException("The expressions are not all integers");
    }
}
