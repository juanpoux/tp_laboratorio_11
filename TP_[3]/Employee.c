#include "Employee.h"

Employee* employee_new()
{
	Employee *auxEmpleado;

	auxEmpleado = (Employee*) malloc(sizeof(Employee));
	if(auxEmpleado != NULL)
	{
		employee_setId(auxEmpleado, 0);
		employee_setNombre(auxEmpleado, " ");
		employee_setHorasTrabajadas(auxEmpleado, 0);
		employee_setSueldo(auxEmpleado, 0);
	}

	return auxEmpleado;
}
Employee* employee_newParametros(char *idStr, char *nombreStr, char *horasTrabajadasStr, char *sueldoStr)
{
	Employee *aux;
	int id;
	char nombre[MAXNAME];
	int horas;
	int sueldo;
	aux = employee_new();
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		id = atoi(idStr);
		strncpy(nombre, nombreStr, MAXNAME);
		horas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);
		if(employee_setId(aux, id) || employee_setNombre(aux, nombre) || employee_setHorasTrabajadas(aux, horas) || employee_setSueldo(aux, sueldo))
		{
			aux = NULL;
		}
	}
	return aux;
}

int employee_delete(Employee *this)
{
	int retorno;
	retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		free(this);
	}
	return retorno;
}

int employee_setId(Employee *this, int id)
{
	int retorno;

	retorno = -1;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee *this, int *id)
{
	int retorno;

	retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *nombre)
{
	int retorno;

	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

int employee_setNombreXTeclado(Employee *this)
{
	int retorno;
	char nombre[MAXNAME];

	PedirNombre("Ingrese el nombre: ", nombre, MAXNAME);
	retorno = -1;
	if(this != NULL)
	{
		employee_setNombre(this, nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee *this, char *nombre)
{
	int retorno;

	retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, MAXNAME);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
	int retorno;

	retorno = -1;
	if(this != NULL && horasTrabajadas > -1)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadasXTeclado(Employee *this)
{
	int retorno;
	int horasTrabajadas;

	retorno = -1;
	PedirEnteroP(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas: ", "Error ", 0, 999999999);
	if(this != NULL)
	{
		employee_setHorasTrabajadas(this, horasTrabajadas);
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
{
	int retorno;

	retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_setSueldo(Employee *this, int sueldo)
{
	int retorno;

	retorno = -1;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldoXTeclado(Employee *this)
{
	int retorno;
	int sueldo;

	retorno = -1;
	PedirEnteroP(&sueldo, "Ingrese el sueldo: ", "Error ", 0, 999999999);
	if(this != NULL && sueldo > 0)
	{
		employee_setSueldo(this, sueldo);
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo)
{
	int retorno;

	retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_mostrarUno(Employee *this)
{
	int retorno;
	int id;
	char nombre[MAXNAME];
	int horas;
	int sueldo;

	retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);
		printf("|%-4d |%-15s |%-6d |%-12d|\n", id, nombre, horas, sueldo);
		//Renglones(-1, 45, '-');
	}

	return retorno;
}

void employee_encabezado()
{
	Renglones(-1, 45, '=');
	printf("|%-4s |%-15s |%-6s |%-12s|\n", "ID", "Nombre", "Horas", "Sueldo");
	Renglones(-1, 45, '=');
}

int employee_compararNombres(void *empleadoUno, void *empleadoDos)
{
	int retorno;
	Employee *auxUno;
	Employee *auxDos;
	char nombreUno[MAXNAME];
	char nombreDos[MAXNAME];

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		auxUno = (Employee*) empleadoUno;
		auxDos = (Employee*) empleadoDos;
		employee_getNombre(auxUno, nombreUno);
		employee_getNombre(auxDos, nombreDos);
		retorno = stricmp(nombreUno, nombreDos);
	}
	return retorno;
}

int employee_compararSueldo(void *empleadoUno, void *empleadoDos)
{
	int retorno;
	Employee *auxUno;
	Employee *auxDos;
	int sueldoUno;
	int sueldoDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		retorno = 0;
		auxUno = (Employee*) empleadoUno;
		auxDos = (Employee*) empleadoDos;
		employee_getSueldo(auxUno, &sueldoUno);
		employee_getSueldo(auxDos, &sueldoDos);
		if(sueldoUno > sueldoDos)
		{
			retorno = 1;
		}
		else
		{
			if(sueldoUno < sueldoDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_compararHoras(void *empleadoUno, void *empleadoDos)
{
	int retorno;
	Employee *auxUno;
	Employee *auxDos;
	int horasUno;
	int horasDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		retorno = 0;
		auxUno = (Employee*) empleadoUno;
		auxDos = (Employee*) empleadoDos;
		employee_getHorasTrabajadas(auxUno, &horasUno);
		employee_getHorasTrabajadas(auxDos, &horasDos);
		if(horasUno > horasDos)
		{
			retorno = 1;
		}
		else
		{
			if(horasUno < horasDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_compararId(void *empleadoUno, void *empleadoDos)
{
	int retorno;
	Employee *auxUno;
	Employee *auxDos;
	int idUno;
	int idDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		retorno = 0;
		auxUno = (Employee*) empleadoUno;
		auxDos = (Employee*) empleadoDos;
		employee_getId(auxUno, &idUno);
		employee_getId(auxDos, &idDos);
		if(idUno > idDos)
		{
			retorno = 1;
		}
		else
		{
			if(idUno < idDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

Employee* employee_newXTeclado()
{
	Employee *aux;

	aux = employee_new();

	if(aux != NULL)
	{
		employee_setNombreXTeclado(aux);
		employee_setHorasTrabajadasXTeclado(aux);
		employee_setSueldoXTeclado(aux);
	}

	return aux;
}
