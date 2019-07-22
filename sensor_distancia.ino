#include <math.h>
#include <arduino.h>


const int sensor_pin = 15;
const int num_muestra = 10;
int array_muestra[num_muestra]; // buffer circular
int array_muestra_sum = 0;
double dist_previa = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  
  // Inicialización
  pinMode(sensor_pin, INPUT);
  analogReference(3.3);

  // Inicializar buffer circular
  for(int i=0; i<num_muestra; i++) {
    long muestra = analogRead(A15);
    array_muestra[i] = muestra;
    array_muestra_sum += array_muestra[i];
    delay(60); // Tiempo de lectura del sensor
  }
}

void loop() {

    array_muestra_sum -= array_muestra[0];
    // Buffer circular como FIFO
    for(int i=1; i < num_muestra; i++) {
        array_muestra[i-1] = array_muestra[i];
    }
    
    array_muestra[num_muestra-1] = analogRead(sensor_pin);
    array_muestra_sum += array_muestra[num_muestra-1];

    float ADC_valor = array_muestra_sum / array_muestra;
    float voltaje_estimado = ADC_valor * (3.3 / 1024); 
    
  // input = f(voltaje) regresión polinómica de orden 6 según datos:
  // distancia [cm]: 45, 40,35, 30, 25, 20, 15, 10, 5
  // voltaje [v]: 0.395, 0.512, 0.623, 0.779, 0.941, 1.182, 1.622, 2.202, 3.0
  // R^2 = 0.9999
  float input = 0.6945 * pow(voltaje_estimado, 6) 
               - 3.7828 * pow(voltaje_estimado, 5) 
               + 3.7846 * pow(voltaje_estimado, 4) 
               - 5.0294 * pow(voltaje_estimado, 3) 
               + 8.859 * pow(voltaje_estimado, 2) 
               - 56.587 * voltaje_estimado 
               + 65.642;
               
  //Filtro paso bajo
  float alpha = 0.5;
  float dist = (alpha * input) + (1-alpha) * dist_previa;
  dist_previa = dist;

      if (dist > 45){
        dist = 45;
      }
      else if (dist < 5){
        dist = 5;
      }
}
