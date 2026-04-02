# Respuestas Pto2 - TPN01

## El archivo .gitignore

Este archivo tiene como funcion principal **indicarle a Git que archivos o carpetas debe ignorar** y no incluir en el historial de versiones.

Cuando un archivo esta listado en el .gitignore, Git deja de "rastrearlo" (untracked), lo que significa que no apararecera com un cambio pendiente cuando se ejecuta un git status.

## ¿Por que es conveniente incluirlo?

Cuando estamos trabajano en nuestro proyecto, no todo lo que esta en nuestra carpeta de trabajo conviene subirlo a la nube. Incluir este archivo es fundamental por tres simples razones:

- Seguridad: Evita subir accidentalmente informacion sensible, como claves de API, contrasenias o archivos, etc.
- Limpieza y Peso: Impide que el repositorio se llene de "basura" tecnica, como carpetas de dependencias pesadas, archivos temporales del sistema o archivos de compilacion.
- Rendimiento: Al ignorar archivos innecesarios, las operacion de Git (como clonar) son muchas mas rapidas, porque el repositorio pesa menos.

## ¿Cuando se debe hacer?

Es altamente recomendable crearlo cuando se inicia el proyecto.

## ¿Como configuraria el archivo .gitignore?

Para configurarlo, solo se necesita listar los nombres o patrones de los archivos que se quiere excluir.

### Sintaxis baisca:

| Patron | Resultado |
| --- | --- |
| archivo.txt | Ignora un archivo en especifico llamado archivo.txt |
| *.log | Es una expecie de comodin (*) ignora todos los archivos que terminen en .log |
| temp/ | La barra (/) al final ignora una carpeta entera y todo su contenido |
| # Comentario | Las lineas que empiezan con (#) son notas propias y Git las ignora |
| !importante.log | El signo (!) es una excepcion; Git rastreara este archivo aunque los .log esten ignorados | 

## Ejemplo:

Supongamos que quiero que Git ignore un archivo `ignorar.txt`, para ello debemos seguir los siguientes pasos:

1. Crear o editar el archivo **.gitignore**

Si aun no tengo el archivo, puedo crearlo y aniadir la regla en una sola linea desde Git Bash:

`echo "ignorar.txt" >> .gitignore`

- `echo "ignorar.txt"` escribe el nombre del archivo.
- `>> .gitignore` crea el archivo (si no existe) o aniade la linea al final del archivo existente.

2. Verificar el estado

Para confirmar que Git ahora ignora el archivo, utilizamos el comando de estado:

`git status`

Si lo hicimos correctamente, `ignorar.txt` **no deberia aparecer** en la seccion de "Untracked files" (archivos sin seguimiento). En su lugar, veremos que el archivo `.git ignore` **aparece como un cambio nuevo** que debemos incluir en nuestro repositorio. 

3. Guardar la configuracion en nuestro repositorio

Recordemos que el archivo `.gitignore` debe formar parte de nuestro proyecto para que funcione, y para que funcione, tambien en el repositorio remoto (Github). Ahora debemos prepararlo y confirmalo:

`git add .gitignore`
`git commit -m "Agrego ignorar.txt a .gitignore"`

- `git add` prepara el archivo de configuracion para el siguiente commit.
- `git commit` almacena de forma segura la regla de ignorar en nuestro repositorio local.