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

int print_board(vector<int> d, int x, int y)
{
  cout << "\n int print_board(vector<int> d, int x, int y) \n"  << endl;
  int count = 0;
  for(int i = 0; i < y; i++){
    cout << "\n"  << endl;
    for(int j = 0; j < x; j++){
      cout << " " << d[count];
      count++;
    }
  }

  return 0;
}

int complete(vector<int> d, int x, int y)
{
  cout << "\n int complete(vector<int> d, int x, int y) \n"  << endl;
  int n = 0;
  while(n < d.size()){
    if(d[n] == 0){
      return -1;
    }
    n++;
  }
  return 1;
}


int check(vector<int> d, int x, int y, int counter, int num)
{
  cout << "\n int check(vector<int> d, int x, int y, int counter, int num) \n"  << endl;
  int row = counter / x;
  int column = counter % x;
  cout << "counter = " << counter << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "row = " << row << endl;
  cout << "column = " << column << endl;
  // check column
  int m = column;
  while(m < d.size()){
    cout << "m = " << m << endl;
    cout << "d[m] = " << d[m] << endl;
    if(d[m]==num){
      cout << "\n error: number found already: " << d[m]  << endl;
      cout << "\n num: " << num  << endl;
      cout << "\n counter: " << counter  << endl;
      cout << "\n column: " << column  << endl;
      cout << "\n m: " << m  << endl;
      cout << "x = " << x << endl;
      cout << "y = " << y << endl;
      print_board(d, x, y);
      exit(0);
      return -1;
    }
    m = m+x;
  }
  // check row
  int n = row;
  int begin = row;
  while(n < begin+x){
    cout << "n = " << n << endl;
    cout << "d[n] = " << d[n] << endl;
    if(d[n]==num){
      cout << "\n error: number found already: " << d[n]  << endl;
      cout << "\n num: " << num  << endl;
      cout << "\n counter: " << counter  << endl;
      cout << "\n row: " << row  << endl;
      cout << "\n n: " << n  << endl;
      cout << "x = " << x << endl;
      cout << "y = " << y << endl;
      print_board(d, x, y);
      exit(0);
      return -1;
    }
    n++;
  }
  return 1;
}

int solve (vector<int> d, int x, int y, int counter)
{
  cout << "\n int solve (std::vector<int> d, int i, int j) \n";
  if(counter >= d.size()){
    return 1;
  }
  print_board(d, x, y);
  int size = d.size();
  /*
  cout << "\n size of the list is : "<<size;
  cout << "\n";
  for(int X : d) 
    cout << "X = " << X << endl;
  cout << "\n d[counter]: = " << d[counter] << endl;
  */
  int finished = complete(d, x, y);
  if(finished == 1){
    return 1;
  }
  if(d[counter]==0)
  {
    for(int i = 1; i < 10; i++){
      int result = check(d, x, y, counter, i);
      if(result == 1){
        d[counter] = i;
        cout << "d[counter] = i \n";
        cout << "\n i : " <<  i << endl;
        exit(0);
        solve(d, x, y, counter+1);
        print_board(d, x, y);
      }
    }
  }else if(counter < d.size()){
    solve(d, x, y, counter+1);
  }
  return 1;
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



