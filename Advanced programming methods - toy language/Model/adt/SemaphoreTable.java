package Model.adt;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class SemaphoreTable<Integer, Value> implements ISemaphore<Integer, Value> {
    private HashMap<Integer, Value> semaphore;

    public SemaphoreTable() {synchronized(this){
        semaphore = new HashMap<Integer, Value>();
    }}

    @Override
    public HashMap<Integer, Value> getSemaphore() {synchronized(this){
        return semaphore;
    }}

    @Override
    public Map<Integer, Value> getContent() {synchronized(this){
        return semaphore.entrySet().stream()
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }}

    @Override
    public void setContent(HashMap<Integer, Value> h) {synchronized(this){
        semaphore = h;
    }}



    public SemaphoreTable(HashMap<Integer, Value> semaphore) {synchronized(this){
        this.semaphore = semaphore;
    }}

    public int getFreeAddress() {synchronized(this) {
        return semaphore.size() + 1;
    }}

    @Override
    public void add(Integer key, Value value) {synchronized(this) {
        semaphore.put(key, value);
    }}

    @Override
    public void update(Integer key, Value value) {synchronized(this) {
        semaphore.put(key, value);
    }}

    @Override
    public Value lookup(Integer key) {synchronized(this) {
        return semaphore.get(key);
    }}

    @Override
    public boolean isDefined(Integer key) {synchronized(this) {
        return semaphore.containsKey(key);
    }}

    @Override

    public String toString() {synchronized(this)  {
        String returnValue = "";
        for (Map.Entry<Integer, Value> e : semaphore.entrySet()) {
            Integer key = e.getKey();
            Value v = e.getValue();
            returnValue += key.toString() + ' ' + v.toString() +"\n";
        }
        return returnValue;
    } }
}
