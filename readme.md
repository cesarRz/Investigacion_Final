# Investigación Final
**Programación de Graficos**
<hr>

André Urruticoechea Pérez Mar.
Oscar Alexander Robles Braun.
César Román Zúñiga.

<hr>

## Estructura del proyecto

```
.
|____Server
| |____app.py
| |____templates
| | |____botones.html
| | |____giroscopio.html
|____semaforo.c
|____reciever.c
|____coordenadas.csv
|____semaforo

```

## Requisitos
- Python3
  - Flask
- C
  - OpenGl
  - GLut
- [ngrok](https://ngrok.com/)

<hr>

## Servidor de Flask

### Instalacion de modulos de python
Para el servidor solo se utilizo el modulo de Flask
```
pip install Flask
```

### Archivo `app.py`
Este archivo corre el servidor de flask. 
Estando en la carpeta `root` se utiliza el siguiente comando para que el peurto 5000 se abra y se inicialice el servidor

```
python3 Server/app.py
```

### Acelerometro
Se tomo como base un programa encontrado en el [Blog Medium](https://kongmunist.medium.com/accessing-the-iphone-accelerometer-with-javascript-in-ios-14-and-13-e146d18bb175) para leer los datos del acelerometro y se modelaron para que estos hicieran sentido con lo que se busca en la investigación.

## Puerto de ngrok

### Inslalacion de ngrok

[Instrucciones para la descarga e instalacion de ngrok](https://ngrok.com/download)


### Abrir puerto con ngrok

Para abrir el puerto publico por medio de ngrok, es necesario conocer el puerto en el que el servidor de Flask esta corriendo para hacerlo publico con el protocolo `http`. En nuestro caso es el puerto 5000.

```
ngrok http 5000
```

Se abre una ventana de la terminal que muestra un url generico al que te puedes conectar desde cualquier dispositivo sin tener que estar en la misma red.

Este url es que se va a utilizar para acceder desde un telefono movil, donde enviara la información a la computadora con el programa en c

## Programa de C

### Compliar Programa

Compilar el programa desde MacOs la carpeta `root` se escibre el siguiente comando:

```
gcc semaforo.c -framework OpenGL -framework GLUT -o semaforo
```

Se utilizo el programa del semaforo animado de la tarea 6 como base. Adicionalmente se creo un .h llamado `readCoordenates.h` para leer un csv con las coordenadas que se reciben del giroscopio del celular y se almacenan en este.

### Ejecucion del código

Para correr el programa del semaforo se utiliza el siguiente comando en MacOs

```
./semaforo
```


# Video
