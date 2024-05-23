/* Incluye todo lo necesario y más */
#include <bits/stdc++.h>
/* Incluye implementaciones de algunos algoritmos útiles */
#include <algorithm>

/* Para no tener que poner std:: cada rato */
using namespace std;

/* Funcion que imprime un vector con su nombre */
void printv(vector<int> v, string s);
/* Funcion que imprime un vector con su nombre y los indices de sus elementos */
void printvi(vector<int> v, string s);
/* Funcion que imprime un vector con su nombre y N en los elementos vacios (0 en este caso) */
void printvn(vector<int> v, string s);

/* Funcion que convierte un vector a svg */
string svgv(vector<int> v, string s);
/* Funcion que convierte un vector a svg con sus indices */
string svgvi(vector<int> v, string s);
/* Funcion que convierte un vector a svg sin elementos vacios (0 en este caso) */
string svgvn(vector<int> v, string s);

string svg = "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";

int main()
{
  /* Funciones para mejorar la velocidad de impresión */
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  srand(time(NULL));

  /* Reservar memoria para el svg */
  svg.reserve(200000);

  /* Valores mínimo y máximo para los números aleatorios */
  int lb = 1;
  int ub = 7;

  /* Cantidad de números a generar */
  int n = 30;

  /* Asegurar que sea múltiplo de 3 para que cada número aparezca 3 veces */
  if (n % 3 != 0)
  {
    n += 3 - (n % 3);
  }

  svg.append("<svg version=\"1.1\" width=\"");
  svg.append(to_string(15*(n + ub + 1) + 20));
  svg.append("\" height=\"");
  svg.append(to_string(30*(n + 2) + 20));
  svg.append("\">\n");

  /* Vector en el que se van a guardar los n números */
  vector<int> l(n);

  /* Generar un número aleatorio (en nuestro rango definido) y meterlo 3 veces al vector */
  for (int i = 0; i < n; i+=3)
  {
    int z = (rand() % (ub - lb + 1)) + lb;
    l[i] = z;
    l[i+1] = z;
    l[i+2] = z;
  }

  /* Usar una función ya implementada para desordenar el vector */
  shuffle(l.begin(), l.end(), random_device());

  /* Imprimir el vector */
  printv(l, "L");
  svg.append("<g transform=\"translate(5,5)\">\n");
  svg.append(svgv(l, "L"));
  svg.append("\n</g>\n");

  /* Vector auxiliar contador para contar el número de apariciones
   * (cuenta las apariciones de 0 a ub por lo que necesitamos un espacio extra para el 0) */
  vector<int> c(ub+1);

  /* Para cada elemento de l añadir 1 al contador de ese elemento */
  for (int e : l)
  {
    c[e]++;
  }

  /* Imprimir el vector (junto con sus índices) */
  printvi(c, "C");
  svg.append("<g transform=\"translate("+to_string(15*l.size() + 15)+", 5)\">\n");
  svg.append(svgvi(c, "C"));
  svg.append("\n</g>\n");

  cout << "---------------\n";

  /* Estimar la cantidad de elementos menores al número sumando los valores contiguos */
  for (int i = 1; i < c.size(); i++)
  {
    c[i] = c[i] + c[i-1];
  }

  /* Imprimir el vector con indices */
  printvi(c, "C");
  svg.append("<g transform=\"translate("+to_string(15*l.size() + 15)+", 35)\">\n");
  svg.append(svgvi(c, "C"));
  svg.append("\n</g>\n");

  /* Vector que contendrá la secuencia ordenada */
  vector<int> b(n);

  /* Imprimir vector (poniendo una N en los elementos vacios) */
  printvn(b, "B");
  svg.append("<g transform=\"translate(5,35)\">\n");
  svg.append(svgvn(b, "B"));
  svg.append("\n</g>\n");

  /* Recorremos los elementos del vector original
   * (en este caso en reversa ya que así está implementado en las notas
   *  pero también podría ser de manera normal) */
  for (int i = n-1; i >= 0; i--)
  {
    int j = 30*(n-i + 1) + 30;
    int j2 = 30*(n-i + 1) + 5;
    /* Mostramos el número de iteracion */
    cout << "I" << n-i << ": --------\n";
    svg.append("<text fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" x=\"8\" y=\"");
    svg.append(to_string(j));
    svg.append("\"> I");
    svg.append(to_string(n-i));
    svg.append("</text>\n");

    /* Obtenemos la posición del elemento con ayuda del vector auxiliar
     * (le restamos 1 ya que iniciamos los índices con 0) */
    int p = c[l[i]] - 1;

    /* Ponemos el elemento en la nueva lista en su posición correcta */
    b[p] = l[i];
    /* Actualizamos el vector auxiliar para reflejar el cambio */
    c[l[i]]--;

    /* Imprimimos los vectores actualizados */
    printvi(c, "C");
    svg.append("<g transform=\"translate(");
    svg.append(to_string(15*l.size() + 15));
    svg.append(", ");
    svg.append(to_string(j2));
    svg.append(")\">\n");
    svg.append(svgvi(c, "C"));
    svg.append("\n</g>\n");
    printvn(b, "B");
    svg.append("<g transform=\"translate(");
    svg.append(to_string(5));
    svg.append(", ");
    svg.append(to_string(j2));
    svg.append(")\">\n");
    svg.append(svgvn(b, "B"));
    svg.append("\n</g>\n");
  }

  svg.append("</svg>");

  ofstream file("countsort.svg");
  file << svg;
  file.close();
}


