#include <iostream>
using namespace std;

int add(string table[], string val) {
  int h = 0, hash, newHash;
  for (int i = 0; i < val.length(); i++) {
    h += int(val[i])*(i+1);
  }
  hash = (h * 19) % 101;

  if (table[hash] == val) {
    return -1;
  }
  
  else{
		for(int j=1; j<=19; j++){
			newHash = (hash+(23*j)+(j*j))%101;
			if(table[newHash] == val){
				return -1;
			}
		}
	}

  if (table[hash] == "") {
    table[hash] = val;
    return 1;
  }

  for (int i = 1; i <= 19; i++) {
    newHash = (hash+(i*i)+(23*i))%101;
    if (table[newHash] == "") {
      table[newHash] = val;
      return 1;
    }
  }
  return -1;
}

int del(string table[], string val) {
  for (int i = 0; i < 101; i++){
    if (table[i] == val){
      table[i] = "";
      return 1;
    }
  }
  return -1;
}

int main() {
  int cases, numOP, num;
  string op, val, table[101];
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cin >> numOP;
    num = 0;

    for (int j = 0; j < 101; j++){
      table[j] = "";
    }
    
    for (int k = 0; k < numOP; k++) {
      cin >> op;

      if (op.substr(0, 4) == "ADD:") {
        val = op.substr(4);
        if (add(table, val) == 1) {num += 1;}
      } 
      else if (op.substr(0, 4) == "DEL:") {
        val = op.substr(4);
        if (del(table, val) == 1) {num -= 1;}
      }
    }
    cout << num << "\n";
    for (int l = 0; l < 101; l++){
      if(table[l] != ""){
        cout << l << ":" << table[l] << "\n";
      }  
    }
  }
  return 0;
}