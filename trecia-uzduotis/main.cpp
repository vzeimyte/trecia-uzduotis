#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;

void myguku_turinio_meniu(string nav[], int pasirinkimas);
void svetaines_antrastes_pavadinimas(string title);
void nav_laukeliu_pavadinimai(string nav[]);
void prideti_nuotrauka(string url_adresas);
void vardas_viduryje(string vardas_pavarde);
void supildyti_profesija(string profesija);
void navigacijos_elementu_redaktorius(string nav[]);

int main()
{
    string title;
    string profesija;
    string photo_url;
    string nav_mygtukai[3];

    cout << "--------------------------------------------\n";
    cout << "                                            \n";
    cout << "           PAGRINDINE INFORMACIJA           \n";
    cout << "                                            \n";
    cout << "--------------------------------------------\n\n";
    cout << "Jusu vardas ir pavarde (Privaloma): ";
    getline(cin, title);

    cout << "\nJusu dabartine arba anorima profesija: ";
    getline(cin, profesija);

    cout << "\nJusu nuotraukos URL nuoroda: ";
    cin >> photo_url;

    cout << "\n Suveskite 3 norimos navigacinius mygtukus\n";
    cin.ignore();

    for (int i = 0; i < 3; i++)
    {
        getline(cin, nav_mygtukai[i]);
    }

    svetaines_antrastes_pavadinimas(title);
    nav_laukeliu_pavadinimai(nav_mygtukai);
    prideti_nuotrauka(photo_url);
    vardas_viduryje(title);
    supildyti_profesija(profesija);
    navigacijos_elementu_redaktorius(nav_mygtukai);

    ofstream failas("index2.html", ios::app);
    failas << "</body></html>";
}
void supildyti_profesija(string profesija)
{

    string profesijos_html_start = "<!-- Masthead Subheading-->"
                                   "<p class=\"masthead-subheading font-weight-light mb-0\">";
    string profesijos_html_end = "</p>\n"
                                 "</div>\n"
                                 "</header>\n";

    ofstream failas("index2.html", ios::app);
    failas << profesijos_html_start << profesija << profesijos_html_end;
}
void svetaines_antrastes_pavadinimas(string title)
{

    const string html_pradzia1 = "<!DOCTYPE html>\n"
                                 "<html lang=\"en\">\n"
                                 "<head>\n"
                                 "<meta charset=\"utf-8\" />/n"
                                 "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\" />\n"
                                 "<meta name=\"description\" content=\"\" />\n"
                                 "<meta name=\"author\" content=\"\" />\n"
                                 "<title>";
    const string html_pradzia2 = "</title>\n"
                                 "<link rel=\"icon\" type=\"image/x-icon\" href=\"assets/favicon.ico\" />\n"
                                 "<script src=\"https://use.fontawesome.com/releases/v6.1.0/js/all.js\" crossorigin=\"anonymous\"></script>\n"
                                 "<link href=\"https://fonts.googleapis.com/css?family=Montserrat:400,700\" rel=\"stylesheet\" type=\"text/css\" />\n"
                                 "<link href=\"https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic\" rel=\"stylesheet\" type=\"text/css\" />\n"
                                 "<link href=\"css/styles.css\" rel=\"stylesheet\" />\n"
                                 "</head>\n";

    const string home_page_pradzia1 = "<body id=\"page-top\">\n"
                                      "<nav class=\"navbar navbar-expand-lg bg-secondary text-uppercase fixed-top\" id=\"mainNav\">\n"
                                      "<div class=\"container\">\n"
                                      "<a class=\"navbar-brand\" href=\"#page-top\">";

    const string home_page_pradzia2 = "</a>\n"
                                      "<button class=\"navbar-toggler text-uppercase font-weight-bold bg-primary text-white rounded\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarResponsive\" aria-controls=\"navbarResponsive\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n"
                                      "Menu\n"
                                      "<i class=\"fas fa-bars\"></i>"
                                      "</button>\n";

    ofstream failas;
    failas.open("index2.html");

    failas << html_pradzia1 << title << " CV" << html_pradzia2 << home_page_pradzia1 << title << " CV" << home_page_pradzia2;
}

void vardas_viduryje(string vardas_pavarde)
{
    string vardas_viduryje_start = "<!-- Masthead Heading-->"
                                   "<h1 class=\"masthead-heading text-uppercase mb-0\">";
    string vardas_viduryje_end = "</h1>\n"
                                 "<!-- Icon Divider-->"
                                 "<div class=\"divider-custom divider-light\">\n"
                                 "\t<div class=\"divider-custom-line\"></div>\n"
                                 "\t<div class=\"divider-custom-icon\"><i class=\"fas fa-star\"></i></div>\n"
                                 "\t<div class=\"divider-custom-line\"></div>\n"
                                 "</div>\n";
    ofstream failas("index2.html", ios::app);
    failas << vardas_viduryje_start << vardas_pavarde << vardas_viduryje_end;
}

