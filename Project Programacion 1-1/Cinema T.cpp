#include <iostream>
using namespace std;


class Movie {
private:
    string name;
    int year;
    int time;
    string country;
    int reviews;
    bool withData = false;

public:
    Movie() {

    }

    Movie(string name, int year, int time, string country, int reviews) {
        this->name = name;
        this->year = year;
        this->time = time;
        this->country = country;
        this->reviews = reviews;
    }

    string getName() { return name; }
    int getYear() { return year; }
    int getTime() { return time; }
    string getCountry() { return country; }
    int getReviews() { return reviews; }
    bool getWithData() { return withData; }


    void setName(string n) { name = n; }
    void setYear(int ye) { year = ye; }
    void setTime(int t) { time = t; }
    void setCountry(string c) { country = c; }
    void setReviews(int r) { reviews = r; }
    void setWithData(bool wd) { withData = wd; }
};

class Seat {
private:
    int id;
    bool state;

public:

    Seat() {
        this->state = false;
    }
    void setState(bool estado) {
        state = estado;
    }
    int getId() {
        return id;
    }
    bool getState() {
        return state;
    }


};

class Room {
private:
    int id;
    int seatsNumber;
    double price;
    Seat roomSeats[5][5];

public:

    Room() {

    }


    Room(int id, int seatsNumber, double price) {
        this->id = id;
        this->seatsNumber = seatsNumber;
        this->price = price;
    }

    double getPrice() {
        return this->price;
    }
    int getId() {
        return this->id;
    }
    int getSeat() {
        return this->seatsNumber; 
    }

    void printSeats() {
        

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (roomSeats[i][j].getState() == false) {
                    cout << 0 << " ";
                }
                else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }


    }
    void buySeat() {
        int x, y;
        printSeats();
        roomSeats[x][y].setState(true);
        cout << endl;
        printSeats();
    }
};

class Schedule {
private:
    string date;
    int startHour;
    int endHour;
    Movie movie;
    Room room;

public:

    Schedule() {

    }

    Schedule(string date, int startHour, int endHour, Movie movie, Room room) {
        this->date = date;
        this->startHour = startHour;
        this->endHour = endHour;
        this->movie = movie;
        this->room = room;
    }

    Movie getMovie() {
        return this->movie;
    }

    Room getRoom() {
        return this->room;
    }

    string getDate() {
        return this->date;
    }
    int getStartHour() {
        return this->startHour;
    }
    int getEndHour() {
        return this->endHour;
    }
};

class Booking {
private:
    Schedule schedule;
    Seat bookSeats[5];
    double totalPrice;
    int bookingNumber;

public:

};

class Sale {
private:
    Booking booking; 
    string idCustomer;
    string cardNumber;

public:

};

class Cinema {
private:
    Movie cinemaMovies[4];
    Room cinemaRooms[4];
    Schedule cinemaSchedules[4];
    Booking cinemaBookings[50];
    Sale sales[50];

public:
    Cinema() {
        generateMovies();
        generateRooms();
        generateSchedules();
       // generateSeats(); para asignarles numeros y estados a cada asiento
    }

