/*
 * EJERCICIO:
 * - Muestra ejemplos de creación de todas las estructuras soportadas por defecto en tu lenguaje.
 * - Utiliza operaciones de inserción, borrado, actualización y ordenación.
 *
 * DIFICULTAD EXTRA (opcional):
 * Crea una agenda de contactos por terminal.
 * - Debes implementar funcionalidades de búsqueda, inserción, actualización y eliminación de contactos.
 * - Cada contacto debe tener un nombre y un número de teléfono.
 * - El programa solicita en primer lugar cuál es la operación que se quiere realizar, y a continuación
 *   los datos necesarios para llevarla a cabo.
 * - El programa no puede dejar introducir números de teléfono no númericos y con más de 11 dígitos.
 *   (o el número de dígitos que quieras)
 * - También se debe proponer una operación de finalización del programa.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Persona
{
		char	nombre[20];
		int		telefono;
};

// Declaraciones de funciones
void insertarPersona(struct Persona* p, const char* nombre, int telefono);
void borrarPersona(struct Persona* p);
void actualizarPersona(struct Persona* p, const char* nuevoNombre, int nuevoTelefono);
int  compararPorNombre(const void* a, const void* b);
void ordenarPorNombre(struct Persona personas[], int size);
int  lanzar_agenda(void);


int	main(void)
{
		struct Persona persona1;
		
		lanzar_agenda();
		insertarPersona(&persona1, "Pepe", 654729893);
		return 0;
}

//Inserción
void	insertarPersona(struct Persona* p, const char* nombre, int telefono)
{
		strcpy(p->nombre, nombre);
		p->telefono = telefono;
}

//Borrar una estructura asignando valores por defecto
void	borrarPersona(struct Persona* p)
{
		strcpy(p->nombre, ""); // Vaciar nombre
		p->telefono = 0;
}

//Actualizar estructura
void	actualizarPersona(struct Persona* p, const char* nuevoNombre, int nuevoTelefono)
{
		strcpy(p->nombre, nuevoNombre);
		p->telefono = nuevoTelefono;
}

//Comparación (usada para luego ordenar)
int	compararPorNombre(const void* a, const void* b)
{
		struct Persona* persona1 = (struct Persona*)a;
		struct Persona* persona2 = (struct Persona*)b;
		return strcmp(persona1->nombre, persona2->nombre);
}

//Ordenación
void	ordenarPorNombre(struct Persona personas[], int size)
{
		qsort(personas, size, sizeof(struct Persona), compararPorNombre);
}

//Lanzar agenda?
int	lanzar_agenda(void)
{
		printf("Bienvenido a su agenda.\n");
		printf("#######################\n");
		printf("#### Elija un modo ####\n");
		printf("#######################\n");
		printf("1. Buscar contacto     \n");
		printf("2. Agregar contacto    \n");
		printf("3. Actualizar contacto \n");
		printf("4. Eliminar contacto   \n");
}


