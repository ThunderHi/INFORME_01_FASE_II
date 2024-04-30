#include <iostream>
#include <string>
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
    void setNombre(string nombre) {
         this->nombre = nombre; 
    }

    string getCodigo() const { return codigo; }
    void setCodigo(string codigo) { 
        this->codigo = codigo; 
    }

    string getProfesor() const { return profesor; }
    void setProfesor(string profesor) { 
        this->profesor = profesor; 
    }

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
    void setNombre(string nombre) {
         this->nombre = nombre; 
    }

    int getCodigoAlum() const { return codigo; }
    void setCodigoAlum(int codigo) { 
        this->codigo = codigo; 
    }
};

class Matricula {
private:
    Curso* curso;
    Alumno* alumno;

public:
    Matricula(Curso* curso, Alumno* alumno) {
        this->curso = curso;
        this->alumno = alumno;
    }

    ~Matricula() {}

    Curso* getCurso() const { return curso; }
    void setCurso(Curso* curso) { this->curso = curso; }

    Alumno* getAlumno() const { return alumno; }
    void setAlumno(Alumno* alumno) { this->alumno = alumno; }
};

int main() {

    Curso curso1("Calculo","01","Ing. Pedro");
    Alumno alumno1("Juan", 12345);
    Matricula matricula1(&curso1, &alumno1);
    cout << "Curso: " << matricula1.getCurso()->getNombre() << endl;
    cout << "Alumno inscrito: " << matricula1.getAlumno()->getNombre()<<" Codigo: " <<matricula1.getAlumno()->getCodigoAlum()<< endl;
    return 0;
}
