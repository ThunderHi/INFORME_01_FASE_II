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
    Curso(string nombre, string codigo, string profesor) {
        this->nombre = nombre;
        this->codigo = codigo;
        this->profesor = profesor;
    }

    ~Curso() {}

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    string getCodigo() const { return codigo; }
    void setCodigo(string codigo) { this->codigo = codigo; }

    string getProfesor() const { return profesor; }
    void setProfesor(string profesor) { this->profesor = profesor; }
};

class Alumno {
private:
    string nombre;
    int codigo;

public:
    Alumno(string nombre, int codigo) {
        this->nombre = nombre;
        this->codigo = codigo;
    }

    ~Alumno() {}

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
    Matricula(Curso* curso) {
        this->curso = curso;
    }

    ~Matricula() {
        for (auto& alumno : alumnos) {
            delete alumno;
        }
    }

    Matricula& matricularAlumno(Alumno* alumno) {  //Autoreferencia
        alumnos.push_back(alumno);
        return *this;
    }

    void mostrarMatriculados() {
        cout << "Curso: " << curso->getNombre() << endl;
        cout << "Alumnos inscritos:" << endl;
        for (auto& alumno : alumnos) {
            cout << "Nombre: " << alumno->getNombre() << " / Codigo: " << alumno->getCodigoAlum() << endl;
        }
    }
};

int main() {
    Curso curso1("Calculo", "01", "Ing. Pedro");
    Matricula matricula1(&curso1);
    Alumno* alumno1 = new Alumno("Juan", 2021);
    Alumno* alumno2 = new Alumno("Maria",1515);
    Alumno* alumno3 = new Alumno("Carlos",2526);
    
    //Encadenamiento para registrar varios alumnos en un solo curso
    matricula1.matricularAlumno(alumno1).matricularAlumno(alumno2).matricularAlumno(alumno3);

    matricula1.mostrarMatriculados();
    
    return 0;
}

