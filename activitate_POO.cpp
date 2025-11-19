#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//TEMA1
class Pacient {
public:
	string nume;
	int varsta;
	double* greutate;
	static int nrPacienti;
	const string categorie;
	bool inRecuperare;

	Pacient() : categorie("adult") {
		nume = "Anonim";
		varsta = 30;
		greutate = new double(70.5);
		inRecuperare = true;
		nrPacienti++;
	}

	Pacient(string n, int v) : categorie("senior") {
		nume = n;
		varsta = v;
		greutate = new double(80.0);
		inRecuperare = false;
		nrPacienti++;
	}

	Pacient(string n, int v, double g, bool r, string c) : categorie(c) {
		nume = n;
		varsta = v;
		greutate = new double(g);
		inRecuperare = r;
		nrPacienti++;
	}

	static void AfisareNrPacienti() {
		cout << "Numar total de pacienti: " << nrPacienti << endl;
	}

	void Afisare() {
		cout << "Pacient: " << nume
			<< ", varsta: " << varsta
			<< ", greutate: " << *greutate << " kg"
			<< ", categorie: " << categorie
			<< ", in recuperare: " << (inRecuperare ? "da" : "nu") << endl;
	}

	~Pacient() {
		delete greutate;
	}
};
int Pacient::nrPacienti = 0;

class Exercitiu {
public:
	string denumire;
	int repetari;
	double* durata;
	static int nrExercitii;
	const string scop;
	bool asistat;

	Exercitiu() : scop("mobilitate") {
		denumire = "Genuflexiuni";
			repetari = 10;
		durata = new double(2.0);
		asistat = true;
		nrExercitii++;
	}

	Exercitiu(string d, int r) : scop("echilibru") {
		denumire = d;
		repetari = r;
		durata = new double(1.5);
		asistat = false;
		nrExercitii++;
	}

	Exercitiu(string d, int r, double du, bool a, string s) : scop(s) {
		denumire = d;
		repetari = r;
		durata = new double(du);
		asistat = a;
		nrExercitii++;
	}

	static int TotalRepetari(Exercitiu e1, Exercitiu e2, Exercitiu e3) {
		return e1.repetari + e2.repetari + e3.repetari;
	}

	void Afisare() {
		cout << "Exercitiu: " << denumire
			<< ", repetari: " << repetari
			<< ", durata: " << *durata << " min"
			<< ", scop: " << scop
			<< ", asistat: " << (asistat ? "da" : "nu") << endl;
	}

	~Exercitiu() {
		delete durata;
	}
};
int Exercitiu::nrExercitii = 0;

class Echipament {
public:
	string tip;
	string marca;
	double* greutate;
	static int nrEchipamente;
	const string material;
	bool functional;

	Echipament() : material("otel") {
		tip = "Bicicleta ergonomica";
		marca = "KinetPro";
		greutate = new double(25.0);
		functional = true;
		nrEchipamente++;
	}

	Echipament(string t, string m) : material("plastic") {
		tip = t;
		marca = m;
		greutate = new double(5.0);
		functional = false;
		nrEchipamente++;
	}

	Echipament(string t, string m, double g, bool f, string mat) : material(mat) {
		tip = t;
		marca = m;
		greutate = new double(g);
		functional = f;
		nrEchipamente++;
	}

	static double MedieGreutate(Echipament e1, Echipament e2, Echipament e3) {
		return (*e1.greutate + *e2.greutate + *e3.greutate) / 3;
	}

	void Afisare() {
		cout << "Echipament: " << tip
			<< ", marca: " << marca
			<< ", greutate: " << *greutate << " kg"
			<< ", material: " << material
			<< ", functional: " << (functional ? "da" : "nu") << endl;
	}

	~Echipament() {
		delete greutate;
	}
};
int Echipament::nrEchipamente = 0;
//TEMA2
class Pacient2 {
private:
	string nume;
	int varsta;
	double* greutate;
	bool inRecuperare;

public:
	Pacient2() : nume("Anonim"), varsta(30), greutate(new double(70)), inRecuperare(true) {}
	Pacient2(string n, int v) : nume(n), varsta(v), greutate(new double(80)), inRecuperare(false) {}
	Pacient2(string n, int v, double g, bool r)
		: nume(n), varsta(v), greutate(new double(g)), inRecuperare(r) {
	}

