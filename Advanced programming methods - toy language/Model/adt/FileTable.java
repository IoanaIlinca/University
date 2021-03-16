package Model.adt;
import java.util.HashMap;
import java.util.Map.Entry;

public class FileTable<filename, Buffer> implements IFileTable<filename, Buffer> {
    HashMap<filename, Buffer> dictionary;

    public FileTable() {
        dictionary = new HashMap<filename, Buffer>();
    }

    public boolean isDefined(filename filename) {
        return dictionary.containsKey(filename);
    }

    @Override
    public HashMap<filename, Buffer> getDictionary() {
        return dictionary;
    }

    public Buffer lookup(filename filename) {
        return dictionary.get(filename);
    }

    public void set(filename filename, Buffer buffer) {
        dictionary.put(filename, buffer);
    }

    public void update(filename filename, Buffer buffer) {
        dictionary.put(filename, buffer);
    }

    @Override
    public void remove(filename filename) {
        dictionary.remove(filename);
    }

    @Override
    public String toString() {
        String returnValue = "";
        for (Entry<filename, Buffer> e : dictionary.entrySet()) {
            filename filename = e.getKey();
            returnValue += filename.toString() +"\n";
        }
        return returnValue;
    }
}
