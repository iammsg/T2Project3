# PID Controller Project

#### Overview
This repository contains all the code needed to implement a PID (Proportional Integratal Derivative) Controller which works with the Udacity car simulator. The PID controller allows a car to drive autonomously around the track while automatically correcting the steering angle given a CTE, the cross track error value.

#### Compiling the Code
The seed repo (https://github.com/udacity/CarND-PID-Control-Project) that Udacity provides has the necessary framework for the repository. For a successful build:

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

A successful run will show that it is listening on the WebSocket port for the Udacity Simulator.

#### Code Implementation
Most of the code in this repository comes from translating the python code covered in the course to C++. In this particular scenario, the CTE was calculated from messages from the simulator. The code then calculates the error values for the PID and predicts the steering value based on these errors. This is done using the following formula:

<a href="https://www.codecogs.com/eqnedit.php?latex=Steering&space;Angle&space;=&space;-K_p&space;*&space;CTE&space;-&space;K_d&space;*&space;\frac{\partial&space;CTE}{\partial&space;t}&space;-&space;K_i&space;*&space;\Sigma{CTE}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Steering&space;Angle&space;=&space;-K_p&space;*&space;CTE&space;-&space;K_d&space;*&space;\frac{\partial&space;CTE}{\partial&space;t}&space;-&space;K_i&space;*&space;\Sigma{CTE}" title="Steering Angle = -K_p * CTE - K_d * \frac{\partial CTE}{\partial t} - K_i * \Sigma{CTE}" /></a>

In our implmentation, we also included logic to specify the throttle value. The logic is simple: use a low throttle value for high steering angles and a high throttle value for low steering angles. This was an intuitive step considering real life experience.

#### Tuning the Co-effecients
To begin, we used the same values as provided in the lecture:
```
K_p (Proportional Co-effecient) = 0.2
K_i (Integral Co-effecient) = 0.004
K_d (Differential Co-effecient) = 3.0
```
These set of values already gave me a functioning PID controller that can drive autonomously around the track safely. A video of the same can be found [here](./movies/final_lap.mp4).

The next step was to try tuning these values and what the effect of variation was on each of these. The integral co-effecient($K_i$) here is probably the most sensitive to change where even a unitary change can cause a relatively stable car to oscillate and even go out of track, as is evidenced by this [screen capture](./movies/change_in_ki.mp4). The proportional co-effecient($K_p$) was next in terms of sensitivity where incrementing the variable would cause large oscillations particularly during curves where the steering angle needs to change significantly, as is evidenced by this [screen capture](./movies/change_in_kp.mp4). Lastly, the differential co-effecient ($K_d$) is not as sensitive a knob as the other two. Large changes of this parameter yields smaller variation in the overall path of the car. The effect of this can be seen when the car goes around curves, where a wrong value can cause the car to 'jerk' to the right path rather vigorously, as is evidenced by this [screen capture](./movies/change_in_kd.mp4).

#### Code Improvements
There are a host of improvements that can be implemented to the code to make it more robust. A few of these are:
1. Implement a twiddle algorithm, to improve on the co-effecients more realtime to make the drive smoother.
2. Better throttle control. Currently the code uses static cutoffs and throttle values for car motion. This could be made dynamic by perhaps incorporating a more formulaic approach.

These were created in accordance to the [project rubric](https://review.udacity.com/#!/rubrics/1972/view)