	Pacient2(const Pacient2& p) {
		nume = p.nume;
		varsta = p.varsta;
		greutate = new double(*p.greutate);
		inRecuperare = p.inRecuperare;
	}

	string getNume() const { return nume; }
	double getGreutate() const { return *greutate; }
	void setGreutate(double g) { *greutate = g; }

	friend double IndiceRecuperare(const Pacient2& p);

	void Afisare() const {
		cout << "Pacient2: " << nume << ", " << varsta
			<< " ani, " << *greutate << " kg\n";
	}

	~Pacient2() { delete greutate; }
};

double IndiceRecuperare(const Pacient2& p) {
	return p.varsta / *p.greutate;
}

class Exercitiu2 {
private:
	string denumire;
	int repetari;
	double* durata;

public:
	Exercitiu2() : denumire("Genuflexiuni"), repetari(10), durata(new double(2)) {}
	Exercitiu2(string d, int r) : denumire(d), repetari(r), durata(new double(1.5)) {}

	Exercitiu2(const Exercitiu2& e) {
		denumire = e.denumire;
		repetari = e.repetari;
		durata = new double(*e.durata);
	}

	double getDurata() const { return *durata; }

	friend double DifDurata(const Exercitiu2&, const Exercitiu2&);

	void Afisare() const {
		cout << "Ex2: " << denumire << ", rep: " << repetari
			<< ", durata: " << *durata << endl;
	}

	~Exercitiu2() { delete durata; }
};

double DifDurata(const Exercitiu2& e1, const Exercitiu2& e2) {
	return *e1.durata - *e2.durata;
}

class Echipament2 {
private:
	string tip;
	double* greutate;

public:
	Echipament2() : tip("Bicicleta"), greutate(new double(25)) {}
	Echipament2(string t, double g) : tip(t), greutate(new double(g)) {}

	Echipament2(const Echipament2& e) {
		tip = e.tip;
		greutate = new double(*e.greutate);
	}

	double getGreutate() const { return *greutate; }

	friend double Medie3(const Echipament2&, const Echipament2&, const Echipament2&);

	void Afisare() const {
		cout << "Eq2: " << tip << " (" << *greutate << " kg)\n";
	}

	~Echipament2() { delete greutate; }
};

double Medie3(const Echipament2& a, const Echipament2& b, const Echipament2& c) {
	return (*a.greutate + *b.greutate + *c.greutate) / 3;
}

int main() {
	cout << "=== Domeniu: Geokinetica (Gheorghe Karina) ===\n\n";

		Pacient p1;
	Pacient p2("Ion Popescu", 65);
	Pacient p3("Maria Georgescu", 40, 58.5, true, "adult");
	p1.Afisare(); p2.Afisare(); p3.Afisare();
	Pacient::AfisareNrPacienti();
	cout << endl;

	Exercitiu e1;
	Exercitiu e2("Ridicari pe varfuri", 15);
	Exercitiu e3("Extensii brate", 20, 3.5, true, "forta");
	e1.Afisare(); e2.Afisare(); e3.Afisare();
	cout << "Total repetari: " << Exercitiu::TotalRepetari(e1, e2, e3) << endl << endl;

	Echipament eq1;
	Echipament eq2("Banda de alergare", "Kinetix");
	Echipament eq3("Minge medicinala", "TheraBand", 3.0, true, "cauciuc");
	eq1.Afisare(); eq2.Afisare(); eq3.Afisare();
	cout << "Greutate medie echipamente: "
		<< Echipament::MedieGreutate(eq1, eq2, eq3) << " kg\n";

	Pacient2 pp1;
	Pacient2 pp2("Karina", 22);
	Pacient2 pp3(pp2);
	pp1.Afisare();
	cout << "Indice recuperare: " << IndiceRecuperare(pp1) << endl;

	Exercitiu2 ex21;
	Exercitiu2 ex22("Flotari", 20);
	cout << "Dif durata = " << DifDurata(ex21, ex22) << endl;

	Echipament2 eq21;
	Echipament2 eq22("Minge", 3);
	Echipament2 eq23(eq22);
	cout << "Medie = " << Medie3(eq21, eq22, eq23) << endl;

		return 0;
}
