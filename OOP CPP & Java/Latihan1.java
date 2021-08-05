import java.util.Scanner;

public class Latihan1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String line;

        line = input.nextLine(); // baca banyak data
        int n = Integer.parseInt(line);

        line = input.nextLine(); // baca n data
        String tmp[] = line.split(" ");

        int buff = 0, sum = 0, max = Integer.parseInt(tmp[0]);
        for (int i = 0; i < n; i++) {
            buff = Integer.parseInt(tmp[i]);
            if (buff > max)
                max = buff;
            sum += buff;
        }

        float avg = (float) sum / n;
        int count = 0;
        for (int i = 0; i < n; i++) {
            buff = Integer.parseInt(tmp[i]);
            if (buff > avg)
                count++;
        }
        System.out.println(max + " " + String.format("%.2f", avg) + " " + count);
        input.close();
    }
}
