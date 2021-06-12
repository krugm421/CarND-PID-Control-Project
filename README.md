# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
### Summary

Goal of this project was to implement the longitudinal and lateral control for a car to follow the reference line of a track at a given speed.

### Control scheme

For both the longitudinal control (or speed control) and the lateral control (or steering control) a PID is used. For implementing the PID controller I used the given PID class (PID.cpp, PID.h) with some minor modifications. The control algorithm is identical to the python based implementation presented in the lectures.

The lateral controller uses the cross track error as input and produces the correcting steering command. 

For longitudinal control, the difference between a constant speed set point a the actual speed is used to produce the throttle command.

### Controler tuning 

For the determination of the P, I and D controller parameters a huge number of approaches exist in practical control engineering and literature. For the classical text book approaches like root locus analysis, a sufficiently good model for the dynamics of the system would be required, which we do not have. Other heuristic or optimization based approaches include the Ziegler–Nichols method, the twiddle algorithm from the lectures or manual parameter tuning.

I decided to manually tune the parameters considering the tendencies each parameter has to the closed-loop dynamics which helped me to get a good intuition on the effect of each parameter.

* Increase in P (proportional) gain
  * Faster rise, proportional to the control error
  * Increased tendency to overshoot
* Increase in D (differential) gain
  * Decreases tendency to overshoot 
* Increase in I (integral) gain
  * Reduces steady-state control error

## Longitudinal controler tuning

I started with all parameters at 0, first increasing the P gain till I was able to reach the desired speed in roughly 3 seconds. After that I increased the D gain until I was satisfied with the oscillation and set the I gain to a relatively small value to ensure steady state accuracy. The parameters I ended up with are: 


* P_long - 10.0
* I_long - 0.0001
* D_long - 10.0

## Lateral controler tuning

For the steering control I used the same approach, however it took much more trail-and-error to reach good results where the vehicle keeps to the track and oscillations are at a satisfactory level.

I again started increasing the P gain until the vehicles cross track error was oscillation consistently while keeping the vehicle on track. After that I again increased the D gain until oscillations are at a minimum. I repeated steps 1 and 2 to ensuring that the control was stable, or to be precise, that the amplitude of the oscillation was not increasing. After that, I increased the I gain to eliminate any long-term control error. 

The parameters I used are:

* P_lat - 0.1
* I_lat - 0.002
* D_lat - 1.0

With this parameter set, the controller is able to keep the vehicle on-track at a speed set point of 30 mph.

## Results at 50 mph

With the parameter set, it was initially not possible to follow the track at 50 mph. My observation was that especially in the steep curves after the bridge, the steering angle was intuitively too low. Increasing the I gain to  I_lat - 0.0035 helped to be able to handle those curves better.




