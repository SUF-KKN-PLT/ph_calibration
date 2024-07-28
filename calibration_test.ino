const int potPin=4;
float ph;
float Value=0;
int counter = 0; // Variabel untuk menghitung jumlah data
bool programRunning = true; // Variabel flag untuk status program

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin,INPUT);  
  delay(1000);
}

void loop(){
  if (programRunning) { // Periksa apakah program masih berjalan
    int Value = analogRead(potPin);
    float ph_value = -0.0056*Value + 21.927;//masukkan nilai analog persamaan regresi sebagai nilai pengukuran hasil kalibrasi
    Serial.println(ph_value);
//    Serial.print(" | ");
    float voltage=Value*(3.3/4095.0);
    ph=(3.3*voltage);
//    Serial.println(voltage);
    
    counter++; // Hitung jumlah data yang ditampilkan

    if (counter >= 10000) { // Periksa apakah sudah mencapai 1000 data
      programRunning = false; // Hentikan program
//      Serial.println("Program selesai.");
    }
    delay(100);
  }
}
