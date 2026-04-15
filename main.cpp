#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

const int NOMBREJUGADOR = 20;
const int NOMBREEQUIPO = 20;
const int NUMEROJUGADORES = 5;

struct Jugador
{
    char nombre[ NOMBREJUGADOR ] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0' };
    int edad = -1;
    int partidosJugados = 0;
};

struct Equipo
{
    char nombre[ NOMBREEQUIPO ] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0' };
    int torneosGanados = 0;
    char categoria = ' ';
    Jugador *jugadoresPtr = new Jugador[ NUMEROJUGADORES ];
    int cantidadJugadores = 0;
};

//Función 1
void imprimirEnunciado();

//Función 2
void imprimirMenu();

//Función 3
Equipo crearEquipo( std::string nombreEquipo, int torneosGanadosEquipo, char categoriaEquipo );

//Función 4
void registrarEquipo( Equipo * const equipoPtr, int numeroEquipo );

//Función 5
void imprimirEquiposRegistrados( Equipo * const equipoPtr, int numeroEquipos );

//Función 6
int posicionEquipoAsociar( Equipo * const equipoPtr, int numeroEquipos, std::string nombreJugador );

//Función 7
Jugador crearJugador( std::string nombreJugador, int edadJugador, int partidosJugadosJugador );

//Función 8
void registrarJugador( Equipo * const equipoPtr, int numeroEquipos );

//Función 9
void imprimirRegistros( Equipo * const equipoPtr, int numeroEquipos );

//Función 10
int posicionEquipoInformacion( Equipo * const equipoPtr, int numeroEquipos );

//Función 11
void imprimirEquipoParticular( Equipo * const equipoPtr, int numeroEquipos );

//Función 12
int posicionEquipoEliminar( Equipo * const equipoPtr, int numeroEquipos );

//Función 13
void eliminarEquipo( Equipo * const equipoPtr, int &numeroEquipos );

//Función 14
int posicionEquipoJugador( Equipo * const equipoPtr, int numeroEquipos );

//Función 15
int posicionJugadorEliminar( Equipo * const equipoPtr, int numeroEquipos, int numeroEquipo );

//Función 16
void eliminarJugador( Equipo * const equipoPtr, int numeroEquipos );

//Función 17
void desasignarMemoria( Equipo * const equipoPtr, int numeroEquipos );

