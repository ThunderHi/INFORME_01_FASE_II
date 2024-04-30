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
    //Creación de curso 1
    Curso curso1("Calculo", "01", "Ing. Pedro");  
    curso1.mostrarDetalles();
    Matricula matricula1(&curso1);      //Creación de Matrícula1
    
    //Creación de curso 2
    Curso curso2("Fisica","02");               
    curso2.mostrarDetalles();
    Matricula matricula2(&curso2);      //Creación de Matrícula2

    //Creación de alumnado
    Alumno* alumno1 = new Alumno("Juan", 2021); 
    Alumno* alumno2 = new Alumno("Maria",1515); 
    Alumno* alumno3 = new Alumno("Carlos",2526);   
    
    //Encadenamiento para registrar varios alumnos en un solo curso
    matricula1.matricularAlumno(alumno1).matricularAlumno(alumno2).matricularAlumno(alumno3);
    matricula1.mostrarMatriculados();

    matricula2.matricularAlumno(alumno1).matricularAlumno(alumno2).matricularAlumno(alumno3);
    matricula2.mostrarMatriculados();
    
    return 0;
}
