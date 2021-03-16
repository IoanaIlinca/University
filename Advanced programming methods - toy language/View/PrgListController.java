package View;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;

public class PrgListController {
    @FXML
    private ListView statementListView;

    @FXML
    private ObservableList<Command> statementObservableList=null;

    public void setStatementObservableList(ArrayList<Command> statements)
    {
        statementListView.setItems(FXCollections.observableArrayList(statements));
    }


    @FXML
    public void handleMouseClick(javafx.scene.input.MouseEvent mouseEvent)
    {
        Command command=((Command)statementListView.getSelectionModel().getSelectedItem());

        if(command instanceof ExitCommand)
        {
            command.execute();
        }
        else
        {
            try {
                Stage programStage = new Stage();
                Parent programRoot;
                FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("ProgramWindow.fxml"));
                fxmlLoader.setController(new PrgControllerGUI(((RunExample)command).getController()));
                programRoot = fxmlLoader.load();
                Scene programScene = new Scene(programRoot);
                programStage.setTitle("Toy Language - Program running");
                programStage.setScene(programScene);
                programStage.show();
            } catch (Exception e) {
                //System.out.println(e.getLocalizedMessage());
                System.out.println(e.getMessage());
            }
        }
    }
}