/* Funcion que imprime un vector con su nombre */
void printv(vector<int> v, string s)
{
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
}

/* Funcion que imprime un vector con su nombre y los indices de sus elementos */
void printvi(vector<int> v, string s)
{
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << i << ":" << v[i];
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
}

/* Funcion que imprime un vector con su nombre y N en los elementos vacios (0 en este caso) */
void printvn(vector<int> v, string s)
{
  cout << s << ": ";
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == 0)
    {
      cout << 'N';
    } else {
      cout << v[i];
    }
    if (i + 1 != v.size())
    {
      cout << ", ";
    }
  }
  cout << '\n';
}

/* Funcion que convierte un vector a svg */
string svgv(vector<int> v, string s)
{
  string lsvg;
  lsvg.reserve(10000);
  lsvg.append("<svg width=\"");
  lsvg.append(to_string(v.size()*15));
  lsvg.append("\" height=\"");
  lsvg.append(to_string(30));
  lsvg.append("\">\n");

  lsvg.append("<text x=\"5\" y=\"5\" fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\">"+s+":</text>\n");
  for(int i = 0; i < v.size(); i++)
  {
    lsvg.append("<rect x=\"");
    lsvg.append(to_string(15*i));
    lsvg.append("\" y=\"10\" height=\"10\" width=\"15\" stroke=\"black\" fill=\"white\"/>\n");
    lsvg.append("<text fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\" y=\"15\" x=\"");
    lsvg.append(to_string(15*i + 7.5));
    lsvg.append("\">");
    lsvg.append(to_string(v[i]));
    lsvg.append("</text>\n");
  }

  lsvg.append("</svg>");
  return lsvg;
}

/* Funcion que convierte un vector a svg */
string svgvi(vector<int> v, string s)
{
  string lsvg;
  lsvg.reserve(10000);
  lsvg.append("<svg width=\"");
  lsvg.append(to_string(v.size()*15));
  lsvg.append("\" height=\"");
  lsvg.append(to_string(30));
  lsvg.append("\">\n");

  lsvg.append("<text x=\"5\" y=\"5\" fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\">"+s+":</text>\n");
  for(int i = 0; i < v.size(); i++)
  {
    lsvg.append("<rect x=\"");
    lsvg.append(to_string(15*i));
    lsvg.append("\" y=\"10\" height=\"10\" width=\"15\" stroke=\"black\" fill=\"white\"/>\n");
    lsvg.append("<text fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\" y=\"15\" x=\"");
    lsvg.append(to_string(15*i + 7.5));
    lsvg.append("\">");
    lsvg.append(to_string(v[i]));
    lsvg.append("</text>\n");
    lsvg.append("<text fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\" y=\"25\" x=\"");
    lsvg.append(to_string(15*i + 7.5));
    lsvg.append("\">");
    lsvg.append(to_string(i));
    lsvg.append("</text>\n");
  }

  lsvg.append("</svg>");
  return lsvg;
}

/* Funcion que convierte un vector a svg */
string svgvn(vector<int> v, string s)
{
  string lsvg;
  lsvg.reserve(10000);
  lsvg.append("<svg width=\"");
  lsvg.append(to_string(v.size()*15));
  lsvg.append("\" height=\"");
  lsvg.append(to_string(30));
  lsvg.append("\">\n");

  lsvg.append("<text x=\"5\" y=\"5\" fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\">"+s+":</text>\n");
  for(int i = 0; i < v.size(); i++)
  {
    lsvg.append("<rect x=\"");
    lsvg.append(to_string(15*i));
    lsvg.append("\" y=\"10\" height=\"10\" width=\"15\" stroke=\"black\" fill=\"white\"/>\n");
    if (v[i] != 0)
    {
      lsvg.append("<text fill=\"black\" font-size=\"6\" dominant-baseline=\"middle\" text-anchor=\"middle\" y=\"15\" x=\"");
      lsvg.append(to_string(15*i + 7.5));
      lsvg.append("\">");
      lsvg.append(to_string(v[i]));
      lsvg.append("</text>\n");
    }
  }

  lsvg.append("</svg>");
  return lsvg;
}
