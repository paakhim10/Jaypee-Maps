#include "path.h"
#include <fstream>
#include <iostream>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int shortestPath(int s, int d);

/**
 * A class representing a node in a linked list.
 */


void quickSort(vector<vector<int> >& vect1, int left, int right) {
    if (left >= right) {
        return;
    }
    if (right - left <= 10) {
        // Insertion Sort for small sub-vectors
        for (int i = left + 1; i <= right; i++) {
            vector<int> key = vect1[i];
            int j = i - 1;
            while (j >= left && vect1[j][vect1[j].size() - 1] < key[vect1[j].size() - 1]) {
                vect1[j + 1] = vect1[j];
                j--;
            }
            vect1[j + 1] = key;
        }
        return;
    }
    // Partition using Lomuto partition scheme
    int pivot = right;
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (vect1[j][vect1[j].size() - 1] >= vect1[pivot][vect1[pivot].size() - 1]) {
            i++;
            swap(vect1[i], vect1[j]);
        }
    }
    swap(vect1[i + 1], vect1[pivot]);
    pivot = i + 1;
    // Recursive calls to sort left and right sub-vectors
    quickSort(vect1, left, pivot - 1);
    quickSort(vect1, pivot + 1, right);
}

void hybridQuickSort(vector<vector<int> >& vect1) {
    quickSort(vect1, 0, vect1.size() - 1);
}

class travel
{

public:
  travel *next;
  travel()
  {
    this->next = NULL;
  }
};

/**
 * A class that represents navigation functionality for travel.
 */

class navigation : public travel
{

public:
  int choice2, option, count1;
  string un, uno, mydata;
  string uname, passw;

  /**
   * Simulates a walking trip between two cities.
   *
   * @returns None
   */

  void walk()
  {
    float time, avg_velocity = 20, total_distance; // distance will be assigned from filing
    string place1, place2, place3, place4, distance1, distance2;
    int op1, op2, op;
    float s1, s2;
    cout << "YOUR LOCATION: " << endl;

    ifstream data("locations.txt");
    while (getline(data, mydata))
    {
      cout << mydata << endl;
    }
    data.close();
    cin >> op1;
    ifstream d("locations.txt");
    while (d >> op >> place1)
    {

      if (op == op1)
      {
        cout << "YOUR LOCATION: " << place1 << endl;
        goto l;
      }
    }
  l:
    d.close();
    cout << "CHOOSE YOUR DESTINATION " << endl;
    cin >> op2;
    ifstream d2("locations.txt");
    while (d2 >> op >> place2)
    {

      if (op == op2)
      {

        cout << "YOUR DESTINATION:" << place2 << endl;
        goto g;
      }
    }
  g:
    d2.close();

    total_distance = shortestPath(op1, op2);
    time = total_distance / avg_velocity;
    cout << endl
         << "TIME TO REACH DESTINATION: " << time << " minutes."
         << endl;
    exit(0);
  }

  /**
   * Simulates a car journey by calculating the time it takes to travel from a starting location to a destination.
   *
   * @returns None
   */
  void car()
  {
    float time, avg_velocity = 100, distance; // distance will be assigned from filing
    string place1, place2;
    int op, op2, op3;
    int countt;
    cout << "YOUR LOCATION:" << endl;
    ifstream data("locations.txt");
    while (getline(data, mydata))
    {
      cout << mydata << endl;
    }
    data.close();
    cin >> op;
    ifstream f("locations.txt");
    while (f >> op3 >> place1)
    {
      if (op == op3)
      {
        countt = 1;
        goto w;
      }
    }
  w:
    f.close();
    if (countt == 1)
    {
      cout << "YOUR LOCATION: " << place1 << endl;
    }
    cout << "CHOOSE YOUR DESTINATION " << endl;
    cin >> op2;
    ifstream p("locations.txt");
    while (p >> op3 >> place2)
    {
      if (op2 == op3)
      {
        countt = 1;
        goto q;
      }
    }
  q:
    f.close();
    distance = shortestPath(op, op2);

    time = distance / avg_velocity;
    cout << endl
         << "\nTIME TO REACH DESTINATION: " << time << " minutes." << endl;
    exit(0);
  }