    void print() {

        int option, optionA;

        do {
            showMenu();
            cin >> option;

            switch (option) {
            case 1:
                cout << "1-Acerca de. " << endl <<
                    "2-Salir. " << endl;
                cin >> optionA;
                if (optionA == 1) {
                    cout << "Este programa fue creado por el estudiante Abdel Marin Quesada" << endl;
                }
                else if (optionA == 2) {
                    cout << "Saliendo del sistema...\n";
                    break;
                }
                else {
                    cout << "Opcion invalida";
                    break;
                }
                break;
            case 2:
                cout << "Peliculas: " << endl;
                cout << "Pelicula: " << cinemaSchedules[0].getMovie().getName() << "\n";
                cout << "Anio: " << cinemaSchedules[0].getMovie().getYear() << "\n";
                cout << "Duracion: " << cinemaSchedules[0].getMovie().getTime() << " horas." << "\n";
                cout << "Nacionalidad: " << cinemaSchedules[0].getMovie().getCountry() << "\n";
                cout << "Resenias: " << cinemaSchedules[0].getMovie().getReviews() << "\n";

                cout << "Pelicula: " << cinemaSchedules[1].getMovie().getName() << "\n";
                cout << "Anio: " << cinemaSchedules[1].getMovie().getYear() << "\n";
                cout << "Duracion: " << cinemaSchedules[1].getMovie().getTime() << " horas." << "\n";
                cout << "Nacionalidad: " << cinemaSchedules[1].getMovie().getCountry() << "\n";
                cout << "Resenias: " << cinemaSchedules[1].getMovie().getReviews() << "\n";

                cout << "Pelicula: " << cinemaSchedules[2].getMovie().getName() << "\n";
                cout << "Anio: " << cinemaSchedules[2].getMovie().getYear() << "\n";
                cout << "Duracion: " << cinemaSchedules[2].getMovie().getTime() << " horas." << "\n";
                cout << "Nacionalidad: " << cinemaSchedules[2].getMovie().getCountry() << "\n";
                cout << "Resenias: " << cinemaSchedules[2].getMovie().getReviews() << "\n";

                cout << "Pelicula: " << cinemaSchedules[3].getMovie().getName() << "\n";
                cout << "Anio: " << cinemaSchedules[3].getMovie().getYear() << "\n";
                cout << "Duracion: " << cinemaSchedules[3].getMovie().getTime() << " horas." << "\n";
                cout << "Nacionalidad: " << cinemaSchedules[3].getMovie().getCountry() << "\n";
                cout << "Resenias: " << cinemaSchedules[3].getMovie().getReviews() << "\n\n";
                cout << "Informacion de las salas: " << endl;

                cout << "Numero de sala: " << cinemaSchedules[0].getRoom().getId() << "\n";
                cout << "Numero de asientos: " << cinemaSchedules[0].getRoom().getSeat() << "\n";
                cout << "Precio: " << cinemaSchedules[0].getRoom().getPrice() << "\n";

                cout << "Numero de sala: " << cinemaSchedules[1].getRoom().getId() << "\n";
                cout << "Numero de asientos: " << cinemaSchedules[1].getRoom().getSeat() << "\n";
                cout << "Precio: " << cinemaSchedules[1].getRoom().getPrice() << "\n";
                cout << "Informacion de los horarios: " << endl;

                cout << "Fecha: " << cinemaSchedules[0].getDate();
                cout << "Hora de inicio: " << cinemaSchedules[0].getStartHour();
                cout << "Hora de final: " << cinemaSchedules[0].getEndHour();

                cout << "Fecha: " << cinemaSchedules[1].getDate();
                cout << "Hora de inicio: " << cinemaSchedules[1].getStartHour();
                cout << "Hora de final: " << cinemaSchedules[1].getEndHour();

                cout << "Fecha: " << cinemaSchedules[2].getDate();
                cout << "Hora de inicio: " << cinemaSchedules[2].getStartHour();
                cout << "Hora de final: " << cinemaSchedules[2].getEndHour();

                cout << "Fecha: " << cinemaSchedules[3].getDate();
                cout << "Hora de inicio: " << cinemaSchedules[3].getStartHour();
                cout << "Hora de final: " << cinemaSchedules[3].getEndHour();

                break;
            case 3:

                break;
            case 4:
                cout << "Funcion de venta no implementada.\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
            }
        } while (option != 4);


        int optionP;

        cin >> option;

        cout << "Seleccione la pelicula deseada: " << "\n";
        cout << "Pelicula: " << cinemaSchedules[1].getMovie().getName() << "\n";
        cout << "Sala: " << cinemaSchedules[1].getRoom().getId() << "\n";
        cout << "Fecha: " << cinemaSchedules[1].getStartHour() << "- " << cinemaSchedules[1].getEndHour() << "\n";

    }

    void generateMovies() {
        Movie movie1("Ben 10", 2024, 2, "USA", 10);
        cinemaMovies[0] = movie1;

        Movie movie2("SharkBoy and LavaGirld", 2022, 1, "USA", 7);
        cinemaMovies[1] = movie2;

        Movie movie3("Arthur y Los Minimoys", 2021, 3, "Mexico", 9);
        cinemaMovies[2] = movie3;

        Movie movie4("El Castillo Ambulante", 2024, 2, "JAPON", 3);
        cinemaMovies[3] = movie4;
    }

    void generateRooms() {
        Room room1(1, 25, 4000);
        cinemaRooms[0] = room1;
        cinemaRooms[2] = room1;

        Room room2(2, 25, 4000);
        cinemaRooms[1] = room2;
        cinemaRooms[3] = room2;

    }

    void generateSchedules() {
        Schedule schedule1("27/07/2018", 6, 8, cinemaMovies[0], cinemaRooms[0]);
        cinemaSchedules[0] = schedule1;

        Schedule schedule2("22/02/2000", 6, 8, cinemaMovies[0], cinemaRooms[0]);
        cinemaSchedules[0] = schedule1;

        Schedule schedule3("19/08/2004", 6, 8, cinemaMovies[0], cinemaRooms[0]);
        cinemaSchedules[0] = schedule1;

        Schedule schedule4("17/06/2014", 6, 8, cinemaMovies[0], cinemaRooms[0]);
        cinemaSchedules[0] = schedule1;
    }
    void test() {
        cinemaRooms[1].buySeat();

    }
    void showMenu() {
        cout << "Menu: " << endl <<
            "1) Archivo. " << endl <<
            "2) Mantenimiento. " << endl <<
            "3) Reserva. " << endl <<
            "4) Venta. " << endl;

    }


};

int main()
{

    Cinema cinema;
    //cinema.print();
    cinema.test();


    cout << "\n\n\n\n";
    return 0;
}