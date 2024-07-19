# Software de creación de fichas descriptivas basado en LaTeX.
El código actual permite la ccreación de fichas descriptivas en base a una serie de archivos auixiliares que contienen las fortalezas, áreas de oportunidad y recomendaciones a una serie de alunmos contenidos en una base de datos .csv; el actual software se encuentra corriendo de manera estable en Python 3.12, el porteo a c y versiones compiladas de el mismmo se encuentran en desarrollo.
## Software adidcional requerido:
1. Python 3.10 o superior, puede descargar el intérptrte desde [éste enlace.](https://www.python.org/downloads/)
2. Compliador de LaTeX, para las pruebas se ha estado empleando [MiKTeX](https://miktex.org/download), para poderlo instalar adecuadamenet se suguiere el tutorial del [éste vínculo](https://miktex.org/howto/install-miktex).
> [!TIP]
> En la sección *Prefered paper* cambie la opción a *Letter*

## Organización de los datos dentro de las bases de datos de entrada.
Para que el software pueda leer y provesar los datos éstos deben estar organizados en un archivo .cvs (lo pude crear desde MS Excel), de modo que los mismos se encuentren organizados como se muestra a continuación:

| Zona | Sector | Escuela | Grado | Grupo |Ciclo escolar |Nombre | Calificacion |
| --- | --- | --- | --- | --- | --- | --- | --- |
|19|5|Secundaria General Jesús Reyes Heroles|1|A|2023-2024|AGUSTIN PEREZ DEIMAR|6.6|
|19|5|Secundaria General Jesús Reyes Heroles|1|A|2023-2024|AVILA MARTINEZ EMILY|8.3|

Para un óptimo funcionamiento gurde este erchivo en la misma ruta que el programa, y no use espacios
