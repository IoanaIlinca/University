package View;

import Controller.Controller;
import Model.programState.PrgState;
import Model.values.IntegerValue;
import Model.values.Value;
import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import org.javatuples.Pair;

import java.io.BufferedReader;
import java.util.HashMap;
import java.util.List;

public class PrgControllerGUI {
    Controller myController;
    @FXML
    Label nrPrgStates;
    @FXML
    Button runButton;
    @FXML
    TableView<HashMap.Entry<Integer, Value>> heapTable;
    @FXML
    TableColumn<HashMap.Entry<Integer,Integer>, String> heapTableAddress;
    @FXML
    TableColumn<HashMap.Entry<Integer,Value>, String> heapTableValue;
    @FXML
    ListView<String> outList;
    @FXML
    TableView<HashMap.Entry<String, BufferedReader>> fileTable;
    @FXML
    TableColumn<HashMap.Entry<String, Integer>, String> fileTableIdentifier;
    @FXML
    TableColumn<HashMap.Entry<Integer, BufferedReader>, String> fileTableFileName;
    @FXML
    ListView<String> prgStateList;
    @FXML
    TableView<HashMap.Entry<String, Value>> symTable;
    @FXML
    TableColumn<HashMap.Entry<String, Value>, String> symTableVariable;
    @FXML
    TableColumn<HashMap.Entry<String, Value>, String> symTableValue;
    @FXML
    ListView<String> exeStackList;
    @FXML
    TableView<HashMap.Entry<Integer, Pair<IntegerValue, Model.adt.List<Integer>>>> semaphoreTable;
    @FXML
    TableColumn<HashMap.Entry<Integer, Pair<IntegerValue, Model.adt.List<Integer>>>, String> semaphoreTableAddress;
    @FXML
    TableColumn<HashMap.Entry<Integer, Pair<IntegerValue, Model.adt.List<Integer>>>, String> semaphoreTableValue;
    @FXML
    TableColumn<HashMap.Entry<Integer, Pair<IntegerValue, Model.adt.List<Integer>>>, String> semaphoreTableWaitingList;
    /*
    @FXML
    TableView<HashMap.Entry<Integer, Integer>> lockTable;
    @FXML
    TableColumn<HashMap.Entry<Integer,Integer>, String> lockTableAddress;
    @FXML
    TableColumn<HashMap.Entry<Integer,Integer>, String> lockTableValue;
    @FXML
    TableView<HashMap.Entry<Integer, Integer>> latchTable;
    @FXML
    TableColumn<HashMap.Entry<Integer,Integer>, String> latchTableAddress;
    @FXML
    TableColumn<HashMap.Entry<Integer,Integer>, String> latchTableValue;
    @FXML
    TableView<HashMap.Entry<Integer, Pair<Integer, java.util.List<Integer>>>> barrierTable;
    @FXML
    TableColumn<HashMap.Entry<Integer, Pair<Integer, java.util.List<Integer>>>, String> barrierTableAddress;
    @FXML
    TableColumn<HashMap.Entry<Integer, Pair<Integer, java.util.List<Integer>>>, String> barrierTableValue;
    @FXML
    TableColumn<HashMap.Entry<Integer, Pair<Integer, java.util.List<Integer>>>, String> barrierTableWaitingList;*/

    public PrgControllerGUI(Controller myController) {
        this.myController = myController;
    }

