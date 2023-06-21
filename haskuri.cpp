/*
⠀⠀⢠⢽⣿⡏⠁⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢧⡹⣇⠀⢿⣿⣿⡄⠀⠀⠀
⠀⠀⢸⢧⣻⡇⠀⠸⡿⡟⢸⠏⣏⣿⣿⣿⣿⡏⢿⠈⡇⠏⠀⢸⣿⣯⣇⠀⠀⠀
⠀⠀⠘⣾⣽⠷⣀⣀⡀⠁⠸⠀⠋⢺⣿⣯⠻⠠⠯⠚⣁⣄⣀⠜⢻⣧⡟⠀⠀⠀
⠀⠀⠀⠈⠽⠀⠉⢻⣿⣿⣿⣿⣷⣤⣿⣷⣶⣿⠿⠿⠛⡻⠁⠀⣿⠎⠀⠀⠀⠀
⠀⠀⠀⠀⠈⢣⠀⠀⠻⠟⠭⠽⠟⠈⠀⠉⠘⠻⠲⠶⠚⠃⠀⠀⠟⠀⠀⠀⠀⠀
⠀⢀⣀⣀⡀⠏⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⡰⣠⣤⣴⣤⡀⠀
⣴⣿⣿⣿⣿⣷⠘⢆⠀⡤⠀⠀⠠⠃⠀⠀⢪⠀⠀⠀⡰⠂⡻⢡⣿⣿⣿⣿⣿⡄
⣿⣿⣿⣿⣿⣿⣷⡈⢢⡘⣷⣤⣄⡹⠦⢶⢥⣤⣴⡻⢀⣾⣷⣾⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣷⣷⣬⣿⣾⣼⣤⣼⣼⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*/

#include <iostream>
#include <fstream>
#include <vector>
#define FIN "hashuri.in"
#define FOUT "hashuri.out"
#define ins 1
#define del 2
#define search 3
#define MOD 666013

using namespace std;

vector<long> Hash[ MOD ];

int N, op, x;

ifstream fin(FIN);
ofstream fout(FOUT);

vector<long>::iterator seek(int value) {

      vector<long>::iterator it;

      long key = value % MOD;

      for(it = Hash[key].begin(); it != Hash[key].end(); it++) {

          if(*it == value) return it;
      }
      return it;
}

void insert(long value) {

    vector<long>::iterator it;

    long key = value % MOD;

    it = seek(value);

    if(it == Hash[key].end()) Hash[key].push_back(value);
}

void remove(long value) {

  vector<long>::iterator it;

  long key = value % MOD;

  it = seek(value);

  if(it != Hash[key].end()) Hash[key].erase(it);
}

int research(long value) {

  vector<long>::iterator it;

  long key = value % MOD;

  it = seek(value);

  if(it != Hash[key].end()) return 1;
             else
                            return 0;

}

int main(int argc, char const *argv[]) {

      fin>>N;

      for(; N; --N) {

            fin>>op>>x;

            if(op == ins) insert(x);
            else if(op == del) remove(x);
            else if(op == search) {
              int ans = research(x);
              if(ans == 1) fout<<"1\n";
                       else
                           fout<<"0\n";
            }

      }

      fin.close();
      fout.close();
  return 0;
}
