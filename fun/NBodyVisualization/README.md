# Compile
```make```

# Customize

Any input should work. distances on the scale of 10^-3 - 10^-4 begin to have issues.
Use astronomically normal masses, distances, and velocities.
Edit the in.txt file using the conventions stated in the eample file
Units are in AU, Solar masses, and years

# Execute Simpulation
```./sim.out```
```./sim.out <input>```
```./sim.out <input> <output>```

#Visualize
Open NBodySimulation.pde in Processing and execute

# Input File

## Layout
```
Elapsed_Time
Time Step
id,mass,x,y,z,vx,vy,vz
```

## Example
```
100
.001
0,1,0,0,0,0,0,0
1,.000000165,.387098,0,0,0,-9.9909914977,0
2,.000002448,-.723332,0,0,0,7.3874524355,0
3,.000003003,1.00000,0,0,0,-6.2831853071,0
4,.000000321,-1.52367,0,0,0,5.0790317615,0
5,.000955109,5.20260,0,0,0,-2.7571103178,0
6,.000285809,-9.55490,0,0,0,2.0441009166,0
```

Do not leave a new line at the end of the input file! It will cause the program to crash.
