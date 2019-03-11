import java.security.SecureRandom;

class DataSet {
    private SecureRandom random = new SecureRandom();
    private int[] dataArray;

    // defulat constructor.
    public DataSet() {
        // generate 10 random integers between 0 and 100.
        this(10, 0, 100);
    }

    public DataSet(int[] data) {
        dataArray = data;
    }

    // overloaded constructor.
    public DataSet(int size, int min, int max) {
        dataArray = new int[size];

        for (int i = 0; i < dataArray.length; i++) {
            dataArray[i] = min + random.nextInt(max - min + 1);
        }
    }

    // the getter method of dataArray.
    public int[] getDataArray() {
        return dataArray;
    }

    @Override
    public String toString() {
        String output = "";

        for (int element : dataArray) {
            output += Integer.toString(element) + " ";
        }

        return output;
    }
}

interface Sort {
    DataSet sort(DataSet ds);
}

// the method to sort the array's data using BubbleSort algorithm.
class BubbleSort implements Sort {
    public DataSet sort(DataSet ds) {
        boolean swapped = true;
        int[] dataArray = ds.getDataArray();

        while (swapped) {
            swapped = false;

            for (int i = 0; i < dataArray.length - 1; i++) {
                if (dataArray[i] > dataArray[i + 1]) {
                    // swap the numbers if they were put in wrong order.
                    swap(dataArray, i, i + 1);

                    // change the flag.
                    swapped = true;
                }
            }
        }
        return new DataSet(dataArray);
    }

    private void swap(int[] array, int i, int j) {
        int temp;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// the method to sort the array's data using SelectionSort algorithm.
class SelectionSort implements Sort {

    public DataSet sort(DataSet ds) {
        int[] dataArray = ds.getDataArray();

        for (int i = 0; i < dataArray.length - 1; i++) {
            int min = i;

            for (int j = i + 1; j < dataArray.length; j++) {
                if (dataArray[j] < dataArray[min]) {
                    min = j;
                }
            }
            swap(dataArray, i, min);
        }

        return new DataSet(dataArray);
    }

    private void swap(int[] array, int i, int j) {
        int temp;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

class InsertionSort implements Sort {

    public DataSet sort(DataSet ds) {
        int[] dataArray = ds.getDataArray();

        for (int j = 1; j < dataArray.length; j++) {
            int temp = dataArray[j];
            int i = j - 1;

            while (temp < dataArray[i]) {
                dataArray[i + 1] = dataArray[i];
                i -= 1;

                if (i == -1) {
                    break;
                }
            }

            dataArray[i + 1] = temp;
        }

        return new DataSet(dataArray);
    }
}

class Sorter {

    // private int[] dataArray;
    private DataSet ds;
    Sort sortAct;

    // default constructor.
    public Sorter() {
    }

    // overloaded constructor.
    public Sorter(DataSet d, Sort s) {
        ds = d;
        sortAct = s;
        // dataArray = d.getDataArray();
    }

    public DataSet sort() {
        return sortAct.sort(ds);
    }

    public DataSet getDataSet() { return ds; }
}

public class SortAlgorithm {

    public static void main(String[] args) {
        Sorter s;

        s = new Sorter(new DataSet(5, 0, 100), new BubbleSort());
        System.out.println("[*] Bubble Sort...");
        System.out.println("--> Source: " + s.getDataSet());
        System.out.println("--> Result: " + s.sort());
        System.out.println();

        s = new Sorter(new DataSet(5, 0, 100), new SelectionSort());
        System.out.println("[*] Selection Sort...");
        System.out.println("--> Source: " + s.getDataSet());
        System.out.println("--> Result: " + s.sort());
        System.out.println();

        s = new Sorter(new DataSet(5, 0, 100), new InsertionSort());
        System.out.println("[*] Insertion Sort...");
        System.out.println("--> Source: " + s.getDataSet());
        System.out.println("--> Result: " + s.sort());
        System.out.println();
    }
}
