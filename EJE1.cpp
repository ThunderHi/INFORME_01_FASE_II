#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Curso {
private:
    string nombre;
    string codigo;
    string profesor;

public:
    //Constructor de 03 parámetros
    Curso(string nombre, string codigo, string profesor) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->profesor = profesor;
    }
    //Constructor de 02 parámetros
    Curso(string nombre, string codigo) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->profesor = "Por Asignar";
    }
    //Destructor
    ~Curso() {}

    //Get y Set para cada atributo
    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    string getCodigo() const { return codigo; }
    void setCodigo(string codigo) { this->codigo = codigo; }

    string getProfesor() const { return profesor; }
    void setProfesor(string profesor) { this->profesor = profesor; }

    void mostrarDetalles() const {
    cout<<"Nombre del curso: "<<nombre<<endl<<"Codigo del curso: "<<codigo<<endl<<"Profesor del curso: "<<profesor<<endl;
    }
};

class Alumno {
private:
    string nombre;
    int codigo;

public:
    //Constructor
    Alumno(string nombre, int codigo) {
        this->nombre = nombre;
        this->codigo = codigo;
    }
    //Destructor
    ~Alumno() {}

    //Get y Set
    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    int getCodigoAlum() const { return codigo; }
    void setCodigoAlum(int codigo) { this->codigo = codigo; }
};

class Matricula {
private:
    Curso* curso;
    vector<Alumno*> alumnos;

public:
    //Constructor
    Matricula(Curso* curso) {
        this->curso = curso;
    }
    //Destructor
    ~Matricula() {
        for (auto& alumno : alumnos) {
            delete alumno;
        }
    }

    //Autoreferencia
    Matricula& matricularAlumno(Alumno* alumno) {  
        alumnos.push_back(alumno);
        return *this;
    }

    //Muestra de matriculados
    void mostrarMatriculados() {
        cout<<"Curso: "<<curso->getNombre() << endl;
        cout<<"Alumnos inscritos:" << endl;
        for (auto& alumno : alumnos) {
            cout<<"Nombre: "<<alumno->getNombre()<<" / Codigo: "<<alumno->getCodigoAlum()<<endl;
        }
    }
};

int main() {
    int opcion;
    vector<Curso*> cursos;
    vector<Matricula*> matriculas;
    vector<Alumno*> alumnos;

    do {
        cout << "Menu de Opciones" << endl;        //menu de opciones
        cout << "1. Crear curso" << endl;
        cout << "2. Ver detalles de cursos" << endl;
        cout << "3. Crear Alumno" << endl;
        cout << "4. Ver detalles de Alumnos" << endl;
        cout << "5. Generar matricula" << endl;
        cout << "6. Ver detalles de matriculas" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {                //Switch para manejo de opciones
            case 1: {
                string nombre, codigo, profesor;
                cout << "Ingrese el nombre del curso: ";
                cin >> nombre;
                cout << "Ingrese el codigo del curso: ";
                cin >> codigo;
                cout << "Ingrese el nombre del profesor: ";
                cin >> profesor;
                Curso* nuevoCurso = new Curso(nombre, codigo, profesor);
                cursos.push_back(nuevoCurso);
                break;
            }
            case 2: {
                cout << "Detalles de los cursos:" << endl;
                for (auto& curso : cursos) {
                    curso->mostrarDetalles();
                }
                break;
            }
            case 3: {
                string nombre;
                int codigo;
                cout << "Ingrese el nombre del alumno: ";
                cin >> nombre;
                cout << "Ingrese el codigo del alumno: ";
                cin >> codigo;
                Alumno* nuevoAlumno = new Alumno(nombre, codigo);
                alumnos.push_back(nuevoAlumno);
                break;
            }
            case 4: {
                cout << "Detalles de los alumnos:" << endl;
                for (auto& alumno : alumnos) {
                    cout << "Nombre: " << alumno->getNombre() << " / Codigo: " << alumno->getCodigoAlum() << endl;
                }
                break;
            }
            case 5: {
                int indiceCurso, indiceAlumno;
                cout << "Seleccione el curso al que desea matricular: " << endl;
                for (int i = 0; i < cursos.size(); ++i) {
                    cout << i + 1 << ". " << cursos[i]->getNombre() << endl;
                }
                cout << "Ingrese el numero del curso: ";
                cin >> indiceCurso;
                cout << "Seleccione el alumno que desea matricular: " << endl;
                for (int i = 0; i < alumnos.size(); ++i) {
                    cout << i + 1 << ". " << alumnos[i]->getNombre() << endl;
                }
                cout << "Ingrese el numero del alumno: ";
                cin >> indiceAlumno;
                Matricula* nuevaMatricula = new Matricula(cursos[indiceCurso - 1]);
                nuevaMatricula->matricularAlumno(alumnos[indiceAlumno - 1]);
                matriculas.push_back(nuevaMatricula);
                break;
            }
            case 6: {
                cout << "Detalles de las matriculas:" << endl;
                for (auto& matricula : matriculas) {
                    matricula->mostrarMatriculados();
                }
                break;
            }
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 7);
    return 0;
}
