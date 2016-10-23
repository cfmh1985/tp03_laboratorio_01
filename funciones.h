typedef struct {
    char Titulo[31];
    char Genero[31];
    int  Duracion;
    char Descripcion[101];
    int  Puntaje;
    char LImagen[81];
    int estado;
}eMovie;

void Agregar(eMovie *E_peli, FILE *pFile);
void Borrar(eMovie *E_peli, FILE *pFile);
void Modificar(eMovie *E_peli, FILE *pFile);
int Generar_PWeb(eMovie *E_peli, FILE *pFile);
int Val_Entero(int opc, int desde, int hasta);
