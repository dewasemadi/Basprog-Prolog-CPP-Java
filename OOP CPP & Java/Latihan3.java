import java.util.*;

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

    // list of method
    public void setPerson(String nama, int usia, int tinggi, double berat) {
        this.nama = nama;
        this.usia = usia;
        this.tinggi = tinggi;
        this.berat = berat;
    }

    public String getNama() {
        return nama;
    }

    public int getUsia() {
        return usia;
    }

    public int getTinggi() {
        return tinggi;
    }

    public double getBerat() {
        return berat;
    }

    public double getIMT() {
        double t = (double) tinggi / 100;
        return berat / (t * t);
    }

    public String getStatusGizi() {
        if (this.getIMT() < 17.0)
            return "sangat kurus";
        else if (this.getIMT() < 18.5)
            return "kurus";
        else if (this.getIMT() < 25.0)
            return "normal";
        else if (this.getIMT() < 28.0)
            return "gemuk";
        else
            return "sangat gemuk";
    }

    public void print() {
        System.out.println(nama + " " + usia + " " + tinggi + " " + String.format("%.2f", berat));
    }
}

public class Latihan3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String line;

        line = input.nextLine(); // baca banyak data
        int n = Integer.parseInt(line), sum = 0;

        // nama yang sama ga bole masuk lagi boy., solusi pake map key = nama => unik
        // Daftar terurut berdasarkan nama orang secara alfabetik, kalo pake map auto
        // ascending key-nya
        TreeMap<String, Person> data = new TreeMap<String, Person>(); // map dengan value object

        for (int i = 0; i < n; i++) { // baca n data
            line = input.nextLine();
            String tmp[] = line.split(" ");

            String nama = tmp[0];
            int usia = Integer.parseInt(tmp[1]);
            int tinggi = Integer.parseInt(tmp[2]);
            double berat = Double.parseDouble(tmp[3]);

            Person person = new Person(); // buat objek
            person.setPerson(nama, usia, tinggi, berat);

            // lewati kalo ketemu nama yang sama
            if (!data.containsKey(nama)) {
                data.put(nama, person);
                sum += tinggi;
            }
        }

        int count = 0, n_sk = 0, n_k = 0, n_nor = 0, n_g = 0, n_sg = 0;
        double avg = (double) sum / data.size();
        for (Map.Entry<String, Person> entry : data.entrySet()) {
            if (entry.getValue().getTinggi() > avg)
                count++;
            if (entry.getValue().getStatusGizi() == "sangat kurus")
                n_sk++;
            if (entry.getValue().getStatusGizi() == "kurus")
                n_k++;
            if (entry.getValue().getStatusGizi() == "normal")
                n_nor++;
            if (entry.getValue().getStatusGizi() == "gemuk")
                n_g++;
            if (entry.getValue().getStatusGizi() == "sangat gemuk")
                n_sg++;
            System.out.print(entry.getKey() + " " + entry.getValue().getUsia() + " " + entry.getValue().getTinggi()
                    + " " + String.format("%.2f", entry.getValue().getBerat()) + " "
                    + String.format("%.2f", entry.getValue().getIMT()) + " " + entry.getValue().getStatusGizi() + "\n");
        }

        System.out.println(String.format("%.2f", avg));
        System.out.println(count);
        System.out.println(n_sk + " " + n_k + " " + n_nor + " " + n_g + " " + n_sg);
        input.close();
    }
}
