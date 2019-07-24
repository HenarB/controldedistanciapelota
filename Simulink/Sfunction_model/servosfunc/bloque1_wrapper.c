
/*
 * Include Files
 *
 */
#include "simstruc.h"



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

#ifndef MATLAB_MEX_FILE

#include "Arduino.h"

const int sensor_pin = 15;

//buffer circular
#define sample_num 10
int sample_array[sample_num];
int sample_array_sum = 0;


#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */

extern long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void bloque1_Outputs_wrapper(real_T *dist1,
			const real_T *xD,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//Emular loop en el estado 1

if (xD[0] == 1){
     
    #ifndef MATLAB_MEX_FILE
    
    // ************ Procesar señal del Sensor de Distancia ************
          
      
      sample_array_sum -= sample_array[0];
      // shift circular buffer as FIFO
      for(int i=1; i<sample_num; i++) 
      {
        sample_array[i-1] = sample_array[i];
      }
      sample_array[sample_num-1] = analogRead(sensor_pin);
      sample_array_sum += sample_array[sample_num-1];
      
      
      // lectura del sensor
      
      float ADC_mean_value = sample_array_sum / sample_num;
      float estimated_voltage = ADC_mean_value * (3.3 / 1024);
      // input = f(voltage) polynomial regression based on the following empirical values
      // distance [cm]: 45, 40,35, 30, 25, 20, 15, 10, 5
      // voltage [v]: 0.486, 0.564, 0.643, 0.783, 0.939, 1.21, 1.575, 2.202, 3.0
      // R-squared = 0.9997
   
      float dist = 1.2502 * pow(estimated_voltage, 6) 
               - 16.396 * pow(estimated_voltage, 5) 
               + 84.983 * pow(estimated_voltage, 4) 
               - 225.46 * pow(estimated_voltage, 3) 
               + 330.80 * pow(estimated_voltage, 2) 
               - 272.10 * estimated_voltage 
               + 120.72;
      
      //Limitador de distancia
      if (dist < 7){
        dist = 7;
      }
      dist1[0] = dist;
    
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void bloque1_Update_wrapper(real_T *dist1,
			real_T *xD,
			SimStruct *S)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
*/

if (xD[0] == 0) {
     
    #ifndef MATLAB_MEX_FILE
  
    pinMode(sensor_pin, INPUT);
    analogReference(3.3);
      
      // inicializar buffer circular
      for(int i=0; i<sample_num; i++) 
      {
        sample_array[i] = analogRead(sensor_pin);
        sample_array_sum += sample_array[i];
        delay(60); // intervalo de medida del sensor
      }
    
    #endif

    xD[0] = 1;

}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

