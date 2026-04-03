# Respuestas - TPN01

---

## Punto 1

### El archivo .gitignore

Este archivo tiene como funcion principal **indicarle a Git que archivos o carpetas debe ignorar** y no incluir en el historial de versiones.

Cuando un archivo esta listado en el `.gitignore`, Git deja de "rastrearlo" (**untracked**), lo que significa que no apararecera com un cambio pendiente cuando se ejecuta un `git status`.

---

### ¿Por que es conveniente incluirlo?

Cuando estamos trabajano en nuestro proyecto, no todo lo que esta en nuestra carpeta de trabajo conviene subirlo a la nube. Incluir este archivo es fundamental por tres simples razones:

- **Seguridad:** Evita subir accidentalmente informacion sensible, como claves de API, contrasenias o archivos, etc.
- **Limpieza y Peso:** Impide que el repositorio se llene de "basura" tecnica, como carpetas de dependencias pesadas, archivos temporales del sistema o archivos de compilacion.
- **Rendimiento:** Al ignorar archivos innecesarios, las operacion de Git (como clonar) son muchas mas rapidas, porque el repositorio pesa menos.

---

### ¿Cuando se debe hacer?

Es altamente recomendable crearlo cuando se inicia el proyecto, idealmente justo despues del `git init`.

---

### ¿Como configuraria el archivo .gitignore?

Para configurarlo, solo se necesita listar los nombres o patrones de los archivos que se quiere excluir.

#### Sintaxis baisca:

| Patron | Resultado |
| --- | --- |
| `archivo.txt` | Ignora un archivo en especifico llamado `archivo.txt` |
| `*.log` | Es una expecie de comodin (`*`) ignora todos los archivos que terminen en `.log` |
| `temp/` | La barra (`/`) al final ignora una carpeta entera y todo su contenido |
| `# Comentario` | Las lineas que empiezan con `#` son notas propias y Git las ignora |
| `!importante.log` | El signo (`!`) es una excepcion; Git rastreara este archivo aunque los `.log` esten ignorados | 

---

### Ejemplo:

Supongamos que quiero que Git ignore un archivo `ignorar.txt`, para ello debemos seguir los siguientes pasos:

1. Crear o editar el archivo **.gitignore**

    Si aun no tengo el archivo, puedo crearlo y aniadir la regla en una sola linea desde Git Bash:

    ```bash
    echo "ignorar.txt" >> .gitignore
    ```

    - `echo "ignorar.txt"` escribe el nombre del archivo.
    - `>> .gitignore` crea el archivo (si no existe) o aniade la linea al final del archivo existente.

2. Verificar el estado

    Para confirmar que Git ahora ignora el archivo, utilizamos el comando de estado:

    ```bash
    git status
    ```

    Si lo hicimos correctamente, `ignorar.txt` **no deberia aparecer** en la seccion de "Untracked files" (archivos sin seguimiento). En su lugar, veremos que el archivo `.gitignore` **aparece como un cambio nuevo** que debemos incluir en nuestro repositorio. 

3. Guardar la configuracion en nuestro repositorio

    Recordemos que el archivo `.gitignore` debe formar parte de nuestro proyecto para que funcione, y para que funcione, tambien en el repositorio remoto (Github). Ahora debemos prepararlo y confirmalo:

    ```bash
    git add .gitignore
    git commit -m "Agrego ignorar.txt a .gitignore"
    ```

    - `git add` prepara el archivo de configuracion para el siguiente commit.
    - `git commit` almacena de forma segura la regla de ignorar en nuestro repositorio local.

---

## Punto 2

### Cambios Codigo Secreto 2.0

El codigo parte de un `codigo_secreto`, el cual es un numero entero. Se pasa la direccion de memoria del `codigo_secreto` a una funcion `procesar_enigma`. Esta funcion, a traves de otras funciones:

1. Invierte el numero.
2. Divide en dos el numero.
3. Suma al numero, la suma de sus digitos.

Y al final, el codigo muestra el resultado.

### Cambio de nombre de funciones y variables:

Se realizaron las siguientes modificaciones:

- Se cambio el nombre de las funciones auxiliares que utiliza `procesar_enigma`, de nombres genericos a nombres segun lo que realizan. 

    Por ejemplo:

    _Si la funcion `f_alpha` invierte un numero, su nombre ahora es `invertir_num`._

- Se modifico el nombre de la unica variable que utiliza la funcion `procesar_enigma`.

    Paso de `valor_refencia` a `codigo`. Esto pues, la funcion recibe un "codigo" el cual procesa para dar el resultado, de esta manera es un poco menos confuso (para mi).

- Se modifico el nombre de las variables de la funcion `invertir_num` (antes `f_alpha`):

    - `p` ==> `p_num` // Para destacar que es un puntero hacia un numero.
    - `temp` ==> `aux` // Pues solo se usa para no tener que modificar el contenido del puntero.
    - `rev` ==> `num_invertido` // Facilita para que se usa la variable.

- Se modifico el nombre de las variables de la funcion `div_en_2` (antes `f_beta`):

    - `p` ==> `p_num` // Para destacar que es un puntero hacia un numero.

- Se modifico el nombre de las variables de la funcion `sumar_suma_de_digitos` (antes `f_gamma`):

    - `p` ==> `p_num` // Para destacar que es un puntero hacia un numero.
    - `temp` ==> `aux` // Pues solo se usa para no tener que modificar el contenido del puntero.
    - `suma` ==> `sumaDigitos` // Facilita para que se usa la variable.

---

### Correccion de errores en `codigo_sin_funcionar.c`

A continuacion se muestra una tabla con los errores encontrados y corregidos:

| Linea | Categoria | Descripcion | Solucion |
| --- | --- | --- | --- |
| 1 | Compilacion | No incluye Librerias necesarias | Se agrego la libreria correspondiente para que el codigo funcione |
| 12 | Runtime | Dentro de scanf, falta `&` en la variable | Se agrego `&` |
| 17 | Sintaxis | Falta `;` al final | Se agrego `;` |
| 18 | Logica | La funcion pasa parametro por valor y es una funcion void, no devuelve ni modifica nada | Ahora la funcion pasa valor por referencia, y dentro de la funcion se modificaron las variables para que sean punteros |
| 24 | Sintaxis | Falta `;` al final | Se agrego `;` |