int main()
{
    //Declaración de variables
    int cantidadEquipos;
    int equiposRegistrados = 0;
    bool menuCerrado = false;
    int opcionMenu;

    //Lectura de información
    imprimirEnunciado();
    std::cin >> cantidadEquipos;

    //Declaración de apuntador constante que esta apuntando al primer atributo del primer elemento de un arreglo de estructuras Equipo
    Equipo * const equiposPtr = new Equipo[ cantidadEquipos ];

    std::cout << std::endl;
    system("pause");
    system("cls");

    while( menuCerrado == false )
    {
        imprimirMenu();
        std::cin >> opcionMenu;
        std::cout << std::endl;
        switch( opcionMenu )
        {
        case 1:
            system("pause");
            system("cls");
            registrarEquipo( equiposPtr, equiposRegistrados );
            equiposRegistrados++;
            system("pause");
            system("cls");
            break;
        case 2:
            system("pause");
            system("cls");
            registrarJugador( equiposPtr, equiposRegistrados );
            system("pause");
            system("cls");
            break;
        case 3:
            system("pause");
            system("cls");
            eliminarEquipo( equiposPtr, equiposRegistrados );
            system("pause");
            system("cls");
            break;
        case 4:
            system("pause");
            system("cls");
            eliminarJugador( equiposPtr, equiposRegistrados );
            system("pause");
            system("cls");
            break;
        case 5:
            system("pause");
            system("cls");
            imprimirEquipoParticular( equiposPtr, equiposRegistrados );
            system("pause");
            system("cls");
            break;
        case 6:
            system("pause");
            system("cls");
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "Gracias por su atencion, vuelva pronto" << std::endl << std::endl;
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            desasignarMemoria( equiposPtr, equiposRegistrados );
            return 0;
        default:
            system("pause");
            system("cls");
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "El numero ingresado no corresponde a ninguna de las opciones permitidas" << std::endl << std::endl;
            std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

//Función 1
void imprimirEnunciado()
{
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw (64) << "Sistema de Gestión de Equipos" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Digite el numero de equipos: ";
}

//Función 2
void imprimirMenu()
{
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw (64) << "Sistema de Registro" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "Digite la opcion que quiere ejecutar: " << std::endl << std::endl;
    std::cout << "\t" << "(1) Registrar equipo" << std::endl;
    std::cout << "\t" << "(2) Registrar jugador" << std::endl;
    std::cout << "\t" << "(3) Eliminar equipo" << std::endl;
    std::cout << "\t" << "(4) Eliminar jugador" << std::endl;
    std::cout << "\t" << "(5) Ver registros" << std::endl;
    std::cout << "\t" << "(6) Salir" << std::endl << std::endl;
    std::cout << "Eleccion: ";
}

//Función 3
Equipo crearEquipo( std::string nombreEquipo, int torneosGanadosEquipo, char categoriaEquipo )
{
    Equipo equipoCreado;

    strcpy( equipoCreado.nombre, nombreEquipo.c_str() );
    equipoCreado.categoria = categoriaEquipo;
    equipoCreado.torneosGanados = torneosGanadosEquipo;

    return equipoCreado;
}

//Función 4
void registrarEquipo( Equipo * const equipoPtr, int numeroEquipo )
{
    std::string equipoNombre;
    int equipoTorneosGanados;
    char equipoCategoria;
    Equipo nuevoEquipo;

    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    std::cout << "Digite el nombre del equipo: ";
    std::cin >> equipoNombre;
    std::cout << "Digite la categoria del equipo " << equipoNombre << ": ";
    std::cin >> equipoCategoria;
    std::cout << "Digite la cantidad de torneos ganados del equipo " << equipoNombre << ": ";
    std::cin >> equipoTorneosGanados;

    std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    nuevoEquipo = crearEquipo( equipoNombre, equipoTorneosGanados, equipoCategoria );

    *( equipoPtr + numeroEquipo ) = nuevoEquipo;

    return;
}

//Función 5
void imprimirEquiposRegistrados( Equipo * const equipoPtr, int numeroEquipos )
{
    std::cout << "Equipos registrados: " << std::endl << std::endl;

    for( int i = 0; i < numeroEquipos; i++ )
    {
        std::cout << "\t" << "(" << i + 1 << ") " << ( equipoPtr + i )->nombre << std::endl;
    }

    return;
}

//Función 6
int posicionEquipoAsociar( Equipo * const equipoPtr, int numeroEquipos, std::string nombreJugador )
{
    int equipoAsociar;

    imprimirEquiposRegistrados( equipoPtr, numeroEquipos );

    std::cout << std::endl << "Digite el numero del nombre del equipo en el cual quiere asociar al jugador " << nombreJugador << ": ";
    std::cin >> equipoAsociar;

    equipoAsociar -= 1;

    return equipoAsociar;
}

//Función 7
Jugador crearJugador( std::string nombreJugador, int edadJugador, int partidosJugadosJugador )
{
    Jugador jugadorCreado;

    strcpy( jugadorCreado.nombre, nombreJugador.c_str() );
    jugadorCreado.edad = edadJugador;
    jugadorCreado.partidosJugados = partidosJugadosJugador;

    return jugadorCreado;
}

//Función 8
void registrarJugador( Equipo * const equipoPtr, int numeroEquipos )
{
    std::string jugadorNombre;
    int jugadorEdad;
    int jugadorPartidosJugados;
    Jugador nuevoJugador;
    int numeroEquipo;
    int numeroJugador;

    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Digite el nombre del jugador: ";
    std::cin >> jugadorNombre;
    std::cout << "Digite la edad del jugador " << jugadorNombre << ": ";
    std::cin >> jugadorEdad;
    std::cout << "Digite la cantidad de partidos jugados por el jugador " << jugadorNombre << ": ";
    std::cin >> jugadorPartidosJugados;

    std::cout << std::endl;

    numeroEquipo = posicionEquipoAsociar( equipoPtr, numeroEquipos, jugadorNombre );

    std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    numeroJugador = ( equipoPtr + numeroEquipo )->cantidadJugadores;

    Jugador * const jugadorPtr = ( equipoPtr + numeroEquipo )->jugadoresPtr;

    nuevoJugador = crearJugador( jugadorNombre, jugadorEdad, jugadorPartidosJugados );

    *( jugadorPtr + numeroJugador ) = nuevoJugador;

    ( equipoPtr + numeroEquipo )->cantidadJugadores += 1;

    return;
}

//Función 9
void imprimirRegistros( Equipo * const equipoPtr, int numeroEquipos )
{
    std::cout << "Equipos registrados: " << std::endl << std::endl;

    for( int i = 0; i < numeroEquipos; i++ )
    {
        std::cout << "\t" << "(" << i + 1 << ") " << ( equipoPtr + i )->nombre << std::endl;

        if( ( equipoPtr + i )->cantidadJugadores == 5 )
        {
            std::cout << "\t" << "Estado: Completo" << std::endl;
        }
        else if( ( equipoPtr + i )->cantidadJugadores >= 0 || ( equipoPtr + i )->cantidadJugadores <= 5 )
        {
            std::cout << "\t" << "Estado: Faltan Jugadores" << std::endl;
        }
        std::cout << std::endl;
    }

    return;
}

//Función 10
int posicionEquipoInformacion( Equipo * const equipoPtr, int numeroEquipos )
{
    int equipoInteres;

    imprimirEquiposRegistrados( equipoPtr, numeroEquipos );

    std::cout << std::endl << "Digite el numero del nombre del equipo del cual quiere saber mas informacion: ";
    std::cin >> equipoInteres;

    equipoInteres -= 1;

    return equipoInteres;

}

//Función 11
void imprimirEquipoParticular( Equipo * const equipoPtr, int numeroEquipos )
{
    char respuestaUsuario;
    int numeroEquipo;

    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    imprimirRegistros( equipoPtr, numeroEquipos );

    std::cout << "Si quiere ver mas informacion de un equipo en particular, digite 's' para Si y 'n' para No: ";
    std::cin >> respuestaUsuario;

    if( respuestaUsuario == 's' )
    {
        std::cout << std::endl;
        numeroEquipo = posicionEquipoInformacion( equipoPtr, numeroEquipos );
        Jugador * const jugadorPtr = ( equipoPtr + numeroEquipo )->jugadoresPtr;

        std::cout << std::endl << "Equipo " << numeroEquipo + 1 << std::endl;
        std::cout << "\t" << "Nombre: " << ( equipoPtr + numeroEquipo )->nombre << std::endl;
        std::cout << "\t" << "Categoria: " << ( equipoPtr + numeroEquipo )->categoria << std::endl;
        std::cout << "\t" << "Torneos ganados: " << ( equipoPtr + numeroEquipo )->torneosGanados << std::endl;
        std::cout << "\t" << "Cantidad de jugadores: " << ( equipoPtr + numeroEquipo )->cantidadJugadores << std::endl;
        std::cout << "\t" << "Jugadores: " << std::endl;

        for( int i = 0; i < ( equipoPtr + numeroEquipo )->cantidadJugadores; i++ )
        {
            std::cout << "\t" << "Jugador " << i + 1 << std::endl;
            std::cout << "\t\t" << "Nombre: " << ( jugadorPtr + i )->nombre << std::endl;
            std::cout << "\t\t" << "Edad: " << ( jugadorPtr + i )->edad << std::endl;
            std::cout << "\t\t" << "Partidos jugados: " << ( jugadorPtr + i )->partidosJugados << std::endl;
        }
        std::cout << std::endl;
    }
    else if( respuestaUsuario != 's' )
    {
        std::cout << std::endl;
    }

    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    return;
}

//Función 12
int posicionEquipoEliminar( Equipo * const equipoPtr, int numeroEquipos )
{
    int equipoEliminar;

    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    imprimirEquiposRegistrados( equipoPtr, numeroEquipos );

    std::cout << std::endl << "Digite el numero del nombre del equipo que quiere eliminar: ";
    std::cin >> equipoEliminar;

    std::cout << std::endl << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    equipoEliminar -= 1;

    return equipoEliminar;
}

//Función 13
void eliminarEquipo( Equipo * const equipoPtr, int &numeroEquipos )
{
    int numeroEquipo = posicionEquipoEliminar( equipoPtr, numeroEquipos );

    Jugador * const jugadorPtr = ( equipoPtr + numeroEquipo )->jugadoresPtr;

    for( int i = numeroEquipo; i < numeroEquipos; i++ )
    {
        *( equipoPtr + i ) = *( equipoPtr + i + 1 );

        for( int j = 0; j < ( equipoPtr + i )->cantidadJugadores; j++ )
        {
            *( jugadorPtr + j ) = *( jugadorPtr + j + 1 );
        }
    }

    numeroEquipos -= 1;

    return;
}

//Función 14
int posicionEquipoJugador( Equipo * const equipoPtr, int numeroEquipos )
{
    int equipoJugador;

    imprimirEquiposRegistrados( equipoPtr, numeroEquipos );

    std::cout << std::endl << "Digite el numero del nombre del equipo en el cual esta el jugador que quiere eliminar: ";
    std::cin >> equipoJugador;

    equipoJugador -= 1;

    return equipoJugador;
}

//Función 15
int posicionJugadorEliminar( Equipo * const equipoPtr, int numeroEquipos, int numeroEquipo )
{
    Jugador * const jugadorPtr = ( equipoPtr + numeroEquipo )->jugadoresPtr;
    int jugadorEliminar;

    std::cout << std::endl << "Equipo " << numeroEquipo + 1 << std::endl;
    std::cout << "\t" << "Nombre: " << ( equipoPtr + numeroEquipo )->nombre << std::endl;
    std::cout << "\t" << "Categoria: " << ( equipoPtr + numeroEquipo )->categoria << std::endl;
    std::cout << "\t" << "Torneos ganados: " << ( equipoPtr + numeroEquipo )->torneosGanados << std::endl;
    std::cout << "\t" << "Cantidad de jugadores: " << ( equipoPtr + numeroEquipo )->cantidadJugadores << std::endl;
    std::cout << "\t" << "Jugadores: " << std::endl;

    for( int i = 0; i < ( equipoPtr + numeroEquipo )->cantidadJugadores; i++ )
    {
        std::cout << "\t" << "Jugador " << i + 1 << std::endl;
        std::cout << "\t\t" << "Nombre: " << ( jugadorPtr + i )->nombre << std::endl;
        std::cout << "\t\t" << "Edad: " << ( jugadorPtr + i )->edad << std::endl;
        std::cout << "\t\t" << "Partidos jugados: " << ( jugadorPtr + i )->partidosJugados << std::endl;
    }

    std::cout << std::endl << "Digite el numero del nombre del jugador quiere eliminar: ";
    std::cin >> jugadorEliminar;
    std::cout << std::endl;

    jugadorEliminar -= 1;

    return jugadorEliminar;

}

//Función 16
void eliminarJugador( Equipo * const equipoPtr, int numeroEquipos )
{
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
    int numeroEquipo = posicionEquipoJugador( equipoPtr, numeroEquipos );
    int numeroJugador = posicionJugadorEliminar( equipoPtr, numeroEquipos, numeroEquipo );
    std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

    Jugador * const jugadorPtr = ( equipoPtr + numeroEquipo )->jugadoresPtr;

    for( int i = numeroJugador; i < ( equipoPtr + numeroEquipo )->cantidadJugadores; i++ )
    {
        *( jugadorPtr + i ) = *( jugadorPtr + i + 1 );
    }

    ( equipoPtr + numeroEquipo )->cantidadJugadores -= 1;

    return;
}

//Función 17
void desasignarMemoria( Equipo * const equipoPtr, int numeroEquipos )
{
    delete[] equipoPtr;

    return;
}
