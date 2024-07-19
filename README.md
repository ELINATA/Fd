# Software de creación de fichas descriptivas basado en LaTeX.
El código actual permite la creación de fichas descriptivas en base a una serie de archivos auxiliares que contienen las fortalezas, áreas de oportunidad y recomendaciones a una serie de alunmos contenidos en una base de datos .csv; el actual software se encuentra corriendo de manera estable en Python 3.12, el porteo a c y versiones compiladas del mismo se encuentran en desarrollo.
## Software adicional requerido:
1. Python 3.10 o superior, puede descargar el intérprete desde [éste enlace.](https://www.python.org/downloads/)
2. Compliador de LaTeX (se requiere que se encuentre en path), para las pruebas se ha estado empleando [MiKTeX](https://miktex.org/download), para poderlo instalar adecuadamente se sugiere el tutorial del [éste vínculo](https://miktex.org/howto/install-miktex).
> [!TIP]
> En la sección *Prefered paper* cambie la opción a *Letter*

## Organización de los datos dentro de las bases de datos de entrada.
Para que el software pueda leer y procesar los datos éstos deben estar organizados en un archivo .cvs (lo pude crear desde MS Excel), de modo que los mismos se encuentren organizados como se muestra a continuación:

| Zona | Sector | Escuela | Grado | Grupo |Ciclo escolar |Nombre | Calificación |
| --- | --- | --- | --- | --- | --- | --- | --- |
|19|5|Secundaria General Jesús Reyes Heroles|1|A|2023-2024|Aiib Poi Dywi|6.6|
|19|5|Secundaria General Jesús Reyes Heroles|1|A|2023-2024|Aries Mjieg Eivna|8.3|

Para un óptimo funcionamiento guarde éste archivo en la misma ruta que el programa, y no use espacios y evite caracteres especiales
## Ejecución del programa
### Ejecución en un clic
En el directorio principal se encuentra el archivo RUN.bat, de clic sobre el archivo
### Ejecución llamando el terminal
Abra una terminal del su sistema operativo en la ruta en la cual se encuentra esta carpeta de archivos, una vez allí ejecute el siguiente comando:
```python programa_3.py```
### Interacción en la terminal
En la consola de comandos y se mostrará el siguiente mensaje:
`Introduzca el nombre de su archivo, no incluya la extensión, se asume como ".csv"--->`

En ese punto coloque el nombre de la base de datos creada con antelación omitiendo la extensión, por ejemplo, asumamos que el archivo es Matematica_1.csv, en ese caso en la terminal solo coloque `Matematica_1` y de Enter (Intro)
En este momento ya se encuentran creándose los archivos de fichas descriptivas en su dispositivo, los archivos contaran con el siguiente formato de nombre:
`Nombre-Grado-Grupo.pdf`
y se encontraran en la carpeta principal, para una mejor organización de los archivos se le siguiere al usuario organizar los archivos creados en subcarpetas

## Futuras actualizaciones:
Se espera que en futuras versiones de éste programa se cuente con:
1. Administración automática en subcarpetas
2. Reducción del tiempo de ejecución o de los recursos empleados
3. UI amigable, interacción por terminal en segundo plano

## Aproximación del tiempo de ejecución:
Considere el número de alumnos en la base de datos como $n$ y el número de procesadores lógicos de ordenador como $p$, con ello tenemos que
$$t\approx1.2\dfrac{n}{p}+10 [=] s$$
Los procesadores lógicos de su ordenador los puede ver en el administrador de tareas o bien con el los siguientes comandos en una terminal:
```
python
```
```python
import os
```
```python
p=os.cpu_count()
```
```python
print(f"p={p}")
```
## Muchas gracias por su tiempo.
