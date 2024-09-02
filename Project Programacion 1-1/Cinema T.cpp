

#include <iostream>
using namespace std;

//private, public y protected

class Movie {
    private:
        string name;
            int year;
            int time;
        string country;
            int reviews; //Del 0 al 10
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

    // Getters
    string getName() { return name; }
    int getYear() { return year; }
    int getTime() { return time; }
    string getCountry() { return country; }
    int getReviews() { return reviews; }
    bool getWithData() { return withData; }

    // Setters
    void setName(string n) { name = n; }
    void setYear(int y) { year = y; }
    void setTime(int t) { time = t; }
    void setCountry(string c) { country = c; }
    void setReviews(int r) { reviews = r; }
    void setWithData(bool wd) { withData = wd; }
};

class Seat {
    private:
        int id;
        string state; //Disponible | Reservada | Vendida

        public:

            Seat() {
                this->state = "DIS";
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
};

class Schedule {
private:
    string date;
    int startHour;
    int endHour;
    Movie movie; //*
    Room room; //*

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
};

class Booking {
private:
    Schedule schedule; //*
    Seat bookSeats[5]; //Limite de 5 asientos por reserva
    double totalPrice;
    int bookingNumber;

public:

};

class Sale {
private:
    Booking booking; //*
    string idCustomer;
    string cardNumber;

public:

};

class Cinema {
private:
    Movie cinemaMovies[4]; // * * * * * . . . . .
    Room  cinemaRooms[2];
    Schedule cinemaSchedules[4];
    Booking cinemaBookings[50];
    Sale sales[50];

public:
    Cinema() {
        generateMovies();
        generateRooms();
        generateSchedules();
    }

    void print() {
        cout << "Seleccione su horario: " << "\n";
        cout << "Fecha: " << cinemaSchedules[0].getDate() << "\n";
        cout << "Pelicula: " << cinemaSchedules[0].getMovie().getName() << "\n";
        cout << "Sala: " << cinemaSchedules[0].getRoom().getPrice() << "\n";

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

        Room room2(2, 25, 4000);
        cinemaRooms[1] = room2;
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

    void addMovie() {
        int moviesNumber = 0;
        cout << "Numero de peliculas?? ";
        cin >> moviesNumber;

        if (moviesNumber < 1 || moviesNumber > 10) {
            return;
        }

        string name = "", country = "";
        int year = 0, time = 0, reviews = 0;
        for (int index = 0; index < moviesNumber; index++) {
            if (!cinemaMovies[index].getWithData()) {
                cout << "Name: ";
                cin >> name;
                cout << "Year: ";
                cin >> year;
                cout << "Time: ";
                cin >> time;
                cout << "Reviews: ";
                cin >> reviews;
                cout << "Country: ";
                cin >> country;

                //Almacena
                cinemaMovies[index].setName(name);
                cinemaMovies[index].setYear(year);
                cinemaMovies[index].setTime(time);
                cinemaMovies[index].setReviews(reviews);
                cinemaMovies[index].setCountry(country);
                cinemaMovies[index].setWithData(true);
            }
        }

    }
};

int main()
{
    Cinema cinema;
    cinema.print();
    cout << "\n\n\n\n";
    return 0;
}