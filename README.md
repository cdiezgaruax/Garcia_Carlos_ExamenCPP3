# Garcia\_Carlos\_ExamenCPP3

**Link:** [https://github.com/cdiezgaruax/Garcia_Carlos_ExamenCPP3/tree/main](https://github.com/cdiezgaruax/Garcia_Carlos_ExamenCPP3/tree/main)

## Condiciones de Entrega del Examen de Programación en C++

Estimado estudiante,

Para garantizar una correcta evaluación de tus habilidades y entendimiento en la programación en C++, hemos establecido un conjunto de condiciones que deberás seguir al momento de entregar tus respuestas al examen. La estructura y presentación de tu entrega son esenciales para facilitar el proceso de corrección y asegurarnos de que hemos evaluado todos tus esfuerzos de manera justa.

### Instrucciones para la entrega:

#### Repositorio en GitHub:

- Todo tu trabajo debe estar contenido en un repositorio en GitHub.
- Asegúrate de que el repositorio sea privado al inicio, y podrás hacerlo público después de que finalice el período de revisión del examen (si así lo deseas).

#### Fichero ZIP:

- Una vez hayas terminado de resolver el examen, crea un archivo ZIP de todo el repositorio.
- El nombre del archivo ZIP debe seguir el formato: Apellido_Nombre_ExamenCPP.zip (reemplaza Apellido y Nombre con tu apellido y nombre respectivamente).

#### Fichero README.md:

Dentro de tu repositorio, debes incluir un archivo README.md. Este archivo debe contener:
- El link directo a tu repositorio de GitHub.
- Una descripción breve de cada uno de los ejercicios resueltos, con referencias a los archivos o carpetas específicos donde se puede encontrar cada solución.
- El uso adecuado de Markdown en tu README.md para estructurar y formatear el contenido será valorado positivamente.

### Envío:

- Entrega el archivo ZIP a través de la plataforma o método que se te indique (por ejemplo, un sistema de gestión de aprendizaje, correo electrónico, etc.).
- Asegúrate de enviar tu trabajo antes de la fecha y hora límite. Las entregas fuera de plazo pueden no ser evaluadas o incurrir en penalizaciones.

### Otros aspectos a considerar:

- Asegúrate de que tu código esté bien comentado, organizado y que sea fácil de leer y entender.
- Si utilizas alguna referencia externa para resolver algún ejercicio, es esencial que lo cites en tu README.md.

Siguiendo estas condiciones y presentando tu trabajo de manera organizada, nos ayudarás a llevar a cabo un proceso de revisión más eficiente. Deseamos que demuestres todo tu conocimiento y habilidades en este examen. ¡Buena suerte!

---

## Bienvenidos a este reto práctico de algoritmos

En este ejercicio, pondrán a prueba sus habilidades para planificar y optimizar recursos bajo un escenario realista de alta presión.

### Enunciado del Problema:

Ustedes son Project Managers en una empresa internacional. Reciben una llamada urgente de un alto ejecutivo, informándoles que el CEO de la compañía ha aterrizado en Barcelona desde Estados Unidos y tiene una reunión crucial para las 19:30 en la ciudad. Sin embargo, el ejecutivo cuenta con solo 100 minutos antes de que cierre la facturación para su vuelo desde Madrid a Barcelona.

**Objetivo:** Debido a la urgencia de la situación, necesitan optimizar las tareas para cumplir con el objetivo de que el ejecutivo llegue a la reunión a tiempo. A continuación se detalla la lista de tareas necesarias, sus descripciones y las duraciones de cada una. Su misión es identificar las dependencias entre las tareas, calcular el tiempo total para completar las tareas en el orden adecuado, y determinar si es posible cumplir con el plazo de 100 minutos.

### Tareas, Descripciones y Duraciones:

- **A:** Reserva de vuelo (20 min)
- **B:** Informar a casa para empacar (5 min)
- **C:** Empacar maletas (40 min)
- **D:** Preparación del billete por la agencia (10 min)
- **E:** Recoger el billete de la agencia (5 min)
- **F:** Llevar el billete a la oficina (10 min)
- **G:** Recoger las maletas de casa (20 min)
- **H:** Llevar maletas a la oficina (25 min)
- **I:** Conversación sobre documentos requeridos (35 min)
- **J:** Dictar instrucciones para ausencia (25 min)
- **K:** Reunir documentos (15 min)
- **L:** Organizar documentos (5 min)
- **M:** Viajar al aeropuerto y facturar (25 min)

### Dependencias entre tareas:

- Algunas tareas deben ser realizadas antes que otras, por ejemplo, no se puede viajar al aeropuerto antes de haber recogido las maletas.
- Además, la reserva del vuelo debe completarse antes de recoger el billete, y la preparación del billete debe ocurrir antes de llevar el billete a la oficina.

### Objetivos del Reto:

- **Definir el Objetivo del Proyecto:** Identificar el propósito principal del proyecto (optimizar la gestión del tiempo para cumplir con el plazo de 100 minutos) y no solo las tareas.
- **Diagrama de Flujo del Cronograma:** Crear un diagrama de flujo para visualizar el cronograma del proyecto, teniendo en cuenta solo las dependencias entre tareas y no restricciones de recursos.

### Desarrollo de Algoritmo en C++:

- Crear un programa en C++ que permita calcular el orden de ejecución de las tareas en función de sus dependencias.
- Determinar el tiempo total necesario para completar todas las tareas.
- Evaluar si es posible completar las tareas en 100 minutos o menos.
- Imprimir el orden óptimo de ejecución de las tareas y su tiempo total.

### Restricciones:

- El tiempo máximo permitido para completar las tareas es de 100 minutos.
- El algoritmo debe gestionar de forma eficiente las dependencias entre las tareas, de tal manera que optimice el tiempo de ejecución.

### Entrega:

- Código fuente en C++ que implemente la solución al problema.
- Diagrama de flujo que represente el cronograma de ejecución de las tareas.

¡Buena suerte y que la optimización esté de su lado!