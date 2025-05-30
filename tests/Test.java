package tests;
import java.util.Arrays;
import solutions.Solution;

public class Test {
    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }

    public static boolean compareArrays(int[] a, int[] b) {
        return Arrays.equals(a, b);
    }

    public static void main(String[] args) {
        int[][] inputs = {
            {8, 1, 2, 2, 3},
            {6, 5, 4, 8},
            {7, 7, 7, 7},
            {1},
            {0, 0, 0},
            {10, 5, 10, 5},
            {100, 50, 0},
            {2, 0, 1, 0, 2}
        };

        int[][] expecteds = {
            {4, 0, 1, 1, 3},
            {2, 1, 0, 3},
            {0, 0, 0, 0},
            {0},
            {0, 0, 0},
            {2, 0, 2, 0},
            {2, 1, 0},
            {3, 0, 2, 0, 3}
        };

        int passed = 0, failed = 0;

        for (int i = 0; i < inputs.length; i++) {
            int[] result = Solution.smallerNumbersThanCurrent(inputs[i]);

            System.out.println("Test Case " + (i + 1) + ":");
            System.out.print("Expected: ");
            printArray(expecteds[i]);
            System.out.print("Got:      ");
            printArray(result);

            if (compareArrays(result, expecteds[i])) {
                System.out.println("✅ Passed\n");
                passed++;
            } else {
                System.out.println("❌ Failed\n");
                failed++;
            }
        }

        System.out.println("Test Cases Passed: " + passed);
        System.out.println("Test Cases Failed: " + failed);
        System.out.println("Total Test Cases: " + (passed + failed));
    }
}