    public void initialize() {
        initialRun();
        prgStateList.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                setSymTableAndExeStack();
            }
        });
        runButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle (ActionEvent e) {
                try {
                    myController.allStepGUI();//allStepGUI
                } catch (RuntimeException e1) {
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Error");
                    alert.setHeaderText(null);
                    alert.setContentText("Error!" + e1.getMessage());
                    Button confirm = (Button) alert.getDialogPane().lookupButton( ButtonType.OK );
                    confirm.setDefaultButton(false);
                    confirm.setStyle("-fx-focus-color: transparent; -fx-faint-focus-color: transparent;");
                    alert.showAndWait();
                    Stage stage = (Stage) heapTable.getScene().getWindow();
                    stage.close();
                } catch (Exception e1) {
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Toy Language - Current program finished");
                    alert.setHeaderText(null);
                    alert.setContentText("Program successfully finished!");
                    Button confirm = (Button) alert.getDialogPane().lookupButton( ButtonType.OK );
                    confirm.setDefaultButton(false);
                    confirm.setStyle("-fx-focus-color: transparent; -fx-faint-focus-color: transparent;");
                    alert.showAndWait();
                    Stage stage = (Stage) heapTable.getScene().getWindow();
                    stage.close();
                }
                updateUIComponents();
            }
        });
    }

    public void initialRun() {
        setNumberLabel();
        setHeapTable();
        setOutList();
        setFileTable();
        setPrgStateList();
        setSemaphoreTable();
        //setLockTable();
        //setLatchTable();
        //setBarrierTable();
        prgStateList.getSelectionModel().selectFirst();
        setSymTableAndExeStack();
    }



    public void updateUIComponents() {
        setSymTableAndExeStack();
        setNumberLabel();

        setOutList();
        setFileTable();
        setHeapTable();
        setPrgStateList();
        setSemaphoreTable();
        //setLockTable();
        //setLatchTable();
        //setBarrierTable();
        if(prgStateList.getSelectionModel().getSelectedItem() == null) {
            prgStateList.getSelectionModel().selectFirst();
        }

    }
    /*
    private void setBarrierTable() {
        ObservableList<HashMap.Entry<Integer, Pair<Integer, java.util.List<Integer>>>> barrierTableList = FXCollections.observableArrayList();
        barrierTableAddress.setCellValueFactory(cellData -> new ReadOnlyStringWrapper(Integer.toString(cellData.getValue().getKey())));
        barrierTableWaitingList.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).getValue1().toString()));
        barrierTableValue.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).getValue0().toString()));
        if(myController.getProgramList().size()>0)
            //heapTableList.addAll((myController.getProgramList().get(0).getHeap().getHeap().entrySet()));
            for(var e : myController.getProgramList().get(0).getBarrierTable().getContent().entrySet())
            {
                //System.out.println(e.toString());
                //System.out.println("--------------------");
                barrierTableList.add(e);

            }

        barrierTable.setItems(barrierTableList);
        barrierTable.refresh();
    }

    private void setLatchTable() {
        ObservableList<HashMap.Entry<Integer, Integer>> latchTableList = FXCollections.observableArrayList();
        latchTableAddress.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getKey().toString())));
        latchTableValue.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).toString()));
        if(myController.getProgramList().size()>0)
            //lockTableList.addAll((myController.getProgramList().get(0).getlock().getlock().entrySet()));
            for(var e : myController.getProgramList().get(0).getLatch().getLatch().entrySet())
            {
                //System.out.println(e.toString());
                //System.out.println("--------------------");
                latchTableList.add(e);

            }

        latchTable.setItems(latchTableList);
        latchTable.refresh();
    }

    private void setLockTable() {
        ObservableList<HashMap.Entry<Integer, Integer>> lockTableList = FXCollections.observableArrayList();
        lockTableAddress.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getKey().toString())));
        lockTableValue.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).toString()));
        if(myController.getProgramList().size()>0)
            //lockTableList.addAll((myController.getProgramList().get(0).getlock().getlock().entrySet()));
            for(var e : myController.getProgramList().get(0).getLock().getLock().entrySet())
            {
                //System.out.println(e.toString());
                //System.out.println("--------------------");
                lockTableList.add(e);

            }

        lockTable.setItems(lockTableList);
        lockTable.refresh();
    }*/

    public void setNumberLabel() {
        nrPrgStates.setText("The number of PrgStates: " + myController.getProgramList().size());
    }

    public void setHeapTable() {
        ObservableList<HashMap.Entry<Integer, Value>> heapTableList = FXCollections.observableArrayList();
        heapTableAddress.setCellValueFactory(cellData -> new ReadOnlyStringWrapper(Integer.toString(cellData.getValue().getKey())));
        heapTableValue.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).toString()));
        if(myController.getProgramList().size()>0)
            //heapTableList.addAll((myController.getProgramList().get(0).getHeap().getHeap().entrySet()));
            for(var e : myController.getProgramList().get(0).getHeap().getHeap().entrySet())
            {
                //System.out.println(e.toString());
                //System.out.println("--------------------");
                heapTableList.add(e);

            }

        heapTable.setItems(heapTableList);
            heapTable.refresh();
    }

    public void setOutList() {
        ObservableList<String> outObservableList = FXCollections.observableArrayList();
        if(myController.getProgramList().size()>0)
            for(var e : myController.getProgramList().get(0).getOutputStream().getList()) {
                outObservableList.add(e.toString());
            }
        outList.setItems(outObservableList);
    }

    public void setFileTable() {
        ObservableList<HashMap.Entry<String, BufferedReader>> fileTableList = FXCollections.observableArrayList();
        fileTableIdentifier.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getKey()).toString()));
        fileTableFileName.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).toString()));
        if(myController.getProgramList().size()>0)
        {
            fileTableList.addAll(myController.getProgramList().get(0).getFileTable().getDictionary().entrySet());
            fileTable.setItems(fileTableList);
        }
    }

    public void setPrgStateList() {
        ObservableList<String> prgStateIdList = FXCollections.observableArrayList();
        if(myController.getProgramList().size()>0)
            for(var e : myController.getProgramList()) {
                prgStateIdList.add(Integer.toString(e.getId()));
            }
        prgStateList.setItems(prgStateIdList);

    }

    public void setSymTableAndExeStack() {
        ObservableList<HashMap.Entry<String, Value>> symTableList = FXCollections.observableArrayList();
        ObservableList<String> exeStackItemsList = FXCollections.observableArrayList();
        symTableVariable.setCellValueFactory(cellData -> new ReadOnlyStringWrapper(cellData.getValue().getKey()));
        symTableValue.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).toString()));
        List<PrgState> allPrgs = myController.getProgramList();
        PrgState prgResult = null;
        for(var e : allPrgs) {
            if(e.getId() == Integer.parseInt(prgStateList.getSelectionModel().getSelectedItem())) {
                prgResult = e;
                break;
            }
        }
        if(prgResult != null) {
            symTableList.addAll(prgResult.getSymTable().getContent().entrySet());
            for(var e : prgResult.getExeStack().getStack()) {
                exeStackItemsList.add(0, e.toString());
            }
            symTable.setItems(symTableList);
            symTable.refresh();
            exeStackList.setItems(exeStackItemsList);
        }
    }

    public void setSemaphoreTable() {
        ObservableList<HashMap.Entry<Integer, Pair<IntegerValue, Model.adt.List<Integer>>>> semaphoreTableList = FXCollections.observableArrayList();
        semaphoreTableAddress.setCellValueFactory(cellData -> new ReadOnlyStringWrapper(Integer.toString(cellData.getValue().getKey())));
        semaphoreTableWaitingList.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).getValue1().getList().toString()));
        semaphoreTableValue.setCellValueFactory(cellData -> new ReadOnlyStringWrapper((cellData.getValue().getValue()).getValue0().toString()));
        if(myController.getProgramList().size()>0)
            //heapTableList.addAll((myController.getProgramList().get(0).getHeap().getHeap().entrySet()));
            for(var e : myController.getProgramList().get(0).getSemaphoreTable().getContent().entrySet())
            {
                //System.out.println(e.toString());
                //System.out.println("--------------------");
                semaphoreTableList.add(e);

            }

        semaphoreTable.setItems(semaphoreTableList);
        semaphoreTable.refresh();
    }

}

