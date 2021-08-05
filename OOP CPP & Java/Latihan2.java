import java.util.Scanner;

class Person {
    // property
    String nama;
    int usia, tinggi;
    double berat;

    // constructor
    Person() {
        this.nama = "";
        this.usia = 0;
        this.tinggi = 0;
        this.berat = 0.0;
    }

    // method
    public void setPerson(String nama, int usia, int tinggi, double berat) {
        this.nama = nama;
        this.usia = usia;
        this.tinggi = tinggi;
        this.berat = berat;
    }
}

public class Latihan2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String line;

        line = input.nextLine(); // baca banyak data
        int n = Integer.parseInt(line), sum = 0;

        Person person[] = new Person[n]; // deklarasi array of object
        for (int i = 0; i < n; i++) { // baca n data
            line = input.nextLine();
            String tmp[] = line.split(" ");

            String nama = tmp[0];
            int usia = Integer.parseInt(tmp[1]);
            int tinggi = Integer.parseInt(tmp[2]);
            double berat = Float.parseFloat(tmp[3]);

            person[i] = new Person(); // buat objek
            person[i].setPerson(nama, usia, tinggi, berat);

            sum += tinggi;
        }

        int count = 0;
        float avg = (float) sum / n;
        for (int i = 0; i < n; i++) {
            if (person[i].tinggi > avg)
                count++;
        }
        for (int i = 0; i < n; i++) {
            System.out.println(person[i].nama + " " + person[i].usia);
        }
        System.out.println(String.format("%.2f", avg) + " " + count);
        input.close();
    }
}