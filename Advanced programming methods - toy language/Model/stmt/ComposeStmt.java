package Model.stmt;

import java.util.ArrayList;

public final class ComposeStmt
{
    public static IStmt compose(ArrayList<IStmt> statements) {
        if (statements.size() == 0) return new NoOperationStmt();
        IStmt statement = statements.get(statements.size() - 1);
        for (int index = statements.size() - 2; index >= 0; index--)
            statement = new CompStmt(statements.get(index), statement);
        return statement;
    }
}
