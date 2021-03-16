package Model.adt;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class LockTable<Integer, Value> implements ILock<Integer, Value> {
    private HashMap<Integer, Value> lock;

    public LockTable() {synchronized(this){
        lock = new HashMap<Integer, Value>();
    }}

    @Override
    public HashMap<Integer, Value> getLock() {synchronized(this){
        return lock;
    }}

    @Override
    public Map<Integer, Value> getContent() {synchronized(this){
        return lock.entrySet().stream()
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }}

    @Override
    public void setContent(HashMap<Integer, Value> h) {synchronized(this){
        lock = h;
    }}



    public LockTable(HashMap<Integer, Value> lock) {synchronized(this){
        this.lock = lock;
    }}

    public int getFreeAddress() {synchronized(this) {
        return lock.size() + 1;
    }}

    @Override
    public void add(Integer key, Value value) {synchronized(this) {
        lock.put(key, value);
    }}

    @Override
    public void update(Integer key, Value value) {synchronized(this) {
        lock.put(key, value);
    }}

    @Override
    public Value lookup(Integer key) {synchronized(this) {
        return lock.get(key);
    }}

    @Override
    public boolean isDefined(Integer key) {synchronized(this) {
        return lock.containsKey(key);
    }}

    @Override

    public String toString() {synchronized(this)  {
        String returnValue = "";
        for (Map.Entry<Integer, Value> e : lock.entrySet()) {
            Integer key = e.getKey();
            Value v = e.getValue();
            returnValue += key.toString() + ' ' + v.toString() +"\n";
        }
        return returnValue;
    } }
}