void prideti_nuotrauka(string url_adresas)
{
    string photo_html_start = "<!-- Masthead-->"
                              "<header class=\"masthead bg-primary text-white text-center\">\n"
                              "<div class=\"container d-flex align-items-center flex-column\">\n"
                              "<!-- Masthead Avatar Image-->"
                              "<img class=\"masthead-avatar mb-5\" src=\"";

    ofstream failas("index2.html", ios::app);
    failas << photo_html_start << url_adresas << "\" alt=\"...\" />\n";
}
void myguku_turinio_meniu(string nav[], int pasirinkimas)
{
    cout << "\n-----------------------------\n";
    cout << "                             \n";
    cout << "      " << nav[pasirinkimas] << " TURINIO REDAGAVIMAS     \n";
    cout << "                             \n";
    cout << "-----------------------------\n\n";
    cout << " 1. Prideti antraste\n";
    cout << " 2 . Prideti paragrafa\n";
    cout << " 3. Prideti lentele\n";
    cout << " 4. Prideti forma\n";
    cout << " 5. Prideti mygtuka\n";
    cout << " 6. PRideti nuotrauku galerija \n";
}

void nav_laukeliu_pavadinimai(string nav[])
{
    string nav_start = "<div class=\"collapse navbar-collapse\" id=\"navbarResponsive\">\n"
                       "<ul class=\"navbar-nav ms-auto\">\n";
    string nav_end = "</ul>\n"
                     "</div>\n"
                     "</div>\n"
                     "</nav>\n";
    string middle_start = "<li class=\"nav-item mx-0 mx-lg-1\"><a class=\"nav-link py-3 px-0 px-lg-3 rounded\" href=\"";
    string middle_end = "</a></li>\n";

    ofstream failas("index2.html", ios::app);
    failas << nav_start;

    for (int i = 0; i < 3; i++)
    {
        ofstream failas("index2.html", ios::app);
        failas << middle_start << nav[i] << ".html"
               << "\">" << nav[i] << middle_end;
    }
    failas << nav_end;
}

void navigacijos_elementu_redaktorius(string nav[])
{
    cout << "--------------------------------------------\n";
    cout << "                                            \n";
    cout << "      NAVIGACIJOS MYGTUKU REDAKTORIUS       \n";
    cout << "                                            \n";
    cout << "--------------------------------------------\n\n";
    // KODEl du kart reikia enter??
    cin.ignore();
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << nav[i] << endl;
        ofstream failas(nav[i] + ".html");
        failas << "<html><head><link href=\"css/styles.css\" rel=\"stylesheet\" /></head><body>";
    }
    int pasirinkimas;
    cout << "\nKurio mygtuko turini noretumete supildyti?Iveskite skaiciu.\n";
    cin >> pasirinkimas;

    cout << "\n-----------------------------------------\n";
    cout << "                                           \n";
    cout << "     " << nav[pasirinkimas - 1] << " ELEMENTU SARASAS             \n";
    cout << "                                           \n";
    cout << "-----------------------------------------\n\n";
    cout << "1. Prideti mygtuka \n";
    cout << "2. Prideti antraste \n";
    cout << "3. Prideti paragrafa \n";
    cout << "4. Prideti lentele \n";

    int elemento_pasirinkimas;
    string mygtuko_pavadinimas;
    int antrastes_dydis;
    string antraste;
    string paragrafas;
    string testi = "Y";

    while (testi == "Y" or testi == "y")
    {
        cout << "Pasirinkite koki elementa norite prideti:\n";
        cin >> elemento_pasirinkimas;
        switch (elemento_pasirinkimas)
        {
        case 1:
        {
            cout << "Iveskite mygtuko pavadinima: ";
            cin >> mygtuko_pavadinimas;

            ofstream failas(nav[pasirinkimas - 1] + ".html", ios::app);
            failas << "<button class=\"btn btn-primary btn-xl\">" << mygtuko_pavadinimas << "</button>";
            break;
        }
        case 2:
        {
            cout << "Pasirinkite antrastes dydi nuo 1-6. 1 - didziausia, 6 - maaziausia.";
            cin >> antrastes_dydis;

            cin.ignore();
            cout << "Irasykite antraste";
            getline(cin, antraste);

            ofstream failas(nav[pasirinkimas - 1] + ".html", ios::app);
            failas << "<h" << antrastes_dydis << ">" << antraste << "</h" << antrastes_dydis << ">";
            break;
        }
        case 3:
        {
            cin.ignore();
            cout << "Irasykite pragrafo teksta: ";
            getline(cin, paragrafas);

            ofstream failas(nav[pasirinkimas - 1] + ".html", ios::app);
            failas << "<p>" << paragrafas << "</p>\n";
            break;
        }
        case 4:
        {
            int col;
            int rows;
            string col_name;
            string row_name;

            cout << "Iveskite kiek lenteleje bus stulpeliu: ";
            cin >> col;

            ofstream failas(nav[pasirinkimas - 1] + ".html", ios::app);
            failas << "<table><tr>\n";

            for (int i = 0; i < col; i++)
            {
                cout << "Iveskite " << i + 1 << " stulpelio pavadinima: ";
                cin >> col_name;

                failas << "<th>" << col_name << "</th>\n";
            }
            failas << "</tr>\n";
            // Ciklas eiluciu ivedimui sustoja!!!!!!!!!!!!!!!!
            string done = "Y";
            while (done == "Y" or testi == "y")
            {

                for (int i = 0; i < col; i++)
                {
                    cout << "Iveskite eilutes "
                         << i + 1
                         << " laukeli";
                    cin >> row_name;

                    failas << "<td>" << row_name << "</td>\n";
                }
                failas << "</tr>";
                cout << "Norite ivesti dar vbiena eilute? Y/N ";
                cin >> done;
            }

            failas << "</table>";
            break;
        }

        default:
            break;
        }
        cout << "Ar norite prideti dar elementu? Y/N ";
        cin >> testi;
    }
}
