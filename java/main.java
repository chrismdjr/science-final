import java.util.Arrays;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Quicksort {
  static int partition(int array[], int low, int high) {
    
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {
        i++;

        int newArray = array[i];
        array[i] = array[j];
        array[j] = newArray;
      }

    }

    int newArray = array[i + 1];
    array[i + 1] = array[high];
    array[high] = newArray;

    return (i + 1);
  }

  static void quickSort(int array[], int low, int high) {
    if (low < high) {
      int pivot = partition(array, low, high);
      
      quickSort(array, low, pivot - 1);
      quickSort(array, pivot + 1, high);
    }
  }
}

class Main {
    static int[] data;

    public static void main(String args[]) {
        System.out.println("Opening data.csv...");

        try {
            File dataObj = new File("../data.csv");
            Scanner dataReader = new Scanner(dataObj);
            while (dataReader.hasNextLine()) {
                String line = dataReader.nextLine();
                data = Arrays.stream(line.split(",")).mapToInt(Integer::parseInt).toArray();  
            }

            dataReader.close();
        }
        
        catch (FileNotFoundException e) {
            System.out.println("You must run generate_dataset.py to generate a dataset.");
            return;
        }

        int size = data.length;

        System.out.println("[RUNNING IN JAVA] Sorting unsorted dataset of " + size + " integers...");
        long benchmarkStart = System.currentTimeMillis();

        Quicksort.quickSort(data, 0, size - 1);
        System.out.println("Sorted array in " + String.format("%.5g%n", Float.valueOf(System.currentTimeMillis() - benchmarkStart) / 1000).trim() + "s.");
    }
}