  /**
   * Simulates a cycle trip between two cities.
   *
   * @returns None
   */

  void cycle()
  {
    float time, avg_velocity = 40, total_distance; // distance will be assigned from filing
    string place1, place2, place3, place4, distance1, distance2;
    int op1, op2, op;
    float s1, s2;
    cout << "YOUR LOCATION: " << endl;

    ifstream data("locations.txt");
    while (getline(data, mydata))
    {
      cout << mydata << endl;
    }
    data.close();
    cin >> op1;
    ifstream d("locations.txt");
    while (d >> op >> place1)
    {

      if (op == op1)
      {
        cout << "YOUR LOCATION: " << place1 << endl;
        goto l;
      }
    }
  l:
    d.close();
    cout << "CHOOSE YOUR DESTINATION " << endl;
    cin >> op2;
    ifstream d2("locations.txt");
    while (d2 >> op >> place2)
    {

      if (op == op2)
      {

        cout << "YOUR DESTINATION:" << place2 << endl;
        goto g;
      }
    }
  g:
    d2.close();
    total_distance = shortestPath(op1, op2);

    time = total_distance / avg_velocity;
    cout << endl
         << "TIME TO REACH DESTINATION: " << time << " minutes." << endl;
    exit(0);
  }

  /**
   * Allows the user to sign in or sign up.
   *
   * @returns None
   */
  void user()
  {
    string username, password, user, pass;
    int count = 0;

    cout << "\nSelect the option  from below " << endl;
    cout << " 1) SIGN IN \n 2) SIGN UP " << endl;
    cin >> option;
    switch (option)
    {
    case 1:
    {
    x:
      cout << "\nEnter username: ";
      cin >> username;
      cout << "\nEnter password: ";
      cin >> password;
      ifstream myfile("userData.bin");
      while (myfile >> user >> pass)
      {
        if (user == username && pass == password)
        {
          count = 1;
          un = username;
        }
      }
      myfile.close();
      if (count == 1)
      {
        cout << "\nLogin successful" << endl;
      }

      else
      {
        cout << "Try again" << endl;
        goto x;
      }
    }
    break;

    case 2:
    {
    z:
      cout << "\nEnter username: ";
      cin >> uname;
      ifstream hello("userData.bin");
      while (hello >> uno)
      {
        if (uno == uname)
        {
          cout << "\nThe username already exists!" << endl;
          goto z;
        }
      }
      hello.close();

      cout << "\nEnter password: ";
      cin >> passw;

      ofstream file("userData.bin", ios::binary | ios::app);
      file << uname << " " << passw << endl;
      file.close();
      cout << "\nRegistration successful" << endl;
      goto x;
    }

    default:
      cout << "Invalid Selection! " << endl;
      break;
    }

    // till here
    cout << "\nSELECT MODE OF TRANSPORT: " << endl;
    cout << " 1) By walk \n 2) By car \n 3) By cycle\n";
    cin >> choice2;
    switch (choice2)
    {
    case 1:
      walk();
      break;
    case 2:
      car();

    case 3:
      cycle();

    default:
      cout << "Invalid Selection " << endl;
      break;
    }
  }

  /**
   * Computes the shortest path between two nodes in a graph using Depth First Search.
   *
   * @param s The starting node.
   * @param d The destination node.
   *
   * @returns The shortest distance between the starting and destination nodes.
   */

