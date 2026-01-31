# utrahacksteam2
UTRA Hacks 2026 Team 2

# Project Description
The robot must pick up a box which acts as an "entry key" to the different sections of the track. We will first attempt the **red** path, which is the obstacle course. After dropping off the box to enter the obstacle course, we will reupload code to the robot so that it can navigate the course and retrieve a new box at the end. After picking up the new box, the robotwill follow the red path to the end and turn when it sees the **green** path. Along the green path, there will be another point to drop off the box and reupload code. This reuploaded code will make the robot climb up a *curved* or *straight* ramp. At the top of the ramp, the robot will be ***randomly stopped*** (wtf does this mean) on a raised platform. The robot must then follow coloured paths in the order of **blue**, **red**, and **green** to navigate to the **black** centre that has a ball. Upon reaching the centre, we will reupload code for the robot to shoot the ball towards the **blue** zone of the platform. After this, the robot will go back down the ramp and we will be finished. 

# Initial (Black Path)
The robot will go forward on the black path and pick up the box. After picking up the box, it will move forward until it detects **red**. It will then turn a measured number of degrees towards the right side of the red path. It will keep going forward on the red path to drop off the box. After dropping off the box, it will keep moving forward on the red path and reach the reupload point. At the reupload point, we will reupload coad for the Obstacle Course section.

# Obstacle Course (Red Path) + Transfer to Ramp Traversal (Green Path)
During this section, the robot must be able to:
- Follow a **red** path
- Make sharp turns
- Detect obstructions
- Navigate around obstructions
- Pick up a box
- Detect green
- Follow a green path
- Drop off a box

At the end of the green path, code will be reuploaded to the robot.

# Ramp Traversal (Black Path)
The robot will trace a brown path with a black line as a guide. If doing the straight ramp, the robot will only need to go straight and climb against gravity. If doing the curved ramp, the robot will need to turn as well while climbing. It will cross over a blue ring, then a red ring, then a green ring. It will stop when it lands on the black square in the centre. When it reaches this point, the code will be reuploaded. 

# Target Shooting (Raised Platform)
The robot will pick up the ball. The robot can either launch or shoot the ball after picking it up. It should aim for the blue ring, which is behind the green ring and the red ring. The ball should be as close to the blue zone as possible and cannot bounce or hit walls. 

# Essential Functions
- Move forward
- Turn right
- Turn left
- Pick up box
- Drop box
- Pick up ball
- Shoot/launch ball
- Detect obstructions
