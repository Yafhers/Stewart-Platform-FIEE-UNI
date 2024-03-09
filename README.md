# Clasificador de Objetos sobre una Plataforma de Stewart 🐲

Una plataforma de Stewart es un robot en paralelo que posee una plataforma sujeta por 6 varillas (actuadores prismáticos) las cuales están unidas a servomotores. Las varillas colocadas en la placa superior se pueden mover en los seis grados de libertad en los que es posible mover un cuerpo libremente suspendido. Estos son los tres movimientos lineales x, y, z (lateral, longitudinal y vertical), y las tres rotaciones (x,y,z) .

El objetivo de este proyecto es implementar un <span style="color:blue; font-weight:bold;">clasificador de objetos</span>, pero a diferencia de otros proyectos tenemos el reto de lograr clasificar objetos mediante una Plataforma de Stewart, lo cual nos conlleva a una investigación sobre tecnicas de control y algoritmos de reconocimiento de imágenes.

![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/FirstDesign.png)

## Aplicaciones 🚀

* Medicina: Existe un amplio catálogo de prototipos utilizados en laboratorios como robots de asistencia en varios tipos de cirugías. Más allá de la cirugía, es posible encontrar este tipo de robots para aplicaciones de rehabilitación, principalmente del tobillo, donde sí se puede ver algún prototipo comercial.

* CNC: Otra de las aplicaciones más extendidas de estos robots es en CNC de alta velocidad, donde, para el mecanizado de materiales tradicionales de elevada dureza, los robots paralelos pueden llegar a mejorar las prestaciones de los robots serie.

* Pick and Place: Muchas de las grandes empresas de robots industriales incorporan en sus catálogos varios robots paralelos de entre 3 y 6 grados de libertad (Figura 3) para su uso en industrias relacionadas con el embalaje, empaquetado, almacenaje, ensamblaje, etc.

* Simuladores de Vuelo: Una de las primeras aplicaciones fue presentada en 1967 por Mr. Stewart el cual realizo una plataforma que serviría como entrenamiento para los primeros pilotos de ese entonces. Se coloca una cabina real de un avión permitiendo que esta tenga los mismos movimientos que tendría un avión real, permitiendo al piloto tener una experiencia más real e inmersiva del comportamiento del avión

* Simuladores de autos: Debido a que tiene 6 grados de libertad puede simular el movimiento de cualquier automóvil o trasbordador espacial al igual que los simuladores de vuelo.

* Celdas Solares: Debido a la movilidad de esta plataforma se puede implementar para auto posicionar las celdas solares y de esa manera obtener la mayor cantidad de luz posible.

* Otras aplicaciones: En la actualidad también se usan plataformas de Stewart en campos como la ubicación de telescopios y antenas parabólicas, y podría tener muchos mas usos debido a su versatilidad y libertad de movimiento.

## Materiales 👻

* Servos MG90
* ESP32
* PCA9685
* Batería Lipo 7.4v
* Soporte para ESP32
* AMB82 Mini Camera

![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/FirstDesign.png)

## Respecto a la Camara 🎲

El motivo de usar una camara en nuestro proyecto es porque queremos situar la camara por encima de la plataforma para que esta detecte la posición exacta del objeto que se encuentre sobre la plataforma, y además de eso tambien detectar que objeto se encuentra sobre la plataforma. Dependiendo del tipo de objeto la plataforma se inclinará a uno de los lados para de esa manera enviar el objeto a su contenedor respectivo para así lograr clasificar los objetos.

![Texto alternativo](https://github.com/Yafhers/Stewart-Platform-FIEE-UNI/blob/main/Stewart%20Platform%20FIEE%20UNI/Images/FirstDesign.png)

## Autores ✒️

Entre las personas que estamos desarrollando el proyecto estamos:

* **Yafhers Mendoza** - *Líder del Equipo* - [yafhers](https://www.linkedin.com/in/yafhers-alonso-mendoza-c%C3%A9spedes-793655268/)
* **Eliceo Ocampo** - *Integrante del Equipo* - [eliceo](https://www.linkedin.com/in/ocampo-ccoicca-eliceo-5b42a2221/)
* **Alejandro Pacheco** - *Integrante del Equipo* - [alejandro](#fulanito-de-tal)
* **Adrian Burga** - *Integrante del Equipo* - [adrian](#fulanito-de-tal)
* **Daniel Cuaresma** - *Integrante del Equipo* - [daniel](#fulanito-de-tal)

## Licencia 📄

Este proyecto está bajo la Licencia (Tu Licencia) - mira el archivo [LICENSE.md](LICENSE.md) para detalles

## Expresiones de Gratitud 🎁

* Comentanos algo sobre el proyecto o si tienes alguna sugerencia 📢
* Invita un café ☕ a alguien del equipo. 
* Escribenos al correo para cualquier consulta sobre el proyecto 🤓
* Correo: yafhers.mendoza.c@uni.pe ✉

---
⌨️ con ❤️ por [Yafhers](https://github.com/Yafhers) 😊
