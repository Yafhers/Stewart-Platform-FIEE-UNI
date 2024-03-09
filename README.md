# Object Classifier on a Stewart Platform 🐲

A Stewart platform is a parallel robot that has a platform supported by 6 rods (prismatic actuators) which are attached to servomotors. The rods placed on the top plate can move in the six degrees of freedom in which it is possible to move a freely suspended body. These are the three linear movements x, y, and z (lateral, longitudinal and vertical), and the three rotations (x, y, and z).

The objective of this project is to implement an <span style="color:blue; font-weight:bold;">object classifier</span>, but unlike other projects we have the challenge of classifying objects using a Stewart Platform, which leads to an investigation of control techniques and image recognition algorithms.

![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/FirstDesign.png)

## Applications 🚀

* Medicine: There is a wide range of prototypes used in laboratories as assistance robots in various types of surgeries. Beyond surgery, it is possible to find this type of robots for rehabilitation applications, mainly of the ankle, where it is possible to see some commercial prototypes.

* Pick and Place: Many of the large industrial robot companies incorporate in their catalogs several parallel robots of between 3 and 6 degrees of freedom (Figure 3) for use in industries related to packaging, packing, warehousing, warehousing, assembly, etc.

* Flight Simulators: One of the first applications was presented in 1967 by Mr. Stewart who made a platform that would serve as training for the first pilots of that time. A real cockpit of an airplane is placed allowing it to have the same movements that a real airplane would have, allowing the pilot to have a more realistic and immersive experience of the airplane's behavior.

* Car Simulators: Because it has 6 degrees of freedom it can simulate the movement of any car or space shuttle just like the flight simulators.

* Solar Cells: Due to the mobility of this platform it can be implemented to auto position the solar cells to obtain the maximum amount of light possible.

## Materials 👻

* MG90 Servos
* ESP32
* PCA9685
* 7.4v Lipo battery
* Support for ESP32
* AMB82 Mini Camera

![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/AMB82Mini.png)

## About the Camera 🎲

The reason for using a camera in our project is because we want to place the camera above the platform so that it detects the exact position of the object that is on the platform, and in addition to that it also detects which object is on the platform. Depending on the type of object the platform will tilt to one of the sides to send the object to its respective container in order to classify the objects.
![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/CameraSupport.png)

## Our Progress 🎃

Our first meeting to assemble the base of Stewart's platform and set up the electronic circuit:

![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/1.jpg)

## The ABET fair 🎨

ABET, formerly known as the Accreditation Board for Engineering and Technology, is an organization that assesses and accredits educational programs in fields such as engineering and technology, ensuring the quality of education in these domains. The ABET fair serves as a platform where students, academics, professionals, and industries come together to share advancements, research, and innovative projects. Participation in this fair offers visibility, collaboration opportunities, and expert feedback, thus fostering innovation and progress within the discipline.

The ABET fair typically spans about a month, and our team has been preparing for two months, with a projected timeline of six months to complete and present our project.

## Authors ✒️

Among the people who are developing the project are:

* **Yafhers Mendoza** - *Team Leader* - [yafhers](https://www.linkedin.com/in/yafhers-alonso-mendoza-c%C3%A9spedes-793655268/)
* **Eliceo Ocampo** - *Team Member* - [eliceo](https://www.linkedin.com/in/ocampo-ccoicca-eliceo-5b42a2221/)
* **Alejandro Pacheco** - *Team Member* - [alejandro](#fulanito-de-tal)
* **Adrian Burga** - *Team Member* - [adrian](#fulanito-de-tal)
* **Daniel Cuaresma** - *Team Member* - [daniel](#fulanito-de-tal)

## Expressions of Gratitude 🎁

* Tell us something about the project or if you have any suggestions 📢
* Invite someone from the team for a coffee ☕. 
* Write us to the mail for any question about the project 🤓
* Mail: yafhers.mendoza.c@uni.pe ✉
  
---
⌨️ with ❤️ by [Yafhers](https://github.com/Yafhers) 😊