  int shortestPath(int s, int d)
  {
    int n = 0, m = 10, sd = 0;
    string ch;
    int vis2[10000] = {0};
    ifstream f1;
    int x, y, wt;
    vector<int> w;
    f1.open("dist_matrix.txt");

    while (f1 >> x >> y >> wt)
    {
      w.push_back(wt);
      g[x].push_back(y);
      g[y].push_back(x);
    }

    f1.close();

    vector<int> path;

    string place, place1, place2, pth;
    int op, op1, op2, w1, w2;
    path.push_back(s);
    dfs(vis2, s, d, path);

    cout << endl;

    ifstream f2;

    for (int i = 0; i < vect1.size() - 1; i++)
    {

      for (int j = 0; j < vect1.size() - i - 1; j++)
      {

        if (vect1[j][vect1[j].size() - 1] >
            vect1[j + 1][vect1[j + 1].size() - 1])
        {

          swap(vect1[j], vect1[j + 1]);
        }
      }
    }

    cout << "DISTANCE TO DESTINATION: " << endl;
    n = 0;

    for (int i = 0; i < vect1[0].size() - 1; i++)
    {
      f2.open("locations.txt");

      while (f2 >> op >> place)
      {

        if (op == vect1[0][i])
        {

          place1 = place;
          pth = pth + place + ",";
        }
      }
      f2.close();
      cout << place1 << " ";

      n = i;
    }
    cout << endl
         << endl
         << pth;

    cout << vect1[0][n + 1];
    sd = vect1[0][n + 1];
    cout << endl;
  i:
    cout << "\nARE YOU FACING ANY BARRIERS IN THIS WAY? 'YES OR NO'" << endl;
    cin >> ch;
    if (ch == "yes" || ch == "Yes" || ch == "YES")
    {

      for (int i = 0; i < vect1.size() - 1; i++)
      {

        for (int j = 0; j < vect1.size() - i - 1; j++)
        {

          if (vect1[j][vect1[j].size() - 1] <
              vect1[j + 1][vect1[j + 1].size() - 1])
          {

            swap(vect1[j], vect1[j + 1]);
          }
        }
      }
      // hybridQuickSort(vect1);
      vect1.pop_back();
      for (int i = 0; i < vect1.size() - 1; i++)
      {

        for (int j = 0; j < vect1.size() - i - 1; j++)
        {

          if (vect1[j][vect1[j].size() - 1] >
              vect1[j + 1][vect1[j + 1].size() - 1])
          {
            swap(vect1[j], vect1[j + 1]);
          }
        }
      }

      cout << "\nDISTANCE TO DESTINATION: " << endl;
      n = 0;
      pth = "";
      for (int i = 0; i < vect1[0].size() - 1; i++)
      {
        f2.open("locations.txt");

        while (f2 >> op >> place)
        {

          if (op == vect1[0][i])
          {

            place1 = place;
            pth = pth + place + ",";
          }
        }
        f2.close();
        cout << place1 << " ";

        n = i;
      }

      cout << vect1[0][n + 1];
      sd = vect1[0][n + 1];
      cout << endl;
      ch.clear();
      ofstream file("out.txt", ios::binary | ios::trunc);
      file << pth;
      file.close();
      system("/Library/Frameworks/Python.framework/Versions/3.11/bin/python3 graph.py out.txt");
      goto i;
      return sd;
    }
    else if (ch == "no" || ch == "NO")
    {
      ofstream file("out.txt", ios::binary | ios::trunc);
      file << pth;
      file.close();
      system("/Library/Frameworks/Python.framework/Versions/3.11/bin/python3 graph.py out.txt");
      return sd;
      exit(0);
    }
    else
    {
      cout << "Invalid choice " << endl;
      goto i;
    }
  }

  void display()
  {

    string place, place1, place2;
    int op, op1, op2, w1, w2, n = 0;

    ifstream f2;
    for (int i = 0; i < vect1.size(); i++)
    {

      for (int j = 0; j < vect1[i].size() - 1; j++)
      {
        f2.open("locations.txt");

        while (f2 >> op >> place)
        {

          if (op == vect1[i][j])
          {

            place1 = place;
          }
        }
        f2.close();
        cout << place1 << " ";
        n = j;
      }
      cout << vect1[i][n + 1];
      cout << endl;
    }
  }
};

int main()
{

  navigation f;
  int choice1;
  cout << "\t\t\t\t\t WELCOME TO JAYPEE MAPS! \t\t\t\t\t" << endl;
  f.user();
}
