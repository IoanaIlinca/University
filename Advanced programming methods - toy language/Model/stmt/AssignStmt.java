package Model.stmt;

import Exceptions.AssignmentTypesException;
import Exceptions.NotDeclaredVariable;
import Model.adt.IDict;
import Model.adt.IStack;
import Model.exp.Exp;
import Model.programState.PrgState;
import Model.types.Type;
import Model.values.Value;

public final class AssignStmt implements IStmt {
    public final String id;
    public final Exp expression;

    public AssignStmt(String id, Exp expression)
    {
        this.id = id;
        this.expression = expression;
    }

    public String toString() {
        return id+" = " + expression.toString() + ";\n";
    }

    @Override
    public PrgState execute(PrgState state) throws Exception {
        IStack<IStmt> exeStack = state.getExeStack();
        IDict<String, Value> symTable = state.getSymTable();
        var heap = state.getHeap();

        if(symTable.isDefined(id)) {
            Value val = expression.eval(symTable, heap);
            Type typeId = (symTable.lookup(id)).getType();
            if(val.getType().equals(typeId)) {
                symTable.update(id, val);
            }
            else
                throw new AssignmentTypesException("The declared type of variable and the type of the assignment do not match");
        }
        else
            throw new NotDeclaredVariable("The variable was not declared");

        return null;
    }

    public IDict<String, Type> typecheck(IDict<String, Type> typeEnv) throws Exception{
        Type typevar = typeEnv.lookup(id);
        Type typexp = expression.typecheck(typeEnv);
        if(typevar != null)
            if (typevar.equals(typexp))
                return typeEnv;
            else
                throw new AssignmentTypesException("Assignment: right hand side and left hand side have different types ");

        return typeEnv;
    }
}
