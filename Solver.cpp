#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;



int addition (int a, int b)
{
  int r;
  r=a+b;
  return r;
}



int check(vector<int> d, int x, int y, int counter, int num)
{
  int row = counter / x;
  int column = counter % x;
  cout << "counter = " << counter << endl;
  cout << "x = " << x << endl;
  cout << "row = " << row << endl;
  cout << "column = " << column << endl;
  // check column
  int m = column;
  while(m < d.size()){
    cout << "m = " << m << endl;
    cout << "d[m] = " << d[m] << endl;
    if(d[m]==num){
      return -1;
    }
    m = m+x;
  }
  int n = row;
  while(n < d.size()){
    cout << "n = " << n << endl;
    cout << "d[n] = " << d[n] << endl;
    if(d[n]==num){
      return -1;
    }
    n = n+x;
  }
  return 1;
}

int solve (vector<int> d, int x, int y, int counter)
{
  cout << "int solve (std::vector<int> d, int i, int j)";
  int size = d.size();
  cout << "\n size of the list is : "<<size;
  cout << "\n";
  for(int X : d) 
    cout << "X = " << X << endl;
  cout << "\n d[counter]: = " << d[counter] << endl;
  counter = 28;
  if(d[counter]==0)
  {
    for(int i = 1; i < 10; i++){
      int result = check(d, x, y, counter, i);
      if(result == 1){
        d[counter] = i;
        solve(d, x, y, counter);
      }
    }
  }
  return 0;
}


int main () {
    list<int> mylist;
    int myint;
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("Easy.txt");
    int x = 0;
    int y = 0;
    while (getline (MyReadFile, myText)) {
      x = myText.length();
      y++;
    }
    MyReadFile.close();

    ifstream MyReadFile2("Easy.txt");
    int arr[x][y];
    vector<int> d;
    // Use a while loop together with the getline() function to read the file line by line
    int j = 0;
    while (getline (MyReadFile2, myText)) {
      j++;
      // Output the text from the file
      cout << '\n';
      cout << myText;
      cout << '\n';
      // Traverse the string
      for (int i = 0; i < myText.length(); i++) {
          // Print current character
          // cout<< myText[i]<< " ";
          int dig = myText[i] - '0';
          cout<< dig<< ", ";
          d.push_back(dig);
          mylist.push_back(dig);
          arr[i][j] =  dig;
      }
  }
  // Close the file
  MyReadFile2.close();

  solve(d, x, y, 0);


}


