    ##-- Ball & Beam control using Simulink-Arduino --##

This files are intended to be used for educational purpuse.

* Arduino code for the IR distance sensor
* Simulink blocks for modeling:
   * S-function model
   * Predefined blocks model
* 3D STL files
* Drawings

The goal of this project is to stabilize a ball on a beam at the desired distance 
by implementing a discrete PID controller to the system. This will be tested with
two models:
* Model with a custom S-function builder block
* Model with predefined blocks

Arduino code is implemented in a Simulink model by using a custom s-function builder block. 
 
        ##-- Requirements --##
To run this model, you'll need:
* Arduino, v. 1.8.5 or higher
* MATLAB v. 2018a or higher, the Arduino toolbox add-on needs to be installed
* 3D printer

        ##-- Credits --##
* Project author: Henar Brenlla
* EIB (UPV/EHU)

        ##-- Renders --##

![KS®4852419561 15](https://user-images.githubusercontent.com/53175202/61654487-c7f40d00-acbc-11e9-86dd-81b4fa892318.png)

![KS®4852419561 17](https://user-images.githubusercontent.com/53175202/61654497-ccb8c100-acbc-11e9-9cc8-ee241b75b6c0.png)

![KS®4852419561 16](https://user-images.githubusercontent.com/53175202/61654489-c9253a00-acbc-11e9-90aa-687ac9240cd6.png)

        ##-- Operational diagram of the system --##

![diagrama_completo](https://user-images.githubusercontent.com/53175202/61696443-a5eaa100-ad35-11e9-925f-747e1f3a3647.png)

        ##-- How does the system run in Arduino-Simulink? --##

![modo de trabajo (4)](https://user-images.githubusercontent.com/53175202/61696457-a84cfb00-ad35-11e9-9698-b1de3b6a1e25.png)
